
void __thiscall FUN_00475f9e(void *this,int param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)((int)this + 100);
  *(uint *)((int)this + 100) = uVar1 & 0xfffff0ff;
  FUN_00472ecb(this,param_1);
  *(uint *)((int)this + 100) = uVar1;
  return;
}

