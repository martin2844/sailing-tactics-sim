
int __thiscall FUN_004ba69e(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x84)) {
    do {
      if ((iVar1 != param_3) && (*(int *)(*(int *)(param_1 + 0x80) + iVar1 * 4) == param_2)) {
        return iVar1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x84));
  }
  return -1;
}

