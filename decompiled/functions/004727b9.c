
undefined4 __fastcall FUN_004727b9(int param_1)

{
  undefined4 uVar1;
  
  if (*(int **)(param_1 + 0x80) == (int *)0x0) {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x004727c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(**(int **)(param_1 + 0x80) + 0x18))();
  return uVar1;
}

