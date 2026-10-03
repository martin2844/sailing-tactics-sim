
LRESULT FUN_004a7080(int param_1,WPARAM param_2,int param_3)

{
  LRESULT LVar1;
  uint uVar2;
  int local_4;
  
  LVar1 = CallNextHookEx(DAT_00538910,param_1,param_2,param_3);
  if (*(int *)(param_3 + 0xc) != DAT_0053890c) {
    return LVar1;
  }
  UnhookWindowsHookEx(DAT_00538910);
  if (0x35e < DAT_00539aa0) {
    uVar2 = GetWindowLongA(*(HWND *)(param_3 + 0xc),-0x10);
    local_4 = 0;
    if ((uVar2 & 4) != 0) goto LAB_004a70e5;
  }
  local_4 = 1;
LAB_004a70e5:
  SendMessageA(*(HWND *)(param_3 + 0xc),0x11f0,0,(LPARAM)&local_4);
  if (local_4 != 0) {
    FUN_004a6f90(*(undefined4 *)(param_3 + 0xc),DAT_00538914);
  }
  DAT_00538914 = 0;
  DAT_00538910 = (HHOOK)0x0;
  DAT_0053890c = 0;
  return LVar1;
}

