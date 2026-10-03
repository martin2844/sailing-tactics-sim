
void __fastcall FUN_004af405(int param_1)

{
  if (*(int **)(param_1 + 0x38) == (int *)0x0) {
    GetWindowLongA(*(HWND *)(param_1 + 0x1c),-0x14);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x004af41c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0x38) + 0x7c))();
  return;
}

