
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00406270(int *param_1,uint param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int *original_dc;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  HDC pHVar8;
  HGDIOBJ pvVar9;
  int aiStack_50 [10];
  int aiStack_28 [10];
  
  original_dc = param_1;
  iVar3 = (int)(longlong)(_DAT_005259d0 * _DAT_004cc410);
  pcVar1 = *(code **)(*param_1 + 0x2c);
  (*pcVar1)(param_1,8);
  if (DAT_00536450 == 0) {
    param_1 = &DAT_004f4e28;
    iVar5 = 0;
    do {
      iVar7 = *(int *)(&DAT_004fbb90 + param_2 * 4);
      if ((iVar7 < 0xb4) || (0x10e < iVar7)) {
        iVar7 = FUN_0041e3a0(iVar7);
        iVar7 = *(int *)((int)&DAT_00511570 + iVar5) - iVar7;
        FUN_0041e3a0(iVar7);
      }
      else {
        iVar7 = *(int *)((int)&DAT_00511570 + iVar5) - iVar7;
      }
      iVar2 = *(int *)((int)&DAT_004f4868 + iVar5);
      iVar7 = iVar7 * iVar3 + DAT_004f40a8;
      if (DAT_004f8d78 < 3) {
        if (DAT_004f3f5c != (HGDIOBJ)0x0) {
          pHVar8 = (HDC)original_dc[1];
          pvVar9 = DAT_004f3f5c;
override_prt_40634d_6059bb06:
          SelectObject(pHVar8,pvVar9);
        }
      }
      else if (DAT_005230cc != (HGDIOBJ)0x0) {
        pHVar8 = (HDC)original_dc[1];
        pvVar9 = DAT_005230cc;
        goto override_prt_40634d_6059bb06;
      }
      Ellipse((HDC)original_dc[1],iVar7,iVar2 + 1,iVar7 + *param_1,iVar2 + 9);
      if (DAT_004f8d78 < 3) {
        (*pcVar1)(original_dc,0);
      }
      else if (DAT_004fe07c != (HGDIOBJ)0x0) {
        SelectObject((HDC)original_dc[1],DAT_004fe07c);
      }
      Pie((HDC)original_dc[1],iVar7,iVar2,iVar7 + *param_1,iVar2 + 0xb,iVar7 + *param_1 + 1,
          iVar2 + 5,iVar7 + -1,iVar2 + 5);
      iVar5 = iVar5 + 4;
      param_1 = param_1 + 1;
    } while (iVar5 < 0x19);
  }
  if (DAT_004da1f8 == 0xb) {
    return;
  }
  if (DAT_004da1f8 == 0x69) {
    return;
  }
  if (DAT_004da1f8 == 0x68) {
    return;
  }
  if (DAT_004da1f8 == 0x6a) {
    return;
  }
  (*pcVar1)(original_dc,8);
  if ((DAT_005363e4 == 0) && (DAT_00536450 == 0)) {
    if (DAT_004f6a54 == (HGDIOBJ)0x0) goto LAB_00406467;
    pHVar8 = (HDC)original_dc[1];
    pvVar9 = DAT_004f6a54;
  }
  else {
    if (DAT_005230cc == (HGDIOBJ)0x0) goto LAB_00406467;
    pHVar8 = (HDC)original_dc[1];
    pvVar9 = DAT_005230cc;
  }
  SelectObject(pHVar8,pvVar9);
LAB_00406467:
  if (DAT_00536450 == 1) {
    (*pcVar1)(original_dc,4);
  }
  iVar7 = 3;
  iVar5 = DAT_004da148;
  uVar6 = param_2;
  do {
    iVar2 = *(int *)(&DAT_004fbb90 + param_2 * 4);
    if ((iVar2 < 0xb4) || (0x10e < iVar2)) {
      iVar5 = FUN_0041e3a0(iVar2);
      uVar4 = FUN_0041e3a0(*(int *)(iVar7 * 4 + 0x511550) - iVar5);
      iVar5 = DAT_004da148;
    }
    else {
      uVar4 = *(int *)(iVar7 * 4 + 0x511550) - iVar2;
    }
    if (iVar7 == 5) {
      uVar6 = uVar4;
    }
    iVar2 = *(int *)(iVar7 * 4 + 0x4f4848);
    aiStack_50[iVar7] = uVar4 * iVar3 + DAT_004f40a8;
    aiStack_28[iVar7] = (iVar5 - iVar2) + -1;
    iVar7 = iVar7 + 1;
  } while (iVar7 < 8);
  _DAT_004f6e30 = aiStack_50[4];
  _DAT_004f6e38 = aiStack_50[5];
  _DAT_004f6e40 = aiStack_50[6];
  _DAT_004f6e48 = aiStack_50[7];
  _DAT_004f6e50 = aiStack_50[7] + 100;
  _DAT_004f6e28 = aiStack_50[3];
  _DAT_004f6e34 = aiStack_28[4];
  _DAT_004f6e3c = aiStack_28[5];
  _DAT_004f6e44 = aiStack_28[6];
  _DAT_004f6e4c = aiStack_28[7];
  _DAT_004f6e2c = iVar5;
  _DAT_004f6e54 = iVar5;
  if ((int)((uVar6 ^ (int)uVar6 >> 0x1f) - ((int)uVar6 >> 0x1f)) < 0x6e) {
    Polygon((HDC)original_dc[1],(POINT *)&DAT_004f6e28,6);
  }
  return;
}

