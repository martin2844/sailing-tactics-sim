# Tact Optimist: reproducible case study

This describes the measured Optimist experiment, not a universal dinghy recipe. The repository is normally `~/tact`, with the 2026 app at `versions/2026`. The saved experiment branch is `3d-low-poly-experiment`; the normal OG branch is `main`, not `master`. Confirm the checkout before following file paths. If the experiment is not checked out, inspect its files with `git show 3d-low-poly-experiment:<path>` or use an isolated worktree instead of switching the user's working branch unasked.

## Reference and design sequence

Earlier Optimist/Laser/Keelboat redesigns were rejected for toy-like proportions and inaccurate rigs. The successful process restored the OG meshes, concentrated on one class, gathered actual photographs and dimensions, generated three complementary studies, then modeled the agreed direction and reviewed it before live integration.

Geometry sources recorded in the repo:

- UK Optimist class technical information: https://www.optimist.org.uk/the-boat/technical-info/
- World Sailing 2000 class rules, section 6.2.2: https://www.sailing.org/tools/documents/2000_OptimistClassRules-%5B521%5D.pdf
- North Sails sprit-tension photos: https://www.northsails.com/blogs/north-sails-blog/optimist-quick-tip-sprit-tension
- Additional sailing photos and their attribution: `versions/2026/docs/optimist-study/README.md` and its `references/` directory.

The old class rules were a geometry reference, not contemporary certification. Reverify if regulatory conformity is part of a new request.

The Optimist is a short, broad pram with flat bow and stern, an open cockpit and hard chines. Its spritsail has four corners, a short luff, a steep rising head and a peak above the mast. It is neither a square sail nor a triangular Bermuda rig. There are two short leech battens, slender spars, buoyancy bags, a daggerboard trunk, hiking straps, rudder and tiller extension.

The generated references are `docs/optimist-study/concepts/a-profile.png`, `b-racing.png` and `c-cockpit.png`, relative to the app. Full prompts are in `docs/optimist-study/prompts.md`. They used real photos as geometry references, the numeric sail outline below, a desaturated navy/white palette and natural sailor proportions. Three prompts varied side/quarter, sailing, and cockpit studies. They explicitly excluded thick toy bevels, triangular replacement sails, enormous heads and the analytical arrows overlaid on source photos. Built-in OpenAI image generation was used; the local API key was not required.

## Geometry contract

Units are metres; +Y up, bow toward -Z, starboard toward +X. The approved specification is `app/models/optimist-spec.ts`.

| Quantity | Value |
| --- | --- |
| Hull length | 2.36 m |
| Beam | 1.12 m |
| Mast length | 2.26 m |
| Mast Z / step Y | -0.72 / 0.04 m |
| Sail tack Y | 0.55 m |
| Tack in sail plane | (0, 0) |
| Throat | (0, 1.73) |
| Peak | (0.87, 2.60) |
| Clew | (2.04, 0.16) |
| Planar sail area | approximately 3.335 m² |
| Live waterline above hull datum | 0.13 m |

Rig dimensions are measured relative to the tack; they are not world-space coordinates. Hull and interior detail are a class-envelope reconstruction, not a certified cutting plan.

The model uses five hull stations and a seven-by-seven sail sampling lattice. Cloth details sample the triangles actually emitted, including the transparent window hole. The class emblem is authored in metres and inverse-mapped into sail UV coordinates. The sailor uses restrained faceted forms, bent limbs and a normal-sized head. The reviewed full model has approximately 5,725 triangles across hull, rig, sailor and window meshes.

## Code map

All paths below are relative to `versions/2026`.

| File | Responsibility |
| --- | --- |
| `app/models/optimist-spec.ts` | Dimensions, hull stations, pose contract |
| `app/models/study-mesh.ts` | Triangle writer and reusable rod scratch buffers |
| `app/models/optimist-study.ts` | Shared model, full study poses, efficient live animation |
| `app/optimist-study-viewer.ts` | Isolated inspector and geometry-aware camera framing |
| `tools/optimist-study.html` | Inspector entry point |
| `app/boat-model.ts` | Common model interface and class-specific factory |
| `app/models/optimist-boat-mesh.ts` | Game packet to reviewed-model pose adapter |
| `app/optimist-water-mask.ts` | WebGL water exclusion from the open cockpit |
| `app/boat-preview.ts` / `app/scene.ts` | Shared starter/live integration |
| `app/scene-labels.ts` | Labels using the shared local-bounds contract |

Do not edit the archived 2002/2010 engines for this visual change. The class factory selects the new model only for selector 1. Laser selector 2 and Keelboat selector 12 remain native meshes.

Native model packets use quantized coordinates divided by `MODEL_QUANTUM` (2048 in this experiment). The Optimist deck is the part-4 polygon with eleven points; its transverse axis is point 3 minus point 8. Derive heel with atan2(y, x). The first part-5 polygon is the mainsail; its last point minus its first is the tack-to-clew/boom direction. Undo heel before atan2(x, z) to derive trim. Black native fill indicates the original penalty sail. Assert the packet structure rather than silently accepting absent geometry.

The original hull length is four model units and the original presentation scale is four. Therefore the measured model's uniform scale is `16 / 2.36` world units per metre. The adapter places the waterline at `WATER_SURFACE_Y`, applies heel about it, and leaves heading and location to the scene. This preserves the longitudinal footprint; it does not redesign the existing collision envelope to the new measured beam.

Live animation retains a canonical rig buffer, rotates cloth/spars/details continuously, keeps the mast/tiller fixed, and rebuilds the two moving sheets with fixed hull endpoints. Small cloth billow is sampled at 10 Hz with per-boat phases. Crew side follows the source sailing side, not visual headwind oscillation. The shared pause-aware clock stops flutter. Bounds are in the outer model group's local coordinates, so labels can apply its world matrix once.

## Findings that shaped the implementation

- Viewer canvas overflow cropped the rig even when the nominal camera looked correct. Bound the viewport and measure visible vertices for preset framing.
- Opposite-tack camber initially had the wrong sign; test actual emitted positions, not only angle settings.
- Crew visibility once removed the tiller extension. Keep fittings in the rig, not the person mesh.
- A rudder head gap broke the physical linkage between blade, fittings and tiller.
- The emblem distorted in tapered UVs; metric-space authoring fixed it.
- Rebuilding thousands of rig triangles on every frame was too expensive for a fleet. Continuous rigid motion plus cached cloth samples reduced that cost.
- The original solid decks hid water-plane penetration. The open cockpit needed a water exclusion mask based on the same hull stations. The current mask is WebGL-specific; the experimental WebGPU comparison renderer still needs its node-material equivalent.
- Source tack and visual flutter must be separate so the sailor does not jump sides in headwind.
- A Vite server could serve HTML for a JavaScript module after `prepare:legacy` replaced public assets. Restarting the dev server after the build fixed the stale public-file cache. HTTP status alone did not detect it.

## Evaluation commands and limits

Run from the app directory. The existing tools assume the production preview at port 8770 and the dev server at 8771. Inspect processes before starting or restarting either; do not kill unrelated servers.

```sh
npm run check
npm run build
node tools/optimist-study-eval.mjs analysis/app/boat-redesign/NEW-study
node tools/optimist-study-qa.mjs analysis/app/boat-redesign/NEW-qa
node tools/optimist-live-eval.mjs analysis/app/boat-redesign/NEW-live
node tools/boat-redesign-capture.mjs analysis/app/boat-redesign/NEW-views
node tools/boat-redesign-live-eval.mjs analysis/app/boat-redesign/NEW-production
```

Use fresh output directories when preserving a previous receipt. Build before starting the dev server, or restart the dev server afterwards. The study uses `http://127.0.0.1:8771/tools/optimist-study.html`; normal play uses `http://127.0.0.1:8770/`.

The study QA covered 18 framing cases across three desktop sizes, both tack extremes, zero-trim crew retention, hidden-crew hardware, luff movement and no rig rebuild on heel-only changes. Live QA compared actual cloth vertices against the study at ten poses, exercised private original-engine trim/tack/penalty fixtures, verified unchanged engine/RNG boundaries and tested pause and crew stability during flutter.

The headed Chrome test records the GPU and runs 30 Optimists at selected 32×. One final RX 7800 XT run measured about 33× instantaneous pace and browser callback intervals of 12.5 ms median / 25 ms p95. These are a historical result, not a portable threshold or a 60-rendered-FPS claim. Headless Chrome selected SwiftShader on this machine and was not suitable for hardware throughput claims. Run performance captures alone. The evaluator emulates focus because background visibility otherwise pauses the game; distinguish that controlled benchmark from testing actual background-tab pause behaviour.

Final receipts and screenshots are in `analysis/app/boat-redesign/optimist-integration`, `optimist-live-study-qa`, `optimist-live-views` and `optimist-live`. Under fixed capture conditions all sixteen Laser/Keelboat views matched the restored baseline byte for byte. See `docs/optimist-study/live-integration.md` for the full scope and limitations.
