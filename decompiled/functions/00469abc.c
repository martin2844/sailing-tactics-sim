
undefined4 __thiscall FUN_00469abc(void *this,int param_1,LPCSCROLLINFO param_2,BOOL param_3)

{
  undefined4 uVar1;
  int iVar2;
  HWND hwnd;
  
  if (DAT_004ae68c < 0x333) {
    uVar1 = 0;
  }
  else {
    hwnd = *(HWND *)((int)this + 0x1c);
    if (param_1 != 2) {
      iVar2 = (**(code **)(*(int *)this + 0x70))(param_1);
      if (iVar2 != 0) {
        hwnd = *(HWND *)(iVar2 + 0x1c);
        param_1 = 2;
      }
    }
    param_2->cbSize = 0x1c;
    SetScrollInfo(hwnd,param_1,param_2,param_3);
    uVar1 = 1;
  }
  return uVar1;
}

