
void __thiscall FUN_00472380(void *this,int param_1)

{
  void *this_00;
  uint uVar1;
  
  this_00 = *(void **)((int)this + 0x14);
  uVar1 = FUN_00471f89(this_00,*(int *)((int)this + 8));
  uVar1 = uVar1 & 0xfffffdff;
  if (param_1 != 0) {
    uVar1 = uVar1 | 0x200;
  }
  FUN_00471f9a(this_00,*(int *)((int)this + 8),uVar1);
  return;
}

