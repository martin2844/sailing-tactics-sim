
undefined4 __thiscall FUN_0047ba13(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)this;
  if (iVar2 == 0) {
    return 0;
  }
  if (iVar2 == param_1) {
    *(undefined4 *)this = *(undefined4 *)(*(int *)((int)this + 4) + param_1);
  }
  else {
    if (iVar2 == 0) {
      return 0;
    }
    do {
      iVar1 = *(int *)(iVar2 + *(int *)((int)this + 4));
      if (iVar1 == param_1) break;
      iVar2 = iVar1;
    } while (iVar1 != 0);
    if (iVar2 == 0) {
      return 0;
    }
    *(undefined4 *)(iVar2 + *(int *)((int)this + 4)) =
         *(undefined4 *)(param_1 + *(int *)((int)this + 4));
  }
  return 1;
}

