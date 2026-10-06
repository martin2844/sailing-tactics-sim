# ENG-03b-2 — Extract waypoint placement from drawing

2026-10-07. The 2026 `respawnWaypoint` domain function now owns the original
0x465ff0 behavior. It receives named position/constant/storage/numeric ports;
there is no renderer, Canvas, GDI, pixel query or historical-edition import in
that module. A compatibility mapper supplies exact numerical operations and the
current address layout. The public and numeric original entry points delegate
to the new kernel through the declared 2026 preparation adapter.

Player anchoring, signed index/parity, the three placement attempts, precise
coordinate arithmetic, F64 stores before subsequent draws and nearest-point
checks are retained. Raw-angle x87 sine/cosine is required: replacing it with a
wrapped degree lookup or ordinary browser Math.sin would change shared state.

Three focused tests pass: 336 actual recovered public/numeric cases across
players, indices and negative/positive headings; ordered store/draw checks;
and six real crowded-neighbor cases proving two/four/six draws and complete
image/RNG equivalence through actual retry branches.

[65 paired 2026 boundaries and ten frozen 2010 boundaries](cutover-waypoints-2026-10-07/verification.json)
pass, including actual racing and information-page transitions. Both ordinary
and traced candidates match the pinned oracle over every memory byte, RNG,
clock/time/frame and retained shore context. The [phase ledgers](cutover-waypoints-2026-10-07/phase-ledgers.json.gz)
include the newly owned respawn phase and remain untruncated. Build/type checks
pass. Preservation sources remain unchanged.

Invocation timing still comes from the compatibility scene. Moving the owning
world-phase traversal and eliminating pixel/shared-drawing dependencies remain
ENG-03b/03c work; no complete lifecycle independence is claimed here.
