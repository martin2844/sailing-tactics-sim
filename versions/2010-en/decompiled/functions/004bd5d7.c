
undefined4 __thiscall FUN_004bd5d7(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_004af3eb();
  if ((uVar1 & 0x100) == 0) {
    if (DAT_005381f4 != 0) {
      uVar2 = FUN_004ac701(param_1);
      return uVar2;
    }
    if (*(int *)(param_1 + 0xc4) != param_2) {
      *(int *)(param_1 + 0xc4) = param_2;
      SendMessageA(*(HWND *)(param_1 + 0x1c),0x85,0,0);
    }
  }
  else if ((*(byte *)(param_1 + 0x25) & 2) != 0) {
    return 0;
  }
  return 1;
}

