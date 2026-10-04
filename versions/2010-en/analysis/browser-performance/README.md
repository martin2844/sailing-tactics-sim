# 2010 performance update

The final 20-boat headless Chrome comparison against commit `fb856db` reduced
mean paint time from **862 ms to 181 ms**, about **4.8× faster**. Measured frame
rate increased from **1.15 to 5.40 FPS**. The original Round Lake, Keelboat,
Windward course, simulation and drawing remain enabled. Additional actual
2-boat and 30-boat runs completed in full mode without browser exceptions.
Short samples include startup/JIT effects; scene phase and CPU/browser costs
vary, and heavy scenes still have limited frame rates.

[verification.json](verification.json) pins the final production modules,
test/browser receipts and both browser ZIPs. The `.cpuprofile` files accompany
the four final timing reports. Reproduce a measurement with a server running:

```sh
node tools/profile-2010-browser.js current
TACT_PROFILE_FLEET=30 node tools/profile-2010-browser.js current-thirty
```

The update uses exact binary64 carriers only where the x87 PC53 result is
proved representable, with extended arithmetic for other cases. Square-root
candidates require an exact integer rounding certificate. Smaller
trigonometric series require matching m80 rounding of both endpoints of a
conservative error enclosure; ambiguous cases use the original 224-bit series.
Caches remain bounded and preserve every relevant input bit and signed zero.

The generator promotes 113 private, nonoverlapping stack layouts to scalar
variables. Escaping/aliased layouts and explicit retained bytes use the complete
byte frame. All 251 original byte-frame bodies remain preserved. The player
also reuses its reset drawing surface and omits unused diagnostic event arrays.

Final validation passed **379 tests for 2002 and 354 for 2010**, including
**438 retained 2010 full frames** with exact state, random state, text, sounds
and ordered GDI requests. Source and standalone players each passed 119 browser
checks and seven full-version checks. The shared runtime also passed the ten
2002 player checks. Original native expectations and executable bytes are
unchanged. Existing limits on Canvas rasterization and universal x87 identity
remain as documented in the edition README.

The independent [numerical review](numerical-review.md) and
[trigonometric/scalar review](transcendental-scalar-review.md) have no unresolved
findings. They found and fixed byte-array replacement caching, nonsemantic I32
coercion, and premature errors when an extended value spills to infinity but is
overwritten before being loaded. The earlier port-release reports are historical
evidence; this directory contains the current optimization verification.
