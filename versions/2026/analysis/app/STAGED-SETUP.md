# Deferred setup and original course-choice previews

Changing course, venue, boat, wind, fleet or event settings now edits a menu draft.
It updates the previews immediately without replacing the race worker, clearing
models, reseeding the race, or changing its paused native memory/RNG/shore state.
Start validates the final selection and initializes it once, then resumes only
when that generation's engine and models are ready. New race opens held setup;
championship continuation resumes the existing native series and preserves scores.
Reload fleet has been removed. Preview-only graphics recovery uses a selection
change; the Start action can retry a failed race/graphics initialization.

The course-choice charts follow the OG's windward/leeward, triangle, repeated-lap,
Gold Cup and downwind-finish families. Source: native `menu-controller.js` course
commands 32816–32820 / 32992–32993, `course.js` mark construction, and
`race-targets.js` lap/Gold Cup/finish transitions. Arrows describe rounding order,
not predicted sailing tracks. Gates show two marks, and short courses are indicated.
Start/finish labels are separated from buoy labels. Island diagram routes avoid
native land using the existing shoreline visibility graph; this is an illustrative
route, without depth or tactical prediction.

`tools/generate-starter-samples.mjs` captures actual paused native configurations
through isolated EngineClients. The shipped atlas contains all 27 native boat
packets, 7 course families, and 89 venue/family profiles covering all 33 venues.
Its 40 distinct native shorelines are shared. W/L, triangle and downwind profiles
supply native coordinates; repeated laps/Gold Cup describe the corresponding OG
rounding order. Boat previews use their actual native packet and the shared
NativeBoatMesh implementation. Browsing needs no new workers or runtime generation.

These are explicitly labeled course samples, not to scale. They represent the
moderate-wind sample layout, not a promise of exact seeded race coordinates,
future moving finish lines, or a playable/physically optimized route. Wind strength
and fleet/boat-dependent course size are applied by the native engine at Start.
No authoritative engine, rendering adapters, AI or physics module changed.

Chrome evidence:

- `staged-setup-reviewed-2026-10-06`: all seven diagrams; boat/fleet/wind/event,
  gate/short browsing leaves the complete boundary, worker identity and model
  sequence unchanged; rapid/double submission applies only the final compatible
  selection; New race holds the existing world. Desktop and smaller emulated
  viewports have accessible, centered content and no horizontal overflow.
- `staged-starter-regression-2026-10-06`: original initial hash, blocked helm,
  actual Start/countdown, native N and visibility ownership, staged trusted select
  input, applied fifteen/Triangle/Strong and retired-worker error handling pass.
- `staged-starter-layout-fixed-2026-10-06`: preview drag, selected native classes,
  event/name fields, real preview-context loss and recovery by changing selection,
  Start focus, Pause/Space after minimap controls, and New race pass.
- `staged-compatibility-fixed-2026-10-06`: Around Block Island's native offshore
  class/fixed course, incompatible option clearing, gate fleet promotion and
  header reduction to five boats pass through the new deferred Start flow.
- `staged-scoring-fixed-2026-10-06`: unchanged original series boundary/scoring
  and championship results/5/10-race configuration probes pass in manual mode.
- `staged-championship-fixed-2026-10-06`: actual five-boat island race, four AI
  finishes and player DNF; native next-race transition preserves standings and
  returns a ready boat preview and Start next race action. Batch-paced diagnostic,
  not frame-rate measurement.

Review fixed premature launch from the previous generation's readiness, a blank
next-race boat preview, visibility during asynchronous Start, retry ownership,
header fleet/gate normalization order, chart label overlap and scrollbar centering.
Historical native probes use manual mode for immediate diagnostic configuration;
player-journey probes use the deferred Start flow. No unit tests were added.
TypeScript/Vite build and all 6471 frozen-reference checks pass.

Additional checks: `starter-venues-2026-10-06` covers all 33 selected venue
charts, with the full held worker boundary unchanged. Maximum synchronous option
handler time was 63.7ms (excluding eventual preview GPU paint).
`staged-start-performance-2026-10-06/webgl2-0.json` measures the actual 15-boat
standard race through Start: median/P95/P99 changed cadence 16.7/16.8/20.9ms,
camera P95 26.1ms, and 29 draw calls. Cadence, camera, geometry and physics-progress
checks pass. The original drawing/model transport totals 38996 bytes and exceeds
the reference's 32768-byte packet ceiling, so this is not a full-budget pass;
that preset-specific transport limit remains an explicit performance follow-up.
The authoritative worker bundle is byte-identical to the previous build.
