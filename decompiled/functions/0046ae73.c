
void __fastcall FUN_0046ae73(int param_1)

{
  if (*(int **)(param_1 + 0x38) == (int *)0x0) {
    IsWindowEnabled(*(HWND *)(param_1 + 0x1c));
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0046ae88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0x38) + 0xac))();
  return;
}

