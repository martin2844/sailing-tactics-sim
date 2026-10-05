# BASE-06 — supported initial scenarios

Accepted 2026-10-05. `config/scenarios/round-lake-5.json` and
`round-lake-15.json` freeze original Keelboat selector 12, Round Lake area 5,
venue 0, windward/leeward course 1, fleet 5/15, native pace 10, automatic
sheeting and automatic foul slowdown off. Full mode is 0. Native weather,
current and difficulty preferences remain the original values, recorded as
the complete typed original 636-byte preference field sequence and hash.

The deterministic host has seed time 1546300800, tick start 0, canonical
1024×768 24-bit surface, no saved preferences, neutral hover/cursor and
original menu/key handlers. Exactly nine original paints produce the initial
boundary; the original automatic-sheet menu follows without an extra paint.
Commands are 32799 Round Lake, 32816 windward/leeward, 32789 Keelboat,
32806/32808 fleet, 32909 native pace 10, and post-setup 32850 automatic sheet.
Existing loader forecast/Space/slowdown transitions are preserved and recorded
in the verification setup history.

Each scenario was initialized in two fresh Chrome sessions. The entire
2,211,840-byte image hash, RNG, retained shoreline snapshot and every recorded
configuration/preference value match between repetitions. Every loaded module
matches the pinned 2010 reference. Initial boundaries are:

| Preset | Frame | Simulation time | RNG state | Whole-image SHA-256 |
| --- | ---: | ---: | ---: | --- |
| Five boats | 9 | −170.1534699111288 | 713814625 | `07e7856370efb613e4e73d394f38c8fa3a944d8659460a16484b4a786ee0a9bd` |
| Fifteen boats | 9 | −170.1534699111288 | 627798547 | `912541bfa64f540ddb09880520a4779df18785081a81a9bb3fe044d96ec66773` |

The raw image is authoritative; this manifest is not a replay checkpoint.
The fixed host seed is an initial scenario, not a promise of identical weather
after different control histories. Shared native RNG consumption is preserved.
The worker must reproduce these initial hashes before starting autonomous steps.

Evidence is `BASE-06-run-3/verification.json`; reproduce with
`node versions/2026/tools/scenario-capture.mjs NEW_DIRECTORY`. Capture 1 failed
before retained output because the diagnostic mislabeled the area/venue
addresses. Capture 2 retains the values that exposed that mistake. Correct
addresses are area **0x4da19c** and venue **0x4da1f8**, as the menu handlers
demonstrate. No original control or simulation code was changed. BASE-03's
swapped descriptive boat/course menu names were also corrected; its actual
command sequences and races were already correct. These were documentation/
diagnostic mistakes, not changed physics or native presets.

Acceptance: original handlers initialize verified settings twice with exact
image/RNG/retained/configuration equality. No additional unit tests were
necessary; the real initialization comparisons test the required behavior.
