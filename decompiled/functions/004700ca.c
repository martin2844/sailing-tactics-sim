
bool __thiscall FUN_004700ca(void *this,uint param_1)

{
  void *this_00;
  undefined4 *puVar1;
  
  if (param_1 != 0) {
    this_00 = (void *)FUN_00470044();
    *(uint *)((int)this + 4) = param_1;
    puVar1 = FUN_0046705e(this_00,param_1);
    *puVar1 = this;
    (**(code **)(*(int *)this + 0x14))(*(undefined4 *)((int)this + 4));
  }
  return param_1 != 0;
}

