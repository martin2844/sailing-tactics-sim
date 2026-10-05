# Repeatable simulator evaluation

Run from the repository root on the desktop used to play the simulator:

```sh
npm run eval:quick
```

The runner first checks its metrics, exercises physical 2010 HUD input,
compares both font atlas backends against native font pixels in a headed GPU browser, and
compares exact and smooth rendering through real Canvas engine traces. It then
opens one visible Chrome window at a time, alternating the editions across five
repetitions. Do not interact with these windows or run other benchmarks while
they are being measured. Each window closes automatically.

On Hyprland, the runner verifies that its owned browser window is on a visible,
powered monitor workspace and focuses that window before measurement when
necessary. It rechecks visibility after throughput and input probes. Chrome's
DOM visibility alone does not detect a hidden desktop workspace; switching
workspaces during measurement can invalidate a run. Other compositors are
explicitly recorded as lacking this additional visibility check.

The physical test window is 1280×1051 and the logical viewport is 1280×1050.
The odd window height avoids Chrome/Hyprland rounding an even requested height
to a neighboring pixel. Window dimensions must still match exactly; references
collected at the previous 1050-pixel window height need a new comparison run.

The quick suite measures a controlled 15-boat scenario at speed 10, followed by
each edition's normal default configuration with speed 10 selected. Defaults
have different fleet/course settings, so that comparison describes the product
experience rather than equal rendering work. The controlled scenario records
the remaining edition differences, including the original timestep.

Each run uses a fresh browser profile and a fixed startup clock for repeatable
random initialization. Setup drives original commands and paint boundaries;
the measured interval releases the normal browser scheduler. No simulation
state, random output, finish flag, or physics timestep is injected.

Results go into a new `versions/2010-en/analysis/evaluation/<timestamp>-<commit>/`
directory. Open `index.html` for the report; `report.json`, individual `run.json`
files, screenshots, correctness logs, loaded module hashes and a separate CPU
profile preserve the evidence. Existing runs are never overwritten. The runner
checks that the runtime source tree did not change during evaluation.
Exit code 1 indicates incomplete or invalid evidence; code 2 indicates a valid
evaluation that missed its measured performance targets. Code 3 means targets
were provisionally met but repeat variability requires confirmation, or the run
was explicitly diagnostic and did not miss its measured targets. A zero exit code does
not certify coverage that the report explicitly marks as unmeasured.

Measurements include paint duration, completed-content cadence observed at
requestAnimationFrame, simulation seconds per wall second, actual settings,
and trusted camera-click timestamps through the next changed completed frame.
The input and content observations are browser proxies: they do not measure
the physical monitor or its compositor's final presentation. CPU profiling runs
separately and is excluded from timing comparisons.

The initial relative target is p95/p99 cadence within 10% of 2002, with input
response compared separately and p95 strictly below 100 ms. Repeat ranges expose noise; a short passing run
does not establish full-race stability. Failed setup, unexpected controlled
settings, missing frames or runtime errors invalidate the evidence.

For the broader finite suite (including both full test suites and additional
speed, shoreline, fleet and post-start cases):

```sh
npm run eval:release
```

This command is a broader evaluation, not automatic certification: full-race
finish/long-session and physical display coverage are reported separately.
Correctness tests can run in CI; performance comparisons belong on a consistent
desktop with the same browser, viewport and GPU path.
For an exploratory run while other applications are using the machine, add
`--diagnostic --note 'description of competing work'`. Its report cannot claim
performance acceptance or serve as an acceptance-run regression baseline.

Saved baselines are validated before any browser work. Incomplete collections,
failed input checks, changed source pins, and different diagnostic modes or
frame budgets are rejected. The report pins the reference JSON by SHA-256.
When selecting fewer scenarios, only those matching scenarios are compared.

Useful options:

```sh
# Compare a subsequent 2010 change against saved results.
npm run eval:quick -- --baseline versions/2010-en/analysis/evaluation/PREVIOUS/report.json
# Shorter diagnostic cycle; two repeats is the minimum for a comparison.
npm run eval:quick -- --repeats 2 --frames 120 --no-profile --diagnostic
# Select a specific case from scenarios.js.
npm run eval:release -- --scenarios matched-round-lake-15-race
```

Use `TACT_CHROME=/path/to/chrome` on other machines. Chrome needs a functioning
desktop session for timing runs. `--base-url` selects a local source server; the
runner starts its own server if none is listening and closes only that server.
`--output` selects an unused evidence directory. Native reference tests use the
repository's preserved finite captures; this tool does not collect a new native
Windows reference automatically.

Recompute classification from a complete saved collection after improving a
metric or context check, without discarding or repeating its measurements:

```sh
npm run eval:reanalyze -- versions/2010-en/analysis/evaluation/PREVIOUS/report.json
```

This writes a new neighboring evidence directory, preserves the original,
and pins the updated analysis code. It rejects incomplete collections, changed
runtime/collector hashes, failed correctness or raw-run checks, and missing
input observations. Cross-edition native canvas heights are recorded separately;
they must remain constant within each edition, and same-edition regressions
require identical surfaces. Shared browser/GPU/window/viewport settings must match.

The improvement cycle is: reproduce the same scenario, inspect the separate
CPU profile, change one measured bottleneck, rerun correctness, then compare
new timing against the saved baseline. Keep an optimization only when the
physics/control checks still pass and repeated timings show an improvement.

For final Canvas drawing investigations, run a separate instrumented probe:

```sh
node tools/evaluation/canvas-diagnostic.js original,front-software,flush-one,pixel-copy,software-atlas
```

The `original` route uses the current player source, whose hash is saved in the
report. The alternatives force a software front canvas, flush one source pixel,
copy all pixels, or force software auxiliary canvases. Pixel copying changes
alpha composition and is an experiment only. These probes stop at paint
completion, may have incomplete rAF observations, and cannot qualify as timing
acceptance evidence. Keep their final-copy timings separate from normal runs.

Animation timestamps may repeat; observations retain the actual callback time
and completed frame ID. A decrease in either clock still invalidates the run.
The controlled speed-10 scenario turns off **Control → Slow Simulator if Foul
Likely** through its original command. Default scenarios retain this feature:
it can lower speed to 1 and impose the original 80 ms minimum frame duration.
