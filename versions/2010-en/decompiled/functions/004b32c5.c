
void __fastcall FUN_004b32c5(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x34);
  while (iVar1 != 0) {
    iVar1 = FUN_004ab25b();
    *(undefined4 *)(iVar1 + 0x3c) = 0;
    iVar1 = *(int *)(param_1 + 0x34);
  }
  return;
}

