# Speed reset and maneuver regression fix

Space now resets native simulator speed to1 during sailing. Repeated presses
retain1; they never toggle host pause or thaw a frozen simulator. Setup start
and panel dismissal retain their contextual behavior. F and the Pause button
continue to control the host pause. The shortcut text and speed menu agree.

Tack/jibe cancellation came from retained screen controls, not turning physics.
The old boat painter populated the screen hit center. Without that painter,
both pending mouse coordinates and that center were zero. Player1 steering
mistook the empty values for two clicks, rotated slightly and immediately
cleared maneuver/autopilot state. The2026 runtime now explicitly disables the
legacy screen mouse/boat-hit paths. Recovered rudder, tack crossing, jibe
completion and heading arithmetic remain unchanged.

The keyboard adapter also accepts an explicit controlled boat. Modern keyboard
controls and instruments select boat1, including the two-boat fleet where the
original handler otherwise selected the second human. Preservation source is
unchanged; generated adapters retain original defaults without2026 options.

Validation:29 focused tests pass. New coverage includes24 complete maneuvers
(two tacks and two jibes, three boat classes, speeds1 and10),32 whole-image
steering comparisons against the preserved routine with a legitimate neutral
screen, repeated Space/freeze/panel behavior and two-boat input ownership.
Trusted Chrome inputs complete both tacks and both jibes on the default Keelboat
and publish resulting models without error. The15-check controls/depth suite
passes using F for pause and Space for speed reset after focused toolbar clicks.

Reports: `space-f-controls-2026-10-07/verification.json` and
`tack-jibe-controls-2026-10-07/verification.json`.
