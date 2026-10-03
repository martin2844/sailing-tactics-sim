
void FUN_00467f73(int *param_1,int *param_2,uint param_3)

{
  uint uVar1;
  CWnd *pCVar2;
  int iVar3;
  tagRECT local_14;
  
  if (((((param_3 & 0x10000000) == 0) &&
       (uVar1 = FUN_0046ad0b((int)param_1), (uVar1 & 0x50000000) == 0)) &&
      (GetWindowRect((HWND)param_1[7],&local_14), *param_2 == local_14.left)) &&
     (param_2[1] == local_14.top)) {
    GetWindow((HWND)param_1[7],4);
    pCVar2 = FUN_004680cc();
    if ((pCVar2 != (CWnd *)0x0) && (iVar3 = FUN_0046ae73((int)pCVar2), iVar3 != 0)) {
      return;
    }
    iVar3 = (**(code **)(*param_1 + 0xb4))();
    if (iVar3 != 0) {
      FUN_0046a58c(param_1,0);
    }
  }
  return;
}

