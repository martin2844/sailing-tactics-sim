# Three-boat low-poly redesign

The `boat-redesign` branch starts with a repeatable visual baseline for the Optimist, Laser, and Keelboat. Each boat has eight model-space compass views (N, NE, E, SE, S, SW, W, NW) at the same camera elevation and lighting. The gallery uses the app's saved native boat sample and `NativeBoatMesh`, so its pictures show the actual browser model, not a separate concept render.

| Boat | Baseline example | Redesigned example |
| --- | --- | --- |
| Optimist | [SE before](../analysis/app/boat-redesign/baseline/optimist-SE.png) | [SE after](../analysis/app/boat-redesign/after/optimist-SE.png) |
| Laser | [E before](../analysis/app/boat-redesign/baseline/laser-E.png) | [E after](../analysis/app/boat-redesign/after/laser-E.png) |
| Keelboat | [SW before](../analysis/app/boat-redesign/baseline/keelboat-SW.png) | [SW after](../analysis/app/boat-redesign/after/keelboat-SW.png) |

The complete [baseline](../analysis/app/boat-redesign/baseline/manifest.json) and [after](../analysis/app/boat-redesign/after/manifest.json) manifests list all 24 views and their camera bearings. Run `node tools/boat-redesign-capture.mjs analysis/app/boat-redesign/new-capture` with the Vite dev server on port 8771 to repeat the capture.

The hulls now have low-poly sheer, rail, painted topsides, chines, and darker lower facets drawn from the native deck outline. The Optimist gains a recessed open well. The Laser and Keelboat retain their native cockpit positions. The crew use native hiking anchors and have a dimensional torso, life jacket, helmet, bent legs, and hands. These accents use a compact shared palette; the underlying hull color still comes from the original boat state. The sail receives subtle panel variation while keeping its recovered contour, battens, mast, boom, luffing, and penalty color.

Only these three classes select the new hull treatment. The remaining classes retain the prior model. Numerical sailing, collisions, AI, race rules, and original model extraction were not changed.

Verification: TypeScript and production build passed. The existing native rig evaluation passed 14 trim/luff/tack/spinnaker/penalty states and six private-model transport checks. All three classes rendered in the live Chrome race, with [screenshots and model counts](../analysis/app/boat-redesign/live/verification.json). A 30-boat Keelboat run at selected 32× measured 32.25× during the short load check and retained the exact paused numerical boundary ([receipt](../analysis/app/boat-redesign/load/verification.json)). The fixed-gallery views assess the saved presentation pose; they do not certify every possible sailing angle or future art direction.
