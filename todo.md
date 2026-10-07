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

- [x] **BASE-05 — Audit native clock, timestep and pace semantics** · P0 · L · Depends: BASE-03, BASE-04.

  Done when: original levels 1/5/10, timer host, variable timestep and automatic
  foul slowdown are measured; a compatible logical timing profile and honest
  modern pace labels/default are documented without invented wall-time ratios.

  Completed 2026-10-05; [evaluation](versions/2026/analysis/baseline/BASE-05.md).
  Native 1/5/10 and natural foul slowdown measured; default 10 replaces the
  provisional 5. [Compatible timing contract](versions/2026/config/timing.json).

- [x] **BASE-06 — Freeze supported scenario manifests** · P0 · M · Depends: BASE-03, BASE-05.

  Done when: 5/15-boat Keelboat/Round Lake/windward-leeward presets, native
  weather/current settings, initial state/seed, pace and assistance are versioned
  and reproduce through verified original setup handlers.

  Completed 2026-10-05; [evaluation](versions/2026/analysis/baseline/BASE-06.md).
  Both [presets](versions/2026/config/scenarios/) reproduce exact initial image,
  RNG, retained shoreline and complete original preferences in fresh sessions.

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

The production cutover sequence and evaluation gates are specified in
[engine-cutover.md](versions/2026/docs/engine-cutover.md). The target excludes
original lifecycle, Canvas/GDI, pixel reads and drawing callbacks from the
production engine; preserved players remain comparison references.

- [ ] **ENG-01 — Define authoritative state and phase contracts** · P0 · L · Depends: BASE-04, BASE-05.

  Done when: adapter operations, command phases, authoritative memory/RNG/host
  state and presentation-only ranges have a written contract; exclusions have
  evidence and are not broad byte-normalization shortcuts.

- [x] **ENG-02 — Spike worker execution and required legacy surface** · P0 · L · Depends: BASE-04, BASE-05, APP-01.

  Done when: a bounded prototype initializes and steps the reference in a worker,
  preserving required retained/global/Canvas behavior, with state comparisons and
  measured compatibility-bridge cost; unsupported dependencies are explicit.

- [ ] **ENG-03 — Extract original control and semantic phases** · P0 · L · Depends: ENG-01, BASE-09.

  Done when: required state-changing drawing/control work can be invoked in its
  original order without tying it to modern GPU rendering; extracted paths retain
  numeric behavior and have paired reference traces.

- [x] **ENG-03a — Establish paired cutover traces and the dependency ledger.**

  Compare the current 2026 bridge and candidate with identical inputs/policies,
  and retain a separate frozen 2010 comparison lane. Trace state writes/reads,
  intermediate stores, RNG order, retained state and pixel branches. Instrumented
  execution must match plain execution before the observer is accepted.
  Evaluated: 33 whole-image/RNG/context boundaries across four 2026 scenarios,
  with both plain/traced candidates matched to pinned `ce6d9bf`; ten frozen 2010
  boundaries for five/fifteen boats. Three cases reach real racing. Five observer
  tests pass. This is bounded ledger coverage; computed aliases/unvisited branches
  still require classification. See `versions/2026/analysis/app/ENG-03a.md`.

- [ ] **ENG-03b — Extract drawing-owned gameplay phases one callback at a time.**

  Move waypoint/course, slowdown, warning, result/score and cleanup behavior into
  explicit engine functions. Classify camera and host fields. Require paired
  state/RNG and continued future-output evidence for each removed dependency.

- [x] **ENG-03b.1 — Extract race and information-screen state transitions.**

  Independent strict TypeScript controller with injected compatibility actions;
  no Canvas/GDI/browser imports. Preserve sequential reloads and signed phase
  counter behavior. Evaluated: 112 dispatcher cases, seven focused tests,
  65 exact current-2026 paired boundaries including racing/panel transitions,
  ten frozen 2010 boundaries, 14 controls/depth checks and unchanged preservation
  inputs. See `versions/2026/analysis/app/ENG-03b-1.md`.
  The parent extraction and original offscreen rendering remain unfinished.

- [x] **ENG-03b.2 — Extract precise waypoint placement from drawing.**

  Renderer-free domain kernel and typed position/numeric/storage ports. Retain
  anchoring, all retries, exact raw-angle arithmetic, ordered F64 stores and RNG.
  Evaluated: 336 recovered public/numeric cases, six actual crowded-neighbor
  comparisons with two/four/six draws, 65 exact 2026 paired boundaries and ten
  frozen 2010 boundaries. See `versions/2026/analysis/app/ENG-03b-2.md`.
  Calling-phase extraction and remaining scene/pixel dependencies stay open.

- [x] **ENG-03b.3 — Extract the two compatibility camera-state writers.**

  Pure typed phase/ports preserve automatic time/near-mark gates, signed offsets,
  tack/wind modes and asymmetric player-two target behavior. Evaluated: 2,048
  recovered public/numeric full-state comparisons, fourteen distant-mark gate
  cases, 65 exact 2026 boundaries and ten frozen 2010 boundaries. See
  `versions/2026/analysis/app/ENG-03b-3.md`. World invocation/pixels remain open.

- [x] **ENG-03b.4 — Extract automatic foul slowdown rules.**

  Named typed state facade and renderer-free rule function preserve rearm,
  eligibility, saved pace/divisor and cooldown, including pace-one behavior.
  Evaluated: 576 recovered control-block state combinations, 69 exact 2026
  boundaries with naturally armed slowdown and ten frozen 2010 boundaries.
  Independent big-review finds no introduced defect; late warning latch and
  pixel-controlled traversal remain open. See `versions/2026/analysis/app/ENG-03b-4.md`.

- [x] **ENG-03b.5 — Extract wave/heave state and sound selection.**

  Typed renderer-free environment phase preserves proximity/cooldown, raw F64
  copying, amplitude/phase and ordered cues. Heave affects downwind dynamics.
  Evaluated: 672 original/new cases, 69 exact 2026 boundaries, ten frozen 2010
  boundaries with old lifecycle guarded, eighteen tests and 14 controls/depth
  checks. See `versions/2026/analysis/app/ENG-03b-5.md`.
  Wave-position regeneration/world traversal and shared-RNG policy remain open.

- [x] **ENG-03c — Remove raster and shared drawing-randomness dependencies.**

  The user selected independent deterministic streams on2026-10-07. Production
  advances without world rasterization or pixel reads. Typed physical phases
  retain recovered formulas; wave density remains398 points, with explicit
  camera-independent refresh. No constant pixel or guessed RNG burn is used.
  Historical exact extraction traces remain preserved. See the
  [v1 contract](versions/2026/docs/independent-state-contract.md).

- [x] **ENG-04.2 — Own renderer-free runtime and independent random streams.**

  Evaluated20786-step Node races with four AI finishes and a natural20-minute
  DNF cutoff. Identical authoritative image and gameplay RNG despite extra
  cosmetic draws; full checkpoint continuation, held panels and next-race score
  retention passed. Frozen navigation selector matched400 full-image fixtures.
  Physical wave density remains398 points. Browser cutover follows separately.
  See [v1 contract](versions/2026/docs/independent-state-contract.md).

- [x] **ENG-04.3 — Close independent runtime review findings.**

  Complete checkpoints include virtual CString contents and their leg-replay
  boundary. Public N/Space restarts explicitly; coach tack gates match360
  recovered-block fixtures.25 focused tests pass, including592 full-image
  navigation fixtures and discarded-future replay. Strong-wind Tornado races
  finish without graphics. See [review closure](versions/2026/analysis/app/ENG-04-2.md).

- [ ] **ENG-04 — Implement the compatible simulation driver** · P0 · L · Depends: ENG-03, BASE-05.

  Done when: scenario initialization, tick/phase execution, actual finish events
  and disposal use original engine behavior through one adapter, with no new boat
  dynamics, injected expected state or hidden demo restriction.

- [x] **ENG-04.1 — Own numerical/world/timing/cleanup step ordering.**

  Renderer-free typed driver preserves native pace delays, unsigned clock wrap,
  bounded waiting and cleanup after successful phases. The compatibility adapter
  supplies world composition temporarily. Evaluated: 28 original-driver cases,
  failure/bound checks, 65 exact 2026 boundaries and ten frozen 2010 boundaries.
  See `versions/2026/analysis/app/ENG-04-1.md`; the parent driver cutover remains open.

- [ ] **ENG-05 — Preserve canonical host and pixel-read semantics** · P0 · L · Depends: ENG-02, ENG-03.

  Done when: required GDI/pixel behavior, legacy surface/camera, retained locals
  and host callbacks match the declared reference; each removed drawing operation
  has evidence that it cannot affect authoritative output.

- [x] **ENG-05.1 — Own canonical host calibration and bypass original lifecycle entries.**

  Typed surface-free calibration retains caps/scales and exact spills. Worker
  directly dispatches new transitions/step driver. Compatibility raster remains
  for unclassified pixel/world semantics. Evaluated: eighteen host profiles,
  69 exact 2026 boundaries and ten frozen 2010 boundaries with original lifecycle,
  content dispatcher and frame driver guarded to throw for candidates. See
  `versions/2026/analysis/app/ENG-05-1.md`. This is not full offscreen removal.

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

- [x] **ENG-13.1 — Switch production to the independent runtime.**

  Removed old offscreen surfaces/lifecycle/composition/bitmap panels.131 guarded
  boat/venue/course cases pass; private observations retain full future state
  across6000 paired Chrome steps and replay. Natural island results/championship,
  rig/penalty/luffing fixtures, information, controls and context recovery pass.
  Five prestart plus five active-racing Chrome/WebGL2 budget repeats pass. Private presentation adapters
  remain documented and isolated. See [cutover evidence](versions/2026/analysis/app/ENG-13-1.md).

- [ ] **ENG-14 — Prove simulation and presentation independence** · P0 · L · Depends: ENG-12, ENG-13.

  Done when: the same commands produce exact authoritative traces at varied
  presentation schedules and with different camera/quality/observer configurations;
  simulation progress is measured independently of render callback counts.

## APP: modern application foundation

- [x] **APP-01 — Create an isolated modern development scaffold** · P0 · M · Depends: BASE-01, BASE-07.

  Done when: `versions/2026` has a minimal TypeScript/Vite setup, pinned dependencies,
  a development page and a bounded spike route; the original no-install player
  paths and existing build commands remain usable.

- [ ] **APP-02 — Implement race and replay lifecycle ownership** · P0 · L · Depends: APP-01, ENG-07, ENG-09.

  Done when: loading/setup/prestart/racing/pause/finish/replay/error transitions
  own inputs, worker, recording and run IDs; only actual engine events open live
  results and restarts dispose the old run cleanly.

- [ ] **APP-03 — Build setup, forecast and supported-preset selection** · P1 · M · Depends: APP-02, BASE-06.
  - [x] **APP-03a — Build the modern starter screen** (2026-10-05): held
    native preview, 5/15 Keelboats on Round Lake, three original course choices
    and three original wind strengths. Start releases the countdown; New race
    and N reopen setup. All 18 configurations match original whole-image,
    clock/RNG/shore boundaries at initialization and after eight paints.
    [Evaluation](versions/2026/analysis/app/STARTER.md). Current/forecast controls,
    replay and complete settings remain open.

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

- [x] **GFX-01 — Compare and pin the renderer backend** · P0 · M · Depends: APP-01, BASE-07.

  Done when: a bounded Three.js WebGL 2/WebGPU spike checks startup, materials,
  worker coexistence, target devices and timings; the proposed WebGL 2 MVP choice
  or an evidence-backed alternative is recorded with an exact dependency version.

  Completed 2026-10-05; [evaluation](versions/2026/analysis/app/GFX-01.md).
  Three.js 0.186.1 / WebGL 2 selected after five headed Chrome repetitions;
  the requested WebGPU route uses an explicitly reported WebGL fallback here.
  Faithful native-derived 3D boats replace the rejected generic boat, with free
  orbit, curved sails, moving boom, original crew and black penalty main.
  Whole native state checks and graphics recovery pass. This accepts the bounded
  renderer spike; polished/exported assets, verified world scale, production
  transport, full-session QA and physical Pixel 11 testing remain open.

- [ ] **GFX-02 — Establish model, material and export conventions** · P1 · M · Depends: BASE-08, ENG-08, GFX-01.

  Done when: scale/axes/origin, sail pivots, flat shading, GLB export, editable
  source locations, LOD/material budgets and naming/provenance are documented
  and tested on one reference model.

- [ ] **GFX-03 — Create the polished low-poly keelboat** · P1 · L · Depends: GFX-02.
  - [x] **GFX-03a — Remove deck/cockpit overlap** (2026-10-05): native cockpit
    footprint cut from the deck, recessed floor/coaming and safe triangulation
    changes during interpolation; [evaluated](versions/2026/analysis/app/COCKPIT.md).
  - [x] **GFX-03b — Refine the native crew into solid low-poly figures**
    (2026-10-05): native hiking/heel/foot anchors, source shirt colors and the
    helmsman's tiller retained; solid coverage on both tacks, close views,
    simulation isolation and ten repeated 15-boat Chrome runs
    [evaluated](versions/2026/analysis/app/CREW.md).

  Done when: hull/deck/mast/boom/sails/simple crew have a readable silhouette,
  original 2010 proportions, sail contours and usable articulation, fit the asset budget, and ship
  with editable source, provenance and verified exports.

  User direction 2026-10-05: retain recognizable original boat geometry and
  people aboard. Refine the native-derived spike rather than substituting a
  generic hull or triangular sail. See [model foundation](versions/2026/docs/native-boat-models.md).

- [ ] **GFX-04 — Implement fleet LOD and shared geometry/materials** · P1 · M · Depends: GFX-03.

  Done when: 5/15-boat fleets instantiate stable boat IDs efficiently, with distant
  geometry and color/selection distinctions; instancing/bounding volumes work
  correctly and boats are not incorrectly culled after movement.

- [ ] **GFX-05 — Render authoritative poses and course geometry** · P0 · M · Depends: GFX-02, ENG-09.

  Done when: boat positions/headings, start line and marks align with verified
  engine coordinates; visual picking and the course map use the same transform,
  and renderer code cannot mutate simulation state.

- [ ] **GFX-06 — Animate sails, boom, heel and simple crew** · P1 · L · Depends: GFX-03, GFX-05.
  - [x] **GFX-06a — Make the unloaded headwind rig visibly respond**
    (2026-10-05): local native wind/luff telemetry drives deterministic visual
    flutter and boom response; loaded native shapes, hull/crew and mast anchors
    preserved; [evaluated](versions/2026/analysis/app/SAIL-WIND.md).

  Done when: verified tack/trim/luff/heel data visibly drives the rig with bounded
  geometry updates, including the original boom response and black penalty sail;
  original crew remains visible from suitable free-camera angles;
  illustrative animation is distinguished from authoritative
  values and uses no simulation RNG or physical feedback.

- [ ] **GFX-07 — Build the low-poly Round Lake environment** · P1 · L · Depends: GFX-02, BASE-06, ENG-08.
  - [x] **GFX-07a — Display native course objects** (2026-10-05): marks,
    committee boat, pin, retained start/current finish lines and L heading
    guides, with course-framed Overview. Coordinates and engine isolation,
    restart/recovery and four headed performance runs pass.
    [Evaluation](versions/2026/analysis/app/COURSE.md). Shoreline/scale remain open.

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
  - [x] **UI-03b — Show common keys beside the scene** (2026-10-05): collapsible
    right-hand guide with native-action buttons; build, placement, read-only
    display and trusted spinnaker/sheet/freeze/help clicks
    [evaluated](versions/2026/analysis/app/keys-guide1/verification.json).

  - [x] **UI-03a — Restore native hotkeys in the isolated app** (user-requested
    compatibility step). Original virtual-key routing, native context-sensitive
    actions, 3D view adaptation and legacy information panels are implemented;
    [evaluation](versions/2026/analysis/app/HOTKEYS.md). Production command
    recording/replay and the parent prerequisites remain open.

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
| BASE-05 | 2026-10-05 | Atomic `BASE-05` commit; see file history | [Evaluation](versions/2026/analysis/baseline/BASE-05.md) | Short host timing runs; modern repeated graphics acceptance remains open |
| BASE-06 | 2026-10-05 | Atomic `BASE-06` commit; see file history | [Evaluation](versions/2026/analysis/baseline/BASE-06.md) | Initial presets, not replay checkpoints or control-independent weather |
| APP-01 | 2026-10-05 | Atomic `APP-01` commit; see file history | [Evaluation](versions/2026/analysis/app/APP-01.md) | Scaffold; live worker and renderer are next bounded spikes |
| ENG-02 | 2026-10-05 | Atomic `ENG-02` commit; see file history | [Evaluation](versions/2026/analysis/app/ENG-02.md) | Full original Canvas retained; finite paired traces, production transport later |
| GFX-01 | 2026-10-05 | Atomic `GFX-01` commit; see file history | [Evaluation](versions/2026/analysis/app/GFX-01.md) | Faithful native-derived 3D spike; native WebGPU unmeasured; production assets/world scale and Pixel 11 later |
| UI-03a | 2026-10-05 | `d5fc4af` | [Keyboard evaluation](versions/2026/analysis/app/HOTKEYS.md) | Native compatibility panels; modern overlays and production replay still open |
| GFX-03a | 2026-10-05 | `46f40bf` | [Cockpit evaluation](versions/2026/analysis/app/COCKPIT.md) | Reviewed Keelboat surfaces; scale/export work still open |
| GFX-03b | 2026-10-05 | Atomic crew refinement commit; see file history | [Crew evaluation](versions/2026/analysis/app/CREW.md) | Desktop Chrome and current Keelboat; other boats, Pixel 11 and production assets later |
| UI-03b | 2026-10-05 | `9971ecd` | [Common keys](versions/2026/analysis/app/keys-guide1/verification.json) | Desktop guide; complete modern UI remains open |
| GFX-06a | 2026-10-05 | `b378c4f` | [Sail response](versions/2026/analysis/app/SAIL-WIND.md) | Deterministic visual headwind animation, not physical cloth |
| GFX-07a | 2026-10-05 | Atomic native course commit; see file history | [Course evaluation](versions/2026/analysis/app/COURSE.md) | Directional laylines; shoreline/scale and polished assets later |
| APP-03a | 2026-10-05 | Atomic starter commit; see file history | [Starter evaluation](versions/2026/analysis/app/STARTER.md) | Supported native choices; fixed-seed fresh races; complete lifecycle/settings later |
| — | — | — | — | — |

## Requested original-feature expansion (2026-10-05)

Implement each task atomically and evaluate it before checking it off. Preserve
native physics, RNG, weather, scoring and shoreline/depth calculations; modern
extensions must be identified and must not silently replace original behavior.

- [x] **EXT-01 — Restore mark guides and automatic following camera.** Expose
  original mark-line toggle separately from L; show buoy laylines/equal-position
  guides and follow interpolated headings through tacks/jibes. Evaluate geometry,
  trusted toggles, wrapped-heading motion and read-only camera isolation.
- [x] **EXT-02 — Name the fleet and allow editing the player's boat name.**
  Recover native fleet names; safely support a custom display name and retain
  identities across results and championship races.
- [x] **EXT-03 — Build proper race start, finish and results screens.** Show
  native finishing position immediately on finish, complete fleet results when
  available, penalties and clear next-race/new-event actions; prove results are
  triggered by engine events, not elapsed-time or visual-position guesses.
- [x] **EXT-04 — Add standard race / championship selection and event flow.**
  Preserve original three-race series transitions/scoring, with modern longer
  events if needed. Show race number, individual finishes, standings, final
  championship results and a way to continue without accidentally reseeding or
  discarding the ongoing event. Evaluate complete natural event transitions.
- [x] **EXT-05 — Port every native boat class and course option.** Use native
  menu/controller and geometry rather than substituting generic assets. Cover
  all rig/hull/crew families, spinnaker differences, gate/fleet restrictions,
  native area/course compatibility and proper setup labels. Evaluate native
  boundaries and visual fidelity for every supported choice.
- [x] **EXT-06 — Expose native wind/gusts, waves, depth, current and grounding.**
  Render native shoreline/navigation geometry, readable local gust/current/depth
  instruments and grounded status, with restrained wave/gust visuals. Port
  environmental physics already present; any illustrative additions remain
  presentation-only. Evaluate shallow-water and current cases against the OG.
- [x] **EXT-07 — Review and evaluate the complete expanded player journey.**
  Fix findings; check starter/race/finish/championship/restart/error ownership,
  selected boats/courses, no demo mode, frozen-reference integrity and repeated
  Chrome smoothness. Keep incomplete items explicit instead of declaring the
  whole expansion complete early.

Expansion evidence: [catalog](versions/2026/analysis/app/CATALOG.md),
[environment](versions/2026/analysis/app/ENVIRONMENT.md), and
[review / journey / performance](versions/2026/analysis/app/EXPANSION-REVIEW.md).
EXT-05 commit `73806fa`; EXT-06 commit `8fe664b`; EXT-07 see file history.
The requested expansion is complete within these recorded checks; the broader
MVP, physical Pixel 11 and replay/export tasks above retain their existing status.

## Guide and indicator refinement (2026-10-05)

- [x] **VIS-01 — Restore native guide decisions and heading reference.** Validate
  anchors/bearings and suppression against the full original chart; preserve
  simulation state, gate/finish cases and free-camera ownership.
- [x] **VIS-02 — Replace buoy and fleet sprites with one compact label system.**
  Bound screen size, anchor outside boats/sails, avoid label/HUD collisions,
  prioritise the active target and nearby/selected boats, and support show-all.
- [x] **VIS-03 — Refine guide contrast and navigation indicators; evaluate Chrome.**
  Check crowded fleets, close/follow/overview cameras, native conditions,
  lifecycle/restart and repeated smoothness. Record limits and fix findings.
- [x] **VIS-04 — Repair Optimist sail panels lost at some rig angles.** Use
  native cloth coordinates for the main fill; evaluate luffing, trim, both
  sides, native colours, shared boat classes and preserved simulation state.
  Evidence: [sail surface repair](versions/2026/analysis/app/OPTIMIST-SAIL.md).

Evidence: [guide and label refinement](versions/2026/analysis/app/GUIDE-LABEL-REFINEMENT.md).

## Player fixes (2026-10-06)

- [x] **FIX-01 — Make Pause/Space work after toolbar interactions and native freeze.**
- [x] **FIX-02 — Show boat-specific shallow-water warnings before grounding.**
- [x] **FIX-03 — Close races 20 game minutes after the first finisher; score DNFs.**
- [x] **FIX-04 — Repair island mark placement and prevent AI shore traps.**
- [x] **FIX-05 — Add coastal elevations, shore detail and navigational landmarks.**

Evidence: [player fixes](versions/2026/analysis/app/PLAYER-FIXES.md).

## Minimap and race setup (2026-10-06)

- [x] **UI-01 — Add a toggleable north-up course minimap in sailing cameras.**
  Hide in full Overview; preserve preference and native simulation state.
- [x] **UI-02 — Center the starter, preview the selected native boat and provide a large Start race action.**
  Preserve setup/championship flow; evaluate layout, controls and performance.

Evidence: [minimap and starter](versions/2026/analysis/app/MINIMAP-STARTER.md).

- [x] **UI-03 — Stage setup changes until Start and restore OG-style course-choice charts.**
  Remove Reload fleet; cache native boat/venue samples; preserve held simulation
  state, apply the final settings once, and retain championship continuation.
  Evidence: [deferred setup](versions/2026/analysis/app/STAGED-SETUP.md).

- [x] **UI-04 — Enable Island course layouts and compass wind selection.**
  Apply on Start; retain native weather variation and Auto reference behavior.
- [x] **UI-05 — Keep course-preview marks, lines, routes and labels off land.**
  Evaluate every supported course/venue/direction/short/gate combination, fix
  routing gaps, check actual Chrome text bounds, and avoid slow selection handlers.
  Evidence: [island, wind and preview refinement](versions/2026/analysis/app/ISLAND-WIND-PREVIEWS.md).

- [x] **FIX-06 — Recover the original zero-width shoreline conversion without stopping the renderer.**
  Verify masked x87 behavior, reproduce the crash, compare neighboring drawing
  cases and check Chrome races/default reference states.
  Evidence: [shoreline division repair](versions/2026/analysis/app/SHORE-DIVISION.md).

- [x] **FIX-07 — Unify pause controls and reject paused helm/sail inputs.**
  Retain displayed values; prevent deferred control changes on resume.
  Evidence: [pause and information tools](versions/2026/analysis/app/PAUSE-INFORMATION.md).
- [x] **UI-06 — Expose native wind/forecast/current charts and coach comments in the modern interface.**
  Extract from private copies; preserve the sailing state while inspecting them.

## Hull contacts and game polish

- [x] **CONTACT-01 — Derive rigid contact shapes for all 27 boats and share course-object dimensions with graphics.**
  Compound catamaran hulls/platform; exclude sails, crew and labels. Add a contact
  overlay and verify real model alignment before enabling physical changes.
  Evaluated: all 27 live initial hull packets fit; held image/RNG/shore unchanged.
  Catamaran heel shifts required a measured 0.35-unit rounded reserve. See
  `versions/2026/analysis/app/contact-shapes-reviewed-2026-10-06/verification.json`.
- [x] **CONTACT-02 — Add continuous polygon/circle detection and stable physical response.**
  Evaluate bow/side/stern, rotations, grazing, thin-object sweeps, compound gaps,
  resting/sliding contacts and initial penetration. No rendering dependency.
  Evaluated: 143 solver cases, including all 27 hulls in five orientations and
  dense fifteen-boat placement. Conservative translation/rotation sweeps, no
  bounce, tangential sliding and separate non-foul spawn correction.
- [x] **CONTACT-03 — Integrate contacts and original foul decisions in the authoritative worker.**
  Preserve frozen sources via declared adapters. Separate solid contact from foul
  eligibility; retain original penalty relocation, reset, RNG and grace timing.
  Keep all marks/gates/committee solid; use OG temporal foul gates. Prevent
  teleports/replays from generating false sweeps; validate controls, scoring and
  diagnostic isolation.
  Evaluated: 12 real native-rule/world fixtures, 14 control checks, nine information
  checks and 600 real fifteen-boat paints. Initial reference image unchanged;
  rendering does not feed physics. Private rule copies yield one-sided port/
  starboard, windward and clear-astern decisions. A contact HUD explains sanctions.
  Dense-neighbor cost was found and remains a CONTACT-04 performance target.
- [x] **CONTACT-04 — Match AI clearance, evaluate complete races and performance, then review and fix findings.**
  Check crowded starts, rounding/gates/island, all shape families, race results,
  championship reset, pause and the overlay. Keep Chrome desktop cadence smooth.
  Evaluated: three complete native races (Keelboat, Tornado, Island Optimist), all
  four NPCs finish in each; DNF windows/results and natural championship restart
  pass. Five exclusive headed Chrome runs pass every desktop renderer budget:
  median 16.7 ms, P95 16.8 ms, P99 at most 20.9 ms, camera P95 under 24 ms.
  Lifecycle/context recovery passes. Frozen reference: all 6,471 files unchanged.
  Big-review findings fixed: exhausted grazing/rotation sweeps, within-skin
  leaving/re-entry, unresolved dense placement and contact-time tack attribution.
  Final fixtures: 152 solver cases and 13 real native-rule/world cases. Independent
  follow-up probes find no missed penetration in 4,371 random hull sweeps and
  1,248 near-skin rotations. Evidence under `versions/2026/analysis/app/contact-*`.

- [x] **CONTACT-05 — Restore the OG penalty response and grace after the hull upgrade.**
  Reuse original reset/respawn/shift and original RNG draws, preserve human/NPC
  status policy and the opponent-timestamp 50-second gate. Keep geometry solid
  while restoring original mark phase/leg/angle eligibility; no invented gate
  mark-touch rule. Cache/show actual relocation without a false sweep or animated
  teleport through the fleet.
  Evaluated: 81 native full-image/RNG and world fixtures, 152 solver checks,
  14 controls/depth checks, nine information groups and complete Keelboat,
  Tornado and Island Optimist races with all four AI finishes, DNF/results and
  championship restart. See `versions/2026/analysis/app/CONTACT-05.md`.

## Original functionality parity audit

- [x] **Optimist sail detail review — 2026-10-07.** Attach battens to actual
  cloth faces through interpolation/luffing, verify both sides, place course
  guides at water level with hull occlusion, and analyze native pace/clock rates.
  Evaluated all27 sail classes and independent ray/framebuffer controls. See
  `versions/2026/docs/optimist-sail-details.md`.
- [x] **Real-time playback — 2026-10-07.** Implement the accepted recommendation:
  default1×, explicit fast-forward multipliers, Space precision toggle,
  paused wall-time cosmetic flutter, preserved numerical kernels and reviewed
  hold/replay/new-race/assistance routes. See
  `versions/2026/docs/real-time-playback.md` for bounded rate/trajectory evidence.

- [x] **Consolidated speed controls — 2026-10-07.** Setup and sailing use the same
  eight multipliers through32×, Space toggles1×/selected pace, saved OG mode migrates
  to1×, and the OG speedometer uses deterministic progressive needles. Display
  snapshots are capped at60Hz (30Hz at16×+) while every numerical step still runs. Evaluated
  pause/panels/replay/persistence, gauge options and actual rates in Chrome;
  high-rate throughput remains limited by numerical processing cost. See
  `versions/2026/docs/real-time-playback.md`.

- [x] **Boat geometry after fast-forward — 2026-10-07.** Isolate the OG
  drawing speed/detail and divisor from the authoritative simulation preset.
  Compare identical physical states across all eight rates and Space, inspect
  both hull sides, recheck rig/crew fixtures and confirm30-boat32× throughput.
  See `versions/2026/docs/boat-model-pace-regression.md`.

- [x] **32× with30 boats — 2026-10-07.** Map multipliers to recovered OG
  variable timesteps; retain fine preset6 at1× and the selected fast preset
  through Space, replay and new races. Assert all eight multipliers within5%
  in rendered Chrome, evaluate a full30-boat race through results and next race,
  and recheck maneuvers, swept contacts and focus controls. See
  `versions/2026/docs/real-time-playback.md` for the policy and receipts.

- [x] **Global gameplay shortcuts and responsive pacing — 2026-10-07.** Retain
  the chosen pace while Space toggles1×; take game shortcuts from buttons,
  selects and checkboxes; dismiss open pickers without changing selection;
  prevent Space/Enter browser activation. Preserve text editing and paused boat
  guards. Avoid nested timer clamping, reuse private camera storage, reduce
  high-rate display transport and report achieved pace separately from the
  selection and automatic foul slowdown. Evaluated real Chrome controls and
  exact held boundaries; see `versions/2026/docs/real-time-playback.md`.

- [x] **PARITY-00 — Audit original features and explain the current architecture.**
  Inventory all 312 original menu commands, trace UI/worker/renderer routing,
  inspect missing host services and probe coach flags, native key behavior and
  leg replay on a disposable client. Distinguish reachable features, backend-only
  functions, modern replacements and explicit gameplay additions. See
  `versions/2026/docs/og-functionality-audit.md`; this is an audit, not full parity.
- [ ] **PARITY-01 — Restore complete dynamic coach advice and sailing-state HUD.**
  Refresh warning flags on private copies as the OG coach lifecycle does; compare
  advice under heel/luff/bad-air/penalty cases without changing live state/RNG.
  Show appropriate luff, trim, shape, rig, clear-air and header/lift information.
  2026-10-07: exact heel and actual sheltered-wind warnings now survive
  integration; coaching is reachable after results. Remaining advice/HUD cases
  keep this task open. See `versions/2026/docs/rules-controls-review-2026-10-07.md`.
- [ ] **PARITY-02 — Validate leg replay against modern host bookkeeping.**
  Rewind during prestart, a leg, after a finish and during a championship; reconcile
  finish window, DNF ledger, contacts and event scoring. Retain the separate
  existing production replay/timeline tasks.
  2026-10-07: public paused/post-result replay, natural cutoff/DNF rollback and
  active championship receipt replacement now pass. Earlier receipts remain;
  fuller leg/championship coverage and timeline work keep this task open.
- [ ] **PARITY-03 — Restore audio cues.**
  Replace sound/beep stubs with worker-to-main audio events, original cue identity,
  mute and browser activation handling. Evaluate countdown, start, recall/foul
  and paused/restarted sessions; audio must not change simulation pacing.
- [ ] **PARITY-04 — Complete tactical track and chart interactions.**
  Transport bounded track samples and render OG-equivalent paths on the modern
  map; distinguish bad-air/downwind/lap styling. Restore chart point sampling and
  evaluate large-view zoom/orientation and independent minimap behavior.
- [ ] **PARITY-05 — Expose original race options and retain preferences.**
  Add difficulty, prestart/start placement, current enable, hemisphere, rounding
  direction and assistance controls through original handlers. Add night visuals
  if night race is exposed. Evaluate combinations before marking each supported;
  persist validated setup rather than silently resetting all preferences.
  2026-10-07: a single1/2/4/8/16/24/28/32× speed list replaces the original
  pace-level menu. Space toggles1×/selected pace; F pauses; Page keys synchronize preference.
  These pace settings do not complete the separate AI/race-option backlog.
- [ ] **PARITY-06 — Port original learning/help navigation.**
  Make rules/tactics chapters, glossary, bibliography and relevant explanations
  reachable in modern panels; check text/layout, pause policy and private state.
- [ ] **PARITY-07 — Scope and port original advanced interactive modes.**
  Provide modern design/rig and personal-venue controls with validation/previews;
  evaluate original steering-zone/wheel interaction and two-player input/display
  separately. Existing translated handlers and throwing dialog stubs are not a
  completed feature.

Production no longer uses the original offscreen paint lifecycle. The approved
v1 runtime owns progression, world updates and replay. Read-only presentation
compatibility adapters remain a separately tracked cleanup.
- [x] **PARITY-08 — Repeat controlled headed Chrome smoothness acceptance.**
  Five prestart and five active-racing Chrome/WebGL2 repeats now pass: median
  cadence16.7ms, P95≤16.8ms, P99≤29.2ms and camera P95≤22.2ms. Owned windows
  remain visible, sized and focused; no other application window is modified.
  Reports: independent-chrome-performance-settled-2026-10-07 and
  independent-chrome-racing-2026-10-07. Prior penalty-restoration outlier/interrupted
  attempts remain preserved in contact-og-renderer-attempts.json; they were not
  discarded or counted as successful repeats. Physical Pixel testing stays deferred.

- [x] **CONTROL-01 — Restore Space speed reset and working tack/jibe controls.**
  Space sets speed1 without pausing; F owns pause. Disabled legacy screen hit
  handling that cancelled maneuvers, retained original turning math and routed
  keyboard controls to the displayed boat.29 focused tests and trusted Chrome
  tack/jibe/control evaluations pass. See
  [control regression report](versions/2026/analysis/app/maneuver-controls-2026-10-07.md).

- [x] **Dense-fleet computation optimization — 2026-10-07.** Profile actual
  worker phases; accelerate exact original radius screening; reuse immutable
  predictive hull geometry/projections/axes and iteration scratch; prune only
  conservative no-contact translations. Preserve all opponents, collision
  resolution, penalty responses and fixed-step image/RNG. Golden geometry,
  numerical/solver/rules, full-race and Chrome controls pass. See
  `versions/2026/docs/fleet-performance.md`.
