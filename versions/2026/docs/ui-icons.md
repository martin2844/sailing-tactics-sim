# Tact SVG icons

The authored family is defined in [icons.ts](../app/ui/icons.ts). Every icon uses
the same24×24 viewBox, navy `currentColor`,1.2-unit rounded stroke and a shared
SVG template. Boat icons
share mast/sail primitives; course icons share mark and route primitives.

There are39 glyphs, including14 boat class marks, the OG-style speedometer and the dropdown chevron. The complete rendered set is
12,366bytes raw and1,427bytes gzip. This measures the SVG markup alone, not the
application's JavaScript/CSS integration. There are no icon packages, fonts,
images, filters, network references, IDs or randomized paths.

`iconSvg(name)` returns the same SVG for the same name. Compass direction adds
only a deterministic rotation to its needle; its ring remains north-up. The speedometer
keeps the existing face and thin stroke. Its eight ordered multipliers rotate a
seven-unit needle from−120° at1× to120° at32×, rounded to whole degrees. Each
rendered gauge is about410bytes; both the open option and closed selection use
the same generator. The clock glyph and timing optgroups have been removed. Geometry
is authored directly in the source on fixed coordinates, so there is no model
generation or regeneration step.

[select-icons.ts](../app/ui/select-icons.ts) decorates the existing native
selects. Boat type, venue family, wind strength, compass direction, course and
event mode update the decorative icon. In Chrome, `appearance:base-select`
also displays the matching SVG beside every open option. A browser-owned
`selectedcontent` mirrors the selected label; the separate closed-control icon
avoids duplicating the glyph. All labels, option values, keyboard
selection, validation and engine controls remain on the original selects. The
SVGs are hidden from accessibility APIs and pointer input. The browser owns
popover placement, scrolling, pointer selection, typeahead, Enter and Escape.
There is no parallel custom listbox or keyboard state machine.

Class emblems are small monochrome redraws normalized to the shared grid, not
full promotional logos. Filled silhouettes retain their shape; outline strokes
use the lighter weight. Generic boat categories retain the matching hull glyph.
Source references consulted while drawing:

| Class | Reference |
| --- | --- |
| Optimist | [IODA/World Sailing class rules, CR2.7.1](https://media.sailing.org/sailing/wp-content/uploads/2022/03/18105623/IODA_CR_2026-01-01.pdf), [IODA identity](https://www.optiworld.org/) |
| Laser | [Legacy Laser handbook](https://www.laserinternational.org/wp-content/uploads/2019/01/Handbook_2109.pdf); retained legacy sunburst for the game's Laser class name |
| Snipe | [SCIRA insignia history and silhouette](https://www.snipe.org/articles-advices-and-education/exchange-views/scira-emblems-and-insignias/) |
| JY15 | [Builder class identification](https://www.nickelsboatworks.com/collections/jy15-parts); simplified JY/15 path wordmark |
| 505 | [International505 association identity](https://www.int505.org/) |
| Thistle | [Thistle association emblem](https://thistleclass.com/) |
| Lightning | [International Lightning class](https://lightningclass.org/); lightning-bolt glyph |
| Tornado | [Tornado association identity](https://www.tornado-class.org/); reduced slantedT mark |
| Star | [Star association](https://www.starclass.org/); five-point star |
| A class | [International A-Division identity](https://a-cat.org/); A and two lower bars |
| Ideal18 | [Ideal18 identity](https://ideal18.org/); normalized interlocking rings |
| Etchells | [Etchells identity](https://etchells.org/); sail/E mark |
| E Scow | [US Sailing class scantlings](https://www.ussailing.org/wp-content/uploads/2020/07/Class-E-Scantling-rules-MDS-2-28-2020.pdf); E mark |
| Flying Scot | [Builder FS identity](https://flyingscot.com/boats/), [FSSA sail plan](https://fssa.com/wp-content/uploads/2021/01/Class_Rules_9_22_2025.pdf); normalized FS path monogram |

Native picker implementation follows [Chrome's customizable-select reference](https://developer.chrome.com/blog/a-customizable-select).
All marks ship as local SVG paths; references are not runtime dependencies.

Wind strength/direction share a full setup row to leave sufficient space for
their text and icons. Fleet/simulator speed share the preceding row in DOM and
visual order. Native focus indicators and forced-colour dropdown arrows remain
available.

Evaluation: `node tools/select-icons-eval.mjs NEW_DIRECTORY` checks actual Chrome
selection changes, compass rotations, keyboard input, accessibility decoration,
four viewport widths, exact held simulation state, trusted race start and live
speed controls. See
[the receipt](../analysis/app/thin-icons-final-2026-10-07/verification.json).
`node tools/option-icons-eval.mjs NEW_DIRECTORY` additionally opens every setup
picker, inspects all option glyphs and unchanged labels/values, checks trusted
option clicks/typeahead/dismissal and compatibility-disabled courses. See
[open-picker evidence](../analysis/app/option-icons-final-2026-10-07/verification.json).
Screenshots were inspected for the setup at desktop and narrow Chrome widths;
these are not mobile-device certification.

The consolidated-speed regression is recorded in
[the current icon/layout receipt](../analysis/app/consolidated-speed-icons-2026-10-07/verification.json).
The progressive open/closed speed gauges and trusted32× selection are checked in
[the speed receipt](../analysis/app/consolidated-speed-final-2026-10-07/verification.json).
