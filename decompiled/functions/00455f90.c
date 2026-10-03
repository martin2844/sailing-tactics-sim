
undefined4 * __thiscall FUN_00455f90(void *this,undefined4 param_1,undefined4 param_2)

{
  FUN_0046cfd9(this,param_1);
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x94) = param_2;
  *(undefined ***)this = &PTR_FUN_004873bc;
  return this;
}

