
undefined4 __thiscall FUN_004ae19c(int *param_1,int param_2,LPCSCROLLINFO param_3,BOOL param_4)

{
  undefined4 uVar1;
  int iVar2;
  HWND hwnd;
  
  if (DAT_005381e4 < 0x333) {
    uVar1 = 0;
  }
  else {
    hwnd = (HWND)param_1[7];
    if (param_2 != 2) {
      iVar2 = (**(code **)(*param_1 + 0x70))(param_2);
      if (iVar2 != 0) {
        hwnd = *(HWND *)(iVar2 + 0x1c);
        param_2 = 2;
      }
    }
    param_3->cbSize = 0x1c;
    SetScrollInfo(hwnd,param_2,param_3,param_4);
    uVar1 = 1;
  }
  return uVar1;
}

