
void __fastcall FUN_004af553(int param_1)

{
  if (*(int **)(param_1 + 0x38) == (int *)0x0) {
    IsWindowEnabled(*(HWND *)(param_1 + 0x1c));
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x004af568. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0x38) + 0xac))();
  return;
}

