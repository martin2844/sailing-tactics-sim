
void __thiscall FUN_004711ac(void *this,undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  tagRECT local_14;
  
  *(undefined4 *)((int)this + 0x40) = 0xffffffff;
  *(undefined4 *)((int)this + 0x44) = param_1;
  *(undefined4 *)((int)this + 0x48) = param_2;
  if (*(int *)((int)this + 0x1c) != 0) {
    uVar1 = FUN_0046ad0b((int)this);
    if ((uVar1 & 0x300000) != 0) {
      FUN_004699ee(this,0,0,1);
      FUN_004699ee(this,1,0,1);
      FUN_00469a79(this,3,0);
    }
  }
  GetClientRect(*(HWND *)((int)this + 0x1c),&local_14);
  *(LONG *)((int)this + 0x4c) = local_14.right - local_14.left;
  *(LONG *)((int)this + 0x50) = local_14.bottom - local_14.top;
  if (*(int *)((int)this + 0x1c) != 0) {
    FUN_004714b5(this);
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,1);
  }
  return;
}

