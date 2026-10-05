# Final Canvas drawing investigation

The expensive final `drawImage` was completing deferred glyph drawing in its
source buffer. GPU-backed colored font atlases were being used by a software
Canvas buffer. Creating the 2010 font atlases with `willReadFrequently: true`
removes that transfer cost. The visible canvas, original drawing operations,
font masks, physics, RNG and input order are preserved. The 2002 caller keeps
its existing default font backend.

## Evidence

[Four alternative drawing routes](canvas-diagnostic-2026-10-05T07-16-40-265Z/report.json)
showed that making the visible canvas software-backed did not remove the cost.
Reading one source pixel moved it into `getImageData`; replacing the final draw
with a full pixel copy also moved the cost rather than removing it. Pixel
copying has different alpha semantics and was not adopted.

[The paired font-atlas probe](canvas-diagnostic-2026-10-05T07-18-51-285Z/report.json)
reduced the median final drawing call from **58.8 ms to 1.0 ms** over 40 frames.
These are instrumented diagnostic timings, excluded from performance acceptance.
Both runs started at frame 30 and ended at frame 70 with identical memory hashes,
RNG states, simulation time and original settings:

| Boundary | Memory SHA-256 |
| --- | --- |
| Entry | `04331c8c1c9437a34de865b91bcce64dc94d2ec3792c286487315cb0419b5a57` |
| End | `18f9ec2343d34898210ce74c9b5524863ab8979a744de20c2bd4d4cc83342129` |

The ended RNG state was 865560740; simulation time was -159.5843022005575.
Memory hashes are state evidence, not image hashes. Separately,
[160 headed GPU font comparisons](2026-10-05T07-40-19-458Z-83bc7ef0/font-atlas.json)
matched the native whole-string RGBA references: 80 cases for each atlas backend.
The HUD checks and exact/smooth real Canvas engine-trace checks passed.

## Normal scheduler measurements

All normal timing runs use headed GPU Chrome, fixed initialization, original
menu commands, untouched simulation timesteps and the natural scheduler.
The physical window is 1280×1051, with a 1280×1050 logical viewport. A fresh
reference was collected at these dimensions; older 1050-pixel physical-window
reports are not used for the before/after comparison. Each edition retains its
own original canvas dimensions and workload.

The default scenario retains the original automatic foul slowdown. Comparing
the [fresh before-fix reference](2026-10-05T07-20-52-640Z-83bc7ef0/index.html)
against [three post-fix repetitions](2026-10-05T07-27-40-157Z-83bc7ef0/index.html):

| 2010 default workload | Before: 2 repeats | After: 3 repeats |
| --- | ---: | ---: |
| Median per-run p95 paint work | 92.4 ms | 35.9 ms |
| Median per-run p95 observed content interval | 93.9 ms | 84.8 ms |
| Median per-run p95 trusted camera response | 337.4 ms | 178.1 ms |
| Mean observed completed-content FPS, approximately | 11.6 | 21.0 |

The remaining default cadence fails the evaluation target. The original
**Control → Slow Simulator if Foul Likely** feature lowered speed from 10 to 1
during the post-fix measurements, imposing the original 80 ms minimum frame
duration. Users wanting sustained speed 10 can turn off this menu option and
select speed 10. The port's default behavior has not been silently changed.

[Three controlled 15-boat comparisons](2026-10-05T07-40-19-458Z-83bc7ef0/index.html)
disable that option through its original command. All six runs preserved their
edition's native speed, timestep and automatic-slowdown setting. The 2010 port
measured **40.1–40.9 observed FPS**, versus **15.1–15.8 FPS** for 2002.
Its median per-run p95 paint work was 29.4 ms, versus 66.1 ms; observed content
interval was 31.3 ms, versus 71.1 ms.

The controlled response result is **provisional**: median per-run p95 was
97.7 ms, with repeat values 97.7, 87.7 and 152.4 ms. Every measured outlier is
retained. This supports the drawing fix but does not establish consistently
sub-100 ms input response. A longer confirmation collection follows separately.

[The five-repeat, 240-frame confirmation](2026-10-05T07-51-35-087Z-83bc7ef0/index.html)
completed all ten runs with 2,400 paint samples and 120 trusted camera responses.
Compositor visibility was verified before/after each run and after input probes.
The 2010 result was **33.7–39.7 FPS**, versus **9.1–14.6 FPS** for 2002. Median
per-run p95 paint work was 31.0 ms versus 74.0 ms, and observed content interval
was 32.2 ms versus 80.9 ms. Runtime and collector hashes remained constant.

The confirmation **did not meet the complete smoothness target**. Median
per-run p95 input response was **111.5 ms**, versus 216.8 ms for 2002; the five
2010 values were 91.7, 111.5, 115.6, 93.5 and 123.3 ms. The required threshold
is strictly below 100 ms. Repetition variability also remains significant,
especially for 2002. This closes the identified Canvas stall, while consistent
input latency remains a separate measured limitation.

## Evaluation correction and review

[A controlled collection](2026-10-05T07-34-44-619Z-83bc7ef0/index.html)
was initially rejected because two Chrome animation
timestamps were equal even though actual callback time and completed frame ID
advanced. The checker now accepts equal animation timestamps, retains every
observation, and still rejects decreasing timestamps. Cadence continues to use
actual callback delivery time. A regression test covers distinct changed
frames sharing an animation timestamp; another rejects Canvas diagnostic data
from acceptance comparisons. The evaluation suite passed all 52 tests before
the additional compositor visibility checks were added.

The [first longer confirmation](2026-10-05T07-44-27-424Z-83bc7ef0/index.html)
timed out waiting for its final rAF observation. The monitor's active workspace
was 1 and the owned test window was on workspace 3. Its incomplete evidence
is excluded. The collector now validates the owned window's PID/address and
checks its workspace against the powered monitor's active workspace. It focuses
that owned window before measurement when needed, and rechecks visibility after
throughput and input measurements. Unit tests cover the focus target, changed
or ambiguous ownership, and refusal to repair visibility after measurement.
Other compositors are explicitly recorded as lacking this additional check.
The final collection passed all **57 evaluation tests**, the HUD checks,
**160 native font pixel comparisons**, and the real Canvas engine-parity gate.

Self-review found no remaining findings in the font-backend change, option
callers, diagnostic exclusion or metrics correction. Source and collector
hashes remained constant within each completed collection. The standalone
export must include the same font and player source hashes.

The rebuilt standalone export passed a [bounded live smoke check](2026-10-05T07-51-35-087Z-83bc7ef0/export-check/report.json):
20 measured paints, 12 trusted camera responses, full-version mode 0 throughout,
no runtime errors or exceptions, and only modules from `dist-2010` loaded.
All 139 ZIP entries were checked byte-for-byte against the export; manifest
hashes and both changed player sources matched. This is export correctness
evidence, excluded from performance comparisons.

These bounded scenarios do not certify a complete race, long-session stability,
every venue/fleet, other browsers or physical monitor presentation. The full
preservation repository retains the previous evaluation and its limitations.
