# Native course objects

The modern scene now displays the original marks, committee/start boat, pin,
start and finish lines. Course coordinates are read from native memory without
writes. The initial start line is retained across native changes to the current
finish endpoints. When the two coincide, one white prestart line becomes a mint
finish line after the gun. Duplicate native marks share one displayed buoy.
Overview frames the actual course; labels keep a readable screen size.

L toggles two heading guides from the current native target using the player's
wind direction and native close-hauled angle. These are directional laylines,
not predictions corrected for future shifts, current or disturbed air.
The buoy and committee meshes are modern artwork, not recovered native assets.
The lake silhouette and boat scale remain provisional.

Evaluation:

- `course3/verification.json`: actual mesh positions, player rebasing, trusted
  L toggles, overview and committee screenshots; an isolated changed-finish
  fixture checks that distinct start/finish lines both remain visible.
  Presentation leaves the entire native boundary unchanged. L intentionally
  changes native keyboard state; paints, RNG and retained shore stay fixed.
- `course-worker1/verification.json`: five exact whole-image/RNG/clock/shore
  boundaries each for five/fifteen boats over 32 real paints.
- `course-lifecycle1/verification.json`: nine checks including moving rendered
  pixels, paused camera isolation, fleet restart and context loss recovery.
- `course-renderer1/verification.json`: four headed Chrome runs, two per
  backend route. Median 16.7 ms, worst p95 16.8 ms, p99 20.9 ms; camera response
  at most 18 ms. All unchanged budgets pass. Requested WebGPU uses WebGL fallback
  on this host. At most 36 calls and 24,367 combined presentation bytes.
- Production build/type check and all 6,471 frozen reference inputs pass.

The first course check incorrectly expected two native L inputs to leave the
last-key byte unchanged. The corrected evaluation separates read-only rendering
from intentional keyboard mutation; it does not suppress that state difference.
