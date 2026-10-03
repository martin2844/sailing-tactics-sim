# 2010 English numerical engine comparison

Target: `runtime/Tactics2010EnglishPreserved.exe`, SHA256 `d707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787`. The original PE and every runtime edition remain intact. Complete body correspondence is recorded in `engine-correspondence.json`; instruction relocation masking is evidence for a candidate, not a numerical equivalence claim.

The 2010 engine runs x87 control word `0x027f` in the intact application. Shared signed C integer arithmetic, finite Float80 with precision53, the CRT random generator, and the documented transcendental implementation can be reused. Each engine routine uses the 2010 data addresses and constants explicitly. The port does not remap the 2002 global layout at runtime.

## Complete routine correspondence

| Routine | 2002 | 2010 English | Complete body result | Port consequence |
|---|---:|---:|---|---|
| Frame update | `404020` | `4049f0` | Changed from2002; relocated2008 match | Reconstruct its calls and ordering |
| Race initialization | `413f00` | `41be70` | Changed from2002; relocated2008 match | Port all initialization children |
| Boat options | `417790` | `420c00` | Changed fromboth earlier editions | Complete explicit2010 source |
| Global wind | `41b5d0` | `427540` | Changed fromboth earlier editions | Complete explicit2010 source |
| Wind shift schedule | `41ba60` | `427e30` | Relocated complete match | Reuse arithmetic;2010globals |
| AI velocity selection | `4249a0` | `434f70` | Changed | Reconstruct all conditions/constants |
| Boat dynamics | `428c60` | `43a030` | Changed;4491→6968bytes | New complete dynamics routine required |
| Apparent wind | `429df0` | `43bb70` | Changed;326→650bytes | New fullroutine; not old field adapter |
| Clock/position integration | `42adb0` | `43cf60` | Changed | New dependencies, course limits and stores |
| Player1steering | `42b7f0` | `43df50` | Relocated complete match | Reuse control algorithm after data/type audit |
| Player2steering | `42bda0` | `43e510` | Relocated complete match | Reuse control algorithm after data/type audit |
| Penalty display state | `430f90` | `444350` | Relocated complete match |2010globals/OS observation contract |
| One-step degree wrap | `413cb0` | `41bc20` | Relocated complete match | Pure helper reusable |
| One-step radian wrap | `413cd0` | `41bc40` | Relocated complete match | Original3.1416/6.2832constants |
| Scaled random | `415a20` | `41e000` | Relocated complete match | Original CRT draws/truncation |
| Integer trigonometry initialization | `415a60` | `41e040` | Relocated complete match | Native2010 integer tables captured |
| Speed table initialization | `44e380` | `464940` | Relocated complete match | Validate source data/constants separately |
| CRT srand/rand | `456ed0/456ee0` | `49b7a0/49b7b0` | Relocated complete match | Shared generator with explicit state |

There are11 complete relocation candidates against2002 and13 against2008 among these19 routines. Callees, data constants and types still require independent proof even for a normalized body match.

## Confirmed changed behavior

The original2010 boat selector accepts27variants, compared with15 in2002 and24 in2008. These variants select10base classes and subtype flags. The2010 additions include Etchells25(length22, displacement8, sail area10, baseclass6), EScow26(27/5/8, baseclass5), and FlyingScot27(10/6/10, baseclass5). Existing presets also changed. `boat-options.js` preserves every original write and invalid-selector retention behavior;1677 whole-native-state cases pass exactly. The derived flag at`4f4294` uses the original AND test after resetting flags, including its resulting zero in ordinary selector calls.

Command33104 is captioned “Hide Current Indicator” in the preserved English Boat menu, but its original handler`49a120` writes selector25 and Etchells flag`536528`. This source resource defect is preserved; `boat-menu-selectors.json` records original message-map/handler evidence. A browser caption correction must be an explicit separate presentation overlay.

Global wind`427540` includes venue101's35threshold and the complete custom999 branch. Wind initialization uses strength-setting divisors, sector draw79/10+1, venue-specific daily bounds, the venue106 extra random draw, and Optimist tide halving. Wind-patch duration multiplies by a stored binary64 constant at`4da160`, rather than the old integer load. The complete wind/schedule/bearing319/2048/1073 cases and four initialization944/2000/132/616 cases pass native whole-state comparisons exactly.

Geometry also changed: shoreline`42da80` uses continuous x87 `(x+phase)/wavelength` as FSIN input; ellipse`42d280` draws its radius spread from`radius/30`, uses1500 for weather1 and4000 for reversal; advanced terrain`464a30` uses1500 for weather5 and supports the new enlargement/reduction flags. All17 named point constructors are reconstructed from source literal definitions plus complete numerical generation, with1312 native calls passing. Venue4 intentionally omits target copying; venue101 has an index1-dependent initial gap and signedFFFFFFFF gaps. No captured final geometry is used as production source.

Dynamics`43a030` reads the new subtype flags`536528/53652c/536530` in trim, spinnaker and force branches. Its EScow spinnaker threshold97 is present in the original code. AI`434f70` loads2010 multipliers0.99,1.02,1.01,1.04,0.97,1.03 and18.0 from the original constants at`4cc930/4ccaa0/4ccab8/4ccac0/4ccac8/4ccad0/4cca38`. Their complete behavioral effects remain to be captured and ported; matching text in help pages is not rules-engine proof.

Integration`43cf60` uses coefficient25 for course8 or venue5, otherwise20, overridden to17 when`525a9c<2000`, then multiplies time factor`523d48` and divides by stored speed divisor`4da178`. Whole integration is assigned to the root agent. It must preserve these branch and spill changes rather than reuse a2002 global adapter.

## Connected dependency order and native proof

`4049f0` updates global wind, expired wind patches, ascending AI boats, the two steering routines, ascending boat dynamics, then integration subject to`536444`. Exact ordering matters because these calls share mutable state and consume random values.

`41be70` calls configuration`42c060`, wind`426ab0`, tide`427090`, global wind`427540`, wind sources`441400`, starting placement`42dea0(1)`, boat initialization`42b2e0`, and wind patch`42b0b0` for five patches. Configuration calls basic terrain`42da80/42d280/464a30`, all17 named venue constructors, and custom constructor`48b8a0`. Geometry/configuration source must be complete before claiming full race initialization.

`43a030` needs distance`439e80`, apparent wind`43bb70`, interference`43be00`, spinnaker penalty`43c140`, mark/start penalties`43c1e0`, and prestart speed`43c2c0`. Integration needs reset`431960`, target advance`437570`, basic current`42fca0`, venue current`430260`, trails`444760`, waypoint helpers`465e10/465ff0`, and observational sound calls. The larger2010 current/AI/rules functions need their own new source and cases.

The closed2010 native host restores the complete original mutable block`4da000..53a587`, applies typed bounded input patches, sets an explicit CRT seed, calls original fixed function addresses, and verifies unchanged loaded.text/file hashes. It captures all changed byte ranges, full-block SHA256, RNG, sound/GDI requests and typed return values. Strict JS tests reconstruct the expected complete block and compare all bytes and exact floating bits, including preserved fields and outside-block bytes. There are no numerical tolerances.

The next bounded cases cover all defined venue indices, retained flags and placement modes; all basic course/weather geometry paths; custom left/right settings−1/0/1 with their distinct sizes/orientations; configuration's complete venue and course selectors; and connected race initialization. Dynamic functions follow with all27 boat variants, integer angle sweeps, trim/depower edges, mark/start/collision branches and repeated updates. Native transcendental input captures can extend lookup tables if the documented x87 model produces a measured boundary discrepancy. Capturing final game-state outputs as production behavior is excluded.
