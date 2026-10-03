
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041fd90(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  float10 fVar9;
  int local_c;
  
  if ((DAT_00491194 == 9) || (DAT_00491194 == 10)) {
    iVar5 = FUN_00415a20(0x50);
    iVar5 = iVar5 + 0x5a;
    iVar7 = FUN_00415a20(0xfa);
    iVar7 = iVar7 + 200;
  }
  else {
    iVar5 = 0x82;
    iVar7 = 0x145;
  }
  DAT_004a6490 = 0xffffea84;
  DAT_004a6494 = 0xffffea84;
  DAT_004a68cc = DAT_004aa290;
  DAT_004a68c8 = DAT_004aa290 * 6;
  if ((DAT_00491194 == 9) || (DAT_00491194 == 10)) {
    local_c = 0x32;
  }
  else {
    local_c = FUN_00415a20(100);
  }
  iVar8 = 2;
  do {
    iVar3 = FUN_00415a20(0x28);
    iVar4 = (iVar8 + -0x12) * 0xfa;
    (&DAT_004a6490)[iVar8] = iVar4;
    iVar2 = DAT_004aa290;
    iVar1 = DAT_004a8e8c;
    fVar9 = (float10)fsin((float10)((iVar4 + local_c) / iVar7));
    iVar3 = (int)(longlong)(fVar9 * (float10)(iVar3 + iVar5)) * DAT_004a8e8c + DAT_004aa290;
    (&DAT_004a68c8)[iVar8] = iVar3;
    if (iVar8 == 2) {
      DAT_004a68d0 = iVar3 + iVar1 * -100;
    }
    if (iVar8 == 3) {
      DAT_004a68d4 = DAT_004a68d4 + iVar1 * -300;
    }
    if (iVar8 == 4) {
      DAT_004a68d8 = DAT_004a68d8 + iVar1 * -600;
    }
    if (iVar8 == 5) {
      DAT_004a68dc = DAT_004a68dc + iVar1 * -1000;
    }
    if ((iVar8 == 6) || (iVar8 == 7)) {
      (&DAT_004a68c8)[iVar8] = iVar2 + iVar1 * -4000;
    }
    if (iVar8 == 8) {
      DAT_004a68e8 = DAT_004a68e8 + iVar1 * -1000;
    }
    if (iVar8 == 9) {
      DAT_004a68ec = DAT_004a68ec + iVar1 * -500;
    }
    if (iVar8 == 10) {
      DAT_004a68f0 = DAT_004a68f0 + iVar1 * -100;
    }
    iVar8 = iVar8 + 1;
  } while (iVar8 < 0x24);
  _DAT_004a6520 = 0x157c;
  _DAT_004a6524 = 0x157c;
  _DAT_004a6958 = iVar2;
  _DAT_004ac5ec = DAT_004a68f0;
  _DAT_004aa818 = DAT_004a64b8;
  _DAT_004a695c = iVar1 * -6000;
  if (DAT_004aa804 == 1) {
    _DAT_004ab9d0 = DAT_004a690c + -500;
    _DAT_004aa28c = DAT_004a64d4;
    if (DAT_00491194 == 9) {
      _DAT_004aa654 = DAT_004a64a8 + -100;
      _DAT_004aa658 = DAT_004a64a8;
      _DAT_004abe5c = DAT_004a68e0;
    }
    else {
      _DAT_004aa654 = DAT_004a6500;
      _DAT_004aa658 = DAT_004a6500;
      _DAT_004abe5c = DAT_004a6938;
    }
    _DAT_004abc84 = _DAT_004abe5c + -900;
    _DAT_004abe5c = _DAT_004abe5c + -1000;
    if (DAT_00491194 == 9) {
      _DAT_004a677c = DAT_004a68d8 + -0x44c;
      _DAT_004a61e0 = DAT_004a64a0;
      goto LAB_0042012d;
    }
    _DAT_004a677c = DAT_004a6940 + -0x44c;
  }
  else {
    if (DAT_00491194 == 10) {
      _DAT_004aa28c = DAT_004a64a8;
      _DAT_004ab9d0 = DAT_004a68e0 + 700;
    }
    else {
      _DAT_004aa28c = DAT_004a64dc;
      _DAT_004ab9d0 = DAT_004a6914 + 500;
    }
    _DAT_004aa654 = DAT_004a64f4;
    _DAT_004aa658 = DAT_004a64f4;
    _DAT_004abc84 = DAT_004a692c + 900;
    _DAT_004abe5c = DAT_004a692c + 1000;
    if (DAT_00491194 == 10) {
      _DAT_004a677c = DAT_004a68d8 + 0x44c;
      _DAT_004a61e0 = DAT_004a64a0;
      goto LAB_0042012d;
    }
    _DAT_004a677c = DAT_004a6940 + 0x44c;
  }
  _DAT_004a61e0 = DAT_004a6508;
LAB_0042012d:
  piVar6 = &DAT_004aa7b4;
  iVar5 = 9;
  iVar7 = 0;
  do {
    iVar8 = FUN_00415a20(0x1c);
    *(undefined4 *)((int)&DAT_004a899c + iVar7) = (&DAT_004a649c)[iVar8];
    *(int *)((int)&DAT_004ac674 + iVar7) = (&DAT_004a68c8)[iVar8 + 3] + DAT_004a8e8c * iVar5 * -500;
    iVar8 = FUN_00415a20(0x3c);
    *piVar6 = iVar8 + 0x28;
    iVar5 = iVar5 + -1;
    iVar7 = iVar7 + 4;
    piVar6 = piVar6 + 1;
  } while (4 < iVar5);
  return;
}

