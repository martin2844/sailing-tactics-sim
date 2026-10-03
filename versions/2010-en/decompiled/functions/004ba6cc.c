
void __thiscall FUN_004ba6cc(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x84)) {
    do {
      iVar1 = FUN_004ba70d(iVar2);
      if (iVar1 != 0) {
        FUN_004bcdbe();
        FUN_004bbf9a(iVar1,param_2,1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 0x84));
  }
  return;
}

