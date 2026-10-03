
undefined4 __fastcall FUN_004bbd48(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_004bfff8();
  if ((*(int **)(iVar1 + 4))[7] == param_1) {
    uVar2 = (**(code **)(**(int **)(iVar1 + 4) + 0x90))();
    return uVar2;
  }
  return 1;
}

