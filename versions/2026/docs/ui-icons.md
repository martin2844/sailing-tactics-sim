# Tact SVG icons

The authored family is defined in [icons.ts](../app/ui/icons.ts). Every icon uses
the same24×24 viewBox, navy `currentColor`,1.8-unit rounded stroke and a shared
SVG template. The small second-lap glyph uses a1.4-unit detail stroke. Boat icons
share mast/sail primitives; course icons share mark and route primitives.

There are25 glyphs, including the dropdown chevron. The complete rendered set is
8,385bytes raw and946bytes gzip. This measures the SVG markup alone, not the
application's JavaScript/CSS integration. There are no icon packages, fonts,
images, filters, network references, IDs or randomized paths.

`iconSvg(name)` returns the same SVG for the same name. Compass direction adds
only a deterministic rotation to its needle; its ring remains north-up. Geometry
is authored directly in the source on fixed coordinates, so there is no model
generation or regeneration step.

[select-icons.ts](../app/ui/select-icons.ts) decorates the existing native
selects. Boat type, venue family, wind strength, compass direction, course and
event mode update the decorative icon. All labels, option values, keyboard
selection, validation and engine controls remain on the original selects. The
SVGs are hidden from accessibility APIs and pointer input. No extra text or
custom dropdown interaction is required to use an option.

Wind strength/direction share a full setup row to leave sufficient space for
their text and icons. Fleet/simulator speed share the preceding row in DOM and
visual order. Native focus indicators and forced-colour dropdown arrows remain
available.

Evaluation: `node tools/select-icons-eval.mjs NEW_DIRECTORY` checks actual Chrome
selection changes, compass rotations, keyboard input, accessibility decoration,
four viewport widths, exact held simulation state, trusted race start and live
speed controls. See
[the receipt](../analysis/app/select-icons-final-2026-10-07/verification.json).
Screenshots were inspected for the setup at desktop and narrow Chrome widths;
these are not mobile-device certification.
