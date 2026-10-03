
void FUN_004ac653(int *param_1,int *param_2,uint param_3)

{
  uint uVar1;
  HWND pHVar2;
  int iVar3;
  tagRECT local_14;
  
  if (((((param_3 & 0x10000000) == 0) && (uVar1 = FUN_004af3eb(), (uVar1 & 0x50000000) == 0)) &&
      (GetWindowRect((HWND)param_1[7],&local_14), *param_2 == local_14.left)) &&
     (param_2[1] == local_14.top)) {
    pHVar2 = GetWindow((HWND)param_1[7],4);
    iVar3 = FUN_004ac7ac(pHVar2);
    if ((iVar3 != 0) && (iVar3 = FUN_004af553(), iVar3 != 0)) {
      return;
    }
    iVar3 = (**(code **)(*param_1 + 0xb4))();
    if (iVar3 != 0) {
      FUN_004aec6c(0);
    }
  }
  return;
}

