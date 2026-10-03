
void __fastcall FUN_004b6b16(int param_1)

{
  if (*(int **)(param_1 + 0x80) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x004b6b22. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0x80) + 0x3c))();
    return;
  }
  return;
}

