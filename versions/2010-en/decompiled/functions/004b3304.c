
void __fastcall FUN_004b3304(int *param_1)

{
  if ((param_1[0xd] == 0) && (param_1[0x12] != 0)) {
                    /* WARNING: Could not recover jumptable at 0x004b3312. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x84))();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x004b331a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0xa8))();
  return;
}

