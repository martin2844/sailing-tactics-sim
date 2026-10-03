
void FUN_004b6242(void)

{
  HMENU hMenu;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_004cf814;
  hMenu = (HMENU)extraout_ECX[9];
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (hMenu != (HMENU)0x0) {
    DestroyMenu(hMenu);
  }
  if ((HMENU)extraout_ECX[0xb] != (HMENU)0x0) {
    DestroyMenu((HMENU)extraout_ECX[0xb]);
  }
  if ((HMENU)extraout_ECX[0xd] != (HMENU)0x0) {
    DestroyMenu((HMENU)extraout_ECX[0xd]);
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_004b05a5((Tact2010CString *)(extraout_ECX + 0x18));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004af667();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

