# 2026 engine implementation standards

The root 2002 JavaScript player and `versions/2010-en` remain preservation
implementations. New engine and presentation work belongs to `versions/2026`.
Preservation sources are evaluation inputs, not files to refactor in place.

- New modules use strict TypeScript, explicit contracts and readable function
  bodies. Use `unknown` and validation at legacy/transport boundaries. Do not
  extend the old worker's broad `any` types into new engine modules.
- Engine phases must run without browser globals, Canvas/GDI, Three.js, fonts,
  UI state or a drawing callback. During extraction, temporary drawing actions
  are injected through `engine/compatibility`; they are not hidden inside core
  functions. Production independence is incomplete while these actions remain.
- Keep original numerical behavior stable during the lifecycle extraction.
  Temporary address-based storage uses named field maps and narrow memory ports;
  replace it with domain state in a separately evaluated change. Avoid combining
  algorithm, arithmetic, storage and scheduling rewrites in one commit.
- Separate transition logic, physics, command acceptance, timing, state,
  telemetry and presentation. The worker orchestrates those modules. Small
  injected action interfaces let phases be evaluated without a renderer.
- Every authoritative mutation has one engine owner and a declared phase.
  Presentation and diagnostic observers must not change sailing state or RNG.
  Read-only snapshots/events cross the worker boundary; UI does not write memory.
- Preserve ordered input and generation boundaries. Do not drop commands, run
  physics twice or couple simulation steps to display callbacks. Define replay,
  reset and discontinuity ownership explicitly.
- Treat unsupported cases and instrumentation limits explicitly. No invented
  zeroes, constant pixel oracle, guessed RNG burn, broad ignored byte ranges or
  silent fallback to a different reference.
- Keep diagnostic instrumentation optional and bounded. Verify its transparency
  against uninstrumented execution. Restore intercepted descriptors/receivers and
  propagate native errors. Its timing is not a performance benchmark.
- Evaluate one semantic extraction at a time, then commit its code, scope and
  evidence. Use full-state/RNG pairing and real scenarios. Add unit tests for
  meaningful branches and failure behavior; skip implementation-mirroring tests
  and unnecessary tests for documentation or visual-only edits.
- Never replace a reference with current HEAD automatically. Build references
  in an isolated temporary checkout, record identity, and clean up only owned
  resources. Preserve failed evaluation attempts and qualify bounded coverage.

The first extracted controller owns race/panel transition order. Its injected
compatibility actions still draw legacy screens; this is an intermediate bridge,
not a completed renderer-independent engine. Remaining drawing-owned behavior
is tracked by the cutover plan and ENG-03b/03c tasks.
