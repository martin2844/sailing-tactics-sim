# Zero-width shoreline crash (2026-10-06)

The reported `originalDrawing00440b70Number` crash comes from the compatibility
shoreline painter, not the modern boat mesh. Two shore endpoints can have the
same projected integer x coordinate. Its decorative shoreline texture interpolates
the top edge by dividing by that zero horizontal span.

The preserved executable masks x87 exceptions. The JavaScript Float80 runtime
deliberately rejects unsupported division-by-zero semantics, so the recovered
expression stops the worker rather than completing the original paint.

## Original instruction evidence

Inspected `versions/2010-en/runtime/Tactics2010EnglishPreserved.exe` with objdump:

- `0x440fa1`: subtract endpoint x coordinates.
- `0x440fd0`: divide the height difference by the stored horizontal span.
- `0x440fef`: store that slope as a double.
- `0x4410f6`: multiply the sampled x offset by the stored slope.
- `0x4410fa`: call `__ftol` at `0x49b970`.
- `0x49b989`: truncate with `FISTP QWORD`; `0x49b98f` returns its low DWORD in EAX.
- `0x44110a`: add EAX to the first endpoint's top-edge y coordinate.

For a zero span, the sampled x offset is also zero. Both `0 / 0` and a nonzero
height difference divided by zero become an invalid value after multiplication
by zero. Masked conversion produces `0x8000000000000000`, whose low DWORD is zero.
`tools/shore-x87-probe.c` executes this FDIV/stored-double/FMUL/FISTP sequence on
native x87 hardware under the original `0x027f` control word and `__ftol`'s
temporary truncation word. All three zero-span cases return that same value;
its finite control returns 20.

## Repair

The generated 2026 drawing adapter recovers this single integer conversion as
zero when the projected span is zero. It then performs the original y addition
and continues the original texture loop, polygon fills and shoreline strokes.
It does not skip the paint, suppress worker errors, modify boat movement or
change the general Float80 runtime.

All four generated variants are guarded: Number and Float80, each with scalar
and retained-byte-frame locals. The preparation script validates the frozen
source, requires exactly four replacements and declares the repair at
`0x440fd0` in its generated manifest. Frozen preservation files remain intact.

## Evaluation

- `npm run build`: passes TypeScript and production build.
- `node tools/shore-render-eval.mjs analysis/app/shore-render-2026-10-06`:
  27 cases reproduce the exact RangeError on frozen code and complete on the
  adapted routine; exercises Number, exact Float80 and retained-byte-frame
  public entry paths, with positive, negative and zero height differences.
  Another 162 adjacent nonzero-span cases retain identical GDI commands, complete
  memory images and RNG state. General Float80 division-by-zero still throws.
- Native hardware conversion results are retained in that evaluation's
  `verification.json`; the compiled probe is a local artifact, not a runtime asset.
- `tools/island-course-wind-eval.mjs`:
  `shore-wind-regression-2026-10-06/verification.json` contains 20 passing Chrome
  checks: seven Island layouts, eight prevailing compass winds, actual Start,
  unchanged held setup state and identical five/fifteen-boat Auto startup hashes.
- `tools/island-live-eval.mjs`, with `TACT_ISLAND_COURSE=1` and
  `TACT_ISLAND_WIND_DIRECTION=270`:
  `shore-island-west-live-2026-10-06/verification.json` records actual native AI
  sailing through the full course. All four NPCs arrive, the unsteered player
  receives DNF at the finishing deadline, and the result screen completes.
- `shore-camera-regression-2026-10-06/verification.json` records 28 Chrome
  view checks: all 14 original camera keys followed by two original paints,
  on default Round Lake and west-wind Island in paused private workers.
- `node tools/reference.mjs verify`: all 6,471 frozen reference files pass.

Controlled shore fixtures and these representative live runs are not a claim of
naturally sailing every venue and camera configuration. This change adds only
a zero-span comparison in the affected drawing loop; it does not change the
modern renderer's geometry or scheduling. No new performance benchmark was needed.
