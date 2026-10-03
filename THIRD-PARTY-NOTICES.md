# Wine System font

`assets/images/system-font-glyphs.png` contains glyph masks measured from the
default System font in Wine 11.0. The original font source is preserved in
`assets/font-source/system.sfd`.

Copyright (C) 2004 Huw D M Davies, Dmitry Timoshkov.

The font is distributed under GNU LGPL version 2.1 or later. The full license is
included in `LICENSES/Wine-LGPL-2.1.txt`. Source:
[Wine 11.0 System font](https://github.com/wine-mirror/wine/blob/wine-11.0/fonts/system.sfd).

The bitmap export and native comparison tools are
`tools/capture_system_font.c`, `tools/capture_system_font.py` and
`tools/capture_system_text.c`. The capture records native font metrics, original
glyph widths and source hashes in `assets/data/system-font.json`.
