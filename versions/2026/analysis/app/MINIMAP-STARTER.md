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

## Centered starter

The supplied mockup sets the visual direction: a centered pale panel, the actual
boat on water at left, race conditions at right, and a wide navy Start race action
in a separated footer. Existing IBM Plex Sans, navy `#082f50`/`#062f50`, muted
blue `#456682`, pale `#fbfaf6`, water `#177f9c`, and readiness green `#0d9c70`
keep it consistent with sailing. The boat, rather than ornamental UI, is the focal
point. The world behind the panel is the paused sailing scene with a light blur.

`BoatPreview` builds the player's mesh directly from the same native model packet
used by the race renderer. It preserves the recovered rig, hull, crew and native
colours; no substitute boat asset is introduced. Its first camera faces the cloth
plane rather than looking along its edge. Drag/zoom affects only that camera.
Rendering is dirty-driven during setup and stops while sailing; model buffers are
reset on new race/next race and disposed with the page. A preview-only context loss
leaves Start and the engine usable; Changing a selection creates a replacement preview.

All original control IDs, boat/course compatibility rules, custom names and
championship options remain connected to their original event handlers. The
countdown remains paused until Start. Starting restores focus to the sailing
canvas, and Space still works after a minimap button click. Small or short windows
use a scrolling setup panel with an accessible top, rather than clipped content.

Review found and fixed an edge-on preview camera, unsafe vertical centering on
short windows, the Start label's contrast after removing old CSS, and ownership of
a lost preview context. Conflicting obsolete starter styles were removed.

Chrome evaluation:

- `starter-recovery-2026-10-06/verification.json`: centered 1440×1000 panel, exact
  held native boundary after preview drag/loss, native Optimist/board/Snipe/cat/
  offshore selections, championship/name settings, 1280×720 / 768×1024 / 390×844
  layout, trusted Reload/Start/Pause/New race, and minimap-followed-by-Space.
  These smaller viewports are desktop Chrome emulation, not physical-phone tests.
- `starter-regression-2026-10-06/verification.json`: the existing initial hash,
  blocked helm during setup, native countdown, trusted setup selection, retired
  worker errors, N-to-starter and visibility ownership checks still pass.
- `minimap-lifecycle-2026-10-06/verification.json`: actual changing rendered
  pixels, held-state camera switching, three pause cycles, fleet restart, actual
  main-context loss/recovery and single annotation canvas ownership pass.
- `minimap-reference-performance-2026-10-06/verification.json`: three exclusive
  headed WebGL 2 Chrome runs, 15-boat reference with minimap on. Median 16.7ms,
  P95 16.8ms, worst P99 20.9ms; camera P95 at most 17.2ms, 43 draw calls and
  presentation packets at most 28072 bytes. All existing reference budgets pass.
- `minimap-starter-performance-2026-10-06/webgl2-0.json`: actual standard race
  started through the new menu with its preview present. Median/P95/P99
  16.7/16.8/16.8ms and camera P95 14.7ms pass; native original drawing packets
  total 37277 bytes and exceed the reference's 32768-byte transport budget.
  This additional configuration is not a full-budget pass. The chart/preview
  add no worker fields or model packets; the ceiling was not relaxed.

TypeScript/Vite build passes. Frozen-reference verification passes all 6471 files.
- `starter-championship-2026-10-06/verification.json`: actual original paints on
  the island, four AI finishes, player DNF at the game-clock deadline, retained
  championship score and successful second-race/model readiness after the new
  starter is reopened. This uses diagnostic batch pacing, not cadence timing.

The current menu stages all settings until Start and no longer has Reload fleet;
see [deferred setup and course-choice charts](STAGED-SETUP.md) for the final flow.
