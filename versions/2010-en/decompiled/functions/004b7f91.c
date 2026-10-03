
void __fastcall FUN_004b7f91(int param_1)

{
  int iVar1;
  WPARAM wParam;
  LRESULT LVar2;
  
  iVar1 = FUN_004af38e(100);
  wParam = SendMessageA(*(HWND *)(iVar1 + 0x1c),0x188,0,0);
  if (wParam == 0xffffffff) {
    *(undefined4 *)(param_1 + 0x60) = 0;
  }
  else {
    LVar2 = SendMessageA(*(HWND *)(iVar1 + 0x1c),0x199,wParam,0);
    *(LRESULT *)(param_1 + 0x60) = LVar2;
  }
  FUN_004ac237();
  return;
}

