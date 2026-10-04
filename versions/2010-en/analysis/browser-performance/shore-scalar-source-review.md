The 0x47ed40 Number translation promotes nine private I32 slots: offsets 0, 4,
8, 256, 260, 268, 272, 276 and 280 (326 emitted accesses). Offset 264 and the
complete point, callback and array backing at offsets 300 through 919 remain
bytes. Control-flow edges and arithmetic are unchanged. Explicit retained stack
bytes and unusual Number prototype pointer fields select the complete byte
function.

The first array loop initializes counter 260 to zero and pointer 268 to
0x535a98, advances them by 1 and 4 once per cycle, and tests the pointer against
0x535bb5 after the body. Its array writes use indices 1 through 72. The second
loop initializes counter 264 to 1, advances it by the reviewed step 1 or 2, and
tests against 71 after the body; array reads use indices 1 through 71. Closed
control-flow bodies and exact predecessor chains prevent entries that skip
initialization or updates. All other escaped frame views have fixed four-byte
widths, or use the actual writeLocalPoint implementation's eight-byte output.
The six pointer/integer callees are source-pinned, and an unreviewed change
declines promotion. Buffer aliases, including the POINT at 328 overlapping the
array cell at 332, retain their original byte behavior.

Review found a guard defect before this pass entered production generation:
adding a write to counter 264 at case 261, after its pinned initializer, or to
step 276 at case 265, could invalidate the nonnegative index proof while still
passing the loop-body-only checks. The fix verifies the complete ordered ledger
of 17 stores to counters 260, 264, 268 and 276 over the entire function lifetime.
Any additional preheader, body or later store now declines unchanged. Regression
cases cover those two mutations and extra preheader writes to fields 260 and
268. The unchanged recovered source was safe throughout; the defect concerned
acceptance of future modified source.

Validation comprises nine Python generator checks, two Node generator/callee
checks, and four direct runtime comparisons. The latter use complete scene
images reconstructed and hash-checked from existing native captures, comparing
12 shoreline features at each of four venues with the original byte function.
All 48 comparisons preserve every image byte, return/error, RNG state and
ordered GDI request. Venues 6, 9 and 106 exercise visible aliased drawing;
venue 2 exercises early returns. These are differential checks on native input
images, rather than new isolated native captures. The separate final native
full-frame replay and publication suite provide the complete native-output
checks. Source hashes and bounded-scope metadata are recorded in the companion
JSON receipt.
