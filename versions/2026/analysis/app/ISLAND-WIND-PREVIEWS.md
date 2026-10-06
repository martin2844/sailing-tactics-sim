# Island course selection, compass weather and water-safe previews

Island now accepts all seven race-course choices. Previously both the menu and
native basic-island configuration silently forced triangle/triangle twice. The
explicit 2026 configuration adapter preserves the selected course flags; native
lap, target, AI and scoring routines still implement the selected race. Fixed
long-distance routes retain their original compatible course restrictions, with
unavailable choices disabled rather than inviting a silent reset.

Wind from offers Auto plus N, NE, E, SE, S, SW, W and NW. Auto preserves the native
weather and audited startup states. A chosen compass direction configures the
native prevailing sector/base bearing before its weather initialization, and
calibrates the combined mean bearing for that race. The original thermal strength,
shift scheduling, drift, local wind and gust calculations continue; instantaneous
wind can differ slightly from the selected prevailing direction. The calibration
resets on a native new race. Callbacks are scoped to each memory image.

All changes remain staged until Start. Frozen original files are untouched;
`prepare-legacy.mjs` validates each pinned source and declares generated island
configuration and wind initialization/bearing adapters. The new direction choices
are an intentional 2026 extension, not a claim of unchanged physics under a newly
specified wind direction. Auto's five/fifteen reference hashes remain identical.

## Preview defects and repair

The reported Island/west-wind sample's native coordinates were in water. Its
preview invented wide horizontal start/finish strokes and fixed text offsets,
which put drawn objects over land. Rotated samples at other venues could also
move marks onto land, and an incomplete routing graph could omit a leg.

The preview now uses actual line endpoints and orientation, combines coincident
start/finish labels, reserves shoreline-safe text rectangles and separates buoy
names from their symbols with leaders when necessary. Shoreline containment
covers both islands and bounded lakes. Rotated/shortened schematic marks are
moved into nearby water if needed; this presentation correction does not change
race memory. Routes stay in water, symbols shrink to their available clearance,
and a water mask guards drawing over land. Gates show two distinct marks.

Nine expensive Around Block Island routes are baked from the validated geometry,
and checked before reuse. Native compass-specific samples replace the problematic
Edgartown rotated downwind layouts. The atlas now has 133 venue/family/wind profiles
and 46 shared terrain records, alongside the 27 boat/7 course-family samples.

Regeneration: run `tools/generate-starter-samples.mjs`, then
`tools/bake-preview-routes.mjs` against the local production preview. These use
isolated clients/pure geometry and do not change the held player race.

## Evidence and scope

- `island-course-wind-reviewed-2026-10-06` and
  `island-course-wind-tight-2026-10-06`: seven distinct Island course previews;
  actual native initialization and 80 paints for each course and each compass
  direction; actual Start with W/L twice/NW; original 5/15 Auto startup hashes;
  exact unchanged held main-worker boundary after browsing.
- `island-wl-north-live-2026-10-06`: naturally sailed NPCs on Island W/L/North,
  four AI finishes and player DNF via the actual twenty-minute finishing window.
  The unsteered player eventually grounded, as expected without steering.
  Diagnostic batch pacing, not a frame-rate benchmark or the full played cross-product.
- `wind-default-regression-2026-10-06` and `wind-picker-layout-2026-10-06`:
  existing starter/native input, generation ownership, naming/event, preview
  recovery, pause/focus and responsive Chrome checks pass.
- `preview-full-matrix-final-2026-10-06`: 5832 supported combinations across all
  33 venues, seven course types, Auto/eight compass directions and allowed
  short/gate settings. Marks, whole lines, connected routed legs and callout
  rectangles are in water; zero failures. This checks sample geometry, not
  physically sailing every combination or predicting future moving finish lines.
- `preview-visual-final-2026-10-06`: 90 actual Chrome charts covering every Island
  course/wind and Block Island/Edgartown edge cases; SVG text fits its validated
  rectangles, no missing routes, and the whole paused native boundary is unchanged.
  Worst synchronous selection handler was 8.4ms after baking, down from 1090ms
  for the previous cold route calculation. This timing excludes eventual GPU paint.

TypeScript/Vite build and all 6471 frozen-reference checks pass. The existing
preset-specific worker transport budget follow-up in STAGED-SETUP.md is unaffected.
