# Final 2010 port review

No unresolved findings.

The review covers the unpublished 2010 port and its shared browser/publication
changes against the already published 2002 commit
`69f17e67ae2bd227491e0e8b187eea554861235e`. The intended behavior is native
JavaScript reconstruction of the supplied 2010 English preservation build,
using the existing numerical and drawing infrastructure. The original target
and native expected states were unchanged.

## Cleared

- Recovered C bodies, binary resources, captured expectations and compressed
  evidence: generated or immutable inputs, checked through exact hashes and
  original instruction evidence rather than reviewed as authored code.
- Generated AI, drawing and controller bodies: the generators, instruction
  guards, ABI declarations and manual wrappers were reviewed. Independent
  isolated regeneration reproduced all fourteen outputs byte for byte,
  including the final AI correction. The drawing closure has 198 functions
  and no unresolved dependencies. See
  [generation-reproducibility.json](generation-reproducibility.json).
- Export copies and ZIP entries: checked against the actual source graph,
  assets and file manifests. Browser exports contain no executable or proof
  fixture.

## Findings fixed

1. **High: sailboard AI read the speed array with a byte offset.** The
   original instruction at `0x435e2b` reads an I32 array with stride four.
   The old translation gave some completed nonhuman turns an extra five
   degrees. It failed twelve of 384 new cases and a real menu/start/full-frame
   continuation (heading 61 instead of 56). The corrected generated scalar
   translation passes all 384 cases, the three-frame continuation and the
   existing 8,366 AI calls. The preserved old source reproduces the failures.
   [Original bytes and exact before/after evidence](board-turn-native-source-comparison.json).
2. **Medium: two provenance checks depended on unpublished private files.**
   In a clean checkout the application and modal behavior matched, but their
   provenance checks tried to read ignored compiler/observer paths. The
   exact historical compiler inputs are now public content-addressed source
   snapshots; the two recorded host binaries are exact checksummed archives.
   Their checks pass from the staged checkout without the private paths.
   [Fresh-checkout evidence](fresh-staged-focused-validation.json).
3. **Medium: one historical observer source record hashed the source before
   insertion.** Its separate compiled-main field already held the correct
   hash. A narrowly bound annotation preserves both records and the actual
   compiled source without changing frozen expectations. Future captures
   record every source after insertion.
   [Correction evidence](retained-shore-capture-source-provenance-annotation.json).
4. **Low: exported scaledRandom mishandled negative signed ranges.** The
   original takes absolute value only for its small-range guard. Reusing the
   exact shared helper restores signed division and RNG behavior. All 45
   new original-code cases and affected application/controller/AI checks
   pass. Normal gameplay calls use positive ranges.
   [Native helper evidence](scaled-random-native-comparison.json).

## Checked clean

- Manual engine/runtime: arithmetic stores and signedness, retained state,
  initialization, original callback order, asynchronous dialog tails,
  preferences and wrapped timers. Fourteen complete files were independently
  reviewed. [Review record](manual-engine-runtime-big-review.json).
- Rendering: complete manual typed-C, text, host, shoreline and dependency
  adapters; both drawing generators and their ABI/instruction guards; object
  ownership, pointer strides, finite numerical conversion and dispatch.
  Native ordered GDI/text/sound/state comparisons cover the generated paths.
- Browser/publication: actual menu/input wiring, module-relative data loads,
  modal scheduling, error propagation, preference separation, build closure,
  evidence restoration and test discovery. The strict native-state harness
  rejected altered state, RNG, return and native input bytes.
  [Independent review](browser-publication-big-review.json).
- Native proof tools: owned compiler input snapshots, original code integrity,
  bounded transport, semantic strings and complete decompilation verification.
  [Tool review](proof-tools-review.json).
- Final publication changes: all ten compiler-source bundles and 75 native
  runner mappings, exact archived historical hosts, archive-only restoration,
  and ten isolated idempotence/corruption checks.
  [Final independent review](final-publication-delta-review.json).

Final source and standalone browser checks each pass 119 interactions without
uncaught exceptions. The final corrected engine passes 400 retained frames,
35 frames connected to real controller calls, and the three sailboard frames.
The 69-file production snapshot has no source drift. These results and the
layered clean-checkout validation are linked in
[publication-verification.json](publication-verification.json).

The identity scope remains finite native input/state and ordered host calls.
Canvas rasterization, audio device timing, historical CPU speed, nonfinite
floating-point behavior and arbitrary initial Windows stack contents are
outside that claim. See the edition README for the observed shoreline caller
context and original unsupported inputs. No universal every-input equivalence
is asserted by this review.
