#!/usr/bin/env bash
# Rebuild the preserved 2002 binary's inferred decompilation and evidence.
set -euo pipefail
TACT_ROOT="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd)"
TACT_PROJECT_DIR="$TACT_ROOT/decompiled/ghidra-project"
TACT_MODE=process
case "${1:-}" in
  --fresh)
    if [[ $# -ne 2 ]]; then printf 'Usage: %s [--fresh NEW_PROJECT_DIRECTORY]\n' "$0" >&2; exit 2; fi
    TACT_PROJECT_DIR="$2"
    TACT_MODE=import
    if [[ -e "$TACT_PROJECT_DIR/tact.gpr" || -e "$TACT_PROJECT_DIR/tact.rep" ]]; then
      printf 'Fresh import requires a new project directory: %s\n' "$TACT_PROJECT_DIR" >&2
      exit 2
    fi
    ;;
  '') ;;
  *) printf 'Usage: %s [--fresh NEW_PROJECT_DIRECTORY]\n' "$0" >&2; exit 2 ;;
esac
TACT_BINARY="$TACT_ROOT/original/Tact02Demo.exe"
TACT_EXPECTED_SHA=881dc85dc7500a5ad09e09091d4dd53f8c091f5630d5fabdcc887cc4b007acea
TACT_ACTUAL_SHA="$(sha256sum -- "$TACT_BINARY")"
if [[ "${TACT_ACTUAL_SHA%% *}" != "$TACT_EXPECTED_SHA" ]]; then
  printf 'Original 2002 executable SHA256 does not match preserved source.\n' >&2
  exit 1
fi
TACT_GHIDRA="${TACT_GHIDRA_HOME:-$TACT_ROOT/tools/ghidra-runtime}"
TACT_LAUNCHER="$TACT_GHIDRA/bin/ghidra-analyzeHeadless"
if [[ ! -x "$TACT_LAUNCHER" && -x "$TACT_GHIDRA/support/analyzeHeadless" ]]; then
  TACT_LAUNCHER="$TACT_GHIDRA/support/analyzeHeadless"
fi
TACT_PYTHON="${TACT_PYTHON:-/nix/store/d5928y3hxnzhf5xx9lxwa4ab3qycfmpb-python3-3.13.15/bin/python3}"
if [[ ! -x "$TACT_PYTHON" ]]; then TACT_PYTHON="$(command -v python3)"; fi
if [[ -z "${JAVA_HOME:-}" && -d /nix/store/ikk8j180lhdwv20aiabvcic2mk8c9xna-openjdk-21.0.12.1+1 ]]; then
  export JAVA_HOME=/nix/store/ikk8j180lhdwv20aiabvcic2mk8c9xna-openjdk-21.0.12.1+1
fi
if [[ ! -x "$TACT_LAUNCHER" ]]; then printf 'Set TACT_GHIDRA_HOME to Ghidra 12.0.4 runtime.\n' >&2; exit 1; fi
mkdir -p -- "$TACT_PROJECT_DIR" "$TACT_ROOT/analysis" "$TACT_ROOT/decompiled"
TACT_PROJECT_DIR="$(cd -- "$TACT_PROJECT_DIR" && pwd)"
TACT_ARGUMENTS=("$TACT_PROJECT_DIR" tact)
if [[ "$TACT_MODE" == import ]]; then
  TACT_ARGUMENTS+=(-import "$TACT_BINARY")
else
  if [[ ! -e "$TACT_PROJECT_DIR/tact.gpr" ]]; then
    printf 'No saved Ghidra project. Use --fresh NEW_PROJECT_DIRECTORY.\n' >&2; exit 1
  fi
  TACT_ARGUMENTS+=(-process Tact02Demo.exe -noanalysis)
fi
# Fresh import runs Ghidra's standard analysis before these sequential scripts.
# Existing project processing retains the saved numeric and ownership repairs.
TACT_ARGUMENTS+=(-scriptPath "$TACT_ROOT/tools"
  -postScript FixNumericSignatures.py "$TACT_ROOT/decompiled"
  -postScript RecoverFunctions.py "$TACT_ROOT/analysis/message-map-candidates.json" "$TACT_ROOT/analysis/function-recovery.json" "$TACT_ROOT/analysis/runtime-class-candidates.json"
  -postScript RepairCatchContinuations.py "$TACT_ROOT/analysis/function-recovery.json" "$TACT_ROOT/analysis/catch-continuation-repairs.json"
  -postScript RecoverFunctions.py "$TACT_ROOT/analysis/message-map-candidates.json" "$TACT_ROOT/analysis/function-recovery.json" "$TACT_ROOT/analysis/runtime-class-candidates.json"
  -postScript FixCStringSignatures.py "$TACT_ROOT/analysis/drawing-corrections"
  -postScript FixDrawingSignatures.py "$TACT_ROOT/analysis/drawing-corrections"
  -postScript AuditDecompilationCoverage.py "$TACT_ROOT/decompiled" "$TACT_ROOT/analysis/decompilation-coverage.json"
  -postScript ExportDecompilation.py "$TACT_ROOT/decompiled")
printf 'Processing original 2002 executable; log: %s\n' "$TACT_ROOT/analysis/decompilation.log"
"$TACT_LAUNCHER" "${TACT_ARGUMENTS[@]}" > "$TACT_ROOT/analysis/decompilation.log" 2>&1
if ! rg -q 'EXPORT_COMPLETE' "$TACT_ROOT/analysis/decompilation.log" || rg -q 'Traceback|SCRIPT ERROR|Error running script|SyntaxError' "$TACT_ROOT/analysis/decompilation.log"; then
  printf 'A Ghidra script failed; inspect analysis/decompilation.log.\n' >&2
  tail -n 30 "$TACT_ROOT/analysis/decompilation.log" >&2
  exit 1
fi
"$TACT_PYTHON" "$TACT_ROOT/tools/verify_decompilation.py"
"$TACT_PYTHON" - "$TACT_ROOT/decompiled/summary.json" "$TACT_ROOT/analysis/decompilation-coverage.json" <<'PY'
import json,sys
summary=json.load(open(sys.argv[1])); coverage=json.load(open(sys.argv[2]))['totals']
print(json.dumps({'export':summary,'coverage':coverage},sort_keys=True,indent=2))
PY
