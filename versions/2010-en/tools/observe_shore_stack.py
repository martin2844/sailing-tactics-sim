#!/usr/bin/env python3
"""Observe genuine island predecessor reads through normal intact-app UI.

Every launch owns a private working directory and an exact fixed target child.
No existing app is attached or closed. Original menus/key handlers execute;
hardware points only read original stack/state and are cleared before detach.
"""
from __future__ import annotations
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys
import tempfile

EDITION = Path(__file__).resolve().parents[1]
ROOT = EDITION.parents[1]
SOURCE = EDITION / "runtime/Tactics2010EnglishPreserved.exe"
EXPECTED = "d707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787"


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def windows_path(path):
    return "Z:" + str(path.resolve()).replace("/", "\\")


def collect(log):
    rows = [json.loads(line) for line in log.read_text().splitlines() if line.strip()]
    if rows[-1] != {"event": "complete", "samples": 3, "textUnchanged": True, "targetGameMemoryWrites": 0}:
        raise ValueError("Actual first predecessor consumption was not fully observed")
    samples = []
    for row in rows:
        if row["event"] == "shore-entry":
            if row["sample"] != len(samples) or row["controlWord"] != 0x027f or not row["textUnchanged"]:
                raise ValueError("Original entry identity differs")
            samples.append({"entry": row, "reads": []})
        elif row["event"] in ("shore-context", "shore-gates"):
            samples[-1][row["event"].removeprefix("shore-")] = row
        elif row["event"] == "first-tree-branch":
            samples[row["sample"]]["branch"] = row
        elif row["event"] == "consumed-retained-input":
            samples[row["sample"]]["reads"].append(row)
        elif row["event"] == "shore-return":
            samples[row["sample"]]["exit"] = row
    for sample in samples:
        entry = sample["entry"]
        if [row["field"] for row in sample["reads"]] != ["previousX", "previousTreeY"]:
            raise ValueError("Both actual original input reads are required")
        for read in sample["reads"]:
            field = read["field"]
            address = entry["entryEsp"] + (-0xb54 if field == "previousX" else -0x880) + 4 * entry["first"]
            if read["address"] != address or read["value"] != entry[field]:
                raise ValueError("Actual consumed slot differs from recorded original entry")
        if (entry["first"], entry["last"], entry["camera"]) != (0, 36, 1):
            raise ValueError("Intact reference caller domain differs")
        context = sample["context"]
        if (context["course"], context["island"], context["variant"], context["displaySetting"]) != (7, 1, 0, 12):
            raise ValueError("Normal island UI caller context differs")
    for before, after in zip(samples, samples[1:]):
        for field in ("previousX", "previousTreeY", "centerProjectedY"):
            if before["exit"][field] != after["entry"][field]:
                raise ValueError("Original retained predecessor transition differs")
    return rows, samples


def main():
    sys.path.insert(0, str(ROOT / "tools"))
    from verify_native_reference import compile_runner, DEFAULT_GCC
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--launches", type=int, default=2, choices=(1, 2, 3))
    parser.add_argument("--compiler", default=os.environ.get("TACT_MINGW_CC", DEFAULT_GCC))
    parser.add_argument("--wine", default=os.environ.get("TACT_WINE", str(ROOT / "tools/wine-runtime/bin/wine")))
    args = parser.parse_args()
    if sha(SOURCE) != EXPECTED:
        raise ValueError("Exact original target differs")
    owned = Path(tempfile.mkdtemp(prefix="intact-island-", dir=EDITION / "analysis"))
    source = owned / "native_live_shore.c"
    shutil.copyfile(EDITION / "tools/native_live_shore.c", source)
    executable = owned / "native-live-shore.exe"
    try:
        flags = compile_runner(args.compiler, executable, source)
    except subprocess.CalledProcessError as error:
        raise RuntimeError(error.stderr) from error
    environment = dict(os.environ, WINEPREFIX=str(Path.home() / ".local/share/posey-simulator-2010-en/wineprefix"),
                       WINEARCH="win64", WINEDEBUG="-all", WINEDLLOVERRIDES="mscoree,mshtml=")
    launches = []
    for index in range(args.launches):
        work = owned / f"working-{index}"
        work.mkdir()
        log = owned / f"launch-{index}.jsonl"
        with log.open("w") as stdout, (owned / f"launch-{index}.stderr").open("w") as stderr:
            completed = subprocess.run([args.wine, str(executable), windows_path(SOURCE), windows_path(work)],
                                       stdout=stdout, stderr=stderr, env=environment, timeout=75)
        if completed.returncode:
            raise ValueError(f"Incomplete intact observation preserved at {owned}")
        rows, samples = collect(log)
        published_log = EDITION / f"analysis/intact-island-shore-stack-{index}.jsonl"
        shutil.copyfile(log, published_log)
        launches.append({"log": str(published_log.relative_to(EDITION)), "logSha256": sha(published_log),
                         "processId": rows[0]["processId"], "samples": samples})
    if sha(SOURCE) != EXPECTED:
        raise ValueError("Original file changed during observation")
    report = {"format": 1, "sourceSha256": EXPECTED, "x87ControlWord": "0x027f",
              "targetGameMemoryWrites": 0, "loadedOriginalTextUnchanged": True,
              "normalUiPath": "Round the Island command32801 → Start32771 → original Space → display detail32970 (12). Original handlers and normal paint/scene caller execute.",
              "scope": "First0,last36,camera1,course7,island1,variant0,display12; separately owned normal-loader Wine launches with private working directories. Initial raw stack values are caller observations, not universal C initializers.",
              "observer": {"sourceSha256": sha(source), "runnerSha256": sha(executable), "compilerFlags": flags,
                           "source": "analysis/intact-island-shore-observer-source.c", "runner": str(executable.relative_to(EDITION))},
              "launches": launches, "sampleCount": sum(len(row["samples"]) for row in launches),
              "initialObservedStacks": [{field: row["samples"][0]["entry"][field]
                                          for field in ("centerProjectedY", "previousX", "previousTreeY")} for row in launches]}
    shutil.copyfile(source, EDITION / "analysis/intact-island-shore-observer-source.c")
    destination = EDITION / "analysis/intact-island-shore-stack.json"
    destination.write_text(json.dumps(report, indent=2) + "\n")
    print(json.dumps({"launches": len(launches), "samples": report["sampleCount"], "initialStacks": report["initialObservedStacks"],
                      "report": str(destination.relative_to(EDITION))}))


if __name__ == "__main__":
    main()
