# Complete native selection catalog (EXT-05)

The modern starter exposes all 27 native boat classes, seven course shapes,
33 imaginary/named areas and fleets of 2/5/10/15/20/25/30 boats. All selections
use original menu commands and complete original setup paints. Short courses and
downwind gates retain the native restrictions; the interface normalizes island,
distance and Around Block Island routes and explains fixed-route choices.
Around Block Island selects the original offshore racer and course 3. Distance
choices are reapplied after offshore boat selection so native setup does not
silently revert to North shore. The model-yacht command's native lake/fleet
changes are followed by the requested original area/fleet menu commands.

The model extractor now retains the native catamaran hull routines, offshore
cabin/crew polygons and sampled native GDI arcs. The two-player fleet's green
screen-space wind pointer is excluded from 3D geometry, like its red equivalent.
Boat record offsets use Uint32, avoiding overflow in 30-boat packets. Cockpit
edge snapping only absorbs measured projection quantization; interior holes
remain holes. Boom recognition matches the native mainsail foot endpoints.
All 26 conventional rigs were identified; the board's hand-held wishbone retains
its original native animation. This is native-derived geometry with modern
solid crew detail, not a replacement set of generic boat assets.

Evaluation evidence:

- `catalog-complete/verification.json`: 76 selected native-menu cases, combining
  the retained initial run and its completed remainder. Every selection compares
  the complete authoritative image, clock, frame, RNG and retained shore state
  initially and after two actual paints. Not a full cross product or complete
  natural races in all venues.
- `rig-probe1/verification.json`: all 27 classes load, with the rig exception
  above. Diagnostic geometry counts are not a numerical fidelity claim.
- `expanded-model1/verification.json`: seven isolated native rig states, actual
  penalty black sails, trim/boom motion, successive native luff geometry,
  opposite tack, spinnaker, private extraction equality, free-camera isolation
  and unchanged complete master boundaries for 5/15 fleets.
- `expanded-sail1/verification.json`: headwind sail motion with hull, crew and
  mast anchored; loaded sail geometry held fixed; original master unchanged.
- `expanded-starter1/verification.json`: held default boundary and trusted
  starter/settings/restart/visibility controls.

## Native chart compatibility repairs

Some newly exposed charts cannot execute in the frozen recovered JavaScript.
The generated adapter repairs only instructions verified in the preserved EXE,
whose SHA is recorded in `NATIVE-CHART-EVIDENCE.json`. The preserved source is
unchanged. Four Ghidra overlapping-double expressions actually store DWORDs:
Block coordinate `0x46cc21`, Groton lighthouse `0x46f357`, Nassau coordinate
`0x46fa22`, and Edgartown TextOut pointer `0x46fe1a`. Both generated drawing paths
retain the low store without reading a fictional undefined upper word.

A signed distance square can wrap negative at `0x465f39..41`. Native masked
FSQRT followed by the CRT's truncating FISTP QWORD yields integer-indefinite
`0x8000000000000000`; the caller stores its low DWORD, zero. The generated
adapter handles this specific conversion without changing positive calculations
or the shared Float80 implementation. `tools/native-chart-x87.c` confirms the
actual processor result for three nonnegative and two negative inputs.

The original comparison declares compatibility inputs explicitly: an unobserved
upper-word fixture for affected chart locals, a scoped masked-invalid sqrt
conversion, and an instruction-proven two-expression response repair for the
Edgartown pointer. Block/Groton/Nassau/Edgartown candidates use exact compatibility
canvas drawing to match original scratch values. Their modern 3D display remains
independent, but their native paint cost is not certified by the default-lake
performance test. These declarations prevent claiming untouched-oracle parity
for source branches that the recovered translation cannot execute.
