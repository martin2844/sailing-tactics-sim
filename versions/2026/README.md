# Tact 2026 implementation

This directory contains the modern edition's implementation and verification
work. Product scope is defined in [PLAN-2026.md](../../PLAN-2026.md); execution
is tracked in [todo.md](../../todo.md). A playable modern edition does not exist
yet. Preservation players remain under their original routes.

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
