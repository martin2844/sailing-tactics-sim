# Race, navigation, shoreline and control repairs

## Pause and depth

Space now suspends/resumes the host simulation during sailing, including when
a toolbar button owns keyboard focus. It still dismisses original information
panels; editable inputs and result actions retain their normal keyboard use.
The Pause button reports both host pause and native F freeze. Resume thaws a
native freeze before restarting the host scheduler. Snapshot changes update
that state without forcing every ordinary frame to count as a camera change.

Depth uses the actual configured boat's native grounding threshold, combining
its draft limit and the original class/catamaran shallow-water limits. The
readout turns amber as clearance shrinks and red before grounding, with a short
text label. Actual grounding remains driven by the original status flag.

[Chrome control/depth evaluation](controls-depth-final/verification.json)
passes trusted clicks on Follow/Overview/Mark lines/All names followed by Space,
exact paused memory/RNG/shore boundaries, native freeze/button resume, panel
dismissal without pace changes, and isolated depth colour/text fixtures.
Production build/type checking pass. These UI checks do not claim naturally
sailed grounding or change the grounding physics.

## Finishing window

The first actual finisher starts a 1,200-second window on the original race
clock. At the deadline, unfinished boats receive the native fleet-size-plus-one
rank and a DNF label. Existing finishes and retirements remain intact. A fleet
that finishes earlier ends normally. Pause/freeze cannot consume this window.
The HUD shows the remaining allowance; race results and championship records
retain DNF status.

Two declared adapters in the generated 2026 compatibility copy disable the
old single-player immediate end and the AI's player-relative automatic
retirement. Frozen 2010 sources remain untouched. Native results drawing still
computes championship scores; DNF uses its original 101 × (fleet size + 1)
score units. The window resets for a new race or a rewound clock.

[Cutoff evaluation](race-cutoff-final/verification.json) uses real native target
advancement, AI and results calls on private game-clock fixtures. It proves
that the player's finish does not close the race, AI boats do not retire at the
old deadline, the exact 20-minute boundary closes once, native DNF scores match,
and the real client displays results/records correctly without changing the
held worker. Three small policy regression tests pass. These are controlled
fixtures, not naturally sailed arrivals or a played championship.

## Island layouts and shore routing

The failure is reproduced in [the former native layouts](island-before-layouts.json):
Optimist's Island second mark has zero native depth in all three winds, and
model yacht's distance-island second mark can also be dry. The 2026 course
adapter retains full island-course spacing instead of applying those boats'
ordinary-course shortening factors. Native mark bearings, roundings, target
rows and shoreline generation still build the layout.

A buffered visibility graph routes AI around native land on Island, distance
island and Around Block Island. The original AI still samples wind/current and
runs its ordinary tactics; the additional navigation layer changes an AI
heading only when its goal segment or immediate heading points ashore. It
retains the actual race targets and leg advancement tests. Safe headings keep
the native no-go angle and tack fields consistent. It uses no extra random draws.
Background venue sampling features no longer become extra green islands when
the native depth sampler excludes them. The underlying native shoreline arrays
are retained; the corresponding frozen sources are unmodified.

[18 layout/navigation cases](island-navigation-final/verification.json) pass
native buoy-depth checks across all three wind strengths and the affected boat
families. Each buffered route segment stays clear of land; inspection does not
mutate the held simulation. Two small geometry/navigation tests pass.

[A naturally simulated standard race](island-live-final/verification.json)
uses five Optimists, moderate wind, original Page Up pace 15 and an unsteered
human. All four AI boats finish; the human receives DNF at clock 5312, exactly
1200 game seconds after the leader at 4112. No position/leg/finish fixtures are
used. [The championship case](island-champ-final/verification.json) also sails
all four AI boats home, scores the human DNF as native 606 units, and starts
race two without reseeding or carrying the old deadline/DNF flags. At this
large native timestep its cutoff occurs at the first eligible paint after the
deadline. These are diagnostic batch-paced races, not performance runs or a
claim for every venue/wind/fleet combination.

That live evaluation exposed a results-transition issue: a modern human DNF
must save the pace fields just as the original human-finish routine does.
This is now retained for results and next-race initialization. Model extraction
also stops after race completion and holds the last valid meshes. The corrected
standard/championship transitions and a dedicated pace-retention test pass.
