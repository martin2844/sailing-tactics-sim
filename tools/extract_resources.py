#!/usr/bin/env python3
"""Extract Posey's PE resources reproducibly using only the Python standard library.

The original resource bytes are authoritative. JSON and PNG files are convenient
browser representations; dialog dimensions remain in Windows dialog units.
"""
from __future__ import annotations

import argparse
import hashlib
import io
import json
import struct
import wave
import zlib
from pathlib import Path

RESOURCE_TYPES = {1: "cursor", 2: "bitmap", 3: "icon", 4: "menu", 5: "dialog",
                  6: "string", 9: "accelerator", 10: "rcdata", 12: "group_cursor",
                  14: "group_icon", 16: "version"}
CONTROL_CLASSES = {0x80: "button", 0x81: "edit", 0x82: "static", 0x83: "listbox",
                   0x84: "scrollbar", 0x85: "combobox"}


def sha256(data):
    return hashlib.sha256(data).hexdigest()


def align(value, boundary=4):
    return (value + boundary - 1) & ~(boundary - 1)


class Reader:
    def __init__(self, data, position=0):
        self.data, self.position = data, position

    def unpack(self, fmt):
        fmt = "<" + fmt
        result = struct.unpack_from(fmt, self.data, self.position)
        self.position += struct.calcsize(fmt)
        return result

    def word(self):
        return self.unpack("H")[0]

    def text(self):
        start = self.position
        while self.word():
            pass
        return self.data[start:self.position - 2].decode("utf-16le")

    def name(self):
        value = self.word()
        if value == 0:
            return None
        if value == 0xFFFF:
            return {"ordinal": self.word()}
        self.position -= 2
        return self.text()


class PE:
    def __init__(self, data):
        self.data = data
        if data[:2] != b"MZ":
            raise ValueError("Missing DOS MZ signature")
        pe_offset = struct.unpack_from("<I", data, 0x3C)[0]
        if data[pe_offset:pe_offset + 4] != b"PE\0\0":
            raise ValueError("Missing PE signature")
        section_count = struct.unpack_from("<H", data, pe_offset + 6)[0]
        optional_size = struct.unpack_from("<H", data, pe_offset + 20)[0]
        optional = pe_offset + 24
        magic = struct.unpack_from("<H", data, optional)[0]
        directory = optional + {0x10B: 96, 0x20B: 112}[magic]
        self.resource_rva, self.resource_size = struct.unpack_from("<II", data, directory + 16)
        self.sections = []
        for index in range(section_count):
            offset = optional + optional_size + index * 40
            virtual_size, virtual_address, raw_size, raw_offset = struct.unpack_from("<IIII", data, offset + 8)
            self.sections.append({"name": data[offset:offset + 8].rstrip(b"\0").decode("ascii"),
                                  "virtual_address": virtual_address, "virtual_size": virtual_size,
                                  "raw_size": raw_size, "raw_offset": raw_offset})
        self.resource_offset = self.offset(self.resource_rva)

    def offset(self, rva):
        for section in self.sections:
            delta = rva - section["virtual_address"]
            if 0 <= delta < max(section["virtual_size"], section["raw_size"]):
                if delta >= section["raw_size"]:
                    raise ValueError("Resource refers to uninitialized section data")
                return section["raw_offset"] + delta
        raise ValueError(f"Unmapped RVA: {rva:#x}")

    def resources(self):
        leaves, visited = [], set()

        def name(value):
            if value & 0x80000000:
                reader = Reader(self.data, self.resource_offset + (value & 0x7FFFFFFF))
                size = reader.word()
                return reader.data[reader.position:reader.position + size * 2].decode("utf-16le")
            return value

        def walk(relative, parents):
            if relative in visited:
                raise ValueError("Repeated or cyclic resource directory")
            visited.add(relative)
            offset = self.resource_offset + relative
            named, numeric = struct.unpack_from("<HH", self.data, offset + 12)
            for index in range(named + numeric):
                label, destination = struct.unpack_from("<II", self.data, offset + 16 + index * 8)
                path = parents + [name(label)]
                if destination & 0x80000000:
                    walk(destination & 0x7FFFFFFF, path)
                else:
                    if len(path) != 3:
                        raise ValueError(f"Unexpected resource depth: {path}")
                    rva, size, code_page, reserved = struct.unpack_from("<IIII", self.data, self.resource_offset + destination)
                    start = self.offset(rva)
                    payload = self.data[start:start + size]
                    if len(payload) != size:
                        raise ValueError("Truncated resource")
                    leaves.append({"type": path[0], "id": path[1], "language": path[2],
                                   "rva": rva, "file_offset": start, "size": size,
                                   "code_page": code_page, "reserved": reserved, "data": payload})
        walk(0, [])
        return leaves


def parse_menu(data):
    reader = Reader(data)
    version, extra = reader.unpack("HH")
    if version != 0:
        raise ValueError("Unsupported extended menu resource")
    reader.position += extra

    def items():
        result = []
        while True:
            flags = reader.word()
            popup = bool(flags & 0x10)
            command_id = None if popup else reader.word()
            title = reader.text()
            item = {"text": title, "flags": flags, "command_id": command_id,
                    "separator": not popup and command_id == 0 and title == ""}
            if popup:
                item["items"] = items()
            result.append(item)
            if flags & 0x80:
                return result

    result = {"version": version, "items": items()}
    if reader.position != len(data):
        raise ValueError("Trailing menu bytes")
    return result


def parse_dialog(data):
    reader = Reader(data)
    style, ex_style, count, x, y, width, height = reader.unpack("IIHhhhh")
    if data[:4] == b"\1\0\xff\xff":
        raise ValueError("Unsupported extended dialog resource")
    result = {"style": style, "extended_style": ex_style, "control_count": count,
              "rect_dialog_units": [x, y, width, height], "menu": reader.name(),
              "window_class": reader.name(), "title": reader.name()}
    if style & 0x40:
        result["font"] = {"point_size": reader.word(), "face": reader.text()}
    controls = []
    for _ in range(count):
        reader.position = align(reader.position)
        cstyle, cex_style, cx, cy, cwidth, cheight, cid = reader.unpack("IIhhhhH")
        control_class, title = reader.name(), reader.name()
        extra_size = reader.word()
        extra_data = data[reader.position:reader.position + extra_size]
        reader.position += extra_size
        controls.append({"id": cid, "style": cstyle, "extended_style": cex_style,
                         "rect_dialog_units": [cx, cy, cwidth, cheight],
                         "class": control_class,
                         "class_name": CONTROL_CLASSES.get(control_class.get("ordinal")) if isinstance(control_class, dict) else control_class,
                         "title": title, "creation_data_hex": extra_data.hex()})
    if any(data[reader.position:]):
        raise ValueError("Nonzero trailing dialog data")
    result["controls"] = controls
    return result


def parse_strings(data, block):
    reader = Reader(data)
    result = {}
    for index in range(16):
        size = reader.word()
        value = data[reader.position:reader.position + size * 2].decode("utf-16le")
        reader.position += size * 2
        if size:
            result[(block - 1) * 16 + index] = value
    if reader.position != len(data) and (len(data) != align(reader.position) or any(data[reader.position:])):
        raise ValueError("Trailing string table bytes")
    return result


def parse_accelerators(data):
    if len(data) % 8:
        raise ValueError("Truncated accelerator table")
    result = []
    for offset in range(0, len(data), 8):
        flags, key, command_id, padding = struct.unpack_from("<HHHH", data, offset)
        result.append({"flags": flags, "key": key, "command_id": command_id,
                       "virtual_key": bool(flags & 1), "shift": bool(flags & 4),
                       "ctrl": bool(flags & 8), "alt": bool(flags & 16),
                       "last": bool(flags & 0x80), "padding": padding})
    if not result[-1]["last"] or any(item["last"] for item in result[:-1]):
        raise ValueError("Invalid accelerator termination")
    return result


def parse_version(data, offset=0):
    reader = Reader(data, offset)
    length, value_size, value_type = reader.unpack("HHH")
    key = reader.text()
    start = align(reader.position)
    byte_size = value_size * (2 if value_type == 1 else 1)
    value = data[start:start + byte_size]
    node = {"key": key, "type": value_type, "length": length}
    if value_type == 1:
        node["value"] = value.decode("utf-16le").rstrip("\0")
    else:
        node["value_hex"] = value.hex()
        if key == "VS_VERSION_INFO" and len(value) == 52:
            numbers = struct.unpack("<13I", value)
            node["fixed_file_info"] = dict(zip(("signature", "structure_version", "file_version_ms",
                "file_version_ls", "product_version_ms", "product_version_ls", "file_flags_mask",
                "file_flags", "file_os", "file_type", "file_subtype", "file_date_ms", "file_date_ls"), numbers))
    cursor = align(start + byte_size)
    children = []
    while cursor + 6 <= offset + length:
        child_length = struct.unpack_from("<H", data, cursor)[0]
        if not child_length:
            break
        children.append(parse_version(data, cursor))
        cursor = align(cursor + child_length)
    if children:
        node["children"] = children
    return node


def decode_dib(data, icon=False):
    header_size, width, stored_height, planes, bpp, compression, image_size, xppm, yppm, colors, important = struct.unpack_from("<IiiHHIIiiII", data)
    if header_size < 40 or planes != 1 or compression != 0 or bpp not in (1, 4, 8, 24, 32):
        raise ValueError(f"Unsupported DIB: header={header_size}, planes={planes}, bpp={bpp}, compression={compression}")
    height = abs(stored_height) // (2 if icon else 1)
    palette_size = (colors or (1 << bpp)) if bpp <= 8 else 0
    palette = [tuple(data[header_size + i * 4:header_size + i * 4 + 3][::-1]) for i in range(palette_size)]
    pixels_start = header_size + palette_size * 4
    stride = ((width * bpp + 31) // 32) * 4
    mask_start = pixels_start + stride * height
    mask_stride = ((width + 31) // 32) * 4
    rows, inversion_count = [], 0
    for y in range(height):
        source_y = height - y - 1 if stored_height > 0 else y
        line = pixels_start + source_y * stride
        row = bytearray()
        for x in range(width):
            if bpp <= 8:
                byte = data[line + x * bpp // 8]
                value = (byte >> (8 - bpp - (x * bpp % 8))) & ((1 << bpp) - 1)
                red, green, blue = palette[value]
                alpha = 255
            else:
                pixel = line + x * (bpp // 8)
                blue, green, red = data[pixel:pixel + 3]
                alpha = data[pixel + 3] if bpp == 32 else 255
            if icon:
                masked = (data[mask_start + source_y * mask_stride + x // 8] >> (7 - x % 8)) & 1
                if masked:
                    if bpp == 1 and value:
                        inversion_count += 1
                    alpha = 0
            row.extend((red, green, blue, alpha))
        rows.append(bytes(row))
    return {"width": width, "height": height, "bits_per_pixel": bpp,
            "compression": compression, "header_size": header_size,
            "palette_entries": palette_size, "inverting_pixels": inversion_count,
            "stored_height": stored_height, "pixels_offset": pixels_start}, rows


def encode_png(width, height, rows):
    def chunk(kind, payload):
        return struct.pack(">I", len(payload)) + kind + payload + struct.pack(">I", zlib.crc32(kind + payload))
    return (b"\x89PNG\r\n\x1a\n" + chunk(b"IHDR", struct.pack(">IIBBBBB", width, height, 8, 6, 0, 0, 0))
            + chunk(b"IDAT", zlib.compress(b"".join(b"\0" + row for row in rows), 9)) + chunk(b"IEND", b""))


def build_icon(group, lookup, cursor=False):
    reserved, kind, count = struct.unpack_from("<HHH", group)
    if reserved != 0 or kind != (2 if cursor else 1):
        raise ValueError("Invalid icon/cursor group")
    entries, payloads = [], []
    offset = 6 + count * 16
    for index in range(count):
        position = 6 + index * 14
        if cursor:
            width, stored_height, planes, bpp, original_size, resource_id = struct.unpack_from("<HHHHIH", group, position)
        else:
            width, height, color_count, entry_reserved, planes, bpp, original_size, resource_id = struct.unpack_from("<BBBBHHIH", group, position)
        original = lookup[resource_id]
        if len(original) != original_size:
            raise ValueError("Icon group size disagrees with image resource")
        payload = original[4:] if cursor else original
        info, _ = decode_dib(payload, icon=True)
        if cursor:
            hotspot_x, hotspot_y = struct.unpack_from("<HH", original)
            entries.append(struct.pack("<BBBBHHII", info["width"] % 256, info["height"] % 256,
                                       0, 0, hotspot_x, hotspot_y, len(payload), offset))
        else:
            entries.append(struct.pack("<BBBBHHII", width, height, color_count, entry_reserved,
                                       planes, bpp, len(payload), offset))
        payloads.append(payload)
        offset += len(payload)
    return struct.pack("<HHH", 0, kind, count) + b"".join(entries) + b"".join(payloads)


def extract(source: Path, destination: Path):
    binary = source.read_bytes()
    pe = PE(binary)
    resources = pe.resources()
    generated = {}

    def output(path, data):
        if isinstance(data, (dict, list)):
            data = (json.dumps(data, indent=2, ensure_ascii=False) + "\n").encode("utf-8")
        generated[path] = data
        target = destination / path
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_bytes(data)
        return path

    manifest = {"schema_version": 1, "source": source.name, "source_sha256": sha256(binary),
                "resource_directory_rva": pe.resource_rva, "resource_directory_size": pe.resource_size,
                "language_ids": sorted({item["language"] for item in resources}), "resources": []}
    strings, menus, dialogs, accelerators, versions = {}, [], [], [], []
    for resource in resources:
        kind, resource_id, language = resource["type"], resource["id"], resource["language"]
        type_name = RESOURCE_TYPES.get(kind, str(kind).lower())
        basename = f"{type_name}-{resource_id}-{language}"
        payload = resource["data"]
        entry = {key: value for key, value in resource.items() if key != "data"}
        entry["type_name"] = type_name
        entry["sha256"] = sha256(payload)
        entry["raw_path"] = output(f"raw/{basename}.bin", payload)
        if kind == 2:
            info, rows = decode_dib(payload)
            entry["image"] = info
            entry["png_path"] = output(f"images/{basename}.png", encode_png(info["width"], info["height"], rows))
            bmp = b"BM" + struct.pack("<IHHI", len(payload) + 14, 0, 0, info["pixels_offset"] + 14) + payload
            entry["bmp_path"] = output(f"images/{basename}.bmp", bmp)
        elif kind in (1, 3):
            dib = payload[4:] if kind == 1 else payload
            info, rows = decode_dib(dib, icon=True)
            entry["image"] = info
            if kind == 1:
                entry["hotspot"] = list(struct.unpack_from("<HH", payload))
            entry["png_path"] = output(f"images/{basename}.png", encode_png(info["width"], info["height"], rows))
        elif kind in (12, 14):
            image_type = 1 if kind == 12 else 3
            lookup = {item["id"]: item["data"] for item in resources if item["type"] == image_type and item["language"] == language}
            suffix = "cur" if kind == 12 else "ico"
            entry[f"{suffix}_path"] = output(f"images/{basename}.{suffix}", build_icon(payload, lookup, cursor=kind == 12))
        elif kind == "WAVE":
            entry["wav_path"] = output(f"audio/{basename}.wav", payload)
            with wave.open(io.BytesIO(payload)) as audio:
                entry["audio"] = {"channels": audio.getnchannels(), "sample_width_bytes": audio.getsampwidth(),
                                  "sample_rate_hz": audio.getframerate(), "frame_count": audio.getnframes(),
                                  "duration_seconds": audio.getnframes() / audio.getframerate(),
                                  "compression": audio.getcomptype()}
        elif kind == 4:
            menus.append({"resource_id": resource_id, "language": language, **parse_menu(payload)})
        elif kind == 5:
            dialogs.append({"resource_id": resource_id, "language": language, **parse_dialog(payload)})
        elif kind == 6:
            strings.update(parse_strings(payload, resource_id))
        elif kind == 9:
            accelerators.append({"resource_id": resource_id, "language": language, "entries": parse_accelerators(payload)})
        elif kind == 16:
            versions.append({"resource_id": resource_id, "language": language, "info": parse_version(payload)})
        manifest["resources"].append(entry)
    for name, data in (("strings", strings), ("menus", menus), ("dialogs", dialogs),
                       ("accelerators", accelerators), ("versions", versions)):
        output(f"ui/{name}.json", data)
    manifest["generated_files"] = [{"path": path, "size": len(data), "sha256": sha256(data)} for path, data in sorted(generated.items())]
    output("manifest.json", manifest)
    return manifest


def verify(source: Path, destination: Path):
    """Compare every raw byte against PE offsets and every derivative against its hash."""
    manifest = json.loads((destination / "manifest.json").read_text())
    binary = source.read_bytes()
    if sha256(binary) != manifest["source_sha256"]:
        raise ValueError("Original executable hash mismatch")
    current = PE(binary).resources()
    if len(current) != len(manifest["resources"]):
        raise ValueError("Resource count mismatch")
    for raw, entry in zip(current, manifest["resources"]):
        if (raw["type"], raw["id"], raw["language"]) != (entry["type"], entry["id"], entry["language"]):
            raise ValueError("Resource identity mismatch")
        stored = (destination / entry["raw_path"]).read_bytes()
        if stored != raw["data"] or sha256(stored) != entry["sha256"]:
            raise ValueError(f"Raw resource mismatch: {entry['raw_path']}")
    for entry in manifest["generated_files"]:
        data = (destination / entry["path"]).read_bytes()
        if len(data) != entry["size"] or sha256(data) != entry["sha256"]:
            raise ValueError(f"Generated file mismatch: {entry['path']}")
    return len(current), len(manifest["generated_files"])


def main():
    root = Path(__file__).resolve().parent.parent
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--source", type=Path, default=root / "original/Tact02Demo.exe")
    parser.add_argument("--output", type=Path, default=root / "assets")
    parser.add_argument("--verify", action="store_true", help="Verify existing extraction integrity")
    args = parser.parse_args()
    if args.verify:
        resources, files = verify(args.source, args.output)
        print(f"Verified {resources} original resources and {files} generated files")
    else:
        result = extract(args.source, args.output)
        print(f"Extracted {len(result['resources'])} resources into {args.output}")


if __name__ == "__main__":
    main()
