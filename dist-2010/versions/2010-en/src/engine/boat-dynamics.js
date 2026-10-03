import { add32,sub32,imul32,idiv32,i32 } from '../../../../src/runtime/c-types.js';
import { Float80 } from '../../../../src/runtime/float80.js';
import { sinCosX87 } from '../../../../src/runtime/transcendentals.js';
import { wrapDegreesOnce } from '../../../../src/engine/integer-core.js';
import { apparentWindExtended } from './apparent-wind.js';
import { distanceToBoat } from './movement.js';
import { updateInterference,updateSpinnakerDrag,updateMarkStartPenalties,prestartSpeedPercent } from './penalties.js';

export const BOAT_DYNAMICS_ADDRESS=0x43a030;
const at=(address,boat,stride=4)=>add32(address,imul32(boat,stride))>>>0;
const integer=Float80.fromInteger;
const spill=value=>Float80.fromNumber(value.toNumber());
const abs=value=>value<0?sub32(0,value):value;

/** Complete2010 boat dynamics, with original child calls and x87 spill ordering. */
export function updateBoatDynamics(memory,boat,rng,options={}){
 boat=i32(boat);
 const r=a=>memory.readI32(a),w=(a,v)=>memory.writeI32(a,v);
 const rb=a=>r(at(a,boat)),wb=(a,v)=>w(at(a,boat),v);
 const f=a=>Float80.fromNumber(memory.readF64(a)),fb=a=>f(at(a,boat,8));
 const wf=(a,v)=>memory.writeF64(at(a,boat,8),v.toNumber());
 const flag=a=>r(a)===1;
 const trig=options.trig;
 if((abs(r(0x5364e8))&1)===0)return;
 if(typeof trig?.extended!=='function')throw new TypeError('2010 boat dynamics requires original native angle captures');
 const cos=angle=>trig.extended(angle).cosine;
 const continuous=options.sinCos??sinCosX87;
 if(flag(0x5364c8))wb(0x4fe778,2);
 const initialClass=r(0x4da190),initialTime=r(0x4f8cd0);
 let heelLimit=initialClass>=6&&initialClass<=8?22:15;
 if(flag(0x5363b8))heelLimit=10;
 if(r(0x5363c0)>0)heelLimit=19;
 if(flag(0x4fb410))heelLimit=15;
 if(flag(0x5364bc))heelLimit=22;
 if(flag(0x53652c))heelLimit=18;
 w(0x4f4200,heelLimit);w(0x4fe62c,30);
 if(boat<=r(0x4da140)&&add32(rb(0x535620),30)<initialTime)wb(0x5116e0,0);
 if(initialTime<-150)wb(0x5116e0,0);
 const oldSpeed=rb(0x4fdfe8),oldHeel=rb(0x4fc2c0);
 wb(0x522f28,oldHeel);
 let spinLimit=initialClass===2||flag(0x5364c8)||flag(0x5364c4)?140:105;
 if(flag(0x5364c0)||flag(0x5363c4)||initialClass===8||flag(0x53652c))spinLimit=97;
 w(0x525a98,spinLimit);
 if(boat>r(0x4da140)){
  if(rb(0x4f4478)>0)wb(0x4f4478,sub32(rb(0x4f4478),1));
  const raise=spinLimit<rb(0x4fecc8)&&initialClass>1&&initialClass!==9&&rb(0x535178)>90&&initialTime>0&&rb(0x5116e0)!==10&&rb(0x4fe6d0)===0;
  if(rb(0x4f4478)===0){
   if(raise){if(rb(0x5350d8)===0)wb(0x4f4478,2);wb(0x5350d8,1);}
   else wb(0x5350d8,0);
  }
  if(rb(0x4f8538)<3&&r(0x4da19c)!==8)wb(0x5350d8,0);
 }
 if(flag(0x5364c8)&&boat<=r(0x4da140)){
  if(boat===1)w(0x4f4520,spinLimit<r(0x4feccc)?1:0);
  if(boat===2&&r(0x4da140)===2)w(0x4f4524,spinLimit<r(0x4fecd0)?1:0);
 }
 let tackDuration=(rb(0x4fb380)<13?1:0)+5;
 if(r(0x5363b8)===0&&r(0x5363bc)===0)tackDuration=imul32(tackDuration,2);
 if(flag(0x5363bc))tackDuration=2;
 if(r(0x4da174)<4)tackDuration=idiv32(tackDuration,2);
 if(r(0x4da174)===1)tackDuration=0;
 w(0x536494,tackDuration);
 let heelDivisor=initialClass===3?12:9;
 if(initialClass===1)heelDivisor=8;
 if(initialClass===2)heelDivisor=9;
 if(initialClass===4||initialClass===5)heelDivisor=11;
 if(flag(0x5363bc))heelDivisor=16;
 if(initialClass===8)heelDivisor=14;
 if(flag(0x5363b8))heelDivisor=18;
 if(flag(0x5364cc)||flag(0x5363c0))heelDivisor=14;
 if(flag(0x5364bc))heelDivisor=10;
 if(flag(0x53652c))heelDivisor=11;
 if(flag(0x536530))heelDivisor=12;
 let heelCorrection=idiv32(imul32(sub32(9,initialClass),5),2);
 if(initialClass===3)heelCorrection=22;
 if(initialClass===7)heelCorrection=0;
 if(rb(0x4fecc8)>160&&rb(0x4fb380)>10&&r(0x5363b8)===0)heelCorrection=add32(heelCorrection,imul32(r(0x4f8ccc),-3));
 let angle=abs(sub32(rb(0x535740),rb(0x522b90)));
 wb(0x4fecc8,angle>180?sub32(360,angle):angle);
 updateInterference(memory,boat,rng,options);
 w(0x5350dc,flag(0x4f4520)?1:0);
 if(flag(0x4f4524))w(0x5350e0,1);else if(r(0x4da140)===2)w(0x5350e0,0);
 angle=rb(0x4fecc8);
 const boatClass=()=>r(0x4da190),wind=()=>rb(0x4fb380),human=()=>boat<=r(0x4da140);
 let coefficient=boat;
 let lever;
 const subtractLever=address=>{lever=spill(lever.subtract(f(address)));};
 if(r(0x5363b8)===0){
  coefficient=idiv32(imul32(sub32(angle,40),90),140);
  lever=spill(integer(coefficient).subtract(f(0x4cca40)));
  if(boatClass()<6)subtractLever(0x4cc660);
  if(flag(0x5363bc)){if(wind()>9)subtractLever(0x4cc660);if(wind()<10)subtractLever(0x4cc600);}
  if(boatClass()===1&&r(0x5363bc)===0)subtractLever(0x4cc660);
  if(boatClass()===2)subtractLever(wind()<12?0x4cc8b0:0x4cc570);
  if(boatClass()===3)subtractLever(0x4cc570);
  if(flag(0x5363c4))subtractLever(0x4cc668);
  if(boatClass()===5&&wind()<12)subtractLever(0x4cc5d8);
  if(boatClass()===6){if(wind()<12)subtractLever(0x4cc5d8);if(wind()>11)subtractLever(0x4cca48);}
  if(boatClass()===7&&r(0x5363c0)===0)subtractLever(wind()>12?0x4cc5e8:0x4cc690);
  if(boatClass()===8){if(wind()<12)subtractLever(0x4cc5e8);if(wind()>11)subtractLever(0x4cc5d8);}
  if(flag(0x5363c0)){if(wind()>13)subtractLever(0x4cc5c8);if(wind()<14)subtractLever(0x4cc690);}
 }
 if(flag(0x5363b8)){
  coefficient=angle;
  lever=spill(integer(angle).subtract(f(0x4cca50)).multiply(f(0x4cca58)).subtract(f(0x4cca60)).subtract(f(wind()<12?0x4cca68:0x4cca48)));
  if(flag(0x5364c0)&&angle<90)subtractLever(0x4cc7a8);
  if(boatClass()===9)subtractLever(0x4cc798);
 }
 if(!lever)throw new RangeError('Original2010 dynamics has an undefined lever for a nonboolean catamaran flag');
 if(!human()||rb(0x500380)===-1)wb(0x4fe818,lever.truncI32());
 else wb(0x4fe818,Math.max(5,sub32(idiv32(imul32(sub32(angle,40),90),140),3)));
 let trim;
 if(!human()||r(0x5364c8)!==0){trim=angle>59?30:20;if(angle<90&&wind()>13)trim=10;}
 else trim=imul32(rb(0x4fe778),10);
 const pressure=apparentWindExtended(memory,rb(0x4fdfe8),boat,options);
 let sailCoefficient=add32(trim,120);
 if(boatClass()>6&&boatClass()<9&&human()&&r(0x5364c8)===0&&rb(0x5350d8)<1)sailCoefficient=add32(add32(sailCoefficient,imul32(rb(0x4f7ee0),-25)),25);
 const scaledCoefficient=(shift,denominator)=>sub32(idiv32(imul32(add32(sailCoefficient,shift),angle),denominator),shift);
 if(boatClass()>5&&boatClass()<9){
  coefficient=angle<61?scaledCoefficient(boatClass()===6||boatClass()===7?150:95,60):sub32(sailCoefficient,idiv32(sub32(angle,60),5));
 }
 if(boatClass()<6&&r(0x5363c4)===0&&r(0x5363bc)===0&&r(0x53652c)===0)coefficient=angle<=add32(r(0x4f7200),7)?scaledCoefficient(150,add32(r(0x4f7200),7)):sailCoefficient;
 if(flag(0x5363c4)||flag(0x53652c))coefficient=angle<=add32(r(0x4f7200),12)?scaledCoefficient(150,add32(r(0x4f7200),12)):sailCoefficient;
 if(flag(0x5363b8))coefficient=angle<=add32(r(0x4f7200),18)?scaledCoefficient(150,add32(r(0x4f7200),18)):sailCoefficient;
 if(flag(0x5363bc)){
  if(wind()<10){sailCoefficient=idiv32(imul32(sailCoefficient,8),11);if(angle<=add32(r(0x4f7200),30))sailCoefficient=scaledCoefficient(80,add32(r(0x4f7200),30));}
  else if(angle<=add32(r(0x4f7200),25))sailCoefficient=scaledCoefficient(140,add32(r(0x4f7200),25));
  coefficient=angle>=sub32(182,rb(0x4fae60))?idiv32(sailCoefficient,2):sailCoefficient;
 }
 if(coefficient<10&&angle>sub32(r(0x4f7200),10))coefficient=10;
 let spinPower=0;
 if(rb(0x5350d8)>0){
  const small=boatClass()===2||flag(0x5364c8)||flag(0x5364c4);spinPower=small?75:150;
  if(human()){
   updateSpinnakerDrag(memory,boat);
   spinPower=small?sub32(75,imul32(rb(0x535f68),2)):add32(imul32(sub32(50,rb(0x535f68)),3),imul32(rb(0x4fbab0),-100));
  }
 }
 if(angle<sub32(r(0x4f7200),10))coefficient=3;
 if(human()&&rb(0x500380)>=0){
  const setting=rb(0x500380),max=angle<91||r(0x5363bc)!==0?100:imul32(sub32(140,angle),2);
  wb(0x512278,Math.max(0,Math.min(setting,max)));
  if(flag(0x5363bc)&&setting>80){wb(0x512278,90);coefficient=3;}
  else coefficient=idiv32(imul32(sub32(100,rb(0x512278)),coefficient),100);
 }
 if(rb(0x5350d8)>0&&boatClass()>1&&r(0x5364cc)===0&&boatClass()!==9)coefficient=add32(coefficient,spinPower);
 if(coefficient<1)coefficient=1;
 let heelCos=cos(oldHeel<1?0:wrapDegreesOnce(abs(oldHeel)));
 let power=spill(integer(coefficient).multiply(spill(pressure)).multiply(f(0x4cca70)));
 if(flag(0x53652c)&&rb(0x4fc2c0)<10)power=spill(power.multiply(f(0x4cc7b8)));
 if(human())heelCos=continuous(cos(wrapDegreesOnce(rb(0x4fe818))).multiply(power).divide(integer(heelDivisor)).multiply(f(0x4cc568))).cosine;
 //43acb6–43acd1 squares cosine before multiplying power, then sail area.
 power=spill(heelCos.multiply(heelCos).multiply(power).multiply(integer(r(0x4f8d70))));
 if(rb(0x4fe8a8)>1)power=spill(power.multiply(f(0x4cc4f8)));
 let heel=sub32(cos(wrapDegreesOnce(rb(0x4fe818))).multiply(power).divide(integer(heelDivisor)).truncI32(),heelCorrection);
 if(heel<0&&angle<161)heel=0;
 if(angle<60&&heel<5)heel=5;
 if(heel>70)heel=70;
 if(!human()||rb(0x500380)<0){
  wb(0x512278,0);
  if(r(0x4f4200)<heel){const ratio=idiv32(imul32(r(0x4f4200),100),heel);heel=sub32(r(0x4f4200),1);wb(0x512278,idiv32(sub32(100,ratio),2));}
 }
 if(flag(0x53652c)&&integer(heel).compare(f(0x4cc828))<0)heel=11;
 let forceAngle=angle<61?add32(idiv32(imul32(angle,10),60),sub32(imul32(sub32(5,rb(0x535e40)),2),idiv32(rb(0x512278),(boatClass()===7||boatClass()===8)&&r(0x5364c8)===0?6:3))):sub32(22,idiv32(sub32(angle,60),6));
 if(angle>60&&angle<=sub32(180,rb(0x4fae60))&&(flag(0x5363b8)||flag(0x5363bc)))forceAngle=22;
 if(trim>20&&angle<60)forceAngle=add32(forceAngle,idiv32(sub32(20,trim),3));
 if(rb(0x5350d8)<1){if(human()&&boatClass()>6&&boatClass()<9)forceAngle=add32(forceAngle,imul32(sub32(rb(0x4f7ee0),2),5));}
 else forceAngle=sub32(forceAngle,8);
 if(rb(0x4fe8a8)>1&&rb(0x4fdfe8)>20)forceAngle=sub32(forceAngle,human()?4:6);
 if(forceAngle<0)forceAngle=0;
 forceAngle=add32(forceAngle,12);
 if(trim>29&&angle<60)forceAngle=sub32(forceAngle,6);
 if(trim===20&&angle<60&&wind()>13)forceAngle=sub32(forceAngle,4);
 let force=continuous(integer(forceAngle).add(lever).multiply(f(0x4cc568))).sine.multiply(power).multiply(f(0x4cc580));
 if(human()&&rb(0x512278)>80&&angle<35)force=f(0x4cc650);
 if(boatClass()===7||boatClass()===8)force=f(0x4cc488).subtract(integer(rb(0x512278))).multiply(force).multiply(f(0x4cc3f0));
 let windDrag=integer(idiv32(imul32(sub32(90,r(0x4feccc)),wind()),15));
 if(boatClass()>5&&boatClass()<9)windDrag=spill(windDrag.multiply(f(0x4cc4f8)));
 const hull=integer(r(0x4faa48)).sqrt().multiply(f(0x4cc580)),storedHull=spill(hull);
 const drive=spill(force.subtract(windDrag)),displacement=integer(r(0x4f7ecc));
 let ratio=hull.multiply(f(0x4cc838)).divide(displacement);
 if((flag(0x5364c0)||flag(0x5363c4))&&angle>90)ratio=hull.multiply(f(0x4cc5a8)).divide(displacement);
 if(flag(0x53652c)&&angle>90)ratio=hull.multiply(f(0x4cca38)).divide(displacement);
 if((flag(0x5364d0)||flag(0x536530))&&angle>90)ratio=hull.multiply(f(0x4cca38)).divide(displacement);
 if(r(0x5364c0)===0&&flag(0x5363b8)&&angle>90)ratio=hull.multiply(f(0x4cca38)).divide(displacement);
 const root=drive.compare(f(0x4cc658))>0?spill(drive.sqrt()):Float80.fromNumber(0);
 let resistance=root.compare(f(0x4cca78))>0?
  hull.subtract(ratio.subtract(hull).multiply(root.subtract(f(0x4cca78)).sqrt()).multiply(f(0x4cca90))):
  hull.multiply(f(0x4cc7b0)).subtract(hull.multiply(root).multiply(f(0x4cca80)).multiply(f(0x4cca88)));
 if(root.compare(f(0x4cc7a0))<0)resistance=root.multiply(root).multiply(f(0x4cc3f0));
 resistance=integer(rb(0x4fc3e0)).multiply(resistance).multiply(f(0x4cc3f0));
 let multiplier=displacement;
 if(!human()&&abs(sub32(angle,r(0x4feccc)))<30){
  multiplier=spill(f(0x4fe188).multiply(f(0x4cca98)));
  if(resistance.compare(multiplier)>0&&storedHull.multiply(f(0x4cc630)).compare(f(0x4fe188))<0&&r(0x4fe8ac)===0&&r(0x5116e4)===0)resistance=multiplier;
 }
 if(boat===1)w(0x522fdc,f(0x4fe188).multiply(f(0x4cc488)).truncI32());
 if(!human()){
  if(angle<=r(0x4f7200)){
   multiplier=f(0x4ccaa0);
   if(flag(0x5364c4))multiplier=f(0x4cc7b8);
   if(flag(0x5364d8))multiplier=f(0x4cc940);
   if(flag(0x5364d4))multiplier=f(0x4ccaa8);
   if(flag(0x53652c))multiplier=f(0x4ccab0);
   if(flag(0x536528))multiplier=f(r(0x522ad0)<11?0x4cc930:0x4ccaa0);
   if(flag(0x536530)||boatClass()===8)multiplier=f(0x4ccab8);
   if(boatClass()===6)multiplier=f(0x4ccac0);
  }
  if(angle>r(0x4f7200)&&angle<=add32(r(0x4f7200),5))multiplier=f(boatClass()===6?0x4ccaa0:0x4cc650);
  const special=boatClass()===6||flag(0x5363c0)||flag(0x5364d4)||flag(0x5364d8);
  if(angle>add32(r(0x4f7200),5)&&angle<90)multiplier=f(special?0x4ccaa0:0x4cc650);
  if(angle>=90){
   multiplier=f(special?0x4ccaa0:0x4cc650);
   if(flag(0x536528))multiplier=f(0x4cc650);
   if(flag(0x53652c))multiplier=f(0x4cc940);
   if(flag(0x536530))multiplier=f(0x4ccac8);
  }
  if(angle>=sub32(178,rb(0x4fae60))){
   multiplier=f(boatClass()===6||flag(0x5364d8)||flag(0x5364c8)?0x4ccab8:0x4cc650);
   if(flag(0x5363c0)||flag(0x5364d4)||flag(0x5364c0)||flag(0x5364cc))multiplier=f(0x4ccaa0);
   if(boatClass()===8)multiplier=f(0x4ccac0);
   if(flag(0x536528))multiplier=f(0x4cc650);
   if(flag(0x53652c))multiplier=f(0x4cc940);
   if(flag(0x536530))multiplier=f(0x4ccac8);
  }
  if(boatClass()>=1&&boatClass()<=5)multiplier=f(0x4ccad0);
  if(flag(0x536530))multiplier=spill(multiplier.multiply(f(0x4ccab8)));
 }else multiplier=f(flag(0x536534)?0x4cc930:0x4cc650);
 let targetSpeed=spill(multiplier.multiply(resistance));
 if(human()&&rb(0x500380)>=0){
  let drag=0;
  if(add32(r(0x4f4200),2)<heel){drag=add32(sub32(heel,r(0x4f4200)),2);drag=imul32(drag,drag);}
  if(add32(boatClass(),30)<drag)drag=add32(boatClass(),30);
  if(flag(0x5364c8))drag=idiv32(drag,2);
  targetSpeed=spill(targetSpeed.subtract(integer(drag)));
 }
 updateMarkStartPenalties(memory,boat,rng,options);
 const divisor=flag(0x5363bc)?integer(r(0x4f7ecc)):integer(r(0x4f7ecc)).multiply(f(0x4cc4f8));
 const difference=spill(targetSpeed.subtract(fb(0x4fe180)));
 wf(0x4fe180,difference.multiply(f(0x523378)).divide(divisor).add(fb(0x4fe180)));
 if(r(0x4f8cd0)===rb(0x535620))wf(0x4fe180,integer(0));
 if(fb(0x4fe180).compare(f(0x4ccad8))>0)wf(0x4fe180,integer(250));
 if(fb(0x4fe180).compare(f(0x4cc588))<0)wf(0x4fe180,integer(-10));
 wb(0x4fdfe8,fb(0x4fe180).truncI32());wb(0x4fc2c0,idiv32(add32(oldHeel,heel),2));
 if(!human()&&f(0x5359f0).compare(f(0x4cc658))<0){
  const percent=prestartSpeedPercent(memory,boat,rng);const speed=idiv32(imul32(percent,rb(0x4fdfe8)),100);wb(0x4fdfe8,speed);
  if(speed<25)wb(0x512278,40);
  if(rb(0x512278)>30)wb(0x4fc2c0,7);
  if(add32(oldSpeed,6)<speed)wb(0x4fdfe8,add32(oldSpeed,6));
 }
 if(fb(0x4ffcb8).compare(integer(r(0x4da1fc)))<0){
  if(human()){w(0x4fdfec,1);wb(0x5116e0,10);}else wb(0x4fdfe8,1);
 }
 w(0x4fb21c,r(0x4fc2c4)>add32(r(0x4f4200),1)&&r(0x500384)>=0?1:0);
 if(!human()&&rb(0x4faef0)>=0)wb(0x4fdfe8,idiv32(rb(0x4faef0),2));
 wb(0x4faef0,-1);
 let recoverDuration=boatClass()<7?5:8;
 if(boatClass()<3)recoverDuration=3;
 if(flag(0x5363b8)||flag(0x5363c4))recoverDuration=8;
 if(flag(0x5363bc))recoverDuration=10;
 let hullInt=storedHull.truncI32();const lastTurn=rb(0x4f4350);
 if(r(0x4f8cd0)===lastTurn)wb(0x535ed8,oldSpeed);
 const fastRecovery=boatClass()===1&&r(0x5363bc)===0&&r(0x5363cc)===0||boatClass()===2;
 if(rb(0x4fecc8)<add32(r(0x4f7200),5)){
  const half=add32(idiv32(recoverDuration,2),lastTurn);
  if(add32(lastTurn,1)<r(0x4f8cd0)&&r(0x4f8cd0)<=half){
   if(flag(0x5363bc)||oldSpeed<5)hullInt=15;
   if(rb(0x535ed8)<hullInt)hullInt=rb(0x535ed8);
   wb(0x4fdfe8,fastRecovery?idiv32(imul32(hullInt,4),5):idiv32(imul32(hullInt,3),4));
   wf(0x4fe180,integer(rb(0x4fdfe8)));
  }
  if(half<r(0x4f8cd0)&&r(0x4f8cd0)<=add32(recoverDuration,lastTurn)){
   if(flag(0x5363bc)||oldSpeed<5)hullInt=25;
   if(rb(0x535ed8)<hullInt)hullInt=rb(0x535ed8);
   wb(0x4fdfe8,fastRecovery?idiv32(imul32(hullInt,6),7):idiv32(imul32(hullInt,5),6));
   wf(0x4fe180,integer(rb(0x4fdfe8)));
  }
  if(add32(recoverDuration,lastTurn)<r(0x4f8cd0))wb(0x4f4a70,0);
 }
 if(flag(0x5363bc)&&rb(0x523938)===1){
  if(rb(0x4fdfe8)>29)wb(0x4fdfe8,30);
  if(add32(lastTurn,6)<r(0x4f8cd0))wb(0x523938,0);
 }
 if(boat===1)w(0x4fe178,cos(r(0x4feccc)).multiply(f(0x4fe188)).multiply(f(0x4cc580)).truncI32());
 if(rb(0x4fe638)>0&&distanceToBoat(memory,boat,rb(0x4fb548),rb(0x522af0)).compare(f(0x4ccae0))<0){
  wf(0x4fe180,integer(0));wb(0x4fdfe8,0);wb(0x4fc2c0,5);
  //43b9eb stores the per-boat heading, then43b9fa overwrites it with global wind−45.
  wb(0x535740,sub32(rb(0x522b90),r(0x4f7200)));
  wb(0x535740,wrapDegreesOnce(sub32(r(0x5362d4),45)));
  for(const address of[0x511620,0x4f6a68,0x5350d8])wb(address,0);
  wb(0x522ff0,1);wb(0x512278,30);
  if(boat===1)memory.writeF64(0x4fe938,r(0x535744));
 }
 const ground=(smooth,speed)=>{wf(0x4fe180,integer(smooth));wb(0x4fdfe8,speed);wb(0x5116e0,10);};
 if(r(0x5363b8)===0){
  const halfClass=idiv32(boatClass(),2);
  if(fb(0x4ffcb8).compare(integer(add32(halfClass,3)))<0)ground(5,5);
  if(fb(0x4ffcb8).compare(integer(add32(halfClass,1)))<0)ground(5,1);
 }
 if(flag(0x5363b8)){
  if(fb(0x4ffcb8).compare(f(0x4cc728))<0)ground(5,5);
  if(fb(0x4ffcb8).compare(f(0x4cc710))<0)ground(1,1);
 }
}
