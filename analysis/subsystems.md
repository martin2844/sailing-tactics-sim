# Posey Sailing Tactics 2002: subsystem map

This is an evidence map for the original `Tact02Demo.exe`, not a claim of a completed behavioral reconstruction. Addresses are image virtual addresses with image base `0x00400000`. Names below are analyst-assigned; the executable has stripped symbols. The original machine code is the authority where a decompiler loses types or x87 stack operations.

## Confirmed architecture

The executable is 32-bit x86 PE, built with Microsoft Visual C++ linker 5.0. It statically includes substantial MFC and CRT code. Class-name strings `CTACTDoc` and `CTACTView` are present. It uses Win32 GDI drawing, an MFC document/view UI, USER32 input, and embedded WAVE resources through `PlaySoundA`. The PE header timestamp is 2001-01-14 14:26:43 UTC; that is a build-header value, not independent proof of publication date.

Application code is concentrated approximately in `0x401000..0x455xxx`, followed by much CRT/MFC runtime code. Boundaries need to be determined per function rather than assuming this entire region is simulation logic.

`FUN_00404020` is a confirmed frame/update-and-render coordinator. At `0x403dec` it is called from the document/view drawing path with a drawing context. Its initial calls are, in order:

1. `FUN_0041b5d0`: update environmental wind model.
2. `FUN_0041e9c0(i)`: update five environmental entities when their scheduled update time has elapsed.
3. `FUN_004249a0(i)`, ascending boat indices `1..DAT_0049118c`: per-boat tactical/race/control preparation. Detailed semantics remain partial.
4. `FUN_0042b7f0()`: player 1 steering/control update.
5. `FUN_0042bda0()`: player 2 steering/control update when `DAT_00491140 == 2`.
6. `FUN_00428c60(i)`, ascending boat indices: wind sampling, apparent wind, sail and speed update, interference, penalties.
7. `FUN_0042adb0()`: time and position integration, when `DAT_004ac980 == 0`.
8. Race status and rendering calls.

The exact order matters: all boat speed/interference updates happen before the position integration loop. `FUN_0042adb0` integrates boat positions in descending index order. A browser port must preserve these orders until tests demonstrate they are immaterial.

`FUN_00404020` measures host time through `GetTickCount`, then busy waits to a minimum frame duration at low speed settings. Levels 1..4 wait at least 80 ms, level 5 at least 60 ms, level 6 at least 30 ms; an option adds 100 ms. Level 7 and above skip that wait. Physical elapsed time does not directly equal this host-time delay.

## Clock and integration

| Address | Assigned meaning | Type | Evidence |
|---|---|---|---|
| `0x49116c` | simulation speed level | signed int | Menu handlers and display at `0x40d4d0`; divisor dispatch at `0x44e380` |
| `0x491170` | simulation speed divisor | signed int | Exact speed mapping in `FUN_0044e380` |
| `0x4aa948` | simulation time step, seconds | double | Set at `0x42b069`; added to elapsed time at `0x42b110` |
| `0x4ac1f8` | simulation elapsed time, seconds | double | Starts at -170 for normal prestart (`0x413f43..52`), can be -340/0 for alternatives; advanced at `0x42b124` |
| `0x4a5b80` | truncated elapsed seconds | signed int | Assigned from `0x4ac1f8` using CRT float-to-int at `0x42b23c..24d` |
| `0x4a76c8` | previous truncated elapsed seconds | signed int | Copy at `0x42b230` before advancing integer clock |
| `0x4ab0c0` | boat scale/time factor | double | Initialized at `0x417b61..72` to `sqrt(15 / DAT_004a5ba4)` |
| `0x4a5ba4` | boat length/scale parameter | signed int | Displayed with `Length=` in `0x40f4a0`; used for dynamics and time scales; physical unit unconfirmed |
| `0x4a4eec` | displacement coefficient | signed int | `0x40f4a0` labels 8 or below ultra light, 9 light, 10 moderate, 11 heavy; presets set additional values |
| `0x4a5b90` | relative sail-area coefficient | signed int | `0x40f4a0` labels below 10 less than average, 10 average, above 10 more than average |

The confirmed time-step formula at `0x42b047..69` is:

```text
dt = boatScaleFactor * 25.0 / speedDivisor
elapsedSeconds += dt
integerSeconds = trunc(elapsedSeconds)
```

The exact divisor table for levels 1 through 15 is `[2919, 1946, 1297, 865, 577, 384, 256, 171, 114, 76, 51, 34, 23, 15, 10]`. Race time, environmental time, and the displayed day/time are related but have additional scale factors (`0x49115c`, `0x4ab8b8`, `0x4abef0`); do not collapse them into a single browser timestamp.

Position integration at `0x42b3d1..522` forms boat velocity from integer speed and heading, adds current components, then multiplies by `dt / scaleDenominator`. The denominator is selected from environmental/boat options, approximately 2300 or 2600 before corrections. This is not enough evidence to assert SI units.

## Per-boat state layout

The program uses many parallel global arrays rather than one contiguous boat struct. Boat index 0 is normally unused; frame loops start at index 1. Most array allocation/count limits have not yet been proven.

| Array base | Meaning | Element type | Evidence |
|---|---|---|---|
| `0x4a49e8` | horizontal/world X position | double | Sampled by wind/current functions, advanced by `0x42b50e..51b` |
| `0x4a4ae0` | vertical/world Y position | double | Sampled with X, advanced by `0x42b517..522`; heading 0 moves toward decreasing Y |
| `0x4ac018` | heading in degrees | signed int | Normalized through `0x413cb0`, then sin/cos used for motion at `0x42b3d1` |
| `0x4a71c8` | continuous speed in tenths of a knot | double | HUD multiplies by 0.1 at `0x40c8bb..c2`; updated at `0x4298ff..936` |
| `0x4a7060` | quantized speed in tenths of a knot | signed int | Truncated from continuous speed at `0x4299a1..9b1`; used for integration |
| `0x4a6338` | sampled true wind strength in knots | signed int | Input to apparent wind helper `0x429df0`; wind display xrefs |
| `0x4aa5b0` | sampled true wind direction in degrees | signed int | Subtracted from heading at `0x428d98..db2` |
| `0x4a7bc8` | absolute angle between heading and true wind, 0..180 | signed int | Calculated at `0x428d98..dc2` by absolute difference and `360-diff` correction |
| `0x4ab9e8` | apparent wind strength in knots | signed int | Computed by `0x429df0` from squared vector magnitude |
| `0x4a47f8` | apparent wind angle | signed int | Set by `0x429df0` using atan branches |
| `0x4a7868` | bad-air/interference state | signed int enum | Cleared and set in `0x429f40`; HUD strings confirm 0 clear air, 2/12 blanketed, 3 backwinded |
| `0x4a89c0` | penalty/status code | signed int enum | Written by `0x42a2d0`, `0x42a530`; shown by `0x430f90` |
| `0x4abf18` | last penalty time | signed int | Set from integer elapsed time in penalty handlers; expires by time checks |
| `0x4aa730` | tack sign, -1 or +1 | signed int | Used to select port/starboard rules at `0x42a5e6` and rendering |
| `0x4a5420` | race leg/mark progress | signed int | Compared and advanced through tactical/navigation logic; precise state mapping remains partial |
| `0x4abb70` | spinnaker state, probable | signed int | Set for downwind conditions in `0x428eaa..f39`; used in additional sail rendering and polar terms |
| `0x4a6ec8` | heel angle in degrees | signed int | Sail pressure determines its target; averaged with prior angle at `0x4299b8..c0`; `0x411000` uses its sine for hull roll |
| `0x4a77e8` | sail/sheet angle in degrees | signed int | Calculated from wind angle at `0x428dd9..0x428e1c`; feeds sail geometry and power |
| `0x4a8aa8` | luffing percentage | signed int | HUD label `luffing:` at `0x40e9a0`; power reduction and automatic trim in `0x428c60` |
| `0x4ac5f0` | spinnaker angle penalty | signed int | Set to 0/30/100 by `0x42a280`; reduces driving sail term |
| `0x4ac1e8` | closehauled angle offset | signed int | Added to selected beating angle by `0x4269d0` |

## Environment, speed, collision, and race candidates

| Function | Assigned role | Evidence/confidence |
|---|---|---|
| `0x413f00` | initialize a new race | Confirmed: resets clocks, race/boat arrays, and calls course setup |
| `0x417790` | initialize boat options and class parameters | Fully ported; native fixtures verify all written fields, retained state and time-factor bits |
| `0x41b5d0` | global environmental wind update | Confirmed: time/shore-conditioned strength and heading, random shift scheduling |
| `0x41ba60` | schedule next random wind target | Confirmed: advances indices through a stored random sequence and sets next shift time/target |
| `0x420b70`, `0x420c40` | spatial wind samplers | Strong evidence: called by dynamics with integer X/Y/boat, return wind-related values; alternative selection by environment option |
| `0x421560` | spatial current sampler | Strong evidence: position-based call followed by current strength/direction storage in `0x42b2c6..307` |
| `0x4249a0` | tactical/navigation and control preparation | Confirmed per-boat frame call; contains closehauled-angle choice, computer decisions, and race-state checks |
| `0x426ad0` | mark/course navigation update | Strong evidence from callers and mark-related state; needs complete branch mapping |
| `0x4255b0` | select tack sign from heading and wind | Fully mapped and native-fixture tested integer helper |
| `0x4269d0` | set closehauled heading | Fully mapped and native-fixture tested integer helper |
| `0x428c60` | per-boat sailing dynamics | Confirmed: spatial sampling, apparent-wind helper, interference, polar calculations, sail options, acceleration, speed clamps |
| `0x429df0` | apparent wind vector/pressure | Fully mapped small numerical helper; see below |
| `0x429f40` | other-boat wind interference and collision checks | Confirmed: loops over other boats, sets bad-air enums, calls `0x42a530` for close encounters |
| `0x42a2d0` | mark contact and early-start checks | Confirmed: code 1 hit mark and code 2 over early |
| `0x42a280` | spinnaker angle penalty | Fully mapped and native-fixture tested integer helper |
| `0x42a530` | encounter/racing-rule penalty checks | Confirmed: sets codes 3..7 based on tack, overlap, relative wind, mark proximity |
| `0x42a8a0`, `0x42a950` | penalty response/boat repositioning | Confirmed responses called after mark/collision/start infractions; detailed response model incomplete |
| `0x42abb0` | mark proximity/contact test | Strong evidence: called by mark penalty with boat and size threshold |
| `0x42adb0` | clock and world position integration | Confirmed as above |
| `0x42b7f0`, `0x42bda0` | steering updates for players 1 and 2 | Confirmed: mouse UI hit tests, heading changes, manual/automatic mode state |
| `0x430f90` | penalty text display | Confirmed string and enum mapping |

Penalty codes confirmed in `0x430f90`: 1 hit mark (rule 31), 2 over early (rule 29.1), 3 failure to give room (rule 18.2(a)), 4 port tack (rule 10), 5 windward boat (rule 11), 6 overtaking boat (rule 12), 7 tacked too close (rule 13), 10 aground. Code 11 displays `Boat <number> finished <place>. Please wait for last boat.` using finishing position at `0x4a7648[boat*4]`.

The principal speed polar is embedded in the approximately 4.5 KiB `FUN_00428c60`, not a separate exported function. It combines wind angle and strength, boat class, main/jib trim, spinnaker, bad air, and power/drag terms. A replacement generic sailing polar would not preserve behavior.

The speed transform and acceleration tail are mapped below; the complete polar has not been ported or dynamically validated.

### Recovered speed transform inside `0x428c60`

After sail, trim, heel, spinnaker and bad-air computations, `0x429690..0x4297d3` subtracts a drag-like term from driving power and transforms the remainder. These intermediate names are assigned for analysis, not original symbols:

```text
drag = truncSigned32(trueWind[boat] * (90 - angleToTrueWind[1]) / 15)
if boatClass in [6, 7, 8]: drag *= 0.5
powerRoot = netDrivingPower > 0 ? sqrt(netDrivingPower) : 0
H = sqrt(boatLengthScale) * 10
if powerRoot > 24:
    baseSpeed = H - (H * 15 / displacement - H) * sqrt(powerRoot - 24) * -0.125
else:
    baseSpeed = H * 0.3333333333333333 - H * powerRoot * 0.041666666666666664 * -0.6666666666666666
if powerRoot < 7:
    baseSpeed = powerRoot * powerRoot * 0.01
```

`netDrivingPower` includes the drag subtraction. The actual drag instructions first wrap the integer product, then truncate division. The fixed address `0x4a7bcc` at `0x429690` is **boat 1's** wind angle even while another boat is updated; substituting the current boat's angle changes the original behavior. The low-power branch at 7 is also literal original behavior, including its discontinuity; it should not be smoothed.

There are additional prestart computer-boat adjustments, relative boat speed factors at `0x4a6fc8[boat*4]`, and human trim penalties before this result becomes target speed. In particular, the boat-class 7/8 computer downwind factor adds 1.25 before multiplying by 0.01. Those adjustments must be ported with the full function.

At `0x4298de..0x4299c0`, after checking mark/early-start penalties:

```text
timeConstant = displacement * 0.5
if boardFlag == 1: timeConstant = displacement
speed = (targetSpeed - previousSpeed) * dt / timeConstant + previousSpeed
if integerSeconds == penaltyTime[boat]: speed = 0
speed = clamp(speed, -10, 200)
quantizedSpeed[boat] = trunc(speed)
heel[boat] = truncSigned32((previousHeel + targetHeel) / 2)
```

The rest of `0x428c60` further changes quantized speed for prestart AI, grounding, finish, maneuvering and other race states. Continuous and quantized speed are consequently not always interchangeable.

Another confirmed order dependency: `0x429df0` is called at `0x428d56`, before recomputing heading versus true-wind angle at `0x428d98..0x428dc2`. The apparent-wind helper therefore reads the angle present on entry, while later sail calculations read the freshly computed angle. Preserve this ordering. The frame also computes the integration time step after dynamics have already consumed the existing `dt`.

### Boat option flags

`0x417790` maps the selected boat into common geometry/dynamics classes and flags. `0x4ac900` identifies the catamaran variants, `0x4ac904` the Board/windsurfer, `0x4ac908` the Sport Boat variant, `0x4ac90c` the Skiff variant, `0x4ac910` JY15, and `0x4ac914` Optimist. These names are supported by the extracted Boat Type menu, MFC command-map pointers, and initialization selector branches. Some helpers distinguish a flag equal to 1 from any nonzero value; preserve those comparisons even if ordinary UI settings only produce 0 or 1.

The complete routine is translated in `src/engine/boat-options.js`. The selector map is:

| Selector | Boat | Common class |
|---:|---|---:|
| 1 | Optimist | 1 |
| 2 | Laser | 1 |
| 3 | Board | 1 |
| 4 | Snipe | 2 |
| 5 | JY15 | 2 |
| 6 | 505 | 3 |
| 7 | Skiff | 3 |
| 8 | Thistle | 4 |
| 9 | Lightning | 5 |
| 10 | Tornado Catamaran | 9 |
| 11 | Spinnaker Catamaran | 10 |
| 12 | Keelboat | 6 |
| 13 | Sport Boat | 7 |
| 14 | Offshore Racer | 7 |
| 15 | America's Cup | 8 |

Inputs include selector `0x491144`, overrides at `0x4ac918..0x4ac924` (length, displacement, sail area, percentage), and retained class/length/rig/course/flag state. The code clears all six variant flags even for an invalid selector, then preserves the old common class if the selector is outside 1..15. Custom displacement/sail-area values are restricted to 8..11, custom lengths to 20..50 for the relevant classes, and positive percentage overrides have no explicit upper bound before presets overwrite them. Class 7 preserves the prior rig, course, and `0x4ac990`; other classes clear that flag and reset course 8 to 1. Sport Boat presets override custom length/area/displacement; Offshore Racer remains customizable.

All 852 full-state original-instruction fixtures match, including invalid selectors, prior classes 0..11, every written integer field, residual EAX, and exact time-factor bits. An additional calibration comparison exposed 1 ULP differences between original extended-precision division/square root and `Math.sqrt(15/length)` at lengths 29 and 35. The port uses all 38 native factors in `assets/data/boat-calibration.json` for the ordinary domain (11, 14..18, 20..50, 61), with tests checking every stored bit pattern. Arbitrary retained lengths reached through invalid class/selector state use a documented unverified binary64 fallback; no full x87 exception or arbitrary-domain equivalence is claimed.

## Rendering

`FUN_00411000` is the confirmed boat renderer, with arguments equivalent to `(drawingContext, screenX, screenY, boatIndex, viewIndex, bottom, top)`. Its exported body is 6,147 bytes (`0x411000..0x412802`). It builds boat geometry in screen coordinates using x87 `atan`, `sqrt`, `sin`, and `cos`, reads camera/layout state, scale, heading, heel and tack, writes screen arrays at `0x4aa1a0` and `0x4aa2a0`, then draws GDI polygons and lines.

`0x412f60` generates a monohull outline with sine-based width variation. `0x413100` generates the catamaran/twin-hull outline using fixed proportional offsets. Both write model arrays near `0x4ac310` (X), `0x4a3a38` (Y), and `0x4a79f8` (height/width terms). `0x414010` constructs additional sail/model points, `0x413370` adds upper-detail points, and later renderer helpers draw the hull, sails, crew and wake in an order conditioned on viewing angle.

Rendering is **not pure** in this executable. At the start of `0x414010`, drawing a computer-controlled boat sets `0x4a7768[boat*4]=1`, `0x4a4ef8[boat*4]=1`, chooses `0x4a4170[boat*4]=2/3` based on class/options, and clears `0x4ac5f0[boat*4]`. Drawing mark/buoy index 0 also clears `0x4a7bc8[0]`. A faithful port must account for these writes and their ordering, rather than independently scheduling a supposedly pure render pass.

`0x404880` draws the 3D sailing view and establishes clip regions. `0x407e40` is a top/tactical/chart-view renderer with a mode argument. `0x40cxxx` and `0x40e9a0` format player performance data and controls. Many tutorial functions beginning near `0x432xxx` are diagrams and explanatory text, not simulation logic.

## Small numerical functions suitable for faithful translation

### Integer angle correction (`0x413cb0`)

Exact bytes: `8b4424043d680100007c052d6801000085c07d050568010000c3`.

```js
function correctAngleOnce(input) {
  let angle = input | 0;
  if (angle >= 360) angle = (angle - 360) | 0;
  if (angle < 0) angle = (angle + 360) | 0;
  return angle;
}
```

This is deliberately a single correction, not mathematical modulo: `720 -> 360`, `-361 -> -1`. Signed integer overflow semantics matter for extreme inputs. There are no external dependencies or global writes.

### Radian angle correction (`0x413cd0`)

Compare with `3.1416`; if strictly greater, subtract `6.2832`. Then compare with `-3.1416`; if strictly less, subtract `-6.2832`. Equality at either endpoint is preserved. Unordered x87 comparisons take the NaN through the second subtract branch and return NaN. These constants are the original stored doubles, not `Math.PI`.

### Vector bearing (`0x41bb10`)

For signed-32-bit arguments `(param1, param2)`, calculate `wrapDegreesOnce(trunc(0.5 - atan2(param1, param2) * -57.295))`. This deliberately adds 0.5 before truncation, so negative values do not behave like symmetrical nearest rounding. The recovered JS implementation matches 4,145 original-instruction vector fixtures, including axes and integer extremes, but JS `Math.atan2` is not a complete x87 FPATAN model.

### Random numbers (`0x456ee0`, `0x415a20`)

CRT generator: `seed = (seed*214013 + 2531011) mod 2^32`; result is `(seed >>> 16) & 0x7fff`. Seed is thread-local in CRT state. Initialization calls `time` then `srand` at `0x402a2f`.

The game scales this with integer division: if signed `abs(range)` is less than 2, use range 2; `divisor = trunc(32000/range)`; clamp divisor to at least 1; return `trunc(rand()/divisor)`. This can produce the nominal range endpoint and has unusual behavior for negative ranges. Replacing it with `Math.random`, modulo, or `floor(random*range)` changes outcomes.

### Trigonometric lookup tables (`0x415a60`)

The code constructs indices 0 through 361 inclusive:

```text
sine[i]   = trunc(sin(i * 0.017453529976437735) * 100)
cosine[i] = trunc(cos(i * 0.017453529976437735) * 100)
```

The degree factor is stored at `0x484d40` as double bytes `3152cb9156df913f`, mathematically `1/57.295`. Sine base is `0x4a54a0`; cosine base is `0x4a3450`. Native x87 trigonometric results should be captured as fixtures; browser libm may differ near integer truncation boundaries.

### Apparent wind (`0x429df0`)

Arguments: integer speed in tenths of a knot, boat index. Global inputs: integer true wind knots, angle to true wind, and original integer sine/cosine tables.

```text
x = speedTenths + trunc(cosine[angle] * trueWindKnots / 10)
y = trunc(sine[angle] * trueWindKnots / 10)
pressure = (double(x)*double(x) + double(y)*double(y)) * 0.012
apparentWindKnots = trunc(sqrt(pressure * 0.8333333333333334))
```

Multiplications before division are signed 32-bit integer operations; preserve overflow if supporting arbitrary fixture inputs. Writes: apparent strength at `0x4ab9e8[boat*4]`, apparent angle at `0x4a47f8[boat*4]`. Returns `pressure` in x87 ST0. The exact direction branch graph is:

1. If X is zero, store 90 and return.
2. If Y is zero and the original angle is less than 5, store 0 and return.
3. If Y is zero and the original angle is nonnegative, use 179.
4. Otherwise, if X is positive, use `trunc(atan(y/x) * 57.295)`.
5. If X is negative, use `90 - trunc(atan(-x/y) * -57.295)`.
6. If original angle is greater than 179, use 179.

The constants and special branches are intentional fidelity requirements. Large helper domains, nonfinite inputs, and x87 extended precision need emulator fixture coverage.

The JS translation at `src/engine/apparent-wind.js` matches all 1,960 recorded original-instruction cases for both integer globals and the exact returned binary64 pressure bits. Inputs cover every angle 0..361, winds 0..40, speeds 0..199 and boat indices 1..30. This is bounded fixture evidence, not a claim of complete floating-point or full-game equivalence.

### Additional integer sailing helpers

`src/engine/helpers.js` translates four fully mapped routines against original-address memory. Products and sums wrap to signed 32 bits; divisions truncate toward zero. Native fixtures include integer extremes and negative values.

| Routine | Behavior | Native cases |
|---|---|---:|
| `0x4255b0` | Set tack to -1 for heading-minus-wind difference in `(0,180)` or below -180, otherwise +1; no modulo correction | 328 |
| `0x42a280` | Set spinnaker penalty to 100 below threshold-8, 30 below threshold, otherwise 0 | 305 |
| `0x41ba60` | Schedule next wind time/target with independent random-table cursors, incrementing indices and wrapping values above 300 to 1 | 320 |
| `0x4269d0` | Select a closehauled angle from class/wind/options/offset, then set heading to true wind direction minus tack times angle, with one degree correction | 600 |

All outputs, including residual EAX values, match all 1,553 native helper cases exactly. The native routines `0x4255b0` and `0x42a280` are used for their memory writes; JS returns their residual EAX for reference testing. `src/engine/angles.js` also matches all 528 radian fixtures by exact binary64 bits, including signed zero and inputs immediately adjacent to the original ±3.1416 thresholds.

## Decompiler fidelity and corrected signatures

The initial full export declared `0x429df0` as `void` and modeled `__ftol` without its x87 input. As a result its C text omitted the entire pressure calculation and apparent-strength square root, and callers lost numerical expression inputs. Function presence and a successful export were insufficient evidence of numerically usable C.

Corrections recorded in `decompiled/signature-corrections.json` set `__ftol`'s ST0 argument and signed-64-bit EDX:EAX return, attach a truncate/pop x87 callfixup, and correct floating returns for apparent wind and radian correction. The corrected export restores those expressions. The standalone CRT `__ftol` listing can still show `ROUND` because Ghidra does not directly model the routine's temporary x87 rounding-mode changes; caller casts from the callfixup are the intended truncation model.

The callfixup captures ordinary finite numeric dataflow, not all x87 exception flags, invalid conversions or hardware traps. Generated C remains an analysis aid. Check original instructions and native fixtures before translating other numerical routines.

An independent coverage gap was found after the first complete export: Ghidra did not recognize hundreds of indirectly dispatched MFC message handlers as functions. For example, the 505 selector body at `0x44f850` was absent from `functions.jsonl` even though its message-map pointer is present at `0x48293c`. `analysis/mfc-menu-handlers.json` links 329 menu-dispatched records to their extracted captions. `analysis/message-map-candidates.json` additionally identifies 16 complete, contiguous message tables with 495 records and explicit 24-byte zero terminators. At the time of that scan, 431 records pointed to unrecognized function entries. The main application table runs from `0x482898` to its terminator at `0x484c98` and contains 384 records. These candidates supply evidence for expanding function recovery; a full export of recognized functions alone does not establish full executable coverage.

## Next verification work

The complete encounter leaves are now validated through 9,115 unchanged-code
native reference calls. Their typed maps, exact floating spill boundaries, and
the documented hardware correction to the penalty shift are described in
`analysis/encounter-routines.md`. The connected collision, mark/start routing,
interference, full boat dynamics, and avoidance translations are implemented;
their independent native state captures remain the next validation step.
Full dynamics already matches 300 whole mapped-image emulator debugging cases
when explicitly supplied the emulator's trigonometric reference. Production
uses the hardware captures, so that debugging result does not substitute for
native speed-bit verification.

Use native-function emulation or Wine tracing to capture input state, output state, and call order for the small helpers first, then the full `0x428c60` and `0x42adb0` loops. Preserve integer truncation, original constants, PRNG state, and per-boat update order. Dynamic snapshots and complete race replays are required before claiming that browser behavior is identical. Decompiler output is an analysis artifact; successful export alone is not a validated port.
