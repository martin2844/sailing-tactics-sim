# Three-boat low-poly redesign

**Current state:** the three redesigns below were rejected. The playable fleet is restored to the OG models, with all 24 screenshots matching the baseline exactly. New work is confined to the [measured Optimist study](optimist-study/README.md), based on real photographs and generated references. The following sections are historical.

The `boat-redesign` branch starts with a repeatable visual baseline for the Optimist, Laser, and Keelboat. Each boat has eight model-space compass views (N, NE, E, SE, S, SW, W, NW) at the same camera elevation and lighting. The gallery uses the app's saved native boat sample and `NativeBoatMesh`, so its pictures show the actual browser model, not a separate concept render.

| Boat | Baseline example | Redesigned example |
| --- | --- | --- |
| Optimist | [SE before](../analysis/app/boat-redesign/baseline/optimist-SE.png) | [SE after](../analysis/app/boat-redesign/after/optimist-SE.png) |
| Laser | [E before](../analysis/app/boat-redesign/baseline/laser-E.png) | [E after](../analysis/app/boat-redesign/after/laser-E.png) |
| Keelboat | [SW before](../analysis/app/boat-redesign/baseline/keelboat-SW.png) | [SW after](../analysis/app/boat-redesign/after/keelboat-SW.png) |

The complete [baseline](../analysis/app/boat-redesign/baseline/manifest.json) and [after](../analysis/app/boat-redesign/after/manifest.json) manifests list all 24 views and their camera bearings. Run `node tools/boat-redesign-capture.mjs analysis/app/boat-redesign/new-capture` with the Vite dev server on port 8771 to repeat the capture.

## Real-boat reference pass

The second pass uses actual class information, with generated images as visual briefs rather than as technical evidence:

| Game class | Primary real-boat reference | Generated low-poly brief | Result in the mesh |
| --- | --- | --- | --- |
| Optimist | [UK Optimist specifications](https://www.optimist.org.uk/the-boat/technical-info/) and [class description](https://www.optimist.org.uk/the-optimist-class/about-the-boat/) | [Optimist concept](boat-reference-images/optimist.png) | Blunt pram bow, open well, one larger child sailor and a distinct diagonal sprit. The original moving four-cornered sail is retained. |
| Laser | [ILCA boat description](https://ilcasailing.org/about-the-ilca-boat/) and [parts diagram](https://ilcasailing.org/wp-content/uploads/2025/02/Parts-of-the-ILCA-Dinghy.png) | [Laser/ILCA concept](boat-reference-images/laser-ilca.png) | Lower topsides, cockpit hiking strap and centreboard slot, one larger adult sailor. Its original free-standing mast and moving sail remain. |
| Keelboat | The game's Keelboat is generic. The [J/24 manufacturer's specification](https://jboats.com/j24-tech-specs) and [J/24 class crew rule](https://www.j24class.org/wp-content/uploads/2010/11/J24-Class-Rules-2023.pdf) provide a concrete racing-keelboat reference. | [J/24-inspired concept](boat-reference-images/keelboat-j24.png) | Deeper topsides, shallow cabin trunk with dark side windows, restrained lifelines and three larger sailors. The original jib and mainsail remain. |

The [second-pass eight-view captures](../analysis/app/boat-redesign/real-reference-pass-v2/manifest.json) use the same gallery and angles as the baseline. The generated concepts guided visual decisions; their geometry was checked against the class sources before changing code. No generated bitmap is used as a runtime texture or mesh.

The images were produced with the built-in OpenAI image generator. The final prompts are preserved in [prompts.md](boat-reference-images/prompts.md). No local `OPENAI_API_KEY` was available, and the user approved the built-in generator.

For this second pass, `npm run build` and the 14-case rig evaluation passed. The [Optimist sail check](../analysis/app/boat-redesign/real-reference-optimist-sail/verification.json) passed six actual rig states and 24 Chrome camera views after the sprit change. [Live Chrome results](../analysis/app/boat-redesign/real-reference-live/verification.json) show each selected class rendering in an actual five-boat race. The [30-boat pace check](../analysis/app/boat-redesign/real-reference-load/verification.json) measured 32.25× with 32× selected and found no advancement across a pause boundary. The three concepts are intentionally more detailed than the runtime geometry; the renderer still has to keep 30 boats responsive.

The hulls now have low-poly sheer, rail, painted topsides, chines, and darker lower facets drawn from the native deck outline. The Optimist gains a recessed open well. The Laser and Keelboat retain their native cockpit positions. The crew use native hiking anchors and have a dimensional torso, life jacket, helmet, bent legs, and hands. These accents use a compact shared palette; the underlying hull color still comes from the original boat state. The sail receives subtle panel variation while keeping its recovered contour, battens, mast, boom, luffing, and penalty color.

Only these three classes select the new hull treatment. The remaining classes retain the prior model. Numerical sailing, collisions, AI, race rules, and original model extraction were not changed.

Verification: TypeScript and production build passed. The existing native rig evaluation passed 14 trim/luff/tack/spinnaker/penalty states and six private-model transport checks. All three classes rendered in the live Chrome race, with [screenshots and model counts](../analysis/app/boat-redesign/live/verification.json). A 30-boat Keelboat run at selected 32× measured 32.25× during the short load check and retained the exact paused numerical boundary ([receipt](../analysis/app/boat-redesign/load/verification.json)). The fixed-gallery views assess the saved presentation pose; they do not certify every possible sailing angle or future art direction.

## Rebuilt art pass — October 8

The two earlier passes were rejected visually. They retained too much of the old painter's proportions: tall rigs, shallow hulls and undersized crew. Their technical checks did not establish that the art met the brief.

This pass replaces the three selected classes' hulls and sailors with authored geometry. [Eight views per boat](../analysis/app/boat-redesign/rebuilt/manifest.json) show the actual shared runtime mesh. The older captures above remain historical comparisons.

- **Optimist:** rounded pram corners, white topsides and narrow fleet-colour stripe, a deep open well, mast thwart, daggerboard trunk, hiking straps, rudder and tiller. The new four-sided sail has a distinct sprit and seven deliberately connected panels. Native trim, heel, camber and penalty colour still animate its pose.
- **Laser/ILCA:** slender bow, recessed cockpit, centreboard slot and hiking strap. Its moving recovered rig is reduced in height to fit the hull, with dimensional spars and pale seams.
- **Keelboat:** full hull, low cabin and hatch, recessed aft cockpit, lifelines and three sailors. The native moving main and jib remain, with the same proportional correction.
- **Sailors:** eight-sided life jackets, shoulders, separate bent thighs and calves, boots, forearms, hands and capped heads. Native crew anchors choose tack side and hiking lean; body proportions and seating are authored separately from the old pen strokes.

`boat-design.ts` adapts presentation coordinates, `boat-hull.ts` constructs hulls, and `boat-sailor.ts` constructs crew. They emit triangles into the existing merged boat mesh, without adding a draw call for every body part. The other boat classes continue to use the existing shapes. The numerical engine and collision geometry are unchanged; these are visual models, not a new class physics model.

The sail evaluation now checks the actual seam/spar material instead of assuming every detail is black. It retains the detached-detail negative control and tests both cloth faces under interpolation and headwind deformation. That evaluation initially exposed narrow triangles along the new Optimist leech; fixed panel connections removed those slivers. Boom-mounted sheet endpoints also follow the boom's interior, rather than only its clew.

Verification for the rebuilt pass: production build and TypeScript passed; [six Optimist rig states](../analysis/app/boat-redesign/rebuilt-sails-verified/verification.json) passed 198 two-sided surface checks each, including the detached-detail negative control; [the native rig evaluation](../analysis/app/boat-redesign/rebuilt-rig-verified/verification.json) passed 14 cases and six private-model transport checks. [All three classes entered live races](../analysis/app/boat-redesign/rebuilt-live/verification.json). The [30-boat load check](../analysis/app/boat-redesign/rebuilt-load/verification.json) measured 32.25× with 32× selected and retained the exact paused boundary. These are bounded technical checks; the new screenshots are the evidence for judging the visual direction.
