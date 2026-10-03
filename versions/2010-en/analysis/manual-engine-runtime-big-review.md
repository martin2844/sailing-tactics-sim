# Manual engine/runtime big review

The review found one low-priority signed `scaledRandom` API mismatch and fixed it. There are no unresolved findings in the reviewed scope. The original helper uses absolute value only for its `<2` guard; larger negative ranges retain their sign for division. A separate 45-call original-code capture proves the corrected return values, RNG and complete memory scope. Normal race callers use positive ranges.

The exact original instruction evidence, before/fix scenario, fixture hash and source hashes are in [scaled-random-native-comparison.json](scaled-random-native-comparison.json). The new proof and unchanged application/controller/AI regressions pass all 37 tests.

Fourteen manual engine/runtime files were read completely. The review checked the guarded PC53 distance operation order and exponent limits, initialization and dynamics, frame callbacks, sequential paint dispatch, asynchronous modal tails, preferences, mouse callbacks, timer wrapping and the data/native authority boundary. Generated keyboard/menu bodies were cleared; their manual wrappers and existing original native evidence were inspected. The generated renderer was excluded from this independent review.

Existing timer, integration and precision-guard checks also pass all eight tests: 636 original native calls and 4,344 supplementary comparisons to the extended helper. No new original calls are attributed to that rerun. Candidate disproofs and exact reviewed source hashes are recorded in [manual-engine-runtime-big-review.json](manual-engine-runtime-big-review.json).

The finite input and explicit Windows host scope remain declared. Root/parity final browser, full-suite and post-fix retained-frame replays determine publication status.
