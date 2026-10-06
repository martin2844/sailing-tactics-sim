# Native environment and presentation (EXT-06)

The worker retains original wind, gust respawn, current, bathymetry, grounding
and wave-motion calculations. The modern scene reads the five native gusts and
original shoreline contours. Local true wind, depth in native feet, current
speed/direction and grounded status are displayed without recomputing physics.
Gusts are restrained translucent native-position/radius patches. Low-poly wave
crests are deterministic artwork driven by native wave condition, wind and clock;
they add no forces, RNG draws or extra boat heel. Pause/freeze holds their phase.

Named venue land uses the native 72-point polygon arrays; imaginary shore,
lake/island and advanced shoreline families use their actual generated contours.
The old illustrative coast/trees are replaced. Terrain arrives once per native
configuration, including Next race; restart disposes it. A bounded outer ocean
surface prevents rectangular water endings on long courses. An adaptive camera
near plane preserves depth precision in distant overview and close boat views. Fine
water facets are hidden beyond 5,000 units to avoid distant aliasing; the plain
ocean remains. `overview-final1` verifies the final Around Block Island view.

`environment9/verification.json` covers nine native venue/coast families and four
controlled private depths each. Original dynamics/current determine grounding
and speed, with complete private-image/RNG parity, complete master boundaries
unchanged, native terrain/gust/instrument equality and paused camera/wave
isolation. At 1 foot the native keelboat reports status 10 and 0.1 knots. The
controlled Round Lake current falls from raw 4 at 100 feet to 2 at 50 and 0 at 1.
This is deliberately a controlled diagnostic, not a naturally sailed grounding
claim. Coastal chart adapters and original-oracle declarations are documented in
`CATALOG.md`; frozen preservation inputs remain unchanged.

Physical Pixel 11 validation is deferred as requested. Default desktop Chrome
performance and full player-journey review are recorded separately in EXT-07.

2026-10-06: the [player fixes](PLAYER-FIXES.md) replace the flat cap with native-outline
faceted relief, beaches, trees, rocks and a lighthouse. Background venue sampling
features are no longer extruded as additional land when excluded by the native
depth sampler. Island course spacing and AI shore routing now intentionally improve
the inherited unsafe layouts; the original shoreline/physics sources stay frozen.
