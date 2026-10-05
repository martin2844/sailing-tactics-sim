# BASE-04 — drawing and host effects

Accepted 2026-10-05. The simulation bridge must retain the complete original
paint on a canonical 1024×768 Canvas 2D surface, including pixel sampling,
original camera/layout, RNG, retained contexts and cleanup. Modern rendering
can observe snapshots; it cannot replace these operations yet.

## Evidence and phase ownership

`tools/drawing-audit.mjs` inventories source-line read/write, RNG, retained-local
and GetPixel candidates in every edition engine/render module. This is a
conservative inventory, not complete alias analysis. The accepted run pairs
plain and instrumented original execution with identical declared host inputs:
fixed seed, cursor (0,0), original neutral mouse handler and original key/menu
handlers. Incidental desktop pointer/key events are blocked in this diagnostic;
this is not a trusted-input latency test. No game memory is directly assigned.

Five raw whole-image/RNG comparisons pass: race, forecast, forecast dismissal,
wind chart and chart dismissal. The observer forwards original functions and
records **net** image changes, actual RNG calls, actual GetPixel calls and
shoreline retention. Intermediate writes that are restored remain conservatively
required by the static inventory. No purity is inferred from a zero net delta.

| Phase | Observed calls | Net changed words across calls | RNG calls | Pixel reads |
| --- | ---: | ---: | ---: | ---: |
| Wind | 14 | 2 | 0 | 0 |
| Boat wind/AI | 70 | 53 | 0 | 0 |
| Player steering | 14 | 0 | 0 | 0 |
| Boat dynamics | 70 | 46 | 32 | 0 |
| Integration/history | 14 | 1887 | 0 | 0 |
| Save race state | 1 | 11 | 0 | 0 |
| Scene drawing | 14 | 857 | 32194 | 784 |
| Chart drawing | 15 | 41 | 56 | 0 |
| Sailing HUD | 14 | 0 | 0 | 0 |
| Forecast | 1 | 1 | 0 | 0 |

The accepted `BASE-04-run-5` archive contains the phase trace, full source
inventory, per-word literal reader candidates and ten compressed raw images.
Computed-address readers remain required when literal matching finds nothing.
All 83 loaded modules match the frozen reference. Compressed JSON archives
retain the original report contents; decompress them for inspection.

## Required ordering and dependencies

1. Menu/key/mouse handlers run between native paints. Mouse writes hover fields
   `0x5364a0/4`; keyboard writes last-key `0x4faf94`. HUD drawing reads these and
   can change pace/control state. Preserve accepted input order and host cursor.
2. `paintLifecycle` writes display caps, application handle, dimensions and F64
   scales before screen dispatch. Width/height/calibration fields are read by
   steering, projection, layouts and drawing; they are simulation host inputs.
3. `drawPaintContent` advances phase `0x5364e8`, performs initialization/screen
   transitions, and dispatches forecast/chart/pause/results. Results and screen
   flags influence whether the numerical prefix runs.
4. `advanceFrame` performs restore gates, tick/cursor reads, wind/patch updates,
   each boat's AI, human steering, dynamics, integration and history in that
   order. Drawing follows this prefix, not an independent display RAF.
5. Scene children `0x41e0a0/0x41e220` write original camera heading/offset state;
   `0x465ff0` respawns waypoint coordinates consumed by later simulation. Their
   math is explicitly kept exact in `render/dependencies.js`. Preserve all
   their stores and original call order; current fast graphics is not a license
   to omit them.
6. Scene and chart consume the same RNG as physics. Extra legacy paints change
   future wind/AI. A modern camera/render action must consume no native RNG.
7. GetPixel branches in `drawing-functions.js` consume the actual rasterized
   surface to select visibility/detail operations. Source inventory lists all
   sites. Keep real Canvas pixels; a no-op DC or constant pixel oracle is invalid.
8. `shore-stack.js` retains two native caller slots (offsets 280 and 1004),
   including aliased POINT writes, and a completed-call counter outside image
   memory. Typed locals carry byte validity; undefined slots must not be filled
   with invented zeroes. AI/local/packed/scalar paths remain required as written.
9. The original tick wait and `finishFrame` clear `0x4f7124/28` only after
   composition. Buffered surface reset, bitmap selection, blit, deletion,
   invalidation and destructor order remain in `paintLifecycle`. The bridge
   must preserve these operations and their host tick contract.

## Findings and unresolved requirements

Runs 1–4 are retained as unsuccessful diagnostics, not correctness passes.
Run 1 also used a mistaken forecast command, corrected from the menu resource
to 32907. Later raw images identified uncontrolled pointer/keyboard input:
run 3 differs at hover fields; run 4 differs at last-key 0x4faf94. With a fully
declared diagnostic input host, run 5 has zero differing bytes at every boundary.
This explains the newly captured failures, but does **not** identify the missing
raw addresses of the earlier B03-01 hash-only captures. B03-01 remains recorded.

All unclassified computed aliases, temporary/restored writes, unvisited weather,
AI and display branches, retained local state and pixel dependencies remain
simulation requirements. No memory range is excluded from comparison or replay
ownership here. `saveRaceState` is an original race-history operation, not proof
of a complete checkpoint. ENG-01/02/03 and replay tasks must validate any later
extraction. A worker with a real OffscreenCanvas is the first bounded prototype;
its equality and cost must be measured before claiming simulation independence.

Reproduce with `node versions/2026/tools/drawing-audit.mjs NEW_DIRECTORY`.
Acceptance: same-input observer equality, classified phase order/effects and
conservative retention of unknown readers. No extra unit tests were needed;
the real browser comparisons validate the observer. Timing is BASE-05; the
modern renderer's cadence is a separate test.
