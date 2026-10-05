# GFX-01 renderer evaluation

Accepted bounded renderer spike, 2026-10-05. Three.js **0.186.1**,
**WebGLRenderer / WebGL 2** is the MVP backend. The isolated `/` app now renders
faithful native-derived 3D boats with free orbit/zoom, 5/15 fleets, modern faceted
water and the original simulation in a separate worker. The original generic
boat was rejected by the user and is not the accepted visual foundation.

The chosen architecture retains original hull proportions, curved sail contours,
articulated boom, crew and meaningful colors. Deliberate private fixtures verify
the white-to-black penalty main, boom movement with trim/opposite tack, luff
flutter and spinnaker geometry. Actual 3D screenshots were inspected, including
the crew side. See [model derivation and limits](../../docs/native-boat-models.md).
This completes the user's requested isolated-app/renderer task, not the whole MVP
or polished production boat asset.

## Desktop backend measurements

[Five repetitions per requested backend](GFX-01-faithful-run2/verification.json)
use fresh headed Chrome profiles, a visible owned window, hardware GPU enabled,
1280×1050 logical viewport at DPR 1 and a 1280×640 rendered canvas. Browser:
Chrome 152.0.7977.82; ANGLE AMD Radeon RX 7800 XT / OpenGL ES 3.2. Standard
quality and 15 Keelboats/Round Lake use frozen native pace and assistance settings.
Each run warms at least 60 native paints, resets metrics, then collects at least
360 completed rendered samples, with trusted response checks outside that window.
No profiling/readbacks run during cadence measurement. Raw metrics, response
records, native paused boundaries and screenshots accompany every repetition.

| Metric | WebGL 2, five runs | Requested WebGPU, five runs |
| --- | --- | --- |
| Actual backend | WebGL 2 | WebGL 2, explicit WebGPU fallback |
| Completed changed frames | 1,781 total | 1,806 total |
| Median changed cadence, every run | 16.7 ms | 16.7 ms |
| Worst run p95 changed cadence | 16.8 ms | 16.8 ms |
| Worst run p99 changed cadence | 50.0 ms | 16.8 ms |
| Largest individual gap | 66.6 ms | 33.4 ms |
| Worst run p95 trusted camera response | 18.5 ms | 17.2 ms |
| Worst run p95 CPU render submission | 3.8 ms | 1.8 ms |
| Worst run p95 measured GPU time | 0.286 ms | Unavailable |
| Maximum draw calls / triangles | 18 / 34,415 | 19 / 34,416 |
| Maximum combined pose + model bytes | 22,919 | 22,920 |
| Unthrottled initial model-ready range | 1.76–2.92 s | 1.64–1.85 s |

Every repetition passes the declared median≤18/p95≤25/p99≤50 ms cadence,
camera p95<100 ms, presentation≤32 KiB and working draw-call/triangle budgets.
The worst p99 equals the permitted boundary and isolated gaps remain; these short
runs do not certify a perfectly uniform or long-session experience.

The WebGPU route uses Three.js WebGPURenderer and reports its actual backend.
Native WebGPU was unavailable in this configuration. These are fallback results,
not evidence that WebGPU is faster. GPU timing on that route is unavailable;
CPU submission is never substituted for it. Keep WebGL 2 as the tested default
and revisit actual WebGPU later under POST-03.

The engine and graphics workers coexist without a shared authoritative RNG or
memory image. Graphics extraction median per full-fleet packet is 56–105 ms in
WebGL runs and 52–55 ms in fallback runs. UI mesh-build median is about 6–12 ms;
the largest observed build is 38.1 ms. Native paint median varies from 28–58 ms
in WebGL runs and 26–27 ms in fallback runs. The UI interpolates presentation
between worker samples at the capped rendering cadence; it does not invent
simulation steps. Native simulation progress is measured separately: 2.81–5.58
simulated seconds per wall second in WebGL runs, 5.63–5.96 in fallback runs.
These observed rates are not promised pace multipliers. Warm-up/profiling/forced
diagnostic stepping are excluded from these performance figures.

## Correctness and lifecycle evidence

- [Final native worker comparison](native-3d-state-run2/verification.json):
  32 real native paints per 5/15 fleet with Port, Starboard and Tack. Ten whole
  original-image SHA-256, RNG, frame, time, clock and retained shoreline boundaries
  match the frozen reference exactly. Reference module bytes are also checked.
  This is finite trace evidence, not every possible race state.
- [Geometry and isolated rig evaluation](native-3d-geometry-run3/verification.json):
  seven native-derived fixture states, original nine-vertex main, three crew
  heads, direct native palette, moved boom and changing luff vertices. Third
  projections check depth recovery and reviewed integer-rounding tolerances.
  Six 5/15-fleet model packets agree exactly between reduced mutable-state
  graphics transport and extraction from the full image. Fixtures leave the
  entire authoritative image/RNG/shore state unchanged. A trusted free-orbit
  drag changes the camera while those paused boundaries remain identical.
- [Longer geometry session](native-3d-session-run1/verification.json):
  1,100 real native paints per fleet reach a natural race start and clock +20.
  All twelve sampled model packets match full-image extraction without native
  state changes or model errors. Maximum sampled 15-fleet model is 22,184 bytes.
  This is diagnostic pacing, not wall-time acceptance or a complete race.
- [Final lifecycle checks](GFX-01-faithful-lifecycle3/verification.json):
  original initial hashes for both fleet sizes, changing actual rendered RGBA,
  paused camera isolation, three scheduler pause/resume cycles, fleet restart,
  graphics context-loss stop/disabled controls and fresh canvas/worker recovery.
  Startup controls wait for both renderer and boat models; restart clears model
  state and diagnostics. Pixel readback is outside performance measurement.
- [2D reference foundation](native-visual-raster-run2/verification.json):
  six native/reference packet replays have zero differing RGBA bytes on the
  1024×361 transparent boat layer. This proves faithful capture of the observed
  original drawing requests; it does not claim pixel-identical arbitrary 3D.

`npm run build` passes TypeScript and production bundling. Its large-chunk
advisory remains visible; production startup/bundle delivery is APP-05/QA-07.
Frozen preservation verification still passes all 6,471 files. No original
player/source/data/runtime was edited. Original drawing now has one explicit
generated observation/private-model adapter, with separate source/output hashes;
the earlier ENG-02 report describes the prior byte-exact prototype at its commit.
The application fetches no EXE, ZIP, decompiled source or analysis/fixture inputs.
Local IBM Plex font attribution is retained under docs/IBM-Plex-OFL.txt.

## Scope and retained failed attempts

GFX-01-run1–run4 and GFX-01-lifecycle1 concern the rejected generic prototype,
including a missing trusted-input mouse move, unclassified timeout/focus stalls
and an invalid compositor focus helper. They are retained historical artifacts,
not visual acceptance. The accepted evaluator uses Page.bringToFront only.
Native-visual-raster-run1 exposed a missing setPixel observer operation; corrected
run2 passes. Native-3d-geometry-run1 used a tack fixture already equal to the
initial tack; the corrected fixture toggles its actual sign. Earlier successful
faithful runs are retained separately; run2 and the final geometry/lifecycle
reports are the linked evidence for the current decision.

Remaining work includes verified meter/course scale, editable polished boat/GLB
exports, LOD and production animation/transport, course marks/start line, native
shore geometry, tactical aids, replay/coaching, complete race QA and settled
memory/session tests. This spike's lake/trees are illustrative, its boat world
scale is provisional and Follow boat currently remains north-up. Model depth
recovery has bounded rounding error; luff phase on unseen boats need not match
the old viewport's draw order. Original physical state stays authoritative.
Pixel 11 physical testing remains QA-09, per the user's Chrome-desktop-first
decision. Unthrottled readiness is reported, but throttled network/startup
compressed bytes, actual native WebGPU and full release acceptance are unmeasured.

## Reproduction

Build and serve `versions/2026` at localhost:8770, then run from the repository:

```sh
node versions/2026/tools/renderer-eval.mjs NEW_RENDERER_DIRECTORY 5
TACT_HEADLESS=1 node versions/2026/tools/worker-eval.mjs NEW_STATE_DIRECTORY
node versions/2026/tools/native-model-eval.mjs NEW_GEOMETRY_DIRECTORY
node versions/2026/tools/native-model-session-eval.mjs NEW_SESSION_DIRECTORY
node versions/2026/tools/app-lifecycle-eval.mjs NEW_LIFECYCLE_DIRECTORY
node versions/2026/tools/reference.mjs verify
```

Tools refuse to overwrite output directories. Keep headed performance evaluation
separate from other browser checks. These integration/visual evaluations exercise
the real engine and canvas; no implementation-mirroring unit tests were added.
