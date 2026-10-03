
void __thiscall FUN_004734ed(void *this,int param_1)

{
  uint uVar1;
  
  *(uint *)((int)this + 0x60) = *(uint *)((int)this + 0x60) & 0xfffffffc;
  if (param_1 != 0) {
    uVar1 = FUN_0046ad0b((int)this);
    if ((uVar1 & 0x10000000) == 0) {
      *(uint *)((int)this + 0x60) = *(uint *)((int)this + 0x60) | 2;
      return;
    }
    if (param_1 != 0) {
      return;
    }
  }
  uVar1 = FUN_0046ad0b((int)this);
  if ((uVar1 & 0x10000000) != 0) {
    *(uint *)((int)this + 0x60) = *(uint *)((int)this + 0x60) | 1;
  }
  return;
}

