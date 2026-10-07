# Consolidated playback speed and cosmetic time

2026-10-07. Both2026 speed selectors now use exactly **1×,2×,4×,8×,16×,24×,28×
and32×**. There is one public timing system, defaulting to1× real time. Saved
multiplier choices survive reload/restart; old saved OG-mode preferences migrate
to1× because native level numbers were not time multipliers. The old native
speed-preference key no longer influences the2026 app.

Space always sets the selected and active rate to1×, including while paused.
Repeated presses stay at1×. F remains pause. Page Up/Down traverse the ordered
list and clamp at1× and32×. Space still dismisses a held original panel in that
context, and still starts a race after original N/setup.

The same lightweight speedometer SVG appears in both closed controls and every
open option. Its face stays fixed; the needle progresses from left to right
across the eight rates. There are no timing groups or clock icons.

## Numerical and wall-time ownership

`PlaybackPacer` owns transport deadlines, not sailing arithmetic. Ordinary clock
mode uses the recovered numerical preset6, the level whose motion the user
preferred. AI, wind/current, steering, dynamics, target transitions, penalties
and finishing-window calculations retain their existing numerical routines.
There are no split, skipped or extra numerical steps to satisfy the display.

At each completed step, the worker schedules against cumulative game-time
progress divided by the selected wall-clock rate. A faster machine waits until
the deadline instead of accelerating the game without a limit. Work/ordinary
timer jitter is accounted for. Large wall-time debt over250ms is discarded;
an overloaded or stalled host can run below its selected target, without a long
catch-up burst or skipped sailing state.

Display snapshots are emitted at up to60Hz, independently of numerical step
frequency. This avoids cloning/extracting/transporting a full display state for
every high-rate step. Explicit controls, pause/resume, diagnostics and completed
results publish immediately. Numerical steps are never dropped by this display
limit; private reference scheduling retains its original per-step publication.

The published clock is the native game clock. Its integer display can lead or
lag by a fraction of a numerical timestep; fractional wall/game measurements
are the acceptance metric. Pause, freeze, information/legacy panels, tab hiding,
replay and race transitions rebase timing explicitly. A new race clears a
temporary1× reduction and starts at the selected rate.

Settings without a `playback` field retain original scheduling at the worker
API boundary. This preserves numerical diagnostic/reference clients. Actual
2026 UI settings always provide an explicit multiplier choice. Original speed
commands remain a private reference/diagnostic compatibility route; the UI does
not offer them. Checkpoint/replay still belongs to the
independent runtime; playback is host scheduling metadata.

## Assistance and input

Original automatic foul slowdown remains available. It can temporarily select
the original numerical level1, and clock mode displays an effective1× reduction.
An explicit Space reset or Page speed action restores numerical preset6 with the
original four-game-second assistance grace. The owned `restoreSpeed` operation
does not dismiss a held panel. Ordinary clock-rate changes never leak into
original Page Up/Down numerical handlers, including on R/? held screens.

This preserves the original assistance transition as an explicit exception to
ordinary preset6 operation. No penalty is cleared or boat relocated by a pacing
change. Private legacy reference clients retain their original delay/divisor and grace behavior.

## Cosmetic motion

`AnimationClock` advances extra headwind/boom flutter with elapsed wall time,
independent of game-clock acceleration or snapshot/model packet frequency.
Pause/resume samples rebase rather than adding the held interval. Main-thread
pause policy includes host pause, native freeze, held legacy/information screens,
starter/results and hidden tabs. Held legacy screens no longer continuously
request identical numerical images to create new random cosmetic meshes.

Physical trim, boom state, native cloth contours, heave, gust locations and other
environmental presentation continue to follow numerical game state. Only the
additional cosmetic flutter phase uses the new clock. No renderer callback
advances authoritative gameplay or its random streams.

## Current evaluation

The consolidated-speed evaluation uses every multiplier in actual Chrome,
verifies both menus and monotonically increasing needles, repeated Space reset,
F pause with exact boundary equality, held R/? screens, coach, replay, Page-key
clamping, preference reload/migration and trusted native-picker selection.

[Current receipt](../analysis/app/consolidated-speed-final-2026-10-07/verification.json).
Rate windows are5 seconds with5 Optimists on this host.1×–16× follow the selected
target closely. The32× window reached31.57×. The24× and28× windows reached
10.59× and16.66× respectively in more expensive race states; throughput can
therefore vary with AI interactions even at a higher selected rate. These are
requested wall-time rates, not a guarantee that every fleet/venue/hardware can
execute the recovered numerical kernels fast enough. The test records effective
playback and native pace separately so an assistance slowdown cannot masquerade
as a throughput measurement.

[Icon/layout regression](../analysis/app/consolidated-speed-icons-2026-10-07/verification.json)
checks the shared family, boat/course/compass changes, native keyboard selection,
setup state isolation and four desktop Chrome viewport widths.

All42 focused numerical/cutover tests pass, including all eight pacing deadlines,
permanent Space reset, rate traversal/clamping and unchanged numerical/RNG
trajectories at the same timestep and ordered inputs.

## Earlier evaluation and review

The following receipts describe the preceding implementation, including its
then-public OG modes and Space toggle. Those UI behaviors are superseded above.

- All41 focused cutover/independent tests pass, including jitter/deadline rates,
  holds/rewind/stalls/precision/reset, original15-level encoding/scheduling,
  automatic slowdown restoration and fixed numerical trajectory/RNG equality.
- [Chrome public controls](../analysis/app/playback-final-2026-10-07/verification.json)
  passed11 control groups: setup/live speed, Space/F/Page keys, held R/? clocks
  and meshes, information hold/resume, replay, original modes and preference
  reload. Five-second Optimist windows observed0.98×,1.95×,3.92× and7.81× at
  requested1/2/4/8×, including message-stop overhead. Cosmetic elapsed time
  stayed close to wall time at all four choices.
- [Additional1× profiles](../analysis/app/playback-profiles-2026-10-07/verification.json)
  observed0.999× for15 Optimists,0.997× for5 Keelboats and0.987× for5 offshore
  racers on a distance course. These are short Chrome observations on this host,
  not a hardware-independent performance guarantee.
- [Actual scene/mesh clock isolation](../analysis/app/cosmetic-clock-2026-10-07/verification.json)
  rendered identical extra-headwind geometry at0.8s elapsed with game times−100
  and1000. Reintroducing the old game-time phase changed the mesh, verifying the
  negative control. The authoritative image/RNG/clock remained unchanged.
- [Original-control regression](../analysis/app/playback-legacy-controls-2026-10-07/verification.json)
  passed27 checks including all15 original pace choices, Page keys/Space/reload,
  both helm directions, clear white spawns and paused replay.
- [Same-worker new-race reset](../analysis/app/playback-restart-2026-10-07/verification.json)
  uses selected8×, temporary1× and public N/Space initialization to check that
  the new race returns to8× with numerical preset6.

The big-review pass found held-screen Page routing, held cosmetic pause,
automatic-assistance acceleration and temporary precision across new races;
all were fixed and covered through their callers. No duplicate-step or stale
timer-token failure remained in the reviewed paths. Real time and original
mode defaults, persistence, pause/replay ownership and render independence were
checked together. This is bounded correctness/rate evaluation, not a new
full-race cross-product or headed/mobile smoothness certification.
