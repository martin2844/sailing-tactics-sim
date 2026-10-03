
int __thiscall FUN_00475fbe(void *this,int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)((int)this + 0x84)) {
    do {
      if ((iVar1 != param_2) && (*(int *)(*(int *)((int)this + 0x80) + iVar1 * 4) == param_1)) {
        return iVar1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)((int)this + 0x84));
  }
  return -1;
}

