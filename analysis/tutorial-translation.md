The complete original pause dispatcher at `0x41bb40` is implemented in
`src/render/tutorials.js`. Its39 children include the previous-race results
screen at `0x41beb0`. Resources owns the eight basic text pages in
`src/render/tutorial-basics.js`; the31 remaining pages are in
`src/render/tutorial-pages.js`. The three original drawing controls are in
`src/render/tutorial-controls.js`.

The31 pages are emitted as static JavaScript by
`tools/translate_tutorial_sources.py`, using the reviewed CString/CDC signatures
in `analysis/screen-corrections`. `analysis/tutorial-translation-sources.json`
records each complete source's address, selector and SHA256. This build step
requires pycparser2.23; the pinned requirement is in
`tools/tutorial-translation-requirements.txt`. The locally extracted wheel has
SHA256 `e5c6e8d3fbad53479cab09ac03729e0a9faf2bee3db8208a550daf5af81a5934`.

The generated functions contain their own fixed JavaScript control flow,
original data addresses and calls to reconstructed renderer dependencies.
No original machine instructions or C source execute in the browser.
Unsupported syntax and callees stop source generation. `tutorial-source.js`
preserves signed32 integer arithmetic, signed64 intermediate casts, Float80
operations, local arrays and CString byte content. Windows CString allocation
identity is outside this drawing contract. The generated CFG cases are fixed
source-level branch targets, rather than an x86 instruction interpreter.

Validation uses all5,760 complete original calls in
`tests/fixtures/original-tutorials.json`:39 pages×128, three controls×128,
and384 dispatcher cases. Inputs include all15 prepared boat selectors,
tutorial phases0..15, viewport sizes and monochrome modes. Strict source tests
compare the complete mapped image, merged image-store ranges, ordered GDI
requests and RNG. The native confirming report is
`analysis/tutorials-native-reference-comparison.json`; its1,631 measured
emulator differences affected only floating stored state. All original ordered
drawing requests, RNG and sounds already agreed. No tolerance is applied.

These isolated fixtures use CW037f, precision64. Actual application startup
uses CW027f, precision53. The runtime supports selectable precision, but the
isolated proof is not a substitute for the separate connected startup/frame
validation. Canvas raster/font rendering is also distinct from equality of the
original ordered GDI requests.
