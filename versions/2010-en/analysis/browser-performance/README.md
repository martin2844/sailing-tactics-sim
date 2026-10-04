# 2010 crash and performance update

The reported default-fleet crash is fixed. The translated AI used to read an
undefined private stack cell before checking whether the fleet had two boats.
For every other fleet that value cannot affect the native result. The generator
now checks the fleet first and retains the original comparison for two boats.
[The native comparison](../upwind-stack-native-comparison.json) covers 279 calls:
the previous implementation failed 168 of them; the corrected implementation
matches every mutable byte and the random state in all 279.

The default 20-boat speed-10 startup sample improved from **5.00 to 22.01 FPS**,
with mean paint time reduced from **195.87 to 44.47 ms** (about **4.4× faster**).
After advancing through the original menus to simulation clock 100, the final
build measured **28.50 FPS**; a later sample past clock 320 measured **29.60 FPS**.
The rebuilt standalone download measured **28.96 FPS** after clock 100.
Each sample contains 120 actual continuous frames in headless Chrome, with the
original boat, venue, fleet, drawing and physics. Host load, compilation and
scene phase affect these results; they are not a universal frame-rate promise.

The supplied 2010 data retains its original **full-mode value 0**. The actual
later run reached clock 354 without an error or demo interruption. No demo flag,
executable bytes, simulation time step, AI frequency, fleet size or scene detail
was patched to obtain these results.

[verification.json](verification.json) pins the final source modules, test and
browser receipts, timing samples, and both rebuilt browser ZIPs. Individual
review reports retain the hashes of the snapshot they examined. Earlier
profiles and the previous publication reports remain historical evidence.

## What changed

The 2010 translation incurred much more floating-point and local-stack overhead
than the 2002 port. Typed drawing calls now keep exact binary64 values where
PC53 arithmetic allows it. Bounded double-double calculations and square-root
rounding certificates avoid expensive extended arithmetic for common inputs.
Perspective and chart windows can certify their final integer coordinates;
uncertain cases still execute the complete original path.

The generator promotes only proved private scalar cells and four bounded
18-cell water arrays. Aliased point buffers remain bytes. All **251 original
byte-frame bodies** remain unchanged. The shoreline pass preserves its
observable point/array overlap and verifies the complete lifetime of its index
counters before promoting private cells.

The browser batches tiny adjacent pixel reads on the private frame surface,
invalidating the cache on every intervening drawing event. Frames requested
immediately use message tasks, avoiding the browser's nested-timer delay.
Positive simulation delays, controls, modal pauses and freezing retain their
original behavior.

## Verification and review

The shared/2002 suite passed **397 tests**. The complete 2010 suite passed
**423 tests**, followed by **four additional shoreline tests** added during the
review. Source and standalone 2010 players each passed **119 browser checks**
and **seven full-version checks**. Both the source and rebuilt 2002 player
passed their **ten browser checks**.

The native regression includes **150 additional distinct complete frames**
(**190 executions** including original-backend comparisons), bringing the
preserved complete-frame collection to **588**. It checks mutable state,
random state, text, sounds and ordered GDI requests. The shared arithmetic
verification also includes **82,095 differential operations** and **9,059 native
PC53 cases**. These comparisons do not claim identical Canvas/Windows GDI
rasterization or universal behavior outside the documented finite domains.

No unresolved review findings remain. The final review found and fixed a chart
reference coordinate being narrowed before a later I64 division, a generator
guard accepting extra preheader counter writes, and machine-local Python paths
in new regression tests. The chart fallback, counter-store ledger and portable
interpreter selection now have focused verification.

See the [projection bounds](projection-output-bounds.md),
[projection/CFG review](projection-output-source-review.json),
[shoreline review](shore-scalar-source-review.md),
[pixel-cache review](gdi-pixel-cache-source-review.json), and
[scheduler review](paint-scheduler-source-review.json).

## Reproduce timings

With the source server running on port 8765:

```sh
TACT_PACE_DEFAULT=1 node tools/diagnostics/measure-2010-pace.mjs local-startup
TACT_PACE_DEFAULT=1 TACT_PACE_STARTED=1 node tools/diagnostics/measure-2010-pace.mjs local-racing
TACT_PACE_DEFAULT=1 TACT_PACE_STARTED=1 TACT_PACE_CLOCK=320 node tools/diagnostics/measure-2010-pace.mjs local-later-race
```

`TACT_PACE_STARTED` uses the original speed-15 menu to advance actual game
frames, then selects speed 10 for measurement. It does not inject the clock.
Each report records the loaded module hashes, setup, host CPU load, frame
durations, game clock and browser exceptions. Run one timing browser at a time.
The 2002 comparison measured **71.01 FPS**, so it remains faster. It uses its
own original 600-unit course and time-step
constants; the default 2010 course is 2000 units, so their speeds are not an
identical-scenario benchmark.
