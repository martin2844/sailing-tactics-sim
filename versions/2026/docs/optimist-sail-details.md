# Optimist sail details and pace analysis

2026-10-07. This fixes presentation geometry; authoritative sailing calculations,
race timing, speed presets and rules retain their existing behavior.

The subsequent [real-time playback change](real-time-playback.md) implements the
timing recommendation below. The measured original-level observations in this
document remain historical evidence; those modes are still selectable.

## Battens and seams

The private recovered drawing emits a curved sail outline plus separate pen
strokes. Its3D cloth is triangulated, but its strokes used the original curved
positions. On a normal Optimist the interior batten points were0.064–0.358model
units away from the actual rendered surface, versus a0.0078rod radius. They
therefore floated on one side and were hidden by the cloth from the other.

`SailDetailSurface` projects each stroke into the cloth's foot/head coordinate
plane, clips it to the polygon's triangles and reconstructs the corresponding
surface positions. Rod centres retain barycentric attachments to those rendered
triangles. Attachments are applied after interpolation and headwind deformation,
so cloth and detail cannot drift apart during luffing. The original line colour
and radius remain; normal depth testing still hides details behind other objects.
Topology signatures include each clipped segment's face and count.

This uses the actual native outline, rather than replacing its sail geometry.
Unfilled/wireframe cloth retains its native pen behavior. Hull, crew, boom and
rigging primitives remain separate from attached cloth details.

## Course lines crossing the deck

Start, finish and mark guides previously occupied world heights+.6,+.7,+.8,
above the water surface at−2.2. On the small Optimist those lines could physically
sit above the deck; depth testing correctly drew them over it. They now sit
0.06–0.10units above a shared water height. A framebuffer probe shows the boat
occludes the corrected line, while the controlled old+.8height paints over the
same deck sample. Course endpoints, bearing, width, dash pattern and rules are
unchanged. Legitimate boat rigging is retained.

## What speed6 means

The original15 speed levels are nonlinear presets, not wall-clock multipliers.
The recovered speed divisor changes numerical timestep. Levels1–4 also wait at
least80ms per step,5 waits60ms,6 waits30ms, and7–15 have no minimum wait. At the
faster levels, actual game-clock acceleration depends on processing throughput.
Boat/course setup changes the native timestep scale too.

For one five-Optimist Chrome run, three-second observations measured:

| Selected level | Game seconds / wall second | Numerical timestep at boot |
| --- | ---: | ---: |
| 1 | 0.091 | 0.00752s |
| 6 | 1.787 | 0.05715s |
| 10 | 59.223 | 0.28878s |

These are bounded observations on this machine, not preset guarantees. A
Keelboat's corresponding level6 timestep was0.03429s. The displayed race clock
is the integer native simulation clock, and advances with that timestep.

Sails currently combine native contour updates with extra presentation-only
headwind motion. The extra motion's sine phase uses interpolated **game time**;
speed6 therefore also accelerates it. Model packet updates and interpolation
cadence change with the numerical step rate. Smooth-looking motion at6 can thus
coexist with a faster clock. This is inherited pacing plus our existing visual
time choice, not a seconds/minutes display conversion error.

Recommended next timing change: introduce an explicit real-time pacing mode,
and a pause-aware wall-time phase for cosmetic flutter. Real time should advance
one game second per wall second; explicit fast-forward rates should be independent
of machine throughput. Keep recovered numerical timestep/maneuver behavior under
scenario regression while implementing that scheduler. This analysis does not
silently reinterpret the existing15 levels or change the user's selected pace.

## Evaluation

- [Sail detail evidence](../analysis/app/sail-details-accepted-2026-10-07/verification.json): six private original Optimist rig states,1,260 two-sided first-hit checks across interpolation/headwind phases, a detached-stroke negative control,24 camera views and unchanged authoritative image/RNG/clock. [Build/typecheck](../analysis/app/sail-details-final-2026-10-07/build.txt) also pass.
- [Surface regression](../analysis/app/sail-surface-details-final-2026-10-07/verification.json): all27 classes, extra Optimist/Keelboat rig states,432 Optimist orientation checks and black penalty sails. The old missing-panel negative control now uses its fixed recorded contour, instead of requiring the current cosmetic RNG draw to reproduce it.
- [Headwind isolation](../analysis/app/sail-wind-details-2026-10-07/verification.json): hull/crew and mast remain fixed; loaded rig does not acquire extra flutter; private geometry does not change the engine.
- [Line occlusion](../analysis/app/course-line-water-reviewed-2026-10-07/verification.json): actual WebGL framebuffer reads with a controlled old-height negative comparison.
- [Guide regression](../analysis/app/water-guide-details-2026-10-07/verification.json):30 clipping/width geometry cases and nine guide/HUD views.
- [Clock observations](../analysis/app/sail-clock-probe-2026-10-07/rates.json): actual5-Optimist wall/game-time observations at1/6/10.
- [Headless diagnostics](../analysis/app/sail-details-headless-2026-10-07/metrics.json):15 Optimists at6, median render CPU1.9ms and model build5.3ms. Private legacy model extraction remains expensive, median58.8ms; cadence was33.4ms in this headless run. This is not a headed60FPS certification. The headed attempt stopped at compositor window-focus validation and is not acceptance evidence.

Correctness evaluation passes independently of the qualified performance result.
No unit tests were added: actual native mesh intersections, framebuffer reads,
full sail coverage and independent geometry controls exercise the changed paths.
