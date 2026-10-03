# English 2010 rendering recovery

The browser uses static JavaScript recovered from the preserved English target,
SHA256 `d707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787`.
It does not execute, interpret, or load original instruction bytes. The 2002
edition's drawing routines and addresses are not used by this renderer.

`src/render/index.js` exposes `createOriginalRenderer()`, with the original scene,
chart, HUD, compact HUD, advice, start, results, forecast and pause entrypoints.
The drawing graph has 198 generated functions and zero unresolved static
dependencies. Separately generated modules contain 42 tutorial pages, eight
screen/advice roots, and three screen helpers. Reviewed edition-local numerical
functions supply sail geometry, wave motion, waypoint distances, venue current,
and venue metrics. Two small CString receiver helpers preserve the actual
data pointer and the observed string-length header field. These counts describe
source closure, not independent proof
of every possible execution path.

The recoverable C required exact packed stack signatures and indirect CDC/WinAPI
call contracts. The `*-abi-review.json` reports
preserve original caller instruction windows and cleanup evidence. The signature
scripts are applied by `tools/decompile.sh`; canonical recovery currently exports
5,281 functions with no reported decompiler failure. The recovered C remains
analyst output rather than original source.

The final static argument audit checks 251 translated routines and finds zero
caller/callee expression-count discrepancies. This is a useful structural check,
not proof that every arithmetic expression or execution path is correct. The
original-instruction ABI reports and complete native comparisons establish the
individual behavior claims below.

The aligned-stack HUD alias recovery retains a separate symbolic stack namespace
after the original `AND ESP, -8`; it never assumes values for prior local bytes.
The static original CALL evidence agrees with 2,575 overlapping native callback
observations, with no disagreement. This repairs saved TextOut aliases in fresh
normal startup branches, alongside the separately observed snapshot notice.

Two shared translation defects were found through complete native comparisons:
double-pointer reads and writes used four bytes, and byte-copy loops had lost
their original literal addresses. The pointer-width and character-pointer audit
files retain original instruction evidence. Forecast's stack slots falsely typed
as CString objects are represented as actual byte-addressable local storage.
The scene helper's `local_260` is an original low/high DWORD binary64 construction;
its exact reinterpretation is pinned to the original MOV and FLD instructions in
`scene-binary64-constant-construction.json`. Unknown local bytes stay unknown and
raise if an executed branch reads them; an unused argument can transfer those
bytes without inventing a value.

Native references execute the unchanged original under Wine, using the confirmed
startup x87 control word `0x027f`. GDI requests, explicit host pixel inputs,
ordered sound requests, RNG, all 36 semantic global CString cells, and every
mutable game byte are compared. Owned CRT bookkeeping and allocator pointer
identities are declared normalizations with raw evidence retained. Ordered GDI
request parity is distinct from raster output or an unrestricted Windows window
lifecycle claim.

Verified standalone scope is recorded by fixture hashes in
`tutorials-native-reference-comparison.json` (1,848 calls across all 42 pages),
`closed-drawing-native-reference-comparison.json` (480 calls), and
`hud-native-reference-comparison.json` (72 calls). The separate
`hud-branches-native-reference-comparison.json` adds 26 original calls covering
13 actually observed HUD text branches at two widths. All 30 retained initialized
screen calls also pass `tests/initialized-screens.test.js`. The retained-frame
tests additionally pass four genuine race initializations and 400 successive
full `0x4049f0` calls: prestart course 1, genuine class 7/course 8 racing, venue 5
with two human boats, and a profile retaining all 90 constructor GDI handles.
They compare the same complete state, strings, RNG, sounds and drawing requests
while retaining preceding frame outputs. Standalone proof does not substitute
for that connected comparison. The 400-frame run took 459.8 seconds on this
workspace; that is a historical timing, rather than a current browser frame-rate
claim. The guarded PC53 waypoint helper's subsequent exact performance proof is
recorded separately in `production-pc53-distance-review.json`. The
subsequent 400-frame regression with shoreline persistence also passes all six
checks (`retained-frames-shore-replay.log`, 461.1 seconds).

Island vegetation reads two original predecessor array cells before defining
them. These are caller stack inputs, rather than C initializers. The bounded
observer captures two independent ten-call runs: four original initializers and
16 retained full scenes. `tests/island-shore-context.test.js` compares all game
bytes, strings, RNG, sounds, ordered GDI requests and pixel reads. The persistent
model restores only the two observed cells and then carries their actual bytes;
the overlapping POINT write updates the predecessor X cell. Missing caller input
continues to raise when consumed.

Two separate intact application launches following the original Round the
Island, Start and display menu path observed the first consumed X/Y values
`604045502` and `0`, with control word `0x027f`. The source and raw observation
hashes are retained in `intact-island-shore-stack.json` and the browser's explicit
`assets/data/initial-shoreline-stack.json` reference. This is a selected Wine
caller context, not a claim that uninitialized stack values are portable or
universal. The standalone bounded host has its own measured caller values,
which its fixtures preserve separately. Each renderer instance owns one model;
it does not reset these cells each frame.

The full-frame Round the Island caller has a separate native observation: its
first consumed predecessor cells are X `12484608` and Y `40`, rather than the
intact application's selected caller values. A persistent model seeded with
those observed inputs passes the separate 21-call retained controller fixture,
including ten complete frames and eight actual input handlers. These different
contexts stay explicit; the browser asset is not used to seed that native host.

The fresh initialized island chart proof also checks eight unchanged original
calls and 227 ordered drawing requests, including separate prestart and bounded
clock-zero inputs. The latter explicitly sets the timer and race clock after
initialization and does not claim native elapsed-time continuity.

The initialized venue proof covers 16 retained original calls and 12,712 ordered
drawing requests across venues 2, 6, 9 and 106. Venue 106 exposed a PC53
multiplication association defect: original `scale * two-thirds` precedes the
integer width product. The pinned original instruction ordering restores width
6 instead of 7 without changing native expectations. The evidence is preserved
in `venue-roof-multiplication-order-review.json`.

Regenerate static sources after canonical metadata corrections:

```sh
python tools/translate_drawing.py
python tools/translate_drawing.py --screens
python tools/translate_drawing.py --helpers
python tools/translate_drawing_closure.py
```

Run from `versions/2010-en`, with the documented pycparser, pefile and Capstone
dependencies available. Recheck native tutorial proof with
`python tools/verify_tutorials.py`; screen/HUD proof tools are
`verify_closed_drawing.py` and `verify_hud.py`. The test fixtures preserve their
original native outputs, without tolerance or fitted output tables.
