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
