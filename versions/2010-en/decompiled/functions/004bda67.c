
void __thiscall FUN_004bda67(int param_1,undefined4 param_2,LONG param_3,LONG param_4)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xbc) == 0) {
    FUN_004ac701();
  }
  else {
    ReleaseCapture();
    *(undefined4 *)(param_1 + 0xbc) = 0;
    ClientToScreen(*(HWND *)(param_1 + 0x1c),(LPPOINT)&param_3);
    iVar1 = FUN_004bd68e(param_3,param_4);
    if (iVar1 == 3) {
      FUN_004bdac7();
      SendMessageA(*(HWND *)(param_1 + 0x1c),0x10,0,0);
    }
  }
  return;
}

