
undefined4 __thiscall FUN_004b726c(CWnd *param_1,WPARAM param_2)

{
  CWnd *pCVar1;
  int iVar2;
  
  pCVar1 = CWnd::GetOwner(param_1);
  iVar2 = FUN_004bfca5();
  if (param_2 == 0xffffffff) {
    *(undefined4 *)(iVar2 + 0x108) = 0;
    if (((byte)param_1[0x60] & 8) == 0) {
      KillTimer(*(HWND *)(param_1 + 0x1c),0xe000);
      return 0;
    }
    SendMessageA(*(HWND *)(pCVar1 + 0x1c),0x375,0xe001,0);
    *(uint *)(param_1 + 0x60) = *(uint *)(param_1 + 0x60) & 0xfffffff7;
  }
  else {
    if ((((byte)param_1[0x60] & 8) != 0) && (*(WPARAM *)(iVar2 + 0x104) == param_2)) {
      return 0;
    }
    *(CWnd **)(iVar2 + 0x108) = param_1;
    SendMessageA(*(HWND *)(pCVar1 + 0x1c),0x362,param_2,0);
    *(uint *)(param_1 + 0x60) = *(uint *)(param_1 + 0x60) | 8;
    CControlBar::ResetTimer((CControlBar *)param_1,0xe001,200);
  }
  return 1;
}

