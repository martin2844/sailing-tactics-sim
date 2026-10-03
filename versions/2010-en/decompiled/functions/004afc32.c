
void __fastcall FUN_004afc32(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x1c) == 0) {
    iVar1 = FUN_004bce18();
    if (iVar1 != 0) {
      AfxPostQuitMessage(0);
    }
  }
  FUN_004afe9e();
  return;
}

