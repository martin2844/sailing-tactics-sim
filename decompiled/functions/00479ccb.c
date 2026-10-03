
undefined4 __thiscall FUN_00479ccb(void *this,uint param_1)

{
  uint uVar1;
  undefined4 local_4;
  
  local_4 = 0;
  uVar1 = FUN_0046ad0b((int)this);
  if (((uVar1 & 0x100) != 0) && ((param_1 & 0x40) != 0)) {
    local_4 = 1;
  }
  if ((param_1 & 3) != 0) {
    FUN_0046adfd(this,0,0,0,0,0,(-(uint)((param_1 & 1) != 0) & 0xffffffc0) + 0x80 | 0x17);
  }
  if ((param_1 & 0x30) != 0) {
    FUN_0046ae8e(this,param_1 >> 4 & 1);
  }
  if ((param_1 & 0xc) != 0) {
    uVar1 = FUN_0046ad0b((int)this);
    if ((uVar1 & 0x100) != 0) {
      FUN_0046ad3f(this,0x100,0,0);
      SendMessageA(*(HWND *)((int)this + 0x1c),0x86,param_1 >> 2 & 1,0);
      FUN_0046ad3f(this,0,0x100,0);
    }
  }
  return local_4;
}

