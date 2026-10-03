import { i32 } from '../../../../src/runtime/c-types.js';
import { Float80 } from '../../../../src/runtime/float80.js';
import { wrapDegreesOnce, updateSpeedDivisor, scaledRandom } from './application.js';
import { controllerMemory, cI32, cFloat, cAdd, cSub, cMul, cDiv, cRem, cNeg, cBits, cCompare, cTruth } from './controller-values.js';

function originalKeyDown(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const param_2=i32(options.key),param_3=i32(options.repeat ?? 1),param_4=i32(options.flags ?? 0);
  let iVar1,iVar2,iVar3,iVar4,iVar5,bVar6,hWnd;
  w32(0x4faf94,param_2);
  if (cTruth((cTruth(cCompare(param_2,90,"==")) && cTruth(cCompare(r32(0x5363b0),0,"=="))))) {
    w32(0x536534,cAdd(r32(0x536534),1));
    if (cTruth(cCompare(1,r32(0x536534),"<"))) {
      w32(0x536534,0);
    }
    invalidate(0);
  }
  if (cTruth(cCompare(r32(0x4faf94),32,"=="))) {
    if (cTruth(cCompare(r32(0x5364fc),1,"=="))) {
      w32(0x5364fc,0);
      w32(0x4faf94,cNeg(1));
      w32(0x5363b4,0);
      invalidate(0);
    }
    if (cTruth((cTruth((cTruth((cTruth(cCompare(r32(0x4faf94),32,"==")) && cTruth(cCompare(r32(0x5363b0),0,"==")))) && cTruth(cCompare(0,r32(0x4da16c),"<")))) && cTruth(cCompare(r32(0x53648c),0,"=="))))) {
      w32(0x53648c,1);
      w32(0x4faf94,cNeg(1));
      w32(0x5363b4,0);
      invalidate(0);
    }
  }
  if (cTruth(cCompare(r32(0x4faf94),27,"=="))) {
    w32(0x536420,0);
  }
  if (cTruth((cTruth(cCompare(r32(0x4faf94),67,"==")) && cTruth(cCompare(r32(0x5363b0),0,"=="))))) {
    w32(0x5364fc,cAdd(r32(0x5364fc),1));
    if (cTruth(cCompare(1,r32(0x5364fc),"<"))) {
      w32(0x5364fc,0);
    }
    w32(0x4da1f8,999);
    w32(0x4da200,1);
    w32(0x5363b4,0);
    invalidate(0);
    w32(0x4faf94,cNeg(1));
  }
  if (cTruth((cTruth(cCompare(r32(0x4faf94),80,"==")) && cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) || cTruth((cTruth(cCompare(r32(0x4f8cd0),r32(0x4f42b8),"==")) && cTruth(cCompare(r32(0x4da1d8),3,"<"))))))))) {
    w32(0x4da1d8,2);
    w32(0x4faf94,cNeg(1));
    invalidate(0);
  }
  if (cTruth((cTruth(cCompare(r32(0x4faf94),66,"==")) && cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) || cTruth((cTruth(cCompare(r32(0x4f8cd0),r32(0x4f42b8),"==")) && cTruth(cCompare(r32(0x4da1d8),3,"<"))))))))) {
    w32(0x4da1d8,1);
    w32(0x4faf94,cNeg(1));
    invalidate(0);
  }
  if (cTruth((cTruth(cCompare(r32(0x4faf94),52,"==")) && cTruth(cCompare(r32(0x5363b0),0,"=="))))) {
    w32(0x4da198,4);
    w32(0x4faf94,cNeg(1));
    w32(0x5363b4,0);
    invalidate(0);
  }
  if (cTruth((cTruth(cCompare(r32(0x4faf94),53,"==")) && cTruth(cCompare(r32(0x5363b0),0,"=="))))) {
    w32(0x4da198,5);
    w32(0x4faf94,cNeg(1));
    w32(0x5363b4,0);
    invalidate(0);
  }
  if (cTruth((cTruth(cCompare(r32(0x4faf94),54,"==")) && cTruth(cCompare(r32(0x5363b0),0,"=="))))) {
    w32(0x4da198,6);
    w32(0x4faf94,cNeg(1));
    w32(0x5363b4,0);
    invalidate(0);
  }
  if (cTruth((cTruth(cCompare(r32(0x4faf94),55,"==")) && cTruth(cCompare(r32(0x5363b0),0,"=="))))) {
    w32(0x4da198,7);
    w32(0x4faf94,cNeg(1));
    w32(0x5363b4,0);
    invalidate(0);
  }
  if (cTruth((cTruth(cCompare(r32(0x4faf94),56,"==")) && cTruth(cCompare(r32(0x5363b0),0,"=="))))) {
    w32(0x4da198,8);
    w32(0x4faf94,cNeg(1));
    w32(0x5363b4,0);
    invalidate(0);
  }
  if (cTruth((cTruth(cCompare(r32(0x4faf94),57,"==")) && cTruth(cCompare(r32(0x5363b0),0,"=="))))) {
    w32(0x4da198,9);
    w32(0x4faf94,cNeg(1));
    w32(0x5363b4,0);
    invalidate(0);
  }
  if (cTruth((cTruth(cCompare(r32(0x4faf94),48,"==")) && cTruth(cCompare(r32(0x5363b0),0,"=="))))) {
    w32(0x4da198,10);
    w32(0x4faf94,cNeg(1));
    w32(0x5363b4,0);
    invalidate(0);
  }
  if (cTruth((cTruth(cCompare(r32(0x4faf94),49,"==")) && cTruth(cCompare(r32(0x5363b0),0,"=="))))) {
    w32(0x4da198,11);
    w32(0x4faf94,cNeg(1));
    w32(0x5363b4,0);
    invalidate(0);
  }
  if (cTruth((cTruth(cCompare(r32(0x4faf94),50,"==")) && cTruth(cCompare(r32(0x5363b0),0,"=="))))) {
    w32(0x4da198,12);
    w32(0x4faf94,cNeg(1));
    w32(0x5363b4,0);
    invalidate(0);
  }
  if (cTruth((cTruth(cCompare(r32(0x4faf94),51,"==")) && cTruth(cCompare(r32(0x5363b0),0,"=="))))) {
    w32(0x4da198,13);
    w32(0x4faf94,cNeg(1));
    w32(0x5363b4,0);
    invalidate(0);
  }
  if (cTruth((cTruth(cCompare(r32(0x4faf94),77,"==")) && cTruth(cCompare(r32(0x5363b0),0,"=="))))) {
    w32(0x4da154,2);
    w32(0x4faf94,cNeg(1));
    w32(0x5363b4,0);
    invalidate(0);
  }
  if (cTruth((cTruth(cCompare(r32(0x4faf94),76,"==")) && cTruth(cCompare(r32(0x5363b0),0,"=="))))) {
    w32(0x4da154,1);
    w32(0x4faf94,cNeg(1));
    w32(0x5363b4,0);
    invalidate(0);
  }
  if (cTruth((cTruth(cCompare(r32(0x4faf94),83,"==")) && cTruth(cCompare(r32(0x5363b0),0,"=="))))) {
    w32(0x4da154,3);
    w32(0x4faf94,cNeg(1));
    w32(0x5363b4,0);
    invalidate(0);
  }
  if (cTruth((cTruth(cCompare(r32(0x4faf94),32,"==")) && cTruth(cCompare(r32(0x5363b0),0,"=="))))) {
    w32(0x5363b0,1);
    w32(0x5363b4,0);
    invalidate(0);
    w32(0x4faf94,cNeg(1));
  }
  if (cTruth(cCompare(r32(0x4faf94),220,"=="))) {
    w32(0x4da1dc,cAdd(r32(0x4da1dc),1));
    if (cTruth(cCompare(1,r32(0x4da1dc),"<"))) {
      w32(0x4da1dc,0);
    }
    w32(0x4faf94,cNeg(1));
  }
  if (cTruth(cCompare(r32(0x4faf94),20,"=="))) {
    w32(0x5364b0,cAdd(r32(0x5364b0),1));
    if (cTruth(cCompare(1,r32(0x5364b0),"<"))) {
      w32(0x5364b0,0);
    }
    w32(0x4faf94,cNeg(1));
  }
  if (cTruth(cCompare(r32(0x4faf94),8,"=="))) {
    w32(0x5364ac,cAdd(r32(0x5364ac),1));
  }
  if (cTruth(cCompare(1,r32(0x5364ac),"<"))) {
    w32(0x5364ac,0);
  }
  if (cTruth(cCompare(r32(0x4faf94),33,"=="))) {
    if (cTruth(cCompare(r32(0x4da174),15,"<"))) {
      w32(0x4da174,cAdd(r32(0x4da174),1));
    }
    updateSpeedDivisor(memory);
    w32(0x4da180,r32(0x4da174));
    w32(0x4da17c,r32(0x4da178));
    w32(0x5363b4,0);
    invalidate(0);
  }
  if (cTruth(cCompare(r32(0x4faf94),34,"=="))) {
    if (cTruth(cCompare(1,r32(0x4da174),"<"))) {
      w32(0x4da174,cAdd(r32(0x4da174),cNeg(1)));
    }
    updateSpeedDivisor(memory);
    w32(0x4da180,r32(0x4da174));
    w32(0x4da17c,r32(0x4da178));
    w32(0x5363b4,0);
    invalidate(0);
  }
  if (cTruth((cTruth((cTruth((cTruth(cCompare(r32(0x4faf94),123,"==")) && cTruth(cCompare(r32(0x536444),0,"==")))) && cTruth(cCompare(r32(0x4da140),1,"==")))) && cTruth(cCompare(r32(0x4da16c),0,"=="))))) {
    w32(0x536478,cAdd(r32(0x536478),1));
    if (cTruth(cCompare(1,r32(0x536478),"<"))) {
      w32(0x536478,0);
    }
    w32(0x4da1a8,0);
    if (cTruth(cCompare(2,r32(0x4da194),"<"))) {
      w32(0x536478,0);
    }
    w32(0x5363b4,0);
    invalidate(0);
    w32(0x4faf94,cNeg(1));
  }
  if (cTruth(cCompare(r32(0x4faf94),186,"=="))) {
    w32(0x536488,cAdd(r32(0x536488),1));
    if (cTruth(cCompare(1,r32(0x536488),"<"))) {
      w32(0x536488,0);
    }
    w32(0x5363b4,0);
    invalidate(0);
  }
  if (cTruth((cTruth(cCompare(r32(0x4faf94),32,"==")) && cTruth(cCompare(0,r32(0x536444),"<"))))) {
    w32(0x536444,0);
    w32(0x536448,0);
    w32(0x5363b4,0);
    invalidate(0);
    w32(0x4faf94,cNeg(1));
  }
  if (cTruth(cCompare(r32(0x4faf94),191,"=="))) {
    w32(0x5363b4,1);
    w32(0x536444,6);
    w32(0x536448,6);
    invalidate(0);
    w32(0x4fb9b4,0);
  }
  if (cTruth((cTruth(cCompare(r32(0x4faf94),32,"==")) && cTruth(cCompare(0,r32(0x5363b0),"<"))))) {
    if (cTruth((cTruth((cTruth(cCompare(r32(0x5363f0),0,"==")) && cTruth((cTruth((cTruth(cCompare(r32(0x5233a8),0,"==")) && cTruth(cCompare(r32(0x536434),0,"==")))) && cTruth(cCompare(r32(0x536438),0,"==")))))) && cTruth((cTruth(cCompare(r32(0x53644c),0,"==")) && cTruth(cCompare(r32(0x536444),0,"=="))))))) {
      if (cTruth(cCompare(r32(0x4da174),1,"=="))) {
        w32(0x4da178,r32(0x4da17c));
        w32(0x4da174,r32(0x4da180));
        if (cTruth(cCompare(r32(0x4da1dc),1,"=="))) {
          w32(0x4da1dc,2);
          w32(0x4da1e0,r32(0x4f8cd0));
        }
      } else {
        w32(0x4da180,r32(0x4da174));
        w32(0x4da17c,r32(0x4da178));
        w32(0x4da178,2919);
        w32(0x4da174,1);
      }
    } else {
      w32(0x5363f0,0);
      w32(0x536438,0);
      w32(0x536434,0);
      w32(0x536404,0);
      w32(0x5233a8,0);
      w32(0x536444,0);
      w32(0x536448,0);
      w32(0x53644c,0);
      w32(0x53642c,0);
      w32(0x5363b4,0);
      invalidate(0);
    }
    w32(0x4faf94,cNeg(1));
  }
  if (cTruth(cCompare(r32(0x4faf94),78,"=="))) {
    w32(0x5363b0,0);
    w32(0x536440,0);
    w32(0x5363f4,0);
    w32(0x536444,0);
    w32(0x53648c,0);
    w32(0x5363f0,0);
    if (cTruth(cCompare(2,r32(0x5363fc),"<"))) {
      w32(0x5363fc,0);
    }
    w32(0x5363b4,0);
    w32(0x4f8cd0,r32(0x4f42b8));
    invalidate(1);
  }
  if (cTruth(cCompare(r32(0x4faf94),70,"=="))) {
    w32(0x53642c,cAdd(r32(0x53642c),1));
    if (cTruth(cCompare(1,r32(0x53642c),"<"))) {
      w32(0x53642c,0);
    }
    if (cTruth(cCompare(r32(0x53642c),0,"=="))) {
      w32(0x5363b4,0);
      invalidate(0);
    } else {
      w32(0x5363b4,1);
    }
  }
  if (cTruth(cCompare(r32(0x4faf94),82,"=="))) {
    w32(0x5233a8,cAdd(r32(0x5233a8),1));
    (bVar6 = cI32(cCompare(r32(0x5233a8),1,"==")));
    if (cTruth(cCompare(1,r32(0x5233a8),"<"))) {
      w32(0x5233a8,0);
    }
    if (cTruth(bVar6)) {
      (hWnd = cI32(windowHandle));
    } else {
      w32(0x5363b4,0);
      (hWnd = cI32(windowHandle));
    }
    invalidate(0);
    w32(0x536404,0);
    w32(0x536434,0);
    w32(0x536438,0);
    w32(0x5363f0,0);
  }
  if (cTruth(cCompare(r32(0x4faf94),87,"=="))) {
    w32(0x5363f0,cAdd(r32(0x5363f0),1));
    if (cTruth(cCompare(1,r32(0x5363f0),"<"))) {
      w32(0x5363f0,0);
    }
    w32(0x5363b4,0);
    invalidate(1);
    w32(0x536404,0);
    w32(0x5233a8,0);
    w32(0x536444,0);
    w32(0x4fafa0,1);
  }
  if (cTruth((cTruth(cCompare(r32(0x4faf94),89,"==")) && cTruth(cCompare(r32(0x4da140),1,"=="))))) {
    if (cTruth(cCompare(r32(0x536448),300,"=="))) {
      w32(0x536444,0);
      w32(0x536448,0);
    } else {
      w32(0x536444,300);
      w32(0x536448,300);
      w32(0x5363f0,0);
    }
    w32(0x5363b4,0);
    invalidate(0);
  }
  if (cTruth(cCompare(r32(0x4faf94),219,"=="))) {
    w32(0x536434,cAdd(r32(0x536434),1));
    if (cTruth(cCompare(1,r32(0x536434),"<"))) {
      w32(0x536434,0);
    }
    w32(0x5363b4,0);
    invalidate(0);
    w32(0x536438,0);
    w32(0x5233a8,0);
    w32(0x5363f0,0);
    w32(0x536404,0);
    w32(0x536444,0);
  }
  if (cTruth((cTruth(cCompare(r32(0x4faf94),221,"==")) && cTruth(cCompare(0,r32(0x5359d0),"<"))))) {
    w32(0x536438,cAdd(r32(0x536438),1));
    if (cTruth(cCompare(1,r32(0x536438),"<"))) {
      w32(0x536438,0);
    }
    w32(0x5363b4,0);
    invalidate(0);
    w32(0x536434,0);
    w32(0x5233a8,0);
    w32(0x5363f0,0);
    w32(0x536404,0);
    w32(0x536444,0);
  }
  (iVar4 = cI32(r32(0x4fe770)));
  (iVar5 = cI32(r32(0x4faf94)));
  (iVar3 = cI32(r32(0x4da140)));
  if (cTruth((cTruth((cTruth(cCompare(r32(0x5233a8),1,"==")) || cTruth(cCompare(r32(0x536434),1,"==")))) || cTruth(cCompare(r32(0x536438),1,"=="))))) {
    if (cTruth(cCompare(r32(0x4faf94),88,"=="))) {
      w32(0x4da200,1);
      w32(0x5363b4,0);
      invalidate(0);
    }
    (iVar3 = cI32(r32(0x4da140)));
    (iVar5 = cI32(r32(0x4faf94)));
    if (cTruth(cCompare(r32(0x4faf94),90,"=="))) {
      w32(0x4da200,0);
      w32(0x5363b4,0);
      invalidate(0);
      (iVar3 = cI32(r32(0x4da140)));
      (iVar5 = cI32(r32(0x4faf94)));
    }
  } else {
    if (cTruth(cCompare(r32(0x4faf94),88,"=="))) {
      (iVar2 = cI32(cMul(r32(cAdd(0x50f6d0,cMul(r32(0x4da140),4))),2)));
      (iVar1 = cI32(cSub(iVar2,r32(0x4fe770))));
      w32(cAdd(0x50f6d0,cMul(r32(0x4da140),4)),iVar2);
      if (cTruth((cTruth(cCompare(iVar1,0,"!=")) && cTruth(cCompare(iVar4,iVar2,"<="))))) {
        w32(cAdd(0x50f6d0,cMul(iVar3,4)),iVar4);
      }
    }
    if (cTruth((cTruth(cCompare(iVar5,90,"==")) && cTruth(((iVar4 = cI32(r32(cAdd(0x50f6d0,cMul(iVar3,4))))), w32(cAdd(0x50f6d0,cMul(iVar3,4)),cDiv(iVar4,2)), cCompare(cDiv(iVar4,2),2,"<")))))) {
      w32(cAdd(0x50f6d0,cMul(iVar3,4)),2);
    }
  }
  if (cTruth((cTruth(cCompare(iVar5,66,"==")) && cTruth(((iVar4 = cI32(r32(cAdd(0x525a78,cMul(iVar3,4))))), w32(cAdd(0x525a78,cMul(iVar3,4)),cAdd(iVar4,1)), cCompare(2,cAdd(iVar4,1),"<")))))) {
    w32(cAdd(0x525a78,cMul(iVar3,4)),0);
  }
  if (cTruth(cCompare(iVar5,86,"=="))) {
    (iVar4 = cI32(r32(cAdd(0x4f71c0,cMul(iVar3,4)))));
    w32(cAdd(cMul(iVar3,4),5388888),0);
    w32(cAdd(0x4f71c0,cMul(iVar3,4)),cAdd(iVar4,1));
    if (cTruth(cCompare(3,cAdd(iVar4,1),"<"))) {
      w32(cAdd(0x4f71c0,cMul(iVar3,4)),1);
    }
  }
  if (cTruth((cTruth(cCompare(iVar5,85,"==")) && cTruth(((iVar4 = cI32(cAdd(r32(cAdd(cMul(iVar3,4),5194224)),1))), w32(cAdd(cMul(iVar3,4),5194224),iVar4), cCompare(1,iVar4,"<")))))) {
    w32(cAdd(cMul(iVar3,4),5194224),0);
  }
  if (cTruth((cTruth(cCompare(iVar5,188,"==")) || cTruth(cCompare(iVar5,222,"=="))))) {
    if (cTruth(cCompare(iVar3,1,"=="))) {
      w64(0x4fe938,cSub(r64(0x4fe938),r64(0x4cc580)));
    } else {
      w32(0x535748,wrapDegreesOnce(cAdd(r32(0x535748),cNeg(10))));
      (iVar3 = cI32(r32(0x4da140)));
      (iVar5 = cI32(r32(0x4faf94)));
    }
    w32(cAdd(0x511620,cMul(iVar3,4)),0);
    w32(cAdd(0x4f6a68,cMul(iVar3,4)),0);
    w32(cAdd(cMul(iVar3,4),5225384),0);
    w32(cAdd(0x4f7090,cMul(iVar3,4)),0);
    w32(cAdd(0x5356b0,cMul(iVar3,4)),0);
  }
  if (cTruth((cTruth(cCompare(iVar5,190,"==")) || cTruth(cCompare(iVar5,13,"=="))))) {
    if (cTruth(cCompare(iVar3,1,"=="))) {
      w64(0x4fe938,cSub(r64(0x4fe938),r64(0x4cc588)));
    } else {
      w32(0x535748,wrapDegreesOnce(cAdd(r32(0x535748),10)));
      (iVar3 = cI32(r32(0x4da140)));
      (iVar5 = cI32(r32(0x4faf94)));
    }
    w32(cAdd(0x511620,cMul(iVar3,4)),0);
    w32(cAdd(0x4f6a68,cMul(iVar3,4)),0);
    w32(cAdd(cMul(iVar3,4),5225384),0);
    w32(cAdd(0x4f7090,cMul(iVar3,4)),0);
    w32(cAdd(0x5356b0,cMul(iVar3,4)),0);
  }
  if (cTruth(cCompare(iVar5,67,"=="))) {
    w32(cAdd(0x4f7090,cMul(iVar3,4)),4294967295);
    w32(cAdd(0x5359e0,cMul(iVar3,4)),0);
    w32(cAdd(0x511620,cMul(iVar3,4)),0);
    w32(cAdd(0x4f6a68,cMul(iVar3,4)),0);
    w32(cAdd(0x5356b0,cMul(iVar3,4)),0);
  }
  (iVar4 = cI32(r32(0x4f8cd0)));
  if (cTruth(cCompare(iVar5,84,"=="))) {
    w32(cAdd(0x4f7090,cMul(iVar3,4)),1);
    w32(cAdd(0x511620,cMul(iVar3,4)),0);
    w32(cAdd(cMul(iVar3,4),5225384),0);
    w32(cAdd(0x4f6a68,cMul(iVar3,4)),0);
    w32(cAdd(0x4f4350,cMul(iVar3,4)),iVar4);
    w32(cAdd(0x4f4a70,cMul(iVar3,4)),1);
    w32(cAdd(0x5356b0,cMul(iVar3,4)),0);
  }
  if (cTruth(cCompare(iVar5,74,"=="))) {
    w32(cAdd(0x5356b0,cMul(iVar3,4)),1);
    w32(cAdd(0x511620,cMul(iVar3,4)),0);
    w32(cAdd(cMul(iVar3,4),5225384),0);
    w32(cAdd(0x4f6a68,cMul(iVar3,4)),0);
    w32(cAdd(0x4f7090,cMul(iVar3,4)),0);
  }
  if (cTruth(cCompare(iVar5,72,"=="))) {
    if (cTruth(cCompare(r32(cAdd(0x4fecc8,cMul(iVar3,4))),90,"<"))) {
      w32(cAdd(cMul(iVar3,4),5225384),2);
    } else {
      w32(cAdd(cMul(iVar3,4),5225384),3);
    }
    w32(cAdd(0x511620,cMul(iVar3,4)),0);
    w32(cAdd(0x4f6a68,cMul(iVar3,4)),0);
    w32(cAdd(0x4f7090,cMul(iVar3,4)),0);
    w32(cAdd(0x5356b0,cMul(iVar3,4)),0);
  }
  if (cTruth((cTruth(cCompare(iVar5,68,"==")) && cTruth(cCompare(0,r32(0x5363b0),"<"))))) {
    w32(cAdd(cMul(iVar3,4),5225384),1);
    w32(cAdd(0x511620,cMul(iVar3,4)),0);
    w32(cAdd(0x4f6a68,cMul(iVar3,4)),0);
    w32(cAdd(0x4f7090,cMul(iVar3,4)),0);
    w32(cAdd(0x5356b0,cMul(iVar3,4)),0);
    w32(cAdd(0x4f3f60,cMul(iVar3,4)),0);
  }
  if (cTruth((cTruth(cCompare(iVar5,189,"==")) && cTruth((cTruth(cCompare(r32(0x536444),0,"==")) && cTruth(cCompare(r32(0x536438),1,"=="))))))) {
    w32(0x536404,cAdd(r32(0x536404),cNeg(1)));
    if (cTruth(cCompare(r32(0x536404),0,"<"))) {
      w32(0x536404,0);
    }
    w32(0x5363b4,0);
    invalidate(0);
    (iVar3 = cI32(r32(0x4da140)));
    (iVar5 = cI32(r32(0x4faf94)));
  }
  (iVar4 = cI32(r32(0x536444)));
  if (cTruth(cCompare(iVar5,187,"=="))) {
    if (cTruth(cCompare(r32(0x536444),0,"=="))) {
      if (cTruth(cCompare(r32(0x536438),1,"=="))) {
        w32(0x5363b4,0);
        w32(0x536404,cAdd(r32(0x536404),1));
        invalidate(0);
        (iVar4 = cI32(r32(0x536444)));
        (iVar3 = cI32(r32(0x4da140)));
        (iVar5 = cI32(r32(0x4faf94)));
      } else {
        if (cTruth(cCompare(0,r32(cAdd(0x511620,cMul(iVar3,4))),"<"))) {
          w32(cAdd(0x5359e0,cMul(iVar3,4)),5);
          w32(cAdd(0x511620,cMul(iVar3,4)),1);
          w32(cAdd(0x4f6a68,cMul(iVar3,4)),0);
          w32(cAdd(0x4f7090,cMul(iVar3,4)),0);
          w32(cAdd(0x5356b0,cMul(iVar3,4)),0);
        }
        if (cTruth(cCompare(0,r32(cAdd(0x4f6a68,cMul(iVar3,4))),"<"))) {
          w32(cAdd(0x4f3f60,cMul(iVar3,4)),7);
          w32(cAdd(0x4f6a68,cMul(iVar3,4)),1);
          w32(cAdd(cMul(iVar3,4),5225384),0);
          w32(cAdd(0x4f7090,cMul(iVar3,4)),0);
          w32(cAdd(0x5356b0,cMul(iVar3,4)),0);
          w32(cAdd(0x511620,cMul(iVar3,4)),0);
        }
      }
    }
    if (cTruth((cTruth((cTruth((cTruth(cCompare(iVar5,187,"==")) && cTruth(cCompare(100,iVar4,"<")))) && cTruth(cCompare(iVar4,110,"<")))) && cTruth((cTruth(cCompare(r32(0x4da16c),0,"==")) || cTruth(cCompare(iVar4,102,"<"))))))) {
      w32(0x4fb9b4,0);
      w32(0x536444,cAdd(r32(0x536444),1));
      invalidate(0);
      (iVar4 = cI32(r32(0x536444)));
      (iVar3 = cI32(r32(0x4da140)));
      (iVar5 = cI32(r32(0x4faf94)));
    }
  }
  if (cTruth((cTruth((cTruth(cCompare(iVar5,189,"==")) && cTruth(cCompare(101,iVar4,"<")))) && cTruth(cCompare(iVar4,111,"<"))))) {
    w32(0x4fb9b4,0);
    w32(0x536444,cAdd(r32(0x536444),cNeg(1)));
    invalidate(0);
    (iVar4 = cI32(r32(0x536444)));
    (iVar3 = cI32(r32(0x4da140)));
    (iVar5 = cI32(r32(0x4faf94)));
  }
  if (cTruth((cTruth((cTruth((cTruth(cCompare(iVar5,187,"==")) && cTruth(cCompare(500,iVar4,"<")))) && cTruth(cCompare(iVar4,514,"<")))) && cTruth((cTruth(cCompare(r32(0x4da16c),0,"==")) || cTruth(cCompare(iVar4,502,"<"))))))) {
    w32(0x4fb9b4,0);
    w32(0x536444,cAdd(r32(0x536444),1));
    invalidate(0);
    (iVar4 = cI32(r32(0x536444)));
    (iVar3 = cI32(r32(0x4da140)));
    (iVar5 = cI32(r32(0x4faf94)));
  }
  if (cTruth((cTruth((cTruth(cCompare(iVar5,189,"==")) && cTruth(cCompare(501,iVar4,"<")))) && cTruth(cCompare(iVar4,515,"<"))))) {
    w32(0x4fb9b4,0);
    w32(0x536444,cAdd(r32(0x536444),cNeg(1)));
    invalidate(0);
    (iVar4 = cI32(r32(0x536444)));
    (iVar3 = cI32(r32(0x4da140)));
    (iVar5 = cI32(r32(0x4faf94)));
  }
  if (cTruth((cTruth((cTruth(cCompare(iVar5,187,"==")) && cTruth(cCompare(600,iVar4,"<")))) && cTruth(cCompare(iVar4,604,"<"))))) {
    w32(0x4fb9b4,0);
    w32(0x536444,cAdd(r32(0x536444),1));
    invalidate(0);
    (iVar4 = cI32(r32(0x536444)));
    (iVar3 = cI32(r32(0x4da140)));
    (iVar5 = cI32(r32(0x4faf94)));
  }
  if (cTruth(cCompare(iVar5,189,"=="))) {
    if (cTruth((cTruth(cCompare(601,iVar4,"<")) && cTruth(cCompare(iVar4,605,"<"))))) {
      w32(0x4fb9b4,0);
      w32(0x536444,cAdd(r32(0x536444),cNeg(1)));
      invalidate(0);
      (iVar4 = cI32(r32(0x536444)));
      (iVar3 = cI32(r32(0x4da140)));
      (iVar5 = cI32(r32(0x4faf94)));
    }
    if (cTruth((cTruth(cCompare(iVar5,189,"==")) && cTruth(cCompare(iVar4,0,"=="))))) {
      if (cTruth(cCompare(0,r32(cAdd(0x511620,cMul(iVar3,4))),"<"))) {
        w32(cAdd(0x5359e0,cMul(iVar3,4)),4294967291);
        w32(cAdd(0x511620,cMul(iVar3,4)),1);
        w32(cAdd(0x4f6a68,cMul(iVar3,4)),0);
        w32(cAdd(0x4f7090,cMul(iVar3,4)),0);
        w32(cAdd(0x5356b0,cMul(iVar3,4)),0);
      }
      if (cTruth(cCompare(0,r32(cAdd(0x4f6a68,cMul(iVar3,4))),"<"))) {
        w32(cAdd(0x4f3f60,cMul(iVar3,4)),4294967289);
        w32(cAdd(0x4f6a68,cMul(iVar3,4)),1);
        w32(cAdd(cMul(iVar3,4),5225384),0);
        w32(cAdd(0x4f7090,cMul(iVar3,4)),0);
        w32(cAdd(0x5356b0,cMul(iVar3,4)),0);
        w32(cAdd(0x511620,cMul(iVar3,4)),0);
      }
    }
  }
  if (cTruth(cCompare(iVar5,83,"=="))) {
    if (cTruth(cCompare(0,r32(0x5363b0),"<"))) {
      w32(cAdd(0x500380,cMul(iVar3,4)),90);
    }
    if (cTruth(cCompare(r32(0x5363b0),0,"=="))) {
      w32(0x536468,cAdd(r32(0x536468),1));
    }
  }
  if (cTruth(cCompare(1,r32(0x536468),"<"))) {
    w32(0x536468,0);
  }
  if (cTruth(cCompare(iVar5,65,"=="))) {
    if (cTruth(cCompare(iVar4,0,"=="))) {
      w32(cAdd(0x500380,cMul(iVar3,4)),4294967295);
    }
    if (cTruth(cCompare(0,iVar4,"<"))) {
      w32(0x4fb9b4,cAdd(r32(0x4fb9b4),1));
      if (cTruth(cCompare(r32(0x4da18c),r32(0x4fb9b4),"<"))) {
        w32(0x4fb9b4,0);
      }
      invalidate(0);
      w32(0x5363b4,1);
      (iVar3 = cI32(r32(0x4da140)));
      (iVar5 = cI32(r32(0x4faf94)));
    }
  }
  if (cTruth((cTruth(cCompare(iVar5,27,"==")) && cTruth(((iVar4 = cI32(r32(cAdd(0x500380,cMul(iVar3,4))))), w32(cAdd(0x500380,cMul(iVar3,4)),cAdd(iVar4,cNeg(5))), cCompare(cAdd(iVar4,cNeg(5)),0,"<")))))) {
    w32(cAdd(0x500380,cMul(iVar3,4)),0);
  }
  if (cTruth((cTruth(cCompare(iVar5,192,"==")) && cTruth(((iVar4 = cI32(r32(cAdd(0x500380,cMul(iVar3,4))))), w32(cAdd(0x500380,cMul(iVar3,4)),cAdd(iVar4,5)), cCompare(90,cAdd(iVar4,5),"<")))))) {
    w32(cAdd(0x500380,cMul(iVar3,4)),90);
  }
  if (cTruth((cTruth((cTruth(cCompare(iVar5,71,"==")) && cTruth(cCompare(iVar3,1,"==")))) && cTruth((w32(0x4f7ee4,cAdd(r32(0x4f7ee4),1)), cCompare(3,r32(0x4f7ee4),"<")))))) {
    w32(0x4f7ee4,1);
  }
  if (cTruth((cTruth(cCompare(iVar5,73,"==")) && cTruth(((iVar4 = cI32(r32(cAdd(0x500380,cMul(iVar3,4))))), w32(cAdd(0x500380,cMul(iVar3,4)),cAdd(iVar4,cNeg(20))), cCompare(cAdd(iVar4,cNeg(20)),0,"<")))))) {
    w32(cAdd(0x500380,cMul(iVar3,4)),4294967295);
  }
  if (cTruth((cTruth(cCompare(iVar5,79,"==")) && cTruth(((iVar4 = cI32(r32(cAdd(0x500380,cMul(iVar3,4))))), w32(cAdd(0x500380,cMul(iVar3,4)),cAdd(iVar4,20)), cCompare(90,cAdd(iVar4,20),"<")))))) {
    w32(cAdd(0x500380,cMul(iVar3,4)),90);
  }
  (iVar4 = cI32(r32(0x5364c8)));
  if (cTruth((cTruth((cTruth(cCompare(iVar5,69,"==")) && cTruth(cCompare(r32(0x5364c8),0,"==")))) && cTruth(((iVar1 = cI32(r32(cAdd(0x4fe778,cMul(iVar3,4))))), w32(cAdd(0x4fe778,cMul(iVar3,4)),cAdd(iVar1,1)), cCompare(3,cAdd(iVar1,1),"<")))))) {
    w32(cAdd(0x4fe778,cMul(iVar3,4)),1);
  }
  if (cTruth((cTruth(cCompare(iVar5,112,"==")) && cTruth(cCompare(iVar4,0,"=="))))) {
    w32(cAdd(0x4fe778,cMul(iVar3,4)),1);
  }
  if (cTruth((cTruth(cCompare(iVar5,113,"==")) && cTruth(cCompare(iVar4,0,"=="))))) {
    w32(cAdd(0x4fe778,cMul(iVar3,4)),2);
  }
  if (cTruth((cTruth(cCompare(iVar5,114,"==")) && cTruth(cCompare(iVar4,0,"=="))))) {
    w32(cAdd(0x4fe778,cMul(iVar3,4)),3);
  }
  if (cTruth(cCompare(iVar5,115,"=="))) {
    w32(cAdd(0x525a78,cMul(iVar3,4)),1);
  }
  if (cTruth(cCompare(iVar5,116,"=="))) {
    w32(cAdd(0x525a78,cMul(iVar3,4)),2);
  }
  if (cTruth((cTruth((cTruth((cTruth(cCompare(iVar5,80,"==")) && cTruth(cCompare(iVar3,1,"==")))) && cTruth(cCompare(1,r32(0x4da190),"<")))) && cTruth((cTruth(cCompare(r32(0x4da190),9,"!=")) && cTruth((w32(0x4f4520,cAdd(r32(0x4f4520),1)), cCompare(1,r32(0x4f4520),"<")))))))) {
    w32(0x4f4520,0);
  }
  if (cTruth((cTruth((cTruth(cCompare(iVar5,80,"==")) && cTruth(cCompare(iVar3,2,"==")))) && cTruth((cTruth(cCompare(1,r32(0x4da190),"<")) && cTruth((cTruth(cCompare(r32(0x4da190),9,"!=")) && cTruth((w32(0x4f4524,cAdd(r32(0x4f4524),1)), cCompare(1,r32(0x4f4524),"<")))))))))) {
    w32(0x4f4524,0);
  }
  if (cTruth((cTruth(cCompare(iVar5,76,"==")) && cTruth((w32(0x536490,cAdd(r32(0x536490),1)), cCompare(1,r32(0x536490),"<")))))) {
    w32(0x536490,0);
  }
  if (cTruth((cTruth(cCompare(iVar5,48,"==")) && cTruth(((iVar4 = cI32(cAdd(r32(cAdd(cMul(iVar3,4),5388888)),1))), w32(cAdd(cMul(iVar3,4),5388888),iVar4), cCompare(1,iVar4,"<")))))) {
    w32(cAdd(cMul(iVar3,4),5388888),0);
  }
  if (cTruth(cCompare(iVar5,49,"=="))) {
    w32(cAdd(0x4f71c0,cMul(iVar3,4)),1);
    w32(cAdd(cMul(iVar3,4),5388888),0);
  }
  if (cTruth(cCompare(iVar5,50,"=="))) {
    w32(cAdd(0x4f71c0,cMul(iVar3,4)),2);
    w32(cAdd(cMul(iVar3,4),5388888),0);
  }
  if (cTruth(cCompare(iVar5,51,"=="))) {
    w32(cAdd(0x4f71c0,cMul(iVar3,4)),3);
    w32(cAdd(cMul(iVar3,4),5388888),0);
  }
  if (cTruth((cTruth((cTruth(cCompare(iVar5,52,"==")) && cTruth(cCompare(iVar3,1,"==")))) && cTruth(cCompare(r32(0x536478),0,"=="))))) {
    w32(0x4da1a8,cAdd(r32(0x4da1a8),1));
    if (cTruth(cCompare(1,r32(0x4da1a8),"<"))) {
      w32(0x4da1a8,0);
    }
    w32(0x5363b4,0);
    invalidate(0);
    (iVar3 = cI32(r32(0x4da140)));
    (iVar5 = cI32(r32(0x4faf94)));
  }
  if (cTruth((cTruth(cCompare(iVar5,55,"==")) || cTruth(cCompare(iVar5,36,"=="))))) {
    w32(cAdd(0x4f49a0,cMul(iVar3,4)),0);
    w32(cAdd(0x512d60,cMul(iVar3,4)),cNeg(cI32(cCompare(r32(cAdd(0x512d60,cMul(iVar3,4))),cNeg(1),"!="),true)));
  }
  if (cTruth((cTruth(cCompare(iVar5,53,"==")) || cTruth(cCompare(iVar5,12,"=="))))) {
    w32(cAdd(0x4f49a0,cMul(iVar3,4)),0);
    w32(cAdd(0x512d60,cMul(iVar3,4)),cI32(cCompare(r32(cAdd(0x512d60,cMul(iVar3,4))),1,"!="),true));
  }
  if (cTruth(cCompare(iVar5,57,"=="))) {
    w32(0x5233a4,0);
    w32(cAdd(0x4f49a0,cMul(iVar3,4)),0);
    w32(cAdd(0x512d60,cMul(iVar3,4)),cBits(cNeg(cI32(cCompare(r32(cAdd(0x512d60,cMul(iVar3,4))),100,"!="),true)),100,"&"));
  }
  if (cTruth(cCompare(iVar5,38,"=="))) {
    w32(cAdd(0x4f49a0,cMul(iVar3,4)),0);
    w32(cAdd(0x512d60,cMul(iVar3,4)),0);
  }
  if (cTruth(cCompare(iVar5,40,"=="))) {
    w32(cAdd(0x4f49a0,cMul(iVar3,4)),180);
    w32(cAdd(0x512d60,cMul(iVar3,4)),0);
  }
  if (cTruth(cCompare(iVar5,39,"=="))) {
    (iVar4 = cI32(r32(cAdd(0x4f49a0,cMul(iVar3,4)))));
    w32(cAdd(0x4f49a0,cMul(iVar3,4)),cAdd(iVar4,cNeg(30)));
    if (cTruth(cCompare(cAdd(iVar4,cNeg(30)),cNeg(360),"<"))) {
      w32(cAdd(0x4f49a0,cMul(iVar3,4)),0);
    }
    w32(cAdd(0x512d60,cMul(iVar3,4)),0);
  }
  if (cTruth(cCompare(iVar5,37,"=="))) {
    (iVar5 = cI32(r32(cAdd(0x4f49a0,cMul(iVar3,4)))));
    w32(cAdd(0x4f49a0,cMul(iVar3,4)),cAdd(iVar5,30));
    if (cTruth(cCompare(360,cAdd(iVar5,30),"<"))) {
      w32(cAdd(0x4f49a0,cMul(iVar3,4)),0);
    }
    w32(cAdd(0x512d60,cMul(iVar3,4)),0);
  }
  options.defaultKeyHandler?.({key:param_2,repeat:param_3,flags:param_4});
  return;
}

export const KEYBOARD_ROUTINES=Object.freeze({handleKeyDown:0x491db0});
export function handleKeyDown(memory,key,options={}) { return originalKeyDown(memory,{...options,key}); }
