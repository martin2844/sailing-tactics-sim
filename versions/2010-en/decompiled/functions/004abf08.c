
void __fastcall FUN_004abf08(int param_1)

{
  BOOL BVar1;
  
  FUN_004acd09();
  FUN_004ac829();
  BVar1 = IsWindow(*(HWND *)(param_1 + 0x54));
  if (BVar1 != 0) {
    EnableWindow(*(HWND *)(param_1 + 0x54),1);
  }
  *(undefined4 *)(param_1 + 0x54) = 0;
  FUN_004bfff8();
  FUN_004b6be3(1);
  return;
}

