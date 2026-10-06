# Tact 2026 implementation

This directory contains the modern edition's implementation and verification
work. Product scope is defined in [PLAN-2026.md](../../PLAN-2026.md); execution
is tracked in [todo.md](../../todo.md). The isolated app runs the recovered
simulation in a worker with explicit 2026 contact/navigation policies, faithful
native-derived 3D boats and free cameras.
Worker and renderer are evaluated bounded prototypes. Preservation players remain
under their original routes.

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
- [ENG-02: compatible original paint worker](analysis/app/ENG-02.md).
- [GFX-01: faithful 3D renderer and backend evaluation](analysis/app/GFX-01.md).
- [Native keyboard compatibility](analysis/app/HOTKEYS.md).
- [Cockpit overlap correction](analysis/app/COCKPIT.md).
- [Solid crew and repeated smoothness checks](analysis/app/CREW.md).
- [Headwind sail response](analysis/app/SAIL-WIND.md).
- [Native marks, lines, committee boat and heading guides](analysis/app/COURSE.md).
- [Starter screen and native race settings](analysis/app/STARTER.md).
- [All native boats, courses, venues and fleets](analysis/app/CATALOG.md).
- [Native environment, shore, depth, currents and grounding](analysis/app/ENVIRONMENT.md).
- [Race/championship journey and expansion review](analysis/app/EXPANSION-REVIEW.md).
- [Restored original penalty response and evaluation](analysis/app/CONTACT-05.md).
- [OG functionality gaps and current engine architecture](docs/og-functionality-audit.md).
- [Independent engine cutover](docs/engine-cutover.md) and [implementation standards](docs/engine-standards.md).
- [Pinned engine pairing and phase tracing](analysis/app/ENG-03a.md).
- [Extracted race/panel transitions](analysis/app/ENG-03b-1.md).

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
pinned source/asset hashes for all 167 inputs. It copies 158 byte for byte and
generates nine explicit drawing, collision, race, course and wind adapters,
without bundling original code. The generated manifest records source and output
hashes separately. Generated copies and dist are ignored.
Original root commands and preservation routes are unchanged.

Use `/` for the WebGL 2 development player and paused starter screen. Choose
a native boat class, venue, compatible fleet/course and Light,
Moderate or Strong native wind; Start race releases the countdown. New race
or N returns to setup. Choices are staged until Start; boat/course previews use
cached native samples. Fresh races retain the preset's fixed seed; they do not continue
the previous race's weather/RNG stream. Use `/spike/?fleet=15&backend=webgpu`
to inspect the requested alternative, and `?manual` for paused diagnostics.
Drag the canvas to orbit and scroll to zoom; Follow boat resets the camera.
Port/Starboard, Tack, Close hauled and Run invoke original controls. Comma/period
steer; arrows look around; T tacks. F, Space and Pause share a host pause that
retains telemetry and rejects helm/sail inputs. W, [, ], and Y open the modern
forecast/wind/current/coach desk on private copies; closing restores the previous
pause policy. Other sailing controls use the original handlers. See
[keyboard evaluation](analysis/app/HOTKEYS.md) and the app's keyboard help.
Native pace names retain the audited original
levels rather than promising fixed wall-time multipliers.

The geometry foundation and remaining fidelity work are described in
[native-boat-models.md](docs/native-boat-models.md). The lake scenery and model
world scale are provisional; the app displays native course objects but does not yet supply
the complete tactical interface, production replay or production assets.

Rigid contact shapes derive from all 27 native hull families, with compound
catamaran hull/platform shapes and a measured 0.35-unit heel reserve. Buoy and
committee dimensions are shared by physics and rendering. Continuous translation
and rotation sweeps, tangential sliding and non-foul spawn separation run only
in the authoritative worker; AI applies local hull clearance around native goals.
Foul decisions use private original-rule images with contact-time tack/angle,
geometric overlap/astern. Penalty responses reuse the original reset/respawn/shift
routines, native codes/black sails, human/NPC status rules, mark phase eligibility
and the opponent-timestamp 50-game-second grace rule. Episodes only count contacts.
All visible objects remain solid; gate endpoints have no invented mark-touch foul.
Hull proximity and physical blocking remain explicit 2026 changes, so encounter
timing is not identical to the original centre-point detector.
The audited startup image and frozen preservation inputs remain unchanged.
Enable **Renderer evaluation → Show contact shapes**, or use `?hitboxes`, to
inspect contact footprints. See the CONTACT tasks/evidence in root todo.md.
