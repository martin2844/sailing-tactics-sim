#!/usr/bin/env python3
"""Extract exact resources and nonexecutable initial data from the fixed 2010 target.

This tool never writes to the executable. The existing preservation localization
is the source authority; Japanese data and the 2002 browser assets are not inputs
to the browser memory segments generated here.
"""
from __future__ import annotations

import argparse
import collections
import hashlib
import importlib.util
import json
import struct
import tempfile
from pathlib import Path

EDITION = Path(__file__).resolve().parents[1]
ROOT = EDITION.parents[1]
SOURCE = EDITION / "runtime/Tactics2010EnglishPreserved.exe"
EXPECTED = "d707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787"
IMAGE_BASE = 0x400000
DATA_SECTIONS = {".rdata": "original-constants.bin", ".data": "original-initial-state.bin",
                 ".english": "original-english-data.bin"}
resource_spec = importlib.util.spec_from_file_location("posey_resources", ROOT / "tools/extract_resources.py")
resources = importlib.util.module_from_spec(resource_spec)
resource_spec.loader.exec_module(resources)


def digest(data):
    return hashlib.sha256(data).hexdigest()


def json_bytes(value):
    return (json.dumps(value, indent=2, ensure_ascii=False, allow_nan=False) + "\n").encode("utf-8")


def source_data():
    data = SOURCE.read_bytes()
    if digest(data) != EXPECTED:
        raise ValueError("Expected the unchanged preserved 2010 English target")
    return data


def layout(data):
    pe = resources.PE(data)
    header = struct.unpack_from("<I", data, 0x3c)[0]
    optional = header + 24
    magic = struct.unpack_from("<H", data, optional)[0]
    base = struct.unpack_from("<I", data, optional + 28)[0]
    if magic != 0x10b or base != IMAGE_BASE:
        raise ValueError("Expected fixed x86 PE32 image base 0x400000")
    directories = []
    names = ["export", "import", "resource", "exception", "certificate", "base_relocation",
             "debug", "architecture", "global_pointer", "tls", "load_config", "bound_import",
             "iat", "delay_import", "clr", "reserved"]
    for index, name in enumerate(names):
        rva, size = struct.unpack_from("<II", data, optional + 96 + index * 8)
        directories.append({"name": name, "rva": rva, "size": size})
    sections = []
    optional_size = struct.unpack_from("<H", data, header + 20)[0]
    for index, raw in enumerate(pe.sections):
        section = dict(raw)
        flags = struct.unpack_from("<I", data, optional + optional_size + index * 40 + 36)[0]
        section.update(address=base + section["virtual_address"], characteristics=flags,
                       executable=bool(flags & 0x20000000), readable=bool(flags & 0x40000000),
                       writable=bool(flags & 0x80000000),
                       raw_sha256=digest(data[section["raw_offset"]:section["raw_offset"] + section["raw_size"]]))
        sections.append(section)
    result = {"schemaVersion": 1, "source": SOURCE.relative_to(ROOT).as_posix(), "sourceSha256": EXPECTED,
              "fileBytes": len(data), "machine": struct.unpack_from("<H", data, header + 4)[0],
              "imageBase": base, "imageSize": struct.unpack_from("<I", data, optional + 56)[0],
              "entryPoint": base + struct.unpack_from("<I", data, optional + 16)[0],
              "directories": directories, "sections": sections, "imports": []}
    imp = directories[1]["rva"]
    offset = pe.offset(imp)
    def c_string(rva):
        first = pe.offset(rva)
        last = data.index(0, first)
        return data[first:last].decode("ascii")
    while True:
        original_thunks, stamp, forward, name_rva, first_thunks = struct.unpack_from("<5I", data, offset)
        if not any((original_thunks, stamp, forward, name_rva, first_thunks)):
            break
        items = []
        thunk = pe.offset(original_thunks or first_thunks)
        for index in range(4096):
            value = struct.unpack_from("<I", data, thunk + index * 4)[0]
            if not value:
                break
            item = {"address": base + first_thunks + index * 4}
            if value & 0x80000000:
                item["ordinal"] = value & 0xffff
            else:
                item.update(name=c_string(value + 2), hint=struct.unpack_from("<H", data, pe.offset(value))[0])
            items.append(item)
        else:
            raise ValueError("Import table exceeds fixed image bound")
        result["imports"].append({"library": c_string(name_rva), "bindings": items})
        offset += 20
    return result, pe


def embedded_text(data, pe):
    record_path = EDITION / "runtime/localization-record.json"
    map_path = EDITION / "analysis/localization-inputs.json"
    record_data = record_path.read_bytes()
    record = json.loads(record_data)
    mapping_data = map_path.read_bytes()
    mapping = json.loads(mapping_data)
    if record["output_sha256"] != EXPECTED or digest(mapping_data) != record["translation_map_sha256"]:
        raise ValueError("Localization provenance does not match exact target")
    changes = {row["source_va"]: row for row in record["embedded_text_changes"]}
    entries = []
    for row in mapping["embedded"]:
        change = changes[row["va"]]
        address = change.get("target_va", row["va"])
        offset = pe.offset(address - IMAGE_BASE)
        expected = row["target_english"].encode("cp1252") + b"\0"
        if change["method"] == "in-place-preserving-byte-capacity":
            expected = expected[:-1] + b" " * (row["byte_length_including_nul"] - len(expected)) + b"\0"
        if data[offset:offset + len(expected)] != expected:
            raise ValueError(f"Localized literal differs at {address:08x}")
        entries.append({"originalAddress": row["va"], "address": address, "fileOffset": offset,
                        "originalByteCapacity": row["byte_length_including_nul"], "bytes": len(expected),
                        "method": change["method"], "text": expected[:-1].decode("cp1252"),
                        "leadingNul": expected[0] == 0, "sha256": digest(expected)})
    if len(entries) != 1476 or sum(e["method"] == "appended-literal" for e in entries) != 229:
        raise ValueError("Unexpected fixed localization inventory")
    return {"schemaVersion": 1, "sourceSha256": EXPECTED, "encoding": "windows-1252",
            "localizationRecordSha256": digest(record_data), "translationMapSha256": digest(mapping_data),
            "scope": "Verified exact target literals; leading NUL and trailing spaces are retained. "
                     "Fixed native drawing character counts are separate behavior and are not extended here.",
            "entries": entries}


def generate(destination):
    data = source_data()
    metadata, pe = layout(data)
    manifest = resources.extract(SOURCE, destination)
    generated = []
    def write(path, value):
        payload = value if isinstance(value, bytes) else json_bytes(value)
        target = destination / path
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_bytes(payload)
        generated.append({"path": path, "size": len(payload), "sha256": digest(payload)})
    memory = {"schemaVersion": 1, "sourceSha256": EXPECTED, "imageBase": IMAGE_BASE,
              "imageSize": metadata["imageSize"], "scope": "Exact nonexecutable constants, mutable initial "
              "data, and English resource/text data. No PE headers, x86 instructions, or import bindings "
              "are included; browser functions execute native JavaScript.", "segments": []}
    for section in metadata["sections"]:
        if section["name"] not in DATA_SECTIONS:
            continue
        if section["executable"]:
            raise ValueError("Refusing to publish an executable section as browser data")
        size = max(section["virtual_size"], section["raw_size"])
        initialized = data[section["raw_offset"]:section["raw_offset"] + section["raw_size"]]
        payload = initialized + bytes(size - len(initialized))
        filename = DATA_SECTIONS[section["name"]]
        write("data/" + filename, payload)
        memory["segments"].append({"section": section["name"], "file": filename,
            "address": section["address"], "size": size, "initializedBytes": len(initialized),
            "zeroFillBytes": size - len(initialized), "writable": section["writable"], "sha256": digest(payload)})
    if len(memory["segments"]) != 3:
        raise ValueError("Expected the target's three data sections")
    write("data/original-memory.json", memory)
    write("data/embedded-text.json", embedded_text(data, pe))
    write("data/source-layout.json", metadata)
    tables = [{"resourceId": row["id"], "language": row["language"],
               "entries": resources.parse_strings(row["data"], row["id"])}
              for row in pe.resources() if row["type"] == 6]
    write("ui/string-tables.json", {"sourceSha256": EXPECTED, "encoding": "utf-16le", "tables": tables})
    manifest["preservation"] = {"target": "2010 English preservation copy", "executableUnchanged": True,
                                "activeResourceSection": ".english", "embeddedTextEncoding": "windows-1252",
                                "resourceTextEncoding": "utf-16le"}
    manifest["generated_files"].extend(generated)
    manifest["generated_files"].sort(key=lambda row: row["path"])
    (destination / "manifest.json").write_bytes(json_bytes(manifest))
    if SOURCE.read_bytes() != data:
        raise ValueError("Source changed during extraction")
    return manifest


def verify(destination):
    with tempfile.TemporaryDirectory(prefix="tact-2010-assets-") as directory:
        temporary = Path(directory)
        manifest = generate(temporary)
        for path in ["manifest.json", *(row["path"] for row in manifest["generated_files"])]:
            if (temporary / path).read_bytes() != (destination / path).read_bytes():
                raise ValueError(f"Exact extraction mismatch: {path}")
        resources.verify(SOURCE, destination)
        return manifest


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output", type=Path, default=EDITION / "assets")
    parser.add_argument("--verify", action="store_true")
    args = parser.parse_args()
    manifest = verify(args.output) if args.verify else generate(args.output)
    print(json.dumps({"verified": args.verify, "sourceSha256": EXPECTED,
        "resources": len(manifest["resources"]), "generatedFiles": len(manifest["generated_files"]),
        "resourceTypes": dict(sorted(collections.Counter(r["type_name"] for r in manifest["resources"]).items()))}, sort_keys=True))


if __name__ == "__main__":
    main()
