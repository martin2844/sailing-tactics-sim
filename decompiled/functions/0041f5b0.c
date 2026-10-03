
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041f5b0(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  double *pdVar7;
  float10 fVar8;
  float10 fVar9;
  float10 fVar10;
  int local_128;
  double local_120 [36];
  
  DAT_004abae8 = 3000;
  iVar6 = 0;
  DAT_004ac284 = 0;
  DAT_004a3a08 = 0;
  iVar2 = FUN_00415a20(200);
  DAT_004a3a08 = iVar2 + -100;
  if (DAT_004aa804 == 2) {
    DAT_004ac284 = -0x4e2;
  }
  if (DAT_004aa804 == 4) {
    DAT_004ac284 = 0x4e2;
  }
  if (DAT_004a4958 == 1) {
    DAT_004ac284 = 0;
    DAT_004a3a08 = 0;
    DAT_004abae8 = 0x4e2;
  }
  if (1 < DAT_004a4958) {
    DAT_004ac284 = 0;
    DAT_004a3a08 = 0;
  }
  if ((DAT_004a5a4c == 1) && (DAT_00491194 != 8)) {
    DAT_004ac284 = 500;
    DAT_004a3a08 = 0;
    DAT_004abae8 = 0x1a4;
  }
  if ((DAT_004a5a4c == 1) && (DAT_00491194 == 8)) {
    DAT_004a3a08 = 0;
    DAT_004ac284 = 700;
    DAT_004abae8 = 700;
  }
  if (DAT_004a5b9c == 1) {
    DAT_004ac284 = 0;
    DAT_004a3a08 = 0;
    DAT_004abae8 = (-(uint)(DAT_00491194 != 8) & 0xfffffb82) + 0x9c4;
  }
  pdVar7 = local_120;
  local_128 = 0;
  iVar2 = DAT_004abae8;
  do {
    iVar3 = FUN_00415a20(iVar2 / 0x14);
    iVar2 = DAT_004abae8;
    fVar8 = (float10)(iVar3 + DAT_004abae8);
    *pdVar7 = (double)(iVar3 + DAT_004abae8);
    fVar9 = (float10)fsin((float10)local_128 * (float10)_DAT_00484d40);
    fVar10 = (float10)fcos((float10)local_128 * (float10)_DAT_00484d40);
    *(int *)((int)&DAT_004a6490 + iVar6) =
         (int)(longlong)(fVar9 * (float10)_DAT_004a6470 * fVar8) + DAT_004ac284;
    local_128 = local_128 + 10;
    pdVar7 = pdVar7 + 1;
    *(int *)((int)&DAT_004a68c8 + iVar6) =
         DAT_004a3a08 - (int)(longlong)(fVar10 * (float10)_DAT_004abe60 * fVar8);
    iVar6 = iVar6 + 4;
  } while (local_128 < 0x15f);
  _DAT_004a6520 = DAT_004a6490;
  _DAT_004a6958 = DAT_004a68c8;
  if ((DAT_00491194 != 8) || (iVar2 = 1, DAT_004a5a4c != 0)) {
    iVar2 = 2;
  }
  if (DAT_004a4378 == 1) {
    DAT_004a64fc = DAT_004a64fc + -300;
  }
  DAT_004a6528 = DAT_004a6490 + 0x1d4c;
  _DAT_004a6964 = (int)(6000 / (ulonglong)(longlong)iVar2);
  _DAT_004a652c = DAT_004a64d8 + 0x1d4c;
  _DAT_004a6524 = DAT_004a6490;
  DAT_004a6530 = DAT_004a64d8;
  _DAT_004a695c = DAT_004a68c8 - _DAT_004a6964;
  _DAT_004a6964 = _DAT_004a6964 + DAT_004a6910;
  DAT_004a6538 = DAT_004a6490 + -0x1d4c;
  _DAT_004a6534 = DAT_004a64d8 + -0x1d4c;
  if (((DAT_004a5a4c == 0) && (DAT_004a4958 == 0)) && (DAT_004a5b9c == 0)) {
    if (DAT_004aa804 == 2) {
      _DAT_004ac5ec = DAT_004a68f0;
      _DAT_004aa818 = DAT_004a64b8;
      _DAT_004ab9d0 = DAT_004a6900;
      _DAT_004aa28c = DAT_004a64c8 + 400;
      _DAT_004aa654 = DAT_004a64a8 + 900;
      _DAT_004aa658 = DAT_004a64a8 + 1000;
      _DAT_004abc84 = DAT_004a68e0;
      _DAT_004abe5c = DAT_004a68e0;
      _DAT_004a61e0 = DAT_004a64d4 + 700;
      _DAT_004a677c = DAT_004a690c;
    }
    if (DAT_004aa804 == 4) {
      _DAT_004ac5ec = DAT_004a6930;
      _DAT_004aa28c = DAT_004a64ec + -200;
      _DAT_004aa818 = DAT_004a64f8;
      _DAT_004aa654 = DAT_004a64e0 + -900;
      _DAT_004ab9d0 = DAT_004a6924;
      _DAT_004aa658 = DAT_004a64e0 + -1000;
      _DAT_004a61e0 = DAT_004a6514 + -700;
      _DAT_004abc84 = DAT_004a6918;
      _DAT_004abe5c = DAT_004a6918;
      _DAT_004a677c = DAT_004a694c;
    }
  }
  if (DAT_004a5b9c == 1) {
    _DAT_004aa28c = DAT_004a64d8;
    _DAT_004ab9d0 = DAT_004a6910 + 500;
    _DAT_004aa818 = DAT_004a6490;
    _DAT_004abc84 = DAT_004a6904 + 900;
    _DAT_004abe5c = DAT_004a6904 + 1000;
    _DAT_004a677c = DAT_004a6940 + -700;
    _DAT_004ac5ec = DAT_004a68c8;
    _DAT_004aa654 = DAT_004a64cc;
    _DAT_004aa658 = DAT_004a64cc;
    _DAT_004a61e0 = DAT_004a6508;
  }
  if (DAT_004a4958 == 1) {
    _DAT_004aa818 = DAT_004a6490;
    _DAT_004aa28c = DAT_004a64f8 + -500;
    _DAT_004ac5ec = DAT_004a68c8;
    _DAT_004ab9d0 = DAT_004a6930;
    _DAT_004abc84 = DAT_004a6904 + 900;
    _DAT_004abe5c = DAT_004a6904 + 1000;
    _DAT_004aa654 = DAT_004a64cc;
    _DAT_004a677c = DAT_004a6940 + -700;
    _DAT_004aa658 = DAT_004a64cc;
    _DAT_004a61e0 = DAT_004a6508;
  }
  if (DAT_004a5a4c == 1) {
    _DAT_004aa818 = DAT_004ac284;
    if (DAT_00491194 == 8) {
      _DAT_004ac5ec = DAT_004a3a08 + 0x1c2;
    }
    else {
      _DAT_004ac5ec = DAT_004a3a08 + 200;
    }
    _DAT_004aa28c = -1000;
    _DAT_004ab9d0 = -4000;
    _DAT_004aa654 = 1000;
    _DAT_004abc84 = -6000;
    _DAT_004aa658 = 800;
    _DAT_004abe5c = -6000;
    if (DAT_00491194 == 8) {
      _DAT_004a61e0 = DAT_004ac284;
      _DAT_004a677c = DAT_004a3a08 + -800;
    }
    else {
      _DAT_004a61e0 = 1000;
      _DAT_004a677c = -4000;
    }
  }
  if (DAT_004a4378 == 1) {
    _DAT_004aa818 = DAT_004a64ec + 100;
    _DAT_004ac5ec = DAT_004a6924;
    _DAT_004a3c00 = DAT_004a6940;
    _DAT_004aa28c = DAT_004a64fc + -0x5dc;
    _DAT_004a72c4 = DAT_004a64fc + -1000;
    _DAT_004aa654 = DAT_004a6498 + -900;
    _DAT_004ab9d0 = DAT_004a6934 + 100;
    _DAT_004a77e4 = DAT_004a6934 + -200;
    _DAT_004aa658 = DAT_004a649c + -1000;
    _DAT_004abc84 = DAT_004a68d0;
    _DAT_004a61e0 = DAT_004a6500 + -700;
    _DAT_004abe5c = DAT_004a68d4;
    _DAT_004a677c = DAT_004a6938;
    _DAT_004aaec8 = DAT_004a6504 + -700;
    _DAT_004aaec0 = DAT_004a6508 + -700;
    _DAT_004a3a30 = DAT_004a693c;
  }
  piVar5 = &DAT_004aa7b4;
  iVar2 = 0;
  DAT_004a6960 = _DAT_004a695c;
  DAT_004a6968 = _DAT_004a6964;
  _DAT_004a696c = _DAT_004a6964;
  DAT_004a6970 = _DAT_004a695c;
  do {
    iVar6 = FUN_00415a20(0xc);
    iVar3 = iVar6 + 3;
    if (DAT_004aa804 == 4) {
      iVar3 = iVar6 + 0x15;
    }
    if (DAT_004a4958 == 1) {
      iVar3 = FUN_00415a20(0x1e);
      iVar3 = iVar3 + 3;
    }
    if ((iVar3 < 5) || (0x20 < iVar3)) {
      *(int *)((int)&DAT_004a899c + iVar2) = (&DAT_004a6490)[iVar3];
      iVar6 = FUN_00415a20(2000);
      *(int *)((int)&DAT_004ac674 + iVar2) = ((&DAT_004a68c8)[iVar3] + -2000) - iVar6;
    }
    if ((iVar3 < 5) && (0xd < iVar3)) {
LAB_0041fc4f:
      if (iVar3 < 0x18) {
        *(int *)((int)&DAT_004a899c + iVar2) = (&DAT_004a6490)[iVar3];
        iVar6 = FUN_00415a20(2000);
        *(int *)((int)&DAT_004ac674 + iVar2) = iVar6 + 2000 + (&DAT_004a68c8)[iVar3];
        goto LAB_0041fc82;
      }
LAB_0041fc87:
      if (iVar3 < 0x21) {
        iVar6 = FUN_00415a20(2000);
        uVar1 = (&DAT_004a68c8)[iVar3];
        *(int *)((int)&DAT_004a899c + iVar2) = iVar6 + -2000 + (&DAT_004a6490)[iVar3];
        *(undefined4 *)((int)&DAT_004ac674 + iVar2) = uVar1;
      }
    }
    else {
      iVar6 = FUN_00415a20(2000);
      uVar1 = (&DAT_004a68c8)[iVar3];
      *(int *)((int)&DAT_004a899c + iVar2) = iVar6 + 2000 + (&DAT_004a6490)[iVar3];
      *(undefined4 *)((int)&DAT_004ac674 + iVar2) = uVar1;
      if (0xd < iVar3) goto LAB_0041fc4f;
LAB_0041fc82:
      if (0x17 < iVar3) goto LAB_0041fc87;
    }
    if (DAT_004a5b9c == 1) {
      iVar6 = FUN_00415a20(100);
      if (iVar6 < 0x32) {
        iVar6 = FUN_00415a20(4);
        iVar6 = iVar6 + 2;
      }
      else {
        iVar6 = FUN_00415a20(4);
        iVar6 = iVar6 + 0x1d;
      }
      *(int *)((int)&DAT_004a899c + iVar2) = (&DAT_004a6490)[iVar6];
      iVar3 = FUN_00415a20(2000);
      *(int *)((int)&DAT_004ac674 + iVar2) = ((&DAT_004a68c8)[iVar6] + -2000) - iVar3;
    }
    if (DAT_004a4378 == 1) {
      iVar3 = FUN_00415a20(10);
      iVar4 = FUN_00415a20(2000);
      iVar6 = (&DAT_004a6490)[iVar3 + 0x16];
      *(int *)((int)&DAT_004ac674 + iVar2) = (&DAT_004a68c8)[iVar3 + 0x16];
      *(int *)((int)&DAT_004a899c + iVar2) = (iVar6 + -2000) - iVar4;
    }
    iVar6 = FUN_00415a20(0x3c);
    iVar2 = iVar2 + 4;
    *piVar5 = iVar6 + 0x28;
    piVar5 = piVar5 + 1;
    if (0x10 < iVar2) {
      return;
    }
  } while( true );
}

