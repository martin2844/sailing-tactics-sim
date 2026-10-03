
void FUN_004ac630(int param_1,LPRECT param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  GetWindowRect(*(HWND *)(param_1 + 0x1c),param_2);
  uVar1 = FUN_004af3eb();
  *param_3 = uVar1;
  return;
}

