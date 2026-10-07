# Dense-fleet performance

The30-Keelboat case exposed two expensive paths: the recovered center-distance
screen and the modern hull-avoidance predictor. Browser phase measurements
showed the predictor consumed most AI time; the original tactical routine was
only a fraction of the outer AI callback. No numerical steps, boats, collision
checks or penalties have been disabled.

## Changes

The owned avoidance screen uses signed DWORD differences and PC53-equivalent
squares. Pairs outside the original nine-unit radius skip floating carriers and
square roots. Close pairs keep original human-warning/NPC-response callbacks in
the same order. Large-coordinate signed-conversion cases, non-PC53 precision
and retained stack declarations use the original implementation. Frozen2002 and
2010 source files remain unchanged; the generated2026 compatibility copy exposes
an optional typed callback.

The hull predictor creates a query scope for immutable motions during one
steering decision. Bounds, initial world polygons and projections are reused.
Equal edge vectors share exact normalized axes, including signed-zero identity;
there is no angle quantization. Dynamic iterations reuse private scratch arrays
and return independent normals. Scalar projection loops avoid per-axis arrays
and interval objects. Repeated candidate headings reuse risk results. Nearby
blockers are considered first, and a zero-time pure minimum may stop further
queries.

Conservative translation-only enclosures and separating planes reject paths
that cannot approach. Bounds include the original skin and5mm unresolved-interval
margin, plus numerical/angular slack. Rotations, degenerate edges, extreme or
uncertain inputs retain iterative checks. Actual contact resolution continues
to use the uncached solver and existing penalty decisions.

A paused-only worker diagnostic reports native AI/steering/dynamics/integration
cost and optional nested AI phases. It restores all temporary callbacks after
success or failure and preserves the numerical trajectory.

## Evidence

- [Original numerical screen](../tools/independent/collision-performance.test.mjs):
  full-image/RNG equality across radius, integer wrap, clock/grace, human/NPC,
  unsupported precision and retained-stack cases; fixed-step trajectories on
  Optimist, Keelboat and Tornado fleets of5/15/30.
- [Geometry golden receipt](../analysis/app/contact-scalar-golden-2026-10-07/verification.json):
  2,350 exact separations,7,350 exact swept time/normal comparisons, and complete
  image/RNG/navigation-activity equality after every step of three fleet runs.
  Reference geometry/navigator source is pinned to commit c9bdd70.
- [Solver regression](../analysis/app/contact-solver-performance-regression-2026-10-07/verification.json):
  152 checks, including hull/mark crossing, rotations, sliding and no tunnelling.
- [Penalty regression](../analysis/app/contact-world-performance-regression-2026-10-07/verification.json):
  81 checks of native response, grace, mark/leg eligibility and impact-time rules.
- [Full race](../analysis/app/performance-race-keel-2026-10-07/verification.json):
  four natural AI finishes, contacts/penalties, human grounding and the20-minute
  game-time DNF window/results transition.
- [Global controls](../analysis/app/performance-hotkeys-2026-10-07/verification.json):
  all18 Chrome focus/pace/control groups pass.
- All49 focused numerical/cutover tests and the build/type check pass. Read-only
  big-review of numerical fallback/integration and geometry cache/bounds found
  no remaining findings.

## Fixed-step rate observations

The earlier30-Keelboat Chrome32× load observed about0.9× actual progress. The
optimized fresh load observed about5.7×, a substantial improvement with the same
fixed numerical timestep. A longer sequence maintained approximately1×,2× and4×
but remained computation-limited at higher targets. Rate varies with crowded
predictions and race state; the achieved rate remains visible in the HUD.

[Before](../analysis/app/playback-load-2026-10-07/verification.json),
[optimized load](../analysis/app/optimized-fleet-load-2026-10-07/verification.json),
[30-boat rate sequence](../analysis/app/fleet-performance-final-2026-10-07/verification.json).

These measurements are Chrome observations on this machine, not all hardware or
mobile certification. Fixed preset6 requires roughly933 Keelboat steps/sec at
32×. Using the original game's larger timesteps for high fast-forward speeds is
a separate numerical policy choice; it changes fixed-step trajectories even
though the original speed-dependent rules/formulas remain available.
