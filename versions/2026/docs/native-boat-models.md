# Native-derived 3D boat foundation

The user chose faithful 3D boats with free cameras on 2026-10-05 after rejecting
the initial generic boat. The current renderer uses real Three.js meshes whose
contours, rig, articulation, crew positions and meaningful colors come from the
frozen 2010 drawing routines. The hidden 2D boat canvas is a reference diagnostic;
it is not the live boat renderer.

## Preserved simulation and private geometry

The simulation worker still performs the full original 1024×768, 24-bit paint
with real OffscreenCanvas pixel reads, bitmap fonts, x87 control word 0x027f,
native RNG, logical paint clock and retained shoreline context. Drawing remains
part of authoritative simulation until ENG-03 proves a narrower extraction.
There are no skipped simulation paints or catch-up ticks.

Preparation validates all 167 frozen runtime inputs, copies 166 unchanged and
adapts only an ignored copy of drawing-functions.js. Its original boat entry
points gain read-only begin/end/calibration observation; arguments, results,
GDI calls and the real drawing sink are forwarded. Frozen preservation files
are never edited. The manifest records both source hashes and actual prepared
hashes, with adapter name `native-boat-observer-and-private-model-v2`. The v2
adapter also restores the true-wind label's lost native GDI/CString arguments;
its disassembly and separate drawing contract are in the
[hotkey evaluation](../analysis/app/HOTKEYS.md).

A separate exported nativeModelDrawBoatNumber copies the original numeric boat
routine with private projection hooks. This entry only runs on copied memory
and a copied RNG in the graphics worker or paused diagnostics. It never runs
against the authoritative image. Every projection resets that private image
and RNG so paired calls start identically. An unexpected model pixel read or
unreviewed primitive fails explicitly.

The graphics worker owns a separate original image and fixed constants. The
engine sends only the mutable block at 0x4da000 (394,632 bytes), RNG state,
boat IDs and calibrated view width. Only one request is in flight; after
completion the engine submits its latest state. Dropped presentation samples
do not drop simulation steps. This private worker input is not a UI snapshot.
Six early and twelve longer-session boundary checks compare the reduced-state
worker's model packet with extraction from the full original image.

The UI receives pose snapshots and typed geometry packets, not the original
memory image. Model packets use Int16 positions at 1/2048 boat-unit resolution,
Int16 primitive records/boat ranges and Uint32 original COLORREF palette entries.
Coordinate and index bounds are checked before narrowing. Measured combined
live pose/model payloads stay below 32 KiB; production transport remains ENG-13.

## Recovering native geometry

The private entry preserves native initialization, hull and sail shape building,
heel, trim, luffing, spinnaker and crew calculations. Completed local geometry
and native height calibration are scaled by eight before final projection to
reduce integer pixel rounding. Uninitialized inactive spinnaker/crew slots are
excluded using the original conditions. It forces a known model view angle and
records the component identity around each native drawing dependency.

Two otherwise identical projections give each native primitive point's depth.
At angle A = 35 × the original angle constant (about -0.61087355 radians),
with native calibrated scale s, the private screen projection is:

```text
x_screen = 512 + s * X_camera
y_screen = 65536 + s * (0.3 * Z_camera - Up)
y_sheared = y_screen - s * Z_camera

X_camera = (x_screen - 512) / s
Z_camera = (y_screen - y_sheared) / s
Up = (65536 - y_screen) / s + 0.3 * Z_camera

X_body = X_camera * cos(A) - Z_camera * sin(A)
Z_body = X_camera * sin(A) + Z_camera * cos(A)
```

Native C integer rounding occurs before depth recovery. Third-shear checks
measure this approximation: the isolated cases have at most two high-resolution
pixels of affine error and at most 1.75 original pixels of polygon contour
error against the unscaled native projection. The reviewed bound is two
original pixels. This preserves recognizable contours and articulation, but
does not promise pixel-identical 3D rendering at arbitrary camera angles.

The original main has nine edge vertices in the tested Keelboat state; these
are retained and triangulated rather than replaced by a triangle. A second
view at -145 degrees supplies hidden hull sides. Native component mapping:

| Original routine | Mesh contribution |
| --- | --- |
| 0x41e3c0, 0x41e750, 0x41eaf0 | Hull sides and stern |
| 0x419ce0 | Deck |
| 0x41ce80 | Main sail and its native penalty color |
| 0x41f520, 0x425670 | Jib and spinnaker |
| 0x41fe70, 0x4235a0, 0x4243b0 | Mast, moving boom and rig lines |
| 0x4225b0, 0x423c30 | Crew bodies/limbs and heads |

The red line in 0x41fe70 is a screen-space wind pointer, so it is excluded from
boat-local rig geometry. World wakes, projection helpers and tutorial labels
are also excluded. Native pen widths become small five-sided rods for the rig.
The first spike used rods for crew outlines and ellipsoids for ellipse heads.
The current refinement builds closed solid torsos from those same native
shoulder/hip anchors, with bent legs, boots, sleeves, forearms, hands and faceted
heads. Shirt colors keep the native blue/green palette; skin, dark trousers,
boots and hair are new presentation choices. Head centers gain a small offset
along the native torso's up direction. Foot anchors, hiking side and heel stay
native; the source-visible arm retains its hand anchor. On the opposite tack
the painter omits the hidden arm, which is reconstructed from hip/foot anchors.
Unreviewed primitive layouts keep their source geometry. The helmsman's native
tiller/sheet line remains separate. Crew are merged into each boat's existing
mesh and shared material, adding no scene objects or draw calls.
The original three-person Keelboat crew remains present; sails can occlude it
from the opposite side, as expected with real 3D depth.

The cream deck now has a hole at the original gray cockpit footprint, with a
recessed floor and coaming. This removes intersecting faces left by translating
the original overlapping 2D polygons directly. The opening and exterior hull
contour retain their source positions. See the [cockpit evaluation](../analysis/app/COCKPIT.md)
and [crew evaluation](../analysis/app/CREW.md).

Palette values come directly from native drawing choices. The main turns black
when the original penalty branch chooses black; the jib keeps its original
color. These are state-driven changes, not invented modern penalty rules.
Lighting and tone mapping can change visible shades, but semantic colors remain.

## Rendering and current limits

Boat positions/headings come from original state, with east mapped to +X and
native south to +Z. Heading zero faces -Z, and rotation is -heading about Y.
The scene follows the player by rebasing world positions. Model scale is
currently four renderer units per recovered boat unit: provisional, not a
verified meter conversion. ENG-08/GFX-02 must resolve hull/course scale.

Pose snapshots and matching model topology interpolate at a capped 60 rendered
frames per second. Changed topology installs a new mesh state. Colors switch
immediately, so a penalty does not fade through gray. GPU position/color buffers
are reused for ordinary animation; topology changes release old buffers and
resize normals. Models and shared scene resources are disposed on reset/loss.
Triangulation indices are included in topology matching to avoid interpolating
between triangles whose vertex correspondence changed.
OrbitControls changes only the camera, including while simulation is paused.

Keelboat/Round Lake 5/15 fleets are the tested scope. Rig cases are deliberate
private fixtures, not proof of every naturally occurring race state. The private
RNG is cloned from each presentation snapshot; luffing is native-derived, but
its visual phase for boats outside the old viewport need not reproduce the
old painter's exact draw order. Physical state and authoritative RNG stay exact.

Remaining production work includes refined surfaces, editable/GLB exports,
verified world scale and picking, LOD, all production rig transitions, course
marks/start line, authoritative shore geometry, wakes and complete camera modes.
The spike's lake ring/trees and faceted water are illustrative scenery.
GFX-02 through GFX-11 remain separately tracked. See
[GFX-01 evaluation](../analysis/app/GFX-01.md) for actual evidence and limits.
