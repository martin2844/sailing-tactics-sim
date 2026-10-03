#!/usr/bin/env python3
"""Bounded integrity checks for the exact 2010 English browser inputs."""
import importlib.util
import json
import tempfile
import unittest
from pathlib import Path

SPEC = importlib.util.spec_from_file_location("english_assets", Path(__file__).with_name("extract_assets.py"))
ASSETS = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(ASSETS)


class AssetIntegrity(unittest.TestCase):
    def test_complete_reproduction_matches_public_data(self):
        ASSETS.verify(ASSETS.EDITION / "assets")

    def test_resource_directory_uses_translated_section(self):
        data = ASSETS.source_data()
        metadata, pe = ASSETS.layout(data)
        active = next(row for row in metadata["directories"] if row["name"] == "resource")
        english = next(row for row in metadata["sections"] if row["name"] == ".english")
        self.assertEqual(active["rva"], english["virtual_address"])
        self.assertEqual(len(pe.resources()), 76)
        menu = next(row for row in pe.resources() if row["type"] == 4)
        tree = ASSETS.resources.parse_menu(menu["data"])
        def nodes(items):
            for row in items:
                yield row
                yield from nodes(row.get("items", []))
        commands = {row["command_id"]: row["text"] for row in nodes(tree["items"]) if row.get("command_id")}
        self.assertEqual(commands[33105], "E Scow")
        self.assertEqual(commands[33106], "Flying Scot")
        self.assertEqual(len(commands), 312)

    def test_exact_localized_padding_and_leading_nuls(self):
        data = ASSETS.source_data()
        _, pe = ASSETS.layout(data)
        entries = ASSETS.embedded_text(data, pe)["entries"]
        self.assertEqual(sum(row["leadingNul"] for row in entries), 2)
        sample = next(row for row in entries if row["originalAddress"] == 0x4da310)
        self.assertEqual(sample["text"], "Blanket. Jibe ")
        for row in entries:
            payload = row["text"].encode("cp1252") + b"\0"
            self.assertEqual(data[row["fileOffset"]:row["fileOffset"] + row["bytes"]], payload)

    def test_rejects_mutated_asset_and_source(self):
        with tempfile.TemporaryDirectory(prefix="tact-2010-integrity-") as directory:
            output = Path(directory)
            ASSETS.generate(output)
            target = output / "data/original-initial-state.bin"
            data = bytearray(target.read_bytes())
            data[-1] = 1
            target.write_bytes(data)
            with self.assertRaisesRegex(ValueError, "Exact extraction mismatch"):
                ASSETS.verify(output)
            source = ASSETS.SOURCE
            counterfeit = output / "changed.exe"
            wrong = bytearray(source.read_bytes())
            wrong[0x3c] ^= 1
            counterfeit.write_bytes(wrong)
            try:
                ASSETS.SOURCE = counterfeit
                with self.assertRaisesRegex(ValueError, "unchanged preserved 2010 English"):
                    ASSETS.source_data()
            finally:
                ASSETS.SOURCE = source

    def test_browser_segments_exclude_code_and_imports(self):
        manifest = json.loads((ASSETS.EDITION / "assets/data/original-memory.json").read_text())
        data = ASSETS.source_data()
        layout, _ = ASSETS.layout(data)
        self.assertEqual({row["section"] for row in manifest["segments"]}, {".rdata", ".data", ".english"})
        for row in manifest["segments"]:
            section = next(s for s in layout["sections"] if s["name"] == row["section"])
            self.assertFalse(section["executable"])
            content = (ASSETS.EDITION / "assets/data" / row["file"]).read_bytes()
            initialized = data[section["raw_offset"]:section["raw_offset"] + section["raw_size"]]
            self.assertEqual(content[:row["initializedBytes"]], initialized)
            self.assertEqual(content[row["initializedBytes"]:], bytes(row["zeroFillBytes"]))


if __name__ == "__main__":
    unittest.main()
