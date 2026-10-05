# Solid native-anchor crew — 2026-10-05

The crew's three colored outline segments describe a torso. They now form a
closed solid shirt, with bent trouser legs, boots, sleeves, skin forearms/hands
and faceted heads with hair. Original shoulder/hip/foot anchors retain hiking,
heel and side changes. Native blue/green shirt colors and the helmsman's separate
tiller/sheet line remain. The source-visible arm keeps its hand anchor; the arm
omitted by the painter on the opposite tack is inferred from native hip/foot
anchors. Head centers have a small offset along the torso's up direction.
Skin, hair, trousers and boots are deliberate new presentation colors.

These are procedural additions to each boat's existing merged mesh and shared
material. The source model packet, private-worker input and authoritative
simulation are unchanged. Unreviewed source layouts retain native geometry;
this is the reviewed Keelboat refinement, not certification of all boat types.

The first close-camera test caught the omitted opposite-tack arm and failed
torso coverage there. That source layout is now handled. The final independent
ray/triangle checks hit both walls of all three solid torsos in normal, luffing,
opposite-tack and spinnaker states. Close screenshots were inspected on both
sides. The deck remains clear across all nine cockpit probes in each of four
fixtures. Seven native rig/palette cases and six graphics-worker/full-image
packet comparisons passed, including moving boom, changing luff geometry and
black penalty mainsail. Diagnostics leave the whole native boundary unchanged.

The first performance run failed the unchanged cadence budget: p95 was 33.4 ms
and median UI mesh build was 20.3 ms. Small joints/boots now use eight-face
geometry instead of head-resolution spheres. Rig/limb rods reuse scratch rings
and cached trigonometry instead of allocating vectors for every triangle.
This preserves the rod contour and triangle order apart from negligible seam
roundoff. Heads retain their eight-segment faceted shape.

All ten final headed Chrome runs passed the existing desktop budgets: five
default WebGL 2 and five requested WebGPU runs using its actual WebGL 2 fallback.
Native WebGPU was unavailable and is not claimed as tested. Worst run statistics:

| Measurement | Result |
| --- | --- |
| Changed-frame median / p95 / p99 | 16.7 / 16.9 / 20.9 ms |
| Largest individual interval | 50.1 ms |
| UI mesh-build median / p95 / maximum | 6.7 / 12.6 / 17.3 ms |
| Trusted camera-response p95 | 18.3 ms |
| Maximum calls / triangles | 19 / 38,156 |
| Combined typed presentation payload | 23,116 bytes |

These bounded 15-boat measurements cover visible Chrome on this machine, not a
complete race, Pixel 11 or other browsers. The final build and TypeScript check
passed. The crew implementation also passed nine pause/restart/context-loss
checks; 32-paint frozen-reference comparisons matched all ten declared whole
memory/RNG/time/frame/shore boundaries across 5/15 boats. Longer sessions ran
1,100 native paints per fleet, reaching race clock +20, with all twelve graphics
transport comparisons exact and no changes to the authoritative boundary.
All [6,471 frozen preservation inputs](refinements-reference-verification.json)
remain unchanged.

Evidence:

- [Final close-camera crew checks](crew-close3/verification.json).
- [Final cockpit checks](crew-surface2/verification.json).
- [Final native model checks](crew-models2/verification.json).
- [Repeated Chrome performance](refinements-renderer2/verification.json).
- [Worker parity](refinements-worker1/verification.json).
- [Session checks](refinements-session1/verification.json).
- [Lifecycle checks](refinements-lifecycle1/verification.json).
- [Initial omitted-arm failure](crew-close1/failure.txt) and
  [initial performance failure](refinements-renderer1/failure.txt).

Reproduce against a built preview at localhost:8770 using `crew-eval.mjs`,
`boat-surface-eval.mjs`, `native-model-eval.mjs` and `renderer-eval.mjs`, each with
a fresh output directory. The polished model's scale/export/LOD and production
asset work remain open in GFX-02/GFX-03/GFX-04.
