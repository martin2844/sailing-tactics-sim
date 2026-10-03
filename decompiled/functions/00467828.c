
void __fastcall FUN_00467828(int param_1)

{
  BOOL BVar1;
  
  FUN_00468629();
  FUN_00468149(param_1);
  BVar1 = IsWindow(*(HWND *)(param_1 + 0x54));
  if (BVar1 != 0) {
    EnableWindow(*(HWND *)(param_1 + 0x54),1);
  }
  *(undefined4 *)(param_1 + 0x54) = 0;
  FUN_0047b918();
  FUN_00472503(1);
  return;
}

