# BASE-02 evaluation: reproduce the 2010 baseline

Completed 2026-10-05. Result: **accepted** against the task's completion condition.
Atomic commit subject: `BASE-02: reproduce and evaluate the frozen 2010 baseline`.

All checks ran against the detached reference checkout at commit `64d5cdf`,
served by an owned localhost server. Generated legacy reports stayed in that
checkout. New evidence is retained here; the preservation workspace's original
reports and player inputs were not overwritten.

## Results

| Gate | Observed result | Evidence |
| --- | --- | --- |
| Original 2010 suite | First run: 476 passed, 13 failed because `pycparser` was unavailable; all 22 tests in the five affected files passed after correcting the environment | [First log](BASE-02-run-1/2010-tests.log), [remediation](BASE-02-run-2/2010-tests-remediation.log) |
| Complete evaluation suite | 57 passed, 0 failed | [Complete gate](BASE-02-run-2/evaluation-complete.log) |
| Deterministic setup suite | 5 passed, 0 failed | [Setup gate](BASE-02-run-2/deterministic-setup.log) |
| Exact asset extraction | Existing 5 integrity tests passed | [Asset checks](BASE-02-run-2/assets.log) |
| Recovered source integrity | 5,281 function bodies and recovery evidence verified, 0 failures | [Verification](BASE-02-run-2/decompilation-export-verification.json) |
| Actual source player | 119 existing browser checks passed | [Source report](BASE-02-run-2/source-browser.json) |
| Actual standalone player | 119 existing browser checks passed | [Standalone report](BASE-02-run-2/standalone-browser.json) |
| HUD interactions | 18 checks passed in each of three wide/narrow/smooth/exact configurations | [HUD report](BASE-02-run-2/hud.json) |
| Exact/smooth real Canvas | 417 engine-prefix traces and 420 completed paints per run; no declared state/trace differences | [Canvas comparison](BASE-02-run-2/canvas-parity/smooth-graphics-canvas-coupling.json) |
| Bitmap font pixels | 160 headed GPU comparisons matched native RGBA references | [Font report](BASE-02-run-2/font-atlas.json) |
| Source full-version behavior | 7 checks passed; supplied mode 0, original fleet choices through 30, preferences and declared clock-boundary cases | [Source full-mode report](BASE-02-run-2/base-02-full-version.json) |
| Standalone full-version behavior | The same 7 checks passed against the exported player | [Export full-mode report](BASE-02-run-2/base-02-standalone-full-version.json) |
| Static export and archive | All 138 manifest entries validated; all 139 ZIP entries matched export bytes | [Archive check](BASE-02-run-2/export-and-zip.log) |
| Preservation integrity | All 6,471 pinned workspace inputs still match; detached checkout matches 6,470, with only its intentionally regenerated browser report excluded | [Run report](BASE-02-run-2/report.json) |

The 476 first-run passes and 22 remediation passes are separate collections.
They must not be advertised as one new all-suite execution or added to historical
native-call counts. Runtime comparisons use existing independently captured
native fixtures; this task did not recapture the original executable under Wine.

## Failure disposition and collector review

The [initial report](BASE-02-run-1/report.json) remains failed. Its generator
failures occurred because the detached checkout lacked the ignored local
`tools/python-libs` package tree. The existing Python interpreter had the PE
dependencies but did not itself contain `pycparser`. The corrected collector
uses the existing local library path, verifies `pycparser==2.23` before testing,
and retains the dependency identity in its log. No reference source or expected
fixture was edited to resolve the failures.

The first attempt also found the configured port already serving another
process. It refused to test that server. The corrected collector launches its
own server on an ephemeral port and records the owned process/address. Existing
servers were left alone.

Successful restoration/asset/decompilation/evaluation checks were reused only
after their retained log hashes matched. All five failed test files were rerun
in full. Both old and new collectors and their hashes are retained, so the
corrected evidence does not rewrite the first attempt's provenance.

Self-review found two omissions in the initially selected evaluation test list.
The [extension report](BASE-02-run-2/verification-extension.json) records the
complete six-file 57-test gate and the five existing deterministic-setup tests.
Additional test inputs were matched to the frozen Git blobs and hashed. The
collector's future default now selects the complete evaluation list.

Self-review also limited resume to the reviewed pre-browser dependency failure.
Reusing a later browser stage could copy an already overwritten report under
the wrong identity. A [bounded collector check](BASE-02-run-2/collector-review.json)
confirms that such reuse is rejected before creating output or launching a
process. Source and standalone reports are copied separately by URL identity.

No new sailing-code unit tests were added. Existing tests and direct collector
probes supply the task's needed evidence. There are no unresolved failures in
the required finite baseline checks after the documented remediation.
Raw process logs retain their original bytes, including error-output whitespace;
the local Git attribute excludes those data files from whitespace linting.

## Scope and next gate

The legacy browser script prepares a one-finisher input to exercise its results
menu. Its full-version script prepares clock 261 to exercise the original demo
gate. Those are declared finite test inputs, **not** evidence of a naturally
completed race or naturally elapsed session. This task does not claim complete
race stability, new graphics smoothness, a modern replay or touch support.

`BASE-03` must collect real starts, mark progression and finishes through original
controls. `BASE-04` must inventory drawing side effects before extraction. The
2010 supplied full-version identity and source/export behavior are confirmed for
the existing baseline without changing the edition mode.

For a fresh reproduction, first create a new detached checkout; checks intentionally
generate reports there:

```sh
git worktree add --detach /tmp/tact-2010-reference 64d5cdf
node versions/2026/tools/baseline-checks.mjs \
  --root /tmp/tact-2010-reference \
  --output /tmp/tact-2026-baseline-results
```

Use unused directories. Set `TACT_PYTHON` to an interpreter with the documented
analysis dependencies when the optional local interpreter is unavailable. A
local `tools/python-libs` installation is used if present. The collector writes
only its new report directory and the detached checkout, and closes its owned
server/browser sessions. Browser checks require the configured Chrome executable;
the headed font check also needs the desktop display.
