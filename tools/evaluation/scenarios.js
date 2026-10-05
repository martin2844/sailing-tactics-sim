/** Original menu choices. A common menu selection does not equate native geometry. */
const both=Object.freeze(['2002','2010']);
const make=(id,label,settings,commands,extra={})=>Object.freeze({
  id,label,editions:both,controlled:false,quick:false,phase:'prestart',
  settings:Object.freeze(settings),commands:Object.freeze(commands),...extra,
});

export const scenarios=Object.freeze([
  make('matched-round-lake-15','Common menus: 15 Keelboats, Round Lake, Windward / Leeward, speed 10',
    {fleet:15,boatSelector:12,area:5,venue:0,course:1,speed:10,automaticSlowdown:'off'},
    [32799,32816,32789,32808,32909],{controlled:true,quick:true,
      comparisonScope:'Matching original menus and fleet; native course length, timestep, initialization and geometry are recorded and may differ between editions.'}),
  make('default-speed-10','Original defaults, speed 10, native automatic slowdown',
    {speed:10,automaticSlowdown:'native'},[32909],{quick:true}),
  make('default-speed-1','Original defaults, speed 1, native automatic slowdown',
    {speed:1,automaticSlowdown:'native'},[32872]),
  make('shoreline-2010','2010 north shoreline, 15 Keelboats, speed 10',
    {fleet:15,boatSelector:12,area:1,venue:0,course:1,speed:10,automaticSlowdown:'off'},
    [32795,32816,32789,32808,32909],{editions:Object.freeze(['2010']),controlled:true}),
  make('fleet-30-2010','2010 Round Lake, 30 Keelboats, speed 10',
    {fleet:30,boatSelector:12,area:5,venue:0,course:1,speed:10,automaticSlowdown:'off'},
    [32799,32816,32789,32811,32909],{editions:Object.freeze(['2010']),controlled:true}),
  make('matched-round-lake-15-race','Common 15-boat menus after native clock 100',
    {fleet:15,boatSelector:12,area:5,venue:0,course:1,speed:10,automaticSlowdown:'off'},
    [32799,32816,32789,32808,32909],{controlled:true,phase:'race',clock:100,
      comparisonScope:'Matching menu inputs and clock threshold, not identical cross-edition world state.'}),
]);

export function getScenario(id){
  const scenario=scenarios.find(row=>row.id===id);
  if(!scenario)throw new RangeError(`Unknown evaluation scenario: ${id}`);
  return scenario;
}
