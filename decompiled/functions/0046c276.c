
int __thiscall FUN_0046c276(void *this,int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = *(undefined4 **)this;
  if ((1 < (int)puVar1[-3]) || ((int)puVar1[-1] < param_1)) {
    iVar2 = puVar1[-2];
    if (param_1 < iVar2) {
      param_1 = iVar2;
    }
    FUN_0046bdc1(this,param_1);
    FUN_00457850(*(undefined4 **)this,puVar1,iVar2 + 1);
    *(int *)(*(int *)this + -8) = iVar2;
    FUN_0046be2d(puVar1 + -3);
  }
  return *(int *)this;
}

