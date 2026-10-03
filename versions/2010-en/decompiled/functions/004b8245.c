
void FUN_004b8245(void)

{
  code *pcVar1;
  Tact2010CString *original_this;
  int iVar2;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  FUN_004b045a((Tact2010CString *)(unaff_EBP + -0x10));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004b045a((Tact2010CString *)(unaff_EBP + -0x14));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  pcVar1 = *(code **)(**(int **)(unaff_EBP + 0x10) + 0x6c);
  iVar2 = (*pcVar1)(unaff_EBP + -0x10,4);
  if ((iVar2 != 0) && (*(int *)(*(int *)(unaff_EBP + -0x10) + -8) != 0)) {
    iVar2 = (*pcVar1)(unaff_EBP + -0x14,3);
    if ((iVar2 != 0) && (*(int *)(*(int *)(unaff_EBP + -0x14) + -8) != 0)) {
      original_this = *(Tact2010CString **)(unaff_EBP + 0x14);
      iVar2 = *(int *)(unaff_EBP + 0xc);
      if (original_this != (Tact2010CString *)0x0) {
        FUN_004b06ed(original_this,(char *)(*(int *)(unaff_EBP + -0x10) + 1));
        *(char **)(iVar2 + 0x3c) = original_this->data;
        *(int *)(iVar2 + 0x18) = *(int *)(iVar2 + 0x14) + 1;
      }
      FUN_004b093e(unaff_EBP + -0x14);
      FUN_004b0929(0);
      FUN_004b0929(0x2a);
      FUN_004b093e(unaff_EBP + -0x10);
      FUN_004b0929(0);
      *(int *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + 1;
    }
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x14));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x10));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

