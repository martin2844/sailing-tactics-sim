
void __fastcall FUN_004ad03f(int *param_1)

{
  if (param_1[7] != 0) {
                    /* WARNING: Could not recover jumptable at 0x004ad047. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x60))();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x004ad04a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0xac))();
  return;
}

