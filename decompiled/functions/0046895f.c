
void __fastcall FUN_0046895f(int *param_1)

{
  if (param_1[7] != 0) {
                    /* WARNING: Could not recover jumptable at 0x00468967. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x60))();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0046896a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0xac))();
  return;
}

