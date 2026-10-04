# 2010 rendering smoothness and native verification

This record describes performance release `57ecb9f`. Its measurements and
source hashes are historical. The later [HUD repair verification](../hud-controls-verification.json)
records the tooltip argument and view-rendering storage corrections, current
interaction tests and rebuilt export; those fixes do not have a new FPS claim.

The player now defaults to smoother graphics. Browser sine, cosine and atan2
avoid extended-precision drawing objects, and the common perspective projection
uses ordinary arithmetic for screen coordinates. Small drawing-rounding
differences are intentional. Add `?graphics=exact` to use the exact rendering
path; the native comparison suites still use that path.

The final same-build comparison measured **37.58 FPS** with
smooth graphics and **32.43 FPS** with exact graphics, a
**15.9%** improvement. Mean paint time fell from
**29.75 to 25.59 ms**. Host CPU busy fractions were
17.4% and 19.0%; this remains below60FPS and is
not a universal speed guarantee. [Exact run](smooth-graphics-final-exact.json),
[smooth run](smooth-graphics-final-smooth.json).

The rendering-only option is supplied to the renderer separately from the
engine bindings. Shared waypoint and camera-bearing calculations retain exact
math because the next physics frame reads their results. The browser coupling
check compares every ordered engine memory access over 417 physics updates and
the end-of-frame RNG, time, speed and full-mode state over 420 paints. A separate
native-fixture comparison covers seven race setups, including offshore sailing
and two players. These are finite comparisons, not exhaustive proof of every
possible program state.

The preceding exact-result rendering checkpoint measured **27.23 FPS**, compared with
**23.51 FPS** for commit `a6b5a6d`, across 240 consecutive frames from the same
race state. Mean paint time fell from **41.04 to 35.24 ms**; the 95th percentile
fell from **56.2 to 44.9 ms**. The initial, measurement-entry and final complete
memory images and random states match. Both runs use the original speed-10
step and finish at the same frame and simulation time.

These are sequential headless Chrome samples, not a universal speed guarantee.
Host CPU busy time was 52.9% for the baseline and 50.0% for the candidate.
This remains below 60 FPS. The current 2002 fresh-default sample measured
53.19 FPS and 14.28 ms mean paint, but uses 15 boats, a 1000-unit course and a
pregun phase; the 2010 sample uses 20 boats, a 2000-unit course and a running
race. They are different workloads. Older single-run timings should not be
compared directly with these paired samples.

[verification.json](verification.json) records the release validation. The
[exact-rendering checkpoint](exact-rendering-checkpoint.json) preserves its
earlier source and export hashes, tests and review receipts. Raw checkpoint measurements
are in [the baseline report](smoothness-water-slab-old.json) and
[the candidate report](smoothness-water-slab-new.json).

## What changed

The water renderer has a generated 129-operation numeric calculation that
retains the original expression trees and floating-point stores. Each operation
must certify the same PC53 result before any output is committed. Unsupported
values, precision modes and custom memory implementations use the complete
original path. All **23,745 calls** observed during the native frame replay
qualified, and all 37 outputs matched. The isolated calculation, including its
guards and output copies, measured 3.95 times faster; that is a leaf measurement,
not a whole-game speedup. See [the reproducible diagnostic](water-number-slab-review.json).

Other changes remove repeated private water loads, promote proved private POINT
stores, remove redundant Boolean conversions, avoid unnecessary argument
boxing, and keep exact venue calculations unboxed. Shared extended arithmetic
caches immutable operand splits and avoids temporary result objects when a
binary64 result has already been certified.

The browser resets and reuses its private canvas, retains small pixel-read
tiles across drawing-state changes, and pauses hidden tabs. Returning to a tab
uses ordinary simulation steps without catching up missed frames. Old open
tabs must be reloaded to use this behavior. The 2002 scheduler is unchanged.

The 2010 scheduling gap measured about 1.6 ms between paints; drawing itself
was the main cost. RequestAnimationFrame samples record completed logical
canvas frames and rendering opportunities. They do not establish physical
monitor presentation.

## Preserved behavior and review

The supplied executable and original full-mode value **0** are unchanged. The
source and standalone browser checks verify full-version behavior separately
from rendering performance. The default-fleet AI correction from the previous
release remains covered by [279 native comparisons](../upwind-stack-native-comparison.json).

All **251 original byte-frame drawing bodies** remain unchanged. The integrated
water path passes **190 native frame executions**, including exact mutable
state, random state, text, sound requests and ordered GDI operations. Generation
is reproducible. [The generation receipt](water-number-slab-validation.json)
and [the independent review](water-number-independent-review.json) cover the
optimized window and its fallback, including partial outputs and failures.
Canvas and Windows GDI rasterization can still differ; the documented native
comparisons cover finite recorded inputs rather than every possible program
state or historical machine speed.

Review fixes include rejecting shared or modified memory views, preserving the
original constructor getter order, pinning the complete water body against
future frame escapes, preventing malformed copied parameter metadata from
aliasing mask bits, and capturing a generator test's actual pipeline input.
The detailed source pins and validation results are linked from the final
verification receipt.

## Reproduce the controlled race measurement

With the source player served on port 8765:

```sh
TACT_PACE_DEFAULT=1 TACT_PACE_STARTED=1 TACT_PACE_FRAMES=240 \
TACT_PACE_PRESENTATION=1 TACT_PACE_NO_AUTO_SLOW=1 \
node tools/diagnostics/measure-2010-pace.mjs local-racing
```

The diagnostic uses actual original menu commands and paint callbacks. It
advances to clock 100 using speed 15, then selects speed 10. For this comparison
it turns off the original **Slow Simulator if Foul Likely** option through menu
32984; normal player defaults remain unchanged. That option can otherwise lower
the selected speed near another boat. Backslash toggles it in the player.

Serve a preserved baseline separately and set `TACT_2010_URL` for its run.
For exact-math comparisons, pass its report path through
`TACT_PACE_SETUP_REFERENCE` to require identical setup, control history and
final game memory. Smooth drawing intentionally changes rendering scratch
memory, so use `check-smooth-graphics-browser.mjs` to compare engine accesses
and per-frame simulation state across graphics modes. Reports
include the actual loaded module hashes, per-frame durations and host load.
Run one timing browser at a time, without concurrent test suites or profilers.
