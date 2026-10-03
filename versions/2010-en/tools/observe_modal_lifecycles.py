#!/usr/bin/env python3
"""Observe eight actual unchanged 2010 English modal-window lifecycles.

The original application's MFC routing and dialog controls run normally. Fixed
hardware points observe the original EndDialog/InvalidateRect calls and selected
game globals; no target code, game data or floating-point settings are written.
"""
from __future__ import annotations
import argparse
import hashlib
import json
import os
import shutil
import subprocess
import sys
from pathlib import Path

EDITION = Path(__file__).resolve().parents[1]
ROOT = EDITION.parents[1]
SOURCE = EDITION / "runtime/Tactics2010EnglishPreserved.exe"
EXPECTED = "d707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787"


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def windows_path(path):
    return "Z:" + str(path.resolve()).replace("/", "\\")


def collect(log, executable, wine_version):
    rows = [json.loads(line) for line in log.read_text().splitlines() if line.strip()]
    complete = rows[-1]
    if complete != {"event": "complete", "cases": 8, "textUnchanged": True, "targetGameMemoryWrites": 0}:
        raise ValueError("Actual modal observation is incomplete")
    cases = []
    for row in rows:
        if row["event"] == "scenario":
            cases.append({key: row[key] for key in ["case", "resource", "command", "control", "result"]} | {"observations": []})
        elif row["event"] == "observation":
            if row["case"] != cases[-1]["case"] or not row["textUnchanged"]:
                raise ValueError("Modal observation identity or ordering differs")
            cases[-1]["observations"].append(row)
    if len(cases) != 8:
        raise ValueError("Expected the eight fixed modal scenarios")
    for case in cases:
        points = [row["point"] for row in case["observations"]]
        expected = ["before-command", "command-entry"]
        if case["resource"] == 131:
            expected += ["invalidate"]
        expected += ["radio-return", "end-dialog", "end-dialog-return"]
        if case["resource"] == 131:
            expected += ["invalidate"]
        expected += ["modal-return", "invalidate", "tail-complete"]
        if points != expected:
            raise ValueError("Actual modal point order differs: " + str(points))
        if any(row["controlWord"] != 0x027f for row in case["observations"] if row["address"]):
            raise ValueError("Unexpected original modal arithmetic control word")
    provenance = {"sourceSha256": EXPECTED, "engine": "Intact original 2010 English app through the normal Windows loader under Wine",
                  "wineVersion": wine_version, "x87ControlWord": "027f", "loadedOriginalTextUnchanged": True,
                  "targetGameMemoryWrites": 0,
                  "scope": "Normal original Custom boat menu command32789 followed by normal F input, Design132/Helm131 menu routing, actual radio controls and actual OK/Cancel buttons. Only fixed original EndDialog/InvalidateRect source calls and18 game globals are observed. Whole mutable-block SHA is retained as raw evidence; it is not a claim of framework state equivalence.",
                  "limitations": "Eight genuine setup-screen modal lifecycles. Framework allocation, other Windows messages, modal raster output and whole MFC lifetime are outside these selected-game-global comparisons. Original dialog/frame HWND values are retained; the browser supplies its own host windows.",
                  "evidence": [{"path": path.relative_to(EDITION).as_posix(), "bytes": path.stat().st_size, "sha256": sha(path)}
                               for path in [log, executable, EDITION / "tools/native_modal_observer.c"]]}
    return {"format": 1, "provenance": provenance, "cases": cases}


def main():
    sys.path.insert(0, str(ROOT / "tools"))
    from verify_native_reference import compile_runner, DEFAULT_GCC
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--compiler", default=os.environ.get("TACT_MINGW_CC", DEFAULT_GCC))
    parser.add_argument("--wine", default=os.environ.get("TACT_WINE", str(ROOT / "tools/wine-runtime/bin/wine")
                        if (ROOT / "tools/wine-runtime/bin/wine").exists() else shutil.which("wine")))
    parser.add_argument("--process-id", type=int, help="Revalidate and attach to this exact already-owned app")
    parser.add_argument("--report-only", action="store_true")
    args = parser.parse_args()
    if sha(SOURCE) != EXPECTED:
        raise ValueError("Exact preserved source changed")
    executable = EDITION / "analysis/native-modal-observer.exe"
    log = EDITION / "analysis/modal-lifecycles.jsonl"
    if not args.report_only:
        compile_runner(args.compiler, executable, EDITION / "tools/native_modal_observer.c")
        working = EDITION / "analysis/modal-observation-session"
        working.mkdir(parents=True, exist_ok=True)
        environment = dict(os.environ, WINEPREFIX=str(Path.home() / ".local/share/posey-simulator-2010-en/wineprefix"),
                           WINEARCH="win64", WINEDEBUG="-all", WINEDLLOVERRIDES="mscoree,mshtml=")
        command = [args.wine, str(executable), windows_path(SOURCE), windows_path(working)]
        if args.process_id is not None:
            command.append(str(args.process_id))
        with log.open("w") as stdout, (EDITION / "analysis/modal-lifecycles.stderr").open("w") as stderr:
            subprocess.run(command, env=environment, stdout=stdout, stderr=stderr, check=True)
    if sha(SOURCE) != EXPECTED:
        raise ValueError("Exact source changed during observation")
    version = subprocess.run([args.wine, "--version"], check=True, capture_output=True, text=True).stdout.strip()
    fixture = collect(log, executable, version)
    target = EDITION / "tests/fixtures/original-modal-lifecycles.json"
    target.write_text(json.dumps(fixture, indent=2) + "\n")
    report = {"format": 1, "sourceSha256": EXPECTED, "cases": 8, "actualWindowsDialogs": [131, 132],
              "loadedOriginalTextUnchanged": True, "targetGameMemoryWrites": 0,
              "fixture": {"path": target.relative_to(EDITION).as_posix(), "bytes": target.stat().st_size, "sha256": sha(target)},
              "scope": fixture["provenance"]["scope"], "limitations": fixture["provenance"]["limitations"],
              "observations": sum(len(case["observations"]) for case in fixture["cases"]),
              "allActualModalResultsMatchClickedButton": all(next(row for row in case["observations"] if row["point"] == "modal-return")["eax"] == case["result"] for case in fixture["cases"])}
    (EDITION / "analysis/modal-native-reference-comparison.json").write_text(json.dumps(report, indent=2) + "\n")
    print(json.dumps({"cases": 8, "observations": report["observations"], "fixture": str(target.relative_to(EDITION))}))


if __name__ == "__main__":
    main()
