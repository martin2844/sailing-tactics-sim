
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004060f0(int param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int this;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  HDC pHVar8;
  HGDIOBJ pvVar9;
  int aiStack_50 [10];
  int aiStack_28 [10];
  
  this = param_1;
  iVar3 = (int)(longlong)(_DAT_004ab0c8 * _DAT_00484ce8);
  pcVar1 = *(code **)(*(int *)param_1 + 0x2c);
  (*pcVar1)((void *)param_1,8);
  if (DAT_004ac98c == 0) {
    param_1 = (int)&DAT_004a4928;
    iVar5 = 0;
    do {
      iVar7 = *(int *)(&DAT_004a6830 + param_2 * 4);
      if ((iVar7 < 0xb4) || (0x10e < iVar7)) {
        iVar7 = FUN_00415dc0(iVar7);
        iVar7 = *(int *)((int)&DAT_004a8870 + iVar5) - iVar7;
        FUN_00415dc0(iVar7);
      }
      else {
        iVar7 = *(int *)((int)&DAT_004a8870 + iVar5) - iVar7;
      }
      iVar2 = *(int *)((int)&DAT_004a44f0 + iVar5);
      iVar7 = iVar7 * iVar3 + DAT_004a3fa0;
      if (DAT_004a5b98 < 3) {
        if (DAT_004a3efc != (HGDIOBJ)0x0) {
          pHVar8 = *(HDC *)(this + 4);
          pvVar9 = DAT_004a3efc;
LAB_004061cd:
          SelectObject(pHVar8,pvVar9);
        }
      }
      else if (DAT_004aa7f4 != (HGDIOBJ)0x0) {
        pHVar8 = *(HDC *)(this + 4);
        pvVar9 = DAT_004aa7f4;
        goto LAB_004061cd;
      }
      Ellipse(*(HDC *)(this + 4),iVar7,iVar2 + 1,iVar7 + *(int *)param_1,iVar2 + 9);
      if (DAT_004a5b98 < 3) {
        (*pcVar1)((void *)this,0);
      }
      else if (DAT_004a70e4 != (HGDIOBJ)0x0) {
        SelectObject(*(HDC *)(this + 4),DAT_004a70e4);
      }
      Pie(*(HDC *)(this + 4),iVar7,iVar2,iVar7 + *(int *)param_1,iVar2 + 0xb,
          iVar7 + *(int *)param_1 + 1,iVar2 + 5,iVar7 + -1,iVar2 + 5);
      iVar5 = iVar5 + 4;
      param_1 = param_1 + 4;
    } while (iVar5 < 0x19);
  }
  (*pcVar1)((void *)this,8);
  if ((DAT_004ac92c == 0) && (DAT_004ac98c == 0)) {
    if (DAT_004ac8ec == (HGDIOBJ)0x0) goto LAB_004062be;
    pHVar8 = *(HDC *)(this + 4);
    pvVar9 = DAT_004ac8ec;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_004062be;
    pHVar8 = *(HDC *)(this + 4);
    pvVar9 = DAT_004aa7f4;
  }
  SelectObject(pHVar8,pvVar9);
LAB_004062be:
  if (DAT_004ac98c == 1) {
    (*pcVar1)((void *)this,4);
  }
  iVar7 = 3;
  iVar5 = DAT_00491148;
  uVar6 = param_2;
  do {
    iVar2 = *(int *)(&DAT_004a6830 + param_2 * 4);
    if ((iVar2 < 0xb4) || (0x10e < iVar2)) {
      iVar5 = FUN_00415dc0(iVar2);
      uVar4 = FUN_00415dc0(*(int *)(iVar7 * 4 + 0x4a8850) - iVar5);
      iVar5 = DAT_00491148;
    }
    else {
      uVar4 = *(int *)(iVar7 * 4 + 0x4a8850) - iVar2;
    }
    if (iVar7 == 5) {
      uVar6 = uVar4;
    }
    iVar2 = *(int *)(iVar7 * 4 + 0x4a44d0);
    aiStack_50[iVar7] = uVar4 * iVar3 + DAT_004a3fa0;
    aiStack_28[iVar7] = (iVar5 - iVar2) + -1;
    iVar7 = iVar7 + 1;
  } while (iVar7 < 8);
  _DAT_004a4cb0 = aiStack_50[4];
  _DAT_004a4cb8 = aiStack_50[5];
  _DAT_004a4cc0 = aiStack_50[6];
  _DAT_004a4cc8 = aiStack_50[7];
  _DAT_004a4cd0 = aiStack_50[7] + 100;
  _DAT_004a4ca8 = aiStack_50[3];
  _DAT_004a4cb4 = aiStack_28[4];
  _DAT_004a4cbc = aiStack_28[5];
  _DAT_004a4cc4 = aiStack_28[6];
  _DAT_004a4ccc = aiStack_28[7];
  _DAT_004a4cac = iVar5;
  _DAT_004a4cd4 = iVar5;
  if ((int)((uVar6 ^ (int)uVar6 >> 0x1f) - ((int)uVar6 >> 0x1f)) < 0x6e) {
    Polygon(*(HDC *)(this + 4),(POINT *)&DAT_004a4ca8,6);
  }
  return;
}

