
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0042d280(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  double *pdVar5;
  int *piVar6;
  int iVar7;
  float10 fVar8;
  float10 fVar9;
  float10 fVar10;
  int local_128;
  double local_120 [36];
  
  DAT_004f4b00 = 3000;
  iVar7 = 0;
  DAT_00535bc8 = 0;
  DAT_004f3858 = 0;
  iVar2 = FUN_0041e000(200);
  DAT_004f3858 = iVar2 + -100;
  if (DAT_005230dc == 2) {
    DAT_00535bc8 = -0x4e2;
  }
  if (DAT_005230dc == 4) {
    DAT_00535bc8 = 0x4e2;
  }
  if (DAT_004f4510 == 1) {
    DAT_004f4b00 = 4000;
  }
  if (DAT_004f69b8 == 1) {
    DAT_00535bc8 = 0;
    DAT_004f3858 = 0;
    DAT_004f4b00 = 0x5dc;
  }
  if (1 < DAT_004f69b8) {
    DAT_00535bc8 = 0;
    DAT_004f3858 = 0;
  }
  if ((DAT_004f8b78 == 1) && (DAT_004da19c != 8)) {
    DAT_00535bc8 = 500;
    DAT_004f3858 = 0;
    DAT_004f4b00 = 0x1a4;
  }
  if ((DAT_004f8b78 == 1) && (DAT_004da19c == 8)) {
    DAT_004f3858 = 0;
    DAT_00535bc8 = 700;
    DAT_004f4b00 = 700;
  }
  if (DAT_004f8db8 == 1) {
    DAT_00535bc8 = 0;
    DAT_004f3858 = 0;
    DAT_004f4b00 = (-(uint)(DAT_004da19c != 8) & 0xfffffb82) + 0x9c4;
  }
  pdVar5 = local_120;
  local_128 = 0;
  iVar2 = DAT_004f4b00;
  do {
    iVar3 = FUN_0041e000(iVar2 / 0x1e);
    iVar2 = DAT_004f4b00;
    fVar8 = (float10)(iVar3 + DAT_004f4b00);
    *pdVar5 = (double)(iVar3 + DAT_004f4b00);
    fVar9 = (float10)fsin((float10)local_128 * (float10)_DAT_004cc568);
    fVar10 = (float10)fcos((float10)local_128 * (float10)_DAT_004cc568);
    *(int *)((int)&DAT_004fb6b8 + iVar7) =
         (int)(longlong)(fVar9 * (float10)_DAT_004fba00 * fVar8) + DAT_00535bc8;
    local_128 = local_128 + 10;
    pdVar5 = pdVar5 + 1;
    *(int *)((int)&DAT_004fbc38 + iVar7) =
         DAT_004f3858 - (int)(longlong)(fVar10 * (float10)_DAT_00535558 * fVar8);
    iVar7 = iVar7 + 4;
  } while (local_128 < 0x15f);
  _DAT_004fb748 = DAT_004fb6b8;
  _DAT_004fbcc8 = DAT_004fbc38;
  if ((DAT_004da19c != 8) || (iVar2 = 1, DAT_004f8b78 != 0)) {
    iVar2 = 2;
  }
  if (DAT_004f4510 == 1) {
    DAT_004fb724 = DAT_004fb724 + -300;
  }
  DAT_004fb750 = DAT_004fb6b8 + 0x1d4c;
  _DAT_004fbcd4 = (int)(6000 / (ulonglong)(longlong)iVar2);
  _DAT_004fb754 = DAT_004fb700 + 0x1d4c;
  _DAT_004fb74c = DAT_004fb6b8;
  DAT_004fb758 = DAT_004fb700;
  _DAT_004fbccc = DAT_004fbc38 - _DAT_004fbcd4;
  _DAT_004fbcd4 = _DAT_004fbcd4 + DAT_004fbc80;
  DAT_004fb760 = DAT_004fb6b8 + -0x1d4c;
  _DAT_004fb75c = DAT_004fb700 + -0x1d4c;
  if (((DAT_004f8b78 == 0) && (DAT_004f69b8 == 0)) && (DAT_004f8db8 == 0)) {
    if (DAT_005230dc == 2) {
      _DAT_00535f64 = DAT_004fbc60;
      _DAT_0052317c = DAT_004fb6e0;
      _DAT_00534ea0 = DAT_004fbc70;
      _DAT_005229cc = DAT_004fb6f0 + 400;
      _DAT_00522e5c = DAT_004fb6d0 + 900;
      _DAT_00522e60 = DAT_004fb6d0 + 1000;
      _DAT_00535278 = DAT_004fbc50;
      _DAT_00535554 = DAT_004fbc50;
      _DAT_004fb208 = DAT_004fb6fc + 700;
      _DAT_004fb9bc = DAT_004fbc7c;
    }
    if (DAT_005230dc == 4) {
      _DAT_00535f64 = DAT_004fbca0;
      _DAT_005229cc = DAT_004fb714 + -200;
      _DAT_0052317c = DAT_004fb720;
      _DAT_00522e5c = DAT_004fb708 + -900;
      _DAT_00534ea0 = DAT_004fbc94;
      _DAT_00522e60 = DAT_004fb708 + -1000;
      _DAT_004fb208 = DAT_004fb73c + -700;
      _DAT_00535278 = DAT_004fbc88;
      _DAT_00535554 = DAT_004fbc88;
      _DAT_004fb9bc = DAT_004fbcbc;
    }
  }
  if (DAT_004f8db8 == 1) {
    _DAT_005229cc = DAT_004fb700;
    _DAT_00534ea0 = DAT_004fbc80 + 500;
    _DAT_0052317c = DAT_004fb6b8;
    _DAT_00535278 = DAT_004fbc74 + 900;
    _DAT_00535554 = DAT_004fbc74 + 1000;
    _DAT_004fb9bc = DAT_004fbcb0 + -700;
    _DAT_00535f64 = DAT_004fbc38;
    _DAT_00522e5c = DAT_004fb6f4;
    _DAT_00522e60 = DAT_004fb6f4;
    _DAT_004fb208 = DAT_004fb730;
  }
  if (DAT_004f69b8 == 1) {
    _DAT_0052317c = DAT_004fb6b8;
    _DAT_005229cc = DAT_004fb720 + -500;
    _DAT_00535f64 = DAT_004fbc38;
    _DAT_00534ea0 = DAT_004fbca0;
    _DAT_00535278 = DAT_004fbc74 + 900;
    _DAT_00535554 = DAT_004fbc74 + 1000;
    _DAT_00522e5c = DAT_004fb6f4;
    _DAT_004fb9bc = DAT_004fbcb0 + -700;
    _DAT_00522e60 = DAT_004fb6f4;
    _DAT_004fb208 = DAT_004fb730;
  }
  if (DAT_004f8b78 == 1) {
    _DAT_0052317c = DAT_00535bc8;
    if (DAT_004da19c == 8) {
      _DAT_00535f64 = DAT_004f3858 + 0x1c2;
    }
    else {
      _DAT_00535f64 = DAT_004f3858 + 200;
    }
    _DAT_005229cc = -1000;
    _DAT_00534ea0 = -4000;
    _DAT_00522e5c = 1000;
    _DAT_00535278 = -6000;
    _DAT_00522e60 = 800;
    _DAT_00535554 = -6000;
    if (DAT_004da19c == 8) {
      _DAT_004fb208 = DAT_00535bc8;
      _DAT_004fb9bc = DAT_004f3858 + -800;
    }
    else {
      _DAT_004fb208 = 1000;
      _DAT_004fb9bc = -4000;
    }
  }
  if (DAT_004f4510 == 1) {
    _DAT_0052317c = DAT_004fb714 + 100;
    _DAT_00535f64 = DAT_004fbc94;
    _DAT_004f3c00 = DAT_004fbcb0;
    _DAT_005229cc = DAT_004fb724 + -0x5dc;
    _DAT_004fe29c = DAT_004fb724 + -1000;
    _DAT_00522e5c = DAT_004fb6c0 + -900;
    _DAT_00534ea0 = DAT_004fbca4 + 100;
    _DAT_004fe810 = DAT_004fbca4 + -200;
    _DAT_00522e60 = DAT_004fb6c4 + -1000;
    _DAT_00535278 = DAT_004fbc40;
    _DAT_004fb208 = DAT_004fb728 + -700;
    _DAT_00535554 = DAT_004fbc44;
    _DAT_004fb9bc = DAT_004fbca8;
    _DAT_00523b10 = DAT_004fb72c + -700;
    _DAT_00523b08 = DAT_004fb730 + -700;
    _DAT_004f3a30 = DAT_004fbcac;
  }
  piVar6 = &DAT_00523084;
  iVar2 = 0;
  DAT_004fbcd0 = _DAT_004fbccc;
  DAT_004fbcd8 = _DAT_004fbcd4;
  _DAT_004fbcdc = _DAT_004fbcd4;
  DAT_004fbce0 = _DAT_004fbccc;
  do {
    iVar7 = FUN_0041e000(0xc);
    iVar3 = iVar7 + 3;
    if (DAT_005230dc == 4) {
      iVar3 = iVar7 + 0x15;
    }
    if (DAT_004f69b8 == 1) {
      iVar3 = FUN_0041e000(0x1e);
      iVar3 = iVar3 + 3;
    }
    if ((iVar3 < 5) || (0x20 < iVar3)) {
      *(int *)((int)&DAT_005116bc + iVar2) = (&DAT_004fb6b8)[iVar3];
      iVar7 = FUN_0041e000(2000);
      *(int *)((int)&DAT_00535ffc + iVar2) = ((&DAT_004fbc38)[iVar3] + -2000) - iVar7;
    }
    if ((iVar3 < 5) && (0xd < iVar3)) {
LAB_0042d93a:
      if (iVar3 < 0x18) {
        *(int *)((int)&DAT_005116bc + iVar2) = (&DAT_004fb6b8)[iVar3];
        iVar7 = FUN_0041e000(2000);
        *(int *)((int)&DAT_00535ffc + iVar2) = iVar7 + 2000 + (&DAT_004fbc38)[iVar3];
        goto LAB_0042d96d;
      }
LAB_0042d972:
      if (iVar3 < 0x21) {
        iVar7 = FUN_0041e000(2000);
        uVar1 = (&DAT_004fbc38)[iVar3];
        *(int *)((int)&DAT_005116bc + iVar2) = iVar7 + -2000 + (&DAT_004fb6b8)[iVar3];
        *(undefined4 *)((int)&DAT_00535ffc + iVar2) = uVar1;
      }
    }
    else {
      iVar7 = FUN_0041e000(2000);
      uVar1 = (&DAT_004fbc38)[iVar3];
      *(int *)((int)&DAT_005116bc + iVar2) = iVar7 + 2000 + (&DAT_004fb6b8)[iVar3];
      *(undefined4 *)((int)&DAT_00535ffc + iVar2) = uVar1;
      if (0xd < iVar3) goto LAB_0042d93a;
LAB_0042d96d:
      if (0x17 < iVar3) goto LAB_0042d972;
    }
    if (DAT_004f8db8 == 1) {
      iVar7 = FUN_0041e000(100);
      if (iVar7 < 0x32) {
        iVar7 = FUN_0041e000(4);
        iVar7 = iVar7 + 2;
      }
      else {
        iVar7 = FUN_0041e000(4);
        iVar7 = iVar7 + 0x1d;
      }
      *(int *)((int)&DAT_005116bc + iVar2) = (&DAT_004fb6b8)[iVar7];
      iVar3 = FUN_0041e000(2000);
      *(int *)((int)&DAT_00535ffc + iVar2) = ((&DAT_004fbc38)[iVar7] + -2000) - iVar3;
    }
    if (DAT_004f4510 == 1) {
      iVar3 = FUN_0041e000(10);
      iVar4 = FUN_0041e000(2000);
      iVar7 = (&DAT_004fb6b8)[iVar3 + 0x16];
      *(int *)((int)&DAT_00535ffc + iVar2) = (&DAT_004fbc38)[iVar3 + 0x16];
      *(int *)((int)&DAT_005116bc + iVar2) = (iVar7 + -2000) - iVar4;
    }
    iVar7 = FUN_0041e000(0x3c);
    iVar2 = iVar2 + 4;
    *piVar6 = iVar7 + 0x28;
    piVar6 = piVar6 + 1;
    if (0x10 < iVar2) {
      return;
    }
  } while( true );
}

