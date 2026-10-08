# Optimist study QA

Scope: the isolated visual study. The playable fleet remains on the restored OG models.

## Findings fixed

- **Canvas overflow and cropped boat.** At a 1000 × 700 browser size the old canvas grew to 1151 px tall; geometry reached 1.103 in vertical normalized device coordinates, outside the visible frame. The desktop viewport now has a bounded height, the options scroll independently, and preset/resize framing measures the actual visible geometry with a margin. Added a Fit boat control. Manual orbit and zoom remain available.
- **Wrong camber on the opposite tack.** Camber now reverses with tack. Passing through zero retains the existing tack and crew side, avoiding an abrupt side switch at dead centre.
- **Disappearing tiller extension.** It belonged to the sailor mesh, so hiding the sailor also hid boat hardware. It now belongs to the rig and remains connected to the appropriate grip position.
- **Rudder head gap.** Added the head connecting the existing blade to the upper fitting and tiller.
- **Distorted class emblem.** The mark was drawn in tapered sail UV coordinates, stretching the circle and skewing its stem. It is now laid out in metres, mapped back onto the actual cloth triangles, and positioned clear of the sprit.
- **Unnecessary geometry rebuilds.** Crew visibility and heel now update visibility/transform without rebuilding the sail. Luffing stops updating the geometry when switched off.

The viewer script is now a separate TypeScript module checked by `npm run check`, instead of unchecked inline JavaScript. This module is only loaded by the study page.

## Evaluation

- TypeScript passed.
- `tools/optimist-study-qa.mjs`: 18 framing checks, comprising five presets at 1280 × 1000, 1000 × 700 and 1920 × 1080, plus neutral and both ±85° trim / ±25° heel extremes. Every visible vertex stays within the camera margin; canvas stays inside the desktop viewport.
- Actual cloth vertices mirror exactly between ±25° trim. A zero-trim transition preserves crew geometry.
- Hiding crew preserves the tiller extension. Heel/visibility changes leave the rig buffer version unchanged.
- Luffing produces measurable movement; switching it off stops buffer changes. Penalty and crew controls work, reference links respond successfully.
- Existing dimension/pose checks still pass, with 16 fresh screenshots including eight compass views.

Receipts: `../../analysis/app/boat-redesign/optimist-qa-final/verification.json` and `../../analysis/app/boat-redesign/optimist-qa-views-final/verification.json`. These checks assess the presentation prototype, not live numerical-engine integration or class certification.
