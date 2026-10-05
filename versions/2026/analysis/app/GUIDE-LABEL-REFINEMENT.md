# Guide and label refinement

## Pass 1 — original guide behavior

The modern guide extractor executes a generated copy of the original chart's
mark/gate/finish decisions and integer-angle emissions on a private memory/RNG
image. It drops unrelated chart artwork, tracks and gust drawing, and admits
points outside the historical viewport for free-camera clipping. It does not
modify or replace authoritative drawing routines. Guide anchors and bearings
come from those decisions; extension length and styling remain presentation.
The invented target rays and gray equal-distance line have been removed. The
native boat guide, when eligible, is retained. L now changes the heading reference
by the original tack-dependent 45 degrees and never creates additional rays.

Evaluation: [30 original-chart comparisons](guides-pass1-final2/verification.json)
cover prestart, upwind, reaching suppression, third-mark approach, downwind,
finish sides, gate endpoints, recall, results, mark-line suppression, wind
359/1 and both alternate chart orientations, on five/thirty-boat private images.
The independent oracle runs the full original chart with real GDI children;
anchor and bearing tolerances account only for original integer pixel endpoints.
These are controlled fixtures, not completed races or a full course/state product.
Extraction leaves the entire master image/RNG/frame/clock/shore unchanged.
[Paired original simulation](guides-worker1/verification.json) matches five
whole-image boundaries per fleet for five/fifteen boats and real helm/tack inputs.
Production build/type checking pass. Frozen sources remain unedited.

## Pass 2 — shared labels

One screen-space canvas now lays out measured 20px-high buoy badges and boat names (maximum 144px wide). Projected native hull/rig bounds, other labels and visible HUD panels reserve space. Active marks, hover/selection and prestart endpoints have priority; up to four nearby names appear automatically, with an All names toggle for additional identities where space permits. Clipped rigs can deliberately have no label. Pointer selection preserves the follow camera; names remain canvas text, not HTML. Restart/context recovery preserves the display toggle. HUD reservations refresh every rendered frame.

Evaluation: [19 layout cases](labels-pass2-final/verification.json), covering 5/15/30 boats, chase/overview/close cameras, trusted pointer selection and DPR2, passed fixed-size and collision checks with the full native boundary unchanged. [Name evaluation](labels-names-final/verification.json) passed native identities, custom name storage and fleet reset; it verifies safe text plumbing, not every rendered glyph. [Headed Chrome lifecycle](labels-lifecycle2/verification.json) passed changing rendered pixels, pause isolation, three pause cycles, fleet restart and context-loss recovery. An earlier lifecycle attempt stopped before app checks because the compositor reported a one-pixel window-size mismatch; a fresh owned-window attempt matched and passed. Production build/type checking passed.

## Pass 3 — visual hierarchy and Chrome evaluation

Pending evaluation.
