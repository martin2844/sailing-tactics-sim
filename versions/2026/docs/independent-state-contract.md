# Independent simulation contract v1

The2026 UI now uses an explicit wall-time playback scheduler and a separate
cosmetic animation clock. [Real-time playback](real-time-playback.md) defines
the consolidated1×–32× multipliers and private reference scheduling, assistance exceptions and pause/reset ownership.
Host scheduling metadata does not enter the numerical checkpoint; given the
same native preset, ordered controls and step count, numerical state/RNG remains
the regression contract. Existing reference clients omit playback settings and
retain original scheduling.

2026-10-07. The user selected independent deterministic gameplay randomness
instead of reproducing the old painter's seed-specific random consumption.
Recovered sailing, AI, wind, current and penalty calculations remain the
numerical foundation. Identical old seeds need not produce identical races.

`EngineRuntime` owns initialization, ordered numeric controls, phase cadence,
variable timestep, world updates, coach counters, score finalization, finishing
window, next-race initialization and complete binary/host checkpoints. It runs in
Node without DOM, Canvas, GDI, bitmap fonts or a graphics backend.

The CRT distribution is retained. Gameplay, physical waves and cosmetic
presentation have separate versioned seeds. The physical wave field retains398
points and the recovered spawn/heave calculations. Field refresh is based on
physical boat position/heading and a2000-unit radius, independent of camera
coverage. This replaces the old screen-visibility spawn policy; wave encounters
and seed-specific heave can consequently differ. It does not remove wave effects
from boat dynamics.

Every successful simulation step normalizes NPC rigs, refreshes physical waves,
updates heave, applies automatic foul slowdown, copies warning latches, samples
coaching data and clears frame warnings. Navigation classification retains
native bearing/distance arithmetic. Sampling takes place once per step rather
than once per HUD drawing. Paused/frozen or held information screens do not
advance authoritative state.

Checkpoints include the entire address image, all three RNG states, simulation
host ticks, virtual CString host contents, race-window finish/DNF bookkeeping
and the current leg-replay boundary. Leg replay restores the latest
native save boundary after its entire world phase and freezes. It does not use
the old partial memory restore or allow wave respawns to consume gameplay RNG.
The browser must reset/reseed contact and island-navigation observers on replay.
Transport sequence numbers remain monotonic independently of restored clocks.

Browser scheduling honors the native80/60/30ms minimum at applicable pace levels;
levels7+ retain the native unthrottled contract. It never inflates a simulation
step to catch up with a display frame or spin-waits on browser time.

Evaluation gates:

- Frozen primitive comparisons retain complete image/arithmetic equivalence.
- Whole-race equality compares two independent-v1 runtimes with identical sailing
  commands and different presentation work. Old raster/shared-stream whole-race
  equality is historical extraction evidence, not v1 acceptance.
- Complete headless races must reach native finishes/DNF/results; scores,
  checkpoint continuation, held-state stability and championship reset are checked.
- Browser cutover additionally evaluates private presentation purity, contacts,
  island routes, every boat class, controls and menus. These are separate from
  display performance certification.

Evidence: `analysis/app/independent-runtime-telemetry-2026-10-07/verification.json`
(two complete20786-step races, four AI arrivals,20-minute player DNF, identical
image/gameplay RNG despite cosmetic work; checkpoint, held-panel and next-race
checks; review regressions additionally cover a discarded future replay point,
virtual strings and N/Space restart) and the frozen navigation/wave/waypoint/camera/step tests.
