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
