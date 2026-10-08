---
name: low-poly-game-models
description: Create proportionally faithful low-poly 3D game models from real references, evaluate them in an isolated study, and integrate them into an existing animated game without changing simulation behaviour. Use for model redesigns, articulated vehicles and sailors, multi-angle visual QA, or replacing legacy game meshes; not for standalone raster illustrations.
---

# Low-poly game models

Build a measured model, a repeatable visual evaluation, and a game adapter. Treat these as separate deliverables: an attractive generated image is not proof of correct geometry, and a correct static mesh is not proof of correct live animation.

For the Tact sailing project, read [the Optimist case study](references/tact-optimist.md) for exact dimensions, files, commands and known limitations. Use its numbers only for that class. For other objects, establish a new geometry contract from their actual references.

## Establish the baseline and scope

- Inspect the current branch, local instructions, model factory, scene transforms, preview renderer, engine snapshots and available evaluation tools. Identify who owns units, heading, heel, animation time and materials.
- Preserve a recoverable original. Capture N, NE, E, SE, S, SW, W and NW at fixed viewport, elevation, light, state and scale. Add side/top/cockpit views when they reveal structural differences. Record camera settings and mesh counts with the images.
- Keep unsupported or unapproved classes on their existing models. In a one-class experiment, a shared factory should select the new renderer only for that class.
- Preserve simulation, random state, penalties and contact logic unless the user explicitly includes behavioural changes. Document visual-size/contact-envelope differences instead of quietly changing physics.

## Research and generate references

Use real manufacturer/class photographs and technical plans or dimensions as geometry authority. Browse to verify niche specifications; save source URLs and distinguish measured dimensions from estimates. Use different viewpoints to resolve ambiguous shapes. Analytical arrows and photo overlays are not physical fittings.

Write down the defining silhouette before making meshes: hull outline, bow/stern form, rig type, sail corners, major proportions, spar attachment points and human scale. A logo cannot compensate for the wrong silhouette.

When generated concepts are requested or useful, use the available image-generation tool and its skill. Supply the real photographs, numeric proportions and explicit rig description. Generate complementary studies: an unobscured side/quarter view, a sailing view with a natural sailor, and a cockpit/detail view. Preserve the exact prompts and output paths. Do not claim a built-in image-generator call was a direct API-key request.

For a serious low-poly brief, prefer restrained materials, deliberate facets, thin real-world edges and natural human proportions. Avoid toy-like bevels, oversized heads/hands and decorative geometry that changes the class identity. These are style choices for that brief, not restrictions on intentionally cartoon projects.

If the user requested concept review before modeling, present that stage first and honour it. Reuse approvals already given; do not add new approval gates to an authorized integration. Reject or correct concept distortions before copying them into code. Generated images remain visual guidance, not cutting plans.

## Build an isolated, measurable study

Keep one shared geometry specification in physical units. Record the coordinate convention, hull datum, waterline and conversion to game units. Express hull stations, sail corners, mast height and pivot points explicitly. Share these values with dependent rendering such as water masks.

For code-generated assets, split responsibilities:

- Specification: dimensions and pose contract.
- Geometry writer: triangles, colours and reusable primitives.
- Model: hull, cloth, spars, ropes, fittings and sailor.
- Study viewer: lights, camera, pose controls and capture hooks.
- Game adapter: authoritative state to visual pose; no engine mutations.

Build the defining silhouette first. Add cockpit, chines, rudder, daggerboard, thin spars and rigging before incidental detail. Model people to the boat's scale, with credible joints, seated/hiking posture, feet in the cockpit and hands near the controls. Keep boat hardware independent of sailor visibility.

For sails and rigging:

- Triangulate the actual sail contour; do not substitute a generic triangle for a four-corner sail.
- Attach seams, battens and insignia to the emitted cloth triangles, using barycentric coordinates or equivalent surface sampling. Independent smooth surfaces can intersect faceted cloth and disappear from one side.
- Lay out geometric insignia in physical coordinates before mapping to tapered sail UVs, so circles and stems stay correctly proportioned.
- Give narrow details enough physical thickness to be visible from both sides while preserving depth occlusion. Do not disable depth testing to hide placement bugs.
- Keep boom/sprit/cloth connected around their real pivots. Sheets may have a rotating endpoint and a fixed hull endpoint.
- Mirror camber and crew placement with the sailing tack. At zero trim, retain the prior side. A visually fluttering sail crossing the centreline must not by itself move the sailor to the other side.

Fit preset cameras against actual visible geometry with a margin. Test both extreme poses and narrow desktop viewports; canvas overflow can invalidate seemingly correct camera bounds. Preserve manual orbit and zoom. Put the viewer code under normal type checking.

## Evaluate the study before integration

Use a small, deterministic evaluation appropriate to the risks, rather than tests that repeat implementation formulas. Inspect the screenshots as well as automated receipts.

Check dimensions against source envelopes and actual emitted vertices; finite positions/normals; sail corners through trim/heel extremes; two-sided details; correct camber on each tack; continuity through zero trim; penalty colour; crew/hardware visibility; and complete framing from eight directions. Exercise the real viewer controls.

Check lifecycle costs too: changing heel should normally be a transform, hiding a sailor should be visibility, and disabling luff should stop time-driven geometry writes. Refresh cached bounds when geometry changes. State when an evaluation proves only presentation geometry, not physics fidelity, certification or integration.

## Integrate with the existing game

Use the same reviewed model in the starter preview and live fleet through a common rendering interface. Include local bounds, update/interpolation and disposal; avoid forcing every model to pretend it has one merged geometry.

Map authoritative state explicitly. If the engine only supplies recovered geometry, extract heel from a known transverse deck axis, undo that heel before deriving boom bearing, and use the original sail fill for penalty colour. Verify sign conventions on opposite-tack fixtures. Do not infer gameplay penalties from visual motion.

Separate world position/heading, waterline-centred heel and local rig rotation. Scale physical dimensions uniformly into the existing world footprint. Use the game's pause-aware presentation clock for flutter, not independent wall time. Check preview updates, class switches, race resets and disposal as well as continuous sailing.

Open cockpits expose a problem solid legacy decks can hide: the water plane intersects their floor. Exclude water inside the hull or use the renderer's equivalent masking mechanism; do not lift the boat or flatten its measured interior just to conceal the intersection. Check support on the actual renderer backend and document any experimental-backend gap.

Avoid rebuilding detailed geometry on every frame for every boat. Measure first; use rigid transforms or reusable buffers for trim/heel, cache static topology, and rebuild only what changes. If small visual deformations can be sampled less often, stagger work across the fleet while keeping boom motion continuous. This is a presentation optimization, not permission to reduce the physics timestep or change the race clock.

## Validate live and deliver

- Start the changed class and representative unchanged classes through the real setup UI.
- Exercise source-driven trim, both tacks, luff and penalties; compare whole-state/RNG boundaries around rendering-only probes when available.
- Verify that pause freezes presentation and numerical state. Check crew stability during headwind flutter separately from actual tacking.
- Run the maximum relevant fleet and requested pace on the intended browser/hardware. Record actual GPU, requested/achieved pace, interval distribution and long frames. Browser animation callback intervals are not necessarily rendered-frame intervals. Headless software rendering is not representative of desktop GPU performance. Avoid overlapping performance tests.
- Capture the final starter, a live close-up and eight directions. Compare unchanged classes to their baseline under identical conditions; byte identity is useful only with a deterministic capture setup.
- Build the production app and check the served result. Development-server public-file caches can become stale if the build replaces copied assets: inspect content type/body, restart the server when needed, and do not mistake an HTML fallback for a valid JavaScript response merely because it is HTTP 200.

Save sources, prompts, assumptions, findings, fixes and evaluation receipts. State remaining limits. Commit only task-related paths when requested; preserve unrelated untracked work. If shelving the experiment, commit it on its branch before switching to the repository's actual default branch, rebuild that branch's ignored output, and verify the running app uses its original models. A branch switch alone does not replace an already-built preview.
