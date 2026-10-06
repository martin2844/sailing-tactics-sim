# ENG-03b-1 — Extract race and information phase dispatch

2026-10-06. The strict TypeScript `dispatchRacePhases` now owns the state
transition sequence previously embedded in `drawPaintContent`. It uses a narrow
memory port and injected actions and runs in Node without DOM/Canvas/GDI. Named
fields cover the legacy phase counter, setup/init/racing, results, series pause,
forecast, course/wind/current charts and coach/help pages. Sequential condition
reloads are preserved because prior actions can alter later eligibility.

A small compatibility action adapter supplies existing callbacks temporarily.
The declared preparation adapter delegates screen dispatch to the new controller
only in 2026. Frozen 2002/2010 files are untouched. The main offscreen lifecycle,
scene drawing, pixel reads and private model/information drawing still remain;
this milestone does not claim completed independence.

Evaluation:

- Two controller tests pass: 112 combinations compared with the actual recovered
  dispatcher, including callbacks that change phase/results during dispatch, plus
  signed DWORD counter overflow. The five observer tests remain passing.
- [65 paired boundaries](cutover-race-phases-2026-10-06/verification.json) pass
  across five/fifteen Keelboats, Tornado/strong wind and Island Optimist/west wind.
  Both normal and traced candidates match the pinned 2026 oracle byte for byte,
  including RNG/time/clock/frame/shore context. Actual racing plus forecast,
  course, coach and key-summary opening/dismissal are covered.
- Two frozen 2010 comparison lanes retain all ten exact boundaries at startup
  and 32 paints with native port/starboard/tack commands.
- [Phase ledgers](cutover-race-phases-2026-10-06/phase-ledgers.json.gz) remain
  untruncated; counts include enclosing phases and must not be summed across them.
- [14 controls/depth checks](cutover-phases-controls-2026-10-06/verification.json)
  pass, including host pause, ignored paused sailing inputs and chart dismissal.
- [Complete island championship race](cutover-phases-island-champ-2026-10-06/verification.json) passes: all four AI boats finish, unattended player DNFs at the cutoff, results open and the next race resets cleanly.
- Build/type checks pass. Preservation verification reports all 6,471 inputs
  unchanged. Coverage remains bounded; this does not certify every original option.

Implementation rules are in [engine standards](../../docs/engine-standards.md).
Remaining ENG-03b work includes waypoint/camera writes, slowdown, dynamic coach
preparation, result/score semantics and final cleanup, followed by RNG/pixel
extraction in ENG-03c.
