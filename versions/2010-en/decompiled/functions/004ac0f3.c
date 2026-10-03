
int __fastcall FUN_004ac0f3(int *param_1)

{
  int *piVar1;
  int iVar2;
  HWND pHVar3;
  int iVar4;
  
  (**(code **)(*param_1 + 0xd4))();
  iVar2 = FUN_004bfff8();
  piVar1 = *(int **)(iVar2 + 0x1038);
  if ((piVar1 != (int *)0x0) && (iVar2 = param_1[0x16], iVar2 != 0)) {
    if (param_1[0x13] == 0) {
      iVar2 = (**(code **)(*piVar1 + 0x20))(param_1,param_1[0x10],iVar2);
    }
    else {
      iVar2 = (**(code **)(*piVar1 + 0x1c))(param_1,param_1[0x13],iVar2);
    }
    if (iVar2 == 0) {
      FUN_004ac0ab(0xffffffff);
      return 0;
    }
  }
  iVar2 = FUN_004ac701(param_1);
  if ((iVar2 != 0) && ((*(byte *)((int)param_1 + 0x25) & 1) != 0)) {
    pHVar3 = GetNextDlgTabItem((HWND)param_1[7],(HWND)0x0,0);
    iVar4 = FUN_004ac7ac(pHVar3);
    if (iVar4 != 0) {
      FUN_004af595();
      iVar2 = 0;
    }
  }
  return iVar2;
}

