# Tact 2026 MVP tracker

Implementation status: **in progress**. Created 2026-10-05.
Product and engineering contract: [PLAN-2026.md](PLAN-2026.md).
Preservation reference: commit `64d5cdf` and its existing 2010 evidence.

Initial backlog: **110 required MVP tasks** (64 P0, 46 P1) and **10 post-MVP
tasks**. All implementation checkboxes start unchecked.

## Tracking rules

Every P0 and P1 item is required for the defined MVP. P0 protects the simulation,
data or release foundation; P1 completes a promised product capability. P2 is
post-MVP and does not block release. Priority is not a license to omit P1 work.

Sizes are S (one bounded change), M (several related changes) and L (a work package
that may need splitting after its spike). They are not delivery-date estimates.
Complete prerequisites before starting dependent work; research spikes can use
temporary fixtures but cannot be accepted as the production feature.

Each checkbox has a stable ID, dependencies and a completion condition. Check it
only after attaching implementation and evidence links. For a large item, add
child IDs such as `ENG-03a` without renumbering existing tasks. A blocked item stays
unchecked and gets a row in the blocker table. Current planning documents and
historical test passes do not complete future implementation tasks.

Completion note template: `Completed YYYY-MM-DD; commit/PR: …; evidence: …;
remaining scope: …`. If scope or acceptance changes, update the plan and record
the decision before marking a task done.

## Milestone gates

| Gate | Status | Exit evidence |
| --- | --- | --- |
| M0: reference and decisions | Pending | Source/scenario pins, real-race baseline, semantic/timing inventory and bounded renderer/worker decisions |
| M1: reusable simulation | Pending | Exact driver/worker comparisons, immutable snapshots, checkpoint prototype and presentation invariance |
| M2: playable vertical slice | Pending | Low-poly race with usable helm/HUD/cameras reaching an actual finish; recorded run reconstructs |
| M3: all five pillars | Pending | Spectator/map, five tactical aid categories, persistent replay/seek, three coaching categories and review |
| M4: release hardening | Pending | Required platform/session/performance matrix, verified build/ZIP, preservation regression and release documentation |

M1 includes `RPL-01` through `RPL-03` for complete checkpoint restoration;
M2 includes `RPL-04` and `RPL-05` for recording and reconstruction of its real
race. M4 closes at `REL-07`, after every other required P0/P1 item is complete.

## First execution queue

Start with `BASE-01`, then establish reference checks and real-race observations
in `BASE-02`/`BASE-03`. Complete the side-effect/timing inventory in
`BASE-04`/`BASE-05`; freeze scenario/device choices in `BASE-06`/`BASE-07`.
Scaffold only the bounded spikes needed for `ENG-02` and `GFX-01`. Finish M0
decisions before broad implementation. A beautiful scene is not an M1 exit.

## BASE: reference, scope and decisions

- [x] **BASE-01 — Freeze the preservation reference** · P0 · S · Depends: none.

  Done when: the 2010 source/data/runtime hashes, reference commit and current
  evaluation artifacts are recorded in a 2026 baseline manifest; new work has an
  isolated location and does not overwrite preservation evidence.

  Completed 2026-10-05; atomic commit: `BASE-01: freeze the 2010 preservation
  reference`; [evaluation and scope](versions/2026/analysis/baseline/BASE-01.md),
  [verification](versions/2026/analysis/baseline/BASE-01-verification.json).
  Accepted: 6,471 frozen inputs verified; isolated mutation probes passed.

- [x] **BASE-02 — Reproduce the existing correctness baseline** · P0 · M · Depends: BASE-01.

  Done when: required existing 2010/native/browser checks pass on the frozen
  inputs, or each pre-existing failure has a reproducible report and an explicit
  disposition; current full-version mode and source/export behavior are recorded.

  Completed 2026-10-05; atomic commit: `BASE-02: reproduce and evaluate the
  frozen 2010 baseline`; [evaluation and failure disposition](versions/2026/analysis/baseline/BASE-02.md),
  [run evidence](versions/2026/analysis/baseline/BASE-02-run-2/report.json).
  Accepted: finite native/runtime/browser/export gates pass after dependency
  remediation; full mode retained; real complete-race evidence remains `BASE-03`.

- [x] **BASE-03 — Establish real complete-race evidence** · P0 · L · Depends: BASE-02.

  Done when: supported candidate setups progress through real starts, marks and
  finishes with original controls; record scenarios, inputs, finish/events and
  any baseline bugs without forcing result flags or substituting native outputs.

  Completed 2026-10-05; atomic commit: `BASE-03: establish natural complete-race
  evidence`; [evaluation](versions/2026/analysis/baseline/BASE-03.md). Both
  5/15-boat candidates finish naturally; one repeated raw finish-image pair
  matches exactly. Earlier hash-only mismatch B03-01 remains recorded.

- [x] **BASE-04 — Inventory paint and drawing side effects** · P0 · L · Depends: BASE-02.

  Done when: frame/control phases, drawing memory writes, RNG calls, retained
  locals, pixel reads and cleanup are classified with their readers and evidence;
  unresolved dependencies are explicitly listed as simulation requirements.

  Completed 2026-10-05; [evaluation](versions/2026/analysis/baseline/BASE-04.md).
  Five raw observer comparisons pass with declared host inputs. Preserve the
  full canonical paint/surface/RNG/retained context until extraction is proven.

- [ ] **BASE-05 — Audit native clock, timestep and pace semantics** · P0 · L · Depends: BASE-03, BASE-04.

  Done when: original levels 1/5/10, timer host, variable timestep and automatic
  foul slowdown are measured; a compatible logical timing profile and honest
  modern pace labels/default are documented without invented wall-time ratios.

- [ ] **BASE-06 — Freeze supported scenario manifests** · P0 · M · Depends: BASE-03, BASE-05.

  Done when: 5/15-boat Keelboat/Round Lake/windward-leeward presets, native
  weather/current settings, initial state/seed, pace and assistance are versioned
  and reproduce through verified original setup handlers.

- [x] **BASE-07 — Name target devices and freeze acceptance budgets** · P0 · S · Depends: BASE-01.

  Done when: desktop/browser/viewport/quality and one physical landscape-touch
  device are named; timing, input, download, resource and replay budgets from the
  plan have a recorded reference context and no unmeasured success claim.

  Completed 2026-10-05; atomic commit: `BASE-07: freeze Chrome targets and
  acceptance budgets`; [evaluation](versions/2026/analysis/baseline/BASE-07.md),
  [acceptance contract](versions/2026/config/acceptance.json).
  Accepted: actual Chrome desktop/GPU profile captured; Pixel 11 Chrome named
  for later physical testing; no 2026 performance or touch pass claimed.

- [ ] **BASE-08 — Finalize the nautical art and interaction brief** · P1 · M · Depends: BASE-06.

  Done when: low-poly silhouette, palette/type tokens, desktop/touch layouts,
  clean/training views and race journey have concrete mockups reviewed against
  readable sailing decisions, rather than generic dashboard styling.

- [ ] **BASE-09 — Record initial architecture decisions** · P0 · S · Depends: BASE-04, BASE-05, BASE-06, BASE-07, BASE-08, ENG-02, GFX-01.

  Done when: the canonical host/surface, simulation ownership, renderer backend,
  worker feasibility, default pace, unsupported paths and scope consequences have
  decision records linked from the plan and tracker.

## ENG: reusable 2010 simulation

- [ ] **ENG-01 — Define authoritative state and phase contracts** · P0 · L · Depends: BASE-04, BASE-05.

  Done when: adapter operations, command phases, authoritative memory/RNG/host
  state and presentation-only ranges have a written contract; exclusions have
  evidence and are not broad byte-normalization shortcuts.

- [ ] **ENG-02 — Spike worker execution and required legacy surface** · P0 · L · Depends: BASE-04, BASE-05, APP-01.

  Done when: a bounded prototype initializes and steps the reference in a worker,
  preserving required retained/global/Canvas behavior, with state comparisons and
  measured compatibility-bridge cost; unsupported dependencies are explicit.

- [ ] **ENG-03 — Extract original control and semantic phases** · P0 · L · Depends: ENG-01, BASE-09.

  Done when: required state-changing drawing/control work can be invoked in its
  original order without tying it to modern GPU rendering; extracted paths retain
  numeric behavior and have paired reference traces.

- [ ] **ENG-04 — Implement the compatible simulation driver** · P0 · L · Depends: ENG-03, BASE-05.

  Done when: scenario initialization, tick/phase execution, actual finish events
  and disposal use original engine behavior through one adapter, with no new boat
  dynamics, injected expected state or hidden demo restriction.

- [ ] **ENG-05 — Preserve canonical host and pixel-read semantics** · P0 · L · Depends: ENG-02, ENG-03.

  Done when: required GDI/pixel behavior, legacy surface/camera, retained locals
  and host callbacks match the declared reference; each removed drawing operation
  has evidence that it cannot affect authoritative output.

- [ ] **ENG-06 — Implement display-independent scheduling** · P0 · L · Depends: ENG-04, ENG-05, BASE-05.

  Done when: native steps and pace changes are preserved independently of display
  refresh; hidden resume rebases timing, late steps are handled with bounded work,
  and no silent step skipping, timestep inflation or catch-up burst occurs.

- [ ] **ENG-07 — Implement validated ordered sailing commands** · P0 · L · Depends: ENG-04, ENG-05.

  Done when: meaningful helm/trim/maneuver/pause/pace actions invoke verified
  original semantics with bounds, run IDs, accepted tick/phase and sequence;
  discrete commands survive queue pressure in a documented order.

- [ ] **ENG-08 — Map units, coordinates and stable boat IDs** · P0 · M · Depends: ENG-01, BASE-06.

  Done when: known engine points/headings/boat lengths validate a single
  original-to-render transform; distance/speed/wind units and reset/identity
  behavior are documented and used consistently by all consumers.

- [ ] **ENG-09 — Publish immutable snapshots and engine events** · P0 · L · Depends: ENG-04, ENG-08.

  Done when: versioned snapshots expose verified boat/course/race/sail fields,
  native timing and validity, plus ordered penalty/start/finish/reset events;
  ordinary rendering requires no direct engine-memory access.

- [ ] **ENG-10 — Export safe environmental and tactical telemetry** · P0 · L · Depends: ENG-09, ENG-05.

  Done when: wind/current/air/sail readouts identify their true/local/apparent
  meaning; stateful samplers are isolated or avoided and observation cannot
  consume live RNG, modify globals or change a future simulation result.

- [ ] **ENG-11 — Expose retained-state and host serialization hooks** · P0 · L · Depends: ENG-03, ENG-05.

  Done when: original retained frames, host clock/phase and adapter-owned mutable
  context can be enumerated and serialized at safe boundaries; ignored caches
  have a reproducibility argument verified against future output.

- [ ] **ENG-12 — Verify exact adapter-versus-reference traces** · P0 · L · Depends: ENG-04, ENG-05, ENG-07, ENG-09, ENG-11.

  Done when: initial and per-boundary state, RNG and event ordering match for
  supported scenarios, controls, slowdowns, resets and retained-state cases;
  any allowed presentation exclusions are versioned and narrowly justified.

- [ ] **ENG-13 — Complete the production worker and bounded transport** · P0 · L · Depends: ENG-02, ENG-06, ENG-07, ENG-09, ENG-11.

  Done when: worker startup, commands, snapshots, errors, pause/resume and disposal
  work with bounded transfer buffers; original arithmetic/host state are isolated
  and generation IDs reject late messages from a previous run.

- [ ] **ENG-14 — Prove simulation and presentation independence** · P0 · L · Depends: ENG-12, ENG-13.

  Done when: the same commands produce exact authoritative traces at varied
  presentation schedules and with different camera/quality/observer configurations;
  simulation progress is measured independently of render callback counts.

## APP: modern application foundation

- [ ] **APP-01 — Create an isolated modern development scaffold** · P0 · M · Depends: BASE-01, BASE-07.

  Done when: `versions/2026` has a minimal TypeScript/Vite setup, pinned dependencies,
  a development page and a bounded spike route; the original no-install player
  paths and existing build commands remain usable.

- [ ] **APP-02 — Implement race and replay lifecycle ownership** · P0 · L · Depends: APP-01, ENG-07, ENG-09.

  Done when: loading/setup/prestart/racing/pause/finish/replay/error transitions
  own inputs, worker, recording and run IDs; only actual engine events open live
  results and restarts dispose the old run cleanly.

- [ ] **APP-03 — Build setup, forecast and supported-preset selection** · P1 · M · Depends: APP-02, BASE-06.

  Done when: 5/15-boat supported scenarios, verified weather/current options and
  explicit pace/assistance settings initialize the expected engine configuration;
  unsupported modern content is not presented as playable.

- [ ] **APP-04 — Implement pause, modal and hidden-page behavior** · P0 · M · Depends: APP-02, ENG-06.

  Done when: pause/settings/visibility transitions stop progression appropriately,
  clear held controls and resume without an input leak or time catch-up; camera
  inspection while paused behaves as specified.

- [ ] **APP-05 — Load and validate runtime/graphics assets** · P0 · M · Depends: APP-01, GFX-01, ENG-13.

  Done when: engine data, worker code and models load through declared manifests,
  hashes and paths, with progress/retry states; startup rejects incompatible
  asset versions and never requests EXEs or proof fixtures.

- [ ] **APP-06 — Add separate versioned modern preferences** · P1 · M · Depends: APP-03.

  Done when: camera/input/quality/assistance/sound preferences persist and migrate
  in a `tact-2026` namespace, can be reset, and never overwrite or reinterpret
  the 2010 preference archive.

- [ ] **APP-07 — Provide recoverable errors and diagnostics** · P0 · M · Depends: APP-02, APP-05.

  Done when: boot/runtime/worker errors stop unsafe progression, keep useful
  context and provide restart/export/classic-edition actions without silently
  resetting a race or leaving controls enabled on a dead worker.

- [ ] **APP-08 — Add bounded sound controls and event cues** · P1 · S · Depends: APP-02, APP-05.

  Done when: explicit enable/volume controls and start/penalty/finish cues work
  after a user gesture, respect pause/replay/mute and do not leak audio instances
  across restart; added assets and original notices are tracked.

## GFX: low-poly scene and smooth rendering

- [ ] **GFX-01 — Compare and pin the renderer backend** · P0 · M · Depends: APP-01, BASE-07.

  Done when: a bounded Three.js WebGL 2/WebGPU spike checks startup, materials,
  worker coexistence, target devices and timings; the proposed WebGL 2 MVP choice
  or an evidence-backed alternative is recorded with an exact dependency version.

- [ ] **GFX-02 — Establish model, material and export conventions** · P1 · M · Depends: BASE-08, ENG-08, GFX-01.

  Done when: scale/axes/origin, sail pivots, flat shading, GLB export, editable
  source locations, LOD/material budgets and naming/provenance are documented
  and tested on one reference model.

- [ ] **GFX-03 — Create the polished low-poly keelboat** · P1 · L · Depends: GFX-02.

  Done when: hull/deck/mast/boom/sails/simple crew have a readable silhouette,
  correct proportions and usable articulation, fit the asset budget, and ship
  with editable source, provenance and verified exports.

- [ ] **GFX-04 — Implement fleet LOD and shared geometry/materials** · P1 · M · Depends: GFX-03.

  Done when: 5/15-boat fleets instantiate stable boat IDs efficiently, with distant
  geometry and color/selection distinctions; instancing/bounding volumes work
  correctly and boats are not incorrectly culled after movement.

- [ ] **GFX-05 — Render authoritative poses and course geometry** · P0 · M · Depends: GFX-02, ENG-09.

  Done when: boat positions/headings, start line and marks align with verified
  engine coordinates; visual picking and the course map use the same transform,
  and renderer code cannot mutate simulation state.

- [ ] **GFX-06 — Animate sails, boom, heel and simple crew** · P1 · L · Depends: GFX-03, GFX-05.

  Done when: verified tack/trim/luff/heel data visibly drives the rig with bounded
  geometry updates; illustrative animation is distinguished from authoritative
  values and uses no simulation RNG or physical feedback.

- [ ] **GFX-07 — Build the low-poly Round Lake environment** · P1 · L · Depends: GFX-02, BASE-06, ENG-08.

  Done when: shoreline, land, marks and restrained scenery fit the art brief and
  authoritative navigable geometry; landmark and shore-crossing checks expose
  no misleading collision gaps or world-scale mismatches.

- [ ] **GFX-08 — Implement lightweight animated water** · P1 · M · Depends: GFX-01, GFX-07.

  Done when: bounded water animation/materials are readable in chase/overhead
  views, respect low quality/reduced motion and do not masquerade as current
  measurements or introduce expensive per-boat reflection passes.

- [ ] **GFX-09 — Add pooled wakes and minimal effects** · P1 · M · Depends: GFX-05, GFX-08.

  Done when: wakes follow recorded boat motion, reset cleanly and stay within
  fixed resource budgets; they do not imply an exact aerodynamic field and
  contribute no engine inputs or RNG calls.

- [ ] **GFX-10 — Implement snapshot interpolation and discontinuities** · P0 · L · Depends: GFX-05, ENG-06.

  Done when: variable-time positions/wrapped headings interpolate correctly;
  resets, seeks, hidden resume, pace changes and late data clear/rebase buffers
  without fictitious collisions, extrapolated physics or stale-run poses.

- [ ] **GFX-11 — Bound quality, pixel ratio and resource lifetime** · P0 · M · Depends: GFX-04, GFX-06, GFX-07, GFX-08, GFX-09, GFX-10.

  Done when: standard/low settings, shadow/LOD/DPR limits and reuse/disposal work
  through resize/restart/seek; per-frame allocation and reported mesh/material/
  texture/draw-call counts remain bounded.

- [ ] **GFX-12 — Handle graphics context loss and unsupported devices** · P0 · M · Depends: GFX-11, APP-07.

  Done when: context loss can rebuild presentation from the live snapshot or
  offer a clear recovery/classic route; unsupported rendering never resets the
  authoritative engine silently or traps the user on a blank screen.

- [ ] **GFX-13 — Review representative scene readability** · P1 · M · Depends: GFX-11, CAM-01, CAM-02, UI-04.

  Done when: screenshots/motion captures show legible sails, marks, opponents,
  warnings and shoreline in both quality modes and key sailing situations;
  contrast/selection works independently of color and art follows the brief.

## CAM: cameras and synchronized map

- [ ] **CAM-01 — Implement stable chase camera** · P1 · M · Depends: GFX-10.

  Done when: follow distance/height/look-ahead and bounded damping keep the
  player, nearby boats and course readable through tacks without excessive roll,
  obstruction or a dependence on authoritative camera memory.

- [ ] **CAM-02 — Implement tactical overhead view** · P1 · M · Depends: GFX-05, ENG-08.

  Done when: north-up/boat-up, pan/zoom/recenter and course framing work with
  consistent distances and IDs, including the start and mark-rounding regions.

- [ ] **CAM-03 — Implement spectator orbit and boat focus** · P1 · M · Depends: CAM-01.

  Done when: orbit/pan/select/focus/recenter works with bounded camera movement;
  observing another boat does not transfer helm ownership or change engine state.

- [ ] **CAM-04 — Build the snapshot-driven course map** · P1 · M · Depends: CAM-02, ENG-09.

  Done when: player/opponents/marks/start line/current leg match the scene under
  both map orientations and different aspect ratios, without a second position
  calculation or hidden engine reads.

- [ ] **CAM-05 — Resolve camera controls and gesture ownership** · P0 · M · Depends: CAM-01, CAM-02, CAM-03, UI-07.

  Done when: switching modes and pointer/touch capture give a gesture exactly
  one owner; camera gestures never issue helm commands and steering never orbits
  the scene unexpectedly.

- [ ] **CAM-06 — Add reduced-motion camera behavior** · P1 · S · Depends: CAM-05, UI-10.

  Done when: settings remove decorative bob/roll/long transitions while preserving
  follow/recenter usability, visible course information and the same engine trace.

- [ ] **CAM-07 — Rebase cameras across lifecycle changes** · P0 · M · Depends: CAM-05, APP-02.

  Done when: setup/start/pause/finish/restart and changed boat IDs reset targets
  safely; camera movement remains available while paused without affecting input
  ownership or race progression.

## UI: understandable keyboard, mouse and touch play

- [ ] **UI-01 — Implement visual tokens and local typography** · P1 · S · Depends: BASE-08, APP-01.

  Done when: nautical palette, type scale, tabular readouts, focus styles and
  control sizes are shared tokens; selected local font assets, fallback behavior
  and notices are recorded.

- [ ] **UI-02 — Build the desktop scene/HUD layout** · P1 · M · Depends: UI-01, APP-02.

  Done when: viewport, instrument strip, helm/trim area, course-map slot and
  collapsible race/settings panel remain usable at the declared desktop sizes
  with semantic HTML controls and no obstruction of the central sailing scene.

- [ ] **UI-03 — Map verified sailing actions to keyboard controls** · P0 · M · Depends: UI-02, ENG-07.

  Done when: steer/trim/shape/maneuver/pause/pace shortcuts share the adapter
  command semantics, support documented repeat behavior and do not hijack
  typing, focused controls or dialogs.

- [ ] **UI-04 — Display authoritative instruments and status** · P1 · M · Depends: UI-02, ENG-09, ENG-10.

  Done when: speed/wind angle/sail state/leg/position/penalties and next target
  use verified units and validity flags; pending actions are distinct from
  applied values and no estimated readout is presented as engine truth.

- [ ] **UI-05 — Implement helm, sheet, shape and maneuver controls** · P0 · M · Depends: UI-03, UI-04.

  Done when: labeled buttons/sliders provide immediate visual acknowledgement
  and ordered engine application; bounds and original control phases match
  keyboard behavior, with no undisclosed auto-trim or steering changes.

- [ ] **UI-06 — Add pace/assistance/settings and concise control help** · P1 · M · Depends: UI-05, APP-03, APP-06.

  Done when: native pace labels, foul-slowdown toggle, quality/input/sound choices
  and help match persisted scenario/settings behavior; descriptions distinguish
  display FPS, simulation pace and historical rules.

- [ ] **UI-07 — Implement unified pointer input and capture** · P0 · M · Depends: UI-05.

  Done when: mouse/touch press, move, release, wheel and cancellation use explicit
  control ownership and the same ordered actions as keyboard; no pointer outside
  the control can leave steering/trim active indefinitely.

- [ ] **UI-08 — Build landscape touch layout and orientation handling** · P1 · L · Depends: UI-07, UI-02.

  Done when: separated steering/trim areas, ≥44 CSS px primary targets and a
  collapsible map work on the named device; portrait shows usable setup/results
  and guidance, and rotating does not reset the active race.

- [ ] **UI-09 — Integrate camera/map/overlay navigation controls** · P1 · M · Depends: UI-02, CAM-01, CAM-02, CAM-03, CAM-04.

  Done when: camera mode, follow/recenter/map actions and training/clean-view
  entry points are discoverable with keyboard and touch, without mixing camera
  intent with sailing actions.

- [ ] **UI-10 — Verify accessible interaction and status feedback** · P1 · M · Depends: UI-02, UI-04.

  Done when: focus order/labels, contrast, color-independent warnings,
  reduced-motion preferences and restrained status announcements work; high
  frequency numeric updates do not overwhelm assistive output.

- [ ] **UI-11 — Eliminate held-input leaks across transitions** · P0 · M · Depends: UI-03, UI-07, APP-04.

  Done when: blur, hidden page, pause, settings, pointer cancellation and run
  replacement clear held actions with browser-level checks; stale commands from
  a previous mode/race are rejected.

- [ ] **UI-12 — Validate the complete player journey** · P1 · L · Depends: UI-06, UI-08, UI-09, UI-10, UI-11, APP-07, CAM-06, CAM-07.

  Done when: setup/forecast/start/race/pause/finish/review/retry paths are usable
  with real inputs, no control trap and understandable errors; observed usability
  findings have fixes or explicit MVP scope decisions.

## OVL: optional tactical aids

- [ ] **OVL-01 — Define overlay data and uncertainty contracts** · P0 · M · Depends: ENG-10, BASE-08.

  Done when: Wind/Current/Air/Course/Start sources, update cadence, units,
  validity and exact-versus-estimated meaning are specified; stateful environmental
  samplers cannot be called casually on the live engine.

- [ ] **OVL-02 — Build read-only overlay state and toggles** · P1 · M · Depends: OVL-01, UI-04, CAM-04.

  Done when: clean/training views and individual aids render from snapshots,
  persist sensible visual preferences and remain synchronized with the course
  map without changing sailing configuration.

- [ ] **OVL-03 — Add local wind, shifts and safe field arrows** · P1 · L · Depends: OVL-02, ENG-10.

  Done when: player wind and shift history are clearly labeled; field arrows
  use safe supported sampling or are suppressed, and true/apparent/local/global
  wind are never conflated in UI or coaching.

- [ ] **OVL-04 — Add authoritative current indicators** · P1 · M · Depends: OVL-02, ENG-10.

  Done when: current at the player and any valid field samples match engine
  units/direction/strength, handle zero/unavailable data, and remain visibly
  distinct from decorative water animation.

- [ ] **OVL-05 — Add engine-backed clean/disturbed-air aid** · P1 · M · Depends: OVL-02, ENG-10.

  Done when: verified air status and any supported responsible-boat information
  are shown; a visual cone is omitted or explicitly illustrative unless an
  authoritative field has been proven and exported safely.

- [ ] **OVL-06 — Add next-mark and estimated layline guidance** · P1 · M · Depends: OVL-02, ENG-08, ENG-09.

  Done when: course/mark alignment is correct, the sailing-angle assumption is
  documented and guidance is marked estimated; invalid/stale inputs suppress
  aids instead of implying an optimal route.

- [ ] **OVL-07 — Add start-line/countdown/distance aids** · P1 · M · Depends: OVL-02, ENG-09.

  Done when: line geometry, signed distance and engine countdown agree with
  reference cases; estimated timing/bias warnings are distinguished from actual
  early-start penalties and race events.

- [ ] **OVL-08 — Complete legends, map equivalents and concise help** · P1 · S · Depends: OVL-03, OVL-04, OVL-05, OVL-06, OVL-07.

  Done when: every aid has units, validity/meaning explanations and readable map
  representation where relevant; Clean view removes visual aids without
  silently disabling a simulation feature.

- [ ] **OVL-09 — Verify aid purity and combined performance** · P0 · M · Depends: OVL-08, ENG-14.

  Done when: each aid and all aids together preserve exact authoritative traces
  across cameras, and measured update/render costs, stale data and temporary
  resource counts stay within the declared budgets.

## RPL: deterministic recording, persistence and playback

- [ ] **RPL-01 — Define replay manifest and accepted-command format** · P0 · M · Depends: BASE-06, BASE-05, ENG-07, ENG-09.

  Done when: engine/application/data versions, scenario/initial state/RNG, host
  profile, accepted tick/phase commands and events have a versioned format;
  replay controls are separate from authoritative sailing inputs.

- [ ] **RPL-02 — Inventory complete checkpoint state** · P0 · L · Depends: ENG-11, RPL-01.

  Done when: memory, retained locals, RNG, host clock, driver phase and queues
  are accounted for at a safe boundary; original race-history save/restore is
  not assumed to be a complete replay checkpoint.

- [ ] **RPL-03 — Implement exact binary checkpoints and restoration** · P0 · L · Depends: RPL-02, ENG-13.

  Done when: fresh-engine restore preserves original integer/float/extended
  representations and relevant contexts, with version/hash/bounds checks and
  identical future traces after restored checkpoints.

- [ ] **RPL-04 — Record commands, events and checkpoints during play** · P0 · M · Depends: RPL-01, RPL-03.

  Done when: recording captures accepted commands and authoritative events
  without altering simulation RNG/timing semantics, exposes its active status
  and stops cleanly on finish/restart/error.

- [ ] **RPL-05 — Implement deterministic seek and playback driver** · P0 · L · Depends: RPL-03, RPL-04.

  Done when: compatible checkpoints plus recorded commands reconstruct forward
  and backward targets; playback speed changes scheduling only, and generation
  IDs prevent stale seek/worker responses from replacing the requested state.

- [ ] **RPL-06 — Build replay timeline and playback controls** · P1 · M · Depends: RPL-05, UI-02, CAM-07.

  Done when: play/pause/scrub/speed/event navigation/selected-boat inspection work
  with all cameras; live sailing commands are disabled and loading/seeking states
  remain clear and cancellable.

- [ ] **RPL-07 — Reset rendering and cameras on replay discontinuities** · P0 · M · Depends: RPL-06, GFX-10.

  Done when: seeks/recording switches reset interpolation/wakes/camera targets
  and reconcile run IDs, so old poses/events never bleed into the new timeline.

- [ ] **RPL-08 — Persist and manage local recordings safely** · P1 · M · Depends: RPL-04, APP-06.

  Done when: separate versioned IndexedDB records support listing/naming/loading/
  deletion with metadata; quota/unavailable-storage handling offers export and
  never deletes another replay or breaks a live race.

- [ ] **RPL-09 — Implement bounded export/import and version handling** · P0 · M · Depends: RPL-08, RPL-03.

  Done when: exported records round-trip exactly; oversized/malformed/corrupt/
  incompatible inputs fail with clear recovery, length/schema/hash validation
  and no execution of replay-provided code or external resource paths.

- [ ] **RPL-10 — Implement retry of the same initial scenario** · P1 · M · Depends: APP-03, RPL-01.

  Done when: initial state/RNG/configuration can be restored for a new attempt;
  UI explains that different actions may change future weather/AI RNG evolution,
  and does not label a retry as identical future conditions.

- [ ] **RPL-11 — Prove full recording and checkpoint round trips** · P0 · L · Depends: RPL-03, RPL-04, RPL-05, RPL-09.

  Done when: original live run, fresh replay, imported replay and several
  checkpoint-restored runs match each authoritative boundary and real finish;
  a failed match stops playback and retains useful evidence.

- [ ] **RPL-12 — Meet recording, storage and seek budgets** · P1 · L · Depends: RPL-07, RPL-08, RPL-11.

  Done when: the named reference recording, 30-minute support cap, proposed
  50 MiB limit and ten-minute replay seek target have measured evidence; exact
  delta/compression choices and quota degradation are documented.

## COA: explainable coaching and race review

- [ ] **COA-01 — Define coaching telemetry, thresholds and provenance** · P0 · M · Depends: ENG-09, ENG-10, RPL-04.

  Done when: source/units/validity for each insight and versioned observation
  windows/thresholds are explicit; derived metrics are read-only and cannot
  assert causal time loss or optimal routes without evidence.

- [ ] **COA-02 — Add start-execution insights** · P1 · M · Depends: COA-01, OVL-07.

  Done when: actual start crossing/early-start/lateness observations use validated
  events, point to a replay interval, and distinguish engine penalties from
  training estimates or unavailable data.

- [ ] **COA-03 — Add sustained luffing and trim observations** · P1 · M · Depends: COA-01, UI-04.

  Done when: prolonged engine-backed luff/trim states produce concise threshold-
  based insights with duration and context; ordinary tacks/invalid samples do not
  trigger fabricated advice or unsupported “seconds lost” claims.

- [ ] **COA-04 — Add observed wind-shift and tack-timing review** · P1 · M · Depends: COA-01, OVL-03.

  Done when: actual local/global wind sources and maneuver events support
  explainable intervals, with disturbed air and missing data handled correctly;
  observations never become a second wind or AI model.

- [ ] **COA-05 — Build post-race track/charts/insight navigation** · P1 · L · Depends: COA-02, COA-03, COA-04, RPL-06, RPL-08.

  Done when: course track, speed/wind/luff charts and key events are synchronized
  with replay; selecting an insight seeks correctly, and users can save/retry
  from a real finished-race review.

- [ ] **COA-06 — Compare two recorded attempts honestly** · P1 · M · Depends: COA-05, RPL-10, RPL-08.

  Done when: recorded tracks/results align by simulation time or milestone,
  differing conditions/settings are labeled, and comparisons show observations
  without implying identical future weather or a causal optimum.

## QA: correctness, performance and full-session evidence

- [ ] **QA-01 — Establish automated baseline and modern contract gates** · P0 · M · Depends: APP-01, BASE-02, ENG-01.

  Done when: existing preservation checks plus modern type/contract tests run
  reproducibly in the development/CI workflow; new driver/replay tests join the
  gate as their features land and fixture expectations are not weakened.

- [ ] **QA-02 — Measure render, simulation and transport independently** · P0 · M · Depends: GFX-11, ENG-13.

  Done when: actual completed scene cadence, engine progression, bridge work,
  bounded transport and GPU work where available have separate observations;
  CPU draw-call timings and rAF callback counts cannot masquerade as GPU/FPS proof.

- [ ] **QA-03 — Measure trusted camera, HUD and sailing response** · P0 · M · Depends: UI-12, CAM-07, ENG-14.

  Done when: real keyboard/mouse events measure visible camera/HUD response and
  accepted/applied helm phases separately; all samples/outliers remain in reports,
  with native deliberate delay distinguished from host overhead.

- [ ] **QA-04 — Run repeated reference performance acceptance** · P0 · L · Depends: QA-02, QA-03, OVL-09, RPL-12, BASE-07.

  Done when: five repeated unprofiled runs at fixed device/browser/surface/quality
  meet the frozen desktop cadence/input/resource gates, with source/context pins,
  real visibility, warm-up and all-aids/replay lanes reported independently.

- [ ] **QA-05 — Complete supported races across engine conditions** · P0 · L · Depends: UI-12, OVL-09, RPL-11, COA-05.

  Done when: 5/15-boat races, selected wind/current states, pace changes, starts,
  penalties and rounding paths reach actual finishes; at least three independent
  complete reference races have state/event/recording evidence.

- [ ] **QA-06 — Run a 30-minute mixed-session and resource soak** · P0 · L · Depends: QA-05, QA-04.

  Done when: live play, pause/resume, repeated restarts and seeks produce no
  crashes, stale-input leaks or accumulating resources; warmed memory/resource
  comparisons and any deliberate bounds are retained.

- [ ] **QA-07 — Stress the inherited 30-boat engine/scene case** · P1 · M · Depends: QA-02, UI-12.

  Done when: the internal stress scenario reports correctness, queues,
  cadence/resources and graceful degradation; it remains separate from supported
  5/15-boat public presets unless explicitly promoted with its own evidence.

- [ ] **QA-08 — Validate Chrome desktop** · P0 · L · Depends: QA-05, QA-03.

  Done when: the specified Chrome desktop version passes startup, original
  numerical/worker behavior, controls, graphics, replay and real finish checks;
  renderer/asset failure handling and platform-specific limits are documented.

- [ ] **QA-09 — Validate the named physical landscape-touch device** · P1 · L · Depends: UI-08, QA-05.

  Done when: actual hardware passes steering/trim/camera gestures, rotation,
  hidden resume, finish/replay and its separate low-quality cadence/input targets;
  desktop touch emulation is not recorded as a physical-device pass.

- [ ] **QA-10 — Exercise recovery, persistence and import failures** · P0 · M · Depends: GFX-12, APP-07, RPL-09.

  Done when: missing assets, dead workers, context loss, storage quota and bad
  replay inputs fail safely, retain existing user recordings and provide workable
  recovery without corrupting a live engine or silently changing versions.

- [ ] **QA-11 — Verify behavior through the production build** · P0 · L · Depends: REL-02, QA-05, RPL-11.

  Done when: built/bundled engine and worker match declared source behavior;
  actual input, complete race, replay/import and supported graphics checks pass
  without development-only helpers or proof-fixture/EXE requests.

- [ ] **QA-12 — Review the final implementation and fix findings** · P0 · L · Depends: QA-01, QA-04, QA-06, QA-07, QA-08, QA-09, QA-10, QA-11, COA-06.

  Done when: state/control/worker/replay/render/resource paths receive an
  evidence-first review, confirmed findings are fixed with appropriate checks,
  and no unresolved divergence, crash, data-loss or finish-blocking finding remains.

## REL: candidate export and release readiness

- [ ] **REL-01 — Complete model/font/audio attribution and notices** · P0 · S · Depends: GFX-03, GFX-07, UI-01, APP-08.

  Done when: original engine/data credits and notices for each new distributed
  model/font/sound are included with its source/provenance, and export inputs
  contain only assets intended for the modern player.

- [ ] **REL-02 — Build the isolated static 2026 candidate** · P0 · M · Depends: APP-05, GFX-13, UI-12, OVL-09, RPL-12, COA-06, REL-01.

  Done when: modern root commands produce `dist-2026` with pinned bundles,
  workers, assets and manifest hashes; the production graph contains no EXEs,
  proof fixtures, analysis output or broken subpath imports.

- [ ] **REL-03 — Package and verify the browser ZIP** · P0 · M · Depends: REL-02, QA-11.

  Done when: `posey-2026-browser.zip` matches the candidate byte-for-byte,
  extraction/serving works, and source/build/archive manifests and behavior
  reports identify the same candidate version.

- [ ] **REL-04 — Recheck the 2002/2010 preservation editions** · P0 · M · Depends: REL-03, BASE-02.

  Done when: shared changes and modern build commands leave original player
  routes, numerical evidence, preferences, full/demo modes and downloadable
  exports intact, with appropriate regression evidence.

- [ ] **REL-05 — Write player/release documentation and known limits** · P1 · M · Depends: QA-12, REL-03, REL-04.

  Done when: launch/controls, supported content/devices, historical rules profile,
  pace/slowdown, replay/retry distinction, storage limits and measured performance
  are documented without universal equivalence or physical-latency claims.

- [ ] **REL-06 — Link the modern edition from the project entry points** · P1 · S · Depends: REL-05.

  Done when: launcher/README navigation clearly distinguishes 2002 demo, 2010
  preservation full version and 2026 modern release, and all links target the
  verified candidate without confusing shared preferences or support claims.

- [ ] **REL-07 — Close the MVP readiness matrix** · P0 · S · Depends: REL-05, REL-06, QA-12, REL-04, REL-03, REL-08.

  Done when: every other required P0/P1 item has evidence, milestone gates are
  closed, actual finish/replay/full-version/performance/platform checks pass,
  and the remaining nonblocking limitations are explicitly recorded.

- [ ] **REL-08 — Prepare the reviewed release and publishing procedure** · P1 · S · Depends: REL-05, REL-03, REL-04, QA-12.

  Done when: the candidate has a reviewable commit/version, archive hashes,
  static-host deployment/rollback instructions and a reproducible release record;
  actual remote publication is performed only under the user's applicable
  instruction, with the final candidate available for review first.

## P2: explicitly post-MVP

- [ ] **POST-01 — Add more native boat classes and venues** · P2 · L · Depends: REL-07.

  Done when: each added class/venue has its own polished assets, controls,
  scenario manifest and native/modern behavior/performance evidence.

- [ ] **POST-02 — Add portrait phone and gamepad support** · P2 · L · Depends: REL-07.

  Done when: new layouts/input mappings are validated on actual supported
  devices without weakening existing steering/camera ownership or accessibility.

- [ ] **POST-03 — Promote WebGPU if justified by measurements** · P2 · L · Depends: REL-07, GFX-01.

  Done when: target-browser compatibility, materials, resources and repeatable
  performance justify the backend and preserve identical authoritative traces.

- [ ] **POST-04 — Add controlled-weather comparison profiles** · P2 · L · Depends: REL-07, RPL-10, COA-06.

  Done when: independent environmental playback/branching has a defined
  simulation contract and evidence; retries can legitimately be compared under
  controlled future conditions rather than merely sharing an initial seed.

- [ ] **POST-05 — Add noninteractive replay ghosts** · P2 · M · Depends: REL-07, COA-06.

  Done when: aligned recorded tracks render as clearly labeled ghosts without
  affecting AI, collisions, air/water sampling, RNG or race outcomes.

- [ ] **POST-06 — Extend disturbed-air field visualization** · P2 · L · Depends: REL-07, OVL-05.

  Done when: a verified read-only aerodynamic field supports meaningful spatial
  geometry and its approximate/exact scope is clear; cones are not fabricated
  as substitutes for engine data.

- [ ] **POST-07 — Design newer rules or simulation profiles** · P2 · L · Depends: REL-07.

  Done when: a separate named/versioned profile has specified differences and
  independent validation, with preserved 2010 behavior remaining available.

- [ ] **POST-08 — Evaluate multiplayer and network determinism** · P2 · L · Depends: REL-07, ENG-14, RPL-11.

  Done when: authority, synchronization, reconnect and fairness have a concrete
  design and prototype evidence before introducing servers/accounts into the
  shipping single-player architecture.

- [ ] **POST-09 — Add course editing and longer-term race progression** · P2 · L · Depends: REL-07.

  Done when: editable geometry/race progression have validated engine contracts,
  persistence and replay versioning, rather than unsupported configuration writes.

- [ ] **POST-10 — Add offline installation and optional cloud replay storage** · P2 · L · Depends: REL-07, RPL-09.

  Done when: cache/version/quota/recovery and optional service ownership are
  designed and tested; old replays and preserved editions remain accessible.

## Blockers and scope decisions

Known research risks are documented in the plan and assigned to BASE/ENG/RPL
tasks. Findings below remain open until their follow-up evidence resolves them.

| Task | Blocker / evidence | Next concrete action | Decision link |
| --- | --- | --- | --- |
| B03-01 / BASE-04, ENG/QA | Earlier full-image hashes differ despite matching race telemetry; later raw pair matches | Classify drawing/host dependencies; retain raw snapshots on any recurrence | [BASE-03](versions/2026/analysis/baseline/BASE-03.md) |

## Completion evidence log

Check tasks off only after evaluating their acceptance criteria, and link the
retained evidence here.

| Task / milestone | Completed | Commit / PR | Test / report / artifact | Remaining limitation |
| --- | --- | --- | --- | --- |
| BASE-01 | 2026-10-05 | `cb60695` | [Evaluation](versions/2026/analysis/baseline/BASE-01.md) | Integrity baseline only |
| BASE-02 | 2026-10-05 | Atomic `BASE-02` commit; see file history | [Evaluation](versions/2026/analysis/baseline/BASE-02.md) | Finite checks; real races and modern performance remain open |
| BASE-07 | 2026-10-05 | Atomic `BASE-07` commit; see file history | [Evaluation](versions/2026/analysis/baseline/BASE-07.md) | Performance unmeasured; Pixel 11 physical validation later |
| BASE-03 | 2026-10-05 | Atomic `BASE-03` commit; see file history | [Evaluation](versions/2026/analysis/baseline/BASE-03.md) | B03-01 recorded; controlled races do not certify smoothness or all replay state |
| BASE-04 | 2026-10-05 | Atomic `BASE-04` commit; see file history | [Evaluation](versions/2026/analysis/baseline/BASE-04.md) | Unclassified aliases/branches retained as simulation requirements |
| — | — | — | — | — |
