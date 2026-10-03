# Posey PE resource inventory

Extracted from `original/Tact02Demo.exe`; SHA-256 `881dc85dc7500a5ad09e09091d4dd53f8c091f5630d5fabdcc887cc4b007acea`. The file has 66 resource leaves, all language ID 1033 (English, United States).

Run `python3 tools/extract_resources.py` to reproduce the extraction, then `python3 tools/extract_resources.py --verify` to compare every resource byte and derivative hash. The extractor uses only the Python standard library. Run `python3 -m unittest discover -s tests -p test_resources.py -v` for independent resource, image, and UI checks.

## Archive layout

- `assets/manifest.json` records original resource type, ID, language, executable file offset, RVA, byte length, SHA-256, and converted file paths. Generated file hashes make accidental changes detectable.
- `assets/raw/` holds every resource payload exactly as stored in the PE, including Windows DIBs and UI templates.
- `assets/images/` contains RGBA PNG previews, BMP wrappers around the original bitmap payloads, ICO groups, and the original CUR group.
- `assets/audio/` holds original PCM WAV bytes. No resampling or compression was applied.
- `assets/ui/` holds menu hierarchy, dialog/control layout, strings, accelerators, and version information as JSON.

## Counts

| Resource type | Leaves |
|---|---:|
| accelerator | 1 |
| bitmap | 4 |
| cursor | 2 |
| dialog | 4 |
| group_cursor | 1 |
| group_icon | 2 |
| icon | 4 |
| menu | 1 |
| string | 37 |
| version | 1 |
| wave | 9 |

The 37 string blocks contain 261 nonempty strings. The menu contains 192 nonseparator command entries and 192 distinct command IDs. All blank slots and separators remain recoverable from raw bytes; menu separators also appear in JSON.

## Image interpretation

Palette colors are preserved exactly. Windows DIB bottom-up rows are converted to top-down PNG rows; icon/cursor AND masks become alpha. Both cursors have no pixels requiring destination-color inversion, so their PNG transparency represents the masks exactly. Cursor hotspots are retained in CUR files and the manifest. Dialog dimensions remain in Windows dialog units; conversion to screen pixels depends on the selected Windows font metrics.

| Type | ID | Size | Palette/depth | Browser file |
|---|---:|---|---|---|
| cursor | 5 | 32 × 32 | 1 bit | `images/cursor-5-1033.png` |
| cursor | 6 | 16 × 16 | 1 bit | `images/cursor-6-1033.png` |
| bitmap | 26567 | 70 × 39 | 4 bit | `images/bitmap-26567-1033.png` |
| bitmap | 30994 | 12 × 10 | 4 bit | `images/bitmap-30994-1033.png` |
| bitmap | 30995 | 39 × 13 | 4 bit | `images/bitmap-30995-1033.png` |
| bitmap | 30996 | 33 × 11 | 4 bit | `images/bitmap-30996-1033.png` |
| icon | 1 | 32 × 32 | 4 bit | `images/icon-1-1033.png` |
| icon | 2 | 16 × 16 | 4 bit | `images/icon-2-1033.png` |
| icon | 3 | 32 × 32 | 4 bit | `images/icon-3-1033.png` |
| icon | 4 | 16 × 16 | 4 bit | `images/icon-4-1033.png` |

The bitmaps are small interface graphics. The sailing scenes, boats, terrain, and text are not supplied as large bitmap resources; their appearance must be recovered from drawing code and numeric data.

## Audio

| ID | Channels | PCM bits | Hz | Frames | Duration, seconds |
|---:|---:|---:|---:|---:|---:|
| 134 | 1 | 8 | 11111 | 2732 | 0.245882459 |
| 135 | 1 | 8 | 22050 | 18542 | 0.840907029 |
| 136 | 1 | 16 | 22050 | 33399 | 1.514693878 |
| 137 | 1 | 8 | 22050 | 46688 | 2.117369615 |
| 138 | 1 | 16 | 22050 | 45504 | 2.063673469 |
| 139 | 1 | 16 | 22050 | 40044 | 1.816054422 |
| 140 | 1 | 8 | 11111 | 10929 | 0.983619836 |
| 141 | 1 | 8 | 22050 | 14449 | 0.655283447 |
| 142 | 1 | 8 | 22050 | 4224 | 0.191564626 |

Audio event meanings require call-site analysis. Resource IDs alone do not establish whether a sound is a start horn, warning, or other cue.

## Dialog layouts

Each rectangle is `(x, y, width, height)` in dialog units; resource styles and extended styles are preserved numerically in JSON. Static controls with ID 65535 represent Windows ID_STATIC.

### 100: About TACT

Bounds: `[0, 0, 217, 55]`. Font: MS Sans Serif, 8 pt.

| Control ID | Class | Bounds | Caption or ordinal |
|---:|---|---|---|
| 65535 | static | `[11, 17, 20, 20]` | {'ordinal': 128} |
| 65535 | static | `[40, 10, 119, 8]` | Sailing Tactics Simulator 2002 |
| 65535 | static | `[42, 30, 143, 11]` | Copyright (C) 1998 -2001 by C. Dennis Posey |
| 1 | button | `[178, 7, 32, 14]` | OK |

### 131: Select Boat 2 relative speed

Bounds: `[0, 0, 200, 106]`. Font: System, 8 pt.

| Control ID | Class | Bounds | Caption or ordinal |
|---:|---|---|---|
| 1 | button | `[143, 7, 50, 14]` | OK |
| 2 | button | `[143, 24, 50, 14]` | Cancel |
| 1000 | button | `[9, 12, 113, 10]` | Boat 2 much faster than boat 1 |
| 1001 | button | `[9, 25, 94, 10]` | Boat 2 significantly faster |
| 1002 | button | `[9, 37, 79, 10]` | Boat 2 slightly faster |
| 1003 | button | `[9, 51, 55, 10]` | Equal speed |
| 1004 | button | `[9, 65, 79, 10]` | Boat 1 slightly faster |
| 1005 | button | `[9, 77, 94, 10]` | Boat 1 significantly faster |
| 1006 | button | `[9, 89, 75, 10]` | Boat 1 much faster |

### 132: Design Options

Bounds: `[0, 0, 308, 162]`. Font: System, 8 pt.

| Control ID | Class | Bounds | Caption or ordinal |
|---:|---|---|---|
| 1 | button | `[243, 106, 50, 14]` | OK |
| 2 | button | `[244, 135, 50, 14]` | Cancel |
| 1007 | button | `[19, 33, 43, 105]` | Length |
| 1008 | button | `[25, 50, 30, 10]` | 20 ft |
| 1009 | button | `[25, 64, 30, 10]` | 25 ft |
| 1010 | button | `[25, 78, 30, 10]` | 30 ft |
| 1011 | button | `[25, 92, 30, 10]` | 35 ft |
| 1012 | button | `[25, 106, 30, 10]` | 40 ft |
| 1013 | button | `[25, 121, 30, 10]` | 50 ft |
| 1014 | button | `[73, 33, 59, 85]` | Displacement |
| 1015 | button | `[77, 49, 37, 10]` | Heavy |
| 1016 | button | `[77, 65, 47, 10]` | Moderate |
| 1017 | button | `[77, 83, 32, 10]` | Light |
| 1018 | button | `[77, 101, 50, 10]` | Ultra Light |
| 1019 | button | `[143, 33, 78, 61]` | Sail Area |
| 1020 | button | `[147, 48, 53, 10]` | Lots of Sail |
| 1021 | button | `[147, 64, 43, 10]` | Average |
| 1022 | button | `[147, 80, 77, 10]` | Less than Average |
| 1023 | button | `[232, 34, 61, 48]` | Rig |
| 1024 | button | `[236, 47, 48, 10]` | Fractional |
| 1025 | button | `[236, 65, 48, 10]` | Masthead |

### 30721: New

Bounds: `[9, 26, 183, 70]`. Font: MS Sans Serif, 8 pt.

| Control ID | Class | Bounds | Caption or ordinal |
|---:|---|---|---|
| 65535 | static | `[6, 5, 123, 8]` | &New  |
| 100 | listbox | `[6, 15, 125, 49]` |  |
| 1 | button | `[137, 6, 40, 14]` | OK |
| 2 | button | `[137, 23, 40, 14]` | Cancel |
| 57670 | button | `[137, 43, 40, 14]` | &Help |

## Menu command map

These IDs can be matched to MFC message-map records and command handlers. Captions retain original ampersands and whitespace in JSON; table display condenses whitespace. Check/enabled flags are template defaults, and live behavior depends on update handlers.

| Menu path | Command ID | Hex | Caption |
|---|---:|---|---|
| &Control | 32771 | `0x8003` | Start spacebar |
| &Control | 32907 | `0x808b` | Weather Forecast &W |
| &Control | 32939 | `0x80ab` | Show Race Results |
| &Control | 32962 | `0x80c2` | No Strategic View &4 |
| &Control | 32776 | `0x8008` | No Header / Lift Info |
| &Control | 32957 | `0x80bd` | Colored Mainsails |
| &Control | 32963 | `0x80c3` | Warning of Right of Way Boat |
| &Control | 32984 | `0x80d8` | Slow Simulator on Warning backslash |
| &Control | 32965 | `0x80c5` | Show True Wind |
| &Control | 32966 | `0x80c6` | No Sounds |
| &Control | 32910 | `0x808e` | Freeze F |
| &Control | 32968 | `0x80c8` | Replay Leg backspace |
| &Control | 32777 | `0x8009` | Another Race &N |
| &Control | 32983 | `0x80d7` | Simplify Graphics |
| &Control | 32958 | `0x80be` | Monochrome |
| &Control | 57665 | `0xe141` | E&xit |
| &Option | 32778 | `0x800a` | One Player |
| &Option | 32779 | `0x800b` | Two Players |
| &Option → Difficulty Level | 32882 | `0x8072` | 1 |
| &Option → Difficulty Level | 32883 | `0x8073` | 2 |
| &Option → Difficulty Level | 32884 | `0x8074` | 3 |
| &Option → Difficulty Level | 32885 | `0x8075` | 4 |
| &Option → Difficulty Level | 32886 | `0x8076` | 5 |
| &Option → Difficulty Level | 32887 | `0x8077` | 6 |
| &Option → Difficulty Level | 32888 | `0x8078` | 7 |
| &Option → Difficulty Level | 32889 | `0x8079` | 8 |
| &Option → Difficulty Level | 32890 | `0x807a` | 9 |
| &Option → Difficulty Level | 32891 | `0x807b` | 10 |
| &Option → Difficulty Level | 32892 | `0x807c` | 11 |
| &Option → Difficulty Level | 32893 | `0x807d` | 12 |
| &Option → Difficulty Level | 32894 | `0x807e` | 13 |
| &Option → Difficulty Level | 32895 | `0x807f` | 14 |
| &Option → Difficulty Level | 32896 | `0x8080` | 15 |
| &Option → Boat Type | 32781 | `0x800d` | Optimist |
| &Option → Boat Type | 32782 | `0x800e` | Laser |
| &Option → Boat Type | 32881 | `0x8071` | Board |
| &Option → Boat Type | 32897 | `0x8081` | Snipe |
| &Option → Boat Type | 32784 | `0x8010` | JY15 |
| &Option → Boat Type | 32783 | `0x800f` | 505 |
| &Option → Boat Type | 32786 | `0x8012` | Skiff |
| &Option → Boat Type | 32787 | `0x8013` | Thistle |
| &Option → Boat Type | 32788 | `0x8014` | Lightning |
| &Option → Boat Type | 32793 | `0x8019` | Tornado Catamaran |
| &Option → Boat Type | 32794 | `0x801a` | Spinnaker Catamaran |
| &Option → Boat Type | 32789 | `0x8015` | Keelboat |
| &Option → Boat Type | 32790 | `0x8016` | Sport Boat |
| &Option → Boat Type | 32791 | `0x8017` | Offshore Racer |
| &Option → Boat Type | 32792 | `0x8018` | America's Cup |
| &Option → Fleet Size | 32805 | `0x8025` | 2 Match Racing |
| &Option → Fleet Size | 32806 | `0x8026` | 5 |
| &Option → Fleet Size | 32807 | `0x8027` | 10 |
| &Option → Fleet Size | 32808 | `0x8028` | 15 |
| &Option → Fleet Size | 32809 | `0x8029` | 20 |
| &Option → Fleet Size | 32810 | `0x802a` | 25 |
| &Option → Fleet Size | 32811 | `0x802b` | 30 |
| &Option → Racing Area | 32795 | `0x801b` | Shoreline to the North |
| &Option → Racing Area | 32796 | `0x801c` | Shoreline to the East |
| &Option → Racing Area | 32797 | `0x801d` | Shoreline to the South |
| &Option → Racing Area | 32798 | `0x801e` | Shoreline to the West |
| &Option → Racing Area | 32799 | `0x801f` | Round Lake |
| &Option → Racing Area | 32800 | `0x8020` | Sound |
| &Option → Racing Area | 32801 | `0x8021` | Round the Island |
| &Option → Racing Area | 32802 | `0x8022` | Distance Race - Along Shore |
| &Option → Racing Area | 32964 | `0x80c4` | Distance Race - Around Island |
| &Option → Racing Area | 32803 | `0x8023` | River Mouth North |
| &Option → Racing Area | 32804 | `0x8024` | River Mouth South |
| &Option → Racing Area | 32961 | `0x80c1` | Bay |
| &Option → Racing Area | 32976 | `0x80d0` | Banana Lakes |
| &Option → Racing Area | 32977 | `0x80d1` | Five Finger Lakes |
| &Option → Racing Area | 32978 | `0x80d2` | Branching Rivers |
| &Option | 32938 | `0x80aa` | Southern Hemisphere |
| &Option → Wind Strength | 32812 | `0x802c` | Light |
| &Option → Wind Strength | 32813 | `0x802d` | Moderate |
| &Option → Wind Strength | 32814 | `0x802e` | Strong |
| &Option | 32815 | `0x802f` | Tidal Currents |
| &Option → Race Course | 32816 | `0x8030` | Windward / Leeward |
| &Option → Race Course | 32817 | `0x8031` | Windward / Leeward Twice Around |
| &Option → Race Course | 32818 | `0x8032` | Triangle |
| &Option → Race Course | 32819 | `0x8033` | Triangle Twice Around |
| &Option → Race Course | 32820 | `0x8034` | Gold Cup |
| &Option | 32821 | `0x8035` | Short Course |
| &Option | 32908 | `0x808c` | Marks to Starboard |
| &Option | 32927 | `0x809f` | Night Race |
| &Option | 32822 | `0x8036` | Wheel Steering |
| &Option | 32823 | `0x8037` | Design |
| &Option | 32824 | `0x8038` | No Series Scoring. |
| &Option | 32960 | `0x80c0` | New Series |
| &Option | 32979 | `0x80d3` | 10 Min Pre-start |
| &Option | 32980 | `0x80d4` | 5 Min Pre-start |
| &Option | 32981 | `0x80d5` | Perfect Start at Pin |
| &Option | 32982 | `0x80d6` | Perfect Start at C. Boat |
| &Simulate speed | 32872 | `0x8068` | &1 slowest |
| &Simulate speed | 32873 | `0x8069` | &2 |
| &Simulate speed | 32874 | `0x806a` | &3 |
| &Simulate speed | 32875 | `0x806b` | &4 |
| &Simulate speed | 32876 | `0x806c` | &5 |
| &Simulate speed | 32877 | `0x806d` | &6 |
| &Simulate speed | 32878 | `0x806e` | &7 |
| &Simulate speed | 32879 | `0x806f` | &8 |
| &Simulate speed | 32880 | `0x8070` | &9 |
| &Simulate speed | 32909 | `0x808d` | 1&0 |
| &Simulate speed | 32969 | `0x80c9` | 11 |
| &Simulate speed | 32970 | `0x80ca` | 12 |
| &Simulate speed | 32971 | `0x80cb` | 13 |
| &Simulate speed | 32972 | `0x80cc` | 14 |
| &Simulate speed | 32973 | `0x80cd` | 15 fastest |
| &Simulate speed | 32974 | `0x80ce` | Faster page up |
| &Simulate speed | 32975 | `0x80cf` | Slower page dn |
| 3D &view | 32825 | `0x8039` | Close in View &1 |
| 3D &view | 32826 | `0x803a` | Wide View &2 |
| 3D &view | 32827 | `0x803b` | High Viewpoint &3 |
| 3D &view | 32912 | `0x8090` | Change Viewpoint &V |
| 3D &view | 32835 | `0x8043` | Automatic View &0 |
| 3D &view | 32828 | `0x803c` | Look Ahead up arrow |
| 3D &view | 32829 | `0x803d` | Look Right right arrow |
| 3D &view | 32830 | `0x803e` | Look Left left arrow |
| 3D &view | 32831 | `0x803f` | Look Astern down arrow |
| 3D &view | 32832 | `0x8040` | Look to Windward &5 |
| 3D &view | 32833 | `0x8041` | Look to Leeward &7 |
| 3D &view | 32834 | `0x8042` | Look at Other Boat &9 |
| 3D &view | 32913 | `0x8091` | Hide Sails &U |
| &Top view | 32898 | `0x8082` | Zoom In Tactical &Z |
| &Top view | 32899 | `0x8083` | Zoom Out Tactical &X |
| &Top view | 32914 | `0x8092` | Bow Up Orientation |
| &Top view | 32916 | `0x8094` | Wind Up Orientation |
| &Top view | 32915 | `0x8093` | Same Orientation as Sailing View |
| &Top view | 32919 | `0x8097` | Show Tracks ~ |
| &Top view | 32918 | `0x8096` | Show laylines, Equal Line |
| &Top view | 32902 | `0x8086` | Wind Chart [ |
| &Top view | 32903 | `0x8087` | Tide Chart ] |
| &Top view | 32904 | `0x8088` | Tide @ +1 hour + |
| &Top view | 32905 | `0x8089` | Race Course &R |
| S&teer | 32842 | `0x804a` | 10 to Port < or Left Click |
| S&teer | 32841 | `0x8049` | 10 to Starboard > or Right Click |
| S&teer | 32843 | `0x804b` | Closehauled &C |
| S&teer | 32844 | `0x804c` | Pinch - |
| S&teer | 32845 | `0x804d` | Foot + |
| S&teer | 32846 | `0x804e` | Tack &T |
| S&teer | 32849 | `0x8051` | Reach &H |
| S&teer | 32847 | `0x804f` | Jibe &J |
| S&teer | 32848 | `0x8050` | Run Downwind &D |
| Sh&eet | 32850 | `0x8052` | Automatic Sheet (max speed) &A |
| Sh&eet | 32851 | `0x8053` | Max Luff &S |
| Sh&eet | 32852 | `0x8054` | Sheet In 20% &I |
| Sh&eet | 32853 | `0x8055` | Sheet Out 20% &O |
| S&ail | 32854 | `0x8056` | Flat F1 |
| S&ail | 32855 | `0x8057` | Medium F2 |
| S&ail | 32856 | `0x8058` | Baggy F3 |
| S&ail | 32911 | `0x808f` | Change Shape &E |
| S&ail | 32857 | `0x8059` | Spin Up (wing) &P |
| S&ail | 32858 | `0x805a` | Spin Down P |
| S&ail | 32859 | `0x805b` | #1 Genoa |
| S&ail | 32860 | `0x805c` | #2 Genoa |
| S&ail | 32861 | `0x805d` | #3 Blade |
| &Help | 32862 | `0x805e` | Simulator Operation |
| &Help | 32924 | `0x809c` | What You See (Sailing Views) |
| &Help | 32864 | `0x8060` | View Control |
| &Help | 32865 | `0x8061` | Steering |
| &Help | 32866 | `0x8062` | Sail Control |
| &Help | 32925 | `0x809d` | Key Command Summary &? |
| &Help | 32868 | `0x8064` | New Features |
| &Help | 32869 | `0x8065` | Tips for First Use |
| &Help | 57664 | `0xe140` | &About This Simulator |
| &Help | 32967 | `0x80c7` | Show Button Explanations |
| &Help | 59393 | `0xe801` | Hide Menu Item Help |
| Co&ach | 32923 | `0x809b` | Coach &Y |
| Co&ach → Rules Tutorial | 32928 | `0x80a0` | Introduction |
| Co&ach → Rules Tutorial | 32931 | `0x80a3` | Opposite Tacks |
| Co&ach → Rules Tutorial | 32929 | `0x80a1` | Same Tack |
| Co&ach → Rules Tutorial | 32930 | `0x80a2` | Overtaking |
| Co&ach → Rules Tutorial | 32932 | `0x80a4` | Marks and Obstructions |
| Co&ach → Rules Tutorial | 32933 | `0x80a5` | Rounding a Windward Mark |
| Co&ach → Rules Tutorial | 32934 | `0x80a6` | Tacking for Obstructions |
| Co&ach → Rules Tutorial | 32935 | `0x80a7` | Same Tack Before Starting |
| Co&ach → Rules Tutorial | 32936 | `0x80a8` | Room at a Starting Mark |
| Co&ach → Rules Tutorial | 32937 | `0x80a9` | Miscellaneous |
| Co&ach → Tactics + Strategy Tutorial | 32940 | `0x80ac` | Introduction |
| Co&ach → Tactics + Strategy Tutorial | 32941 | `0x80ad` | Wind Shift Effects - Concepts |
| Co&ach → Tactics + Strategy Tutorial | 32942 | `0x80ae` | Lifts |
| Co&ach → Tactics + Strategy Tutorial | 32943 | `0x80af` | Headers |
| Co&ach → Tactics + Strategy Tutorial | 32955 | `0x80bb` | Death by Layline |
| Co&ach → Tactics + Strategy Tutorial | 32944 | `0x80b0` | Strategy for Oscillating Winds |
| Co&ach → Tactics + Strategy Tutorial | 32945 | `0x80b1` | Strategy for One Side Favored |
| Co&ach → Tactics + Strategy Tutorial | 32954 | `0x80ba` | Downwind Strategy |
| Co&ach → Tactics + Strategy Tutorial | 32946 | `0x80b2` | Wind Prediction - 1 |
| Co&ach → Tactics + Strategy Tutorial | 32947 | `0x80b3` | Wind Prediction - 2 |
| Co&ach → Tactics + Strategy Tutorial | 32948 | `0x80b4` | Currents |
| Co&ach → Tactics + Strategy Tutorial | 32949 | `0x80b5` | Wind Interference from Other Boats |
| Co&ach → Tactics + Strategy Tutorial | 32950 | `0x80b6` | Starting |
| Co&ach → Tactics + Strategy Tutorial | 32951 | `0x80b7` | Mark Rounding |
| Co&ach | 32926 | `0x809e` | Glossary |
| Co&ach | 32956 | `0x80bc` | Bibliography |

## Accelerator table

The embedded table is an MFC framework table. The many letter, function-key, mouse, and arrow-key hints in the simulation menus are not present here; their handling must be recovered from the view's keyboard and mouse handlers.

| Shortcut | Command ID | Hex |
|---|---:|---|
| Ctrl+N | 57600 | `0xe100` |
| Ctrl+O | 57601 | `0xe101` |
| Ctrl+S | 57603 | `0xe103` |
| Ctrl+Z | 57643 | `0xe12b` |
| Ctrl+X | 57635 | `0xe123` |
| Ctrl+C | 57634 | `0xe122` |
| Ctrl+V | 57637 | `0xe125` |
| Alt+Backspace | 57643 | `0xe12b` |
| Shift+Delete | 57635 | `0xe123` |
| Ctrl+Insert | 57634 | `0xe122` |
| Shift+Insert | 57637 | `0xe125` |
| F6 | 57680 | `0xe150` |
| Shift+F6 | 57681 | `0xe151` |

## Version metadata

The version resource identifies `TACT.EXE`, `TACT MFC Application`, and version `1, 0, 0, 1`. Its copyright text says 1997; the About dialog separately says “Sailing Tactics Simulator 2002” and “Copyright (C) 1998 -2001 by C. Dennis Posey”. Both are preserved as evidence rather than reconciled by assumption.

## Verification scope

Integrity tests compare all 66 raw resources directly with original executable offsets, independently parse PNG chunks and CRCs, compare every converted image pixel with the original DIB palette/mask/orientation, check ICO/CUR payloads and cursor hotspots, and verify key command/dialog/string identities. Extraction has succeeded and all four preservation tests pass. This establishes resource fidelity; it does not establish simulation or rendering behavior parity.
