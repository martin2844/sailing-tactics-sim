import type {SceneSnapshot} from './protocol';
import {boatName} from './fleet-names';
import type {EventSession} from './event-session';
export const ordinal=(value:number)=>`${value}${value%100>=11&&value%100<=13?'th':value%10===1?'st':value%10===2?'nd':value%10===3?'rd':'th'}`;
export class RaceResults{
 readonly element=document.createElement('section');private heading=document.createElement('h1');private intro=document.createElement('p');private table=document.createElement('table');private standings=document.createElement('div');private next=document.createElement('button');private watch=document.createElement('button');private dismissed=false;private key='';
 constructor(newEvent:()=>void,private event:()=>EventSession,nextRace:()=>void){
  this.element.id='race-results';this.element.hidden=true;this.element.setAttribute('aria-labelledby','results-heading');this.heading.id='results-heading';
  const card=document.createElement('div');card.className='result-card';const kicker=document.createElement('span');kicker.className='starter-location';kicker.textContent='RACE RESULTS';
  this.watch.textContent='Watch the fleet';this.watch.addEventListener('click',()=>{this.dismissed=true;this.element.hidden=true;});const next=document.createElement('button');next.textContent='Choose a new race';next.addEventListener('click',newEvent);
  this.next.id='next-race';this.next.textContent='Next race →';this.next.hidden=true;this.next.addEventListener('click',nextRace);
  const actions=document.createElement('div');actions.className='result-actions';actions.append(this.watch,this.next,next);card.append(kicker,this.heading,this.intro,this.table,this.standings,actions);this.element.append(card);
 }
 reset(){this.dismissed=false;this.key='';this.element.hidden=true;}
 update(state:SceneSnapshot){
  const event=this.event();event.receive(state);const player=state.boats[0];if(!player.finished){this.reset();return;}
  const key=`${state.generation}:${event.activeRace}:${state.completedRaces}:${state.resultsReady}:${player.finished}:${state.boats.map(b=>b.finished).join(',')}`;if(key===this.key)return;this.key=key;
  const placed=player.finished<=state.boats.length;this.heading.textContent=placed?`Finished in ${ordinal(player.finished)} place.`:'Race retired.';
  this.intro.textContent=`${boatName(player)} · ${state.boats.length} boats${state.resultsReady?' · Race complete':' · The remaining fleet is still racing'}`;
  this.table.replaceChildren();const head=document.createElement('thead'),row=document.createElement('tr');for(const text of ['Place','Boat','Result']){const th=document.createElement('th');th.textContent=text;row.append(th);}head.append(row);this.table.append(head);
  const body=document.createElement('tbody');for(const boat of [...state.boats].sort((a,b)=>(a.finished||Infinity)-(b.finished||Infinity)||a.id-b.id)){const row=document.createElement('tr');if(boat.id===1)row.className='own-result';for(const text of [boat.finished>state.boats.length?'—':boat.finished?String(boat.finished):'—',boatName(boat),boat.finished>state.boats.length?'Retired':boat.finished?'Finished':'Racing']){const cell=document.createElement('td');cell.textContent=text;row.append(cell);}body.append(row);}this.table.append(body);
  this.standings.replaceChildren();this.next.hidden=!event.canContinue;
  if(event.mode==='championship'&&state.resultsReady){
   const heading=document.createElement('h2');heading.textContent=event.complete?'Championship complete':`Standings · Race ${event.activeRace} of ${event.length}`;
   const table=document.createElement('table'),header=document.createElement('tr');for(const text of ['Rank','Boat',...event.races.map(r=>'R'+r.race),'Points']){const th=document.createElement('th');th.textContent=text;header.append(th);}const head=document.createElement('thead');head.append(header);table.append(head);const body=document.createElement('tbody');
   event.standings.forEach((boat,index)=>{const row=document.createElement('tr');if(boat.id===1)row.className='own-result';for(const text of [String(index+1),boatName(boat),...boat.finishes.map(f=>f>state.boats.length?'Ret.':String(f)),String(Math.floor(boat.points/100))]){const cell=document.createElement('td');cell.textContent=text;row.append(cell);}body.append(row);});table.append(body);this.standings.append(heading,table);
   if(event.complete){const position=event.standings.findIndex(b=>b.id===1)+1;this.heading.textContent=`Championship: ${ordinal(position)} place.`;}
  }
  this.watch.hidden=state.resultsReady;this.element.hidden=this.dismissed&&!state.resultsReady;
 }
}
