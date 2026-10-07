# Boat models and playback presets

The variable-timestep change exposed a remaining coupling in private boat
extraction. The recovered painter reads numerical speed to select geometry and
detail branches, and reads the timestep divisor for drawing calculations.
Those settings belonged to OG paint pacing; they should not change the shape of
2026 boats when the same physical state is displayed at a different multiplier.

Each disposable projection image now selects the audited detailed drawing
profile (level6, divisor384) before tracing the boat. Both stereo projections,
the hidden hull sides, rig and crew use that profile. Actual sailing state,
trim, heel, luffing, penalty colours and positions remain copied from the
simulation. The authoritative numerical preset, wall-time deadlines and RNG
remain unchanged. This applies to live model workers and private diagnostics.

Evaluation:

- Before the fix, the same paused30-boat state produced different position and
  record packets at32× and Space precision. After the fix there are zero
  differences in positions, records, colours or boat ranges.
- [All eight multipliers and Space](../analysis/app/model-pace-fixed-2026-10-07/verification.json)
  produce byte-identical packets on a post-start physical state. Extraction
  preserves the complete master image/RNG boundary. Rendered hulls and rigs
  were inspected from [starboard](../analysis/app/model-pace-fixed-2026-10-07/starboard.png)
  and [port](../analysis/app/model-pace-fixed-2026-10-07/port.png).
- [Native rig fixtures](../analysis/app/model-profile-rigs-fixed-2026-10-07/verification.json)
  check native projection/lifting, trim, both tacks, luffing, spinnaker,
  penalty colours, crew, free-camera isolation and live/private transport.
- [30-boat throughput](../analysis/app/model-pace-load-fixed-2026-10-07/verification.json)
  remains approximately32.26× at requested32× in Chrome after the drawing fix;
  pausing retains the exact numerical boundary. This is a bounded desktop
  observation, not mobile certification.
- Type check and production build pass.

The earlier32× throughput tests checked numerical rate and race completion,
but did not compare geometry across numerical presets. The new model-pacing
regression check explicitly covers that gap.
