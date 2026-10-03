#!/usr/bin/env bash
# Recover the exact English 2010 target; original runtime bytes remain untouched.
set -euo pipefail
TACT_2010_ROOT="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd)"
TACT_SHARED_ROOT="$(cd -- "$TACT_2010_ROOT/../.." && pwd)"
TACT_2010_BINARY="$TACT_2010_ROOT/runtime/Tactics2010EnglishPreserved.exe"
TACT_2010_EXPECTED_SHA=d707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787
TACT_2010_ACTUAL_SHA="$(sha256sum -- "$TACT_2010_BINARY")"
if [[ "${TACT_2010_ACTUAL_SHA%% *}" != "$TACT_2010_EXPECTED_SHA" ]]; then
  printf '2010 English target SHA256 differs from its preserved source.\n' >&2; exit 1
fi
TACT_2010_PROJECT="$TACT_2010_ROOT/decompiled/ghidra-project"
TACT_2010_GHIDRA="${TACT_GHIDRA_HOME:-$TACT_SHARED_ROOT/tools/ghidra-runtime}"
TACT_2010_LAUNCHER="$TACT_2010_GHIDRA/bin/ghidra-analyzeHeadless"
if [[ ! -x "$TACT_2010_LAUNCHER" ]]; then TACT_2010_LAUNCHER="$TACT_2010_GHIDRA/support/analyzeHeadless"; fi
if [[ ! -x "$TACT_2010_LAUNCHER" ]]; then printf 'Set TACT_GHIDRA_HOME to a Ghidra runtime.\n' >&2; exit 1; fi
if [[ -z "${JAVA_HOME:-}" && -d /nix/store/ikk8j180lhdwv20aiabvcic2mk8c9xna-openjdk-21.0.12.1+1 ]]; then
  export JAVA_HOME=/nix/store/ikk8j180lhdwv20aiabvcic2mk8c9xna-openjdk-21.0.12.1+1
fi
mkdir -p -- "$TACT_2010_PROJECT" "$TACT_2010_ROOT/decompiled" "$TACT_2010_ROOT/analysis"
TACT_2010_ARGUMENTS=("$TACT_2010_PROJECT" tact2010en)
if [[ -f "$TACT_2010_PROJECT/tact2010en.gpr" ]]; then
  TACT_2010_ARGUMENTS+=(-process Tactics2010EnglishPreserved.exe -noanalysis)
else
  TACT_2010_ARGUMENTS+=(-import "$TACT_2010_BINARY")
fi
TACT_2010_ARGUMENTS+=(-scriptPath "$TACT_2010_ROOT/tools;$TACT_SHARED_ROOT/tools"
  -postScript RecoverFunctions.py "$TACT_2010_ROOT/analysis/message-map-candidates.json" "$TACT_2010_ROOT/analysis/function-recovery.json" "$TACT_2010_ROOT/analysis/runtime-class-candidates.json"
  -postScript RepairCatchContinuations.py "$TACT_2010_ROOT/analysis/function-recovery.json" "$TACT_2010_ROOT/analysis/catch-continuation-repairs.json"
  -postScript RecoverFunctions.py "$TACT_2010_ROOT/analysis/message-map-candidates.json" "$TACT_2010_ROOT/analysis/function-recovery.json" "$TACT_2010_ROOT/analysis/runtime-class-candidates.json"
  -postScript FixNumericSignatures.py "$TACT_2010_ROOT/analysis"
  -postScript FixAISignatures.py "$TACT_2010_ROOT/analysis"
  -postScript FixCStringSignatures.py "$TACT_2010_ROOT/analysis"
  -postScript FixDrawingSignatures.py "$TACT_2010_ROOT/analysis/drawing-corrections"
  -postScript AuditDecompilationCoverage.py "$TACT_2010_ROOT/decompiled" "$TACT_2010_ROOT/analysis/decompilation-coverage.json"
  -postScript ExportDecompilation.py "$TACT_2010_ROOT/decompiled")
"$TACT_2010_LAUNCHER" "${TACT_2010_ARGUMENTS[@]}" > "$TACT_2010_ROOT/analysis/decompilation.log" 2>&1
if ! rg -q 'EXPORT_COMPLETE' "$TACT_2010_ROOT/analysis/decompilation.log" || rg -q 'Traceback|SCRIPT ERROR|Error running script|SyntaxError' "$TACT_2010_ROOT/analysis/decompilation.log"; then
  tail -n 35 "$TACT_2010_ROOT/analysis/decompilation.log" >&2; exit 1
fi
TACT_2010_FINAL_SHA="$(sha256sum -- "$TACT_2010_BINARY")"
[[ "${TACT_2010_FINAL_SHA%% *}" == "$TACT_2010_EXPECTED_SHA" ]]
printf '2010 English decompilation complete; original target unchanged.\n'
