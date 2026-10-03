# Original-reference function recovery

Source: `original/Tact02Demo.exe`, SHA256 `881dc85dc7500a5ad09e09091d4dd53f8c091f5630d5fabdcc887cc4b007acea`. Recovery edits Ghidra metadata only; original executable bytes were not changed.

## Result and baseline

The preserved pre-recovery project exported 1,439 functions. Current discovery exports 4,268 inferred functions and compiler/runtime funclets: 2,810 explicit evidence-supported additions and 19 automatic additions with original references. The current body union covers 512,283 bytes (97.33%) versus 459,331 bytes (87.27%) initially. All 158,242 decoded instructions belong to functions.

`analysis/recovery-baseline/` preserves the original summary/coverage and compressed combined C/index before discovery. `analysis/decompiler-baseline/` separately preserves the earlier numeric-signature baseline. Current source/evidence/file hash checks are in `analysis/decompilation-export-verification.json`.

## Evidence for additions

| Original evidence | Explicit additions |
|---|---:|
| Validated C++ unwind action pointer | 1,770 |
| Validated MFC message-map callback | 425 |
| Original immediate PUSH/MOV code pointer | 284 |
| Originally defined code pointer | 281 |
| Validated C++ catch-handler pointer | 17 |
| Original direct CALL target | 9 |
| Validated SEH3 handler | 9 |
| Validated SEH3 filter | 8 |
| Validated CRuntimeClass create-object callback | 7 |

`analysis/function-recovery.json` records every explicit address, original pointer/instruction/record bytes, source location, initial/final body size, and final inferred signature. All original evidence bytes were independently checked against the preserved PE file, including every entry's first bytes. The 19 automatic additions also have original incoming references and their bytes recorded and verified.

Message maps require contiguous six-word AFX_MSGMAP_ENTRY records, valid executable callback pointers, and a 24-byte zero terminator. Registered-message rows use a mapped data pointer for nSig; the original standard ordinal-only predicate omitted two valid tables. `tools/discover_dispatch_metadata.py` reproducibly validates all 18 tables (564 entries) and 11 CRuntimeClass create-object callback records from the original file. Some targets were already functions, so table-entry counts exceed additions.

Microsoft C++ FuncInfo, unwind, and catch maps were validated with Ghidra 12.0.4's bundled Microsoft ehdata.h models. The old imported compiler label lacks a modern Visual Studio stamp, so the script temporarily selects that model validator and restores the original label immediately. Of the scanned structures, 232 validated and two failed validation; invalid candidates were not used. Original SEH3 prologs establish another eight scope tables via PUSH -1, PUSH scope-table, PUSH original except_handler3, FS chain read, and observed original try-level stores.

Original immediate PUSH/MOV code pointers were accepted only when their target was already decoded executable orphan code. Padding/proximity alone did not seed complex functions. Compiler cleanup handlers and exception filters are exported as funclets with inferred declarations; their parent-frame semantics require care.

## Original control-flow repair

`analysis/catch-continuation-repairs.json` records 12 restored continuation/branch regions and eight removed automatic starts. Original catch handlers MOV a continuation into EAX then RET; the associated original FuncInfo handler stub and method prolog establish ownership. Ghidra had interpreted some intra-method JMPs as calls to shared-return functions. The repair restores original JMP interpretation and assigns original conditional-branch tails to the owning method. It does not modify executable instructions.

## Remaining unknown bytes

There remain 12,526 undefined bytes: 9,585 bytes in fill-only ranges and 2,941 bytes in mixed ranges. Original code remains visible in some mixed spans. No unsupported entries were fabricated to improve the percentage. See `analysis/decompiler-caveats.md` and complete `analysis/decompilation-coverage.json` ranges.

## Reproduction

Run `tools/decompile.sh` to update the saved 2002 project and export. For a new imported project, run `tools/decompile.sh --fresh /absolute/path/to/new-project-directory`; it rejects an existing tact project. The original executable hash is verified first. Scripts run sequentially: numeric signatures, supported discovery, catch-continuation ownership repair, discovery closure, coverage audit, full C export. Existing-project mode was executed and independently verified; fresh import uses the same pipeline after standard Ghidra analysis.

Requires Ghidra 12.0.4 with Jython and Java 21. The workspace's Nix runtimes are defaults; `TACT_GHIDRA_HOME`, `TACT_PYTHON`, and `JAVA_HOME` can point to compatible installations. Regenerate the checked-in dispatch candidate JSON using `python3 tools/discover_dispatch_metadata.py` when auditing the parser.
