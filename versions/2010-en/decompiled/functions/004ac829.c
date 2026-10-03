
int __fastcall FUN_004ac829(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  if (iVar1 != 0) {
    iVar2 = FUN_004ac73c(0);
    if (iVar2 != 0) {
      FUN_004ab78e(*(undefined4 *)(param_1 + 0x1c));
    }
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  *(undefined4 *)(param_1 + 0x38) = 0;
  return iVar1;
}

