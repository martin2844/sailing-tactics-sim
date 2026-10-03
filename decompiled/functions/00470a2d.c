
bool __thiscall FUN_00470a2d(void *this,uint param_1)

{
  void *this_00;
  undefined4 *puVar1;
  
  if (param_1 != 0) {
    this_00 = (void *)FUN_004709a7();
    *(uint *)((int)this + 4) = param_1;
    puVar1 = FUN_0046705e(this_00,param_1);
    *puVar1 = this;
  }
  return param_1 != 0;
}

