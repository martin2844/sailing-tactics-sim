# BASE-05 — native timing and pace

Accepted 2026-10-05. Use the original unit-tick browser host, full paint steps,
native variable timestep and native pace controls. Modern camera/render RAF
must never advance this clock or consume engine randomness.

The real 15-boat Chrome runs each sample 36 continuous full paints, using
original levels 1, 5 and 10. The host returns successive U32 ticks; all samples
verify last–first equals reads–1 and that the requested delay covers the native
minimum. All loaded modules match the frozen reference. These short runs
establish semantics; they are not the final repeated graphics benchmark.

| Native level | Divisor | Round Lake timestep | Minimum host delay | Observed simulation seconds / wall second |
| --- | ---: | ---: | ---: | ---: |
| 1 | 2919 | 0.004511183068552661 | 80 ms | 0.0562 |
| 5 | 577 | 0.022821738955121695 | 60 ms | 0.3795 |
| 10 | 76 | 0.17326504443559496 | 0 ms | 4.2890 |

Ratios are observations of this host/run, not constant multipliers or performance
acceptance. `integration.js` derives dt from original time factor × venue/course
scale ÷ divisor with original Float80 arithmetic/spills. Short-course, venue
and weather configuration may change dt; there is no universal fixed physics dt.
`minimumFrameDuration` uses 80 ms below level 5, 60 at 5, 30 at 6, zero at 7+.
`createPaintClock` also includes drawing tick reads and returns reads–1 as its
minimum. `play.js` subtracts actual paint CPU duration before scheduling.

Automatic slowdown is a drawing/control effect: native boat/HUD dependency
detects a qualifying foul warning, saves pace/divisor and selects level 1 and
divisor 2919. A real 15-boat speed-15 run with automatic slowdown enabled changes
to level 1 after 11 paints, clock −155, without any injected foul flag. Original
toggle/Space handlers verify automatic states 0 (off), 1 (armed), 2 (resume
grace), then off again. The drawing routine rearms 2 after four original clock
seconds. This behavior must remain in the compatibility driver.

Decision: change the provisional 2026 default from native level 5 to **10**.
Level 5 takes roughly 7.5 minutes of wall time for the original 170-second
prestart in this context; level 10 preserves the familiar original controls
with a practical prestart. Label levels **Precision**, **Study**, **Sailing**
and show native level in settings/diagnostics. Do not advertise 1×/5×/10×.
Automatic foul slowdown defaults off in the modern presets and remains an
explicit original option. This does not change the original numerical formulas.

`config/timing.json` freezes the driver contract: complete original step,
canonical dimensions, one tick per native read, logical clock start 0, real
native minimum delay with CPU time subtracted, event-loop yield, no dropped
steps or wall-time catch-up. Pause/hidden/restart must cancel pending work; RAF
can inspect a frozen snapshot without invoking legacy drawing. Lifecycle
certification remains APP/ENG work; this document defines the required behavior.

Evidence: `BASE-05-run-1/report.json` and `natural-slowdown.json`. Reproduce with
`node versions/2026/tools/timing-audit.mjs NEW_DIRECTORY`; the natural trigger
probe uses only menus 32973/32984 and 11 real scheduled paints. No new unit tests
were needed: real host reads/delays, original controls and natural slowdown were
measured directly. Graphics cadence and worker equality remain separate gates.
