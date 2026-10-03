
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0042da80(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  float10 fVar8;
  int local_18;
  int local_14;
  
  if ((DAT_004da19c == 9) || (DAT_004da19c == 10)) {
    iVar5 = FUN_0041e000(0x50);
    iVar5 = iVar5 + 0x5a;
    local_14 = FUN_0041e000(0xfa);
    local_14 = local_14 + 200;
  }
  else {
    iVar5 = 0x82;
    local_14 = 0x145;
  }
  DAT_004fb6b8 = 0xffffea84;
  DAT_004fb6bc = 0xffffea84;
  DAT_004fbc3c = DAT_005229d0;
  DAT_004fbc38 = DAT_005229d0 * 6;
  if ((DAT_004da19c == 9) || (DAT_004da19c == 10)) {
    local_18 = 0x32;
  }
  else {
    local_18 = FUN_0041e000(100);
  }
  iVar7 = 2;
  do {
    iVar2 = FUN_0041e000(0x28);
    iVar3 = (iVar7 + -0x12) * 0xfa;
    (&DAT_004fb6b8)[iVar7] = iVar3;
    iVar1 = DAT_005229d0;
    iVar4 = DAT_005127a4;
    fVar8 = (float10)fsin(((float10)iVar3 + (float10)local_18) / (float10)local_14);
    iVar2 = (int)(longlong)(fVar8 * (float10)(iVar2 + iVar5)) * DAT_005127a4 + DAT_005229d0;
    (&DAT_004fbc38)[iVar7] = iVar2;
    if (iVar7 == 2) {
      DAT_004fbc40 = iVar2 + iVar4 * -100;
    }
    if (iVar7 == 3) {
      DAT_004fbc44 = DAT_004fbc44 + iVar4 * -300;
    }
    if (iVar7 == 4) {
      DAT_004fbc48 = DAT_004fbc48 + iVar4 * -600;
    }
    if (iVar7 == 5) {
      DAT_004fbc4c = DAT_004fbc4c + iVar4 * -1000;
    }
    if ((iVar7 == 6) || (iVar7 == 7)) {
      (&DAT_004fbc38)[iVar7] = iVar1 + iVar4 * -4000;
    }
    if (iVar7 == 8) {
      DAT_004fbc58 = DAT_004fbc58 + iVar4 * -1000;
    }
    if (iVar7 == 9) {
      DAT_004fbc5c = DAT_004fbc5c + iVar4 * -500;
    }
    if (iVar7 == 10) {
      DAT_004fbc60 = DAT_004fbc60 + iVar4 * -100;
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0x24);
  _DAT_004fb748 = 0x157c;
  _DAT_004fb74c = 0x157c;
  _DAT_004fbcc8 = iVar1;
  _DAT_00535f64 = DAT_004fbc60;
  _DAT_0052317c = DAT_004fb6e0;
  _DAT_004fbccc = iVar4 * -6000;
  if (DAT_005230dc == 1) {
    _DAT_00534ea0 = DAT_004fbc7c + -500;
    _DAT_005229cc = DAT_004fb6fc;
    if (DAT_004da19c == 9) {
      _DAT_00522e5c = DAT_004fb6d0 + -100;
      _DAT_00522e60 = DAT_004fb6d0;
      _DAT_00535554 = DAT_004fbc50;
    }
    else {
      _DAT_00522e5c = DAT_004fb728;
      _DAT_00522e60 = DAT_004fb728;
      _DAT_00535554 = DAT_004fbca8;
    }
    _DAT_00535278 = _DAT_00535554 + -900;
    _DAT_00535554 = _DAT_00535554 + -1000;
    if (DAT_004da19c == 9) {
      _DAT_004fb9bc = DAT_004fbc48 + -0x44c;
      _DAT_004fb208 = DAT_004fb6c8;
      goto LAB_0042de2e;
    }
    _DAT_004fb9bc = DAT_004fbcb0 + -0x44c;
  }
  else {
    if (DAT_004da19c == 10) {
      _DAT_005229cc = DAT_004fb6d0;
      _DAT_00534ea0 = DAT_004fbc50 + 700;
    }
    else {
      _DAT_005229cc = DAT_004fb704;
      _DAT_00534ea0 = DAT_004fbc84 + 500;
    }
    _DAT_00522e5c = DAT_004fb71c;
    _DAT_00522e60 = DAT_004fb71c;
    _DAT_00535278 = DAT_004fbc9c + 900;
    _DAT_00535554 = DAT_004fbc9c + 1000;
    if (DAT_004da19c == 10) {
      _DAT_004fb9bc = DAT_004fbc48 + 0x44c;
      _DAT_004fb208 = DAT_004fb6c8;
      goto LAB_0042de2e;
    }
    _DAT_004fb9bc = DAT_004fbcb0 + 0x44c;
  }
  _DAT_004fb208 = DAT_004fb730;
LAB_0042de2e:
  piVar6 = &DAT_00523084;
  iVar5 = 9;
  iVar7 = 0;
  do {
    iVar4 = FUN_0041e000(0x1c);
    *(undefined4 *)((int)&DAT_005116bc + iVar7) = (&DAT_004fb6c4)[iVar4];
    *(int *)((int)&DAT_00535ffc + iVar7) = (&DAT_004fbc38)[iVar4 + 3] + DAT_005127a4 * iVar5 * -500;
    iVar4 = FUN_0041e000(0x3c);
    *piVar6 = iVar4 + 0x28;
    iVar5 = iVar5 + -1;
    iVar7 = iVar7 + 4;
    piVar6 = piVar6 + 1;
  } while (4 < iVar5);
  return;
}

