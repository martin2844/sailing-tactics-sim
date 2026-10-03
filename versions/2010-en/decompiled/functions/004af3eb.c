
void __fastcall FUN_004af3eb(int param_1)

{
  if (*(int **)(param_1 + 0x38) == (int *)0x0) {
    GetWindowLongA(*(HWND *)(param_1 + 0x1c),-0x10);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x004af402. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0x38) + 0x78))();
  return;
}

