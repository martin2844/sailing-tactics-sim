
void __thiscall FUN_0046db61(void *this,int param_1)

{
  int iVar1;
  
  FUN_0046be50((int *)(*(int *)((int)this + 8) + param_1 * 4));
  for (; iVar1 = *(int *)((int)this + 8), param_1 < *(int *)((int)this + 4) + -1;
      param_1 = param_1 + 1) {
    FUN_0046bfbe((void *)(iVar1 + param_1 * 4),(int *)(iVar1 + 4 + param_1 * 4));
  }
  FUN_0046be50((int *)(iVar1 + param_1 * 4));
  return;
}

