#!/usr/bin/env python3
"""Measure fixed island predecessor reads without supplying any stack bytes.

Uses a private snapshot of the reviewed original-code host. Its four hardware
points observe only the original Y reads after 440400 allocates its frame.
Original code/data/CW are never written by the observation handler. This is a
bounded reference caller, distinct from the intact application's UI caller.
"""
from __future__ import annotations
import argparse
import importlib.util
import json
import os
from pathlib import Path
import shutil
import struct
import subprocess
import sys
import tempfile

EDITION = Path(__file__).resolve().parents[1]
ROOT = EDITION.parents[1]
sys.path.insert(0, str(EDITION / "tools"))
import capture_native as native


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output", type=Path, default=EDITION / "tests/fixtures/original-island-shore-context.json")
    parser.add_argument("--replace", action="store_true", help="Explicitly replace this derived context capture")
    args = parser.parse_args()
    if args.output.exists() and not args.replace:
        raise ValueError("Preserve existing caller evidence; choose another --output or explicitly --replace")
    manifest_path = EDITION / "analysis/initialized-island-scene-capture-inputs.json"
    manifest = json.loads(manifest_path.read_text())
    # Reuse only the actual initialization/settings, then retain the original
    # state through eight complete scene calls. No retained stack inputs.
    manifest["cases"] += [dict(manifest["cases"][-1], continue_=True) for _ in range(7)]
    for case in manifest["cases"][3:]:
        case.pop("continue_", None)
        case["continue"] = True
        case["patches"] = []
        case.pop("seed", None)
    target = EDITION / "runtime/Tactics2010EnglishPreserved.exe"
    if native.digest(target) != native.EXPECTED or manifest["sourceSha256"] != native.EXPECTED:
        raise ValueError("Fixed original target differs")
    owned = Path(tempfile.mkdtemp(prefix="shore-observer-", dir=EDITION / "analysis/native-runners"))
    source_names = ["native_reference.c", "native_gdi_trace.h", "native_controller_trace.h", "native_controller_table.h", "native_shore_reads.h"]
    source_records = []
    for name in source_names:
        source = EDITION / "tools" / name
        shutil.copyfile(source, owned / name)
        source_records.append({"path": str(source.relative_to(EDITION)), "sha256": native.digest(source)})
    source = owned / "native_reference.c"
    code = source.read_text()
    code = code.replace("static void run_case(uint32_t command) {", '#include "native_shore_reads.h"\nstatic void run_case(uint32_t command) {')
    code = code.replace('write_exact("TACT2010",8);', 'initialize_original_shore_reads();\n  write_exact("TACT2010",8);')
    code = code.replace("if (command==1 || command==3) run_case(command);", "shore_observation_case=operations-1;\n    if (command==1 || command==3) run_case(command);")
    if '#include "native_shore_reads.h"' not in code:
        raise ValueError("Reviewed host structure changed")
    source.write_text(code)
    spec = importlib.util.spec_from_file_location("build_helper", ROOT / "tools/verify_native_reference.py")
    helper = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(helper)
    executable = owned / "native-shore-reference.exe"
    try:
        flags = helper.compile_runner(helper.DEFAULT_GCC, executable, source)
    except subprocess.CalledProcessError as error:
        raise RuntimeError(error.stderr) from error
    requests = b"".join(native.encode_case(manifest, case) for case in manifest["cases"]) + struct.pack("<I", 0)
    (owned / "requests.bin").write_bytes(requests)
    environment = dict(os.environ, WINEDEBUG="-all", WINEPREFIX=str(Path.home() / ".local/share/posey-simulator-2010-en/wineprefix"))
    completed = subprocess.run([str(ROOT / "tools/wine-runtime/bin/wine"), str(executable), str(target)],
                               input=requests, capture_output=True, env=environment, timeout=120)
    (owned / "output.bin").write_bytes(completed.stdout)
    (owned / "shore-reads.jsonl").write_bytes(completed.stderr)
    if completed.returncode:
        raise RuntimeError(completed.stderr.decode(errors="replace"))
    output = completed.stdout
    if output[:8] != b"TACT2010" or struct.unpack_from("<7I", output, 8) != (1, 0x400000, 0x21c000, 0x027f, 358, native.DATA_BASE, native.DATA_BYTES):
        raise ValueError("Fixed original oracle handshake differs")
    baseline = output[36:36 + native.DATA_BYTES]
    state = bytearray(baseline)
    offset = 36 + native.DATA_BYTES
    cases = []
    observations = [json.loads(line) for line in completed.stderr.decode().splitlines()]
    if any(row["event"] != "original-shore-read" or row["controlWord"] != 0x027f for row in observations):
        raise ValueError("Unexpected hardware observation")
    for index, case in enumerate(manifest["cases"]):
        command, length = struct.unpack_from("<2I", output, offset)
        offset += 8
        if command != 1 or length > native.DATA_BYTES * 6 + 2097152 + 65536:
            raise ValueError("Fixed original response extent differs")
        expected = native.decode_case(output[offset:offset + length], manifest, case, state, baseline)
        offset += length
        reads = [row for row in observations if row["case"] == index]
        if index >= 2 and (not reads or any(row["first"] != 0 or row["last"] != 36 or row["camera"] != 1 for row in reads)):
            raise ValueError("Original first-tree consumption was not observed")
        cases.append({**case, "expected": expected, "shoreReads": reads})
    if output[offset:] != struct.pack("<3I", 0, 4, 1) or native.digest(target) != native.EXPECTED:
        raise ValueError("Original final integrity differs")
    result = {**manifest, "mutableBlock": {"address": native.DATA_BASE, "size": native.DATA_BYTES},
              "mutableBaseline": baseline.hex(), "cases": cases,
              "provenance": {"sha256": native.EXPECTED, "engine": "Original fixed x86 code under Wine, observed at four hardware execution points",
                             "x87ControlWord": "0x027f", "loadedOriginalTextUnchanged": True, "originalFileUnchanged": True,
                             "targetGameMemoryWritesByObserver": 0, "stackInputsSupplied": False,
                             "runnerSourceSha256": native.digest(source), "runnerSourceFiles": source_records,
                             "runnerSha256": native.digest(executable), "compilerFlags": flags,
                             "observerScope": "Reads inside the original already allocated 440400 frame. Owned VEH stack is below its current ESP; observed predecessor slots are above ESP. Host caller layout is explicit and distinct from intact normal UI.",
                             "rawObservations": str((owned / "shore-reads.jsonl").relative_to(EDITION))}}
    destination = args.output.resolve()
    destination.parent.mkdir(parents=True, exist_ok=True)
    destination.write_text(json.dumps(result, indent=2) + "\n")
    print(json.dumps({"calls": len(cases), "reads": len(observations), "fixture": str(destination.relative_to(EDITION)),
                      "previousTreeY": sorted({row["previousTreeY"] for row in observations})}))


if __name__ == "__main__":
    main()
