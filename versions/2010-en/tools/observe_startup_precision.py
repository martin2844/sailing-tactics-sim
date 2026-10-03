#!/usr/bin/env python3
"""Run the fixed 2010 English read-only hardware-breakpoint startup observer.

This opens an owned normal Wine application in the existing 2010 English prefix.
Focus that application's setup window and press Space to exercise its first
frame and scene. No executable bytes, game data, or floating-point settings are
modified by the observer. The app remains open after the observer detaches.
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
EXPECTED = "d707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787"
SOURCE = EDITION / "runtime/Tactics2010EnglishPreserved.exe"
POINTS = {"004a26d4": "after CRT _controlfp FLDCW", "00404510": "first paint entry",
          "004049f0": "first connected frame entry", "00405320": "first scene entry"}


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def windows_path(path):
    return "Z:" + str(path.resolve()).replace("/", "\\")


def write_report(log, executable, output, wine_version, existing_process=False):
    rows = [json.loads(line) for line in log.read_text().splitlines() if line.strip()]
    observed = [dict(row, meaning=POINTS[row["address"]]) for row in rows if row["event"] == "hardware-breakpoint"]
    complete = next((r for r in reversed(rows) if r["event"] == "complete"), {})
    masks = 0
    for row in observed:
        if row.get("textUnchanged") is not True:
            raise ValueError("Observed instruction identity is not verified")
        masks |= 1 << list(POINTS).index(row["address"])
    valid = not existing_process and masks == 15 and complete.get("observedMask") == 15
    report = {"schemaVersion": 1, "sourceSha256": EXPECTED, "source": SOURCE.relative_to(ROOT).as_posix(),
              "scope": "Intact fixed 2010 English preservation copy through the normal Wine/Windows loader. "
              "Read-only process memory plus per-thread hardware execution breakpoints; no target "
              "instructions, game data, or x87 control words written. The observer clears its debug "
              "registers and detaches, leaving its owned app running.",
              "wineVersion": wine_version, "winePrefix": "posey-simulator-2010-en/wineprefix",
              "uiPath": "Normal setup window focused, then Space key; original keyboard and startup logic execute.",
              "attachedExistingProcess": existing_process,
              "completeStartupObservation": valid, "observed": observed,
              "allObservedControlWords": sorted({r["controlWord"] for r in observed}),
              "arithmeticPrecisionBits": 53 if observed and all(r["controlWord"] == "027f" for r in observed) else None,
              "interpretation": "0x027f masks x87 exceptions, selects round-to-nearest and 53-bit precision "
              "for arithmetic. FST/FSTP storage width and transcendental instructions still need their "
              "own exact original-code references.",
              "evidence": [{"path": p.relative_to(ROOT).as_posix(), "bytes": p.stat().st_size, "sha256": sha(p)}
                           for p in [log, executable, EDITION / "tools/native_startup_precision.c"]],
              "applicationProcessId": next((r["processId"] for r in rows if r["event"] == "started"), None),
              "completion": complete}
    output.write_text(json.dumps(report, indent=2) + "\n")
    return report


def main():
    sys.path.insert(0, str(ROOT / "tools"))
    from verify_native_reference import compile_runner, DEFAULT_GCC
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--compiler", default=os.environ.get("TACT_MINGW_CC", DEFAULT_GCC))
    parser.add_argument("--wine", default=os.environ.get("TACT_WINE", str(ROOT / "tools/wine-runtime/bin/wine")
                        if (ROOT / "tools/wine-runtime/bin/wine").exists() else shutil.which("wine")))
    parser.add_argument("--compile", action="store_true")
    parser.add_argument("--report-only", action="store_true")
    parser.add_argument("--process-id", type=int, help="Observe only frame/scene of an already-owned exact app")
    args = parser.parse_args()
    if sha(SOURCE) != EXPECTED:
        raise ValueError("Preserved 2010 English executable changed")
    executable = EDITION / "analysis/native-startup-precision.exe"
    log = EDITION / "analysis/startup-precision.jsonl"
    report_path = EDITION / "analysis/startup-precision.json"
    if args.compile or not executable.exists():
        compile_runner(args.compiler, executable, EDITION / "tools/native_startup_precision.c")
    if not args.wine:
        raise ValueError("Wine is required for intact native startup observation")
    version = subprocess.run([args.wine, "--version"], check=True, capture_output=True, text=True).stdout.strip()
    if not args.report_only:
        environment = dict(os.environ, WINEPREFIX=str(Path.home() / ".local/share/posey-simulator-2010-en/wineprefix"),
                           WINEARCH="win64", WINEDEBUG="-all", WINEDLLOVERRIDES="mscoree,mshtml=")
        command = [args.wine, str(executable), windows_path(SOURCE), windows_path(SOURCE.parent)]
        if args.process_id is not None:
            command.append(str(args.process_id))
        print("Focus the owned 2010 English setup window and press Space; observer detaches after its four fixed points.", flush=True)
        with log.open("w") as stdout, (EDITION / "analysis/startup-precision.stderr").open("w") as stderr:
            subprocess.run(command, env=environment, stdout=stdout, stderr=stderr, check=True)
    if sha(SOURCE) != EXPECTED:
        raise ValueError("Preserved 2010 executable changed during observation")
    report = write_report(log, executable, report_path, version, args.process_id is not None)
    print(json.dumps({"complete": report["completeStartupObservation"],
                      "controlWords": report["allObservedControlWords"],
                      "report": report_path.relative_to(ROOT).as_posix()}))


if __name__ == "__main__":
    main()
