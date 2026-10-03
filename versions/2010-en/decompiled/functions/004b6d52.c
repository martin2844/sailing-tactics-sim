
undefined4 __fastcall FUN_004b6d52(int param_1)

{
  undefined4 uVar1;
  
  if (*(int **)(param_1 + 0x80) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x004b6d5e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(**(int **)(param_1 + 0x80) + 0x28))();
    return uVar1;
  }
  return 1;
}

