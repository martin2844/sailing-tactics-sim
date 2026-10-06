# ENG-03a — Paired cutover runner and phase ledger

Accepted bounded foundation, 2026-10-06. This does not remove the lifecycle.

A pinned, detached checkout of `ce6d9bf` provides the 2026 oracle. The runner
builds it outside the working tree, serves both built workers on an isolated
local server, and disposes its own browsers/worktree/server afterward. Worker
artifact hashes and the full reference revision are recorded. Updating HEAD
never silently updates the reference. The existing frozen 2010 reference is a
separate comparison lane, with 2026 geometric contacts disabled there.

Four scenarios pass: five/fifteen Keelboats, five Tornados in strong wind and
five Island Optimists with west wind. All 33 paired boundaries compare every
image byte plus exact RNG, simulation time/clock/frame and retained shoreline
context for both the plain candidate and instrumented candidate. Three cases
run 634 actual native steps each, reaching real racing; the fifteen-boat case
covers prestart. Frozen 2010 five/fifteen-boat lanes each pass initialization and
four eight-step boundaries with native port/starboard/tack inputs. This is
bounded phase coverage, not full-race or every-option certification.

The strict TypeScript observer captures nested phase ownership, method reads and
writes (including writes restored before return), net word changes, actual pixel
queries, exact RNG boundary states, draw counts and an ordered diagnostic digest.
Full-image/RNG pairing, not the digest, determines acceptance. Captures are
bounded and a truncated ledger fails this evaluation. Private copied memory and
RNG use are excluded. Normal play does not install the observer.

Limits: direct DataView/byte-array intermediate stores can bypass method hooks;
full phase deltas catch net effects but not restored direct writes. Callback
registries not exposed through options are attributed to the enclosing phase.
Access lists aggregate counts rather than record all values/order. Static source
inventory and expanded branch-specific tracing remain required for extraction.
Inclusive parent counts must not be summed as independent operations.

Five meaningful observer tests pass: transparency/nesting/restored and raw
writes, exception forwarding, installation rollback, bounded pixels and borrowed
method receivers. Build/type checks pass. The initial browser launch failure
(missing trailing URL slash) happened before either engine started; it is retained
under `cutover-pairing-2026-10-06`. Corrected evidence:

- [verification](cutover-pairing-retry-2026-10-06/verification.json)
- [phase ledgers](cutover-pairing-retry-2026-10-06/phase-ledgers.json.gz)

Reproduce after `npm run build`:
`node tools/cutover/evaluate.mjs NEW_OUTPUT_DIRECTORY` from `versions/2026`.
No original 2002/2010 source is edited by instrumentation or reference building.
