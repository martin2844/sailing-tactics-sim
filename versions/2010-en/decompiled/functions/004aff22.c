
undefined4 __thiscall FUN_004aff22(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 4);
  if ((iVar1 == 0x200) || (iVar1 == 0xa0)) {
    if ((*(int *)(param_1 + 0x5c) == *(int *)(param_2 + 0x14)) &&
       ((*(int *)(param_1 + 0x60) == *(int *)(param_2 + 0x18) && (iVar1 == *(int *)(param_1 + 100)))
       )) {
      return 0;
    }
    *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(param_2 + 0x14);
    *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_2 + 0x18);
    *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_2 + 4);
  }
  else if ((iVar1 == 0xf) || (iVar1 == 0x118)) {
    return 0;
  }
  return 1;
}

