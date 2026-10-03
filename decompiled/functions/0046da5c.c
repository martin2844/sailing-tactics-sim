
int * __thiscall FUN_0046da5c(void *this,byte param_1)

{
  int *piVar1;
  
  if ((param_1 & 2) == 0) {
    FUN_0046bec5(this);
    piVar1 = this;
    if ((param_1 & 1) == 0) {
      return this;
    }
  }
  else {
    FUN_00458790(this,4,*(int *)((int)this + -4),FUN_0046bec5);
    piVar1 = (int *)((int)this + -4);
  }
  FUN_0046b541((undefined *)piVar1);
  return this;
}

