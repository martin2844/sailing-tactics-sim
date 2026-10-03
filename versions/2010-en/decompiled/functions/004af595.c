
void __fastcall FUN_004af595(int param_1)

{
  HWND pHVar1;
  
  if (*(int **)(param_1 + 0x38) == (int *)0x0) {
    pHVar1 = SetFocus(*(HWND *)(param_1 + 0x1c));
    FUN_004ac7ac(pHVar1);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x004af5b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0x38) + 0xb4))();
  return;
}

