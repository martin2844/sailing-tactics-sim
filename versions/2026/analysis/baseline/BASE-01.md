# BASE-01 evaluation: preservation reference

Completed 2026-10-05. Result: **accepted** against the task's completion condition.
Atomic commit subject: `BASE-01: freeze the 2010 preservation reference`.

The [manifest](reference.json) pins 6,471 inputs to commit
`64d5cdf2d1ce084724a5a87ccc3ec1993176e7c8` and its Git tree. Each file has its
size, SHA-256 and original Git blob identity. Capture compared current bytes
with the actual frozen Git blob before accepting them. This covers 71 edition
source modules, 88 shared source files, 123 edition assets, 120 shared
assets/notices, 5,287 recovered-source artifacts, 230 native-evidence files,
3 executable/provenance inputs, 362 edition/shared verification files,
139 standalone files, 34 final-confirmation artifacts and 14 metadata files.

The exact supplied executable is retained as a reference input; it is neither
modified nor copied into a modern browser application. The pinned compressed
evidence manifests retain identities of expanded native captures. Existing
full-version and Canvas reports are historical inputs, not rerun results.

New work is isolated under `versions/2026/`. Its verification tool is read-only
in `verify` mode. `freeze` refuses a changed reference input and writes the
manifest exclusively, so an existing capture cannot be silently replaced.
Untracked experiments, other editions and machine-local caches are excluded.

The [verification report](BASE-01-verification.json) records a successful
recheck of every file. Temporary isolated probes accepted exact bytes and
rejected a same-length byte change, duplicate paths and an outside-root path.
No sailing-code unit tests were added because this task changes no sailing
behavior; these probes directly evaluate the new integrity tool.

Self-review: source/data/runtime identities, original commit and current
evaluation identities are recorded; no historical evidence was overwritten.
The completion condition is satisfied. Sailing fidelity, complete races,
worker execution and graphics performance remain unverified 2026 work.

Reproduce from the repository root:

```sh
node versions/2026/tools/reference.mjs verify
```

For task implementation history, use:

```sh
git log --oneline -- versions/2026/analysis/baseline/BASE-01.md
```
