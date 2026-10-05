# Race start/finish presentation (EXT-03)

The existing paused starter is now paired with a proper modern results card.
A finish is detected from original `4fe638 + boatId*4`, the finishing-order value
written by `advanceRaceTarget`. It is never inferred from time or scene distance.
Your placing appears immediately, with a Watch fleet action while other boats
race; final results appear when the native race is complete. Names use the same
native/custom display identity as the scene. A placing above fleet size is
retired, not a fictitious successful finish.

The worker now performs the next original results paint before stopping at a
race finish. Original `drawResultsScreen` owns scoring writes on that paint;
previously pausing at the finishing simulation paint skipped those writes.
Native score cells and completed race count are exposed read-only for the event
controller. No score formula replaces the original routine.

[Chrome evaluation](results1/verification.json) invokes the original final-leg
transition for a deliberately reversed finish order in a **private memory/RNG
clone**, then invokes the original results drawing routine. Native winner score
is 100; other scores are position × 101, retaining the original fractional
ordering behavior. The modern UI displays that native finish packet correctly
and master memory/RNG/shore remain unchanged. This is a controlled transition
fixture, not evidence that an entire race was sailed naturally. Full event
journey evaluation remains EXT-04/07. Starter evaluation remains in STARTER.md.
