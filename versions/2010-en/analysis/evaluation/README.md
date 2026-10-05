# Desktop smoothness evaluations

The Canvas font-backend fix and its evaluation are documented in
[Final Canvas drawing investigation](CANVAS-FIX.md). The latest
[five-repeat confirmation](2026-10-05T07-51-35-087Z-83bc7ef0/index.html)
measured 2,400 paint frames and 120 trusted camera responses. The 2010 port
measured 33.7–39.7 observed FPS versus 9.1–14.6 FPS for 2002 in the controlled
speed-10 scenario. Its median per-run p95 input response was 111.5 ms, so the
strict sub-100 ms target remains unmet. All 57 evaluation tests and the
HUD/font/Canvas correctness gates passed. Source hashes stayed constant.

The font-atlas change reduced the instrumented median final drawing call from
58.8 ms to 1.0 ms with identical initial/final simulation memory hashes.
Normal default measurements improved too, but retain the native automatic foul
slowdown and its speed-1 frame delay. Instrumented probes are excluded from
acceptance timing. Full-race and physical display coverage remain unmeasured.

## Earlier collection

The first completed collection is a loaded-desktop diagnostic, not an acceptance baseline.

- [Open the evaluated report](2026-10-05T00-06-33-132Z-5ee3bb36-reanalysis-2026-10-05T00-34-57-382Z/index.html) or read the [findings](2026-10-05T00-06-33-132Z-5ee3bb36-reanalysis-2026-10-05T00-34-57-382Z/FINDINGS.md).
- [Original collected evidence](2026-10-05T00-06-33-132Z-5ee3bb36/report.json) remains unchanged. Its initial context check rejected the editions' different native canvas heights. The derived report corrects that classification while requiring stable surfaces within each edition.
- The derived report pins its original JSON and analysis code by SHA-256. All 27 copied original artifacts are byte-identical. Supplemental profiles are separate from comparative timing.

Eight sequential headed GPU runs measured 960 paint frames and 96 trusted camera responses. The default speed-10 p95 content interval was 152.20 ms for 2002 and 189.25 ms for 2010; the measured smoothness target was missed. Other Unity/game and video-test workloads were active, so idle-desktop confirmation is still required.

The final evaluation-tool test run passed all 51 tests. HUD and real Canvas engine-parity gates passed during collection. No simulator runtime changed for this evaluation. Full-race finish, long-session stability and physical display latency were not evaluated.

See the [evaluation guide](../../../../tools/evaluation/README.md) to reproduce the cycle.
