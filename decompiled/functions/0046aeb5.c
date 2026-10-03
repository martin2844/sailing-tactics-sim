
void __fastcall FUN_0046aeb5(int param_1)

{
  if (*(int **)(param_1 + 0x38) == (int *)0x0) {
    SetFocus(*(HWND *)(param_1 + 0x1c));
    FUN_004680cc();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0046aed0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0x38) + 0xb4))();
  return;
}

