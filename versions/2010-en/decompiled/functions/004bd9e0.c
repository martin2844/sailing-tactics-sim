
void __thiscall FUN_004bd9e0(int param_1,undefined4 param_2,LONG param_3,LONG param_4)

{
  uint uVar1;
  HWND pHVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0xbc) == 0) {
    FUN_004ac701();
  }
  else {
    ClientToScreen(*(HWND *)(param_1 + 0x1c),(LPPOINT)&param_3);
    pHVar2 = GetCapture();
    iVar3 = FUN_004ac7ac(pHVar2);
    if (iVar3 == param_1) {
      uVar1 = *(uint *)(param_1 + 0xc0);
      iVar3 = FUN_004bd68e(param_3,param_4);
      if ((iVar3 == 3) != uVar1) {
        *(uint *)(param_1 + 0xc0) = (uint)(uVar1 == 0);
        FUN_004bdac7();
      }
    }
    else {
      *(undefined4 *)(param_1 + 0xbc) = 0;
      SendMessageA(*(HWND *)(param_1 + 0x1c),0x85,0,0);
    }
  }
  return;
}

