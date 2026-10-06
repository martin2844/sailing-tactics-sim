# ENG-03b-5 — Extract wave/heave motion

2026-10-07. A renderer-free typed environment phase now owns wave proximity,
raw previous-distance copying, cooldown, heave phase/amplitude and sound events.
The compatibility mapper supplies exact arithmetic and nearest-wave values.
This state is gameplay relevant: the existing dynamics reads heave for downwind
heel correction. It cannot be dropped as visual decoration.

The focused comparator checks 672 combinations against the original wave
function: wind-angle thresholds, waves, player count, pace divisor, phase wrap,
countdown and mute state. Full memory and ordered sound events match.

[69 paired current-2026 boundaries and ten frozen 2010 boundaries](cutover-waves-2026-10-07/verification.json)
match every image byte, RNG/time/frame and retained shore context, with original
lifecycle entries guarded to throw. [Phase ledgers](cutover-waves-2026-10-07/phase-ledgers.json.gz)
remain untruncated. All eighteen current cutover tests pass; build/type checks,
[14 pause/input/depth checks](cutover-world-controls-2026-10-07/verification.json)
and preservation verification (6,471 files) pass. The [complete island championship regression](cutover-world-island-champ-2026-10-07/verification.json) also passes: four AI finishes, DNF cutoff/results and next-race reset.

World invocation and wave-position regeneration remain in the compatibility
traversal. The remaining raster/shared-RNG contract has an explicit user question
pending: preserve exact old seed trajectories or separate gameplay randomness
from cosmetic drawing while retaining the numerical model. No such behavior
change has been made without that answer, and complete offscreen independence
is not claimed.
