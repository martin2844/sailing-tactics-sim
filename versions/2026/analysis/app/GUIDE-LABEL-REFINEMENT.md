# Guide and label refinement

## Pass 1 — original guide behavior

The modern guide extractor executes a generated copy of the original chart's
mark/gate/finish decisions and integer-angle emissions on a private memory/RNG
image. It drops unrelated chart artwork, tracks and gust drawing, and admits
points outside the historical viewport for free-camera clipping. It does not
modify or replace authoritative drawing routines. Guide anchors and bearings
come from those decisions; extension length and styling remain presentation.
The invented target rays and gray equal-distance line have been removed. The
native boat guide, when eligible, is retained. L now changes the heading reference
by the original tack-dependent 45 degrees and never creates additional rays.

Evaluation: [30 original-chart comparisons](guides-pass1-final2/verification.json)
cover prestart, upwind, reaching suppression, third-mark approach, downwind,
finish sides, gate endpoints, recall, results, mark-line suppression, wind
359/1 and both alternate chart orientations, on five/thirty-boat private images.
The independent oracle runs the full original chart with real GDI children;
anchor and bearing tolerances account only for original integer pixel endpoints.
These are controlled fixtures, not completed races or a full course/state product.
Extraction leaves the entire master image/RNG/frame/clock/shore unchanged.
[Paired original simulation](guides-worker1/verification.json) matches five
whole-image boundaries per fleet for five/fifteen boats and real helm/tack inputs.
Production build/type checking pass. Frozen sources remain unedited.

## Pass 2 — shared labels

One screen-space canvas now lays out measured 20px-high buoy badges and boat names (maximum 144px wide). Projected native hull/rig bounds, other labels and visible HUD panels reserve space. Active marks, hover/selection and prestart endpoints have priority; up to four nearby names appear automatically, with an All names toggle for additional identities where space permits. Clipped rigs can deliberately have no label. Pointer selection preserves the follow camera; names remain canvas text, not HTML. Restart/context recovery preserves the display toggle. HUD reservations refresh every rendered frame.

Evaluation: [19 layout cases](labels-pass2-final/verification.json), covering 5/15/30 boats, chase/overview/close cameras, trusted pointer selection and DPR2, passed fixed-size and collision checks with the full native boundary unchanged. [Name evaluation](labels-names-final/verification.json) passed native identities, custom name storage and fleet reset; it verifies safe text plumbing, not every rendered glyph. [Headed Chrome lifecycle](labels-lifecycle2/verification.json) passed changing rendered pixels, pause isolation, three pause cycles, fleet restart and context-loss recovery. An earlier lifecycle attempt stopped before app checks because the compositor reported a one-pixel window-size mismatch; a fresh owned-window attempt matched and passed. Production build/type checking passed.

## Pass 3 — visual hierarchy and Chrome evaluation

Native guide centreline endpoints now expand into ordinary depth-tested meshes with a stable CSS-pixel width and a narrow contrast edge. The active approach is amber; other native guides use pale strokes, with a quieter native boat guide. Start and finish dashes retain a stable screen size. Homogeneous near/far/viewport clipping occurs before expansion, keeping free-camera crossings finite. Boats and land occlude the guides through normal scene depth. Guide extension and raster styling are presentation changes; selection and bearings remain original. Overview fitting now includes gates, separate finish endpoints and the native target. Water facet contrast is reduced, and label slots retain their previous placement while it still fits.

The HUD adds a native-target bearing and bow-relative direction arrows for that target, wind **from** direction, and current **flow** direction. Absolute numeric bearings remain visible. The original HUD target-selection routine (0x440350) runs after guide extraction on the same private image, with its original finish-midpoint overrides. Its physical chart object supplies the target name/bearing and active-guide highlight; AI approach waypoints remain unchanged. This fixes the live-race case where an approach point offset from the buoy previously produced “Target” and no amber mark. Native object indices disambiguate coincident marks. Prestart/recall coordinates can lie anywhere along the start line; finish reuse and completed boats have appropriate names. Recall takes its bearing from the original return waypoint even when the sailing HUD selector still identifies a race mark. Finished/zero-current arrows truly hide despite their display styles. No unverified world-distance unit conversion is displayed.

[Projected geometry and navigation checks](guides-visual-final4/geometry.json) cover 30 depth/viewport/layer width measurements, near/far/eye/viewport clipping, bounded dashes, heading wrap and eight target identity fixtures. [Nine guide render cases](guides-visual-final4/verification.json) project source-checked emissions for upwind, reach suppression, third mark, downwind, finish, gate, recall and north wrap. These are isolated presentation fixtures, not completed races. [The original oracle](guides-oracle-final/verification.json) again matches 15 conditions per fleet (5/30).

[Actual countdown-to-race smoke evaluation](guides-live-race-final/verification.json) advances five boats through 1,200 real original paints to clock 37, checks non-demo mode, four original guides, Mark 1 at the original physical buoy, two amber approaches and an unchanged paused camera boundary. It is an early-race check, not a completed race. [Final crowded-label evaluation](labels-complete/verification.json) passes all 19 layout cases.

Review also isolated the full-chart diagnostic from the real native boat observer and host callbacks. [Future-state isolation](guides-isolation-target-final/verification.json) checks the observer stream unchanged, then compares two workers byte for byte after 1, 8, 32 and 232 real paints on 5/15 boats. One worker runs the private oracle; the other does not. This covers memory/RNG/clock/frame/shore without claiming full-race parity. [Context recovery](labels-recovery-final/verification.json) checks the All names toggle and exactly one annotation canvas after graphics replacement, in addition to the lifecycle checks above.

Final Chrome performance: [ten standard runs](guides-chrome-standard-positioned/verification.json) and [ten guide-heavy runs](guides-chrome-stress-positioned/verification.json) passed unchanged budgets, with five repetitions per requested backend in each dataset. The extra workload uses six original upwind guide emissions and All names, while the real native worker continues its ordinary prestart; it is a presentation stress fixture rather than a completed-race claim. Chrome 152.0.7977.82 used the Radeon RX 7800 XT, an owned 1280×1051 headed window, 1280×1050 DPR1 logical viewport and actual 1280×640 scene surface. Both requests ran WebGL 2 (the WebGPU request used its fallback); native WebGPU and fallback GPU-query timing are not certified.

Across all 20 runs, median changed-frame intervals were 16.7ms, worst per-run P95 was 16.8ms, worst P99 25.0ms, and worst isolated frame 37.4ms. Worst camera-response P95 was 20.4ms across six trusted camera clicks per run. Maximum combined presentation packet was 27570 bytes; draw calls peaked at 48, visible triangles at 38269. Simulation progress/rate is recorded independently and never inferred from render FPS. Paused whole-state checks and trusted native Port changes passed. See [aggregate numbers](guides-chrome-summary.json).

[Two additional live-race runs](guides-chrome-live-race/verification.json), one per requested backend, use 1,000 explicit original countdown paints each on 15 boats, after their initial real startup paints, rather than an injected presentation fixture. With the original AI, physical target and four original guides active, both pass every recorded budget: median changed intervals 16.7ms, worst P95 16.8ms, worst P99 20.8ms, maximum combined presentation 29131 bytes and camera-response P95 17.4ms. They are supplemental early-race measurements, not five repetitions or completed races.

Production build/type checking and [frozen reference integrity](reference-guides-final.json) pass (6,471 files). The simulation, captured RNG and original sources remain unchanged.

Evaluation incidents are retained separately: an earlier window startup reported a one-pixel compositor mismatch; short retries initially recovered some starts, but later repeated failures required a 2026-only sizing wrapper. Direct CDP/compositor inspection found off-screen origins and repeatable extra-pixel extents; integer positioning inside the owned monitor resolved those extents. The wrapper uses PID/address-checked [Hyprland window dispatchers](https://wiki.hypr.land/configuring/core/dispatchers/) for explicit floating, resizing and integer positioning, and waits for two settled, exact CDP readings before accepting the same declared dimensions. The frozen shared helper is unchanged. One cadence attempt lost the foreground before collecting enough frames. Another guide-heavy attempt switched to 30 boats during its 15-boat measurement, visible in its saved screenshot, so its transport-budget result is outside the declared scenario. The runner now checks fleet, race generation, configuration, pace and annotation settings at both measurement boundaries, and locks fleet/restart controls in its temporary benchmark window. These incidents are excluded from final acceptance; frame and transport budgets remain unchanged.

Scope remains Linux desktop Chrome, the recorded 15-boat reference workload and controlled layout/guide fixtures. Physical Pixel 11, native WebGPU, complete races across every course, and long-session acceptance remain outside these passes. Labels intentionally hide when no readable location exists; this is not a guarantee that every identity is visible in every camera view.
