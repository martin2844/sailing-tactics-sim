# Tact 2026 implementation

This directory contains the modern edition's implementation and verification
work. Product scope is defined in [PLAN-2026.md](../../PLAN-2026.md); execution
is tracked in [todo.md](../../todo.md). The isolated development scaffold is available; worker and renderer
are being evaluated as bounded prototypes. Preservation players remain under their original routes.

The 2010 reference is commit `64d5cdf`. Its exact source, assets, native runtime,
shared numerical/drawing support, comparison archives and existing evaluation
are pinned in [reference.json](analysis/baseline/reference.json).

Verify those inputs without writing to the preservation trees:

```sh
node versions/2026/tools/reference.mjs verify
```

The `freeze` command is a one-time capture that refuses to overwrite the
manifest and refuses inputs differing from the named Git commit. It is not an
automatic way to accept a changed reference. Expanded native evidence retains
the byte identities declared by the original compressed-evidence manifests.

Run baseline checks in a detached reference checkout. Generated reports and
expanded captures belong there; retain new result summaries under this
directory's `analysis/`, leaving historical evidence intact. Test outputs are
not production inputs.

Completed task evaluations:

- [BASE-01: preservation reference](analysis/baseline/BASE-01.md).
- [BASE-02: reproduced correctness baseline](analysis/baseline/BASE-02.md).
- [BASE-03: natural complete races](analysis/baseline/BASE-03.md).
- [BASE-07: Chrome desktop targets and budgets](analysis/baseline/BASE-07.md).

The baseline collector and reproduction instructions are documented in BASE-02.
Its failed first setup attempt is retained alongside the corrected evidence.

Development (Node >=22.12 or supported Node 20.19):

```sh
cd versions/2026
npm ci
npm run dev
# / development player; /spike/ bounded renderer route
npm run build
npm run preview
```

Dependencies are exact versions in this directory only. prepare:legacy checks
pinned source/asset hashes and generates byte-exact public runtime copies,
without bundling original code. Generated copies and dist are ignored.
Original root commands and preservation routes are unchanged.
