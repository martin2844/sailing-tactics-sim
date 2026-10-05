# Expanded player journey review (EXT-07)

Scope: the requested original-feature expansion, including committed mark/follow,
names, result/event flow, and the complete boat/course/environment changes. The
big-review workflow covered the intent and caller contracts, full application
files, engine ownership, private geometry/RNG isolation, state after failure,
resources/generation lifetime and whether the evaluations actually exercise the
claimed behavior. Parallel read-only reviews covered event/UI and graphics/state
angles. Generated evidence and frozen inputs were excluded from style review.

Findings fixed and evaluated:

- Around Block Island's selected course now matches its native fixed course 3;
  its original offshore racer and incompatible short/gate options are normalized.
- Header fleet changes clear an unsupported gate and update native settings,
  rather than leaving a gate/fleet mismatch that fails initialization.
- Explicit `gate:false` on fifteen boats is excluded from the audited-default
  hash assertion because the original gate toggle adds a setup paint.
- Distance area commands run after offshore selection; otherwise original setup
  immediately changes the selected area back to North shore.
- All-venue drawing exposed recovered-source chart/invalid-conversion errors.
  Instruction-proven generated adapters and explicit oracle declarations are
  documented in `CATALOG.md`, including the CPU x87 probe. No preserved source
  was changed or unknown authoritative retained byte supplied to the candidate.
- Large-course overview had a finite water edge and depth/facet aliasing. A
  bounded outer sea, adaptive near clipping and distant facet culling fix the
  inspected Around Block view without adding simulation behavior.

The setup corrections are exercised by `selection-review2/verification.json`:
actual native startups, fixed-route readback, a twenty-boat gate followed by
header selection of five boats, and an isolated fifteen-boat explicit false gate
client. `expanded-lifecycle1` exercises moving rendered RGBA frames, paused
camera isolation, three scheduler pause cycles, fleet restart, actual WebGL
context loss, disabled controls and recovery. `expanded-starter1` uses trusted
Start/settings controls and checks held setup, restart, visibility and retired
worker ownership. The naturally sailed three-race event in `event-sailing4`
provides original finish/scoring/Next evidence; controlled result packets and
longer-event ledger tests are separately labeled in `CHAMPIONSHIP.md`.

`catalog-complete` retains all 76 selected source comparisons, not a cross product
or a natural race for every configuration. `environment9` compares nine native
shore/current families at four controlled private depths, not naturally sailed
grounding. `expanded-model1` and `expanded-sail1` preserve native geometry and
master boundaries under their declared private display cases. Source-mode
readback is zero (full version) in every catalog case.

Smoothness evidence: five hardware Chrome WebGL 2 runs and five requested-WebGPU
runs (actual WebGL 2 fallback on this machine), combined in
`expanded-renderer-complete/verification.json`. Existing budgets are unchanged.
The first fallback attempt lost compositor focus and stopped receiving RAF while
its native worker continued; its failure is retained, not counted as a pass.
A second focus helper attempt failed explicitly before measurement. The corrected
helper uniquely identifies the evaluator-owned browser PID/window, uses the
installed Hyprland API and verifies the active compositor window before timing.
It does not alter Chrome flags, scene quality or numerical acceptance thresholds.
API reference: https://wiki.hypr.land/0.55.0/Configuring/Basics/Dispatchers/ .

The final report records actual renderer cadence, worker/model cost, trusted
camera latency, geometry and transport budgets. GPU timings unavailable on the
fallback are reported as unavailable. Camera changes preserve the paused entire
native image/RNG/shore boundary. No runtime evidence/EXE/decompiled files are
fetched by the application.

Limits: default fifteen-boat Round Lake performance is certified only for the
recorded Linux/Chrome hardware/surface. All coastal paints, thirty-boat fleets,
class/venue cross-products, physical Pixel 11, native WebGPU, replay/export,
network/startup and complete broader MVP acceptance remain separate work.
