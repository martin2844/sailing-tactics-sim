
undefined4 FUN_004ac17b(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined1 local_c [8];
  
  iVar1 = FUN_004bfff8();
  uVar3 = 0;
  if (*(int *)(iVar1 + 4) != 0) {
    piVar2 = (int *)FUN_0049a2e0();
    if ((piVar2 != (int *)0x0) &&
       (iVar1 = (**(code **)(*piVar2 + 0x14))(0xe146,0,0,local_c), iVar1 != 0)) {
      return 1;
    }
    iVar1 = FUN_004bfff8();
    uVar3 = (**(code **)(**(int **)(iVar1 + 4) + 0x14))(0xe146,0,0,local_c);
  }
  return uVar3;
}

