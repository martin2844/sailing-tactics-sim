
void __cdecl FUN_00464530(HWND param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  HWND hWnd;
  undefined1 local_10 [12];
  int local_4;
  
  GetWindowRect(param_1,(LPRECT)local_10);
  uVar2 = GetWindowLongA(param_1,-0x10);
  if ((uVar2 & 0x10000000) != 0) {
    if (param_2 != 0) {
      uVar1 = *(uint *)(param_2 + 0x18);
      if ((((uVar1 & 0xc0) == 0) && ((uVar1 & 2) != 0)) && ((uVar1 & 1) != 0)) {
        return;
      }
      if (((((byte)uVar1 & 3) == 2) && (local_10._8_4_ - *(int *)(param_2 + 0x10) == local_10._0_4_)
          ) && (*(int *)(param_2 + 0x14) <= local_4 - local_10._4_4_)) {
        local_10._4_4_ = local_10._4_4_ + *(int *)(param_2 + 0x14) + 1;
      }
    }
    InflateRect((LPRECT)local_10,1,1);
    hWnd = GetParent(param_1);
    ScreenToClient(hWnd,(LPPOINT)local_10);
    ScreenToClient(hWnd,(LPPOINT)(local_10 + 8));
    if ((uVar2 & 0x200000) != 0) {
      local_10._8_4_ = local_10._8_4_ + 1;
    }
    InvalidateRect(hWnd,(RECT *)local_10,0);
  }
  return;
}

