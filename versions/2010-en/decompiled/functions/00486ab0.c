
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00486ab0(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  int local_8 [2];
  
  iVar2 = param_2;
  FUN_0043e730(0,(double)*(int *)(&DAT_004fb9d0 + param_2 * 4),
               (double)*(int *)(&DAT_004f7208 + param_2 * 4),param_3,5);
  iVar1 = DAT_00523660;
  iVar6 = DAT_004fed58;
  param_2 = DAT_00523660;
  if ((-1 < DAT_004fed58) && (DAT_004fed58 <= DAT_004fe624)) {
    fVar8 = (float10)FUN_00406220(DAT_00523660,param_3);
    iVar5 = (int)(longlong)(fVar8 * (float10)_DAT_004cd008);
    if (iVar5 < 0x1e) {
      iVar5 = 0x1e;
    }
    if (1000 < iVar5) {
      iVar5 = 1000;
    }
    FUN_00471160(param_1);
    iVar7 = iVar1 - iVar5 / 3;
    iVar3 = (int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3;
    Rectangle((HDC)param_1[1],iVar6 - iVar3,iVar7,iVar6 + iVar3,iVar1);
    if ((DAT_004fb9b8 % 10 == 0) && (DAT_00536450 == 1)) {
      param_2 = iVar5 / 0x32;
      if (param_2 < 2) {
        param_2 = 2;
      }
      if (3 < param_2) {
        param_2 = 3;
      }
      FUN_0046a700(param_1);
      FUN_00433a70(param_1,param_2,iVar6,iVar7);
    }
    FUN_0043e730(0,(double)*(int *)(&DAT_00536220 + iVar2 * 4),
                 (double)*(int *)(&DAT_004f6d40 + iVar2 * 4),param_3,5);
    iVar1 = DAT_004fed58;
    local_8[0] = DAT_00523660;
    FUN_0043e730(0,(double)*(int *)(&DAT_004fb9f0 + iVar2 * 4),
                 (double)*(int *)(&DAT_004f71f0 + iVar2 * 4),param_3,5);
    iVar3 = DAT_00523660;
    iVar5 = DAT_004fed58;
    fVar8 = (float10)FUN_00406220(DAT_00523660,param_3);
    iVar6 = (int)(longlong)(fVar8 * (float10)_DAT_004cd008);
    if (iVar6 < 0x1e) {
      iVar6 = 0x1e;
    }
    if (1000 < iVar6) {
      iVar6 = 1000;
    }
    FUN_00471160(param_1);
    iVar7 = iVar3 - iVar6 / 3;
    iVar4 = (int)(iVar6 + (iVar6 >> 0x1f & 7U)) >> 3;
    Rectangle((HDC)param_1[1],iVar5 - iVar4,iVar7,iVar5 + iVar4,iVar3);
    if ((DAT_004fb9b8 % 10 == 0) && (DAT_00536450 == 1)) {
      FUN_0046a700(param_1);
      FUN_00433a70(param_1,param_2,iVar5,iVar7);
    }
    FUN_0043e730(0,(double)*(int *)(&DAT_00536210 + iVar2 * 4),
                 (double)*(int *)(&DAT_004f6d50 + iVar2 * 4),param_3,5);
    iVar5 = DAT_00523660;
    iVar2 = DAT_004fed58;
    FUN_00471160(param_1);
    iVar3 = local_8[0] - iVar6 / 9;
    Rectangle((HDC)param_1[1],iVar1,iVar3,iVar2,iVar6 / 0xc + iVar5);
    (**(code **)(*param_1 + 0x2c))(param_1,7);
    FUN_004b4d9d(param_1,local_8,iVar1,iVar3);
    CDC::LineTo(param_1,iVar2,iVar5 - iVar6 / 9);
  }
  return;
}

