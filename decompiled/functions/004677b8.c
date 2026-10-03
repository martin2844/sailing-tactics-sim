
undefined4 * __thiscall FUN_004677b8(void *this,uint param_1,undefined4 param_2)

{
  FUN_00467d63(this);
  *(undefined ***)this = &PTR_FUN_00485644;
  _memset((uint *)((int)this + 0x3c),0,0x20);
  *(undefined4 *)((int)this + 0x50) = param_2;
  *(uint *)((int)this + 0x3c) = param_1;
  *(uint *)((int)this + 0x40) = param_1 & 0xffff;
  return this;
}

