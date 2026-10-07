# Spawn, rules and controls review

2026-10-07. Reviewed the independent runtime cutover and current player fixes
against preserved2010 handlers, numerical routines and actual Chrome workers.
No remaining verified finding in the changed spawn/control/coach/replay paths.
This is bounded correctness acceptance, not complete OG feature parity or a new
performance certification.

## Findings fixed

| Severity | Trigger and wrong outcome | Fix and evidence |
| --- | --- | --- |
| High | Default Keelboat spawn positions were distinct but two hulls overlapped. The second live geometry step assigned a port/starboard foul; its retained penalty timestamp made the sail black for30game seconds even after the status cleared. | Deterministic hull-aware placement at initialization/restart/next race, water/depth and obstacle clearance, original start-side preservation, synchronized position aliases and replay rebasing. Actual mesh fills and penalty timestamps pass nine boot/four-step fleet/class cases. Genuine later collisions remain enabled. |
| Medium | Space only selected speed1; there was no saved user pace or full OG selector. | All15 recovered speed commands are exposed in setup and the footer. Space alternates1/selected; F pauses. Selected pace is separate from temporary slowdown and is retained in checkpoints, new races and validated local preferences. |
| Medium | Page Up/Down were blocked while held, changed native pace did not update the modern setup preference, and the live speed selector could retain shortcut focus. | The held-control route permits speed keys. Published selected pace updates setup and persistence; selecting a live pace returns focus to sailing. Trusted Page Up, Space restore and browser reload pass. |
| Medium | Integration erased the heel and sheltered-wind coach warning cells. Prestart returned before telemetry could reconstruct heel advice. | Reconstruct the exact heel condition before the sampling gate; retain the actual human sheltered-wind producer across integration and clear it before each fresh step. Real heeling steps and a controlled original spatial-wind sample pass; no venue-based warning is invented. |
| Medium | The host rejected coach access after results, making OG finished-race advice inaccessible. | The private information desk remains available after results. Trusted Y on a naturally completed island race opens advice without changing the live image/RNG/clock. |
| Medium | Public Backspace was blocked while paused, while diagnostic raw keys bypassed that guard. Rewinding a completed race also needed to discard its modern event receipt. | Public replay is permitted while held; checkpoint restoration resets finish-window/DNF state and contact history. Only the active race receipt is removed, preserving earlier championship races. Trusted post-result Backspace and a two-race receipt regression pass. |

Restoring speed during automatic foul slowdown also retains the OG's mode2
four-second grace. The paired reproduction with a new warning one second later
remains at speed10 in both implementations.

## Rules checked clean

- **Starboard exists:** the public helm button turns the retained rudder in the
  correct direction; port turns it back. Actual swept opposite-tack contacts
  assign code4 to the port boat and protect the starboard boat, matching the
  frozen2010 classifier before and after the gun. Original49/50-second opponent
  grace is preserved. No rule inversion or replacement was justified.
- **Start checks run:**15 controlled positions exercise the original early-side
  recall window and behind-line/outside negatives. OG signed start distance uses
  its recovered radial approximation and narrow recall window; this is not a
  new exact continuous line-crossing algorithm.
- **Marks, laps and finishes run:** controlled physical waypoints advance all
  seven courses, four supported gates and repeated laps to native finishing.
  These are proximity/target transitions around marks, not a requirement to
  touch a buoy. They do not certify every naturally sailed rounding path.
- **Natural island progression runs:** two separate five-Optimist races produce
  four AI arrivals, then player DNF at the requested20-minute deadline. One
  verifies actual finished-race Y/Backspace rollback; the other verifies the
  championship next-race reset and retention of completed scores.

## Acceptance evidence

| Gate | Evidence |
| --- | --- |
| Typecheck/build and35 focused numerical/transition tests | [Build receipt](../analysis/app/rules-review-2026-10-07/build.txt); [test receipt](../analysis/app/rules-review-2026-10-07/unit-tests.txt) |
| All27 hulls × fleets5/30: clearance, aliases, idempotence, no RNG draw | `tools/independent/spawns.test.mjs` |
| Chrome15 pace choices, Space/F/PageUp, preference reload, both helm commands, nine actual startup meshes, held replay | [27 checks including speed-selector focus](../analysis/app/player-regression-focus-final-2026-10-07/verification.json) |
| Focused Chrome focus/pause/panel and depth controls | [15 control groups](../analysis/app/speed-toggle-controls-2026-10-07/verification.json) |
| Every boat/venue,56 island course/wind cases, short/gated courses;30 live steps/case with authoritative Canvas/bitmap guards | [131 cases](../analysis/app/spawn-selection-accepted-2026-10-07/verification.json) |
| Actual swept right-of-way versus frozen classifier | [Six fixtures](../analysis/app/rules-review-2026-10-07/starboard.json) |
| Early starts and all course/lap/gate/finish transitions | [Controlled progression](../analysis/app/rules-review-2026-10-07/progression.json) |
| Natural finished-race coach/replay | [Island race](../analysis/app/rules-island-replay-2026-10-07/verification.json) |
| Natural DNF championship to next race | [Championship transition](../analysis/app/spawn-island-championship-2026-10-07/verification.json) |
| Paired private observation cannot change future authoritative state | [Private presentation purity](../analysis/app/purity-rules-accepted-2026-10-07/verification.json) |
| Preserved/non2026 tracked files unchanged from72116dc | [12,559 file comparisons](../analysis/app/rules-review-2026-10-07/preservation.json) |

Reviewed speed validation/mapping, preference fallbacks, selected versus active
pace, replay checkpoint ownership, spawn callers and position aliases, private
depth sampling, transient warning producers, results/info pause restoration and
event receipt ownership. Cleared generated/assets/preservation files from
implementation review; preservation comparison verifies they were untouched.

Two evaluation runs were invalidated by rebuilding their served assets midway;
another parallel run had an asset-fetch/CDP timeout. Those failed attempts remain
in analysis directories and are not acceptance evidence. Final gates use a stable
build; startup coverage is bounded and does not imply every cross-product race
has been completed or performance tested.

## Remaining OG functionality

The [updated OG inventory](og-functionality-audit.md) and root `PARITY-01..07`
tasks remain the authoritative backlog. Audio cues, complete trim/air/header/HUD
feedback, tactical tracks/chart point sampling, advanced race setup/preferences,
tutorial navigation, design/custom venues, mouse steering and full two-player
hosting are not all implemented. This review did not relabel translated backend
handlers as completed user-facing features.

The numerical foundation is translated JS, not the Windows executable. The
authoritative original screen lifecycle is gone. Read-only recovered boat and
guide/information adapters remain, and modern geometry contacts/finish-window/
island policies are declared gameplay extensions.
