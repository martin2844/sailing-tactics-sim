
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00482ae0(int *param_1,int param_2,int param_3,double param_4,double param_5,double param_6,
            double param_7,double param_8,int param_9)

{
  int iVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  double *pdVar5;
  int iVar6;
  float10 fVar7;
  float10 fVar8;
  double local_1a8;
  int *piStack_19c;
  code *local_198 [2];
  double local_190;
  int iStack_184;
  double local_180;
  int iStack_174;
  int aiStack_170 [10];
  int aiStack_148 [10];
  undefined4 auStack_120 [2];
  undefined8 local_118;
  double local_110;
  double local_108;
  double local_100;
  double local_f8;
  double local_f0;
  double local_e8;
  double local_e0;
  double local_d8;
  undefined4 auStack_d0 [2];
  undefined8 local_c8;
  double local_c0;
  double local_b8;
  double local_b0;
  double local_a8;
  double local_a0;
  double local_98;
  double local_90;
  double local_88;
  int aiStack_80 [10];
  undefined8 uStack_58;
  undefined8 local_50;
  double local_40;
  
  iVar4 = 0x3c;
  if ((((DAT_004da1f8 == 9) || (DAT_004da1f8 == 10)) || (DAT_004da1f8 == 100)) ||
     (DAT_004da1f8 == 0x6a)) {
    iVar4 = 0x37;
  }
  if (((((DAT_004da1f8 == 2) || (DAT_004da1f8 == 3)) ||
       ((DAT_004da1f8 == 4 || ((DAT_004da1f8 == 6 || (DAT_004da1f8 == 0xb)))))) ||
      (DAT_004da1f8 == 0xc)) ||
     (((DAT_004da1f8 == 0x65 || (DAT_004da1f8 == 0x68)) || (DAT_004da1f8 == 0x69)))) {
    iVar4 = 0x32;
  }
  _DAT_005364e4 = 1;
  fVar7 = (float10)FUN_00465e90(param_2,param_3,0,param_9);
  iVar1 = (int)(longlong)(fVar7 * (float10)_DAT_004cc3e8);
  if (iVar4 < iVar1) {
    return;
  }
  if (iVar1 < -iVar4) {
    return;
  }
  fVar7 = (float10)fsin((float10)param_5 * (float10)_DAT_004cc568);
  fVar8 = (float10)fcos((float10)(double)((float10)param_5 * (float10)_DAT_004cc568));
  local_190 = param_6 * param_4 * (double)(fVar8 * (float10)param_7);
  local_b8 = (double)param_2;
  local_180 = param_6 * param_4 * (double)(fVar7 * (float10)param_7);
  local_108 = (double)param_3;
  local_a8 = param_4 * (double)(fVar7 * (float10)param_7);
  local_1a8 = param_4 * (double)(fVar8 * (float10)param_7);
  local_c8 = local_b8 + local_a8;
  local_a8 = local_b8 - local_a8;
  local_88 = local_b8 + local_190;
  local_d8 = local_108 - local_180;
  local_118 = local_108 - local_1a8;
  local_f8 = local_108 + local_1a8;
  local_c0 = (local_b8 + local_c8) * _DAT_004cc4f8;
  local_110 = (local_108 + (local_108 - local_1a8)) * _DAT_004cc4f8;
  local_b0 = (local_b8 + local_a8) * _DAT_004cc4f8;
  iVar4 = 1;
  local_100 = (local_108 + local_108 + local_1a8) * _DAT_004cc4f8;
  local_90 = (local_b8 + local_190 + local_b8) * _DAT_004cc4f8;
  local_e0 = ((local_108 - local_180) + local_108) * _DAT_004cc4f8;
  local_a0 = local_b8 - local_190;
  local_f0 = local_108 + local_180;
  local_98 = ((local_b8 - local_190) + local_b8) * _DAT_004cc4f8;
  local_e8 = (local_108 + local_180 + local_108) * _DAT_004cc4f8;
  do {
    FUN_0043e730(0,(double)CONCAT44(auStack_d0[iVar4 * 2 + 1],auStack_d0[iVar4 * 2]),
                 (double)CONCAT44(auStack_120[iVar4 * 2 + 1],auStack_120[iVar4 * 2]),param_9,5);
    aiStack_170[iVar4] = DAT_004fed58;
    aiStack_148[iVar4] = DAT_00523660;
    if (((iVar4 == 2) || (iVar4 == 8)) || ((iVar4 == 4 || (iVar4 == 7)))) {
      pdVar5 = (double *)(&uStack_58 + iVar4);
      fVar7 = (float10)FUN_00406220(aiStack_148[iVar4],param_9);
      *pdVar5 = (double)(fVar7 * (float10)param_8 * (float10)param_4);
    }
    else {
      pdVar5 = (double *)(&uStack_58 + iVar4);
      *(undefined4 *)pdVar5 = 0;
      *(undefined4 *)((int)&uStack_58 + iVar4 * 8 + 4) = 0;
    }
    if (iVar4 == 3) {
      fVar7 = (float10)FUN_00406220(aiStack_148[3],param_9);
      local_40 = (double)(fVar7 * (float10)param_4);
    }
    aiStack_80[iVar4] = (int)(longlong)*pdVar5;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 10);
  FUN_00484270(param_1);
  iVar1 = aiStack_148[6];
  iVar4 = aiStack_170[6];
  _DAT_004f6e28 = aiStack_170[1];
  _DAT_004f6e2c = aiStack_148[1];
  _DAT_004f6e38 = aiStack_170[5];
  _DAT_004f6e30 = aiStack_170[6];
  _DAT_004f6e34 = aiStack_148[6];
  _DAT_004f6e3c = aiStack_148[5];
  _DAT_004f6e40 = aiStack_170[9];
  _DAT_004f6e44 = aiStack_148[9];
  Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
  local_198[0] = *(code **)(*param_1 + 0x2c);
  (*local_198[0])(param_1,8);
  _DAT_004f6e30 = aiStack_170[7];
  _DAT_004f6e34 = aiStack_148[7] - aiStack_80[7];
  _DAT_004f6e28 = iVar4;
  iVar6 = aiStack_148[3] - aiStack_80[3];
  _DAT_004f6e44 = aiStack_148[8] - aiStack_80[8];
  _DAT_004f6e2c = iVar1;
  local_180 = (double)CONCAT44(local_180._4_4_,_DAT_004f6e44);
  _DAT_004f6e38 = aiStack_170[3];
  _DAT_004f6e40 = aiStack_170[8];
  _DAT_004f6e48 = aiStack_170[9];
  _DAT_004f6e4c = aiStack_148[9];
  _DAT_004f6e3c = iVar6;
  iStack_174 = _DAT_004f6e34;
  Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,5);
  (*local_198[0])(param_1,7);
  FUN_004b4d9d(param_1,(int *)&local_1a8,aiStack_170[6],aiStack_148[6]);
  CDC::LineTo(param_1,aiStack_170[7],iStack_174);
  CDC::LineTo(param_1,aiStack_170[3],iVar6);
  FUN_004b4d9d(param_1,(int *)&local_1a8,aiStack_170[3],iVar6);
  CDC::LineTo(param_1,aiStack_170[8],local_180._0_4_);
  CDC::LineTo(param_1,aiStack_170[9],aiStack_148[9]);
  FUN_00484270(param_1);
  _DAT_004f6e28 = aiStack_170[1];
  _DAT_004f6e30 = aiStack_170[2];
  _DAT_004f6e2c = aiStack_148[1];
  _DAT_004f6e34 = aiStack_148[2] - aiStack_80[2];
  local_190 = (double)CONCAT44(local_190._4_4_,_DAT_004f6e34);
  _DAT_004f6e40 = aiStack_170[4];
  _DAT_004f6e44 = aiStack_148[4] - aiStack_80[4];
  _DAT_004f6e38 = aiStack_170[3];
  local_1a8 = (double)CONCAT44(local_1a8._4_4_,_DAT_004f6e44);
  _DAT_004f6e48 = aiStack_170[5];
  _DAT_004f6e4c = aiStack_148[5];
  _DAT_004f6e3c = iVar6;
  Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,5);
  (*local_198[0])(param_1,7);
  local_198[0] = (code *)0x0;
  iStack_184 = *(int *)(&DAT_004fbb90 + param_9 * 4);
  piStack_19c = (int *)(longlong)param_5;
  iVar4 = FUN_0041bc20((int)piStack_19c);
  uVar3 = iStack_184 - iVar4 >> 0x1f;
  if (((int)((iStack_184 - iVar4 ^ uVar3) - uVar3) < 0x1e) ||
     (iVar4 = FUN_0041bc20((int)piStack_19c), uVar3 = iStack_184 - iVar4 >> 0x1f,
     pcVar2 = local_198[0], 0x14a < (int)((iStack_184 - iVar4 ^ uVar3) - uVar3))) {
    pcVar2 = (code *)0x1;
  }
  if (pcVar2 == (code *)0x0) {
    FUN_004b4d9d(param_1,(int *)local_198,aiStack_170[1],aiStack_148[1]);
    CDC::LineTo(param_1,aiStack_170[2],local_190._0_4_);
    CDC::LineTo(param_1,aiStack_170[3],iVar6);
  }
  local_198[0] = (code *)0x0;
  iVar4 = FUN_0041bc20((int)piStack_19c);
  uVar3 = iStack_184 - iVar4 >> 0x1f;
  if ((int)((iStack_184 - iVar4 ^ uVar3) - uVar3) < 0xd2) {
    iVar4 = FUN_0041bc20((int)piStack_19c);
    uVar3 = iStack_184 - iVar4 >> 0x1f;
    pcVar2 = (code *)0x1;
    if (0x96 < (int)((iStack_184 - iVar4 ^ uVar3) - uVar3)) goto LAB_00483174;
  }
  pcVar2 = local_198[0];
LAB_00483174:
  if (pcVar2 == (code *)0x0) {
    FUN_004b4d9d(param_1,(int *)&local_190,aiStack_170[3],iVar6);
    CDC::LineTo(param_1,aiStack_170[4],local_1a8._0_4_);
    CDC::LineTo(param_1,aiStack_170[5],aiStack_148[5]);
  }
  if ((int)(longlong)_DAT_004f6c40 < param_2) {
    FUN_004b4d9d(param_1,(int *)&local_1a8,aiStack_170[6],aiStack_148[6]);
    CDC::LineTo(param_1,aiStack_170[7],iStack_174);
    CDC::LineTo(param_1,aiStack_170[3],iVar6);
  }
  if (param_2 < (int)(longlong)_DAT_004f6c40) {
    FUN_004b4d9d(param_1,(int *)&local_1a8,aiStack_170[3],iVar6);
    CDC::LineTo(param_1,aiStack_170[8],local_180._0_4_);
    CDC::LineTo(param_1,aiStack_170[9],aiStack_148[9]);
  }
  if (DAT_005364f4 == 1) {
    if (DAT_00536450 == 0) {
      if (DAT_005125f4 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_005125f4);
      }
      if (DAT_00535c64 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_00535c64);
      }
    }
    else {
      FUN_00471160(param_1);
    }
    iVar4 = aiStack_80[3] / 6;
    _DAT_004f6e28 = aiStack_170[3] - iVar4;
    _DAT_004f6e34 = iVar6 + iVar4 * -5;
    _DAT_004f6e38 = iVar4 + aiStack_170[3];
    _DAT_004f6e2c = iVar6;
    _DAT_004f6e30 = _DAT_004f6e28;
    _DAT_004f6e3c = _DAT_004f6e34;
    _DAT_004f6e40 = _DAT_004f6e38;
    _DAT_004f6e44 = iVar6;
    if (0 < iVar4) {
      Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
    }
  }
  if ((DAT_005363e0 != 1) && (DAT_004da174 < 0xc)) {
    piStack_19c = &DAT_00512d78;
    local_198[0] = (code *)&DAT_00512d9c;
    local_1a8 = (double)CONCAT44(local_1a8._4_4_,aiStack_80[3] * 2);
    do {
      local_190 = (double)CONCAT44(local_190._4_4_,
                                   ((aiStack_80[3] * *(int *)local_198[0] * 4) / 100 +
                                   aiStack_170[3]) - local_1a8._0_4_);
      iVar4 = aiStack_148[3] - (aiStack_80[3] * *piStack_19c) / 0x8c;
      if (DAT_004f7084 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004f7084);
      }
      FUN_00424320(param_1,local_190._0_4_,iVar4,1);
      local_198[0] = local_198[0] + 4;
      piStack_19c = piStack_19c + 2;
    } while ((int)local_198[0] < 0x512e35);
    _DAT_005364e4 = 0;
  }
  return;
}

