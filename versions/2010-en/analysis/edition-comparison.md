# 2002 and 2010 English: evidence-backed comparison

The 2010 port reconstructs the selected English executable independently. The 2002 implementation supplied reusable numerical and drawing infrastructure; its game globals and resulting states are not substituted for the 2010 target. [The JSON companion](edition-comparison.json) records exact resources, addresses, source hashes, control writes, presets and numerical bytes.

The preserved sources are:

- 2002: `original/Tact02Demo.exe`, SHA256 `881dc85dc7500a5ad09e09091d4dd53f8c091f5630d5fabdcc887cc4b007acea`.
- 2010 English: `versions/2010-en/runtime/Tactics2010EnglishPreserved.exe`, SHA256 `d707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787`.

## Boat selectors and presets

2002 has 15 selectors; the target has 27. The table shows original internal `length/displacement/sailArea` integers after complete boat-option initialization with zero overrides, previous class 6/length 25, rig 1 and course 1 under CW027f. These numbers are not asserted to be feet, weights or physical sail areas. Prior rig and override choices can change retained values; full outputs and their input contract are in the JSON.

| Selector | Command | 2002 caption | 2010 supplied caption | 2002 preset | 2010 preset |
| --- | --- | --- | --- | --- | --- |
| 1 | 32781 | Optimist | Optimist | 11/10/10 | 9/10/10 |
| 2 | 32782 | Laser | Laser | 14/6/10 | 8/5/10 |
| 3 | 32881 | Board | Board | 40/6/10 | 40/6/10 |
| 4 | 32897 | Snipe | Snipe | 15/7/10 | 8/6/10 |
| 5 | 32784 | JY15 | JY15 | 14/6/10 | 8/5/10 |
| 6 | 32783 | 505 | 505 | 18/5/10 | 16/5/10 |
| 7 | 32786 | Skiff | Skiff | 30/5/11 | 24/6/11 |
| 8 | 32787 | Thistle | Thistle | 16/6/10 | 10/6/10 |
| 9 | 32788 | Lightning | Lightning | 17/7/10 | 11/7/10 |
| 10 | 32793 | Tornado Catamaran | Non-Spinnaker Catamaran | 37/6/10 | 30/7/14 |
| 11 | 32794 | Spinnaker Catamaran | Tornado Catamaran | 37/6/10 | 36/7/14 |
| 12 | 32789 | Keelboat | Keelboat | 25/10/10 | 25/10/10 |
| 13 | 32790 | Sport Boat | Sprit Offshore Racer | 25/7/11 | 40/9/10 |
| 14 | 32791 | Offshore Racer | Offshore Racer | 40/10/10 | 40/10/10 |
| 15 | 32792 | America's Cup | America's Cup | 61/10/12 | 90/10/12 |
| 16 | 32985 | — | Star | — | 19/9/12 |
| 17 | 32986 | — | A Class Catamaran | — | 28/7/12 |
| 18 | 32987 | — | Racer Cruiser | — | 40/10/10 |
| 19 | 32988 | — | Cruising Canvas | — | 40/10/10 |
| 20 | 32989 | — | Model Yacht | — | 14/10/10 |
| 21 | 33100 | — | 25 ft Sportboat | — | 16/6/11 |
| 22 | 33101 | — | 35 ft Sportboat | — | 21/6/11 |
| 23 | 33098 | — | Offshore Catamaran | — | 30/6/11 |
| 24 | 33099 | — | Ideal 18 Keelboat | — | 18/9/12 |
| 25 | 33104 | — | Hide Current Indicator | — | 22/8/10 |
| 26 | 33105 | — | E Scow | — | 27/5/8 |
| 27 | 33106 | — | Flying Scot | — | 10/6/10 |

Command **33104** is a supplied caption defect: its Boat Type item reads **“Hide Current Indicator.”** Original handler `0x49a120` writes selector25 at `0x4da144` and Etchells flag1 at `0x536528`; eight native menu-handler profiles verify those writes. Its interim class7 becomes class6 when original `0x420c00` initializes the Etchells preset. The extracted resource remains unchanged. The semantic description “Etchells Keelboat” identifies behavior, not replacement resource bytes. See [the exact command map](boat-menu-selectors.json) and [controller proof](controller-native-reference-comparison.json).

Both versions check length overrides 20..50 and displacement/sail-area overrides 8..11 before applying preset-specific replacements. 2010 expands subtype flags and has explicit Star, A Class, cruising, model-yacht, sportboat, offshore-catamaran, Ideal18, Etchells, E Scow and Flying Scot branches. For example, E Scow flag `0x53652c` changes the original dynamics' heel limit 18, heel divisor 11 and spinnaker threshold 97; the complete branch tree is independently translated in [boat-dynamics.js](../src/engine/boat-dynamics.js).

## Venue and course controls

Both resources contain the same 15 imaginary-area commands, from northern/eastern/southern/western shores through lakes, island/distance routes, river mouths and branching rivers. The target additionally exposes **18 named racing areas**, with original handler stores to venue `0x4da1f8`. These are Northeast Harbor, ME (33014→1); Marblehead, MA (33015→2); Edgartown, MA (33032→102); Newport, RI (33016→3); West of Block Island, RI (33017→4); Around Block Island, RI (33018→5); Groton, CT (33029→100); Essex, CT (33019→7); Larchmont, NY (33030→101); Annapolis, MD (33021→6); Thurmond Lake, GA / SC (33026→103); Charleston, SC (33022→9); Biscayne Bay, FL (33023→11); Key West, FL (33027→105); St Petersburg, FL (33028→104); Nassau, Bahamas (33031→106); Kingston, ON (33020→10); Chicago, IL (33024→12). They are original simplified geometry definitions; labels do not establish geographic accuracy. Seventeen distinct point constructors plus the venue 5 reuse of venue 4 geometry account for the 18 named choices. Custom venue 999 has its own point computation.

The original five Race Course commands are retained: Windward/Leeward 32816, twice-around 32817, Triangle 32818, twice-around 32819 and Gold Cup 32820. New commands 32992/32993 select the two downwind-finish layouts 6/7 at `0x4da188` and enlarged-course flag `0x53527c`. Command 32994 toggles the gate flag `0x4da1e8`; its actual fleet/course/state enable predicates remain in the original controller. The JSON records all constant stores and exact target captions. [Configuration](../src/engine/configuration.js), [course routing](../src/engine/course.js), [venue literals](../src/engine/venue-definitions.js) and geometry tails compute the target's state rather than loading captured final states.

## Rules and tutorials

The ten Rules Tutorial command IDs and fourteen Tactics/Strategy command IDs match between the two extracted menus. The pause dispatcher grows from **39 to 42 page selectors**, adding 10, 11 and 12 while retaining the existing rule/tactics pages. Tutorial text changes independently of those unchanged command labels.

The original 2002 literal at file offset `0x952a0` states its tutorial is based on the **2001–2004 Racing Rules of Sailing**. The selected target literals state **2009–2012** and describe mark-room at a **three boat length** circle, where the older literal at `0x95e6c` describes a two boat length circle. Exact target addresses and text hashes are in the JSON and [embedded-text.json](../assets/data/embedded-text.json). These are source claims, not a new audit of compliance with every official rule.

Actual proximity logic also changes: `0x42abb0` in 2002 uses a final start-endpoint threshold of radius+2; target `0x43ccf0` uses radius+3 and adds long-course, elapsed-time and current/final-leg conditions. This Manhattan proximity test is separate from the tutorial's rule-zone wording. The target's penalty, interference and AI paths were reconstructed as complete routines.

## Numerical runtime, memory and ABI

Both live original applications initialize x87 **CW027f**, including precision 53 arithmetic. Integer overflow, signed division, original constants, operation association and binary64 spill boundaries remain observable. Shared Float80 and C integer helpers handle those mechanics; target functions load target constants and use target addresses. Integer/native trig tables were independently captured from the 2010 source under its original control word. The earlier isolated 037f evidence remains labeled separately.

| Image property | 2002 | 2010 English |
| --- | --- | --- |
| Preferred base | 0x400000 | 0x400000 |
| Mapped image size | 0x111000 | 0x21c000 |
| Mutable block | 0x491000,129608bytes | 0x4da000,394632bytes |
| Boat selector | 0x491144 | 0x4da144 |
| Boat-option routine | 0x417790 | 0x420c00 |
| Dynamics routine | 0x428c60 | 0x43a030 |
| Position integration | 0x42adb0 | 0x43cf60 |
| Data-only browser bytes | 188488 | 933768 |

The 2010 data-only browser segments are original `.rdata`, `.data` and active `.english`; they contain no x86 code or import bindings. Numeric per-boat fields use their actual 4/8 byte strides. CString cells contain actual native text semantics, with allocator/TLS pointer identities normalized and preserved as separate raw evidence. The native sail helper `0x41bfb0` takes **F64,I32,I32,I32,I32,F64**—eight DWORDs—so treating its stack words as six integer arguments changes geometry. The explicit port and 2971 fresh native cases validate this ABI and all target-specific sail branches, including the Etchells arithmetic association.

Pure wrap/random algorithms, finite x87 arithmetic, integer mechanics, generic memory and GDI/Canvas abstractions were reused. Boat options, race/configuration initialization, venue geometry, wind/current, AI, penalties, apparent wind, dynamics, position integration and rendering use independent target addresses and source reconstruction. A normalized assembly correspondence is a discovery candidate, not proof that different editions behave identically. See [engine-correspondence.json](engine-correspondence.json).

## Native evidence inventory

[The reference index](native-reference-index.json) now records **177 unique fixture hashes, 87,266 explicit original entrypoint calls and 780 distinct entrypoints**. The earlier 161/86,603/777 snapshot is preserved in its metadata. Every counted call has unchanged original text/file capture integrity. The index records exact fixture hashes, per-address counts, mixed per-case routines, control words and matching report hashes. It counts each unique fixture once and never adds report totals, recursive child/API calls or derived wire-response projections again. The 8 intact modal lifecycles are separate observations.

These are **captured-call counts**, not a whole-port pass count. Native capture integrity and JavaScript replay status are separate fields. In this snapshot, 34,032 calls are linked to explicit successful source reports; other source tests may pass without producing such a report. Each report identifies its tested source snapshot, and the final suite determines current port parity. Connected numerical evidence includes 139 real initializations, 7550 retained integrations and 5700 original dynamics calls, each comparing complete mutable state, RNG, names and ordered sounds.

The latest rendering supplements strictly match four native initialized venue chains (16 calls, 12,712 ordered drawing requests), both island chart panels before and at explicitly supplied clock zero (8 calls, 227 requests), and two independent retained island shoreline contexts (20 calls, 15,296 requests). [The venue proof](initialized-venue-render-native-comparison.json), [chart proof](initialized-island-chart-native-comparison.json) and [shore proof](island-shore-context-native-comparison.json) retain immutable native expectations and exact source hashes. The venue probe exposed an original multiplication-order boundary: `scale × factor × width` truncates to 6, while the reassociated expression truncates to 7. [Original instructions and numerical bytes](venue-roof-multiplication-order-review.json) support the source correction.

Retained shoreline predecessor bytes depend on the original caller context. Two intact normal UI launches supplied the production reference; the bounded oracle supplied different independently observed inputs. The port retains the actual POINT alias writes over subsequent calls and never replaces them with per-frame expected values. [The context proof](island-shore-context-native-comparison.json) records this scope. Isolated finite tests do not establish Windows raster identity or every possible caller/exception state equivalence.
