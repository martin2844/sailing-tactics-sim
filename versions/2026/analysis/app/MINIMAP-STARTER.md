# Minimap and centered race setup

## Minimap

A north-up Canvas 2D chart in the bottom right uses the same course coordinates,
original shoreline polygons, and interpolated fleet positions as the 3D scene.
It includes the marks, committee boat, start/finish lines, and native guides when
Mark lines is enabled. Red identifies the player; finished competitors are muted.
This is a tactical chart, rather than a second 3D render or an engine camera input.

The Minimap toolbar button and close button control a persisted preference. Full
Overview temporarily hides the chart without losing that preference; follow,
orbit and native sailing cameras restore it. Setup, results and native panels
also hide it. Boat labels reserve its screen rectangle. A bounded 10 Hz redraw
keeps the chart inexpensive without changing physics, native state or RNG.

Evaluation: `tools/minimap-eval.mjs`, evidence in
`minimap-2026-10-06/verification.json` and `minimap.png`: trusted toggle/camera
clicks, player/mark pixel checks, persisted reload preference, and identical
entire paused native boundaries before and after chart/camera interactions.
