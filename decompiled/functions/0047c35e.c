
undefined4 __thiscall FUN_0047c35e(void *this,int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = (int *)0x0;
  if ((0 < param_1) && (piVar1 = FUN_00458640(param_1,param_2), piVar1 == (int *)0x0)) {
    return 0;
  }
  FUN_00457710(*(undefined **)((int)this + 0x5c));
  *(int **)((int)this + 0x5c) = piVar1;
  *(int *)((int)this + 0x58) = param_1;
  return 1;
}

