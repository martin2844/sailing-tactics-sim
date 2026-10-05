# ENG-02 worker spike evaluation

Accepted bounded prototype, 2026-10-05. Uses the original 1024×768/24-bit host,
unit ticks, whole original image, x87 mode, RNG, bitmap font, retained shoreline
slots and actual full original paint lifecycle. Its OffscreenCanvas performs
real drawing and pixel reads. Modern UI receives only small read-only snapshots.
All original modules load externally as byte-exact prepared copies.

Paired original/worker checks pass at initialization and four boundaries across
32 real paints each for 5 and 15 boats, including original port/starboard/tack
commands. Compared entire image SHA-256, RNG, time, frame, clock and retained
shore state, with zero normalization/tolerance. See [raw verification](ENG-02-run1/verification.json)
and tools/worker-eval.mjs (preview server :8770).

Compatibility-paint costs (ms; two headed Chrome sessions and diagnostic awaits,
not continuous performance acceptance):

```json
[
  {
    "fleet": 5,
    "median": 34.599999994039536,
    "p95": 78.80000001192093,
    "max": 97.39999997615814,
    "bytes": 785
  },
  {
    "fleet": 15,
    "median": 38.099999994039536,
    "p95": 110.90000000596046,
    "max": 126,
    "bytes": 1689
  }
]
```

Unsupported: native modal dialogs, original sound, arbitrary preference/setup
profiles, replay/checkpoint restoration and production command transport.
Worker pacing retains original minimum delays with no skipped steps/catchup.
Pause invalidates queued timer/message tokens; restart replaces the worker.
This is a spike, not ENG-13 production completion or full-race certification.
