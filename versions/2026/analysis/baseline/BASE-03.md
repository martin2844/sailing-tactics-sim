# BASE-03 evaluation — complete original races

Completed 2026-10-05. Accepted for this task: both candidate Keelboat / Round
Lake / windward–leeward setups reached natural results after every boat
finished. This verifies the existing 2010 reference, not a playable 2026 edition.

## Method and controls

`tools/race-baseline.mjs` starts its own ephemeral local server and fresh,
visible Chrome with the hardware GPU. The final collector uses the BASE-07
1280×1051 physical window and 1280×1050 logical viewport at DPR 1. Earlier
five-boat captures used a 1280×1050 physical window with a 1280×907 content
viewport; their actual metadata is retained. These are correctness runs, not
performance runs or measurements of physical screen latency.

The host seed is `Date.now() = 1546300800000`. Original setup commands are:
`32799` Round Lake, `32816` Keelboat, `32789` windward–leeward, `32806` five
boats or `32808` fifteen boats, and `32909` speed 10. Trusted Space key events
start the original race and dismiss its original forecast. The original
automatic foul-slowdown setting is disabled through menu `32984` when needed.
Menu `32850` selects original automatic sheeting, and `32973` selects original
speed 15 for the diagnostic race. This is not a “15× real time” claim or the
proposed 2026 default pace; BASE-05 audits those meanings.

The diagnostic pilot reads native boat coordinates, heading, wind and next
target, then calls original port/starboard ten-degree commands `32842`/`32841`.
It sends at most one such command before each paint and keeps a frame-indexed
input log. It is a test pilot, not new sailing AI. No position, time, RNG state,
leg, finishing position or result flag is assigned by the collector.

The scheduler gate retains each actual scheduled paint callback. Each step
executes the complete original numerical prefix, rendering, pixel reads,
timing-host reads and cleanup. Positive native timer delays still occur before
a callback can be held. This bounds observation at paint boundaries; it does
not replace the timestep, skip graphics or certify uninterrupted wall-time
play. The canonical native surface remains 1024×768, as in the reference host.

## Accepted evidence

| Capture | Original race paints | Final clock | Human place | Finishers | Results rendered |
| --- | ---: | ---: | ---: | ---: | --- |
| `BASE-03-race-5-a` | 1891 | 2319 | 3 | 5 | Flag reached; capture predates extra results paint |
| `BASE-03-race-5-b` | 1891 | 2319 | 3 | 5 | Yes |
| `BASE-03-race-5-c` | 1891 | 2319 | 3 | 5 | Yes |
| `BASE-03-race-5-d` | 1891 | 2319 | 3 | 5 | Yes |
| `BASE-03-race-15-b` | 2288 | 2842 | 5 | 15 | Yes |

Each accepted run begins at negative native clock, passes clock 260 in full
mode 0, observes human legs 0 through 9, and ends with every boat beyond final
leg 8 and a positive native finishing position. The result flag becomes 1
through the original engine. Later collectors execute the next scheduled
paint to draw the actual results screen; both fleet sizes' screenshots were
visually inspected. No browser exception or simulator error was recorded.

Raw reports include sampled boat telemetry, every leg/finish transition, all
pilot commands, initial/final image hashes, RNG state, setup history, Chrome
metadata and the loaded module identities. Newer captures retain the exact
collector source and compressed finish image. Reports are diagnostic inputs,
not shipped product assets.

[BASE-03-source-verification.json](BASE-03-source-verification.json) confirms
all 83 loaded JavaScript modules in each of the five accepted runs match the
frozen reference. It also verifies all 6471 frozen inputs are unchanged. The
final collector applies this module check as an acceptance gate; the archived
runs were checked independently with this same pinned source manifest.

## Repeat comparison and remaining finding

The five-boat runs have identical setup image hashes, all recorded control
sequences, samples, leg/finish transitions, final frame, simulation time and
RNG state. The final two captures `5-c` / `5-d` also have identical **unmasked
2,211,840-byte finish images**, verified against their individual hashes:
`f9bef694e23f69d81e7af6a897f9727900abbcc1bee72c0bbe8601a99afae1bc`.
[BASE-03-repeat-verified.json](BASE-03-repeat-verified.json) records zero
differing bytes. This finite comparison is not certification of all scenarios
or a complete replay checkpoint including retained locals and host state.

**B03-01 remains open:** earlier `5-a` / `5-b` finish image hashes differ despite
identical recorded race traces and final RNG. Those earlier collectors retained
hashes without raw images, so the differing addresses cannot be recovered from
these archives. Do not describe that earlier mismatch as fixed, mask it away,
or infer it is harmless graphics scratch. BASE-04 must classify all drawing
and host dependencies, and ENG/QA determinism checks must retain raw snapshots
when a mismatch recurs. The task's natural complete-race criterion passes;
universal whole-state determinism remains a separate acceptance requirement.

## Failed and bounded attempts

`BASE-03-pilot-1` failed in the diagnostic injection with an invalid top-level
`await`; no race evidence is claimed. `BASE-03-pilot-2` stopped at its deliberate
1500-paint bound while on the final leg; it is not a completed race.
`BASE-03-race-15-a` failed before setup because Chrome exposed height 1051
against a requested 1050. The collector was aligned with the recorded BASE-07
physical window and explicit logical viewport; `15-b` then completed. These
attempts are retained and are not simulator failures or accepted race counts.

## Reproduction and evaluation

From the repository root, use new output directories:

```sh
node versions/2026/tools/reference.mjs verify
node versions/2026/tools/race-baseline.mjs /tmp/tact-race-5-new 5 3500
node versions/2026/tools/race-baseline.mjs /tmp/tact-race-15-new 15 5000
node versions/2026/tools/compare-races.mjs \
  versions/2026/analysis/baseline/BASE-03-race-5-c \
  versions/2026/analysis/baseline/BASE-03-race-5-d \
  /tmp/tact-race-comparison-new.json
```

The collector refuses an existing output directory, owns and closes only its
own server/Chrome, and returns failure for a bounded incomplete race, error,
missing human leg, unfinished boat, missing results presentation or changed
loaded module. The comparison validates compressed images against their
captured size and SHA-256 before comparing bytes. Syntax checks, real browser
runs, visual results inspection, source integrity and repeat comparisons are
the task's verification. No extra unit tests were necessary for this diagnostic
addition. BASE-03 is accepted with B03-01 recorded for follow-up.
