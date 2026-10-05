# Mark guides and follow camera (EXT-01)

The native Mark lines option (command 32918 / `4da184`) now controls paired
red/green rays from distinct marks. L remains the independent local target guide
(`536490`). Bearings read the boat's native wind and close-hauled/downwind
angles; downwind angle is the original small offset, so its spread is 180 minus
that angle. A gray equal windward-distance guide is modern presentation, not the
legacy raster projection or a prediction of future current.

Follow boat places the camera behind the interpolated heading. Shortest-angle
interpolation already handles north crossings. Manual orbit takes ownership;
Follow boat restores automatic tracking.

Evaluation: [heading/mark/tack fixtures](follow-lines2/verification.json) cover
0/90/180/270/359/1 degrees, real native mark toggle and eight native tack paints.
Camera changes leave the entire memory hash, RNG, clock and shoreline unchanged.
[Native paired evaluation](follow-worker1/verification.json) checks five boundary
comparisons per fleet, including steering and tacking, against the frozen OG.
[Four headed renderer runs](follow-renderer1/verification.json) cover both backend
requests (WebGPU falls back to WebGL on this machine), 15 boats, camera response,
paused state isolation and the existing geometry/transport/cadence budgets.
This is desktop Chrome evidence; phone behavior and exact historical raster
layline projection are not claimed.
