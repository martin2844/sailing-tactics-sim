- Eight complete unprofiled runs (960 paints) and 96 trusted camera response checks; HUD and real Canvas engine-parity checks passed. No simulator error was reported in these runs.

- Loaded desktop diagnostic: Unity/game and video test workloads were observed. These results are not a clean-machine baseline or a physical monitor latency measurement.

- Default speed 10: median observed content FPS 7.05 (2002) versus 5.69 (2010). Median per-run p95 content interval 152.20 ms versus 189.25 ms (24.3% worse); p95 input response 456.35 ms versus 595.55 ms. Performance targets were not met.

- The separate final 2010 profile attributed 86.5% of sampled time to native drawImage calls. Its scene callback averaged 22.45 ms/paint and physics 2.10 ms/paint. Supplemental profiles localize the dominant native drawing call to the final visible Canvas blit. Sampling alone does not distinguish rasterization, copy, flush or GPU waiting.

- Next controlled experiment: isolate the visible Canvas/presentation path and viewport override under the same recorded workload, followed by an idle-desktop repetition. Then reduce the remaining 2010 scene-rendering cost. No simulator runtime was changed for this evaluation.

- Native canvas sizes differ: 2002 is 1024×730 and 2010 is 1024×723. Browser, GPU, window, logical viewport and requested simulator dimensions match; native surfaces remain stable across repeats. Course length/timestep also differ, so the common-menu case is not identical cross-edition physics or geometry.
