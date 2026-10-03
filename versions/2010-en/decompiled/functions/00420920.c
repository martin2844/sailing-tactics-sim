
void __cdecl
FUN_00420920(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  code *pcVar6;
  int local_8 [2];
  
  pcVar6 = SelectObject_exref;
  if (DAT_00536450 != 1) {
    if (DAT_005363e4 == 0) {
      uVar4 = param_4 >> 0x1f;
      if (((param_4 ^ uVar4) - uVar4 & 1 ^ uVar4) == uVar4) {
        if (DAT_004f1cec != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_004f1cec);
        }
      }
      else if (DAT_004fb994 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004fb994);
        pcVar6 = SelectObject_exref;
      }
      if ((param_7 == 1) && (DAT_004f49b4 != (HGDIOBJ)0x0)) {
        (*pcVar6)((HDC)param_1[1],DAT_004f49b4);
      }
      if ((param_7 == 2) && (DAT_004f408c != (HGDIOBJ)0x0)) {
        (*pcVar6)((HDC)param_1[1],DAT_004f408c);
      }
      if ((param_7 == 3) && (DAT_005125ec != (HGDIOBJ)0x0)) {
        (*pcVar6)((HDC)param_1[1],DAT_005125ec);
      }
    }
    else if (DAT_004f7ec4 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004f7ec4);
    }
    iVar2 = *(int *)(&DAT_00522ff0 + param_4 * 4);
    iVar3 = *(int *)(&DAT_004fecc8 + param_4 * 4);
    iVar1 = FUN_0041e000(0x14);
    iVar2 = FUN_0041bc20((-((iVar2 * iVar3 * 2) / 3) - param_5) + -10 + iVar1);
    iVar3 = FUN_0041bc20(iVar2);
    iVar2 = param_6 / 0xf;
    if (0 < param_7) {
      iVar2 = param_6 / 0x14;
    }
    if ((2 < DAT_004f71c4) || (500 < DAT_00536444)) {
      iVar2 = (iVar2 * 2) / 3;
    }
    iVar1 = (iVar2 * (&DAT_004f85c8)[iVar3]) / 100 + param_2;
    iVar5 = (iVar2 * (&DAT_004f1740)[iVar3]) / 300 + param_3;
    iVar2 = param_2;
    iVar3 = param_3;
    if (param_7 != 0) {
      iVar2 = (iVar1 + param_2 * 4) / 5;
      iVar3 = (iVar5 + param_3 * 4) / 5;
    }
    FUN_004b4d9d(param_1,local_8,iVar2,iVar3);
    CDC::LineTo(param_1,iVar1,iVar5);
    if (param_7 == 3) {
      if (DAT_004f7ec4 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004f7ec4);
      }
      iVar2 = (iVar1 + param_2) / 2;
      iVar3 = (iVar5 + param_3) / 2;
      FUN_004b4d9d(param_1,local_8,iVar2 + 1,iVar3);
      CDC::LineTo(param_1,iVar2 + 2,iVar3);
    }
    return;
  }
  pcVar6 = *(code **)(*param_1 + 0x2c);
  (*pcVar6)(param_1,6);
  (*pcVar6)(param_1,0);
  FUN_00433a70(param_1,2,param_2,param_3 + -1);
  return;
}

