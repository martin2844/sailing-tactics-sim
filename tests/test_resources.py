"""Independent preservation checks for the extracted resource archive."""
import hashlib
import json
import struct
import unittest
import zlib
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
ASSETS = ROOT / "assets"
SOURCE_SHA256 = "881dc85dc7500a5ad09e09091d4dd53f8c091f5630d5fabdcc887cc4b007acea"


class ResourcePreservationTests(unittest.TestCase):
    assets = ASSETS
    source = ROOT / "original/Tact02Demo.exe"
    source_sha256 = SOURCE_SHA256
    resource_count = 66

    @classmethod
    def setUpClass(cls):
        cls.binary = cls.source.read_bytes()
        cls.manifest = json.loads((cls.assets / "manifest.json").read_text())

    def test_source_and_raw_resources_match_original_offsets(self):
        self.assertEqual(hashlib.sha256(self.binary).hexdigest(), self.source_sha256)
        self.assertEqual(self.manifest["source_sha256"], self.source_sha256)
        self.assertEqual(len(self.manifest["resources"]), self.resource_count)
        for resource in self.manifest["resources"]:
            with self.subTest(resource=(resource["type"], resource["id"])):
                start = resource["file_offset"]
                raw = (self.assets / resource["raw_path"]).read_bytes()
                self.assertEqual(raw, self.binary[start:start + resource["size"]])

    def test_png_crc_dimensions_orientation_palette_and_mask(self):
        # Read PNGs independently, checking both the container and every pixel
        # against the raw Windows DIB's palette, bottom-up rows, and AND mask.
        for resource in self.manifest["resources"]:
            if "png_path" not in resource:
                continue
            with self.subTest(path=resource["png_path"]):
                png = (self.assets / resource["png_path"]).read_bytes()
                self.assertEqual(png[:8], b"\x89PNG\r\n\x1a\n")
                position, compressed, chunks = 8, b"", []
                while position < len(png):
                    size = struct.unpack_from(">I", png, position)[0]
                    kind = png[position + 4:position + 8]
                    payload = png[position + 8:position + 8 + size]
                    crc = struct.unpack_from(">I", png, position + 8 + size)[0]
                    self.assertEqual(crc, zlib.crc32(kind + payload))
                    chunks.append(kind)
                    if kind == b"IHDR":
                        width, height, depth, color_type, compression, filtering, interlace = struct.unpack(">IIBBBBB", payload)
                        self.assertEqual((depth, color_type, compression, filtering, interlace), (8, 6, 0, 0, 0))
                    if kind == b"IDAT":
                        compressed += payload
                    position += size + 12
                self.assertEqual(chunks, [b"IHDR", b"IDAT", b"IEND"])
                self.assertEqual(position, len(png))
                pixels = zlib.decompress(compressed)
                self.assertEqual(len(pixels), height * (width * 4 + 1))
                raw = (self.assets / resource["raw_path"]).read_bytes()
                if resource["type"] == 1:
                    raw = raw[4:]
                header_size, dib_width, dib_height = struct.unpack_from("<Iii", raw)
                bpp = struct.unpack_from("<H", raw, 14)[0]
                colors = struct.unpack_from("<I", raw, 32)[0] or 2 ** bpp
                icon = resource["type"] in (1, 3)
                self.assertEqual((dib_width, abs(dib_height) // (2 if icon else 1)), (width, height))
                stride = ((width * bpp + 31) // 32) * 4
                bitmap_start = header_size + colors * 4
                for y in range(height):
                    self.assertEqual(pixels[y * (width * 4 + 1)], 0)
                    source_y = height - y - 1 if dib_height > 0 else y
                    for x in range(width):
                        byte = raw[bitmap_start + source_y * stride + x * bpp // 8]
                        palette_index = (byte >> (8 - bpp - x * bpp % 8)) % (2 ** bpp)
                        palette_start = header_size + palette_index * 4
                        blue, green, red = raw[palette_start:palette_start + 3]
                        alpha = 255
                        if icon:
                            mask_stride = ((width + 31) // 32) * 4
                            mask_byte = raw[bitmap_start + height * stride + source_y * mask_stride + x // 8]
                            alpha = 0 if mask_byte & (0x80 >> (x % 8)) else 255
                        png_position = y * (width * 4 + 1) + 1 + x * 4
                        self.assertEqual(pixels[png_position:png_position + 4], bytes((red, green, blue, alpha)))

    def test_ico_and_cur_retain_image_payloads_and_hotspots(self):
        for resource in self.manifest["resources"]:
            if resource["type"] not in (12, 14):
                continue
            cursor = resource["type"] == 12
            suffix = "cur" if cursor else "ico"
            group = (self.assets / resource["raw_path"]).read_bytes()
            icon = (self.assets / resource[f"{suffix}_path"]).read_bytes()
            count = struct.unpack_from("<H", group, 4)[0]
            self.assertEqual(struct.unpack_from("<HHH", icon), (0, 2 if cursor else 1, count))
            for index in range(count):
                image_id = struct.unpack_from("<H", group, 6 + index * 14 + 12)[0]
                image_type = "cursor" if cursor else "icon"
                original = (self.assets / f"raw/{image_type}-{image_id}-{resource['language']}.bin").read_bytes()
                size, offset = struct.unpack_from("<II", icon, 6 + index * 16 + 8)
                self.assertEqual(icon[offset:offset + size], original[4:] if cursor else original)
                if cursor:
                    self.assertEqual(icon[6 + index * 16 + 4:6 + index * 16 + 8], original[:4])

    def test_ui_ids_and_dialog_controls(self):
        menus = json.loads((self.assets / "ui/menus.json").read_text())
        self.assertEqual(len(menus), 1)
        self.assertEqual(menus[0]["resource_id"], 128)
        start = next(item for item in menus[0]["items"][0]["items"] if not item["separator"])
        self.assertEqual(start["command_id"], 32771)
        self.assertEqual(start["text"], "Start          spacebar")
        dialogs = json.loads((self.assets / "ui/dialogs.json").read_text())
        design = next(dialog for dialog in dialogs if dialog["resource_id"] == 132)
        self.assertEqual(design["title"], "Design Options")
        self.assertEqual(design["rect_dialog_units"], [0, 0, 308, 162])
        self.assertEqual({control["id"] for control in design["controls"]}, {1, 2, *range(1007, 1026)})
        strings = json.loads((self.assets / "ui/strings.json").read_text())
        self.assertEqual(len(strings), 261)
        self.assertEqual(strings["57344"], "TACT")


class ResourcePreservation2008Tests(ResourcePreservationTests):
    assets = ROOT / "versions/2008/assets"
    source = ROOT / "versions/2008/original/2008_English/TacticsDemo.exe"
    source_sha256 = "93ea6431f9cd81260d5ea2c2de7d01453a110bffe3de40967d6024f20e0307b9"
    resource_count = 77

    def test_ui_ids_and_dialog_controls(self):
        menus = json.loads((self.assets / "ui/menus.json").read_text())
        self.assertEqual(len(menus), 1)
        self.assertEqual(menus[0]["resource_id"], 128)
        start = next(item for item in menus[0]["items"][0]["items"] if not item["separator"])
        self.assertEqual((start["command_id"], start["text"]),
                         (32771, "Start  Racing             spacebar"))
        options = next(item for item in menus[0]["items"] if item["text"] == "&Option")
        real_areas = next(item for item in options["items"] if item["text"] == "Real Racing Areas")
        boats = next(item for item in options["items"] if item["text"] == "Boat Type")
        self.assertEqual(sum(not item["separator"] for item in real_areas["items"]), 18)
        self.assertEqual(sum(not item["separator"] for item in boats["items"]), 24)
        self.assertTrue(any(item["text"] == "Create" for item in menus[0]["items"]))
        dialogs = json.loads((self.assets / "ui/dialogs.json").read_text())
        self.assertEqual({dialog["resource_id"] for dialog in dialogs}, {100, 131, 132, 154, 30721})
        about = next(dialog for dialog in dialogs if dialog["resource_id"] == 100)
        self.assertIn("Copyright (C) 1998 -2007 by C. Dennis Posey",
                      [control["title"] for control in about["controls"]])
        design = next(dialog for dialog in dialogs if dialog["resource_id"] == 132)
        self.assertEqual(design["title"], "Design Options")
        self.assertEqual(design["rect_dialog_units"], [0, 0, 308, 162])
        self.assertEqual({control["id"] for control in design["controls"]}, {1, 2, *range(1007, 1026)})
        strings = json.loads((self.assets / "ui/strings.json").read_text())
        self.assertEqual(len(strings), 294)
        self.assertEqual(strings["57344"], "TACT")
        self.assertEqual(strings["33096"],
                         "Permits you to create a personal race area using the Create Menu.")


class ResourcePreservation2010JapaneseTests(ResourcePreservationTests):
    assets = ROOT / "versions/2010-jp/assets"
    source = ROOT / "versions/2010-jp/original/TacticsDemoj.exe"
    source_sha256 = "27c77acfb4fc1a69092a3c2cfebc52f666ff7b2ca53ed80661664c87d9d0c177"
    resource_count = 76

    def test_ui_ids_and_dialog_controls(self):
        menus = json.loads((self.assets / "ui/menus.json").read_text())
        self.assertEqual((len(menus), menus[0]["resource_id"], menus[0]["language"]),
                         (1, 128, 1041))

        def leaves(items):
            for item in items:
                if "items" in item:
                    yield from leaves(item["items"])
                elif not item["separator"]:
                    yield item

        commands = {item["command_id"]: item["text"] for item in leaves(menus[0]["items"])}
        self.assertEqual(len(commands), 312)
        self.assertEqual(commands[33105], "E-スコー")
        self.assertEqual(commands[33106], "フライングスコット")
        dialogs = json.loads((self.assets / "ui/dialogs.json").read_text())
        self.assertEqual({dialog["resource_id"] for dialog in dialogs}, {100, 131, 132, 154, 30721})
        about = next(dialog for dialog in dialogs if dialog["resource_id"] == 100)
        self.assertIn("日本語化：ま～ちゃん", [control["title"] for control in about["controls"]])
        self.assertIn("Copyright (C) 1998 -2009 by C. Dennis Posey",
                      [control["title"] for control in about["controls"]])
        design = next(dialog for dialog in dialogs if dialog["resource_id"] == 132)
        self.assertEqual(design["rect_dialog_units"], [0, 0, 308, 162])
        self.assertEqual({control["id"] for control in design["controls"]}, {1, 2, *range(1007, 1026)})
        strings = json.loads((self.assets / "ui/strings.json").read_text())
        self.assertEqual(len(strings), 293)
        self.assertEqual(strings["57344"], "TACT")
        self.assertEqual(strings["57345"], "準備完了")


class StringResourcePaddingTests(unittest.TestCase):
    def test_only_zero_padding_to_resource_alignment_is_accepted(self):
        import importlib.util
        spec = importlib.util.spec_from_file_location("extract_resources", ROOT / "tools/extract_resources.py")
        extractor = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(extractor)
        resource = struct.pack("<H", 1) + "風".encode("utf-16le") + b"\0\0" * 15
        self.assertEqual(extractor.parse_strings(resource + b"\0\0", 1), {0: "風"})
        for suffix in (b"\0\1", b"\0\0\0", b"\0\0\0\0\0\0"):
            with self.subTest(suffix=suffix):
                with self.assertRaises(ValueError):
                    extractor.parse_strings(resource + suffix, 1)


if __name__ == "__main__":
    unittest.main()
