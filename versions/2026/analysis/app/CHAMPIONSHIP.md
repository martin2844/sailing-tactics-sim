# Events and native series (EXT-04, journey evaluation in progress)

The starter selects Standard race or Championship (3, 5 or 10 races). Standard
race uses native No Series Scoring, ending on the player's finish. Championship
uses native series scoring and waits for the complete native results. The three
race mode preserves the original point units, including fractional tie ordering.
Five/ten-race events are modern no-discard extensions: score each race natively,
aggregate the exact native units across three-race chunks, and resolve remaining
equal totals by ascending boat ID, as the original strict-less sort does.

Next race uses original N / Space and complete canonical paints in the **same
worker**, including the original between-races notice dismissal. It does not
reseed or discard fleet/weather/RNG state. After race three, the original N resets
the native three-race counter; the modern event history remains. Settings are
locked on the next-race starter. Repeated Next requests are guarded; stale model
packets cannot reveal the previous race while the new fleet is prepared.

Evidence:
- Four focused event-ledger tests cover finalized-only recording, deduplication,
  fractional score ordering and ties, native counter rollover in a ten-race
  event, and rejection of incorrect native scoring mode. Run with
  `node --experimental-transform-types --test tools/event-session.test.mjs`.
- [Eighteen standard-race configurations](event-settings1/verification.json)
  match whole original memory, clock, RNG and shore initially and after eight
  paints, using independently supplied native menu IDs including No Series.
- [Championship UI/selection](championship2/verification.json) verifies the
  audited original series initial boundary, native-score presentation fixtures,
  completed three-race standings, and five/ten-race selection. These result
  packets are controlled presentation fixtures, not naturally sailed races.
- [Starter journey](event-starter1/verification.json) checks held setup, trusted
  Start and settings, N/new-event, visibility listener, and stale-worker errors.
- The first natural sailing attempt was stopped after an evaluator helm-step
  calibration problem. The second [retained run](event-sailing2/failure.json)
  sailed a real first-place finish and initialized race two, then a Node-side
  evaluator typo (`tact2026` used outside its page) stopped the test. This is a
  test-harness failure, not an application error. The full three-race run is
  being repeated; EXT-04 stays unchecked until that journey is evaluated.

No mobile acceptance or completed full championship claim yet. Final Chrome
smoothness evaluation belongs to EXT-07 after the complete feature expansion.

## Complete natural series evaluation

`event-sailing4/verification.json` now proves three naturally sailed native races, both N/Space transitions, race clocks advancing after each start, retained RNG across transitions, native completed-race counters 1/2/3 and final championship standings. The automated helm uses original port/starboard commands and real paints, with no authoritative game-memory fixtures. Each player finish was first; the original engine subsequently retired the other four boats (native position 6 and native raw score 606), which is shown as retired rather than invented finishing places. This verifies the event flow, not a claim about human sailing or AI competitiveness.

The earlier `event-sailing3` failure exposed that original result drawing freezes the simulator. N retains the freeze flag, and dismissing the series notice consumes Space before the ordinary thaw branch. Next race now dismisses active overlays and uses the original F handler only if still frozen. The successful three-race run checks that flag every sailing batch. Four ledger unit checks also pass.
