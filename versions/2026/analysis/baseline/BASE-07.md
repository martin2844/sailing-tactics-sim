# BASE-07 evaluation: target devices and acceptance budgets

Completed 2026-10-05. Result: **accepted** against the task's completion condition.
Atomic commit subject: `BASE-07: freeze Chrome targets and acceptance budgets`.

The [browser decision](../../docs/browser-targets.md) records desktop Chrome
now and the user's Pixel 11 with Chrome for later physical touch testing.
The [acceptance contract](../../config/acceptance.json) freezes the plan's
cadence, input, startup, transport, geometry, memory and replay budgets.
Those are future release requirements, not measured 2026 performance.

A fresh owned, headed GPU Chrome session [captured the actual desktop](BASE-07-device.json):
Ryzen 7 5700G, RX 7800 XT, NixOS 26.05 x86_64, Chrome 152.0.7977.82,
1280×1051 physical window and 1280×1050 logical viewport at pixel ratio 1.
WebGL 2 and its timer-query extension were available. This proves capability
and reference identity; it does not certify renderer cost or GPU timing accuracy.

Evaluation: the captured browser/hardware/dimensions match the named reference;
all budget values are explicit, positive and consistent with the plan. The
phone is named without inventing its OS version or asserting a touch pass.
Quality is fixed for acceptance runs; changing the browser/device/surface or
quality requires recording a new comparison context. No game code changed,
so no new unit tests are warranted for this configuration/documentation task.

Reproduce the capability capture into a new file:

```sh
node versions/2026/tools/device-profile.mjs /tmp/tact-desktop-device.json
```

Remaining work: build and benchmark the modern scene on Chrome, measure real
input and simulation timing, and perform `QA-09` on the Pixel 11 later. M0
remains open until the semantic/timing/scenario/spike decisions also pass.
