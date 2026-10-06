# Pause and information tools (2026-10-06)

The 2026 simulation is the recovered 2010 engine expressed in JavaScript. Three.js
renders faithful boat geometry extracted on private memory copies. No C executable
or emulator runs in the browser. Some information panels still used the original
GDI UI; that presentation gap does not imply a second simulation.

## Stable pause

Space, F and the Pause button now share the host pause policy. Native F previously
froze the game clock while permitting parts of the original painting/dynamics
path to execute. Steering/sail inputs could modify retained control state while
host-paused, becoming visible on the next paint.

User sailing inputs now use guarded worker messages. While paused or native-frozen,
helm and sail actions are ignored before touching original memory, with no queued
actions on resume. The helm/pace buttons disable, telemetry and geometry retain
their last values, and the clock shows Paused. Camera controls and information
inspection remain available. Raw native key/command messages remain explicit
diagnostic interfaces for original-handler parity fixtures.

`tools/controls-depth-eval.mjs` passes 14 checks in
`pause-input-controls-reviewed-2026-10-06/verification.json`: trusted toolbar
focus/Space, F/button equivalence, paused helm/sail input through both DOM and
worker, identical complete native image/RNG/shore boundary and retained telemetry,
panel dismissal and depth warnings. Production build passes.
