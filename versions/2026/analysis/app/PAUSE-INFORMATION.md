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

## Modern information access

The Information buttons at the top of the sailing sidebar and the original
shortcuts now open the same modern Sailing desk:

- W: weather forecast, including the committee boat's recorded wind history.
- [: spatial wind chart, including original mixing/convergence/divergence/puff/
  channelled wind categories.
- ]: spatial current/tide chart; + and − inspect the original future tide hours.
- Y: original state-dependent coach comments, in readable text.
- X/Z in either chart: original zoom/whole-course selection.

Opening from sailing holds the race and restores play when closed. Opening from
pause keeps it paused afterward. Space/Esc and Return to sailing close the desk.
Background helm/pace/pause controls disable while the desk is open. Restart/setup
cancels pending reads; stale responses cannot reopen a closed desk. Tab focus stays
inside the panel.

`captureInformation` copies the complete native memory image, dynamic CString
contents, RNG and retained shore stack. It invokes the existing forecast, coach
or chart routine directly with isolated callbacks, rather than advancing the
simulation. Text and plot primitives cross the worker boundary only on request;
they are not added to every physics snapshot. This uses the original advice and
weather/current formulas, not new canned messages or synthetic chart data.

Forecast/history columns are separated by their native layout roles rather than
interleaved by y coordinate. Wind/current maps retain native vector positions and
category decisions with a restrained SVG palette and readable labels. Native
screen toolbars and the stale fixed-pointer readout are omitted; chart-point hover
sampling is not exposed by this desk yet. Native keyboard/help/other tutorial pages
remain in the compatibility panel.

`tools/information-eval.mjs` passes nine grouped Chrome evaluations in
`information-release-2026-10-06/verification.json`: trusted sidebar buttons and
W/[ /]/Y shortcuts, original forecast/history and coach output, wind/current
plots, zoom restoration, tide +/−, nonzero telemetry preservation, full native
memory/RNG/shore/clock retention, and restoring the prior pause policy. Additional
private native cases cover west-wind Island and Newport tide profiles. Screenshots
were visually inspected and refined after the functional evaluation. Frozen
reference verification still passes all 6,471 files; TypeScript/build passes.
