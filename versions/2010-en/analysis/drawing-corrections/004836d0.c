
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004836d0(int *param_1,int param_2,int param_3,int param_4)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int left;
  int iVar4;
  int iVar5;
  int top;
  HDC pHVar6;
  HGDIOBJ pvVar7;
  int aiStack_8 [2];
  
  if (param_3 < DAT_004da148) {
    return;
  }
  if (param_2 < 0) {
    return;
  }
  if (DAT_004fe624 < param_2) {
    return;
  }
  if (DAT_00535564 < param_3) {
    return;
  }
  iVar5 = ((param_3 - DAT_004da148) * 0xc) / 0x14 + 3;
  if (1000 < iVar5) {
    iVar5 = 1000;
  }
  pcVar1 = *(code **)(*param_1 + 0x2c);
  (*pcVar1)(param_1,7);
  if (DAT_00536450 == 0) {
    if (DAT_004f3f5c != (HGDIOBJ)0x0) {
      pHVar6 = (HDC)param_1[1];
      pvVar7 = DAT_004f3f5c;
override_prt_483789_6059bb06:
      SelectObject(pHVar6,pvVar7);
    }
  }
  else if (DAT_004fe07c != (HGDIOBJ)0x0) {
    pHVar6 = (HDC)param_1[1];
    pvVar7 = DAT_004fe07c;
    goto override_prt_483789_6059bb06;
  }
  Rectangle((HDC)param_1[1],param_2 - iVar5,param_3 - iVar5 / 5,iVar5 + param_2,param_3);
  iVar5 = (iVar5 * 2) / 3;
  if (DAT_00536450 == 0) {
    if (DAT_004fb25c != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004fb25c);
    }
    if (DAT_005362ec != (HGDIOBJ)0x0) {
      pHVar6 = (HDC)param_1[1];
      pvVar7 = DAT_005362ec;
override_prt_483829_6059bb06:
      SelectObject(pHVar6,pvVar7);
    }
  }
  else if (DAT_004fe07c != (HGDIOBJ)0x0) {
    pHVar6 = (HDC)param_1[1];
    pvVar7 = DAT_004fe07c;
    goto override_prt_483829_6059bb06;
  }
  left = param_2 - iVar5;
  iVar2 = param_3 - iVar5 / 5;
  top = param_3 - iVar5;
  Rectangle((HDC)param_1[1],left,top,iVar5 + param_2,iVar2);
  FUN_004b4d9d(param_1,aiStack_8,param_2,iVar2);
  CDC::LineTo(param_1,param_2,top);
  iVar4 = param_2 + iVar5 * -2;
  iVar2 = param_2 + iVar5 * 2;
  (*pcVar1)(param_1,7);
  iVar3 = param_3 + iVar5 * -2;
  _DAT_004f6e40 = iVar5 + param_2;
  _DAT_004f6e28 = left;
  _DAT_004f6e2c = top;
  _DAT_004f6e3c = iVar3;
  _DAT_004f6e44 = top;
  if (DAT_00536450 == 0) {
    _DAT_004f6e30 = iVar4;
    _DAT_004f6e34 = iVar3;
    _DAT_004f6e38 = iVar2;
    if (DAT_004f3f5c == (HGDIOBJ)0x0) goto LAB_00483924;
    pHVar6 = (HDC)param_1[1];
    pvVar7 = DAT_004f3f5c;
  }
  else {
    _DAT_004f6e30 = iVar4;
    _DAT_004f6e34 = iVar3;
    _DAT_004f6e38 = iVar2;
    if (DAT_004fe07c == (HGDIOBJ)0x0) goto LAB_00483924;
    pHVar6 = (HDC)param_1[1];
    pvVar7 = DAT_004fe07c;
  }
  _DAT_004f6e30 = iVar4;
  _DAT_004f6e34 = iVar3;
  _DAT_004f6e38 = iVar2;
  SelectObject(pHVar6,pvVar7);
LAB_00483924:
  Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
  _DAT_004f6e34 = param_3 + iVar5 * -3;
  _DAT_004f6e30 = (iVar4 + param_2) / 2;
  _DAT_004f6e38 = (iVar2 + param_2) / 2;
  _DAT_004f6e28 = iVar4;
  _DAT_004f6e2c = iVar3;
  _DAT_004f6e3c = _DAT_004f6e34;
  _DAT_004f6e40 = iVar2;
  _DAT_004f6e44 = iVar3;
  if (DAT_00536450 == 0) {
    (*pcVar1)(param_1,0);
  }
  else if (DAT_004f3f5c != (HGDIOBJ)0x0) {
    SelectObject((HDC)param_1[1],DAT_004f3f5c);
  }
  Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
  if (DAT_00536450 == 1) {
    FUN_00469670(param_1);
    FUN_00433a70(param_1,2,iVar4,iVar3);
    FUN_00433a70(param_1,2,param_2,iVar3);
    FUN_00433a70(param_1,2,iVar2,iVar3);
  }
  return;
}

