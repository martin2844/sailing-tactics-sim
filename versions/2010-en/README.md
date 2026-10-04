# Posey Sailing Tactics Simulator 2010 English

A native JavaScript reconstruction of the supplied English preservation build
of the 2010 edition, Release 7J. It uses the 2002 browser port's numerical and
Windows drawing support as a base, with independently reconstructed 2010
simulation, race initialization, opponents, controls, menus and graphics.

## Play

From the repository root:

```sh
npm start
```

Open <http://127.0.0.1:8765/versions/2010-en/play.html>. Press **Space** to start.
The original menus and **?** explain the sailing controls. The footer enables
sound and full screen. Original preferences are stored in this browser as a
636-byte archive, separately from the 2002 demo. The player needs localhost or
HTTPS for its data hash checks. No Wine, Windows executable, x86 emulator or
runtime C interpreter is used by the browser.

Smoother graphics are enabled by default. Drawing uses browser trigonometry
and permits small pixel-rounding differences; the simulation keeps its original
arithmetic. Add `?graphics=exact` to the player URL for the exact drawing math
used by the native comparison tests.

Hidden tabs pause painting and resume with the normal simulation step, without
catching up missed frames. Reload older open tabs after updating so they also
use this behavior. The original **Slow Simulator if Foul Likely** option can
lower the selected speed near another boat; **\\** toggles it. That automatic
speed change is separate from the browser's rendering frame rate.

For a standalone static site:

```sh
npm run build:2010
node dist-2010/serve.mjs
```

The generated `dist-2010/` also works on a static HTTPS host. Its manifest
records every player file and SHA-256; it contains no executable, native proof
fixtures, analysis runtime or decompilation. The repository-root
`posey-2010-browser.zip` packages this export.

## Target and recovered source

The exact input is [Tactics2010EnglishPreserved.exe](runtime/Tactics2010EnglishPreserved.exe),
1,899,520 bytes, SHA-256:

```text
d707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787
```

This supplied English restoration already selects the unrestricted edition.
The port preserves that input. Its native language resources are in the
appended `.english` section, while its simulation remains the 2010 code.
The [localization record](runtime/localization-record.json) preserves the prior
restoration's provenance; rebuilding that separate restoration requires its
Japanese and 2008 reference inputs.

The player is the **full version**: all original fleet choices through 30 boats
are available. Original demo time and session branches remain inactive in the
supplied full mode. The [full-version audit](analysis/full-version-audit.json)
and actual source/standalone browser probes check startup, preferences, menus,
and play beyond the demo clock boundary.

Ghidra exports **5,281 functions and compiler funclets**, with zero failures.
The [recovered C](decompiled/recovered.c), [function index](decompiled/functions.jsonl),
individual bodies, resource inventories and original discovery evidence are
preserved. These are inferred declarations and pseudo-C, not recovered
original source files. Packed arguments and Windows/CString call signatures
were checked against original instructions before JavaScript generation.

The 76 embedded resources retain their identities and byte hashes. Extracted
assets include 312 menu commands, five dialogs, 293 string IDs and twelve
sounds. The port has all 42 original tutorial pages and the original
procedural race graphics. Simulation arithmetic uses the original signed
integer rules, CRT random generator and explicit floating-point stores. The
observed intact application's x87 control word is `0x027f`; shared BigInt
floating-point code and separately captured 2010 trigonometric data reproduce
that precision.

The [edition comparison](analysis/edition-comparison.md) distinguishes the
2002 and 2010 controls, boats, venue data and rules text. One supplied caption
is retained verbatim: boat menu command `33104`, labeled **Hide Current
Indicator**, executes the original Etchells selector. The native instructions,
extracted resource and controller comparisons agree on this mismatch.

## Verify and reproduce

The generator regression tests require Python 3 with `pycparser==2.23`.
Set `TACT_PYTHON` to a virtual-environment interpreter when needed. Otherwise
they use the optional local `tools/python-runtime/bin/python3`, then `python3`
from `PATH`. The browser player itself requires neither Python nor Node.

```sh
npm run test:2010
npm run check:play:2010
python3 versions/2010-en/tools/test_assets.py
python3 versions/2010-en/tools/verify_decompilation.py
```

Run the browser check with a server already running. `TACT_2010_URL` selects an
edition page or standalone export, and `TACT_CHROME` selects Chrome. The check
uses the actual player, original menus and physical keyboard/mouse events,
including race advancement, tutorials, freezing, modal pause/resume and
preference reload. It rejects uncaught browser exceptions and production
requests for executables or proof fixtures. Browser reports are preserved in
[browser-verification.json](analysis/browser-verification.json).

The original port's [review](analysis/big-review.md) and
[publication checks](analysis/publication-verification.json) preserve that
release's findings, source hashes and proof runs. The current performance
update has a separate [review and verification record](analysis/browser-performance/README.md),
including the final test runs, source/standalone browser checks and export hashes.

The [native reference index](analysis/native-reference-index.json) lists exact
fixture hashes and counts original calls without adding overlapping reports.
The native runners execute the unchanged original i386 instructions under
Wine on the host CPU; they verify original code and file integrity, use
explicit Windows host inputs, and record full mutable state, random state,
semantic CString contents, sounds and ordered drawing requests. Physical host
pointer/handle identities are normalized in declared slots, with raw evidence
retained separately. Each JavaScript comparison starts from independently
reconstructed inputs and retained state, never from native output state.

Large captures are committed as exact gzip archives under `evidence/`, with
expanded and compressed hashes. `npm run test:2010` restores them;
`npm run restore:evidence:2010` also makes them available to direct analysis
commands. The standalone player needs none of these expanded captures. The
manifest gives their disk requirement, and restoration preserves an existing
file whose bytes differ instead of overwriting it.

Native capture, source generation, asset extraction, saved metadata correction
and decompilation tools are under `tools/`. Analysis requires Python with the
tools' PE/Capstone dependencies, Wine, a MinGW compiler, Ghidra and Java.
Machine-local runtime links and Wine state are excluded from Git. Captured
runner source snapshots are preserved by hash under
`analysis/native-source-sets/` where the original capture recorded them.
The exact constructor host and intact-dialog observer binaries needed by
provenance checks are checksummed evidence archives. They are never player
inputs. Other compiler outputs and Wine caches remain local.

## Scope of identity

Native comparisons require exact mutable bytes, random state, text, sound
requests and GDI call order for their recorded finite inputs. They do not use
a numerical tolerance. Full-frame proofs retain state between calls and
declare the original caller's phase counter and platform inputs explicitly.
The browser supplies Windows surface/object lifetime and moves original timer
waits into its paint scheduler.

The original island renderer reads two retained, initially undefined caller
stack slots. The browser explicitly starts from the values observed in the
intact supplied application and preserves their subsequent byte aliases.
Bounded native reference hosts have their own separately recorded initial
values. These caller contexts are documented in
[the shoreline evidence](analysis/island-shore-context-native-comparison.json);
arbitrary Windows stack contents are outside the identity claim.

Canvas line and curve rasterization can differ from Windows GDI; browser audio
scheduling and the system beep can also differ. No universal pixel,
sound-device, historical-CPU, nonfinite x87 or every-possible-input identity is
claimed. The [initialization domain](analysis/initialization-domain.md)
documents original unsupported inputs, including 35 boats; the native menu's
maximum is 30. Other editions and their Wine state are not browser inputs.

The performance update removes arithmetic, local-stack and browser scheduling
overhead from the translation. It uses guarded PC53 arithmetic, certified
square roots and projected integer coordinates, bounded caches, and private
scalar/array storage. The original extended arithmetic and byte frames remain
the fallback when an optimization cannot establish the same result. Immediate
frames use browser message tasks; deliberate simulation delays retain timers.

The default-fleet AI crash came from reading an undefined private stack cell
whose value cannot affect the native result outside the two-boat branch. The
translator now checks the fleet before reading that cell; the two-boat branch
and all observable native state remain covered by the original comparisons.
The supplied 2010 executable's full-mode value is preserved without a demo
patch. See the [performance, review and verification record](analysis/browser-performance/README.md)
for measurements, native comparisons and the rebuilt browser downloads.
