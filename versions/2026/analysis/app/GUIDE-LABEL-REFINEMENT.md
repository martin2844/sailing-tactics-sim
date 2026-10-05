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

Pending evaluation.

## Pass 3 — visual hierarchy and Chrome evaluation

Pending evaluation.
