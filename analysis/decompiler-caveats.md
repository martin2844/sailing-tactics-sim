# Decompiler coverage and semantic caveats

All 4,268 inferred functions and runtime funclets in the saved Ghidra project were exported with zero failures. Function hashes, index/file equality, combined-C inclusion, original recovery-evidence bytes, and provenance hashes were independently verified in `analysis/decompilation-export-verification.json`. This completes the export of the recovered set; it does not establish full executable recovery or source-level correctness.

## Executable-memory coverage

`tools/AuditDecompilationCoverage.py` measures byte unions in the executable `.text` block, `00401000` through `004817ff`; complete ranges are in `analysis/decompilation-coverage.json`.

| Measurement | Initial analysis | Current recovered project |
|---|---:|---:|
| Inferred functions / funclets | 1,439 | 4,268 |
| .text memory bytes | 526,336 | 526,336 |
| Function body bytes | 459,331 (87.27%) | 512,283 (97.33%) |
| Analyzed instructions | 146,287 / 472,183 bytes | 158,242 / 512,283 bytes |
| Instructions outside functions | 3,930 / 12,852 bytes | 0 / 0 bytes |
| Defined data in .text | 693 items / 1,527 bytes | 693 items / 1,527 bytes |
| Undefined .text bytes | 52,626 | 12,526 |

Instruction bytes + defined data + undefined bytes equal the full block size. All decoded instructions now belong to functions; `decompiled/unassigned-instructions.asm` contains only its explanatory header. Earlier missing MFC menu handlers and pointer helpers were recovered from original message maps, callbacks, and compiler exception metadata. Eight automatically invented starts were removed when original catch-return continuations showed that they were shared method tails.

The undefined bytes comprise 9,585 bytes in ranges made entirely of 00/90/CC and 2,941 bytes in other mixed ranges. Fill-byte composition is a classification aid, not proof of padding. Some mixed ranges clearly contain additional runtime instructions, but no supported incoming reference has established their entries.

Largest remaining mixed undefined spans:

| Start | End | Bytes |
|---|---|---:|
| `00461382` | `0046164f` | 718 |
| `004642d7` | `0046443f` | 361 |
| `00461f6a` | `004620bf` | 342 |
| `00465bbf` | `00465d0f` | 337 |
| `004626bf` | `004627ff` | 321 |
| `0045c7ce` | `0045c84f` | 130 |
| `004658e1` | `0046593f` | 95 |
| `0045c543` | `0045c58f` | 77 |
| `00462d1f` | `00462d5f` | 65 |
| `0045616d` | `004561a6` | 58 |

For example, original bytes at `00461390` resemble CRT file-handle cleanup followed by other padding-separated routines. Their boundaries, ownership, and reachability remain unverified. They were preserved as unknown rather than assigned arbitrary function starts. `analysis/function-recovery.md` documents the evidence and historical baseline.

## Corrected numeric inference

`tools/FixNumericSignatures.py` changes Ghidra analysis metadata and its program-specific p-code model. Original executable bytes remain unchanged. `decompiled/signature-corrections.json` records the original/current declarations and `numeric-corrections/*.asm` records the original instructions. Baseline C and function metadata remain under `analysis/decompiler-baseline/`.

| Function | Correction and evidence |
|---|---|
| `004570b0` / __ftol | Declare an 80-bit ST0 input and retain the EDX:EAX signed 64-bit return. Add a callfixup modeling truncation, x87 stack pop, and return-address stack compensation. |
| `00429df0` | Declare a floating return in ST0 with two integer arguments. Caller consumption and retained x87 pressure show the value is returned. Pressure and square-root magnitude are restored in C. |
| `00413cd0` | Declare double argument/return, matching stack input and ST0 output of angle normalization. |
| `0041bb10` | Declare int return with two int arguments. Original code calls `00413cb0` to wrap the converted angle, then `ADD ESP,4; RET` without changing EAX. The corrected C returns the wrapping result. |
| `00420b70`, `00420c40`, `00420d10` | Declare explicit 80-bit ST0 returns and exactly three int arguments at stack offsets +4/+8/+12. Default Windows cdecl inference treats float10 as a hidden return pointer, which the original does not use. Explicit custom storage restores the original ABI and the unrounded values consumed by __ftol. |
| `00428ab0`, `00426f50`, `004139d0` | Declare direct 80-bit ST0 results, preserving unrounded distance, signed-start distance and crew scale. Original native return captures verify binary64 and all ten extended bytes. |
| `00412f60`, `00413100` | Restore two packed stack doubles for the original curved/flat hull geometry. |
| `00413a20`, `00413370`, `00414010` | Restore original packed mixed double/integer crew and sail geometry stack words. Native full-state captures verify these contracts. |

In `00420c40`, the x-axis normalized value is spilled to a qword without popping ST0, then the rounded qword is multiplied by the extended ST0 value. The y-axis square has no intervening qword store. Corrected C preserves that asymmetry as `fVar1 * (float10)(double)fVar1`; treating both squares as ordinary binary64 changes the original result.

Important: the standalone `004570b0.c` still prints `ROUND(x87_value)`. Ghidra's generic FISTP p-code does not consult the changed x87 rounding-control word. The original helper sets truncation mode before conversion and restores the word afterward. The custom callfixup makes callers use truncation and preserve the remaining x87 stack values; do not copy the standalone ROUND expression into JavaScript.

The callfixup models dataflow for finite values representable as signed 64-bit integers. It does not model exception flags, masked invalid-conversion sentinel values, or hardware traps. Inputs near conversion boundaries need native-reference fixtures.

## Corrected drawing and string metadata

`tools/FixCStringSignatures.py` restores five original output-object/string contracts. The three concat helpers use original stdcall `RET 12`; game numeric formatters remain cdecl. Explicit stack storage prevents eight-byte alignment gaps absent from the original i386 callers. `tools/FixDrawingSignatures.py` restores twenty-three reviewed drawing signatures and 2,079 CDC/import call prototypes, including original dynamically observed HUD/chart calls and original import aliases. The verified evidence files retain source hashes and verify the recorded original CALL instructions. The saved script order is CString then Drawing.

These changes repair decompiler dataflow; they do not make unresolved parent-frame registers or all indirect function pointers portable. The current combined C SHA256 is `9ddce9a7e5513a4b2ab33fca0f0bef655e53517835332159a34a3ba3d1803a9b`; its 4,268 function files and provenance were independently verified after the saved export.

## Remaining automatic-C artifacts

Counts below are from the current individual C files; declarations and uses both count as occurrences. The increase in `unaff_` comes mainly from recovered exception cleanup funclets accessing their parent's EBP frame.

| Pattern | Functions | Occurrences |
|---|---:|---:|
| `unaff_` | 1,992 | 6,688 |
| `extraout_` | 111 | 690 |
| `WARNING: Could not recover jumptable` | 28 | 31 |
| `WARNING: Treating indirect jump as call` | 28 | 31 |
| `WARNING: Globals starting` | 173 | 173 |

The x87 audit found zero `extraout_ST*` / `unaff_ST*` / `in_ST*` artifacts and zero no-argument `__ftol()` calls. All nine fpatan expressions assign their result. This verifies those specific artifacts, not every numeric function.

Concrete remaining caveats:

- `0040db30.c` contains unresolved ESI/EDI register assumptions in comparisons, drawing, and indirect calls.
- `00437950.c` includes Windows FS exception-chain setup. Recovered cleanup funclets such as `00480af0.c` use their parent's EBP frame; ordinary C parameter inference cannot express that convention directly.
- `00462806.c` prints an apparent recursive `ReuseDDElParam` call around an import jump. This is a thunk artifact.
- Original catch handlers return continuation code addresses. `tools/RepairCatchContinuations.py` restores ownership and direct branches; native exception dispatch still needs explicit browser behavior if it matters in a supported scenario.

Functions with unresolved indirect-jump warnings:

`00455be0`, `00455be8`, `00455da8`, `00456990`, `004569d0`, `00456be0`, `00458ad0`, `00462800`, `00462806`, `0046280c`, `00462812`, `00462818`, `0046281e`, `00462824`, `0046282a`, `00462830`, `0046895f`, `0046ad0b`, `0046ad25`, `0046ae73`, `0046aeb5`, `0046ebdd`, `0046ec24`, `0046ee28`, `00472436`, `00472446`, `00472672`, `004727b9`.

Original shoreline rendering at `0042d120` also reads retained local stack values in some island/tree branches. Observed reads include `entryESP-0xb6c` and prior local-array entries at `entryESP-0xb54+first*4` / `entryESP-0x2d8+first*4`. Standalone branches whose values are defined can be tested independently; connected caller capture is needed for the retained cases. Treating these as initialized zeroes would invent behavior.

Ghidra's `decompileCompleted` means C text was produced. It does not validate inferred signatures, pointer types, structure layouts, or branches. Exported function/funclet count is not the count of original source functions. Windows runtime code, indirect callbacks, and overlapping globals prevent treating this dump as ordinary compilable source.

## Browser-parity implications

The original uses 32-bit signed arithmetic, x87 extended intermediates, explicit double stores, and native trigonometric instructions. JavaScript Number is binary64 and bitwise coercions have distinct rules. Preserve each integer truncation/store and compare outputs against original-code fixtures at angle and conversion boundaries. Pseudo-C fpatan, fsin, fcos, and SQRT need explicit behavioral definitions.

Live intact startup and first complete paint/frame/scene calls use x87 control word `0x027f`, selecting 53-bit arithmetic. Hardware execution breakpoints observed the word without instruction or control-word writes, and verified unchanged original `.text`. See `analysis/startup-precision.json`. Explicit m80 loads retain their full stored precision, while arithmetic rounds according to the current word; JavaScript ports must model both the active arithmetic precision and original binary64 spills. Separate startup-context references are in `assets/data/pc53/`; earlier `0x037f` assets remain intact.

Completed current native evidence has **98,775 verified cases** across **209 complete original routine addresses**: 98,472 isolated calls, 300 retained frames and three connected initialization lifetimes. The initialization lifetimes run five original initialization leaves plus the exact viewport-calibration fragment; fragment `00403c62..00403cb9` is separately labeled and excluded from function/address counts. Every native-authoritative case matches exactly, including full mutable-state hashes, RNG, ordered sounds, drawing requests, HUD text and timing where applicable. `analysis/native-reference-index.json` excludes repeated subset reports.

The three 100-frame chains use actual native prior state and RNG at verified startup `0x027f`, with independent JavaScript initialization/replay. The separately captured 180 prepared frames remain isolated comparisons. Runtime TLS, declared original CRT/CString allocator bookkeeping, and semantic HUD allocation pointers are explicitly normalized; exact raw runtime bytes remain in hashed compressed evidence artifacts. Live normal island initialization also exposed caller-history-dependent retained stack data. The selected concrete reference and differing observations are in `assets/data/pc53/initial-shoreline-stack.json`; actual consuming instructions verified its predecessor values. These inputs are neither universal zeros nor a cross-machine startup guarantee.

GDI commands and synthetic pixel returns are observational. Full Windows/MFC lifecycle, raster/text/audio identity, every indeterminate initial caller context, untested exceptional inputs and arbitrary whole-race trajectories remain separately scoped. See `analysis/native-reference.md`.
