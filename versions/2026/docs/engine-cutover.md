# Remove the original offscreen lifecycle

2026-10-06. Target: the production simulation advances without the original
paint lifecycle, Canvas/GDI surfaces, bitmap fonts, original drawing callbacks
or pixels. The preserved 2010 player remains a separate evaluation reference.
The recovered numerical JavaScript is reusable; wholesale replacement of AI,
wind, current and sailing mathematics is unnecessary.

## Current state —2026-10-07

Production uses the renderer-free2026 EngineRuntime. It initializes, advances,
freezes, scores, resets and restores races without the old paint lifecycle,
world compositor, Canvas/GDI raster surfaces, bitmap fonts or pixel reads.
The user explicitly selected independent gameplay/wave/cosmetic random streams;
old seed-specific trajectories are not the new equality contract.

Private presentation still reuses recovered boat, guide and information
routines on copied state. It uses trace events to produce meshes/vectors and
cannot advance the authoritative engine. Pure boat-definition/chart rewrites
remain presentation cleanup, rather than a dependency of simulation progression.
The2026 transport's existing compatibility boundary still contains broad legacy
types; new authoritative modules use strict TypeScript ports.

See [independent contractv1](independent-state-contract.md),
[core review closure](../analysis/app/ENG-04-2.md) and
[browser cutover](../analysis/app/ENG-13-1.md).

## Historical foundation and discovered dependencies

`app/engine.worker.ts:paint()` formerly constructed Canvas DCs and called the
original lifecycle. That lifecycle initializes races, dispatches screens,
advances simulation, composes drawings, runs timing gates and performs cleanup.
`advanceFrame()` already exposes much of the numerical update in its original
order, but it is not a complete independent tick.

The accepted BASE-04 trace observed scene drawing changing 857 words and making
32,194 random calls across 14 calls. Those are bounded trace totals, not fixed
per-tick counts. Camera routines write retained state; routine 0x465ff0 changes
waypoints consumed by later simulation. Scene/chart drawing shares the gameplay
RNG. Some branches read rasterized pixels. BASE-05 also established that drawing
can trigger/rearm foul slowdown. Removing drawing without relocating these
semantics changes behavior, even if an initial sailing screenshot looks right.

Two further dependencies are separate from the main lifecycle: private graphics
workers invoke original boat drawing to construct meshes, and private information
and guide capture invokes original drawing callbacks. A complete production
cutover must address those too.

Sources: [drawing audit](../analysis/baseline/BASE-04.md),
[timing audit](../analysis/baseline/BASE-05.md),
[feature audit](og-functionality-audit.md),
[worker](../app/engine.worker.ts), [guides](../app/native-guides.ts),
[information](../app/native-information.ts), [models](../app/native-models.ts).

## Sequence and evaluation gates

| Step | Deliverable | Required evaluation |
| --- | --- | --- |
| 1. Define state and comparison ownership | Classify authoritative state, RNG, commands, timing, retained context, visual scratch and existing 2026 policies. Freeze current working behavior as the immediate cutover reference. | A repeatable paired runner with identical seed, settings and ordered commands; compare old/new phase traces, report first differing field/call. |
| 2. Expand dependency tracing | Record writes, intermediate/restored writes, reads, RNG calls and pixel queries by original routine. Cover startup, actual racing, finish, reset/replay, chart/coach and alternate options. | Instrumented and plain reference executions agree. Every removed dependency has a reader/use argument, including computed addresses and retained state. A zero net memory delta alone is insufficient. |
| 3. Extract semantic drawing work | Move required waypoint/course updates, camera-derived compatibility state, slowdown, warning preparation, result/score transitions and cleanup into explicit engine phases. | Replace one callback at a time; compare relevant state, exact RNG state/draw order and future outputs over continued sailing. Unknown branches retain the old path in the development reference until classified. |
| 4. Remove pixel and drawing-randomness dependencies | Replace required visibility/geometry decisions with deterministic calculations. Apply the user-approvedv1 random-stream contract; retain the recovered distributions and numerical formulas. | Pixel-dependent branches have focused fixtures and continued full-state/RNG comparisons. Never return a constant pixel or consume a guessed fixed random count. RNG separation is explicit in the approvedv1 contract. If a query cannot be reproduced without rasterization, report the blocker; do not declare this step complete. |
| 5. Introduce the independent engine driver | Explicit initialize, apply commands, step, pause, finish, reset, checkpoint/restore and dispose APIs. Retain native arithmetic and variable timestep; keep contacts, navigation and finish-window policies in their declared phases. | Paired races, steering/trim/maneuvers, penalties and grace, rounding/gates, grounding, finish/DNF, championship reset and replay. No double advance, skipped tick or timestep inflation. |
| 6. Publish presentation data directly | Snapshots/events carry rig/sail/crew pose, colors, air/depth status, course objects/guides, warnings, chart fields, history, score and sound cues. Build geometry from reusable boat definitions and animation inputs; replace old bitmap information panels. | All 27 boat families and rig states checked against preserved samples; all production observation is read-only and leaves state/RNG unchanged. Opening charts, coach or changing cameras cannot change sailing outcomes. |
| 7. Switch production to the new worker | Remove lifecycle/DC allocation/blits, legacy surface/camera calibration dependencies, bitmap font hosting and runtime drawing-module imports. Keep the old engine accessible only to evaluation tools. | Run the engine with no DOM, Canvas, GDI or WebGL. Guards fail if forbidden drawing/pixel/lifecycle operations are attempted. Same ordered commands yield identical authoritative traces with rendering disabled and at 30/60/120/240 Hz. |
| 8. Certify supported behavior and performance | Complete a coverage matrix for original options and existing 2026 additions, then close outstanding feature gaps. | Complete races across boat/venue/course families, dense starts, long sessions, restart/replay and pause. Recheck simulation throughput separately from five-repeat Chrome presentation acceptance. Feature audit PARITY tasks remain real work. |

Steps map to ENG-01, ENG-03 through ENG-14 and the existing PARITY tasks. They
are ordered milestones; none is marked complete by this document.

## Reference strategy

Use two comparison lanes:

1. **Frozen 2010 lane:** validates recovered numerical/control semantics and
   original options without assuming that 2026 hull contacts or finish policies
   are byte-identical to the original proximity detector.
2. **Current 2026 lane:** validates the cutover with the same collision, navigation,
   selected-wind, championship and DNF policies enabled on both sides. This is
   the immediate regression gate for keeping the game that currently works.

Start with complete image/RNG/context comparisons while extracting semantics.
When old rendering-only fields are deliberately removed, introduce a versioned
state contract with individually justified exclusions and future-output checks.
Do not discard entire memory ranges simply because their writes occur in render
files. Keep exact authoritative arithmetic; visual fidelity has its separate
comparison and the user's existing allowance for tiny drawing differences.

The initial paired runner can use captured deterministic command sequences and
complete native stepping, avoiding the unreliable headed benchmark window for
correctness work. Headed Chrome remains required for presentation performance.

## Shape of the resulting architecture

The authoritative worker owns original numerical routines, explicit semantic
phases, input order, RNG, clock, penalties, race/series state and replay state.
It advances without a presentation host and emits immutable snapshots/events.
The main thread owns Three.js, UI, audio and interpolation. A graphics worker
may build meshes from pure boat definitions, but does not call original drawing
functions or advance gameplay. Preservation assets and original player remain
available to test and compare outside the production runtime.

Keep the address-space representation and Float80 helpers during extraction;
converting every field to idiomatic objects or replacing arithmetic is separate
work. Mixing those rewrites with lifecycle removal makes discrepancies harder
to locate. Once independence is demonstrated, state cleanup can proceed against
the same fixtures.

The first implementation task is the paired runner and per-phase dependency
ledger. Do that before deleting or bypassing the existing lifecycle.
