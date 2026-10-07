# Playback speed and global gameplay shortcuts

The2026 setup and sailing selectors use **1×,2×,4×,8×,16×,24×,28× and32×**.
There is one public timing system, defaulting to1× real time. Saved multipliers
survive reload/restart. Saved OG-mode preferences migrate to1× because native
level numbers were not wall-time multipliers; the old native speed-preference
key no longer influences the2026 app.

Space temporarily selects1× and restores the retained selected pace on the next
press, including while paused or reading a coach/course panel. Repeats from a
held Space key do not toggle repeatedly. Selecting a different rate ends the
temporary reduction. Page Up/Down traverse the ordered list and clamp at1×/32×.
The dropdown and saved preference retain the selected fast pace while the HUD
shows “1× · Space restores…”. F remains pause.

During sailing, unmodified gameplay keys take focus from selectors, buttons and
checkboxes, prevent their native action and execute through the game controls.
Enter steers instead of activating a focused toolbar button. Open native pickers
are dismissed without changing their selection or firing change; the selected
label and speedometer needle remain intact. Chrome's customizable picker does
not close on blur and has no close-picker API, so the helper briefly rebuilds
its menu/listbox type and restores the selected value.

Space is reserved for pace even while a panel holds the race. Escape or Return
to sailing closes panels. A sailing shortcut from a held panel returns to the
game and executes through the same runtime control guard. Manual pause still
rejects boat/sail mutations; no movement is queued for unpause. Text/name entry,
IME composition and browser modifier shortcuts retain their normal behavior.
Space on the setup Start button changes pace without clicking Start.

The public2026 Space action uses a dedicated `toggle-pace` message. The private
original/reference key API retains contextual N/Space/panel behavior. This keeps
reference clients and original panel-close actions separate from public pacing.

The same lightweight speedometer SVG appears in both closed controls and every
open option. The face stays fixed; the needle progresses across the eight rates.
There are no timing groups or clock icons.

## Scheduling, workload and numerical ownership

PlaybackPacer owns wall-time deadlines. The multiplier also selects an existing
OG numerical preset, so fast-forward performs fewer, larger numerical steps:

| Multiplier | OG numerical preset |
| --- | --- |
|1×|6|
|2×|7|
|4×|9|
|8×|11|
|16×|13|
|24×|14|
|28×|14|
|32×|15|

1× retains the fine preset6 timestep. Space temporarily applies that preset
without changing the retained selected preset, including in checkpoints/replay
and setup matching. Fast-forward uses the recovered speed-dependent formulas;
AI, wind/current, steering, dynamics, course progress and penalties all run for
every boat on every step. Geometric contacts sweep between positions. No boats
or completed numerical steps are skipped. Different presets intentionally give
different trajectories; exact image/RNG parity is asserted for identical native
preset, ordered inputs and step count.

Each completed step schedules against cumulative game-time progress divided by
the active wall-clock rate. Work and ordinary timer jitter are accounted for;
wall-time debt over250ms is discarded to avoid unbounded catch-up after stalls.
An overloaded host can run below target without changing the selected pace.

Every next tick enters through a MessageChannel task, including after a timer
expires. This avoids Chrome's4ms nested-timer clamp on chained short timers.
Stale-token cancellation and pause checks remain on the message receiver.
Display state is published at up to60Hz, or30Hz at16× and above. Three.js still
draws and interpolates at display refresh; every numerical step still runs.
Explicit controls, pause/resume, diagnostics and final results publish immediately.
Private reference scheduling retains its original per-step publication.

The private2.2MB camera image is reused and fully refreshed from the master on
each snapshot. Camera writes remain isolated from authoritative memory. Snapshot
preparation cost (`snapshotWorkMs`) is reported separately from numerical work.

PlaybackRateMeter observes game seconds per wall second in two-second windows
with smoothing and hysteresis. It never changes deadlines, selection or physics.
Sustained processing limits show the achieved rate in the HUD. Holds, rewind and
pace changes rebase samples rather than displaying zero speed. The integer game
clock can differ from fractional time by less than a numerical step; fractional
time is the rate-evaluation metric.

Settings without a playback field retain original scheduling at the private
worker boundary. Actual2026 UI settings always provide a multiplier. Checkpoint
and replay belong to EngineRuntime; pacing is separate host metadata.

## Assistance and cosmetic motion

Original automatic foul slowdown remains available. It can temporarily select
numerical level1, with an explicit “Foul slowdown” label and active1× in the host.
Space restores the selected multiplier and its mapped native preset with the original
four-game-second assistance grace. No penalty is cleared by a pacing change.
Private legacy reference clients retain their original delay/divisor behavior.

AnimationClock advances extra headwind/boom flutter with elapsed wall time.
Physical trim, native cloth contours, heave, gust locations and other environment
presentation follow numerical game state. Host/native pause, held panels,
starter/results and hidden tabs hold cosmetic time. Resume does not accumulate
the held interval. Renderer callbacks never advance authoritative gameplay/RNG.

## Evaluation

- [30-boat rate sequence](../analysis/app/variable-step-fleet-2026-10-07/verification.json)
  asserts all eight multipliers within5% in rendered Chrome with geometric
  contacts enabled. Requested32× achieved31.30× over the short sample.
- [Full32× race](../analysis/app/fast-forward-race-2026-10-07/verification.json)
  checks sustained throughput, prestart, natural AI progress/arrivals,
  DNF/results, championship next race and Space preset restoration.
- [Playback controls](../analysis/app/variable-step-playback-2026-10-07/verification.json)
  covers all presets, held charts/coach, pause, replay, Page keys and preferences.
- [Global focus controls](../analysis/app/variable-step-hotkeys-2026-10-07/verification.json)
  uses trusted Chrome key events over open/closed selectors, buttons and panels.
- [Swept contacts](../analysis/app/variable-step-sweeps-2026-10-07/verification.json)
  checks152 fast crossings, rotating hulls, compound hulls and dense placement.
- 50 focused numerical/cutover tests pass, including full-image/RNG comparison
  after precision restoration at every mapped preset, tacks/jibes, checkpoints,
  warning grace and scheduling. Type check/build pass. Local review of preset
  selection, temporary pace ownership, warning recovery and lifecycle routes
  found no remaining findings.

These are Chrome desktop observations on this machine. Achieved rate still
appears in the HUD if a device cannot meet the target. Pixel evaluation remains
pending. Earlier fixed-preset6 receipts are historical measurements; their
high-rate limitations are superseded by this explicit variable-timestep policy.

See [fleet performance](fleet-performance.md) for the calculation optimizations
and earlier fixed-step comparison.
