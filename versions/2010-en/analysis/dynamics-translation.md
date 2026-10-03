# 2010 English complete boat dynamics

The native JavaScript source is `src/engine/boat-dynamics.js`, translating the complete original routine at `0x0043a030`. The target executable remains unchanged. The simulation uses the original application control word `0x027f`, including 53-bit arithmetic with extended exponent range. Native integer-angle sine/cosine captures are supplied through `options.trig`; continuous nested heel and force phases use the shared `sinCosX87` model and require strict original-code validation.

The eight connected encounter/penalty children in `src/engine/penalties.js` have 1,978 native reference cases comparing every byte of the mutable image, RNG state, integer returns where defined, and ordered sound requests. The `0x43bb70` apparent-wind child has 5,670 exact native cases. Distance, reset and relative geometry children are independently validated by the corresponding edition modules.

The complete dynamics routine now passes **all7,017 native cases exactly** in `tests/fixtures/original-updateBoatDynamics.json`. `tests/boat-dynamics.test.js` compares the entire original mutable block (`0x4da000`, size`0x60588`), exact SHA256, RNG state and every ordered sound request. The capture proves that loaded original text and the executable file remain unchanged. No numeric tolerance or expected-state substitution is used. There were no output mismatches from the continuous trigonometric model in this tested domain; this finite proof does not assert identical vendor transcendental bits for arbitrary operands.

Original dynamics dependencies are `0x43be00` interference, `0x43bb70` apparent wind, `0x43c140` spinnaker drag, `0x43c1e0` mark/start penalties, `0x43c2c0` prestart speed, `0x439e80` distance and `0x41bc20` degree wrapping. No child is substituted with a placeholder.

Important original arithmetic and spill evidence:

- `0x43ac32–0x43ac5e` multiplies integer sail coefficient by the apparent-wind routine's stored force and then the coefficient at `0x4cca70`; the result spills to binary64 before heel calculations.
- `0x43ac84–0x43acb4` forms the human player's nested cosine from wrapped sail angle, stored power, class-specific heel divisor and the original degree factor at `0x4cc568`.
- `0x43acb6–0x43acd1` squares the unspilled cosine first, multiplies stored power, then integer sail area, and stores binary64. The decompiler's reassociated printed expression is not used.
- `0x43af65–0x43af7b` forms the continuous force phase from integer force angle plus the stored binary64 lever, multiplies the original degree factor, executes FSIN, then multiplies stored power and ten.
- `0x43b023–0x43b049` retains the hull-speed operand after an FST binary64 copy and stores the net drive before its square root. The hull ratio and resistance remain on the x87 stack until their original consumers.
- `0x43b52f–0x43b58c` invokes mark/start penalties before computing interpolation. The target-minus-old-speed difference spills to binary64; the time-step multiplication, displacement division and old-speed addition then precede the final store.
- `0x43b9eb` writes a per-boat wind-minus-closehaul heading, and `0x43b9fa` overwrites it with wrapped **global wind minus45**. Both original writes are preserved.
- `0x43bac3–0x43bad5` retains the original shallow-water asymmetry: smooth speed5 and integer speed1. Catamaran grounding has separate thresholds and smooth speed1 for its shallower branch.

The capture manifest is generated from source-validated boat options/reset plus explicit finite inputs. It covers all27 selectors, every sailing angle0..180, wind calibration thresholds, manual and automatic sail controls, both human players, heel, grounding, start-time and turn recovery, finish routing, odd/even refresh gates and actual collision children. Prepared data and original routine outputs remain separate; no captured final-state lookup implements the physics.
