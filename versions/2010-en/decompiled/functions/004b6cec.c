
undefined4 FUN_004b6cec(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBP;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  FUN_004b045a((Tact2010CString *)(unaff_EBP + -0x10));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004b1f41(*(undefined4 *)(unaff_EBP + 8));
  iVar3 = *(int *)(unaff_EBP + 0x10);
  if (iVar3 == -1) {
    iVar3 = *(int *)(unaff_EBP + 8);
  }
  iVar1 = FUN_004bfff8();
  uVar2 = (**(code **)(**(int **)(iVar1 + 4) + 0x94))
                    (*(undefined4 *)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + 0xc),iVar3);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x10));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar2;
}

