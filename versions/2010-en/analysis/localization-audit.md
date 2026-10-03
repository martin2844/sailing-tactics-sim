# Independent audit of the 2010 English preservation copy

The reviewed output is `runtime/Tactics2010EnglishPreserved.exe`, SHA-256
`d707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787`.
The preserved Japanese source remains SHA-256
`27c77acfb4fc1a69092a3c2cfebc52f666ff7b2ca53ed80661664c87d9d0c177`;
the preserved 2008 English source also retains its recorded original hash.
The reviewed translation map hash is
`808b2c156144eed4ff9652d7b44a88ca0c66a82928fb3e7b59c58408832a61c8`.

`tests/test_localized_2010.py` contains nine passing checks against the original
and completed executable. These independently verify:

- The source, output and translation-map hashes agree with the build record.
- Original PE section headers, entry point, imports, import-section bytes and
  every non-resource data directory are unchanged. The new `.english` section
  contains read-only initialized data, is aligned, and produces a valid checksum.
- All 76 resource identities, language IDs, code pages and reserved values
  survive. Menu hierarchy, command IDs and flags; dialog control IDs, geometry,
  classes and styles; string IDs; accelerator bindings; and non-text resource
  payloads survive. The English dialog font follows the approved translation
  map; its Latin typography is an intentional localization change.
- All 1,476 translated literals exist at their actual effective addresses.
  Translations that fit remain within their original byte capacity; 229 longer
  literals reside in the appended section.
- Each of the 407 changed existing instruction operands points to its own
  translated literal or one of four specifically verified compass-buffer tails.
  The decoded opcode and instruction size stay unchanged. Normalizing those
  address bytes restores the original instruction bytes, and the entire original
  code section equals the source except for those recorded address operands.
- Every changed byte in the original file extent has a specific allowed purpose:
  PE metadata, the added section header, an in-place translated literal, a
  recorded address operand, or the one edition-selector byte at offset `0xd856c`.
- The actual output retains the 2010 version, Etchells, Flying Scot and E Scow
  labels, 2009–2012 rules wording, three-length zone and model-yacht exception,
  Rule 20 and Rule 18.2(d) text, and all 114 reviewed semantic overrides.

The initial build had a confirmed forecast-label defect. Its compiler-generated
copy block read each compass word in two chunks, while the translator initially
redirected only the first chunk. `north` and `south` consequently became `nort`
and `sout`. The builder now redirects the four original +4 tail loads as well,
after verifying their instruction addresses, memory widths and original zero
padding. No copy instruction or copy width changes. The regression test executes
the completed executable's original x86 copy block at `0x42990b..0x429990` under
Unicorn, stops before its first Windows drawing call, and verifies that the
resulting stack buffers contain complete `north`, `east`, `west` and `south`
strings. Drawing calls and copied instructions are not substituted.

`tools/audit_2010_text_references.py` additionally scans original decoded immediate
and memory operands both linearly and from each Ghidra recovered function body.
For all 229 moved literals it found zero references strictly inside their
original text ranges. Extending each range through uninterrupted zero padding
up to the next independently recovered literal found exactly the four known
compass tail reads; all four now have recorded redirects. The detailed inventory
is `runtime/interior-reference-audit.json`. This bounded scan does not establish
the absence of dynamically computed pointers or prove arbitrary padding belongs
to a source object.

Verification commands:

```sh
tools/python-runtime/bin/python3 -m unittest tests/test_localized_2010.py -v
tools/python-runtime/bin/python3 -m unittest discover -s tests -p 'test_*.py' -v
tools/python-runtime/bin/python3 tools/audit_2010_text_references.py
```

The localization-specific checks passed 9/9; the complete Python suite passed
29/29. There are no remaining confirmed integrity defects in this reviewed
artifact. These checks prove the stated byte, resource, translation and bounded
native-copy invariants. They do not establish full game parity or complete visual
coverage: fixed drawing lengths, all tutorial pages, and every race/UI path still
require runtime inspection. The builder records those rendering limits.
