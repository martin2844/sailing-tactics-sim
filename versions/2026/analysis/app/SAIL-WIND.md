# Visible headwind response

The preserved painter's 0x41ce80 varies luffing sail lines using 0x41e000,
while the filled sail contour from 0x41bfb0 remains comparatively rigid. Directly
translating that into a shaded 3D surface did not give a readable unloaded sail.

The snapshot now exposes each boat's native wind direction (0x522b90), wind
angle (0x4fecc8), luff (0x512278), boom angle (0x4fe818) and tack (0x522ff0),
all at their original four-byte boat stride. Main and mast/boom primitives keep
distinct component IDs. Below 35 degrees to the local wind, the main and boom
weathercock toward the wind with bounded flutter, driven by the original
simulation time. The mast axis, sail foot and mast attachments stay anchored.
Hull and crew do not deform. Loaded sailing retains the native shape; original
trim/tack/heel/penalty geometry continues to arrive from the private worker.

This is deterministic presentation animation, not recovered 2010 cloth physics.
It consumes no RNG, writes no engine memory and stops with the native clock.
The source sail contour and its curved vertices remain the foundation.

Independent actual-mesh checks measured 0.381 boat units of headwind motion
between two display times, zero hull/crew movement, zero mast-axis movement and
no time-dependent change in a loaded 60-degree state. Whole native boundaries
were unchanged. Three close display frames were inspected. Seven native rig
fixtures, six private-worker packet comparisons and all ten declared frozen
whole-image/RNG/clock/shore boundaries across 5/15 boats passed. These headwind
screens are explicitly isolated presentation fixtures, not natural race traces.

Evidence: [wind response](sail-wind1/verification.json),
[native geometry](sail-native1/verification.json),
[engine parity](sail-worker1/verification.json).

Build/type checks and [four headed 15-boat Chrome runs](sail-renderer1/verification.json)
passed the unchanged budgets. Median changed-frame interval was 16.7 ms in every
run; worst p95 was 25 ms and p99 50 ms. Both requested backends were measured,
with WebGPU actually using its WebGL 2 fallback. Native WebGPU remains untested.
