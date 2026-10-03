
int __thiscall FUN_004b6998(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar1 = FUN_004b6641(0);
    if (-1 < iVar1) {
      iVar1 = *(int *)(*(int *)(param_1 + 0x5c) + iVar1 * 0x14 + 0x10);
      iVar2 = *(int *)(iVar1 + -8);
      if (param_2 < iVar2) {
        iVar2 = param_2 + -1;
      }
      FUN_0049c110(param_3,iVar1,iVar2);
    }
    *(undefined1 *)(iVar2 + param_3) = 0;
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}

