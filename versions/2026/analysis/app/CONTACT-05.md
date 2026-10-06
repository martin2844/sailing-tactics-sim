# CONTACT-05 — Restore original penalty behavior

2026-10-06. Replaces the independently introduced in-place penalty policy with
original responses while retaining the evaluated swept hull collision system.

The prepared penalty adapter now preserves the native opponent-timestamp
50-game-second grace test and the original human/NPC eligibility for the final
tacking branch. Private rule evaluation records which original movement branch
was selected; the authoritative worker calls that original reset/respawn/shift
routine once. Mark touch uses the original phase/leg/angle eligibility helper at
the collided object's centre. All course objects stay physically solid; gate
endpoints do not gain a direct mark-touch foul absent from the original helper.

Native prestart respawn consumes its original two RNG draws and resets the target
leg. Race-time shifting uses native distance/trig calculations. Same-clock speed
zeroing reproduces the native dynamics response at the post-integration contact
boundary. Contact episodes now count impacts rather than override native grace.
The solver caches the actual relocated position, preventing a false teleport
sweep on the next frame. Presentation uses the native penalty timestamp to show
that relocation immediately instead of interpolating it through other boats.

Evaluation:

- [81 native response/world checks](contact-og-response-2026-10-06/verification.json):
  whole-image/RNG comparison with direct original response branches, mark touch,
  prestart/racing boundary, port/starboard, clear astern, windward, both tacking
  movement branches, room, NPC-only respawn, mark gates, grace at 49/50 seconds,
  impact-time tack, no-contact identity and post-relocation caching.
- [152 solver checks](contact-og-solver-2026-10-06/verification.json), including all
  27 hulls, remain passing.
- [14 controls/depth checks](contact-og-controls-2026-10-06/verification.json) and
  [nine information groups](contact-og-information-2026-10-06/verification.json)
  pass, including held state/RNG and chart inspection.
- Three actual complete five-boat races pass:
  [Keelboat](contact-og-race-keel-2026-10-06/verification.json),
  [Tornado](contact-og-race-cat-2026-10-06/verification.json),
  [Island Optimist/championship reset](contact-og-race-island-champ-2026-10-06/verification.json).
  All four NPCs finish in each, then the unattended player DNFs and results open.
- Build/type checks pass; preservation verification reports all 6,471 pinned
  files unchanged.

Limits: this restores response and grace, not identical contact timing. Shape
proximity, swept blocking, spawn correction, impact-time overlap classification
and local AI clearance are explicit 2026 policies. Focused impact fixtures are
synthetic; the separate race checks exercise natural AI sailing. Full OG feature
parity and all course/fleet combinations are not claimed.

Graphics recheck did **not** complete five-repeat acceptance. Four completed
reference-route runs passed (median 16.7 ms, P95 16.8 ms, P99 at most 20.9 ms),
one completed run missed P99 (62.5 ms against the 50 ms budget), and two attempts
timed out after frame collection stopped while the worker continued. Those
windows were unfocused; there was no reported application error. Host CPU
contention was observed but cannot conclusively explain the outlier. Retained
[all-attempt summary](contact-og-renderer-attempts.json). Functional restoration
is accepted; a clean fresh smoothness certification remains open.
