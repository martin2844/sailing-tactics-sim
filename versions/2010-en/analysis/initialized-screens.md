The new screen reference executes the unchanged English original in six retained chains: boat options at `0x420c00`, race initialization at `0x41be70`, start at `0x413bc0`, results at `0x428b70` and forecast at `0x4298f0`. Each chain uses selector 1, 7, 12, 17, 26 or 27, with 12 boats on basic course 1. These 30 original calls produce 3,304 ordered drawing requests.

The pre-call inputs come from the existing initialization preparation. The original paint calibration supplies a 1024×768 viewport, with the original usable client height of 723. All 90 pen and brush slots use their exact original constructor handle-slot addresses as declared logical platform handles. The constructor fixture, input preparation, paint source and original binary are identified by hashes in the manifest. Between original calls, mutable game data, CRT RNG and semantic CString contents remain native-owned; there are no finish-order or name substitutions.

The original initializer populates 30 nonempty boat names. The 35 original boat-name cells include the unused empty index zero and four empty spare cells at indices 31–34. All 12 active boats have their actual original names. Each relevant call records all 36 semantic CString cells, including the separate HUD string, and raw native allocator/TLS deltas remain available alongside normalized mutable state.

An initial capture exposed a caller-context issue in the reused initialization boundary inputs: the custom-course editor flag `0x5364fc` was one. The original start routine then enters the editor and changes the venue to 999. Those 30 calls are preserved in `original-initialized-editor-screens.json`. The requested normal-start fixture restores the flag to the original constructor/default value zero before the first call. It keeps venue zero throughout and exercises distinct class-specific start-screen drawing.

Both fixtures independently pass reconstruction of every normalized mutable byte and SHA256 through all 60 retained native calls. The original `.text`, complete target file and `0x027f` precision mode remain unchanged. `initialized-screens-native-capture.json` records the fixture hashes and per-call counts. `initialized-screens-cdc-callsites.json` verifies 111 CDC virtual and 100 imported API callsites against exact original instruction boundaries.

The strict public API replay is in `tests/initialized-screens.test.js`. Its native provenance/input check passes, and both numerical initialization calls match for all six profiles. The first renderer replay currently stops in packed argument metadata at `0x41bfb0` for selectors 1/7/12/17 and `0x41a5e0` for selectors 26/27. The resources agent owns these renderer corrections. The results and forecast replay remain pending because each strict chain stops at its first start-screen failure; the original reference fixtures are frozen.

Regenerate the normal native capture with:

```sh
node versions/2010-en/tools/prepare-initialized-screens-inputs.js
nix-shell -p python3 --run 'python3 versions/2010-en/tools/capture_native.py versions/2010-en/analysis/initialized-screens-capture-inputs.json versions/2010-en/tests/fixtures/original-initialized-screens.json'
```

The optional `--editor` argument creates the separately named editor-input manifest. The fixtures establish original drawing-request, game-state, RNG, text and sound evidence under declared platform bindings; they do not establish Windows-versus-Canvas raster identity.
