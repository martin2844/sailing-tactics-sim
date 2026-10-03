
void __thiscall FUN_004afa58(int param_1,WPARAM param_2)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    uVar1 = SendMessageA(*(HWND *)(*(int *)(param_1 + 0x14) + 0x1c),0x87,0,0);
    if ((uVar1 & 0x2000) != 0) {
      SendMessageA(*(HWND *)(*(int *)(param_1 + 0x14) + 0x1c),0xf1,param_2,0);
    }
  }
  else if (*(int *)(param_1 + 0x10) == 0) {
    CheckMenuItem(*(HMENU *)(*(int *)(param_1 + 0xc) + 4),*(UINT *)(param_1 + 8),
                  (uint)CONCAT11(4,-(param_2 != 0) & 8));
  }
  return;
}

