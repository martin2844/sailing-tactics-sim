
undefined4 * __thiscall FUN_0046d073(void *this,uint *param_1)

{
  int iVar1;
  
  if (param_1 == (uint *)0x0) {
    *(undefined4 *)this = 0;
    *(undefined4 *)((int)this + 4) = 0;
    *(undefined4 *)((int)this + 8) = 0;
  }
  else {
    iVar1 = FUN_0046d16c(param_1);
    FUN_0046d0a2(this,param_1,iVar1);
  }
  return this;
}

