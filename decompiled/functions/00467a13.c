
int __fastcall FUN_00467a13(int *param_1)

{
  int *piVar1;
  int iVar2;
  CWnd *pCVar3;
  
  (**(code **)(*param_1 + 0xd4))();
  iVar2 = FUN_0047b918();
  piVar1 = *(int **)(iVar2 + 0x1038);
  if ((piVar1 != (int *)0x0) && (iVar2 = param_1[0x16], iVar2 != 0)) {
    if (param_1[0x13] == 0) {
      iVar2 = (**(code **)(*piVar1 + 0x20))(param_1,param_1[0x10],iVar2);
    }
    else {
      iVar2 = (**(code **)(*piVar1 + 0x1c))(param_1,param_1[0x13],iVar2);
    }
    if (iVar2 == 0) {
      FUN_004679cb(param_1,-1);
      return 0;
    }
  }
  iVar2 = FUN_00468021(param_1);
  if ((iVar2 != 0) && ((*(byte *)((int)param_1 + 0x25) & 1) != 0)) {
    GetNextDlgTabItem((HWND)param_1[7],(HWND)0x0,0);
    pCVar3 = FUN_004680cc();
    if (pCVar3 != (CWnd *)0x0) {
      FUN_0046aeb5((int)pCVar3);
      iVar2 = 0;
    }
  }
  return iVar2;
}

