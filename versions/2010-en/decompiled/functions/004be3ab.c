
undefined4 __thiscall FUN_004be3ab(void *this,uint param_2)

{
  uint uVar1;
  undefined4 local_4;
  
  local_4 = 0;
  uVar1 = FUN_004af3eb();
  if (((uVar1 & 0x100) != 0) && ((param_2 & 0x40) != 0)) {
    local_4 = 1;
  }
  if ((param_2 & 3) != 0) {
    FUN_004af4dd(0,0,0,0,0,(-(uint)((param_2 & 1) != 0) & 0xffffffc0) + 0x80 | 0x17);
  }
  if ((param_2 & 0x30) != 0) {
    FUN_004af56e(param_2 >> 4 & 1);
  }
  if ((param_2 & 0xc) != 0) {
    uVar1 = FUN_004af3eb();
    if ((uVar1 & 0x100) != 0) {
      FUN_004af41f(0x100,0,0);
      SendMessageA(*(HWND *)((int)this + 0x1c),0x86,param_2 >> 2 & 1,0);
      FUN_004af41f(0,0x100,0);
    }
  }
  return local_4;
}

