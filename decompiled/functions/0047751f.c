
void __thiscall FUN_0047751f(void *this,undefined4 param_1)

{
  int iVar1;
  
  if ((*(byte *)((int)this + 0x24) & 0x20) != 0) {
    param_1 = 1;
  }
  iVar1 = FUN_0046ae73((int)this);
  if (iVar1 == 0) {
    param_1 = 0;
  }
  (**(code **)(*(int *)this + 0xa8))(0x86,param_1,0);
  return;
}

