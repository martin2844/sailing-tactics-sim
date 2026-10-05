# Native keyboard compatibility

User-requested compatibility step, 2026-10-05. The isolated app translates
browser physical key codes to the original Windows virtual-key values and calls
the preserved handleKeyDown, instead of substituting menu commands. This restores
the original context-sensitive behavior: arrows look rather than steer;
comma/period steer, A/S/I/O/Esc/Backquote control sheet, F1–F3/E shape the sail,
P/G control sails, T/H/J/D/C and +/− maneuver, and Page Up/Down change pace.
Space keeps the native slow/resume or information-dismiss action. F freezes the
native simulation; the modern Pause button or Pause key suspends the worker.

Native camera values drive the 3D view keys, including view distance/elevation,
relative look, windward/leeward, other boat, tactical zoom and orientation.
Orbit remains available and does not alter native state. Keys retain their native
setup meanings after N; Space starts the original setup flow. Original weather,
course, chart, help, coach and setup screens are displayed from read-only copies
of the canonical canvas. They are compatibility panels pending modern equivalents,
not completion of the production overlay/replay/coaching tasks. These panels
transfer bounded ImageBitmap copies separately from small pose/model messages;
their pixels are not included in the 32 KiB typed scene-packet budget.

Input fields, editable content, selects and browser modifiers retain normal
behavior. Buttons retain Space/Enter activation while other sailing shortcuts
remain usable after a button click. Tab navigation is not intercepted. Ordinary
OS key repeat is forwarded; no held-key simulation loop is introduced. Restart
clears any stale panel, and received bitmaps are closed after use or rejection.
createImageBitmap copies the canonical surface; transferToImageBitmap is avoided
because it would clear that simulation surface.

[Five-boat verification](hotkeys-run3-5/verification.json) and
[15-boat verification](hotkeys-run3-15/verification.json) exercise 79 trusted
key events each, including subsequent native paints and native setup contexts.
Whole image, RNG, frame, time, clock and shoreline context are compared with
the frozen original handler at every declared boundary. Text entry remains
isolated. Frozen reference modules are checked byte for byte.

The broader matrix exposed a pre-existing crash in the frozen port when CapsLock
enables true-wind labels. The translation of 0x48b7e0 omitted SetTextColor's zero
argument and TextOut's CString data/length handling. The reviewed native
[disassembly](hotkeys-native-label-disassembly.txt) shows the pushed zero at
0x48b813, signed height/30 + 40 coordinate, decimal value at 0x51158c and prefix
at 0x4ecae0, followed by string data and length at 0x48b854–0x48b85e.
The generated drawing copy repairs only that display routine; frozen sources
remain untouched. The manifest names adapter v2 and records this repair.

CapsLock's native key mutation is compared exactly, then toggled off before
paired painting, since the frozen reference cannot paint the enabled branch.
Separate checks exercise the candidate's enabled full paint and the native GDI
call contract, with unchanged private memory. This exception is explicit in
each verification scope; it is not an exact painted-state claim against the
broken frozen branch. The first failed run and subsequent attempts are retained.

Build/type checks pass. Reproduce with a built preview at localhost:8770:

```sh
node versions/2026/tools/hotkeys-eval.mjs NEW_DIRECTORY 5
node versions/2026/tools/hotkeys-eval.mjs ANOTHER_NEW_DIRECTORY 15
```

The native keyboard summary is available with ? or Keyboard controls. Browser/
desktop-reserved keys work when Chrome delivers them to the focused app; modifiers
for browser navigation are intentionally left alone. This verifies the current
5/15 Keelboat presets and tested setup contexts, not every historic boat/venue or
production replay, two-player mode and touch controls.
