
void __cdecl FUN_004645f0(HWND param_1)

{
  uint uVar1;
  HWND hWnd;
  undefined1 local_10 [16];
  
  uVar1 = GetWindowLongA(param_1,-0x10);
  GetWindowRect(param_1,(LPRECT)local_10);
  InflateRect((LPRECT)local_10,1,1);
  hWnd = GetParent(param_1);
  ScreenToClient(hWnd,(LPPOINT)local_10);
  ScreenToClient(hWnd,(LPPOINT)(local_10 + 8));
  if ((uVar1 & 0x200000) != 0) {
    local_10._8_4_ = local_10._8_4_ + 1;
  }
  ValidateRect(hWnd,(RECT *)local_10);
  return;
}

