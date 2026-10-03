import { Float80 } from '../../../../src/runtime/float80.js';
import { i32 } from '../../../../src/runtime/c-types.js';

export const BOAT_OPTION_ADDRESSES = Object.freeze({
  routine:0x420c00, selector:0x4da144, boatClass:0x4da190,
  lengthOverride:0x5363d0, displacementOverride:0x5363d4,
  sailAreaOverride:0x5363d8, sailPercentOverride:0x5363dc,
  length:0x4faa48, displacement:0x4f7ecc, sailArea:0x4f8d70,
  sailPercent:0x4da150, rig:0x4da14c, course:0x4da19c,
  offshoreCourseFlag:0x536454, timeFactor:0x523d48,
  timeFactorNumerator:0x4cc838,
  jy15Flag:0x5363c8, catamaranFlag:0x5363b8, boardFlag:0x5363bc,
  spritOrSportBoatVariant:0x5363c0, skiffFlag:0x5363c4,
  optimistFlag:0x5363cc, ideal18Flag:0x4fb410,
  starFlag:0x5364bc, aClassCatamaranFlag:0x5364cc,
  offshoreRacerFlag:0x5364d4, racerCruiserFlag:0x5364d8,
  cruisingCanvasFlag:0x5364c4, modelYachtFlag:0x5364c8,
  tornadoFlag:0x5364c0, laserFlag:0x5364d0,
  offshoreCatamaranFlag:0x513478, etchellsFlag:0x536528,
  eScowFlag:0x53652c, flyingScotFlag:0x536530,
  boatFeatureFlag53573c:0x53573c,
  boatFeatureFlag4f6d28:0x4f6d28,
  boatFeatureFlag4f4294:0x4f4294,
});

/** Menu labels linked to original WM_COMMAND records and selector stores. */
export const BOAT_SELECTORS = Object.freeze({
  1:'Optimist',2:'Laser',3:'Board',4:'Snipe',5:'JY15',6:'505',7:'Skiff',
  8:'Thistle',9:'Lightning',10:'Non-Spinnaker Catamaran',11:'Tornado Catamaran',
  12:'Keelboat',13:'Sprit Offshore Racer',14:'Offshore Racer',15:"America's Cup",
  16:'Star',17:'A Class Catamaran',18:'Racer Cruiser',19:'Cruising Canvas',
  20:'Model Yacht',21:'25 ft Sportboat',22:'35 ft Sportboat',23:'Offshore Catamaran',
  24:'Ideal 18 Keelboat',25:'Etchells Keelboat',26:'E Scow',27:'Flying Scot',
});

const resetFlags=[
  'jy15Flag','catamaranFlag','boardFlag','spritOrSportBoatVariant','skiffFlag',
  'optimistFlag','ideal18Flag','starFlag','aClassCatamaranFlag','offshoreRacerFlag',
  'racerCruiserFlag','cruisingCanvasFlag','modelYachtFlag','tornadoFlag','laserFlag',
  'offshoreCatamaranFlag','etchellsFlag','eScowFlag','flyingScotFlag',
];

/**
 * Complete original 0x420c00. The caller's x87 control word governs arithmetic;
 * production startup uses precision53. No captured-output or class fallback is
 * substituted. Invalid selectors keep the prior class after all subtype resets.
 * Positive retained lengths are supported; masked nonfinite x87 results from
 * nonpositive invalid-state lengths are outside the finite runtime contract.
 * Returns residual EAX for comparison; original callers use the memory writes.
 */
export function initializeBoatOptions(memory) {
  const a=BOAT_OPTION_ADDRESSES;
  const read=field=>memory.readI32(a[field]);
  const write=(field,value)=>memory.writeI32(a[field],i32(value));
  const selector=read('selector');
  let variant=0,catamaran=false,tornado=false,modelYacht=false,eScow=false;
  for(const field of resetFlags)write(field,0);
  switch(selector){
    case 1:write('boatClass',1);write('optimistFlag',1);break;
    case 2:write('boatClass',1);write('laserFlag',1);break;
    case 3:write('boatClass',1);write('boardFlag',1);break;
    case 4:write('boatClass',2);break;
    case 5:write('jy15Flag',1);write('boatClass',2);break;
    case 6:write('boatClass',3);break;
    case 7:write('skiffFlag',1);write('boatClass',3);break;
    case 8:write('boatClass',4);write('eScowFlag',0);break;
    case 9:write('boatClass',5);break;
    case 10:catamaran=true;write('boatClass',9);write('catamaranFlag',1);break;
    case 11:catamaran=true;tornado=true;write('boatClass',10);write('catamaranFlag',1);write('tornadoFlag',1);break;
    case 12:write('boatClass',6);break;
    case 13:variant=1;write('boatClass',7);write('spritOrSportBoatVariant',1);break;
    case 14:write('offshoreRacerFlag',1);write('boatClass',7);break;
    case 15:write('rig',1);write('boatClass',8);break;
    case 16:write('starFlag',1);write('boatClass',2);break;
    case 17:catamaran=true;write('boatClass',9);write('aClassCatamaranFlag',1);write('catamaranFlag',1);break;
    case 18:write('racerCruiserFlag',1);write('boatClass',7);break;
    case 19:write('cruisingCanvasFlag',1);write('boatClass',7);break;
    case 20:modelYacht=true;write('boatClass',7);write('modelYachtFlag',1);break;
    case 21:variant=2;write('boatClass',6);write('spritOrSportBoatVariant',2);write('rig',-1);break;
    case 22:variant=3;write('boatClass',6);write('spritOrSportBoatVariant',3);break;
    case 23:catamaran=true;write('boatClass',10);write('catamaranFlag',1);write('spritOrSportBoatVariant',0);write('rig',1);write('offshoreCatamaranFlag',1);break;
    case 24:write('ideal18Flag',1);write('boatClass',6);break;
    case 25:write('etchellsFlag',1);write('boatClass',6);break;
    case 26:eScow=true;write('boatClass',5);write('eScowFlag',1);break;
    case 27:write('flyingScotFlag',1);write('boatClass',5);break;
  }
  const boatClass=read('boatClass');
  if(boatClass===1||read('jy15Flag')===1||boatClass===3||read('skiffFlag')===1
    ||boatClass===2||tornado||modelYacht||read('ideal18Flag')===1){
    write('boatFeatureFlag53573c',0);
  }else{
    write('boatFeatureFlag53573c',1);
    if(read('flyingScotFlag')===1)write('boatFeatureFlag53573c',0);
  }
  if(read('starFlag')===1||eScow)write('boatFeatureFlag53573c',1);
  if(read('boardFlag')===1||catamaran)write('boatFeatureFlag4f6d28',0);
  else{write('boatFeatureFlag4f6d28',1);if(modelYacht)write('boatFeatureFlag4f6d28',0);}
  if(boatClass===1||boatClass===4||read('jy15Flag')===1||catamaran
    ||read('skiffFlag')===1||modelYacht||read('ideal18Flag')===0){
    write('boatFeatureFlag4f4294',0);
  }else{
    write('boatFeatureFlag4f4294',1);
    if(read('flyingScotFlag')===0)write('boatFeatureFlag4f4294',0);
  }
  const displacement=read('displacementOverride');
  const defaultDisplacement=variant!==1?10:9;
  if(displacement<8)write('displacement',defaultDisplacement);
  else{write('displacement',displacement);if(displacement>11)write('displacement',defaultDisplacement);}
  const area=read('sailAreaOverride');
  write('sailArea',area>=8&&area<=11?area:10);
  if(boatClass===7&&variant===0){
    write('sailPercent',100);if(read('etchellsFlag')!==0)write('sailPercent',80);
  }else write('sailPercent',80);
  const percent=read('sailPercentOverride');if(percent>0)write('sailPercent',percent);
  if(boatClass<6){write('sailPercent',80);write('displacement',10);write('sailArea',10);}
  if(read('laserFlag')===1){write('displacement',5);write('length',8);}
  if(boatClass===1&&read('boardFlag')===1){write('displacement',6);write('length',40);write('sailArea',10);}
  if(boatClass===1&&read('optimistFlag')===1){write('displacement',10);write('length',9);write('sailArea',10);}
  if(boatClass===2){
    write('length',8);write('displacement',read('jy15Flag')!==1?6:5);
    if(read('starFlag')===1){write('length',19);write('displacement',9);write('sailArea',12);}
  }
  if(boatClass===3){
    write('displacement',5);
    if(read('skiffFlag')===0){write('length',16);write('sailArea',10);}
    else{write('displacement',6);write('length',24);write('sailArea',11);}
  }
  if(boatClass===4){write('displacement',6);write('length',10);}
  if(boatClass===5){write('displacement',7);write('length',11);}
  const length=read('lengthOverride');
  if(boatClass===6&&variant===0&&read('etchellsFlag')===0){
    if(length<20)write('length',25);
    else{write('length',length);if(length>50)write('length',25);}
  }
  if(boatClass===7&&read('etchellsFlag')===0)write('length',length>=20&&length<=50?length:40);
  if((boatClass<7&&variant!==3)||boatClass>8)write('rig',-1);
  if(boatClass===8){write('displacement',10);write('length',90);write('sailArea',12);write('sailPercent',80);write('rig',1);}
  if(boatClass===9){write('displacement',7);write('length',30);write('sailArea',14);write('sailPercent',80);}
  if(boatClass===10){write('displacement',7);write('length',36);write('sailArea',14);write('sailPercent',80);}
  if(read('aClassCatamaranFlag')===1){write('displacement',7);write('length',28);write('sailArea',12);write('sailPercent',80);}
  if(read('modelYachtFlag')===1){write('length',14);write('displacement',10);write('sailArea',10);write('sailPercent',80);}
  if(variant===2||variant===3){write('sailArea',11);write('length',variant===2?16:21);write('displacement',6);}
  if(read('offshoreCatamaranFlag')===1){write('displacement',6);write('length',30);write('sailArea',11);write('sailPercent',80);write('rig',1);}
  if(read('ideal18Flag')===1){write('displacement',9);write('length',18);write('sailArea',12);write('sailPercent',80);}
  if(read('etchellsFlag')===1){write('displacement',8);write('length',22);write('sailArea',10);write('sailPercent',80);}
  if(read('eScowFlag')===1){write('displacement',5);write('length',27);write('sailArea',8);write('sailPercent',80);}
  if(read('flyingScotFlag')===1){write('sailPercent',80);write('length',10);write('displacement',6);write('sailArea',10);}
  memory.writeF64(a.timeFactor,Float80.fromNumber(memory.readF64(a.timeFactorNumerator))
    .divide(Float80.fromInteger(read('length'))).sqrt().toNumber());
  let returnValue=boatClass;
  if(boatClass!==7){
    returnValue=read('offshoreCatamaranFlag');
    if(returnValue===0){returnValue=read('course');write('offshoreCourseFlag',0);if(returnValue===8)write('course',1);}
  }
  return returnValue;
}
