# Exact 2010 English browser inputs

The authority is `runtime/Tactics2010EnglishPreserved.exe`, SHA-256
`d707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787`,
1,899,520 bytes. Extraction reads this file without modifying it. The existing
localization record describes differences from the upstream Japanese executable;
those changes are part of this fixed target, not changes introduced by extraction.

`assets/manifest.json` preserves all 76 resource identities, raw payloads and
hashes, with 117 generated files. The active PE resource directory is RVA
`0x1aa000` in the appended `.english` section. The older `.rsrc` bytes remain in
the executable but are not the active English resource directory.

| Resource | Count |
|---|---:|
| Menu | 1 |
| Dialog | 5 |
| String block | 43 |
| Accelerator | 1 |
| Bitmap | 4 |
| Icon / group icon | 4 / 2 |
| Cursor / group cursor | 2 / 1 |
| Version | 1 |
| WAVE | 12 |

The menu has 419 entries and 312 distinct command IDs, including Flying Scot
33106 and E Scow 33105. There are 293 nonempty resource strings. Menu hierarchy,
flags, accelerators, dialog geometry/styles/control IDs, font selection, and
resource language IDs are exact. Resource languages remain 1033 and 1041 even
though captions in the active directory are English. `ui/string-tables.json`
retains each resource/language identity separately; `ui/strings.json` is the
convenient flattened string-ID view.

Resource text is UTF-16LE. Embedded display text is Windows-1252, including the
existing localization's padding. `data/embedded-text.json` verifies all 1,476
localized literals at their actual effective addresses: 1,247 remain in place,
229 are appended. The two deliberately leading-NUL strings remain leading-NUL.
Fixed original drawing lengths remain separate behavior; extraction does not
extend a text call or strip padding to improve appearance.

The three browser memory segments contain 933,768 bytes of exact initial data:

| Section | Address | Bytes | Initialized / zero fill |
|---|---:|---:|---:|
| `.rdata` | `0x4c8000` | 72,704 | 72,704 / 0 |
| `.data` | `0x4da000` | 394,632 | 95,744 / 298,888 |
| `.english` | `0x5aa000` | 466,432 | 466,432 / 0 |

`data/original-memory.json` records exact lengths, addresses and SHA-256 hashes.
These files exclude PE headers, x86 instructions, `.idata` imports and the stale
resource section. Original pointer-valued constants remain data; browser game
functions must use native JavaScript. Read-only `.english` contains both active
resources and appended English strings, so copying only the older data sections
would omit actual target strings.

`data/source-layout.json` records the full PE layout and all 358 import bindings.
The preferred base is `0x400000`, entry point `0x49ba50`, and image size
`0x21c000`; no relocation or TLS directory is present. CRT/MFC code is statically
linked. Its addresses and data layout differ from 2002. The prior Japanese
1,562-function Ghidra export is an initial recovered-function inventory, not
evidence of complete 2010 code discovery or browser parity.

The intact target's real loader/startup has now been observed using hardware
breakpoints: after CRT precision selection and at first paint, frame and scene,
the control word is `0x027f`. See `startup-precision.json` and its raw JSONL.
This establishes 53-bit arithmetic precision for the observed Wine startup;
2010 calibration, trig tables and routine outputs still require their own
original-code references. 2002 numeric assets cannot establish 2010 parity.

Reproduce from the project root with any Python 3 runtime (standard library only):

```sh
python3 versions/2010-en/tools/extract_assets.py
python3 versions/2010-en/tools/extract_assets.py --verify
python3 versions/2010-en/tools/test_assets.py -v
```

The five integrity checks verify complete exact regeneration, the active
resource directory and added boat IDs, literal padding/leading NULs, rejection
of changed source/data, and exclusion of code/import sections. The original
target hash remains unchanged after extraction and native observation.
