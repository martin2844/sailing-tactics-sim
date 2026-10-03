
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00413370(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  double dVar3;
  double dVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  float10 fVar9;
  uint local_1c;
  double local_18;
  double local_8;
  
  if ((DAT_00491140 < param_3) && (DAT_004ac928 == 1)) {
    return;
  }
  dVar3 = (DAT_004a3a38 - DAT_004a3a40) * _DAT_00484e70;
  if ((DAT_00491188 < 6) || (local_1c = 0x16, 8 < DAT_00491188)) {
    local_1c = 0xf;
  }
  if (DAT_004ac900 == 1) {
    local_1c = 10;
  }
  if ((((DAT_00491140 < param_3) || (6 < DAT_00491188)) ||
      (DAT_004a5b80 < *(int *)(&DAT_004a3a18 + param_3 * 4))) ||
     (*(int *)(&DAT_004a41f0 + param_3 * 4) + DAT_004ac9d4 <= DAT_004a5b80)) {
    iVar7 = 1;
    if ((int)(local_1c / 3) < *(int *)(&DAT_004a6ec8 + param_3 * 4)) {
      iVar7 = 2;
    }
    if (((param_3 <= DAT_00491140) && (DAT_00491188 < 7)) &&
       (DAT_004a5b80 < *(int *)(&DAT_004a41f0 + param_3 * 4) + DAT_004ac9d4)) {
      iVar7 = 2;
    }
    if (DAT_004ac90c == 1) {
      iVar7 = 2;
    }
    if ((DAT_00491188 == 1) && (param_3 <= DAT_00491140)) {
      *(undefined4 *)(&DAT_004a3a18 + param_3 * 4) = 20000;
    }
  }
  else {
    iVar7 = -1;
  }
  fVar9 = FUN_004139d0(iVar7);
  if ((DAT_0049114c == 1) && (DAT_00491188 == 7)) {
    fVar9 = (float10)_DAT_00484e10;
  }
  iVar1 = *(int *)(&DAT_004aa730 + param_3 * 4);
  if (DAT_004ac900 == 0) {
    dVar4 = _DAT_004ac388;
    if (0 < iVar7 * iVar1) {
      dVar4 = _DAT_004ac348;
    }
    local_18 = (double)((fVar9 * (float10)dVar4 + (float10)DAT_004ac318) /
                       (fVar9 - (float10)_DAT_00484e78));
    if (DAT_004ac90c == 1) {
      local_18 = local_18 - (double)iVar1 * dVar3 * _DAT_00484d60;
    }
    if (((DAT_004ac904 == 1) && (*(int *)(&DAT_004a8aa8 + param_3 * 4) < 0x50)) &&
       (uVar5 = (int)(longlong)_DAT_004abef0 + param_3, uVar6 = (int)uVar5 >> 0x1f,
       ((uVar5 ^ uVar6) - uVar6 & 3 ^ uVar6) == uVar6)) {
      local_18 = local_18 - _DAT_00484e80;
    }
    local_8 = DAT_004a3a40 - dVar3;
    if (DAT_00491188 == 1) {
      local_8 = local_8 - dVar3 * _DAT_00484e88;
    }
  }
  if (DAT_004ac900 == 1) {
    dVar4 = _DAT_004ac390;
    if (0 < iVar7 * iVar1) {
      dVar4 = _DAT_004ac348;
    }
    local_18 = (double)((fVar9 * (float10)dVar4 + (float10)DAT_004ac318) /
                       (fVar9 - (float10)_DAT_00484e78));
    if (iVar7 == 2) {
      if (DAT_00491188 == 10) {
        local_18 = local_18 - (double)iVar1 * dVar3 * _DAT_00484e90;
      }
      if (DAT_00491188 == 9) {
        local_18 = local_18 - (double)iVar1 * dVar3 * _DAT_00484e80;
      }
    }
    local_8 = (DAT_004a3a40 + _DAT_004a3a48) * _DAT_00484da8 - dVar3;
  }
  FUN_00413a20(local_18,local_8,dVar3,(double)CONCAT44(param_2,param_1),0x27,param_3,1,param_4,iVar7
              );
  iVar1 = DAT_00491188;
  iVar7 = DAT_00491140;
  if (DAT_00491188 < 2) {
    return;
  }
  if (((DAT_00491140 < param_3) || (6 < DAT_00491188)) ||
     ((DAT_004a5b80 < *(int *)(&DAT_004a3a18 + param_3 * 4) ||
      (*(int *)(&DAT_004a41f0 + param_3 * 4) + DAT_004ac9d4 <= DAT_004a5b80)))) {
    if (((1 < DAT_00491188) && (DAT_00491188 < 4)) && (param_3 <= DAT_00491140)) {
      *(undefined4 *)(&DAT_004a3a18 + param_3 * 4) = 20000;
    }
    iVar2 = *(int *)(&DAT_004a6ec8 + param_3 * 4);
    uVar5 = 1;
    if ((int)(local_1c / 3) < iVar2) {
      uVar5 = 2;
    }
    if (((param_3 <= iVar7) && (iVar1 < 7)) &&
       (DAT_004a5b80 < *(int *)(&DAT_004a41f0 + param_3 * 4) + DAT_004ac9d4)) {
      uVar5 = 2;
    }
    if (((iVar2 < 5) && (uVar5 = (uint)(iVar1 == 7), iVar2 < 5)) &&
       ((iVar1 == 9 && (0x78 < *(int *)(&DAT_004a7bc8 + param_3 * 4))))) {
      uVar5 = 0xfffffffe;
    }
  }
  else {
    uVar5 = 0xffffffff;
  }
  fVar9 = FUN_004139d0(uVar5);
  iVar7 = *(int *)(&DAT_004aa730 + param_3 * 4);
  if (DAT_004ac900 == 0) {
    dVar4 = _DAT_004ac380;
    if (0 < (int)(uVar5 * iVar7)) {
      dVar4 = _DAT_004ac350;
    }
    local_18 = (double)((fVar9 * (float10)dVar4 + (float10)_DAT_004ac320) /
                       (fVar9 - (float10)_DAT_00484e78));
    if (uVar5 == 2) {
      if (DAT_00491188 == 3) {
        local_18 = local_18 - (double)iVar7 * dVar3 * _DAT_00484e98;
      }
      if (DAT_004ac90c == 1) {
        local_18 = local_18 - (double)iVar7 * dVar3 * _DAT_00484e90;
      }
    }
    local_8 = _DAT_004a3a48 - dVar3 * _DAT_00484e78;
  }
  if (DAT_004ac900 == 1) {
    dVar4 = _DAT_004ac380;
    if (0 < (int)(uVar5 * iVar7)) {
      dVar4 = _DAT_004ac358;
    }
    local_18 = (double)((fVar9 * (float10)dVar4 + (float10)_DAT_004ac328) /
                       (fVar9 - (float10)_DAT_00484e78));
    if (uVar5 == 2) {
      local_18 = local_18 - (double)iVar7 * dVar3 * _DAT_00484e90;
    }
    local_8 = dVar3 - (_DAT_004a3a48 + _DAT_004a3a50) * _DAT_00484ea0;
  }
  FUN_00413a20(local_18,local_8,dVar3,(double)CONCAT44(param_2,param_1),0x2d,param_3,2,param_4,uVar5
              );
  iVar2 = DAT_004a5b80;
  iVar1 = DAT_00491188;
  iVar7 = DAT_00491140;
  if (DAT_00491188 < 4) {
    return;
  }
  if (DAT_004ac900 == 1) {
    return;
  }
  if (DAT_00491140 < param_3) {
LAB_004138c5:
    if ((DAT_00491188 < 7) && (param_3 <= DAT_00491140)) {
      *(undefined4 *)(&DAT_004a3a18 + param_3 * 4) = 20000;
    }
  }
  else if (DAT_00491188 < 7) {
    if ((*(int *)(&DAT_004a3a18 + param_3 * 4) <= DAT_004a5b80) &&
       (DAT_004a5b80 < *(int *)(&DAT_004a41f0 + param_3 * 4) + DAT_004ac9d4)) {
      iVar8 = -1;
      goto LAB_00413933;
    }
    goto LAB_004138c5;
  }
  iVar8 = 1;
  if ((int)(local_1c / 3) < *(int *)(&DAT_004a6ec8 + param_3 * 4)) {
    iVar8 = 2;
  }
  if (((param_3 <= iVar7) && (iVar1 < 7)) &&
     (iVar2 < *(int *)(&DAT_004a41f0 + param_3 * 4) + DAT_004ac9d4)) {
    iVar8 = 2;
  }
  if ((*(int *)(&DAT_004a6ec8 + param_3 * 4) < 7) && (iVar1 != 7)) {
    iVar8 = 0;
  }
LAB_00413933:
  fVar9 = FUN_004139d0(iVar8);
  dVar4 = _DAT_004ac378;
  if (0 < iVar8 * *(int *)(&DAT_004aa730 + param_3 * 4)) {
    dVar4 = _DAT_004ac358;
  }
  FUN_00413a20((double)((fVar9 * (float10)dVar4 + (float10)_DAT_004ac328) /
                       (fVar9 - (float10)_DAT_00484e78)),_DAT_004a3a50 - dVar3 * _DAT_00484e98,dVar3
               ,(double)CONCAT44(param_2,param_1),0x33,param_3,3,param_4,iVar8);
  return;
}

