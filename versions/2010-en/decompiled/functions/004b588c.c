
void __thiscall FUN_004b588c(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  tagRECT local_14;
  
  *(undefined4 *)(param_1 + 0x40) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x44) = param_2;
  *(undefined4 *)(param_1 + 0x48) = param_3;
  if (*(int *)(param_1 + 0x1c) != 0) {
    uVar1 = FUN_004af3eb();
    if ((uVar1 & 0x300000) != 0) {
      FUN_004ae0ce(0,0,1);
      FUN_004ae0ce(1,0,1);
      FUN_004ae159(3,0);
    }
  }
  GetClientRect(*(HWND *)(param_1 + 0x1c),&local_14);
  *(LONG *)(param_1 + 0x4c) = local_14.right - local_14.left;
  *(LONG *)(param_1 + 0x50) = local_14.bottom - local_14.top;
  if (*(int *)(param_1 + 0x1c) != 0) {
    FUN_004b5b95();
    InvalidateRect(*(HWND *)(param_1 + 0x1c),(RECT *)0x0,1);
  }
  return;
}

