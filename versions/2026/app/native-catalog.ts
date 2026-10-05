/** Native menu IDs / stores audited in the preserved 2010 controller. Menu
 * resource text mislabeled 33104; its implementation selects Etchells (25). */
export const boatChoices=[
 [1,'Optimist',32781],[2,'Laser',32782],[3,'Board',32881],[4,'Snipe',32897],[5,'JY15',32784],[6,'505',32783],[7,'Skiff',32786],[8,'Thistle',32787],[9,'Lightning',32788],[10,'Non-spinnaker catamaran',32793],[11,'Tornado catamaran',32794],[12,'Keelboat',32789],[13,'Sprit offshore racer',32790],[14,'Offshore racer',32791],[15,"America’s Cup",32792],[16,'Star',32985],[17,'A class catamaran',32986],[18,'Racer cruiser',32987],[19,'Cruising canvas',32988],[20,'Model yacht',32989],[21,'25 ft sportboat',33100],[22,'35 ft sportboat',33101],[23,'Offshore catamaran',33098],[24,'Ideal 18',33099],[25,'Etchells',33104],[26,'E Scow',33105],[27,'Flying Scot',33106],
].map(([value,label,command])=>({value:Number(value),label:String(label),command:Number(command)}));
export const fleetChoices=[{value:2,command:32805},{value:5,command:32806},{value:10,command:32807},{value:15,command:32808},{value:20,command:32809},{value:25,command:32810},{value:30,command:32811}];
export const areaChoices=[
 [32795,'North shore',1,0],[32796,'East shore',2,0],[32797,'South shore',3,0],[32798,'West shore',4,0],[32799,'Round Lake',5,0],[32800,'Sound',6,0],[32801,'Island',7,0],[32802,'Distance along shore',8,0],[32964,'Distance around island',8,0],[32803,'North river',9,0],[32804,'South river',10,0],[32961,'Bay',11,0],[32976,'Banana lakes',12,0],[32977,'Five finger lakes',13,0],[32978,'Branching rivers',14,0],
 [33014,'Northeast Harbor',0,1],[33015,'Marblehead',0,2],[33016,'Newport',0,3],[33017,'West Block Island',0,4],[33018,'Around Block Island',0,5],[33019,'Essex',0,7],[33020,'Kingston',0,10],[33021,'Annapolis',0,6],[33022,'Charleston',0,9],[33023,'Biscayne Bay',0,11],[33024,'Chicago',0,12],[33026,'Thurmond Lake',0,103],[33027,'Key West',0,105],[33028,'St Petersburg',0,104],[33029,'Groton',0,100],[33030,'Larchmont',0,101],[33031,'Nassau',0,106],[33032,'Edgartown',0,102],
].map(([command,label,area,venue])=>({command:Number(command),label:String(label),area:Number(area),venue:Number(venue)}));
export const offshoreBoats=new Set([13,14,18,19,20,23]);
export const gateCourses=new Set([1,2,5,7]);
