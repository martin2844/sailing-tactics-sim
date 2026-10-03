
void __thiscall FUN_0047c32d(void *this,uint param_1)

{
  uint uVar1;
  
  FUN_00456537(this,param_1 & 0x10);
  uVar1 = *(uint *)((int)this + 100);
  if (uVar1 != param_1) {
    *(uint *)((int)this + 100) = param_1;
    (**(code **)(*(int *)this + 0xdc))(uVar1,param_1);
  }
  return;
}

