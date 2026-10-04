# Transcendental and scalar-stack review

No unresolved findings. Two storage contract differences discovered during this review have been fixed: signed integer stores now preserve DataView coercion for objects with false pointer fields, and finite extended overflow is rejected at the original later floating load rather than prematurely at its store. The new argument-read helper preserves that timing when a stored double is passed onward.

The exact caches remain bounded to 2,048 entries and use the complete canonical value, signed zero and x87 control word. Returned sin/cos wrappers cannot mutate cached components. Signed shifts preserve the original division semantics.

The 112-bit candidate is safe because its enclosure covers the corresponding original 224-bit integer result. For sine/cosine, the term recurrence, finite termination and alternating tail give an error below 262 fast units. For atan, the corresponding bound is below 240 fast units plus 10,000 original units, still below 241 fast units. The production interval allows 1,024 fast units. Acceptance requires both endpoints to normalize to exactly the same m80 value; domains, iteration guards, near zero and ambiguous rounding all retain the original path. The Machin PI and x87 66-bit quadrant reduction remain unchanged.

An independent direct-division integer implementation checked 8,274 sine/cosine components and 32,920 signed atan quadrant results. The largest observed differences were below 3.846 and 6.377 fast units respectively. This sampling corroborates the analytical enclosure; it does not replace its derivation or claim universal native-vendor instruction equivalence.

Static promotion only applies to private, disjoint fixed-width slots whose addresses and write results cannot escape. Explicit retained bytes use the complete byte frame. Independent regeneration matched all 251 baseline routines, including 113 promoted routines. All 15 focused transcendental/native/precision tests, 11 scalar/native drawing tests, and four generator boundary tests passed.

The companion [JSON report](transcendental-scalar-review.json) contains the complete derivation, resolved findings, commands, scope limits and final source hashes. Browser timing and the broader retained-frame/native suite are reported separately.
