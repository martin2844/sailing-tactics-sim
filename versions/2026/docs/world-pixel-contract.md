# Remaining world pixel and randomness contract

2026-10-07. Independent big-review examined changed kernels, hooks, driver,
private-image ownership and the evaluation tools. No introduced findings
survived; sixteen tests passed at that review boundary. The later host/wave tests
bring the focused suite to eighteen passing tests.

Three recovered routines make pixel queries (each has translated variants):

- `0x43efd0` checks green COLORREF 32768 at projected object y+1 and y+2.
  A match skips the object, including boat drawing, its coordinate stores and
  shared random draws for sail luffing, wakes and rig effects.
- `0x440b70` checks four shoreline endpoints. It has no RNG and writes common
  polygon scratch before use. Ten default reference paints recorded 2,080 scratch
  writes and no external reads before overwrite. This is bounded evidence, not a
  reason to discard retained shoreline stack or projected shoreline arrays.
- `0x481e90` checks blue water at y and y+4. The accepted scenery path can update
  bearing/distance and the player's look offset. A private-image probe proves
  blue leaves them untouched while white performs the stores, including writes
  whose final value equals the old value.

The scene order is water, gust artwork, water/scenery dots, foreground indicator,
sky/background, shores/scenery, target selection, sorted course objects/boats,
then foreground instruments. Each query sees prior artwork in that order.
There is no exact-green 32768 static pen/brush definition or explicit pixel store;
coverage/compositing can create it from other colors. A land-only polygon test
or constant pixel response is therefore not a justified exact replacement.
Thirty default reference paints observed more than 1,600 pixel probes and no
exact-green match; that sample cannot prove the branch unreachable.

To preserve the exact legacy random sequence, the new world contract must
reproduce required canonical visibility/coverage decisions and ordered random
consumption independent of the Three.js camera. Separating gameplay randomness
from cosmetic drawing is a cleaner independent engine contract, but changes
seed-specific future weather/AI trajectories even with identical formulas.
The user has been asked to choose this material behavior requirement. Existing
code still preserves the old shared stream pending that answer.
