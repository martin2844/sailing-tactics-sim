# Cockpit surface correction — 2026-10-05

The recovered painter placed a gray cockpit polygon on a complete cream deck.
Both became 3D faces, leaving the deck across the cockpit and causing overlapping
surfaces. The deck now has a hole at the original cockpit footprint, with a
recessed floor and vertical coaming. Hull, sail and rig contours remain native.
This is a presentation correction; the native paint and physics are unchanged.

Polygon triangulation indices are now part of the animation topology key.
When triangulation changes, vertices install immediately instead of interpolating
between triangles with different vertex correspondence.

Evaluation used vertical rays through nine interior points against the actual
uploaded mesh, independently classified by deck/floor colors. Normal, trimmed,
opposite-tack and luffing fixtures each had nine overlapping deck intersections
before; after, all had zero deck intersections and nine covered floor points.
Before/after inspection preserved the complete authoritative boundary. Screenshots
were inspected. The seven native rig/color fixtures, six private-worker packet
comparisons and free-camera isolation also passed. TypeScript and the production
build passed.

Evidence: [before](cockpit-before2/verification.json),
[after](cockpit-after1/verification.json),
[native model checks](cockpit-models1/verification.json).
These checks cover the current Keelboat fixture, not every boat type or the
complete polished-model task.
