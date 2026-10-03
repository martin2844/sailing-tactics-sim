# Encounter and penalty reconstruction

The source modules translate complete original functions; their callers consume
the original memory, RNG, and sound effects. The executable remains unchanged.
The source SHA256 is `881dc85dc7500a5ad09e09091d4dd53f8c091f5630d5fabdcc887cc4b007acea`.

## Validated leaves

`tests/encounter-leaves.test.js` checks 9,115 captured calls, including exact
returns, binary64/extended return bits, RNG state, ordered sound requests,
original image store ranges, and all changed mapped-image bytes. Independent
Wine execution of the unchanged original functions confirms these results.

| Original address | JavaScript export | Return | Effects |
| --- | --- | --- | --- |
| `00421c40` | `resetBoat` | residual signed EAX | resets race stage; interpolates or centers start targets |
| `00428af0` | `relativeProjection` | signed64 `BigInt` | reads two boats and projected heading/wind geometry |
| `0044da90` | `aheadAstern` | signed64 `BigInt` | reads projected wind geometry and two complete distance calls |
| `0042a8a0` | `respawnNearStart` | residual signed EAX | sound request, reset targets, two RNG draws, two coordinates |
| `0042a950` | `shiftPenaltyPosition` | residual signed EAX | sound request, two coordinates |
| `0042abb0` | `checkNearRaceMarks` | signed32 | asymmetric Manhattan radius check |
| `00426f50` | `signedStartDistance` | retained `Float80` ST0 | no mapped-image writes |

The full signed64 returns preserve EDX:EAX from `__ftol`; ordinary encounter
callers use only the low32, exposed by `projectionLow32`. The reset's residual
EAX is 2 except when the final start-center override runs, where it is the
integer midpoint Y. The respawn returns the final integer Y, while the shift
returns its chosen, once-wrapped integer angle.

## Numerical evidence

`00426f50` spills the position X difference at `00426fcc`, spills Y without
popping at `00426fe2`, spills the reference X difference at `00426fee`, and
spills the first square root at `00427014`. Position X and reference X squares
use the stored binary64 values twice. Position Y uses its retained extended
value times its stored binary64 copy. Reference Y remains extended through its
square. The final return subtracts an unrounded reference square root from the
stored first square root.

`00428af0` retains both projected coordinates; its first X difference spills
once before multiplication and the first square root spills to binary64.
The second X and Y differences each multiply their retained extended value by
their own stored binary64 copy. `0044da90` spills both projected coordinates and
the first distance result, then subtracts the second distance without spilling.

`native-trig.js` loads actual host x87 captures for integer angle × original
binary64 degree factor, with separate tables for radians retained in extended
precision and radians first stored as binary64. Unsupported capture inputs
throw; there is no browser `Math.sin` or `Math.cos` fallback. These are finite
host-processor reference results under control word `037f`, not an assertion
that every historical processor's transcendental low bits were identical.

The initial Unicorn shift fixture differed from actual x87 output in 1,738 of
1,988 calls. The browser's hardware-reference implementation agreed with the
unchanged original code running under Wine. The preserved emulator baseline,
comparison report, and authoritative correction provenance identify the exact
changed position bits and image deltas; the tests use no tolerance.

The normal shift tack domain is ±1. Other native tacks load an uninitialized
stack local and are explicitly unsupported. Two-boat interference has a
similar uninitialized threshold for other tacks.

## Connected routines under validation

`collisionPenalty` (`0042a530`), `updateMarkStartPenalties` (`0042a2d0`), and
`updateInterference` (`00429f40`) are complete translations using these leaves.
The collision cooldown reads the other boat's timestamp; encounter scanning
runs in descending boat order and rereads positions after prior collisions.
The original routines have void contracts. Their unused residual EAX can
contain caller register state or x87 status and is not invented as a return.

`updateBoatDynamics` (`00428c60`) translates the entire connected routine in
`src/engine/boat-dynamics.js`; full native state coverage is still being captured.
Its additional typed map is `analysis/boat-dynamics-map.json`.
The first full-image emulator smoke case agrees exactly, which is a debugging
check rather than a complete dynamics parity claim.

The propulsion multiplication follows `004292a6`–`004292d4`: coefficient ×
stored apparent-wind pressure × retained cosine × 0.01 × sail area × cosine ×
0.1, then binary64 storage. The decompiler's reassociated multiplication order
is not used. The hull-speed square root × 10 is stored without popping at
`004296f2`; its retained extended copy × 15 / displacement then spills at
`0042970a`. Fractional sail-force FSIN at `0042964c` preserves FILD sail angle,
optional FSUB 0.8 and FSUB -0.2, FILD force angle, FADDP, and FMUL degree factor.
`assets/data/x87-force-trig.json` keys its native results by that final radian
m80 representation.
