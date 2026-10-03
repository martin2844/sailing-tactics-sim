# Retained-frame performance review

This records the initial diagnostic experiment before production changed.
The guarded helper is now part of the 2010 port; the original extended
routine remains the fallback. The final production comparison is recorded in
[production-pc53-distance-review.json](production-pc53-distance-review.json).
The loader detects the production implementation and exposes its original
extended routine for supplementary checks.

The dominant cost is the original nearest-waypoint distance scan. A diagnostic guarded PC53 distance helper reduced the measured complete frame from **8.66s to 1.25s**, with identical mutable image, RNG, names, sounds and all 1,469 ordered GDI requests. Production source and native fixtures remain unchanged.

| Diagnostic | Target frame 1 | Native output |
| --- | ---: | --- |
| Existing source, CPU sampled | 8,662.57ms | exact |
| Immutable input cache (4096 entries) | 5,613.19ms | exact |
| Immutable output WeakMap | 8,619.73ms | exact |
| Guarded PC53 distance | 1,247.13ms | exact |
| Guarded distance plus input cache | 1,722.98ms | exact |

These are single measurements with a concurrent proof process; they are evidence for prioritization, not a controlled browser benchmark. Target timing excludes startup, initialization and prior frame 0.

The V8 profile includes initialization and both frames: nearestWaypointDistance accounts for 12.62s of 13.91s in drawSimulationFrame. Float80.bitLength has 5.26s self time and fromNumber 3.79s. The scan executes817,028 distance calls across the observed frames.

Original 0x4662d0 performs two subtractions, an X binary64 spill, two squares, addition, threshold comparisons and FSQRT. Under original control word 0x027f, finite binary64-normal intermediates have the same 53-bit significand rounding as Number arithmetic. The diagnostic falls back to the original Float80 routine for other control words, nonfinite or subnormal intermediates, and underflowed zero products. It retains the original operand order and data-loaded thresholds.

The unchanged native distance/nearest/respawn/integration fixtures all pass:636 original calls,4 tests, exact full mutable bytes/RNG/m80/m64 returns and sounds. An additional 4,344 generated comparison checks across 027f/037f also match the original Float80 helper, including six preserved unsupported overflow/spill failures; these are supplementary JS checks, not new native calls.

Prefer the guarded distance candidate alone. The output cache barely reuses instances, and combining the input cache with the fast path adds Map/eviction overhead. Before production, review the proof, preserve fallback, and repeat all connected native numerical and retained-frame proofs plus the browser check.

Reproduce with the read-only loader:

```sh
node --experimental-loader ./versions/2010-en/tools/diagnostics/pc53-distance-loader.mjs --test versions/2010-en/tests/integration.test.js
node --experimental-loader ./versions/2010-en/tools/diagnostics/pc53-distance-loader.mjs versions/2010-en/tools/diagnose-retained-frame.js standard-course1-prestart 1
```

The final argument is two separate CLI arguments: profile name followed by frame index 1. Full timings, source/fixture hashes, sampling data and exact output evidence are in retained-standard-performance-review.json. Diagnostic loaders never write production source or fixture expectations.

Run the supplementary guard checks with the same loader and tools/diagnostics/check-pc53-distance.mjs.
