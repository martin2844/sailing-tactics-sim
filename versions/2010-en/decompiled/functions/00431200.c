
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00431200(int param_1,int param_2)

{
  int iVar1;
  float10 fVar2;
  float10 fVar3;
  
  if (DAT_004da1f8 == 0) {
    if (DAT_004f69b8 == 5) {
      if (param_2 < 1) {
        DAT_004fe160 = 0x10e;
        DAT_005229c4 = 0x5a;
        return;
      }
      if (0 < param_2) {
        DAT_005229c4 = 0x10e;
        DAT_004fe160 = 0x5a;
        return;
      }
    }
    iVar1 = FUN_00427ee0(DAT_00535bc8 - param_1,param_2 - DAT_004f3858);
    if (DAT_004f8b78 == 0) {
      iVar1 = iVar1 + 0xb4;
    }
    DAT_005229c4 = FUN_0041bc20(iVar1 + 0x5a);
    DAT_004fe160 = FUN_0041bc20(iVar1 + -0x5a);
  }
  if (DAT_004da1f8 == 1) {
    if ((((-0x9c4 < param_1) && (param_1 < -0x33e)) && (-0x53 < param_2)) && (param_2 < 0xc80)) {
      DAT_005229c4 = 0x154;
    }
    DAT_004fe160 = 0xa0;
  }
  if (DAT_004da1f8 == 2) {
    DAT_005229c4 = 0x3c;
    DAT_004fe160 = 0xf0;
  }
  if (DAT_004da1f8 != 3) goto LAB_004313b5;
  if (param_1 < -0x708) {
    DAT_005229c4 = 0x19;
    DAT_004fe160 = 0xcd;
    if (-0x709 < param_1) goto LAB_00431350;
LAB_00431369:
    if (0x16 < param_1) goto LAB_0043136e;
LAB_00431381:
    if (0x8d3 < param_1) goto LAB_00431389;
  }
  else {
LAB_00431350:
    if (param_1 < 0x17) {
      DAT_005229c4 = 0xb4;
      DAT_004fe160 = 0x168;
      goto LAB_00431369;
    }
LAB_0043136e:
    if (param_1 < 0x8d4) {
      DAT_005229c4 = 0x19;
      DAT_004fe160 = 0xcd;
      goto LAB_00431381;
    }
LAB_00431389:
    if (param_1 < 0xe10) {
      DAT_005229c4 = 0xd2;
      DAT_004fe160 = 0x1e;
    }
  }
  if (0xeb9 < param_1) {
    DAT_005229c4 = 0x5a;
    DAT_004fe160 = 0x10e;
  }
LAB_004313b5:
  if (DAT_004fb5d4 == 1) {
    if (((param_1 < 0x1996) && (0 < param_2)) && (param_2 < 0x125c)) {
      DAT_004fe160 = 10;
      DAT_005229c4 = 0xbe;
    }
    if (((param_1 < 0x26d4) && (param_2 < -1000)) && (-0x1478 < param_2)) {
      DAT_004fe160 = 0x1e;
      DAT_005229c4 = 0xd2;
    }
    if (((0x1af4 < param_1) && (param_1 < 14000)) && (0xa28 < param_2)) {
      DAT_005229c4 = 0x50;
      DAT_004fe160 = 0x104;
    }
    if ((0x28f7 < param_1) && (param_2 < 0x898)) {
      DAT_005229c4 = 0x159;
      DAT_004fe160 = 0xa5;
    }
  }
  if (DAT_004da1f8 == 6) {
    DAT_004fe160 = -900;
    DAT_005229c4 = -900;
    if (param_1 < 3000) {
      if (0x707 < param_2) {
        DAT_004fe160 = 0xbe;
        DAT_005229c4 = 0x172;
      }
    }
    else {
      DAT_004fe160 = 0x1e;
      DAT_005229c4 = 0x96;
    }
    if (((param_1 < -300) && (-0x578 < param_2)) && (param_2 < -0xd48)) {
      DAT_004fe160 = 0x10e;
      DAT_005229c4 = 0x5a;
    }
    if (param_1 < 3000) {
      if ((param_2 < 0x579) && (param_2 < -0x577)) {
        DAT_004fe160 = 0x82;
        DAT_005229c4 = 0x136;
      }
      if ((param_1 < 3000) && (param_2 < -0xd47)) {
        DAT_004fe160 = 0xbe;
        DAT_005229c4 = 0x172;
      }
    }
  }
  if (DAT_004da1f8 == 7) {
    if (param_1 < 1) {
      if (param_2 < -400) {
        DAT_005229c4 = 0x186;
        DAT_004fe160 = 0xd2;
      }
      else {
        DAT_005229c4 = 0x154;
        DAT_004fe160 = 0xa0;
      }
    }
    else {
      DAT_004fe160 = 0x154;
      DAT_005229c4 = 0xa0;
    }
  }
  if ((DAT_004da1f8 == 9) &&
     (iVar1 = FUN_0047def0(-0x1662,0x62c,-0x145,0x8a6,0x6a4,0x140a,param_1,param_2), iVar1 == 1)) {
    DAT_004fe160 = 100;
    DAT_005229c4 = 0x118;
  }
  if (DAT_004da1f8 == 10) {
    iVar1 = FUN_0047def0(-0x1130,0x1414,0xaf0,0x1900,-0x992,0x5dc,param_1,param_2);
    if (iVar1 == 1) {
      DAT_004fe160 = 0x41;
      DAT_005229c4 = 0xf5;
    }
    iVar1 = FUN_0047def0(-0x1130,0x596,-0x474,0x1900,-0x1518,-0x992,param_1,param_2);
    if (iVar1 == 1) {
      DAT_005229c4 = 0x41;
      DAT_004fe160 = 0xf5;
    }
  }
  if ((DAT_004da1f8 == 0xb) && (param_1 < 1000)) {
    DAT_005229c4 = 0x17c;
    DAT_004fe160 = 200;
  }
  if (DAT_004da1f8 == 0xc) {
    DAT_005229c4 = 0x15e;
    DAT_004fe160 = 0xbe;
  }
  if (DAT_004da1f8 == 0x67) {
    DAT_005229c4 = 1000;
    DAT_004fe160 = 1000;
    if (1000 < param_1) {
      DAT_004fe160 = 0x154;
      DAT_005229c4 = 0xa0;
    }
    if (0x5dc < param_2) {
      DAT_004fe160 = 0x46;
      DAT_005229c4 = 0xfa;
    }
  }
  if (DAT_004da1f8 == 0x69) {
    DAT_005229c4 = 1000;
    DAT_004fe160 = 1000;
    if (-0xb22 < param_1) {
      DAT_005229c4 = 0x50;
      DAT_004fe160 = 0x104;
    }
  }
  if (DAT_004da1f8 == 100) {
    DAT_005229c4 = 1000;
    DAT_004fe160 = 1000;
    if (param_2 < 1) {
      if ((-4000 < param_1) && (param_2 < -0x514)) {
        DAT_005229c4 = 100;
        DAT_004fe160 = 0x118;
      }
    }
    else if ((param_2 < 0x13ec) && (0 < param_1)) {
      DAT_005229c4 = 0xd7;
      DAT_004fe160 = 0x18b;
    }
  }
  if (DAT_004da1f8 == 0x65) {
    DAT_005229c4 = 1000;
    DAT_004fe160 = 1000;
    if (((1000 < param_2) && (-3000 < param_1)) && (param_1 < 0x8fc)) {
      DAT_005229c4 = 0x10e;
      DAT_004fe160 = 0x5a;
    }
    if (((param_2 < -1000) && (-4000 < param_1)) && (param_1 < 0xc1c)) {
      DAT_004fe160 = 0xfa;
      DAT_005229c4 = 0x46;
    }
  }
  if (DAT_004da1f8 == 0x6a) {
    DAT_005229c4 = 1000;
    DAT_004fe160 = 1000;
    if (param_2 < -800) {
      DAT_005229c4 = 0x2d;
      DAT_004fe160 = 0x13b;
    }
    if (0 < param_2) {
      DAT_004fe160 = 0x73;
      DAT_005229c4 = 0x127;
    }
  }
  if (DAT_004da1f8 == 0x66) {
    DAT_005229c4 = 1000;
    DAT_004fe160 = 1000;
    if ((param_1 < -0x15e) && (param_2 < 0x640)) {
      DAT_005229c4 = 0;
      DAT_004fe160 = 0xb4;
    }
    if ((param_1 < 0x73a) && (0x63f < param_2)) {
      DAT_005229c4 = 0x140;
      DAT_004fe160 = 0x8c;
    }
  }
  if (DAT_004da1f8 == 999) {
    fVar2 = FUN_004662d0((double)param_1,(double)param_2,(double)DAT_0053521c,(double)DAT_004f4b5c);
    fVar3 = FUN_004662d0((double)param_1,(double)param_2,(double)DAT_00535230,(double)DAT_004f4b70);
    if (fVar3 < (float10)(double)fVar2) {
      DAT_005229c4 = FUN_0041bc20((int)(longlong)(_DAT_004fafd8 * _DAT_004cc3e8));
      iVar1 = (int)(longlong)(_DAT_004fafd8 * _DAT_004cc910);
    }
    else {
      DAT_005229c4 = FUN_0041bc20((int)(longlong)(DAT_004fafb0 * _DAT_004cc3e8));
      iVar1 = (int)(longlong)(DAT_004fafb0 * _DAT_004cc910);
    }
    DAT_004fe160 = FUN_0041bc20(0xb4 - iVar1);
  }
  return;
}

