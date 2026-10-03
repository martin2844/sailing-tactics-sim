
void __cdecl FUN_00483ac0(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_8 [2];
  
  iVar2 = param_3;
  if ((((DAT_004da148 < param_3) && (-1 < param_2)) && (param_2 <= DAT_004fe624)) &&
     (param_3 <= DAT_00535564)) {
    param_3 = (param_3 - DAT_004da148) * 2 + 0x1b;
    if (DAT_004da1f8 == 0x69) {
      param_3 = (param_3 * 2) / 3;
    }
    if (1000 < param_3) {
      param_3 = 1000;
    }
    iVar3 = (int)(param_3 + (param_3 >> 0x1f & 7U)) >> 3;
    iVar5 = param_2 - iVar3;
    iVar3 = param_2 + iVar3;
    iVar6 = iVar2 - (param_3 * 2) / 3;
    if ((DAT_004fb9b8 + param_4) % 10 == 0) {
      if (DAT_005363e4 == 0) {
        if (DAT_004f3864 != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_004f3864);
        }
        if (DAT_004fb994 != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_004fb994);
        }
      }
      else {
        pcVar1 = *(code **)(*param_1 + 0x2c);
        (*pcVar1)(param_1,0);
        (*pcVar1)(param_1,6);
      }
      FUN_00433a70(param_1,1,param_2,iVar6 + -1);
    }
    if (DAT_004da1f8 == 0x69) {
      if (DAT_00536450 == 0) {
        if (DAT_005362ec != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_005362ec);
        }
      }
      else {
        (**(code **)(*param_1 + 0x2c))(param_1,7);
      }
      FUN_004b4d9d(param_1,local_8,iVar5,iVar2);
      CDC::LineTo(param_1,iVar5,iVar6);
      FUN_004b4d9d(param_1,local_8,iVar3,iVar2);
      CDC::LineTo(param_1,iVar3,iVar6);
      if (DAT_00536450 == 0) {
        (**(code **)(*param_1 + 0x2c))(param_1,6);
      }
      else {
        (**(code **)(*param_1 + 0x2c))(param_1,7);
      }
      FUN_004b4d9d(param_1,local_8,iVar5,iVar2);
      iVar4 = iVar2 - param_3 / 3;
      CDC::LineTo(param_1,iVar5,iVar4);
      FUN_004b4d9d(param_1,local_8,iVar3,iVar2);
      CDC::LineTo(param_1,iVar3,iVar4);
      FUN_004b4d9d(param_1,local_8,iVar5,iVar6);
      CDC::LineTo(param_1,iVar3,iVar6);
      FUN_004b4d9d(param_1,local_8,iVar5,iVar4);
      CDC::LineTo(param_1,iVar3,iVar4);
      return;
    }
    if (DAT_004fe174 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004fe174);
    }
    FUN_004b4d9d(param_1,local_8,iVar5,iVar2);
    CDC::LineTo(param_1,param_2 + -1,iVar6);
    CDC::LineTo(param_1,param_2,iVar6);
    CDC::LineTo(param_1,iVar3,iVar2);
    if (DAT_00522d14 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_00522d14);
    }
    FUN_004b4d9d(param_1,local_8,param_2,iVar2);
    CDC::LineTo(param_1,param_2,iVar6);
    FUN_004b4d9d(param_1,local_8,param_2 + -1,iVar2);
    CDC::LineTo(param_1,param_2,iVar6);
    FUN_004b4d9d(param_1,local_8,param_2 + 1,iVar2);
    CDC::LineTo(param_1,param_2,iVar6);
  }
  return;
}

