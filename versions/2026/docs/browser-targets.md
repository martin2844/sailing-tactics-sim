# Browser and device decision

Decision date: 2026-10-05. Source: user instruction, “for now only chrome …
we can test on my pixel11 later”.

Use desktop Chrome for current implementation and acceptance work. The named
reference is the existing Linux Ryzen 7 5700G / Radeon RX 7800 XT machine,
Chrome 152.0.7977.82, with the dimensions and quality contract in
[acceptance.json](../config/acceptance.json). Firefox and Safari qualification
are deferred. A later browser update requires a fresh recorded evaluation
context rather than comparing incompatible measurements silently.

The user's Pixel 11 running Chrome is the named future landscape-touch target.
Capture its actual OS/browser versions, canvas dimensions, pixel ratio and
quality when the device is tested in `QA-09`. No device specifications were
inferred from its model name. Physical touch qualification is pending;
desktop touch emulation cannot satisfy that gate. Current work proceeds on
Chrome desktop without waiting for access to the phone.

This decision narrows browser coverage. It preserves the planned touch controls
and later physical validation; it does not claim that they already work.
