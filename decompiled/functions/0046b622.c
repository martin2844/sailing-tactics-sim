
bool __thiscall FUN_0046b622(void *this,int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = param_1;
  if (param_1 < 1) {
    FUN_0046b8a1(this,param_1);
    param_1 = 0;
    if (*(int **)((int)this + 0x80) != (int *)0x0) {
      param_1 = (**(code **)(**(int **)((int)this + 0x80) + 0x18))();
    }
    while (param_1 != 0) {
      piVar2 = (int *)(**(code **)(**(int **)((int)this + 0x80) + 0x1c))(&param_1);
      (**(code **)(*piVar2 + 0x90))();
    }
  }
  else if (param_1 == 1) {
    FUN_0046b8a1(this,1);
  }
  return iVar1 < 1;
}

