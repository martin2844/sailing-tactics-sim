
void __fastcall FUN_004738b1(void *param_1)

{
  int iVar1;
  WPARAM wParam;
  LRESULT LVar2;
  
  iVar1 = FUN_0046acae(param_1,100);
  wParam = SendMessageA(*(HWND *)(iVar1 + 0x1c),0x188,0,0);
  if (wParam == 0xffffffff) {
    *(undefined4 *)((int)param_1 + 0x60) = 0;
  }
  else {
    LVar2 = SendMessageA(*(HWND *)(iVar1 + 0x1c),0x199,wParam,0);
    *(LRESULT *)((int)param_1 + 0x60) = LVar2;
  }
  FUN_00467b57(param_1);
  return;
}

