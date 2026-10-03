# Translation runtime

`src/runtime/index.js` is a browser-compatible ES module. It imports no Node APIs.
It provides memory and integer/storage semantics for translating decompiled C
functions; it is not an x86 instruction interpreter or a Windows compatibility
layer.

## Loading the original image

```js
import { loadPE32 } from './src/runtime/index.js';
const bytes = new Uint8Array(await (await fetch('./original/Tact02Demo.exe')).arrayBuffer());
const memory = loadPE32(bytes);
const value = memory.readF32(0x00491000);
```

`parsePE32(bytes)` returns the preferred image base, entry point, image/header
sizes, alignments, and section records. `loadPE32(bytes)` returns an
`AddressSpaceMemory` with these records in `memory.pe`. It maps the headers and
each section's raw bytes, including file padding, at their original addresses.
Zero-filled virtual section tails and image gaps start as zero. In this
executable, `.data` has 0x12400 raw bytes and 0x1fa48 virtual bytes; the
uninitialized tail at 0x004a3400–0x004b0a47 contains 0xd648 bytes. A default
256 MiB image-size limit can be changed via `loadPE32(bytes, {maxImageSize})`.

The image is loaded at its preferred base 0x00400000. Imports retain their file
values; resolving imports and implementing Windows calls require separate work.
There are no relocations in the supplied executable. The loader does not start
the executable or modify its edition setting.

`AddressSpaceMemory(size, base = 0x400000)` creates zero-filled storage.
`readU8/I8/U16/I16/U32/I32/F32/F64(address)` and corresponding `write*` methods
use little-endian access, including unaligned addresses. Out-of-range addresses
throw instead of wrapping into unrelated storage. `readBytes` returns a copy,
`writeBytes` accepts `Uint8Array`/`ArrayBuffer`, and `moveBytes` supports overlap.
The underlying `bytes` is an editable `Uint8Array`; addresses in translated
functions must go through the methods or subtract `memory.base` explicitly.

## Integer behavior

`i8/u8/i16/u16/i32/u32` implement two's-complement narrowing. They require a
safe integer `Number` or an exact `BigInt`. Floating-point casts need their
instruction-specific conversion and are deliberately separate.
`truncFloatToI32` handles finite, representable truncation toward zero; invalid
conversions throw pending an explicit x87 conversion implementation.

`idiv32/irem32` use signed operands, truncation toward zero and dividend-signed
remainders. Zero division and the signed minimum divided by minus one throw,
matching the invalid inputs to x86 IDIV. `udiv32/urem32` use unsigned operands.
`imul32/umul32` retain the low 32 product bits with `Math.imul`; `add32/sub32`
return wrapped signed 32-bit results. A decompiled expression such as `a * b`
cannot automatically become JavaScript `a * b`: a large product loses low bits
before a later cast. Likewise, each translated expression needs its original
signedness and promotion rules rather than indiscriminate narrowing.

## Floating-point limits

`f32` (`Math.fround`) and `writeF32` model a binary32 storage boundary with
round-to-nearest, ties-to-even. `writeF64/readF64` model binary64 storage.
JavaScript `Number`, including the exported `f64`, is binary64. **It is not
equivalent to x87 80-bit extended precision.** The original executes x87
instructions; register precision, control-word precision and rounding mode,
spill boundaries, exceptions, and transcendental instructions must be examined
per function. Replacing those intermediates with `Number` can change trajectories
and branches even when every final store has the correct width.

`src/runtime/float80.js` now provides immutable finite extended values, with
64-bit significands and round-to-nearest, ties-to-even for addition, subtraction,
multiplication, division, and square root. It supports signed zero, extended
subnormals, exact binary64 input, rounded binary64 stores, comparisons, and the
original CRT's signed64 truncation followed by signed32 narrowing. BigInt holds
intermediates; no host floating-point operation substitutes for extended
arithmetic. Intermediate registers remain extended until an explicit store.

Hardware x87 probes verify 989 arithmetic cases, 110 conversions, and 38 boat
factor division/square-root sequences. The probe uses control word `0x037f` and
records CPU/compiler/source provenance. A confirmed Unicorn pseudo-denormal
subtraction error remains preserved beside the authoritative hardware result.
`tools/capture_x87_fixtures.py` invokes hardware verification by default.

Captured actual FSIN/FCOS m80 results replace emulator trigonometry where used.
Their documented finite input domains are checked before execution. Alternate
rounding modes, floating exception flags/traps, nonfinite values, and every
historical CPU's transcendental behavior remain unsupported or unverified.
Reading a NaN into a `Number` and writing it back also does not promise its
original payload. Byte copies preserve bits. Whole-race parity still requires
reconstruction and comparison of every active simulation component.

## Checks

`node --test tests/runtime.test.js` verifies the actual executable's section
layout, every mapped raw section byte, the full BSS tail, stored pointers,
offset-backed input views, little-endian aliasing, integer boundaries and IDIV
errors, binary32 ties, binary64 bits, and signed zero. These establish runtime
semantics; they do not establish parity for unported simulator functions.

## Recovered integer functions

`src/engine/integer-core.js` translates the following instruction sequences;
`ORIGINAL_ADDRESSES` records their addresses and associated global/TLS fields.

| Original address | JavaScript API | Preserved details |
| --- | --- | --- |
| 0x00413cb0 | `wrapDegreesOnce(input)` | Signed int32 comparisons, at most one subtraction/addition of 360; values far outside a revolution remain outside. |
| 0x0044e380 | `speedDivisor(level, previous)` / `updateSpeedDivisor(memory)` | Exact immediate lookup for levels 1–15; invalid levels leave the prior global unchanged. The memory form uses DAT_0049116c and DAT_00491170. |
| 0x00456ed0 | `PoseyRng.srand(seed)` | Low 32 seed bits stored in the abstract thread state. |
| 0x00456ee0 | `PoseyRng.rand()` | LCG `214013 * seed + 2531011` modulo 2^32; returns bits 16–30. |
| 0x00415a20 | `scaledRandom(input, rng)` | One RNG call, signed division, minimum divisor one; original negative-input behavior retained. |

Each `PoseyRng` instance models one original TLS seed at threadData + 0x14.
Its default seed one is evidenced by the original initializer's store at
0x00459ebb. Save/restore uses its unsigned `.state` property.

The scaled random helper has a significant instruction-level detail: it computes
absolute value into EAX only for the comparison with two; ECX retains the
original signed input unless that comparison requests a clamp. Thus `-100`
gets a negative quotient for `32000 / ECX`, which clamps to one and returns the
whole `rand()` result. It must not be rewritten to divide by the absolute range.
INT_MIN wraps when negated, fails the signed comparison, and selects range two.
This follows the original instructions at 0x00415a20–0x00415a53.

`tests/fixtures/original-core.json` records reference outputs captured by executing
the original x86 instructions in Unicorn 2.1.4. The parity tests check its
executable SHA-256 against the checked-in original and compare 1,041 angle
inputs, 60 speed/prior-state cases, 1,536 successive RNG outputs and seed states,
and 60 scaled random inputs and seed states. The original TLS accessor is
stubbed to supply the isolated thread-data block; these tests do not exercise
Windows TLS allocation or thread lifecycle. These are finite samples against CPU
emulation, not an exhaustive proof against the original CPU or a full-game
comparison. They contain no floating-point simulation comparisons.

Additional translated components now include apparent wind, boat initialization,
global wind, six current/metric routines, player steering, and the first movement
helpers. The original routines have also been executed under Wine on the real
CPU, with preserved code bytes and recorded runtime stubs. See
[`native-reference.md`](native-reference.md) for exact counts, synthetic geometry,
sound recorder limitations, and the complete scoped evidence. Full boat dynamics,
tactics, race progression, procedural graphics, and the Windows/game lifecycle
require further reconstruction and end-to-end comparisons.
