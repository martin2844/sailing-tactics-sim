
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004865c0(int *param_1,int param_2,int param_3)

{
  double dVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  int local_18 [2];
  int local_10 [2];
  int local_8 [2];
  
  FUN_0043e730(0,(double)*(int *)(&DAT_004fb9d0 + param_2 * 4),
               (double)*(int *)(&DAT_004f7208 + param_2 * 4),param_3,5);
  iVar3 = DAT_00523660;
  iVar2 = DAT_004fed58;
  if ((-1 < DAT_004fed58) && (DAT_004fed58 <= DAT_004fe624)) {
    fVar8 = (float10)FUN_00406220(DAT_00523660,param_3);
    if ((DAT_004da1f8 == 3) || ((DAT_004da1f8 == 0xb || (DAT_004da1f8 == 9)))) {
      fVar8 = fVar8 * (float10)_DAT_004cc4f8;
    }
    dVar1 = _DAT_004cd008;
    if (1 < param_2) {
      dVar1 = _DAT_004cc458;
    }
    iVar7 = (int)(longlong)(fVar8 * (float10)dVar1);
    if (2 < param_2) {
      iVar7 = (int)(longlong)(fVar8 * (float10)_DAT_004cc450);
    }
    if (iVar7 < 0x1e) {
      iVar7 = 0x1e;
    }
    if (1000 < iVar7) {
      iVar7 = 1000;
    }
    local_18[0] = iVar7 / 0x19;
    if (local_18[0] < 1) {
      local_18[0] = 1;
    }
    if (3 < local_18[0]) {
      local_18[0] = 3;
    }
    FUN_00471160(param_1);
    if ((DAT_00536450 == 1) && (DAT_005230cc != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_005230cc);
    }
    iVar6 = iVar3 - (iVar7 * 2) / 3;
    Rectangle((HDC)param_1[1],iVar2 - iVar7 / 0x1e,iVar6,iVar2 + iVar7 / 0x1e,iVar3);
    local_8[0] = iVar2;
    iVar4 = iVar3 - iVar7 / 3;
    uVar5 = param_2 + DAT_004fad34 >> 0x1f;
    if ((((param_2 + DAT_004fad34 ^ uVar5) - uVar5 & 1 ^ uVar5) == uVar5) && (DAT_00536450 == 1)) {
      FUN_0046a700(param_1);
      FUN_00433a70(param_1,local_18[0],iVar2,iVar6);
      FUN_00433a70(param_1,local_18[0],iVar2,iVar3 - ((int)(iVar7 + (iVar7 >> 0x1f & 7U)) >> 3));
    }
    FUN_0043e730(0,(double)*(int *)(&DAT_00536220 + param_2 * 4),
                 (double)*(int *)(&DAT_004f6d40 + param_2 * 4),param_3,5);
    if (DAT_00522d14 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_00522d14);
    }
    if ((DAT_00536450 == 1) && (DAT_005362fc != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_005362fc);
    }
    FUN_004b4d9d(param_1,local_10,DAT_004fed58,DAT_00523660);
    CDC::LineTo(param_1,iVar2,iVar4);
    FUN_0043e730(0,(double)*(int *)(&DAT_004fb9f0 + param_2 * 4),
                 (double)*(int *)(&DAT_004f71f0 + param_2 * 4),param_3,5);
    iVar3 = DAT_00523660;
    iVar2 = DAT_004fed58;
    fVar8 = (float10)FUN_00406220(DAT_00523660,param_3);
    if (((DAT_004da1f8 == 3) || (DAT_004da1f8 == 0xb)) || (DAT_004da1f8 == 9)) {
      fVar8 = fVar8 * (float10)_DAT_004cc4f8;
    }
    dVar1 = _DAT_004cd008;
    if (1 < param_2) {
      dVar1 = _DAT_004cc458;
    }
    iVar7 = (int)(longlong)(fVar8 * (float10)dVar1);
    if (2 < param_2) {
      iVar7 = (int)(longlong)(fVar8 * (float10)_DAT_004cc450);
    }
    if (iVar7 < 0x1e) {
      iVar7 = 0x1e;
    }
    if (1000 < iVar7) {
      iVar7 = 1000;
    }
    FUN_00471160(param_1);
    if ((DAT_00536450 == 1) && (DAT_005230cc != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_005230cc);
    }
    iVar6 = iVar3 - (iVar7 * 2) / 3;
    Rectangle((HDC)param_1[1],iVar2 - iVar7 / 0x1e,iVar6,iVar2 + iVar7 / 0x1e,iVar3);
    local_10[0] = iVar3 - iVar7 / 3;
    uVar5 = param_2 + DAT_004fad34 >> 0x1f;
    if ((((param_2 + DAT_004fad34 ^ uVar5) - uVar5 & 1 ^ uVar5) == uVar5) && (DAT_00536450 == 1)) {
      FUN_0046a700(param_1);
      FUN_00433a70(param_1,local_18[0],iVar2,iVar6);
      FUN_00433a70(param_1,local_18[0],iVar2,iVar3 - ((int)(iVar7 + (iVar7 >> 0x1f & 7U)) >> 3));
    }
    FUN_0043e730(0,(double)*(int *)(&DAT_00536210 + param_2 * 4),
                 (double)*(int *)(&DAT_004f6d50 + param_2 * 4),param_3,5);
    if (DAT_00522d14 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_00522d14);
    }
    if ((DAT_00536450 == 1) && (DAT_005362fc != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_005362fc);
    }
    FUN_004b4d9d(param_1,local_18,DAT_004fed58,DAT_00523660);
    iVar3 = local_10[0];
    CDC::LineTo(param_1,iVar2,local_10[0]);
    if (9 < DAT_004da204) {
      FUN_004b4d9d(param_1,local_8,local_8[0],iVar4);
      CDC::LineTo(param_1,iVar2,iVar3);
    }
  }
  return;
}

