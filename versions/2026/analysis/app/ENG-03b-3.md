# ENG-03b-3 — Extract compatibility camera state

2026-10-07. Both legacy view-state writers (0x41e0a0/0x41e220) now delegate
to a renderer-free TypeScript phase with named ports. It retains automatic
viewpoint gates, near-mark selection, signed offset normalization, tack offset,
windward/leeward modes and the asymmetric other-boat mode for player two.
Address mapping and exact bearing/integer conversion stay in compatibility
adapters; no GDI/Canvas or original drawing function is called by the kernel.

Two focused tests pass: 2,048 public/numeric comparisons over both player slots,
player counts, modes, automatic/manual settings, prestart time boundaries,
signed offsets and very large target coordinates; fourteen away-from-mark
checks verify the actual automatic viewpoint boundaries. Every comparison uses
the full image and RNG. Signed DWORD and I64-low-DWORD conversions are retained.

[65 current-2026 paired boundaries and ten frozen 2010 boundaries](cutover-camera-2026-10-07/verification.json)
pass, including prestart/racing and forecast/course/coach/key panels. Both plain
and traced candidates match the immutable oracle, including every image byte,
RNG, simulation clocks and retained shoreline context. Build/type checks pass.
[Phase ledgers](cutover-camera-2026-10-07/phase-ledgers.json.gz) are untruncated.

The owning invocation is still in the compatibility world traversal. Modern
free-camera movement stays separate from authoritative legacy compatibility
state. Scene/pixel/shared-randomness removal remains open.
