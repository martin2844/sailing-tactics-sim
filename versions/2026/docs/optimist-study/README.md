# Optimist: measured, restrained low-poly study

The reviewed Optimist now replaces class 1 in the 2026 starter preview and live fleet. Laser and Keelboat retain the original pre-redesign renderer (`6eca713`); all 16 of their compass screenshots remain byte-for-byte identical to the restored OG baseline. The standalone study remains available for geometry review. See [live integration](live-integration.md) for the state mapping and evaluation.

## References and authority

- [UK Optimist class specifications](https://www.optimist.org.uk/the-boat/technical-info/): 2.36 m overall hull length, 1.12 m beam, 2.26 m mast, nominal 3.3 m² sail.
- [World Sailing class rules, 2000 edition](https://www.sailing.org/tools/documents/2000_OptimistClassRules-%5B521%5D.pdf), section 6.2.2: luff ≤1.730 m, head ≤1.240 m, leech ≤2.800 m, diagonal 2.450–2.580 m; two short batten pockets. These are geometry references, not a claim of contemporary racing certification.
- [North Sails sprit-tension photographs](https://www.northsails.com/blogs/north-sails-blog/optimist-quick-tip-sprit-tension): steep rising head, peak well above the masthead, thin gunwale, sailor scale, short leech battens. Downloaded reference files: `references/north-sails-sprit.png` and `references/north-sails-trim.png`. The orange diagonal is an explanatory overlay, not rigging.
- [Far East builder's sailing photo](https://fareastboats.co.uk/boats/optimist): `references/fareast-sailing.jpg`, used for hull profile, freeboard and seated body proportions.

Photographs remain attributed reference material, not game textures. Generated concepts are visual studies, not dimensioned construction drawings. They may contain misplaced fittings; measurements and actual photographs take precedence.

## Generated studies

Three separate built-in OpenAI image-generator calls, completed before modeling:

1. `concepts/a-profile.png`: side elevation and stern quarter, hull and rig identity.
2. `concepts/b-racing.png`: restrained on-water low-poly treatment and natural sailor proportions.
3. `concepts/c-cockpit.png`: open cockpit, buoyancy bags, rigging and seated crew.

Exact prompts are in [prompts.md](prompts.md). The intended direction combines A's silhouette with B's restrained palette. The production mesh simplifies C's fittings and clothing detail, rather than reproducing its photorealistic texture.

## Geometry contract

Author in metres. Do not alter proportions with independent axis scales. Sail corner layout relative to the tack: tack `(0,0)`, throat `(0,1.730)`, peak `(0.870,2.600)`, clew `(2.040,0.160)`. This is an explicit modeling choice within the cited edge constraints, not an official sail cutting plan. Its planar area is about 3.335 m². The luff is vertical and the head rises steeply; the rejected broad, almost rectangular sail must not return.

Hull envelope is 2.36 × 1.12 m with a flat bow and stern, hard chines, shallow rocker and thin rails. Interior offsets, chine stations, sailor pose and small fittings are visual estimates from photographs, not certified measurements. Spar and line thicknesses are expressed in metres, independently of camera distance. The cloth keeps fixed topology while trim, heel, camber and luffing change pose. The sailor uses natural head/body ratios and muted racing clothing.

## Inspect the model

With Vite running on port 8771, open [the study viewer](http://127.0.0.1:8771/tools/optimist-study.html). It uses the same `app/models/optimist-study.ts` model as the playable Optimist, through an independent inspection UI. The viewer offers orbit, side/bow/stern/top views, trim, heel, luffing, crew visibility and penalty colour. These controls are presentation probes, not a live sailing simulation.

`tools/optimist-study-eval.mjs` checks the class proportion bounds, measured stations in the emitted hull, actual emitted sail corners under several poses, finite geometry and penalty colour. The final receipt and 16 screenshots are in `../../analysis/app/boat-redesign/optimist-measured-final/`, including all eight compass angles. Build and TypeScript checks passed. This does not certify every fitting, real-world sail shape, or integration with the numerical engine; these are the original study receipts. Live integration is evaluated separately below.

A subsequent [QA pass](qa.md) fixed viewport framing, mirrored camber, zero-trim crew switching, rudder/tiller details and emblem distortion. Use `tools/optimist-study-qa.mjs` for the control/layout regression checks; the latest eight-angle captures are in `../../analysis/app/boat-redesign/optimist-qa-views-final/`.
