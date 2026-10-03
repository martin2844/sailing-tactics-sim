
void __thiscall FUN_004b77ca(void)

{
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  FUN_004b4f06(extraout_ECX);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  GetClientRect(*(HWND *)(extraout_ECX + 0x1c),(LPRECT)(unaff_EBP + -0x2c));
  GetWindowRect(*(HWND *)(extraout_ECX + 0x1c),(LPRECT)(unaff_EBP + -0x1c));
  ScreenToClient(*(HWND *)(extraout_ECX + 0x1c),(LPPOINT)(unaff_EBP + -0x1c));
  ScreenToClient(*(HWND *)(extraout_ECX + 0x1c),(LPPOINT)(unaff_EBP + -0x14));
  OffsetRect((LPRECT)(unaff_EBP + -0x2c),-*(int *)(unaff_EBP + -0x1c),-*(int *)(unaff_EBP + -0x18));
  FUN_004b4d05(unaff_EBP + -0x2c);
  OffsetRect((LPRECT)(unaff_EBP + -0x1c),-*(int *)(unaff_EBP + -0x1c),-*(int *)(unaff_EBP + -0x18));
  FUN_004b7c52(unaff_EBP + -0x40,unaff_EBP + -0x1c);
  FUN_004b4d51(unaff_EBP + -0x1c);
  SendMessageA(*(HWND *)(extraout_ECX + 0x1c),0x14,*(WPARAM *)(unaff_EBP + -0x3c),0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004b4f78();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

