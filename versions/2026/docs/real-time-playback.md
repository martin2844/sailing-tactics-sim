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

PlaybackPacer owns transport deadlines, not sailing arithmetic. Ordinary clock
mode uses recovered numerical preset6. AI, wind/current, steering, dynamics,
course transitions, penalties and finishing-window calculations retain their
existing numerical routines. No numerical steps are split or skipped to satisfy
the display. With identical native preset, ordered inputs and step count, the
numerical image and gameplay RNG remain the regression contract.

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
Space restores the selected multiplier and native preset6 with the original
four-game-second assistance grace. No penalty is cleared by a pacing change.
Private legacy reference clients retain their original delay/divisor behavior.

AnimationClock advances extra headwind/boom flutter with elapsed wall time.
Physical trim, native cloth contours, heave, gust locations and other environment
presentation follow numerical game state. Host/native pause, held panels,
starter/results and hidden tabs hold cosmetic time. Resume does not accumulate
the held interval. Renderer callbacks never advance authoritative gameplay/RNG.

## Evaluation

- [Global keyboard/focus receipt](../analysis/app/global-hotkeys-final-build-2026-10-07/verification.json)
  verifies18 groups with actual Chrome keys over buttons, checkbox, closed/open
  selectors, starter and coach/course screens. Selected value/gauge, repeat
  suppression, text entry, Page keys, Q, Enter and T/J/I/O are covered. Paused
  whole-image/RNG boundaries remain identical.
- Its separate scheduling negative control compares100 chained1ms ticks with
  message-mediated ticks. This isolates browser timer throttling from simulation
  calculations; it is not a full-game throughput measurement.
- [Playback receipt](../analysis/app/responsive-playback-final-2026-10-07/verification.json)
  observes all eight multipliers with5 Optimists, checks effective/selected/native
  rates, visible processing limits, Space/F/Page, held R/? clocks/meshes,
  coach/replay and preference reload/migration.
- [Fleet-load receipt](../analysis/app/playback-load-2026-10-07/verification.json)
  observes30 Keelboats at requested32×, checks the effective-rate readout and
  unchanged selected pace/native timestep, and verifies exact pause under load.
- All44 numerical/cutover tests pass, including eight pacing deadlines, Space
  toggle, warning recovery, measurement/holds/rewind, rate clamping and unchanged
  numerical/RNG trajectories. Type check and build pass.

The5-Optimist windows tracked1×–16× closely and reached31.59× at32×. The24×/28×
windows crossed more expensive states and achieved12.58×/19.33×. High rates can
still be limited by the available processing budget. The UI reports this instead
of silently changing selection or skipping physics. These are bounded Chrome
observations, not every fleet/venue or a mobile-device certification.

Earlier receipts remain historical evidence: [prior consolidated controls](../analysis/app/consolidated-speed-final-2026-10-07/verification.json),
[original playback controls](../analysis/app/playback-final-2026-10-07/verification.json),
and [cosmetic clock isolation](../analysis/app/cosmetic-clock-2026-10-07/verification.json).
Their earlier public modes/Space semantics are superseded by this document.

Dense-fleet calculation cost is addressed in the
[fleet performance follow-up](fleet-performance.md); earlier load observations
above predate those optimizations.
