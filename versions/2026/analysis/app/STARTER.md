# Modern starter screen and native settings

The default `/` route opens a full-height sailing preview and a setup card.
The worker initializes a native race while its host scheduler stays paused.
The countdown does not advance while choosing settings or orbiting the preview.
Start race releases the scheduler after the engine, renderer and boat meshes
are ready. New race and the original N request return to a fresh paused setup.
Helm controls and global sailing keys are blocked while setup owns input.

Supported choices are Round Lake / Keelboat, five or fifteen boats,
Windward/leeward, Triangle or Gold Cup, and Light, Moderate or Strong wind.
Course and wind selections invoke the original menu controller followed by its
normal full paint. They do not assign physics fields from the UI. The worker
validates the native configuration and full-version mode at initialization.
The default keeps its audited exact paint sequence and initial hash checks.
Each new race starts a fresh worker with the preset's fixed seed; this is not
continuation of the previous race's RNG/weather stream.

The original keyboard/setup panels remain available on diagnostic `?manual`
and `/spike/` routes. Existing forecast/help/charts in the sailing view retain
their native handlers. Full modern forecast/current settings, replay, sound,
other boats/venues and mobile acceptance remain separate tracker tasks.

## Evaluation

- [Reviewed starter checks](starter-reviewed/verification.json): eight checks
  cover the audited initial whole-state hash, held countdown, blocked helm,
  trusted Start, New race, real keyboard select input for fifteen boats /
  Triangle / Strong wind, N, and visibility-listener ownership. A deliberately
  retired worker error callback cannot stop a newer race. That is an isolated
  callback fixture, not a claim to have reproduced an actual worker crash.
  The visibility check exercises the listener; it is not physical device or
  OS background-tab acceptance. [Inspected starter image](starter-reviewed/starter.png).
- [Native settings matrix](settings1/verification.json): all 18 combinations
  match original whole-image SHA-256, frame, time, clock, RNG and retained shore
  at initialization and after eight real paints (36 paired boundaries). The
  reference uses independently listed native menu IDs, not the UI helper.
- [Keyboard regression](starter-hotkeys1/verification.json): 79 trusted keys
  and subsequent paints match the original native state, including setup and
  compatibility panels. Frozen CapsLock drawing still has its previously
  documented comparison exception; native key mutation and the candidate
  repaired paint/GDI contract are tested separately.
- [Lifecycle](starter-lifecycle2/verification.json): all nine checks pass,
  including actual changing RGBA frames, paused camera isolation, repeated
  pause/resume, five/fifteen fleet restart and graphics-loss recovery.
- [Performance](starter-renderer-final/verification.json): ten headed Chrome
  runs, five each for WebGL 2 and requested WebGPU (actual WebGL fallback).
  All unchanged budgets pass. Worst median 16.7 ms, p95 16.9 ms, p99 33.4 ms;
  camera response at most 19 ms, combined presentation 24,437 bytes, 36 calls.
  One isolated 379.1 ms frame interval occurred in the first WebGL run with
  no visibility change; submit cost at that frame was 1.4 ms. Its cause is not
  established. It is retained, not excluded; the other nine run maxima are
  at most 50 ms. These measurements do not guarantee a stutter-free session.
- Production build/type check and all 6,471 frozen reference inputs pass.

The first concurrent lifecycle attempt timed out during a CDP evaluation.
The [failure](starter-lifecycle1/failure.txt) is retained; the isolated rerun
passes. Its cause was not established. The harness now retains completed
checks and current app/visibility state on future failures.

Final review added generation guards for retired worker error and camera
callbacks, preventing an obsolete setup attempt from affecting a newer one.
The focused starter evaluation was rerun after this guard change; it does not
alter the happy-path engine or renderer measured in the performance series.
