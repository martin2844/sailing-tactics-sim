# Review of dense fleets, playback and boat extraction

## Verdict

No findings. No production fixes were required by this review.

## Scope

Reviewed the recent changes from `c9bdd70` through `46e46df`, including their
full enclosing implementations, callers and relevant tests. This covers the
contact/numerical performance optimization, OG variable-timestep fast-forward
and the correction that isolates detailed boat drawing from playback presets.
It is a review of those changes, not a certification of every feature in the
2026 backlog.

Three independent read-only passes examined lifecycle/caller contracts,
contact/numerical correctness, and private models/evaluation validity. The
primary review checked wiring and evidence before accepting their conclusions.

## Cleared

Generated numerical receipts, profiling output and screenshots were excluded
from line-level defect review. They were used as evidence where appropriate.
Checklist/history-only documentation did not require behavioral review.

## Checked clean

- Playback presets and active versus selected speed: Space retains the selected
  pace, Page controls restore the appropriate preset, and assistance slowdown
  is preserved until an explicit resume. Checkpoints/replay and next-race routes
  synchronize the public timing choice with the numerical state.
- Worker scheduling: cancellation tokens reject stale tasks; deadlines use
  fractional game time; pause and held screens rebase rather than accrue debt.
  Native reference scheduling remains available at the private boundary.
- Avoidance and contact prediction: signed coordinate wrap and unsupported x87
  precision/retained-stack cases keep the exact reference path. Query caches
  receive immutable motions; scratch geometry and returned normals are isolated.
  Conservative translation bounds keep rotation/uncertain-input fallbacks.
  Actual response still uses uncached sweeps and original rule callbacks.
- Profiling: temporary callbacks retain their receiver, arguments, result and
  exception behavior and are restored on success/failure.
- Boat extraction: drawing speed/divisor overrides occur after copying to a
  disposable projection image. Gameplay memory/RNG remain separate. Both live
  model workers and diagnostics use the same extraction helper.
- Evaluation contracts: timing observations are distinguished from fixed-preset
  numerical parity and geometry data equality. Larger fast-forward timesteps
  intentionally change trajectories; they are not claimed to reproduce preset6
  step-for-step. Existing geometry goldens compare against a pinned earlier
  implementation, not the same implementation under test.

## Validation

- Twelve current playback/profiling tests passed during review.
- TypeScript check passed.
- Added a reproducible [model catalog evaluation](../tools/model-profile-catalog-eval.mjs)
  to retain the additional model review coverage. It checks all27 boat classes,
  initialized and40-step close-hauled physical states, and all eight multipliers.
  Every extraction checks full master memory and RNG isolation; packets must
  remain byte-identical when only playback changes at a fixed physical state.
  See its [receipt](../analysis/app/big-review-model-catalog-2026-10-07/verification.json).
- Existing Chrome receipts cover trusted Space/Page/F controls, held panels,
  replay, a full30-boat32× championship race, and both rendered hull sides.
  Existing exact geometry/numerical comparisons cover hull sweeps, rule response
  and fixed-step memory/RNG equality. These prior receipts were inspected;
  they are not represented as new runs in this review.

The catalog evaluation checks model data; it does not visually certify all27
classes or measure Chrome/mobile throughput. Pixel validation remains pending.
