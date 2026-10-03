
void __fastcall FUN_004b772c(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (*(int *)(param_1 + 0x1c) != 0) {
    iVar1 = FUN_004bcdcf();
    if (iVar1 != 0) {
      piVar2 = (int *)FUN_004bcdbe();
      (**(code **)(*piVar2 + 0x60))();
      return;
    }
  }
  FUN_004ad050();
  return;
}

