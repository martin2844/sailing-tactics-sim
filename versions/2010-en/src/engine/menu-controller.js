import { i32 } from '../../../../src/runtime/c-types.js';
import { Float80 } from '../../../../src/runtime/float80.js';
import { wrapDegreesOnce, updateSpeedDivisor, scaledRandom } from './application.js';
import { controllerMemory, cI32, cFloat, cAdd, cSub, cMul, cDiv, cRem, cNeg, cBits, cCompare, cTruth } from './controller-values.js';

function command32771(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b0,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32771(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  return;
}

function command32777(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b0,0);
  w32(0x5363f4,0);
  w32(0x536440,0);
  w32(0x536444,0);
  w32(0x5363f0,0);
  if (cTruth(cCompare(2,r32(0x5363fc),"<"))) {
    w32(0x5363fc,0);
  }
  w32(0x4f8cd0,r32(0x4f42b8));
  w32(0x5363b4,0);
  invalidate(1);
  return;
}

function update32777(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(0,r32(0x5363b0),"<"));
  return;
}

function command32776(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x53643c,cAdd(r32(0x53643c),1));
  if (cTruth(cCompare(1,r32(0x53643c),"<"))) {
    w32(0x53643c,0);
  }
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32776(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(cNeg(1),r32(0x5363b0),"<"));
  check(cCompare(r32(0x53643c),1,"=="));
  return;
}

function command32783(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da144,6);
  w32(0x4da190,3);
  w32(0x5363c0,0);
  w32(0x5363b4,0);
  invalidate(1);
  return;
}

function update32783(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x536470),0,"=="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da144),6,"=="));
  return;
}

function command32792(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da144,15);
  w32(0x4da190,8);
  w32(0x5363c0,0);
  w32(0x5363b4,0);
  invalidate(1);
  return;
}

function update32792(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x536470),0,"=="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da144),15,"=="));
  return;
}

function command32881(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da144,3);
  w32(0x4da190,1);
  w32(0x5363c0,0);
  w32(0x5363b4,0);
  invalidate(1);
  return;
}

function update32881(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x536470),0,"=="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da144),3,"=="));
  return;
}

function command32784(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da144,5);
  w32(0x4da190,2);
  w32(0x5363c0,0);
  w32(0x5363b4,0);
  invalidate(1);
  return;
}

function update32784(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x536470),0,"=="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da144),5,"=="));
  return;
}

function command32789(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da144,12);
  w32(0x4da190,6);
  w32(0x5363c0,0);
  w32(0x5363b4,0);
  invalidate(1);
  return;
}

function update32789(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x536470),0,"=="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da144),12,"=="));
  return;
}

function command32782(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da144,2);
  w32(0x4da190,1);
  w32(0x5363c0,0);
  w32(0x5363b4,0);
  invalidate(1);
  return;
}

function update32782(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x536470),0,"=="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da144),2,"=="));
  return;
}

function command32788(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da144,9);
  w32(0x4da190,5);
  w32(0x5363c0,0);
  w32(0x5363b4,0);
  invalidate(1);
  return;
}

function update32788(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x536470),0,"=="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da144),9,"=="));
  return;
}

function command32791(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da144,14);
  w32(0x4da190,7);
  w32(0x5363c0,0);
  w32(0x5363b4,0);
  invalidate(1);
  w32(0x4da14c,1);
  return;
}

function update32791(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da144),14,"=="));
  return;
}

function command32781(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da144,1);
  w32(0x4da190,1);
  w32(0x5363c0,0);
  w32(0x5363b4,0);
  invalidate(1);
  return;
}

function update32781(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x536470),0,"=="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da144),1,"=="));
  return;
}

function command32786(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da144,7);
  w32(0x4da190,3);
  w32(0x5363c0,0);
  w32(0x5363b4,0);
  invalidate(1);
  return;
}

function update32786(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x536470),0,"=="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da144),7,"=="));
  return;
}

function command32794(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da144,11);
  w32(0x4da190,10);
  w32(0x5363c0,0);
  w32(0x5363b4,0);
  invalidate(1);
  return;
}

function update32794(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x536470),0,"=="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da144),11,"=="));
  return;
}

function command32790(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da144,13);
  w32(0x4da190,7);
  w32(0x5363c0,1);
  w32(0x5363b4,0);
  invalidate(1);
  return;
}

function update32790(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x536470),0,"=="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da144),13,"=="));
  return;
}

function command32787(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da144,8);
  w32(0x4da190,4);
  w32(0x5363c0,0);
  w32(0x5363b4,0);
  invalidate(1);
  return;
}

function update32787(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x536470),0,"=="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da144),8,"=="));
  return;
}

function command32793(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da144,10);
  w32(0x4da190,9);
  w32(0x5363c0,0);
  w32(0x5363b4,0);
  invalidate(1);
  return;
}

function update32793(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x536470),0,"=="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da144),10,"=="));
  return;
}

function update32823(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  if (cTruth((cTruth((cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(5,r32(0x4da190),"<")))) && cTruth(cCompare(r32(0x4da190),8,"<")))) && cTruth((cTruth((cTruth(cCompare(r32(0x5364c8),0,"==")) && cTruth(cCompare(r32(0x5363c0),2,"!=")))) && cTruth((cTruth(cCompare(r32(0x5363c0),3,"!=")) && cTruth(cCompare(r32(0x536528),0,"=="))))))))) {
    enable(1);
    return;
  }
  enable(0);
  return;
}

function command32780(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  return;
}

function update32780(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  return;
}

function command32807(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da194,10);
  w32(0x5363b4,0);
  invalidate(0);
  w32(0x53646c,0);
  w32(0x4da1e8,0);
  return;
}

function update32807(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x536470),0,"=="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da194),10,"=="));
  return;
}

function command32808(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da194,15);
  w32(0x5363b4,0);
  invalidate(0);
  w32(0x53646c,0);
  w32(0x4da1e8,1);
  if (cTruth((cTruth((cTruth((cTruth(cCompare(r32(0x4da188),3,"==")) || cTruth(cCompare(r32(0x4da188),4,"==")))) || cTruth(cCompare(r32(0x4da188),6,"==")))) || cTruth(cCompare(r32(0x4da19c),8,"=="))))) {
    w32(0x4da1e8,0);
  }
  return;
}

function update32808(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x536470),0,"=="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da194),15,"=="));
  return;
}

function command32809(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da194,20);
  w32(0x5363b4,0);
  invalidate(0);
  w32(0x53646c,0);
  w32(0x4da1e8,1);
  if (cTruth((cTruth((cTruth((cTruth(cCompare(r32(0x4da188),3,"==")) || cTruth(cCompare(r32(0x4da188),4,"==")))) || cTruth(cCompare(r32(0x4da188),6,"==")))) || cTruth(cCompare(r32(0x4da19c),8,"=="))))) {
    w32(0x4da1e8,0);
  }
  return;
}

function update32809(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x536470),0,"=="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da194),20,"=="));
  return;
}

function command32810(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da194,25);
  w32(0x5363b4,0);
  invalidate(0);
  w32(0x53646c,0);
  w32(0x4da1e8,1);
  if (cTruth((cTruth((cTruth((cTruth(cCompare(r32(0x4da188),3,"==")) || cTruth(cCompare(r32(0x4da188),4,"==")))) || cTruth(cCompare(r32(0x4da188),6,"==")))) || cTruth(cCompare(r32(0x4da19c),8,"=="))))) {
    w32(0x4da1e8,0);
  }
  return;
}

function update32810(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x536470),0,"=="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da194),25,"=="));
  return;
}

function command32805(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da194,2);
  if (cTruth(cCompare(5,r32(0x4da1d8),"<"))) {
    w32(0x4da1d8,5);
  }
  w32(0x53646c,1);
  w32(0x4da1e8,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32805(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da194),2,"=="));
  return;
}

function command32811(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da194,30);
  w32(0x5363b4,0);
  invalidate(0);
  w32(0x53646c,0);
  w32(0x4da1e8,1);
  if (cTruth((cTruth((cTruth((cTruth(cCompare(r32(0x4da188),3,"==")) || cTruth(cCompare(r32(0x4da188),4,"==")))) || cTruth(cCompare(r32(0x4da188),6,"==")))) || cTruth(cCompare(r32(0x4da19c),8,"=="))))) {
    w32(0x4da1e8,0);
  }
  return;
}

function update32811(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x536470),0,"=="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da194),30,"=="));
  return;
}

function command32806(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da194,5);
  w32(0x5363b4,0);
  invalidate(0);
  w32(0x53646c,0);
  w32(0x4da1e8,0);
  return;
}

function update32806(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x536470),0,"=="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da194),5,"=="));
  return;
}

function command32824(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x536424,cAdd(r32(0x536424),1));
  if (cTruth(cCompare(1,r32(0x536424),"<"))) {
    w32(0x536424,0);
  }
  return;
}

function update32824(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x536424),1,"=="));
  return;
}

function command32778(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da140,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32778(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da140),1,"=="));
  return;
}

function command32820(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da168,0);
  w32(0x5363f8,1);
  w32(0x536408,1);
  w32(0x4da188,5);
  w32(0x53527c,0);
  if (cTruth(cCompare(14,r32(0x4da194),"<"))) {
    w32(0x4da1e8,1);
  }
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32820(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x4da19c),8,"!=")))) && cTruth(cCompare(r32(0x4da19c),7,"!="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  if (cTruth((cTruth((cTruth(cCompare(r32(0x4da188),5,"==")) && cTruth(cCompare(r32(0x4da19c),8,"!=")))) && cTruth(cCompare(r32(0x4da19c),7,"!="))))) {
    check(1);
    return;
  }
  check(0);
  return;
}

function command32818(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da188,3);
  w32(0x4da168,0);
  w32(0x5363f8,0);
  w32(0x536408,0);
  w32(0x53527c,0);
  w32(0x4da1e8,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32818(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x4da19c),8,"!="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  if (cTruth((cTruth(cCompare(r32(0x4da188),3,"==")) && cTruth(cCompare(r32(0x4da19c),8,"!="))))) {
    check(1);
    return;
  }
  check(0);
  return;
}

function command32819(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x536408,1);
  w32(0x4da168,0);
  w32(0x5363f8,0);
  w32(0x4da188,4);
  w32(0x53527c,0);
  w32(0x4da1e8,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32819(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x4da19c),8,"!="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  if (cTruth((cTruth(cCompare(r32(0x4da188),4,"==")) && cTruth(cCompare(r32(0x4da19c),8,"!="))))) {
    check(1);
    return;
  }
  check(0);
  return;
}

function command32816(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da168,1);
  w32(0x5363f8,0);
  w32(0x536408,0);
  w32(0x4da188,1);
  w32(0x53527c,0);
  if (cTruth(cCompare(14,r32(0x4da194),"<"))) {
    w32(0x4da1e8,1);
  }
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32816(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x4da19c),8,"!=")))) && cTruth(cCompare(r32(0x4da19c),7,"!="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  if (cTruth((cTruth((cTruth(cCompare(r32(0x4da188),1,"==")) && cTruth(cCompare(r32(0x4da19c),8,"!=")))) && cTruth(cCompare(r32(0x4da19c),7,"!="))))) {
    check(1);
    return;
  }
  check(0);
  return;
}

function command32817(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da168,1);
  w32(0x5363f8,0);
  w32(0x536408,1);
  w32(0x4da188,2);
  w32(0x53527c,0);
  if (cTruth(cCompare(14,r32(0x4da194),"<"))) {
    w32(0x4da1e8,1);
  }
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32817(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x4da19c),8,"!=")))) && cTruth(cCompare(r32(0x4da19c),7,"!="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  if (cTruth((cTruth((cTruth(cCompare(r32(0x4da188),2,"==")) && cTruth(cCompare(r32(0x4da19c),8,"!=")))) && cTruth(cCompare(r32(0x4da19c),7,"!="))))) {
    check(1);
    return;
  }
  check(0);
  return;
}

function command32802(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da19c,8);
  w32(0x5363f8,0);
  w32(0x53640c,0);
  w32(0x4f8b78,0);
  w32(0x53527c,0);
  w32(0x4da1e8,0);
  w32(0x536408,0);
  w32(0x4da1f8,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32802(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x4da190),7,"=="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  if (cTruth((cTruth(cCompare(r32(0x4da19c),8,"==")) && cTruth(cCompare(r32(0x4f8b78),0,"=="))))) {
    check(1);
    return;
  }
  check(0);
  return;
}

function command32799(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f8,0);
  w32(0x4da19c,5);
  w32(0x5363b4,0);
  invalidate(0);
  w32(0x4da1f8,0);
  return;
}

function update32799(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da19c),5,"=="));
  return;
}

function command32803(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f8,0);
  w32(0x4da19c,9);
  w32(0x5363b4,0);
  invalidate(0);
  w32(0x4da1f8,0);
  return;
}

function update32803(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da19c),9,"=="));
  return;
}

function command32804(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f8,0);
  w32(0x4da19c,10);
  w32(0x5363b4,0);
  invalidate(0);
  w32(0x4da1f8,0);
  return;
}

function update32804(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da19c),10,"=="));
  return;
}

function command32801(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da19c,7);
  w32(0x4da168,0);
  w32(0x5363f8,0);
  w32(0x53640c,0);
  w32(0x4da1e8,0);
  w32(0x53527c,0);
  w32(0x536408,0);
  w32(0x4da1f8,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32801(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x536470),0,"=="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da19c),7,"=="));
  return;
}

function command32796(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f8,0);
  w32(0x4da19c,2);
  w32(0x5363b4,0);
  invalidate(0);
  w32(0x4da1f8,0);
  return;
}

function update32796(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da19c),2,"=="));
  return;
}

function command32795(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f8,0);
  w32(0x4da19c,1);
  w32(0x5363b4,0);
  invalidate(0);
  w32(0x4da1f8,0);
  return;
}

function update32795(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da19c),1,"=="));
  return;
}

function command32797(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f8,0);
  w32(0x4da19c,3);
  w32(0x5363b4,0);
  invalidate(0);
  w32(0x4da1f8,0);
  return;
}

function update32797(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da19c),3,"=="));
  return;
}

function command32798(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f8,0);
  w32(0x4da19c,4);
  w32(0x5363b4,0);
  invalidate(0);
  w32(0x4da1f8,0);
  return;
}

function update32798(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da19c),4,"=="));
  return;
}

function command32800(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f8,0);
  w32(0x4da19c,6);
  w32(0x5363b4,0);
  invalidate(0);
  w32(0x4da1f8,0);
  return;
}

function update32800(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da19c),6,"=="));
  return;
}

function command32821(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x53640c,cAdd(r32(0x53640c),1));
  if (cTruth(cCompare(1,r32(0x53640c),"<"))) {
    w32(0x53640c,0);
  }
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32821(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x4da19c),7,"!=")))) && cTruth(cCompare(r32(0x4da19c),8,"!="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x53640c),1,"=="));
  return;
}

function command32815(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da158,cAdd(r32(0x4da158),1));
  if (cTruth(cCompare(1,r32(0x4da158),"<"))) {
    w32(0x4da158,0);
  }
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32815(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da158),1,"=="));
  return;
}

function update32779(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x536470),0,"=="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da140),2,"=="));
  return;
}

function command32822(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da14c,cNeg(r32(0x4da14c)));
  invalidate(0);
  return;
}

function update32822(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x4da190),7,"=="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da14c),1,"=="));
  return;
}

function command32812(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da154,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32812(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da154),1,"=="));
  return;
}

function command32813(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da154,2);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32813(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da154),2,"=="));
  return;
}

function command32814(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da154,3);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32814(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da154),3,"=="));
  return;
}

function command32882(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da198,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32882(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da198),1,"=="));
  return;
}

function command32891(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da198,10);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32891(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da198),10,"=="));
  return;
}

function command32892(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da198,11);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32892(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da198),11,"=="));
  return;
}

function command32893(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da198,12);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32893(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da198),12,"=="));
  return;
}

function command32894(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da198,13);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32894(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da198),13,"=="));
  return;
}

function command32895(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da198,14);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32895(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da198),14,"=="));
  return;
}

function command32896(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da198,15);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32896(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da198),15,"=="));
  return;
}

function command32883(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da198,2);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32883(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da198),2,"=="));
  return;
}

function command32884(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da198,3);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32884(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da198),3,"=="));
  return;
}

function command32885(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da198,4);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function command32886(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da198,5);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32886(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da198),5,"=="));
  return;
}

function update32885(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da198),4,"=="));
  return;
}

function command32887(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da198,6);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32887(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da198),6,"=="));
  return;
}

function command32888(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da198,7);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32888(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da198),7,"=="));
  return;
}

function command32889(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da198,8);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32889(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da198),8,"=="));
  return;
}

function command32890(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da198,9);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32890(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da198),9,"=="));
  return;
}

function command32897(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da144,4);
  w32(0x4da190,2);
  w32(0x5363c0,0);
  w32(0x5363b4,0);
  invalidate(1);
  return;
}

function update32897(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x536470),0,"=="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da144),4,"=="));
  return;
}

function command32825(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4f71c4,1);
  w32(0x523a5c,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32825(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(0,r32(0x5363b0),"<"));
  check(cCompare(r32(0x4f71c4),1,"=="));
  return;
}

function command32827(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4f71c4,3);
  w32(0x523a5c,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32827(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(0,r32(0x5363b0),"<"));
  check(cCompare(r32(0x4f71c4),3,"=="));
  return;
}

function command32826(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4f71c4,2);
  w32(0x523a5c,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32826(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(0,r32(0x5363b0),"<"));
  check(cCompare(r32(0x4f71c4),2,"=="));
  return;
}

function command32828(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4f49a4,0);
  w32(0x512d64,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32828(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  return;
}

function command32831(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4f49a4,180);
  w32(0x512d64,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32831(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  return;
}

function command32830(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4f49a4,cAdd(r32(0x4f49a4),30));
  w32(0x512d64,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32830(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  return;
}

function command32829(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4f49a4,cAdd(r32(0x4f49a4),cNeg(30)));
  w32(0x512d64,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32829(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  return;
}

function command32907(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
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
  return;
}

function update32907(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(1,r32(0x5363b0),"<"));
  return;
}

function command32908(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x53646c,cAdd(r32(0x53646c),1));
  if (cTruth(cCompare(1,r32(0x53646c),"<"))) {
    w32(0x53646c,0);
  }
  return;
}

function update32908(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x4da19c),7,"!="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x53646c),1,"=="));
  return;
}

function command32905(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  let bVar1,hWnd;
  w32(0x5233a8,cAdd(r32(0x5233a8),1));
  (bVar1 = cI32(cCompare(r32(0x5233a8),1,"!=")));
  if (cTruth(cCompare(1,r32(0x5233a8),"<"))) {
    w32(0x5233a8,0);
  }
  if (cTruth(bVar1)) {
    (hWnd = cI32(windowHandle));
  } else {
    (hWnd = cI32(windowHandle));
  }
  w32(0x5363b4,cI32(!cTruth(bVar1),true));
  invalidate(0);
  w32(0x536404,0);
  w32(0x536434,0);
  w32(0x536438,0);
  w32(0x5363f0,0);
  return;
}

function command32850(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x500384,4294967295);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32850(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(1,r32(0x5363b0),"<"));
  check(cCompare(r32(0x500384),cNeg(1),"=="));
  return;
}

function command32851(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x500384,90);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32851(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(1,r32(0x5363b0),"<"));
  check(cCompare(r32(0x500384),90,"=="));
  return;
}

function command32842(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w64(0x4fe938,cSub(r64(0x4fe938),r64(0x4cc580)));
  w32(0x511624,0);
  w32(0x4f6a6c,0);
  w32(0x4fbbac,0);
  w32(0x4f7094,0);
  w32(0x5356b4,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32842(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(1,r32(0x5363b0),"<"));
  return;
}

function command32841(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w64(0x4fe938,cSub(r64(0x4fe938),r64(0x4cc588)));
  w32(0x511624,0);
  w32(0x4f6a6c,0);
  w32(0x4fbbac,0);
  w32(0x4f7094,0);
  w32(0x5356b4,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32841(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(1,r32(0x5363b0),"<"));
  return;
}

function command32843(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4f7094,4294967295);
  w32(0x5359e4,0);
  w32(0x511624,0);
  w32(0x4f6a6c,0);
  w32(0x4fbbac,0);
  w32(0x5356b4,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32843(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(1,r32(0x5363b0),"<"));
  if (cTruth((cTruth(cCompare(r32(0x511624),1,"==")) && cTruth(cCompare(r32(0x5359e4),11,"<"))))) {
    check(1);
    return;
  }
  check(0);
  return;
}

function command32849(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4fbbac,cAdd(cCompare(90,r32(0x4feccc),"<"),2));
  w32(0x511624,0);
  w32(0x4f6a6c,0);
  w32(0x4f7094,0);
  w32(0x5356b4,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32849(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(1,r32(0x5363b0),"<"));
  return;
}

function command32845(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5359e4,5);
  w32(0x511624,1);
  w32(0x4f6a6c,0);
  w32(0x4fbbac,0);
  w32(0x4f7094,0);
  w32(0x5356b4,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32845(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  (uVar2 = cI32(1));
  if (cTruth((cTruth(cCompare(r32(0x5363b0),2,"<")) || cTruth(cCompare(r32(0x511624),1,"<"))))) {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x5359e4),5,"=="));
  return;
}

function command32847(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5356b4,1);
  w32(0x511624,0);
  w32(0x4f6a6c,0);
  w32(0x4fbbac,0);
  w32(0x5363b4,0);
  invalidate(0);
  w32(0x4f7094,0);
  return;
}

function update32847(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(1,r32(0x5363b0),"<"));
  return;
}

function command32844(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5359e4,4294967291);
  w32(0x511624,1);
  w32(0x4f6a6c,0);
  w32(0x4fbbac,0);
  w32(0x4f7094,0);
  w32(0x5356b4,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32844(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  (uVar2 = cI32(1));
  if (cTruth((cTruth(cCompare(r32(0x5363b0),2,"<")) || cTruth(cCompare(r32(0x511624),1,"<"))))) {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x5359e4),cNeg(5),"=="));
  return;
}

function command32846(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4f7094,1);
  w32(0x4f4a74,1);
  w32(0x4f4354,r32(0x4f8cd0));
  w32(0x5356b4,0);
  w32(0x511624,0);
  w32(0x4f6a6c,0);
  w32(0x4fbbac,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32846(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(1,r32(0x5363b0),"<"));
  return;
}

function command32848(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4fbbac,1);
  w32(0x511624,0);
  w32(0x4f6a6c,0);
  w32(0x4f7094,0);
  w32(0x5356b4,0);
  w32(0x4f3f64,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32848(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(1,r32(0x5363b0),"<"));
  check(cCompare(r32(0x4fbbac),1,"=="));
  return;
}

function command32872(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da174,1);
  updateSpeedDivisor(memory);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32872(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(1);
  check(cCompare(r32(0x4da174),1,"=="));
  return;
}

function command32873(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da174,2);
  updateSpeedDivisor(memory);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32873(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(1);
  check(cCompare(r32(0x4da174),2,"=="));
  return;
}

function command32874(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da174,3);
  updateSpeedDivisor(memory);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32874(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(1);
  check(cCompare(r32(0x4da174),3,"=="));
  return;
}

function command32875(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da174,4);
  updateSpeedDivisor(memory);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32875(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(1);
  check(cCompare(r32(0x4da174),4,"=="));
  return;
}

function command32876(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da174,5);
  updateSpeedDivisor(memory);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32876(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(1);
  check(cCompare(r32(0x4da174),5,"=="));
  return;
}

function command32877(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da174,6);
  updateSpeedDivisor(memory);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32877(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(1);
  check(cCompare(r32(0x4da174),6,"=="));
  return;
}

function command32878(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da174,7);
  updateSpeedDivisor(memory);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32878(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(1);
  check(cCompare(r32(0x4da174),7,"=="));
  return;
}

function command32879(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da174,8);
  updateSpeedDivisor(memory);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32879(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(1);
  check(cCompare(r32(0x4da174),8,"=="));
  return;
}

function command32880(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da174,9);
  updateSpeedDivisor(memory);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32880(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(1);
  check(cCompare(r32(0x4da174),9,"=="));
  return;
}

function command32909(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da174,10);
  updateSpeedDivisor(memory);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32909(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(1);
  check(cCompare(r32(0x4da174),10,"=="));
  return;
}

function command32833(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x512d64,4294967295);
  w32(0x4f49a4,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32833(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(0,r32(0x5363b0),"<"));
  check(cCompare(r32(0x512d64),cNeg(1),"=="));
  return;
}

function command32832(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x512d64,1);
  w32(0x4f49a4,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32832(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(0,r32(0x5363b0),"<"));
  check(cCompare(r32(0x512d64),1,"=="));
  return;
}

function command32852(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x500384,cAdd(r32(0x500384),cNeg(20)));
  if (cTruth(cCompare(r32(0x500384),0,"<"))) {
    w32(0x500384,cNeg(1));
  }
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32852(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(0,r32(0x5363b0),"<"));
  return;
}

function command32853(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x500384,cAdd(r32(0x500384),20));
  if (cTruth(cCompare(90,r32(0x500384),"<"))) {
    w32(0x500384,90);
  }
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32853(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(0,r32(0x5363b0),"<"));
  return;
}

function command32859(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4f7ee4,1);
  w32(0x4f4520,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32859(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth((cTruth(cCompare(r32(0x4da190),7,"<")) || cTruth(cCompare(8,r32(0x4da190),"<")))) || cTruth(cCompare(r32(0x5364c8),0,"!="))))) {
    (uVar2 = cI32(0));
  } else {
    (uVar2 = cI32(1));
  }
  enable(uVar2);
  if (cTruth((cTruth((cTruth(cCompare(r32(0x4f7ee4),1,"==")) && cTruth(cCompare(6,r32(0x4da190),"<")))) && cTruth((cTruth(cCompare(r32(0x4da190),9,"<")) && cTruth(cCompare(r32(0x5364c8),0,"=="))))))) {
    check(1);
    return;
  }
  check(0);
  return;
}

function command32860(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4f7ee4,2);
  w32(0x4f4520,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32860(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth((cTruth((cTruth(cCompare(r32(0x4da190),7,"<")) || cTruth(cCompare(8,r32(0x4da190),"<")))) || cTruth(cCompare(r32(0x4da140),1,"!=")))) || cTruth(cCompare(r32(0x5364c8),0,"!="))))) {
    (uVar2 = cI32(0));
  } else {
    (uVar2 = cI32(1));
  }
  enable(uVar2);
  if (cTruth((cTruth((cTruth(cCompare(r32(0x4f7ee4),2,"==")) && cTruth(cCompare(6,r32(0x4da190),"<")))) && cTruth((cTruth(cCompare(r32(0x4da190),9,"<")) && cTruth(cCompare(r32(0x5364c8),0,"=="))))))) {
    check(1);
    return;
  }
  check(0);
  return;
}

function command32861(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4f7ee4,3);
  w32(0x4f4520,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32861(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth((cTruth((cTruth(cCompare(r32(0x4da190),7,"<")) || cTruth(cCompare(8,r32(0x4da190),"<")))) || cTruth(cCompare(r32(0x4da140),1,"!=")))) || cTruth(cCompare(r32(0x5364c8),0,"!="))))) {
    (uVar2 = cI32(0));
  } else {
    (uVar2 = cI32(1));
  }
  enable(uVar2);
  if (cTruth((cTruth((cTruth(cCompare(r32(0x4f7ee4),3,"==")) && cTruth(cCompare(6,r32(0x4da190),"<")))) && cTruth((cTruth(cCompare(r32(0x4da190),9,"<")) && cTruth((cTruth(cCompare(r32(0x4da140),1,"==")) && cTruth(cCompare(r32(0x5364c8),0,"=="))))))))) {
    check(1);
    return;
  }
  check(0);
  return;
}

function command32856(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4fe77c,3);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32856(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5364c8),0,"=="));
  if (cTruth((cTruth(cCompare(r32(0x4fe77c),3,"==")) && cTruth(cCompare(r32(0x5364c8),0,"=="))))) {
    check(1);
    return;
  }
  check(0);
  return;
}

function command32854(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4fe77c,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32854(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  enable(cCompare(r32(0x5364c8),0,"=="));
  (uVar2 = cI32(1));
  if (cTruth((cTruth(cCompare(r32(0x4fe77c),1,"!=")) || cTruth(cCompare(r32(0x5364c8),0,"!="))))) {
    (uVar2 = cI32(0));
  }
  check(uVar2);
  return;
}

function command32855(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4fe77c,2);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32855(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5364c8),0,"=="));
  if (cTruth((cTruth(cCompare(r32(0x4fe77c),2,"==")) && cTruth(cCompare(r32(0x5364c8),0,"=="))))) {
    check(1);
    return;
  }
  check(0);
  return;
}

function command32858(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4f4520,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32858(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth((cTruth(cCompare(r32(0x4da190),2,"<")) || cTruth(cCompare(r32(0x4da190),9,"==")))) || cTruth(cCompare(r32(0x5364c8),0,"!="))))) {
    (uVar2 = cI32(0));
  } else {
    (uVar2 = cI32(1));
  }
  enable(uVar2);
  if (cTruth((cTruth((cTruth(cCompare(r32(0x4f4520),0,"==")) && cTruth(cCompare(1,r32(0x4da190),"<")))) && cTruth((cTruth(cCompare(r32(0x4da190),9,"!=")) && cTruth(cCompare(r32(0x5364c8),0,"=="))))))) {
    check(1);
    return;
  }
  check(0);
  return;
}

function command32857(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4f4520,cAdd(r32(0x4f4520),1));
  if (cTruth(cCompare(1,r32(0x4f4520),"<"))) {
    w32(0x4f4520,0);
  }
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32857(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth((cTruth(cCompare(r32(0x4da190),2,"<")) || cTruth(cCompare(r32(0x4da190),9,"==")))) || cTruth(cCompare(r32(0x5364c8),0,"!="))))) {
    (uVar2 = cI32(0));
  } else {
    (uVar2 = cI32(1));
  }
  enable(uVar2);
  if (cTruth((cTruth((cTruth(cCompare(r32(0x4f4520),1,"==")) && cTruth(cCompare(1,r32(0x4da190),"<")))) && cTruth((cTruth(cCompare(r32(0x4da190),9,"!=")) && cTruth(cCompare(r32(0x5364c8),0,"=="))))))) {
    check(1);
    return;
  }
  check(0);
  return;
}

function command32910(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x53642c,cAdd(r32(0x53642c),1));
  if (cTruth(cCompare(1,r32(0x53642c),"<"))) {
    w32(0x53642c,0);
  }
  if (cTruth(cCompare(r32(0x53642c),0,"=="))) {
    w32(0x5363b4,r32(0x53642c));
    invalidate(0);
    return;
  }
  w32(0x5363b4,1);
  return;
}

function update32910(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(1,r32(0x5363b0),"<"));
  check(cCompare(r32(0x53642c),1,"=="));
  return;
}

function command32902(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
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
  return;
}

function update32902(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(0,r32(0x5363b0),"<"));
  check(cCompare(r32(0x536434),1,"=="));
  return;
}

function command32903(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  if (cTruth(cCompare(r32(0x5359d0),0,"!="))) {
    w32(0x536438,cAdd(r32(0x536438),1));
    if (cTruth(cCompare(1,r32(0x536438),"<"))) {
      w32(0x536438,0);
    }
    w32(0x536434,0);
    w32(0x5233a8,0);
    w32(0x5363f0,0);
    w32(0x536404,0);
    w32(0x536444,0);
    w32(0x5363b4,0);
    invalidate(0);
  }
  return;
}

function update32903(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),1,"<")) || cTruth(cCompare(r32(0x5359d0),0,"=="))))) {
    (uVar2 = cI32(0));
  } else {
    (uVar2 = cI32(1));
  }
  enable(uVar2);
  check(cCompare(r32(0x536438),1,"=="));
  return;
}

function command32904(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,0);
  w32(0x536404,cAdd(r32(0x536404),1));
  invalidate(0);
  return;
}

function update32904(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar1;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),1,"<")) || cTruth(((uVar1 = cI32(1)), cCompare(r32(0x536438),1,"!=")))))) {
    (uVar1 = cI32(0));
  }
  enable(uVar1);
  return;
}

function command32912(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4f71c4,cAdd(r32(0x4f71c4),1));
  if (cTruth(cCompare(3,r32(0x4f71c4),"<"))) {
    w32(0x4f71c4,1);
  }
  w32(0x523a5c,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32912(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(0,r32(0x5363b0),"<"));
  return;
}

function command32834(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x512d64,100);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32834(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x4da140),2,"==")) || cTruth(cCompare(r32(0x4da194),2,"=="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x512d64),100,"=="));
  return;
}

function command32913(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4f41f4,cAdd(r32(0x4f41f4),1));
  if (cTruth(cCompare(1,r32(0x4f41f4),"<"))) {
    w32(0x4f41f4,0);
  }
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32913(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(0,r32(0x5363b0),"<"));
  check(cCompare(r32(0x4f41f4),1,"=="));
  return;
}

function command32914(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x525a7c,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32914(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(0,r32(0x5363b0),"<"));
  check(cCompare(r32(0x525a7c),1,"=="));
  return;
}

function command32916(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x525a7c,2);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32916(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(0,r32(0x5363b0),"<"));
  check(cCompare(r32(0x525a7c),2,"=="));
  return;
}

function command32919(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x53641c,cAdd(r32(0x53641c),1));
  if (cTruth(cCompare(1,r32(0x53641c),"<"))) {
    w32(0x53641c,0);
  }
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32919(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(0,r32(0x5363b0),"<"));
  check(cCompare(r32(0x53641c),1,"=="));
  return;
}

function command32918(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da184,cAdd(r32(0x4da184),1));
  if (cTruth(cCompare(1,r32(0x4da184),"<"))) {
    w32(0x4da184,0);
  }
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32918(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(0,r32(0x5363b0),"<"));
  check(cCompare(r32(0x4da184),1,"=="));
  return;
}

function update32905(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(0,r32(0x5363b0),"<"));
  check(cCompare(r32(0x5233a8),1,"=="));
  return;
}

function command32915(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x525a7c,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32915(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(0,r32(0x5363b0),"<"));
  check(cCompare(r32(0x525a7c),0,"=="));
  return;
}

function command32862(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,0);
  w32(0x536444,1);
  w32(0x536448,1);
  invalidate(0);
  return;
}

function update32862(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(cNeg(1),r32(0x5363b0),"<"));
  check(cCompare(r32(0x536444),1,"=="));
  return;
}

function command32924(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,0);
  w32(0x536444,2);
  w32(0x536448,2);
  invalidate(0);
  return;
}

function update32924(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth((cTruth((cTruth(cCompare(r32(0x5363b0),2,"<")) || cTruth(cCompare(r32(0x5233a8),0,"!=")))) || cTruth(cCompare(r32(0x536438),0,"!=")))) || cTruth(cCompare(r32(0x5363f0),0,"!="))))) {
    (uVar2 = cI32(0));
  } else {
    (uVar2 = cI32(1));
  }
  enable(uVar2);
  check(cCompare(r32(0x536444),2,"=="));
  return;
}

function command32864(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,0);
  w32(0x536444,3);
  w32(0x536448,3);
  invalidate(0);
  return;
}

function update32864(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(cNeg(1),r32(0x5363b0),"<"));
  check(cCompare(r32(0x536444),3,"=="));
  return;
}

function command32865(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,0);
  w32(0x536444,4);
  w32(0x536448,4);
  invalidate(0);
  return;
}

function update32865(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(cNeg(1),r32(0x5363b0),"<"));
  check(cCompare(r32(0x536444),4,"=="));
  return;
}

function command32866(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,0);
  w32(0x536444,5);
  w32(0x536448,5);
  invalidate(0);
  return;
}

function update32866(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(cNeg(1),r32(0x5363b0),"<"));
  check(cCompare(r32(0x536444),5,"=="));
  return;
}

function command32835(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x523a5c,cAdd(r32(0x523a5c),1));
  if (cTruth(cCompare(1,r32(0x523a5c),"<"))) {
    w32(0x523a5c,0);
  }
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32835(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(cNeg(1),r32(0x5363b0),"<"));
  check(cCompare(r32(0x523a5c),1,"=="));
  return;
}

function command32925(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,0);
  w32(0x536444,6);
  w32(0x536448,6);
  invalidate(0);
  return;
}

function update32925(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(cNeg(1),r32(0x5363b0),"<"));
  check(cCompare(r32(0x536444),6,"=="));
  return;
}

function command32927(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x536454,cAdd(r32(0x536454),1));
  if (cTruth(cCompare(1,r32(0x536454),"<"))) {
    w32(0x536454,0);
  }
  w32(0x536450,cI32(cCompare(r32(0x536454),1,"=="),true));
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32927(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth((cTruth(cCompare(r32(0x4da190),7,"==")) || cTruth(cCompare(r32(0x513478),1,"=="))))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x536454),1,"=="));
  return;
}

function command32928(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,1);
  w32(0x536444,101);
  w32(0x536448,101);
  invalidate(0);
  return;
}

function update32928(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(cNeg(1),r32(0x5363b0),"<"));
  check(cCompare(r32(0x536444),101,"=="));
  return;
}

function command32929(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x536444,103);
  w32(0x536448,103);
  invalidate(0);
  w32(0x4fb9b4,0);
  w32(0x5363b4,1);
  return;
}

function update32929(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"<")) || cTruth(cCompare(r32(0x4da16c),0,"!="))))) {
    (uVar2 = cI32(0));
  } else {
    (uVar2 = cI32(1));
  }
  enable(uVar2);
  check(cCompare(r32(0x536444),103,"=="));
  return;
}

function command32931(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x536444,102);
  w32(0x536448,102);
  invalidate(0);
  w32(0x4fb9b4,0);
  w32(0x5363b4,1);
  return;
}

function update32931(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(cNeg(1),r32(0x5363b0),"<"));
  check(cCompare(r32(0x536444),102,"=="));
  return;
}

function command32930(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,1);
  w32(0x536444,104);
  w32(0x536448,104);
  invalidate(0);
  w32(0x4fb9b4,0);
  return;
}

function update32930(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"<")) || cTruth(cCompare(r32(0x4da16c),0,"!="))))) {
    (uVar2 = cI32(0));
  } else {
    (uVar2 = cI32(1));
  }
  enable(uVar2);
  check(cCompare(r32(0x536444),104,"=="));
  return;
}

function command32932(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,1);
  w32(0x536444,105);
  w32(0x536448,105);
  invalidate(0);
  w32(0x4fb9b4,0);
  return;
}

function update32932(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"<")) || cTruth(cCompare(r32(0x4da16c),0,"!="))))) {
    (uVar2 = cI32(0));
  } else {
    (uVar2 = cI32(1));
  }
  enable(uVar2);
  check(cCompare(r32(0x536444),105,"=="));
  return;
}

function command32933(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,1);
  w32(0x536444,106);
  w32(0x536448,106);
  invalidate(0);
  w32(0x4fb9b4,0);
  return;
}

function update32933(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"<")) || cTruth(cCompare(r32(0x4da16c),0,"!="))))) {
    (uVar2 = cI32(0));
  } else {
    (uVar2 = cI32(1));
  }
  enable(uVar2);
  check(cCompare(r32(0x536444),106,"=="));
  return;
}

function command32934(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,1);
  w32(0x536444,107);
  w32(0x536448,107);
  invalidate(0);
  w32(0x4fb9b4,0);
  return;
}

function update32934(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"<")) || cTruth(cCompare(r32(0x4da16c),0,"!="))))) {
    (uVar2 = cI32(0));
  } else {
    (uVar2 = cI32(1));
  }
  enable(uVar2);
  check(cCompare(r32(0x536444),107,"=="));
  return;
}

function command32935(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,1);
  w32(0x536444,108);
  w32(0x536448,108);
  invalidate(0);
  w32(0x4fb9b4,0);
  return;
}

function update32935(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"<")) || cTruth(cCompare(r32(0x4da16c),0,"!="))))) {
    (uVar2 = cI32(0));
  } else {
    (uVar2 = cI32(1));
  }
  enable(uVar2);
  check(cCompare(r32(0x536444),108,"=="));
  return;
}

function command32936(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,1);
  w32(0x536444,109);
  w32(0x536448,109);
  invalidate(0);
  w32(0x4fb9b4,0);
  return;
}

function update32936(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"<")) || cTruth(cCompare(r32(0x4da16c),0,"!="))))) {
    (uVar2 = cI32(0));
  } else {
    (uVar2 = cI32(1));
  }
  enable(uVar2);
  check(cCompare(r32(0x536444),109,"=="));
  return;
}

function command32937(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,1);
  w32(0x536444,110);
  w32(0x536448,110);
  invalidate(0);
  w32(0x4fb9b4,0);
  return;
}

function update32937(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"<")) || cTruth(cCompare(r32(0x4da16c),0,"!="))))) {
    (uVar2 = cI32(0));
  } else {
    (uVar2 = cI32(1));
  }
  enable(uVar2);
  check(cCompare(r32(0x536444),110,"=="));
  return;
}

function command32923(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  if (cTruth(cCompare(r32(0x536448),300,"!="))) {
    w32(0x536444,300);
    w32(0x536448,300);
    w32(0x5363f0,0);
    w32(0x5363b4,0);
    invalidate(0);
    return;
  }
  w32(0x536444,0);
  w32(0x536448,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32923(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth((cTruth(cCompare(r32(0x5363b0),2,"<")) || cTruth(((uVar2 = cI32(1)), cCompare(r32(0x4da140),1,"!="))))) || cTruth(cCompare(10,r32(0x4da198),"<"))))) {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x536444),300,"=="));
  return;
}

function command32938(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x53645c,cAdd(r32(0x53645c),1));
  if (cTruth(cCompare(1,r32(0x53645c),"<"))) {
    w32(0x53645c,0);
  }
  return;
}

function update32938(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x53645c),1,"=="));
  return;
}

function command32939(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,1);
  w32(0x536444,400);
  w32(0x536448,400);
  invalidate(0);
  w32(0x4fb9b4,0);
  return;
}

function update32939(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth((cTruth(cCompare(r32(0x5363b0),0,"<")) || cTruth(cCompare(r32(0x5363fc),1,"<")))) || cTruth(cCompare(r32(0x536424),0,"!="))))) {
    (uVar2 = cI32(0));
  } else {
    (uVar2 = cI32(1));
  }
  enable(uVar2);
  check(cCompare(r32(0x536444),400,"=="));
  return;
}

function command32940(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,1);
  w32(0x536444,501);
  w32(0x536448,501);
  invalidate(0);
  w32(0x4fb9b4,0);
  return;
}

function update32940(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(cNeg(1),r32(0x5363b0),"<"));
  check(cCompare(r32(0x536444),501,"=="));
  return;
}

function command32941(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,1);
  w32(0x536444,502);
  w32(0x536448,502);
  invalidate(0);
  w32(0x4fb9b4,0);
  return;
}

function update32941(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(cNeg(1),r32(0x5363b0),"<"));
  check(cCompare(r32(0x536444),502,"=="));
  return;
}

function command32942(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,1);
  w32(0x536444,503);
  w32(0x536448,503);
  invalidate(0);
  w32(0x4fb9b4,0);
  return;
}

function update32942(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"<")) || cTruth(cCompare(r32(0x4da16c),0,"!="))))) {
    (uVar2 = cI32(0));
  } else {
    (uVar2 = cI32(1));
  }
  enable(uVar2);
  check(cCompare(r32(0x536444),503,"=="));
  return;
}

function command32943(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,1);
  w32(0x536444,504);
  w32(0x536448,504);
  invalidate(0);
  w32(0x4fb9b4,0);
  return;
}

function update32943(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"<")) || cTruth(cCompare(r32(0x4da16c),0,"!="))))) {
    (uVar2 = cI32(0));
  } else {
    (uVar2 = cI32(1));
  }
  enable(uVar2);
  check(cCompare(r32(0x536444),504,"=="));
  return;
}

function command32955(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,1);
  w32(0x536444,505);
  w32(0x536448,505);
  invalidate(0);
  w32(0x4fb9b4,0);
  return;
}

function update32955(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"<")) || cTruth(cCompare(r32(0x4da16c),0,"!="))))) {
    (uVar2 = cI32(0));
  } else {
    (uVar2 = cI32(1));
  }
  enable(uVar2);
  check(cCompare(r32(0x536444),505,"=="));
  return;
}

function command32944(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,1);
  w32(0x536444,506);
  w32(0x536448,506);
  invalidate(0);
  w32(0x4fb9b4,0);
  return;
}

function update32944(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"<")) || cTruth(cCompare(r32(0x4da16c),0,"!="))))) {
    (uVar2 = cI32(0));
  } else {
    (uVar2 = cI32(1));
  }
  enable(uVar2);
  check(cCompare(r32(0x536444),506,"=="));
  return;
}

function command32945(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,1);
  w32(0x536444,507);
  w32(0x536448,507);
  invalidate(0);
  w32(0x4fb9b4,0);
  return;
}

function update32945(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"<")) || cTruth(cCompare(r32(0x4da16c),0,"!="))))) {
    (uVar2 = cI32(0));
  } else {
    (uVar2 = cI32(1));
  }
  enable(uVar2);
  check(cCompare(r32(0x536444),507,"=="));
  return;
}

function command32954(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,1);
  w32(0x536444,508);
  w32(0x536448,508);
  invalidate(0);
  w32(0x4fb9b4,0);
  return;
}

function update32954(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"<")) || cTruth(cCompare(r32(0x4da16c),0,"!="))))) {
    (uVar2 = cI32(0));
  } else {
    (uVar2 = cI32(1));
  }
  enable(uVar2);
  check(cCompare(r32(0x536444),508,"=="));
  return;
}

function command32946(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,1);
  w32(0x536444,509);
  w32(0x536448,509);
  invalidate(0);
  w32(0x4fb9b4,0);
  return;
}

function update32946(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"<")) || cTruth(cCompare(r32(0x4da16c),0,"!="))))) {
    (uVar2 = cI32(0));
  } else {
    (uVar2 = cI32(1));
  }
  enable(uVar2);
  check(cCompare(r32(0x536444),509,"=="));
  return;
}

function command32947(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,1);
  w32(0x536444,510);
  w32(0x536448,510);
  invalidate(0);
  w32(0x4fb9b4,0);
  return;
}

function update32947(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"<")) || cTruth(cCompare(r32(0x4da16c),0,"!="))))) {
    (uVar2 = cI32(0));
  } else {
    (uVar2 = cI32(1));
  }
  enable(uVar2);
  check(cCompare(r32(0x536444),510,"=="));
  return;
}

function command32948(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,1);
  w32(0x536444,511);
  w32(0x536448,511);
  invalidate(0);
  w32(0x4fb9b4,0);
  return;
}

function update32948(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"<")) || cTruth(cCompare(r32(0x4da16c),0,"!="))))) {
    (uVar2 = cI32(0));
  } else {
    (uVar2 = cI32(1));
  }
  enable(uVar2);
  check(cCompare(r32(0x536444),511,"=="));
  return;
}

function command32949(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,1);
  w32(0x536444,512);
  w32(0x536448,512);
  invalidate(0);
  w32(0x4fb9b4,0);
  return;
}

function update32949(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"<")) || cTruth(cCompare(r32(0x4da16c),0,"!="))))) {
    (uVar2 = cI32(0));
  } else {
    (uVar2 = cI32(1));
  }
  enable(uVar2);
  check(cCompare(r32(0x536444),512,"=="));
  return;
}

function command32950(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,1);
  w32(0x536444,513);
  w32(0x536448,513);
  invalidate(0);
  w32(0x4fb9b4,0);
  return;
}

function update32950(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"<")) || cTruth(cCompare(r32(0x4da16c),0,"!="))))) {
    (uVar2 = cI32(0));
  } else {
    (uVar2 = cI32(1));
  }
  enable(uVar2);
  check(cCompare(r32(0x536444),513,"=="));
  return;
}

function command32951(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,1);
  w32(0x536444,514);
  w32(0x536448,514);
  invalidate(0);
  w32(0x4fb9b4,0);
  return;
}

function update32951(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"<")) || cTruth(cCompare(r32(0x4da16c),0,"!="))))) {
    (uVar2 = cI32(0));
  } else {
    (uVar2 = cI32(1));
  }
  enable(uVar2);
  check(cCompare(r32(0x536444),514,"=="));
  return;
}

function command32926(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,1);
  w32(0x536444,601);
  w32(0x536448,601);
  invalidate(0);
  w32(0x4fb9b4,0);
  return;
}

function update32926(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"<")) || cTruth(cCompare(r32(0x4da16c),0,"!="))))) {
    (uVar2 = cI32(0));
  } else {
    (uVar2 = cI32(1));
  }
  enable(uVar2);
  check(cCompare(r32(0x536444),601,"=="));
  return;
}

function command32956(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,1);
  w32(0x536444,701);
  w32(0x536448,701);
  invalidate(0);
  w32(0x4fb9b4,0);
  return;
}

function update32956(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"<")) || cTruth(cCompare(r32(0x4da16c),0,"!="))))) {
    (uVar2 = cI32(0));
  } else {
    (uVar2 = cI32(1));
  }
  enable(uVar2);
  check(cCompare(r32(0x536444),701,"=="));
  return;
}

function command32898(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  if (cTruth((cTruth((cTruth(cCompare(r32(0x5233a8),1,"==")) || cTruth(cCompare(r32(0x536434),1,"==")))) || cTruth(cCompare(r32(0x536438),1,"=="))))) {
    w32(0x4da200,0);
  } else {
    w32(0x50f6d4,cDiv(r32(0x50f6d4),2));
    if (cTruth(cCompare(r32(0x50f6d4),2,"<"))) {
      w32(0x50f6d4,2);
    }
  }
  invalidate(0);
  w32(0x5363b4,0);
  return;
}

function update32898(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(0,r32(0x5363b0),"<"));
  return;
}

function command32899(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  if (cTruth((cTruth((cTruth(cCompare(r32(0x5233a8),1,"==")) || cTruth(cCompare(r32(0x536434),1,"==")))) || cTruth(cCompare(r32(0x536438),1,"=="))))) {
    w32(0x4da200,1);
  } else {
    w32(0x50f6d4,cMul(r32(0x50f6d4),2));
    if (cTruth(cCompare(r32(0x4fe770),r32(0x50f6d4),"<"))) {
      w32(0x50f6d4,r32(0x4fe770));
    }
  }
  invalidate(0);
  w32(0x5363b4,0);
  return;
}

function update32899(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(0,r32(0x5363b0),"<"));
  return;
}

function command32911(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4fe77c,cAdd(r32(0x4fe77c),1));
  if (cTruth(cCompare(3,r32(0x4fe77c),"<"))) {
    w32(0x4fe77c,1);
  }
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32911(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  if (cTruth((cTruth(cCompare(r32(0x5363bc),0,"==")) && cTruth(cCompare(r32(0x5364c8),0,"=="))))) {
    enable(1);
    return;
  }
  enable(0);
  return;
}

function command32868(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,0);
  w32(0x536444,7);
  w32(0x536448,7);
  invalidate(0);
  return;
}

function update32868(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(cNeg(1),r32(0x5363b0),"<"));
  check(cCompare(r32(0x536444),7,"=="));
  return;
}

function command32869(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,0);
  w32(0x536444,8);
  w32(0x536448,8);
  invalidate(0);
  return;
}

function update32869(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(cNeg(1),r32(0x5363b0),"<"));
  check(cCompare(r32(0x536444),8,"=="));
  return;
}

function command32957(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x536480,cAdd(r32(0x536480),1));
  if (cTruth(cCompare(1,r32(0x536480),"<"))) {
    w32(0x536480,0);
  }
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32957(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth((cTruth(cCompare(r32(0x5363b0),0,"<")) || cTruth(cCompare(r32(0x5363e4),0,"!=")))) || cTruth(cCompare(r64(0x4da230),r64(0x4cc658),"!="))))) {
    (uVar2 = cI32(0));
  } else {
    (uVar2 = cI32(1));
  }
  enable(uVar2);
  check(cCompare(r32(0x536480),1,"=="));
  return;
}

function command32960(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363fc,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32960(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x5363fc),0,"=="));
  return;
}

function command32958(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363e4,cAdd(r32(0x5363e4),1));
  if (cTruth(cCompare(1,r32(0x5363e4),"<"))) {
    w32(0x5363e4,0);
  }
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32958(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(cNeg(1),r32(0x5363b0),"<"));
  check(cCompare(r32(0x5363e4),1,"=="));
  return;
}

function command32961(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f8,0);
  w32(0x4da19c,11);
  return;
}

function update32961(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da19c),11,"=="));
  return;
}

function command32962(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1a8,cAdd(r32(0x4da1a8),1));
  if (cTruth(cCompare(1,r32(0x4da1a8),"<"))) {
    w32(0x4da1a8,0);
  }
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32962(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth((cTruth(cCompare(r32(0x5363b0),0,"<")) || cTruth(cCompare(r32(0x4da140),1,"!=")))) || cTruth(cCompare(r32(0x536478),0,"!="))))) {
    (uVar2 = cI32(0));
  } else {
    (uVar2 = cI32(1));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da1a8),1,"=="));
  return;
}

function command32963(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1ac,cAdd(r32(0x4da1ac),1));
  if (cTruth(cCompare(1,r32(0x4da1ac),"<"))) {
    w32(0x4da1ac,0);
  }
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32963(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"<")) || cTruth(cCompare(r32(0x5363e4),0,"!="))))) {
    (uVar2 = cI32(0));
  } else {
    (uVar2 = cI32(1));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da1ac),1,"=="));
  return;
}

function command32964(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da19c,8);
  w32(0x4da1f8,0);
  w32(0x5363f8,0);
  w32(0x53640c,0);
  w32(0x4f8b78,1);
  w32(0x4da1e8,0);
  w32(0x53527c,0);
  w32(0x536408,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32964(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x4da190),7,"==")))) && cTruth(cCompare(r32(0x536470),0,"=="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  if (cTruth((cTruth(cCompare(r32(0x4da19c),8,"==")) && cTruth(cCompare(r32(0x4f8b78),1,"=="))))) {
    check(1);
    return;
  }
  check(0);
  return;
}

function command32965(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x536498,cAdd(r32(0x536498),1));
  if (cTruth(cCompare(1,r32(0x536498),"<"))) {
    w32(0x536498,0);
  }
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32965(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(1);
  check(cCompare(r32(0x536498),1,"=="));
  return;
}

function command32966(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x536484,cAdd(r32(0x536484),1));
  if (cTruth(cCompare(1,r32(0x536484),"<"))) {
    w32(0x536484,0);
  }
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32966(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(1);
  check(cCompare(r32(0x536484),1,"=="));
  return;
}

function command32967(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1b0,cAdd(r32(0x4da1b0),1));
  if (cTruth(cCompare(1,r32(0x4da1b0),"<"))) {
    w32(0x4da1b0,0);
  }
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32967(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x4da140),1,"=="));
  if (cTruth((cTruth(cCompare(r32(0x4da1b0),1,"==")) && cTruth(cCompare(r32(0x4da140),1,"=="))))) {
    check(1);
    return;
  }
  check(0);
  return;
}

function command32968(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5364ac,cAdd(r32(0x5364ac),1));
  if (cTruth(cCompare(1,r32(0x5364ac),"<"))) {
    w32(0x5364ac,0);
  }
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32968(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x4da1cc),0,"<")) || cTruth(cCompare(r32(0x5363f4),0,"!="))))) {
    (uVar2 = cI32(0));
  } else {
    (uVar2 = cI32(1));
  }
  enable(uVar2);
  check(cCompare(r32(0x5364ac),1,"=="));
  return;
}

function command32969(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da174,11);
  updateSpeedDivisor(memory);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32969(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(1);
  check(cCompare(r32(0x4da174),11,"=="));
  return;
}

function command32970(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da174,12);
  updateSpeedDivisor(memory);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32970(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(1);
  check(cCompare(r32(0x4da174),12,"=="));
  return;
}

function command32971(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da174,13);
  updateSpeedDivisor(memory);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32971(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(1);
  check(cCompare(r32(0x4da174),13,"=="));
  return;
}

function command32972(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da174,14);
  updateSpeedDivisor(memory);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32972(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(1);
  check(cCompare(r32(0x4da174),14,"=="));
  return;
}

function command32973(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da174,15);
  updateSpeedDivisor(memory);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32973(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(1);
  check(cCompare(r32(0x4da174),15,"=="));
  return;
}

function command32974(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  if (cTruth(cCompare(r32(0x4da174),15,"<"))) {
    w32(0x4da174,cAdd(r32(0x4da174),1));
  }
  updateSpeedDivisor(memory);
  w32(0x4da180,r32(0x4da174));
  w32(0x4da17c,r32(0x4da178));
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32974(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(1);
  return;
}

function command32975(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  if (cTruth(cCompare(1,r32(0x4da174),"<"))) {
    w32(0x4da174,cAdd(r32(0x4da174),cNeg(1)));
  }
  updateSpeedDivisor(memory);
  w32(0x4da180,r32(0x4da174));
  w32(0x4da17c,r32(0x4da178));
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32975(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(1);
  return;
}

function command32976(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da19c,12);
  w32(0x4da1f8,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32976(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da19c),12,"=="));
  return;
}

function command32977(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da19c,13);
  w32(0x4da1f8,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32977(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da19c),13,"=="));
  return;
}

function command32978(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da19c,14);
  w32(0x4da1f8,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32978(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da19c),14,"=="));
  return;
}

function command32979(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1d8,10);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32979(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(2,r32(0x4da194),"<"))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da1d8),10,"=="));
  return;
}

function command32980(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1d8,5);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32980(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da1d8),5,"=="));
  return;
}

function command32981(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1d8,2);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32981(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) || cTruth((cTruth(cCompare(r32(0x4f8cd0),r32(0x4f42b8),"==")) && cTruth(cCompare(r32(0x4da1d8),3,"<"))))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da1d8),2,"=="));
  return;
}

function command32982(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1d8,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32982(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) || cTruth((cTruth(cCompare(r32(0x4f8cd0),r32(0x4f42b8),"==")) && cTruth(cCompare(r32(0x4da1d8),3,"<"))))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da1d8),1,"=="));
  return;
}

function command32983(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363e0,cAdd(r32(0x5363e0),1));
  if (cTruth(cCompare(1,r32(0x5363e0),"<"))) {
    w32(0x5363e0,0);
  }
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32983(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(1);
  check(cCompare(r32(0x5363e0),1,"=="));
  return;
}

function command32984(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1dc,cAdd(r32(0x4da1dc),1));
  if (cTruth(cCompare(1,r32(0x4da1dc),"<"))) {
    w32(0x4da1dc,0);
  }
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32984(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x4da1ac),1,"=="));
  check(cCompare(r32(0x4da1dc),1,"=="));
  return;
}

function command32985(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da144,16);
  w32(0x5363b4,0);
  invalidate(1);
  return;
}

function update32985(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da144),16,"=="));
  return;
}

function command32986(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da144,17);
  w32(0x5363b4,0);
  invalidate(1);
  return;
}

function update32986(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da144),17,"=="));
  return;
}

function command32987(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da144,18);
  w32(0x5363b4,0);
  invalidate(1);
  return;
}

function update32987(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da144),18,"=="));
  return;
}

function command32988(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da144,19);
  w32(0x5363b4,0);
  invalidate(1);
  w32(0x4da14c,1);
  return;
}

function update32988(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da144),19,"=="));
  return;
}

function command32989(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  let iVar1;
  w32(0x4da144,20);
  w32(0x4da1f8,0);
  w32(0x5363b4,0);
  invalidate(1);
  w32(0x536498,1);
  w32(0x4da14c,1);
  w32(0x4da194,10);
  w32(0x4da1e8,0);
  (iVar1 = cI32(scaledRandom(100,options.rng)));
  w32(0x4da19c,cAdd(cCompare(iVar1,50,"<"),12));
  return;
}

function update32989(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da144),20,"=="));
  return;
}

function command32990(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4f3f64,4294967289);
  w32(0x5233a4,0);
  w32(0x4f6a6c,1);
  w32(0x4fbbac,0);
  w32(0x4f7094,0);
  w32(0x5356b4,0);
  w32(0x511624,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32990(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  (uVar2 = cI32(1));
  if (cTruth((cTruth(cCompare(r32(0x5363b0),2,"<")) || cTruth(cCompare(r32(0x4f6a6c),1,"!="))))) {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4f3f64),cNeg(7),"=="));
  return;
}

function command32991(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4f3f64,7);
  w32(0x5233a4,0);
  w32(0x4f6a6c,1);
  w32(0x4fbbac,0);
  w32(0x4f7094,0);
  w32(0x5356b4,0);
  w32(0x511624,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32991(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  (uVar2 = cI32(1));
  if (cTruth((cTruth(cCompare(r32(0x5363b0),2,"<")) || cTruth(cCompare(r32(0x4f6a6c),1,"!="))))) {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4f3f64),7,"=="));
  return;
}

function command32992(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da168,1);
  w32(0x5363f8,0);
  w32(0x536408,0);
  w32(0x4da188,6);
  w32(0x53527c,1);
  w32(0x4da1e8,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32992(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x4f8b78),0,"==")))) && cTruth(cCompare(r32(0x4da19c),8,"!="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da188),6,"=="));
  return;
}

function command32993(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da168,1);
  w32(0x5363f8,0);
  w32(0x536408,1);
  w32(0x4da188,7);
  w32(0x53527c,1);
  if (cTruth(cCompare(14,r32(0x4da194),"<"))) {
    w32(0x4da1e8,1);
  }
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32993(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x4f8b78),0,"==")))) && cTruth(cCompare(r32(0x4da19c),8,"!="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da188),7,"=="));
  return;
}

function command32994(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1e8,cAdd(r32(0x4da1e8),1));
  if (cTruth(cCompare(1,r32(0x4da1e8),"<"))) {
    w32(0x4da1e8,0);
  }
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32994(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth((cTruth((cTruth(cCompare(r32(0x4da194),16,"<")) || cTruth(cCompare(r32(0x5363b0),0,"!=")))) || cTruth(cCompare(r32(0x4da19c),8,"==")))) || cTruth((cTruth((cTruth(cCompare(2,r32(0x4da188),"<")) && cTruth(cCompare(r32(0x4da188),5,"!=")))) && cTruth(cCompare(r32(0x4da188),7,"!="))))))) {
    (uVar2 = cI32(0));
  } else {
    (uVar2 = cI32(1));
  }
  enable(uVar2);
  if (cTruth((cTruth((cTruth(cCompare(15,r32(0x4da194),"<")) && cTruth(cCompare(r32(0x4da1e8),1,"==")))) && cTruth((cTruth(cCompare(r32(0x4da19c),8,"!=")) && cTruth((cTruth((cTruth(cCompare(r32(0x4da188),3,"<")) || cTruth(cCompare(r32(0x4da188),5,"==")))) || cTruth(cCompare(r32(0x4da188),7,"=="))))))))) {
    check(1);
    return;
  }
  check(0);
  return;
}

function command32996(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f0,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32996(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da1f0),1,"=="));
  return;
}

function command32997(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f0,2);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32997(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da1f0),2,"=="));
  return;
}

function command32998(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f0,3);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32998(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da1f0),3,"=="));
  return;
}

function command32999(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f0,4);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update32999(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da1f0),4,"=="));
  return;
}

function command33000(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f0,5);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33000(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da1f0),5,"=="));
  return;
}

function command33001(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f0,6);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33001(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da1f0),6,"=="));
  return;
}

function command33002(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f0,7);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33002(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da1f0),7,"=="));
  return;
}

function command33003(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f0,8);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33003(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da1f0),8,"=="));
  return;
}

function command33004(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f0,9);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33004(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da1f0),9,"=="));
  return;
}

function command33005(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f0,10);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33005(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da1f0),10,"=="));
  return;
}

function command33006(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f0,11);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33006(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da1f0),11,"=="));
  return;
}

function command33007(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f0,12);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33007(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da1f0),12,"=="));
  return;
}

function command33010(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f0,13);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33010(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da1f0),13,"=="));
  return;
}

function command33008(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f0,14);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33008(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da1f0),14,"=="));
  return;
}

function command33009(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f0,15);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33009(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da1f0),15,"=="));
  return;
}

function command33011(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,0);
  w32(0x536444,10);
  w32(0x536448,10);
  invalidate(0);
  return;
}

function update33011(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(cNeg(1),r32(0x5363b0),"<"));
  check(cCompare(r32(0x536444),10,"=="));
  return;
}

function command33013(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x500384,cAdd(r32(0x500384),5));
  if (cTruth(cCompare(90,r32(0x500384),"<"))) {
    w32(0x500384,90);
  }
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33013(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(0,r32(0x5363b0),"<"));
  return;
}

function command33012(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x500384,cAdd(r32(0x500384),cNeg(5)));
  if (cTruth(cCompare(r32(0x500384),0,"<"))) {
    w32(0x500384,0);
  }
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33012(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(0,r32(0x5363b0),"<"));
  return;
}

function command33014(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f8,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33014(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da1f8),1,"=="));
  return;
}

function command33015(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f8,2);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33015(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da1f8),2,"=="));
  return;
}

function command33016(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f8,3);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33016(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da1f8),3,"=="));
  return;
}

function command33017(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f8,4);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33017(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da1f8),4,"=="));
  return;
}

function command33018(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f8,5);
  w32(0x5363b4,0);
  invalidate(0);
  w32(0x4da144,14);
  w32(0x4da190,7);
  w32(0x5363c0,0);
  w32(0x536408,0);
  return;
}

function update33018(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da1f8),5,"=="));
  return;
}

function command33019(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f8,7);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33019(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da1f8),7,"=="));
  return;
}

function command33020(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f8,10);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33020(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da1f8),10,"=="));
  return;
}

function command33021(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f8,6);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33021(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da1f8),6,"=="));
  return;
}

function command33022(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f8,9);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33022(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da1f8),9,"=="));
  return;
}

function command33023(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f8,11);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33023(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da1f8),11,"=="));
  return;
}

function command33024(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f8,12);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33024(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da1f8),12,"=="));
  return;
}

function command33025(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,0);
  w32(0x536444,11);
  w32(0x536448,11);
  invalidate(0);
  return;
}

function update33025(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(1);
  check(cCompare(r32(0x536444),11,"=="));
  return;
}

function command33026(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f8,103);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33026(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da1f8),103,"=="));
  return;
}

function command33027(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f8,105);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33027(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da1f8),105,"=="));
  return;
}

function command33028(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f8,104);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33028(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da1f8),104,"=="));
  return;
}

function command33029(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f8,100);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33029(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da1f8),100,"=="));
  return;
}

function command33030(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f8,101);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33030(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da1f8),101,"=="));
  return;
}

function command33031(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f8,106);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33031(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da1f8),106,"=="));
  return;
}

function command33032(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da1f8,102);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33032(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da1f8),102,"=="));
  return;
}

function command33033(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w64(0x4da230,cSub(r64(0x4da230),r64(0x4cc700)));
  if (cTruth(cCompare(r64(0x4cc650),r64(0x4da230),"<"))) {
    w64(0x4da230,Float80.fromNumber(0.0));
  }
  if (cTruth(cCompare(r64(0x4da230),r64(0x4cc650),"=="))) {
    w32(0x536480,0);
  }
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33033(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(1);
  if (cTruth(cCompare(r64(0x4da230),r64(0x4cc650),"=="))) {
    check(1);
    return;
  }
  check(0);
  return;
}

function command33034(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da238,2500);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33034(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da238),2500,"=="));
  return;
}

function command33035(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da238,2000);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33035(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da238),2000,"=="));
  return;
}

function command33036(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da238,1500);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33036(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da238),1500,"=="));
  return;
}

function command33037(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5364fc,1);
  w32(0x4da248,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33037(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da248),0,"=="));
  return;
}

function command33038(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,0);
  w32(0x4da248,1);
  w32(0x5364fc,1);
  invalidate(0);
  return;
}

function update33038(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da248),1,"=="));
  return;
}

function command33039(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da248,2);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33039(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da248),2,"=="));
  return;
}

function command33040(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5364fc,1);
  w32(0x4da23c,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33040(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da23c),0,"=="));
  return;
}

function command33041(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da23c,45);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33041(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da23c),45,"=="));
  return;
}

function command33042(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da23c,90);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33042(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da23c),90,"=="));
  return;
}

function command33043(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da23c,135);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33043(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da23c),135,"=="));
  return;
}

function command33044(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da23c,180);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33044(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da23c),180,"=="));
  return;
}

function command33045(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da23c,225);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33045(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da23c),225,"=="));
  return;
}

function command33046(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da23c,270);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33046(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da23c),270,"=="));
  return;
}

function command33047(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da23c,315);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33047(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da23c),315,"=="));
  return;
}

function command33048(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5364fc,1);
  w32(0x4da240,0);
  w32(0x4da244,0);
  w32(0x4da270,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33048(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  if (cTruth((cTruth(cCompare(r32(0x4da240),0,"==")) && cTruth(cCompare(r32(0x4da244),0,"=="))))) {
    check(1);
    return;
  }
  check(0);
  return;
}

function command33049(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da240,1);
  w32(0x4da244,1);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  w32(0x4da270,0);
  invalidate(0);
  return;
}

function update33049(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  enable(cCompare(r32(0x5363b0),0,"=="));
  (uVar2 = cI32(1));
  if (cTruth((cTruth(cCompare(r32(0x4da240),1,"!=")) || cTruth(cCompare(r32(0x4da244),1,"!="))))) {
    (uVar2 = cI32(0));
  }
  check(uVar2);
  return;
}

function command33050(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5364fc,1);
  w32(0x4da240,4294967295);
  w32(0x4da244,4294967295);
  w32(0x4da270,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33050(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  if (cTruth((cTruth(cCompare(r32(0x4da240),cNeg(1),"==")) && cTruth(cCompare(r32(0x4da244),cNeg(1),"=="))))) {
    check(1);
    return;
  }
  check(0);
  return;
}

function command33051(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da240,4294967295);
  w32(0x4da244,1);
  w32(0x4da270,1);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33051(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  enable(cCompare(r32(0x5363b0),0,"=="));
  if (cTruth((cTruth(cCompare(r32(0x4da240),cNeg(1),"!=")) || cTruth(((uVar2 = cI32(1)), cCompare(r32(0x4da244),1,"!=")))))) {
    (uVar2 = cI32(0));
  }
  check(uVar2);
  return;
}

function command33052(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da240,1);
  w32(0x4da244,4294967295);
  w32(0x4da270,4294967295);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33052(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  enable(cCompare(r32(0x5363b0),0,"=="));
  (uVar2 = cI32(1));
  if (cTruth((cTruth(cCompare(r32(0x4da240),1,"!=")) || cTruth(cCompare(r32(0x4da244),cNeg(1),"!="))))) {
    (uVar2 = cI32(0));
  }
  check(uVar2);
  return;
}

function command33053(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,0);
  w32(0x4da24c,1);
  w32(0x5364fc,1);
  invalidate(0);
  return;
}

function update33053(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da24c),1,"=="));
  return;
}

function command33054(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5364fc,1);
  w32(0x4da24c,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33054(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da24c),0,"=="));
  return;
}

function command33055(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da250,2);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33055(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da250),2,"=="));
  return;
}

function command33056(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,0);
  w32(0x4da250,1);
  w32(0x5364fc,1);
  invalidate(0);
  return;
}

function update33056(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da250),1,"=="));
  return;
}

function command33057(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5364fc,1);
  w32(0x4da250,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33057(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da250),0,"=="));
  return;
}

function command33058(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x535498,8);
  w32(0x522f08,10);
  w32(0x4fe764,10);
  w32(0x5364fc,1);
  w32(0x536508,0);
  w32(0x536504,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33058(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x522f08),10,"=="));
  return;
}

function command33059(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x536504,3);
  w32(0x522f08,8);
  w32(0x4fe764,8);
  w32(0x535498,8);
  w32(0x536508,0);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33059(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x536504),3,"=="));
  return;
}

function command33060(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x522f08,6);
  w32(0x4fe764,6);
  w32(0x535498,6);
  w32(0x536504,1);
  w32(0x536508,0);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33060(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x536504),1,"=="));
  return;
}

function command33061(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x522f08,5);
  w32(0x4fe764,5);
  w32(0x535498,5);
  w32(0x536504,0);
  w32(0x536508,1);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33061(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x522f08),5,"=="));
  return;
}

function command33062(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da260,cAdd(r32(0x4da260),1));
  if (cTruth(cCompare(1,r32(0x4da260),"<"))) {
    w32(0x4da260,0);
  }
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33062(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x536508),0,"=="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  if (cTruth((cTruth(cCompare(r32(0x4da260),1,"==")) && cTruth(cCompare(r32(0x536508),0,"=="))))) {
    check(1);
    return;
  }
  check(0);
  return;
}

function command33063(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5364fc,1);
  w32(0x4da25c,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33063(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da25c),0,"=="));
  return;
}

function command33064(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da25c,45);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33064(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da25c),45,"=="));
  return;
}

function command33065(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da25c,90);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33065(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da25c),90,"=="));
  return;
}

function command33067(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da25c,180);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33067(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da25c),180,"=="));
  return;
}

function command33069(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da25c,270);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33069(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da25c),270,"=="));
  return;
}

function command33070(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da25c,315);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33070(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da25c),315,"=="));
  return;
}

function command33066(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da25c,135);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33066(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da25c),135,"=="));
  return;
}

function command33068(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da25c,225);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33068(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da25c),225,"=="));
  return;
}

function command33071(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5364fc,1);
  w32(0x4da254,0);
  w32(0x4da258,0);
  w32(0x4da274,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33071(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  if (cTruth((cTruth(cCompare(r32(0x4da254),0,"==")) && cTruth(cCompare(r32(0x4da258),0,"=="))))) {
    check(1);
    return;
  }
  check(0);
  return;
}

function command33072(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da254,1);
  w32(0x4da258,1);
  w32(0x4da274,0);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33072(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  enable(cCompare(r32(0x5363b0),0,"=="));
  (uVar2 = cI32(1));
  if (cTruth((cTruth(cCompare(r32(0x4da254),1,"!=")) || cTruth(cCompare(r32(0x4da258),1,"!="))))) {
    (uVar2 = cI32(0));
  }
  check(uVar2);
  return;
}

function command33073(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5364fc,1);
  w32(0x4da254,4294967295);
  w32(0x4da258,4294967295);
  w32(0x4da274,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33073(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  if (cTruth((cTruth(cCompare(r32(0x4da254),cNeg(1),"==")) && cTruth(cCompare(r32(0x4da258),cNeg(1),"=="))))) {
    check(1);
    return;
  }
  check(0);
  return;
}

function command33074(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da254,4294967295);
  w32(0x4da258,1);
  w32(0x4da274,1);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33074(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  enable(cCompare(r32(0x5363b0),0,"=="));
  if (cTruth((cTruth(cCompare(r32(0x4da254),cNeg(1),"!=")) || cTruth(((uVar2 = cI32(1)), cCompare(r32(0x4da258),1,"!=")))))) {
    (uVar2 = cI32(0));
  }
  check(uVar2);
  return;
}

function command33075(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da254,1);
  w32(0x4da258,4294967295);
  w32(0x4da274,4294967295);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33075(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  enable(cCompare(r32(0x5363b0),0,"=="));
  (uVar2 = cI32(1));
  if (cTruth((cTruth(cCompare(r32(0x4da254),1,"!=")) || cTruth(cCompare(r32(0x4da258),cNeg(1),"!="))))) {
    (uVar2 = cI32(0));
  }
  check(uVar2);
  return;
}

function command33076(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,0);
  w32(0x4da264,1);
  w32(0x5364fc,1);
  invalidate(0);
  return;
}

function update33076(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da264),1,"=="));
  return;
}

function command33077(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5364fc,1);
  w32(0x4da264,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33077(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da264),0,"=="));
  return;
}

function command33078(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x536500,2);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33078(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x536500),2,"=="));
  return;
}

function command33079(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,0);
  w32(0x536500,1);
  w32(0x5364fc,1);
  invalidate(0);
  return;
}

function update33079(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x536500),1,"=="));
  return;
}

function command33080(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5364fc,1);
  w32(0x536500,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33080(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x536500),0,"=="));
  return;
}

function command33081(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5364fc,1);
  w32(0x4da268,0);
  w32(0x53650c,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33081(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x4da248),2,"<"))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da268),0,"=="));
  return;
}

function command33082(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da268,45);
  w32(0x53650c,0);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33082(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x4da248),2,"<"))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da268),45,"=="));
  return;
}

function command33083(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da268,90);
  w32(0x53650c,0);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33083(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x4da248),2,"<"))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da268),90,"=="));
  return;
}

function command33084(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da268,135);
  w32(0x53650c,0);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33084(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x4da248),2,"<"))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da268),135,"=="));
  return;
}

function command33085(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da268,180);
  w32(0x53650c,0);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33085(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x4da248),2,"<"))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da268),180,"=="));
  return;
}

function command33086(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da268,225);
  w32(0x53650c,0);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33086(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x4da248),2,"<"))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da268),225,"=="));
  return;
}

function command33087(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da268,270);
  w32(0x53650c,0);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33087(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x4da248),2,"<"))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da268),270,"=="));
  return;
}

function command33088(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da268,315);
  w32(0x53650c,0);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33088(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x4da248),2,"<"))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x4da268),315,"=="));
  return;
}

function command33089(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da26c,1);
  w32(0x536510,0);
  w32(0x536514,0);
  w32(0x4da158,1);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33089(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x536514),0,"=="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  if (cTruth((cTruth((cTruth((cTruth(cCompare(r32(0x4da26c),1,"==")) && cTruth(cCompare(r32(0x536510),0,"==")))) && cTruth(cCompare(r32(0x536514),0,"==")))) && cTruth(cCompare(r32(0x4da158),1,"=="))))) {
    check(1);
    return;
  }
  check(0);
  return;
}

function command33090(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da26c,4294967295);
  w32(0x536510,0);
  w32(0x536514,0);
  w32(0x4da158,1);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33090(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x536514),0,"=="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  if (cTruth((cTruth((cTruth((cTruth(cCompare(r32(0x4da26c),cNeg(1),"==")) && cTruth(cCompare(r32(0x536510),0,"==")))) && cTruth(cCompare(r32(0x536514),0,"==")))) && cTruth(cCompare(r32(0x4da158),1,"=="))))) {
    check(1);
    return;
  }
  check(0);
  return;
}

function command33091(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da26c,1);
  w32(0x536510,1);
  w32(0x536514,0);
  w32(0x4da158,1);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33091(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x536514),0,"=="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  if (cTruth((cTruth((cTruth((cTruth(cCompare(r32(0x4da26c),1,"==")) && cTruth(cCompare(r32(0x536510),1,"==")))) && cTruth(cCompare(r32(0x536514),0,"==")))) && cTruth(cCompare(r32(0x4da158),1,"=="))))) {
    check(1);
    return;
  }
  check(0);
  return;
}

function command33092(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da26c,4294967295);
  w32(0x536510,1);
  w32(0x536514,0);
  w32(0x4da158,1);
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33092(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x536514),0,"=="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  if (cTruth((cTruth((cTruth((cTruth(cCompare(r32(0x4da26c),cNeg(1),"==")) && cTruth(cCompare(r32(0x536510),1,"==")))) && cTruth(cCompare(r32(0x536514),0,"==")))) && cTruth(cCompare(r32(0x4da158),1,"=="))))) {
    check(1);
    return;
  }
  check(0);
  return;
}

function command33093(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x536514,cAdd(r32(0x536514),1));
  if (cTruth(cCompare(1,r32(0x536514),"<"))) {
    w32(0x536514,0);
  }
  if (cTruth(cCompare(r32(0x536514),0,"=="))) {
    w32(0x4da158,1);
  }
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33093(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  enable(cCompare(r32(0x5363b0),0,"=="));
  (uVar2 = cI32(1));
  if (cTruth((cTruth(cCompare(r32(0x536514),1,"!=")) && cTruth(cCompare(r32(0x4da158),0,"!="))))) {
    (uVar2 = cI32(0));
  }
  check(uVar2);
  return;
}

function command33094(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5364fc,0);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33094(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5364fc),1,"=="));
  return;
}

function command33095(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x53650c,cAdd(r32(0x53650c),1));
  if (cTruth(cCompare(1,r32(0x53650c),"<"))) {
    w32(0x53650c,0);
  }
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33095(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x53650c),1,"=="));
  return;
}

function command33096(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5364fc,cAdd(r32(0x5364fc),1));
  if (cTruth(cCompare(1,r32(0x5364fc),"<"))) {
    w32(0x5364fc,0);
  }
  w32(0x4da1f8,999);
  w32(0x4da200,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33096(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x5364fc),1,"=="));
  return;
}

function command33097(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x536524,cAdd(r32(0x536524),1));
  if (cTruth(cCompare(1,r32(0x536524),"<"))) {
    w32(0x536524,0);
  }
  w32(0x5364fc,1);
  w32(0x5363b4,0);
  invalidate(0);
  return;
}

function update33097(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  enable(cCompare(r32(0x5363b0),0,"=="));
  if (cTruth((cTruth(cCompare(r32(0x4da1f8),999,"!=")) || cTruth(((uVar2 = cI32(1)), cCompare(r32(0x536524),1,"!=")))))) {
    (uVar2 = cI32(0));
  }
  check(uVar2);
  return;
}

function command33098(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da144,23);
  invalidate(1);
  w32(0x5363b4,0);
  return;
}

function update33098(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da144),23,"=="));
  return;
}

function command33099(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da144,24);
  invalidate(1);
  w32(0x5363b4,0);
  return;
}

function update33099(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da144),24,"=="));
  return;
}

function command33100(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da144,21);
  invalidate(1);
  w32(0x5363b4,0);
  return;
}

function update33100(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da144),21,"=="));
  return;
}

function command33101(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da144,22);
  invalidate(1);
  w32(0x5363b4,0);
  return;
}

function update33101(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(cCompare(r32(0x5363b0),0,"=="));
  check(cCompare(r32(0x4da144),22,"=="));
  return;
}

function command33102(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x5363b4,0);
  w32(0x536444,12);
  w32(0x536448,12);
  invalidate(0);
  return;
}

function update33102(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(1);
  check(cCompare(r32(0x536444),12,"=="));
  return;
}

function command33103(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x536518,cAdd(r32(0x536518),1));
  if (cTruth(cCompare(1,r32(0x536518),"<"))) {
    w32(0x536518,0);
  }
  invalidate(1);
  w32(0x5363b4,0);
  return;
}

function update33103(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  enable(1);
  check(cCompare(r32(0x536518),1,"=="));
  return;
}

function command33104(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da144,25);
  w32(0x4da190,7);
  w32(0x5363c0,0);
  w32(0x5363b4,0);
  w32(0x536528,1);
  invalidate(1);
  return;
}

function update33104(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x536470),0,"=="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x536528),1,"=="));
  return;
}

function command33105(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da144,26);
  w32(0x4da190,7);
  w32(0x5363c0,0);
  w32(0x5363b4,0);
  w32(0x53652c,1);
  invalidate(1);
  return;
}

function update33105(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x536470),0,"=="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x53652c),1,"=="));
  return;
}

function command33106(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  w32(0x4da144,27);
  w32(0x4da190,5);
  w32(0x5363c0,0);
  w32(0x5363b4,0);
  w32(0x536530,1);
  invalidate(1);
  return;
}

function update33106(memory,options = {}) {
  const {r32,r64,w32,w64}=controllerMemory(memory);
  const windowHandle=options.windowHandle ?? 0;
  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});
  const enable=value=>options.enable(cI32(value));
  const check=value=>options.check(cI32(value));
  let uVar2;
  if (cTruth((cTruth(cCompare(r32(0x5363b0),0,"==")) && cTruth(cCompare(r32(0x536470),0,"=="))))) {
    (uVar2 = cI32(1));
  } else {
    (uVar2 = cI32(0));
  }
  enable(uVar2);
  check(cCompare(r32(0x536530),1,"=="));
  return;
}

export const MENU_COMMAND_ROUTINES=Object.freeze({"32771":4782416,"32777":4782464,"32776":4782544,"32783":4782656,"32792":4782912,"32881":4783040,"32784":4783168,"32789":4783296,"32782":4783424,"32788":4783552,"32791":4783680,"32781":4783808,"32786":4783936,"32794":4784064,"32790":4784192,"32787":4784336,"32793":4784464,"32823":4784592,"32780":4200592,"32807":4784832,"32808":4784976,"32809":4785152,"32810":4785328,"32805":4785504,"32811":4785648,"32806":4785824,"32824":4785968,"32778":4786064,"32820":4786176,"32818":4786368,"32819":4786528,"32816":4786688,"32817":4786880,"32802":4787072,"32799":4787248,"32803":4787376,"32804":4787504,"32801":4787632,"32796":4787792,"32795":4787920,"32797":4788048,"32798":4788176,"32800":4788304,"32821":4788432,"32815":4788560,"32779":4788672,"32822":4788880,"32812":4788992,"32813":4789104,"32814":4789216,"32882":4789328,"32891":4789440,"32892":4789552,"32893":4789664,"32894":4789776,"32895":4789888,"32896":4790000,"32883":4790112,"32884":4790224,"32885":4790336,"32886":4790448,"32887":4790560,"32888":4790672,"32889":4790784,"32890":4790896,"32897":4782784,"32825":4791008,"32827":4791120,"32826":4791232,"32828":4791344,"32831":4791376,"32830":4791440,"32829":4791488,"32907":4791536,"32908":4791616,"32905":4796880,"32850":4797040,"32851":4797152,"32842":4797648,"32841":4797712,"32843":4797776,"32849":4797920,"32845":4797984,"32847":4798128,"32844":4798224,"32846":4798368,"32848":4798448,"32872":4798576,"32873":4798672,"32874":4798768,"32875":4798864,"32876":4798960,"32877":4799056,"32878":4799152,"32879":4799248,"32880":4799344,"32909":4799440,"32833":4800192,"32832":4800304,"32852":4800416,"32853":4800512,"32859":4800576,"32860":4800736,"32861":4800912,"32856":4801088,"32854":4801216,"32855":4801328,"32858":4801456,"32857":4801600,"32910":4801760,"32902":4801888,"32903":4802032,"32904":4802192,"32912":4802288,"32834":4802352,"32913":4802480,"32914":4802592,"32916":4802704,"32919":4802816,"32918":4802928,"32915":4803040,"32862":4803136,"32924":4803248,"32864":4803392,"32865":4803504,"32866":4803616,"32835":4803728,"32925":4803840,"32927":4803952,"32928":4804096,"32929":4804208,"32931":4804352,"32930":4804480,"32932":4804624,"32933":4804768,"32934":4804912,"32935":4805056,"32936":4805200,"32937":4805344,"32923":4805488,"32938":4805648,"32939":4805744,"32940":4805888,"32941":4806016,"32942":4806144,"32943":4806288,"32955":4806432,"32944":4806576,"32945":4806720,"32954":4806864,"32946":4807008,"32947":4807152,"32948":4807296,"32949":4807440,"32950":4807584,"32951":4807728,"32926":4807872,"32956":4808016,"32898":4808160,"32899":4808272,"32911":4808368,"32868":4808496,"32869":4808608,"32957":4808720,"32960":4808864,"32958":4808960,"32961":4809072,"32962":4809168,"32963":4809296,"32964":4809424,"32965":4809600,"32966":4809696,"32967":4809792,"32968":4809952,"32969":4799536,"32970":4799632,"32971":4799728,"32972":4799824,"32973":4799920,"32974":4800016,"32975":4800112,"32976":4810080,"32977":4810192,"32978":4810304,"32979":4810416,"32980":4810544,"32981":4810656,"32982":4810784,"32983":4810912,"32984":4811008,"32985":4811120,"32986":4811232,"32987":4811344,"32988":4811456,"32989":4811568,"32990":4811744,"32991":4811888,"32992":4812032,"32993":4812176,"32994":4812336,"32996":4812544,"32997":4812656,"32998":4812768,"32999":4812880,"33000":4812992,"33001":4813104,"33002":4813216,"33003":4813328,"33004":4813440,"33005":4813552,"33006":4813664,"33007":4813776,"33010":4813888,"33008":4814000,"33009":4814112,"33011":4814224,"33013":4814432,"33012":4814496,"33014":4814544,"33015":4814656,"33016":4814768,"33017":4814880,"33018":4814992,"33019":4815136,"33020":4815248,"33021":4815360,"33022":4815472,"33023":4815584,"33024":4815696,"33025":4815808,"33026":4815904,"33027":4816016,"33028":4816128,"33029":4816240,"33030":4816352,"33031":4816464,"33032":4816576,"33033":4816688,"33034":4816864,"33035":4816976,"33036":4817088,"33037":4817200,"33038":4817312,"33039":4817424,"33040":4817536,"33041":4817648,"33042":4817760,"33043":4817872,"33044":4817984,"33045":4818096,"33046":4818208,"33047":4818320,"33048":4818432,"33049":4818560,"33050":4818672,"33051":4818800,"33052":4818928,"33053":4819056,"33054":4819168,"33055":4819280,"33056":4819392,"33057":4819504,"33058":4819616,"33059":4819760,"33060":4819904,"33061":4820032,"33062":4820160,"33063":4820320,"33064":4820432,"33065":4820544,"33067":4820768,"33069":4820992,"33070":4821104,"33066":4820656,"33068":4820880,"33071":4821216,"33072":4821344,"33073":4821456,"33074":4821584,"33075":4821712,"33076":4821840,"33077":4821952,"33078":4822064,"33079":4822176,"33080":4822288,"33081":4822400,"33082":4822512,"33083":4822640,"33084":4822768,"33085":4822896,"33086":4823024,"33087":4823152,"33088":4823280,"33089":4823536,"33090":4823712,"33091":4823888,"33092":4824064,"33093":4824240,"33094":4824384,"33095":4823408,"33096":4824448,"33097":4824576,"33098":4824720,"33099":4824832,"33100":4824944,"33101":4825056,"33102":4825168,"33103":4825264,"33104":4825376,"33105":4825520,"33106":4825664});
export const MENU_UPDATE_ROUTINES=Object.freeze({"32771":4784800,"32777":4800480,"32776":4782592,"32783":4782704,"32792":4782960,"32881":4783088,"32784":4783216,"32789":4783344,"32782":4783472,"32788":4783600,"32791":4783744,"32781":4783856,"32786":4783984,"32794":4784112,"32790":4784256,"32787":4784384,"32793":4784512,"32823":4784704,"32780":4784800,"32807":4784896,"32808":4785072,"32809":4785248,"32810":4785424,"32805":4785584,"32811":4785744,"32806":4785888,"32824":4786000,"32778":4786112,"32820":4786256,"32818":4786432,"32819":4786592,"32816":4786768,"32817":4786960,"32802":4787152,"32799":4787312,"32803":4787440,"32804":4787568,"32801":4787712,"32796":4787856,"32795":4787984,"32797":4788112,"32798":4788240,"32800":4788368,"32821":4788480,"32815":4788608,"32779":4788800,"32822":4788912,"32812":4789040,"32813":4789152,"32814":4789264,"32882":4789376,"32891":4789488,"32892":4789600,"32893":4789712,"32894":4789824,"32895":4789936,"32896":4790048,"32883":4790160,"32884":4790272,"32886":4790496,"32885":4790384,"32887":4790608,"32888":4790720,"32889":4790832,"32890":4790944,"32897":4782832,"32825":4791056,"32827":4791168,"32826":4791280,"32828":4791424,"32831":4791424,"32830":4791424,"32829":4791424,"32907":4798192,"32908":4791648,"32850":4797088,"32851":4797200,"32842":4798192,"32841":4798192,"32843":4797840,"32849":4798192,"32845":4798048,"32847":4798192,"32844":4798288,"32846":4798192,"32848":4798512,"32872":4798624,"32873":4798720,"32874":4798816,"32875":4798912,"32876":4799008,"32877":4799104,"32878":4799200,"32879":4799296,"32880":4799392,"32909":4799488,"32833":4800240,"32832":4800352,"32852":4800480,"32853":4800480,"32859":4800624,"32860":4800784,"32861":4800960,"32856":4801136,"32854":4801264,"32855":4801376,"32858":4801488,"32857":4801648,"32910":4801824,"32902":4801968,"32903":4802112,"32904":4802240,"32912":4800480,"32834":4802400,"32913":4802528,"32914":4802640,"32916":4802752,"32919":4802864,"32918":4802976,"32905":4796976,"32915":4803072,"32862":4803184,"32924":4803296,"32864":4803440,"32865":4803552,"32866":4803664,"32835":4803776,"32925":4803888,"32927":4804016,"32928":4804144,"32929":4804272,"32931":4804416,"32930":4804544,"32932":4804688,"32933":4804832,"32934":4804976,"32935":4805120,"32936":4805264,"32937":4805408,"32923":4805568,"32938":4805680,"32939":4805808,"32940":4805952,"32941":4806080,"32942":4806208,"32943":4806352,"32955":4806496,"32944":4806640,"32945":4806784,"32954":4806928,"32946":4807072,"32947":4807216,"32948":4807360,"32949":4807504,"32950":4807648,"32951":4807792,"32926":4807936,"32956":4808080,"32898":4800480,"32899":4800480,"32911":4808432,"32868":4808544,"32869":4808656,"32957":4808768,"32960":4808896,"32958":4809008,"32961":4809104,"32962":4809216,"32963":4809344,"32964":4809504,"32965":4809648,"32966":4809744,"32967":4809840,"32968":4810000,"32969":4799584,"32970":4799680,"32971":4799776,"32972":4799872,"32973":4799968,"32974":4800096,"32975":4800096,"32976":4810128,"32977":4810240,"32978":4810352,"32979":4810464,"32980":4810592,"32981":4810704,"32982":4810832,"32983":4810960,"32984":4811056,"32985":4811168,"32986":4811280,"32987":4811392,"32988":4811504,"32989":4811680,"32990":4811824,"32991":4811968,"32992":4812096,"32993":4812256,"32994":4812384,"32996":4812592,"32997":4812704,"32998":4812816,"32999":4812928,"33000":4813040,"33001":4813152,"33002":4813264,"33003":4813376,"33004":4813488,"33005":4813600,"33006":4813712,"33007":4813824,"33010":4813936,"33008":4814048,"33009":4814160,"33011":4814272,"33013":4800480,"33012":4800480,"33014":4814592,"33015":4814704,"33016":4814816,"33017":4814928,"33018":4815072,"33019":4815184,"33020":4815296,"33021":4815408,"33022":4815520,"33023":4815632,"33024":4815744,"33025":4815856,"33026":4815952,"33027":4816064,"33028":4816176,"33029":4816288,"33030":4816400,"33031":4816512,"33032":4816624,"33033":4816800,"33034":4816912,"33035":4817024,"33036":4817136,"33037":4817248,"33038":4817360,"33039":4817472,"33040":4817584,"33041":4817696,"33042":4817808,"33043":4817920,"33044":4818032,"33045":4818144,"33046":4818256,"33047":4818368,"33048":4818480,"33049":4818608,"33050":4818720,"33051":4818864,"33052":4818992,"33053":4819104,"33054":4819216,"33055":4819328,"33056":4819440,"33057":4819552,"33058":4819696,"33059":4819840,"33060":4819968,"33061":4820096,"33062":4820224,"33063":4820368,"33064":4820480,"33065":4820592,"33067":4820816,"33069":4821040,"33070":4821152,"33066":4820704,"33068":4820928,"33071":4821264,"33072":4821392,"33073":4821504,"33074":4821648,"33075":4821776,"33076":4821888,"33077":4822000,"33078":4822112,"33079":4822224,"33080":4822336,"33081":4822448,"33082":4822560,"33083":4822688,"33084":4822816,"33085":4822944,"33086":4823072,"33087":4823200,"33088":4823328,"33089":4823600,"33090":4823776,"33091":4823952,"33092":4824128,"33093":4824320,"33094":4824416,"33095":4823472,"33096":4824512,"33097":4824640,"33098":4824768,"33099":4824880,"33100":4824992,"33101":4825104,"33102":4825216,"33103":4825328,"33104":4825440,"33105":4825584,"33106":4825728});
const commands=Object.freeze({32771:command32771,32777:command32777,32776:command32776,32783:command32783,32792:command32792,32881:command32881,32784:command32784,32789:command32789,32782:command32782,32788:command32788,32791:command32791,32781:command32781,32786:command32786,32794:command32794,32790:command32790,32787:command32787,32793:command32793,32780:command32780,32807:command32807,32808:command32808,32809:command32809,32810:command32810,32805:command32805,32811:command32811,32806:command32806,32824:command32824,32778:command32778,32820:command32820,32818:command32818,32819:command32819,32816:command32816,32817:command32817,32802:command32802,32799:command32799,32803:command32803,32804:command32804,32801:command32801,32796:command32796,32795:command32795,32797:command32797,32798:command32798,32800:command32800,32821:command32821,32815:command32815,32822:command32822,32812:command32812,32813:command32813,32814:command32814,32882:command32882,32891:command32891,32892:command32892,32893:command32893,32894:command32894,32895:command32895,32896:command32896,32883:command32883,32884:command32884,32885:command32885,32886:command32886,32887:command32887,32888:command32888,32889:command32889,32890:command32890,32897:command32897,32825:command32825,32827:command32827,32826:command32826,32828:command32828,32831:command32831,32830:command32830,32829:command32829,32907:command32907,32908:command32908,32905:command32905,32850:command32850,32851:command32851,32842:command32842,32841:command32841,32843:command32843,32849:command32849,32845:command32845,32847:command32847,32844:command32844,32846:command32846,32848:command32848,32872:command32872,32873:command32873,32874:command32874,32875:command32875,32876:command32876,32877:command32877,32878:command32878,32879:command32879,32880:command32880,32909:command32909,32833:command32833,32832:command32832,32852:command32852,32853:command32853,32859:command32859,32860:command32860,32861:command32861,32856:command32856,32854:command32854,32855:command32855,32858:command32858,32857:command32857,32910:command32910,32902:command32902,32903:command32903,32904:command32904,32912:command32912,32834:command32834,32913:command32913,32914:command32914,32916:command32916,32919:command32919,32918:command32918,32915:command32915,32862:command32862,32924:command32924,32864:command32864,32865:command32865,32866:command32866,32835:command32835,32925:command32925,32927:command32927,32928:command32928,32929:command32929,32931:command32931,32930:command32930,32932:command32932,32933:command32933,32934:command32934,32935:command32935,32936:command32936,32937:command32937,32923:command32923,32938:command32938,32939:command32939,32940:command32940,32941:command32941,32942:command32942,32943:command32943,32955:command32955,32944:command32944,32945:command32945,32954:command32954,32946:command32946,32947:command32947,32948:command32948,32949:command32949,32950:command32950,32951:command32951,32926:command32926,32956:command32956,32898:command32898,32899:command32899,32911:command32911,32868:command32868,32869:command32869,32957:command32957,32960:command32960,32958:command32958,32961:command32961,32962:command32962,32963:command32963,32964:command32964,32965:command32965,32966:command32966,32967:command32967,32968:command32968,32969:command32969,32970:command32970,32971:command32971,32972:command32972,32973:command32973,32974:command32974,32975:command32975,32976:command32976,32977:command32977,32978:command32978,32979:command32979,32980:command32980,32981:command32981,32982:command32982,32983:command32983,32984:command32984,32985:command32985,32986:command32986,32987:command32987,32988:command32988,32989:command32989,32990:command32990,32991:command32991,32992:command32992,32993:command32993,32994:command32994,32996:command32996,32997:command32997,32998:command32998,32999:command32999,33000:command33000,33001:command33001,33002:command33002,33003:command33003,33004:command33004,33005:command33005,33006:command33006,33007:command33007,33010:command33010,33008:command33008,33009:command33009,33011:command33011,33013:command33013,33012:command33012,33014:command33014,33015:command33015,33016:command33016,33017:command33017,33018:command33018,33019:command33019,33020:command33020,33021:command33021,33022:command33022,33023:command33023,33024:command33024,33025:command33025,33026:command33026,33027:command33027,33028:command33028,33029:command33029,33030:command33030,33031:command33031,33032:command33032,33033:command33033,33034:command33034,33035:command33035,33036:command33036,33037:command33037,33038:command33038,33039:command33039,33040:command33040,33041:command33041,33042:command33042,33043:command33043,33044:command33044,33045:command33045,33046:command33046,33047:command33047,33048:command33048,33049:command33049,33050:command33050,33051:command33051,33052:command33052,33053:command33053,33054:command33054,33055:command33055,33056:command33056,33057:command33057,33058:command33058,33059:command33059,33060:command33060,33061:command33061,33062:command33062,33063:command33063,33064:command33064,33065:command33065,33067:command33067,33069:command33069,33070:command33070,33066:command33066,33068:command33068,33071:command33071,33072:command33072,33073:command33073,33074:command33074,33075:command33075,33076:command33076,33077:command33077,33078:command33078,33079:command33079,33080:command33080,33081:command33081,33082:command33082,33083:command33083,33084:command33084,33085:command33085,33086:command33086,33087:command33087,33088:command33088,33089:command33089,33090:command33090,33091:command33091,33092:command33092,33093:command33093,33094:command33094,33095:command33095,33096:command33096,33097:command33097,33098:command33098,33099:command33099,33100:command33100,33101:command33101,33102:command33102,33103:command33103,33104:command33104,33105:command33105,33106:command33106});
const updates=Object.freeze({32771:update32771,32777:update32777,32776:update32776,32783:update32783,32792:update32792,32881:update32881,32784:update32784,32789:update32789,32782:update32782,32788:update32788,32791:update32791,32781:update32781,32786:update32786,32794:update32794,32790:update32790,32787:update32787,32793:update32793,32823:update32823,32780:update32780,32807:update32807,32808:update32808,32809:update32809,32810:update32810,32805:update32805,32811:update32811,32806:update32806,32824:update32824,32778:update32778,32820:update32820,32818:update32818,32819:update32819,32816:update32816,32817:update32817,32802:update32802,32799:update32799,32803:update32803,32804:update32804,32801:update32801,32796:update32796,32795:update32795,32797:update32797,32798:update32798,32800:update32800,32821:update32821,32815:update32815,32779:update32779,32822:update32822,32812:update32812,32813:update32813,32814:update32814,32882:update32882,32891:update32891,32892:update32892,32893:update32893,32894:update32894,32895:update32895,32896:update32896,32883:update32883,32884:update32884,32886:update32886,32885:update32885,32887:update32887,32888:update32888,32889:update32889,32890:update32890,32897:update32897,32825:update32825,32827:update32827,32826:update32826,32828:update32828,32831:update32831,32830:update32830,32829:update32829,32907:update32907,32908:update32908,32850:update32850,32851:update32851,32842:update32842,32841:update32841,32843:update32843,32849:update32849,32845:update32845,32847:update32847,32844:update32844,32846:update32846,32848:update32848,32872:update32872,32873:update32873,32874:update32874,32875:update32875,32876:update32876,32877:update32877,32878:update32878,32879:update32879,32880:update32880,32909:update32909,32833:update32833,32832:update32832,32852:update32852,32853:update32853,32859:update32859,32860:update32860,32861:update32861,32856:update32856,32854:update32854,32855:update32855,32858:update32858,32857:update32857,32910:update32910,32902:update32902,32903:update32903,32904:update32904,32912:update32912,32834:update32834,32913:update32913,32914:update32914,32916:update32916,32919:update32919,32918:update32918,32905:update32905,32915:update32915,32862:update32862,32924:update32924,32864:update32864,32865:update32865,32866:update32866,32835:update32835,32925:update32925,32927:update32927,32928:update32928,32929:update32929,32931:update32931,32930:update32930,32932:update32932,32933:update32933,32934:update32934,32935:update32935,32936:update32936,32937:update32937,32923:update32923,32938:update32938,32939:update32939,32940:update32940,32941:update32941,32942:update32942,32943:update32943,32955:update32955,32944:update32944,32945:update32945,32954:update32954,32946:update32946,32947:update32947,32948:update32948,32949:update32949,32950:update32950,32951:update32951,32926:update32926,32956:update32956,32898:update32898,32899:update32899,32911:update32911,32868:update32868,32869:update32869,32957:update32957,32960:update32960,32958:update32958,32961:update32961,32962:update32962,32963:update32963,32964:update32964,32965:update32965,32966:update32966,32967:update32967,32968:update32968,32969:update32969,32970:update32970,32971:update32971,32972:update32972,32973:update32973,32974:update32974,32975:update32975,32976:update32976,32977:update32977,32978:update32978,32979:update32979,32980:update32980,32981:update32981,32982:update32982,32983:update32983,32984:update32984,32985:update32985,32986:update32986,32987:update32987,32988:update32988,32989:update32989,32990:update32990,32991:update32991,32992:update32992,32993:update32993,32994:update32994,32996:update32996,32997:update32997,32998:update32998,32999:update32999,33000:update33000,33001:update33001,33002:update33002,33003:update33003,33004:update33004,33005:update33005,33006:update33006,33007:update33007,33010:update33010,33008:update33008,33009:update33009,33011:update33011,33013:update33013,33012:update33012,33014:update33014,33015:update33015,33016:update33016,33017:update33017,33018:update33018,33019:update33019,33020:update33020,33021:update33021,33022:update33022,33023:update33023,33024:update33024,33025:update33025,33026:update33026,33027:update33027,33028:update33028,33029:update33029,33030:update33030,33031:update33031,33032:update33032,33033:update33033,33034:update33034,33035:update33035,33036:update33036,33037:update33037,33038:update33038,33039:update33039,33040:update33040,33041:update33041,33042:update33042,33043:update33043,33044:update33044,33045:update33045,33046:update33046,33047:update33047,33048:update33048,33049:update33049,33050:update33050,33051:update33051,33052:update33052,33053:update33053,33054:update33054,33055:update33055,33056:update33056,33057:update33057,33058:update33058,33059:update33059,33060:update33060,33061:update33061,33062:update33062,33063:update33063,33064:update33064,33065:update33065,33067:update33067,33069:update33069,33070:update33070,33066:update33066,33068:update33068,33071:update33071,33072:update33072,33073:update33073,33074:update33074,33075:update33075,33076:update33076,33077:update33077,33078:update33078,33079:update33079,33080:update33080,33081:update33081,33082:update33082,33083:update33083,33084:update33084,33085:update33085,33086:update33086,33087:update33087,33088:update33088,33089:update33089,33090:update33090,33091:update33091,33092:update33092,33093:update33093,33094:update33094,33095:update33095,33096:update33096,33097:update33097,33098:update33098,33099:update33099,33100:update33100,33101:update33101,33102:update33102,33103:update33103,33104:update33104,33105:update33105,33106:update33106});

export function handleMenuCommand(memory,command,options={}) {
  command=i32(command);
  if (command===57664 || command===32823 || command===32779) {
    if (!options.dialogHandler) throw new TypeError('The original modal command requires a dialog host');
    const resourceId=command===57664 ? 100 : command===32823 ? 132 : 131;
    const tail=()=>{
      if (command!==57664) {
        memory.writeI32(0x5363b4,0);
        options.invalidateRect?.({windowHandle:options.windowHandle ?? 0,rectangle:null,erase:command===32823 ? 1 : 0});
        if (command===32779) memory.writeI32(0x4da140,2);
      }
      return true;
    };
    const result=options.dialogHandler(resourceId,memory,options);
    return result && typeof result.then==='function' ? Promise.resolve(result).then(tail) : tail();
  }
  if (command===57665) { options.closeWindow?.();return true; }
  if (command===59393) { options.contextHelp?.();return true; }
  const handler=commands[command];
  if (!handler) return false;
  handler(memory,options);
  return true;
}

export function menuCommandState(memory,command,previous={enabled:true,checked:0}) {
  command=i32(command);
  const result={...previous,events:[]};
  const handler=updates[command];
  if (handler) handler(memory,{
    enable:value=>{result.enabled=value!==0;result.events.push({type:'enable',value});},
    check:value=>{result.checked=value;result.events.push({type:'check',value});},
  });
  return result;
}
