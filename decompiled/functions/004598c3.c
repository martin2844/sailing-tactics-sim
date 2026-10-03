
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_004598c3(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int unaff_EBP;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  
  iVar2 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iVar3 = *(int *)(unaff_EBP + 0x10);
  iVar4 = *(int *)(unaff_EBP + 8);
  iVar5 = *(int *)(*(int *)(iVar3 + 8) + *(int *)(unaff_EBP + -0x1c) * 8);
  *(int *)(unaff_EBP + -0x1c) = iVar5;
  while (iVar5 != *(int *)(unaff_EBP + 0x14)) {
    if ((iVar5 < 0) || (*(int *)(iVar3 + 4) <= iVar5)) {
      *(undefined4 *)(iVar2 + -4) = 0x459886;
      FUN_00459fe0();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0;
    iVar1 = *(int *)(*(int *)(iVar3 + 8) + 4 + iVar5 * 8);
    if (iVar1 != 0) {
      *(undefined4 *)(iVar2 + -4) = 0x103;
      *(int *)(iVar2 + -8) = iVar4;
      *(int *)(iVar2 + -0xc) = iVar1;
      *(undefined4 *)(iVar2 + -0x10) = 0x4598a4;
      __CallSettingFrame_12
                (*(undefined4 *)(iVar2 + -0xc),*(undefined4 *)(iVar2 + -8),*(int *)(iVar2 + -4));
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    iVar5 = *(int *)(*(int *)(iVar3 + 8) + iVar5 * 8);
    *(int *)(unaff_EBP + -0x1c) = iVar5;
  }
  *(int *)(iVar4 + 8) = iVar5;
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0x10);
  return;
}

