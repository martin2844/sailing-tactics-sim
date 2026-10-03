
void __thiscall FUN_0046b378(void *this,WPARAM param_1)

{
  uint uVar1;
  
  if (*(int *)((int)this + 0xc) == 0) {
    uVar1 = SendMessageA(*(HWND *)(*(int *)((int)this + 0x14) + 0x1c),0x87,0,0);
    if ((uVar1 & 0x2000) != 0) {
      SendMessageA(*(HWND *)(*(int *)((int)this + 0x14) + 0x1c),0xf1,param_1,0);
    }
  }
  else if (*(int *)((int)this + 0x10) == 0) {
    CheckMenuItem(*(HMENU *)(*(int *)((int)this + 0xc) + 4),*(UINT *)((int)this + 8),
                  (uint)CONCAT11(4,-(param_1 != 0) & 8));
  }
  return;
}

