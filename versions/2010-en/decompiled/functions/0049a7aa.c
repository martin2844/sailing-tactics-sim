
void __thiscall FUN_0049a7aa(int param_1,WPARAM param_2)

{
  LRESULT LVar1;
  int iVar2;
  
  LVar1 = SendMessageA(*(HWND *)(param_1 + 0x1c),0x1002,param_2,0);
  iVar2 = FUN_0049a9b7(LVar1);
  if (iVar2 != 0) {
    SendMessageA(*(HWND *)(param_1 + 0x1c),0x1003,param_2,0);
  }
  return;
}

