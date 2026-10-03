
Tact2010CString *
FUN_004b0755(Tact2010CString *param_1,Tact2010CString *param_2,Tact2010CString *param_3)

{
  int iVar1;
  int iVar2;
  Tact2010CString *pTVar3;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  FUN_004b045a((Tact2010CString *)(unaff_EBP + -0x10));
  iVar1 = **(int **)(unaff_EBP + 0x10);
  iVar2 = **(int **)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_004b0714(*(undefined4 *)(iVar2 + -8),iVar2,*(undefined4 *)(iVar1 + -8),iVar1);
  FUN_004b046a(*(Tact2010CString **)(unaff_EBP + 8),(Tact2010CString *)(unaff_EBP + -0x10));
  *(undefined4 *)(unaff_EBP + -0x14) = 1;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x10));
  pTVar3 = *(Tact2010CString **)(unaff_EBP + 8);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return pTVar3;
}

