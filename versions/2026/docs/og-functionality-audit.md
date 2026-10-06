# 2010 functionality and 2026 architecture audit

Audited 2026-10-06, after restoring original penalty responses. This is an
inventory of the current implementation, not a claim of complete native parity.
The original menu has 312 leaf commands; the extracted inventory and a disposable
worker probe are in [audit evidence](../analysis/app/og-functionality-audit-2026-10-06/).
No preservation files were modified.

## What actually runs

**Yes: the recovered 2010 simulation runs underneath the modern presentation.**
It runs as JavaScript functions, not the Windows executable, Wine, an emulator,
or executable machine code in a browser. `original-data.js` loads nonexecutable
constants, initial mutable data and English text. Its address-space byte array
retains the original layout; Float80 and integer helpers preserve the recovered
arithmetic. AI, wind, gusts, currents, boat dynamics, race targets and native
scoring mostly remain the translated 2010 routines.

The authoritative engine worker still invokes **the complete original paint
lifecycle on an offscreen 1024×768 canvas**. This includes old drawing routines,
pixel reads and retained drawing state. The old program mixed simulation and
painting; eliminating that lifecycle prematurely would change behavior. The
worker advances the game once per simulation paint and publishes snapshots.
Three.js/WebGL2 draws the visible scene from those snapshots, with interpolated
poses, new water, land, objects and UI. Original penalty relocation is presented
immediately rather than interpolated through the fleet.

Boat meshes also reuse recovered drawing logic: a separate graphics worker
copies the simulation data, captures native boat faces at calibrated projections,
and reconstructs 3D geometry, with modern crew/mesh work. Forecast/chart/coach
panels invoke original routines on private copies. Neither operation advances
or mutates the authoritative simulation.

Consequently, this is a **native JavaScript port with a new 3D presentation**, but
not yet an independent, cleanly separated engine. The unfinished ENG extraction
tasks in root todo.md describe that remaining work. The earlier ENG-02 parity
report proves the bounded baseline worker, not parity after every 2026 feature.

Sources: [engine worker](../app/engine.worker.ts),
[model worker](../app/models.worker.ts), [model extraction](../app/native-models.ts),
[information capture](../app/native-information.ts), [scene](../app/scene.ts),
[explicit build adapters](../tools/prepare-legacy.mjs).

## Feature coverage

“Available” describes reachable behavior with existing evidence, not exhaustive
verification of every combination. “Backend only” means translated code exists,
but is insufficient to call the 2026 feature complete.

| Original feature | Current 2026 status | Remaining work |
| --- | --- | --- |
| Sailing AI, shifting wind, gusts, current, depth and grounding | Available through recovered simulation | Continue scenario regression; modern waves are presentation rather than a new hydrodynamic model |
| Boat classes, existing venues, seven courses, short courses, gates, fleets | Available through modern setup, subject to compatibility rules | Full cross-product sailing certification is not implied by preview/catalog coverage |
| Tack/jibe, trim, sail shape, headsail, spinnaker, steering keys | Original handlers reachable | Add better visible trim/luff/sail-state feedback; verify context-sensitive shortcuts separately |
| Penalties, black sails, early-start recall | Original response/grace restored; geometry detection is new | Contact timing differs from original centre-point proximity; retain paired response checks |
| Start/finish, positions, results, three-race series | Available with modern screens | Modern longer championships and 20-minute fleet cutoff are explicit extensions |
| Wind forecast/history, wind/current charts, zoom, tide +1 hour | Available through modern private information desk | Restore location sampling/readout on charts; the old pointer is currently fixed at (0,0) |
| Coach Y | Available, partial fidelity | Refresh transient decision/warning flags privately before coach capture and compare actual advice |
| Original course chart R and key summary ? | Available as original bitmap panels | Replace with modern panels if desired; bitmap visibility is deliberate compatibility hosting |
| Original leg replay Backspace | Backend route works; probe rewinds to saved state | Race-window/contact/modern championship bookkeeping needs explicit replay synchronization evaluation; no modern timeline/seek/export |
| Follow camera, free camera and original sailing-view shortcuts | Available | These are modern reconstructions, not the original projection/view distances |
| Tactical zoom Z/X and orientation F4/F5 | Reconstructed in the large 3D view | Modern minimap remains independently north-up/auto-fit; it does not inherit those settings |
| Continuous boat tracks | Backend recorder/drawing exists | No track data in modern snapshots or trail renderer in minimap/scene; original chart can still show tracks |
| Difficulty levels 1–15 | Backend menu handlers exist | No setup selector; simulator pace levels are a separate setting, not AI difficulty |
| Current enable/disable, southern hemisphere, starboard rounding, night race | Backend options exist | No modern setup fields or reachable menu controls; night lighting not implemented |
| 5/10-minute prestart and perfect start at pin/committee | Backend options exist | Modern setup omits them; context-sensitive keys are blocked while the starter is open |
| Foul slowdown | Original backslash handler forwarded | Default deliberately disabled; no explicit setup assistance control or clear state indicator |
| Original mouse steering zone/click steering/wheel mode | Missing mapping | Pointer drag controls the camera; worker cursor is fixed and receives no steering pointer stream |
| Design/rig configuration | Modal host unsupported | Original design dialog command cannot run through the worker; needs a modern model/UI |
| Two-player mode | Modal host unsupported and modern UI absent | Second-player setup/input/display need an explicit implementation; current worker enforces its audited normal mode |
| Personal racing-area builder | Backend menu code exists | No modern editor, validation, preview, persistence or loading path |
| Rules and tactics tutorials, glossary, bibliography, detailed help | Translated pages exist | No modern navigation/menu for their chapters; key summary does not replace this library |
| Header/lift information, clear/bad air, luff/sheet/shape readouts, fleet statistics | Partial modern presentation | HUD omits several original readouts despite having some data in snapshots |
| Sound, race cues and foul cues | Missing | `playSound`, `beep` and `messageBeep` are stubs, and there is no audio transport/player |
| Original preferences/settings retention | Partial replacement | Initialization uses `preferences:null`; boat name/minimap have local storage, general setup preferences do not |
| Color/header/true-wind/current-indicator toggles and old graphic simplifications | Mostly backend only or modern replacements | Decide which user-facing information switches to expose; monochrome/simplify drawing need not reproduce obsolete rendering |

## Findings that need care

1. **Coach is not fully equivalent yet.** Normal integration clears eleven
   warning slots at `0x4fb210..0x4fb238`; boat dynamics sets, among others,
   `0x4fb21c`. The OG coach paint refreshes dynamics while skipping integration
   when `0x536444` is active. Our private panel copies a post-paint image and
   calls the pause-screen drawing directly. The runtime probe found all eleven
   slots cleared. This supports a missing-warning path; it does not prove every
   coach comment is absent. Existing static weather/sail advice is present.
   See original `integration.js:134`, `boat-dynamics.js:254`, `frame.js:43`
   and `tutorial-pages.js:7588`.
2. **“;: tracks” was incorrect help text.** The original semicolon handler toggles
   `0x536488` (extra fleet HUD information), while the Show Tracks menu toggles
   `0x53641c`. Neither flag currently drives the modern trail rendering. Remove
   the incorrect advertised shortcut; do not invent parity from forwarding a key.
3. **Replay needs host-state validation.** The probe establishes a native memory
   rewind, not correct modern event scoring or DNF bookkeeping after that rewind.
4. **The collision upgrade remains a gameplay difference.** Swept hulls, physical
   blocking, non-foul spawn separation and local AI clearance are additions.
   Restoring penalties does not make encounter timing identical to the OG.
5. **Not just graphics changed.** Other declared policies include the requested
   20-minute fleet finish window, island route/course clearance, selectable wind
   direction, expanded island choices and longer championship events. Frozen
   original inputs remain intact; nine declared build adapters expose the changes.

## Recommended order

1. Finish dynamic coach fidelity, sailing-state HUD and replay/host-state checks.
2. Add audio cues and modern tactical tracks and chart sampling; evaluate the reconstructed large-view zoom/orientation.
3. Expose difficulty, prestart, rounding, current and hemisphere choices, with
   scenario-level evaluations and visible state indicators.
4. Port tutorial navigation and design/personal-area controls; scope two-player
   as a separate feature.
5. Complete the existing engine extraction tasks, with paired whole-state/RNG
   checks at every removed paint dependency. Do not replace sound AI/weather just
   to make the architecture look cleaner.

The audit findings have separate unchecked PARITY tasks in root todo.md. They
are newly identified work, not completed functionality.
