
void FUN_0047bf57(void)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00485b94;
  pcVar1 = (code *)extraout_ECX[4];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(0);
  }
  if ((HMODULE)extraout_ECX[2] != (HMODULE)0x0) {
    FreeLibrary((HMODULE)extraout_ECX[2]);
  }
  uVar2 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_004865ec;
  *unaff_FS_OFFSET = uVar2;
  return;
}

