
LRESULT FUN_004629a0(int param_1,WPARAM param_2,int param_3)

{
  LRESULT LVar1;
  uint uVar2;
  int local_4;
  
  LVar1 = CallNextHookEx(DAT_004aedb8,param_1,param_2,param_3);
  if (*(int *)(param_3 + 0xc) != DAT_004aedb4) {
    return LVar1;
  }
  UnhookWindowsHookEx(DAT_004aedb8);
  if (0x35e < DAT_004aff60) {
    uVar2 = GetWindowLongA(*(HWND *)(param_3 + 0xc),-0x10);
    local_4 = 0;
    if ((uVar2 & 4) != 0) goto LAB_00462a05;
  }
  local_4 = 1;
LAB_00462a05:
  SendMessageA(*(HWND *)(param_3 + 0xc),0x11f0,0,(LPARAM)&local_4);
  if (local_4 != 0) {
    FUN_004628b0(*(HWND *)(param_3 + 0xc),DAT_004aedbc);
  }
  DAT_004aedbc = 0;
  DAT_004aedb8 = (HHOOK)0x0;
  DAT_004aedb4 = 0;
  return LVar1;
}

