
undefined4 * FUN_004b2064(void)

{
  int iVar1;
  char *pcVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_004b045a((Tact2010CString *)(extraout_ECX + 3));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004b045a((Tact2010CString *)(extraout_ECX + 4));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_004b045a((Tact2010CString *)(extraout_ECX + 7));
  iVar1 = *(int *)(unaff_EBP + 0x14);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *extraout_ECX = &PTR_FUN_004cf504;
  piVar3 = (int *)FUN_004afbe5(iVar1 * 4 + 4);
  *(int **)(unaff_EBP + -0x14) = piVar3;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  if (piVar3 == (int *)0x0) {
    uVar4 = 0;
  }
  else {
    *piVar3 = iVar1;
    *(int **)(unaff_EBP + 0x14) = piVar3 + 1;
    FUN_0049b5c0(piVar3 + 1,4,iVar1,FUN_004b045a,FUN_004b05a5);
    uVar4 = *(undefined4 *)(unaff_EBP + 0x14);
  }
  pcVar2 = *(char **)(unaff_EBP + 0xc);
  extraout_ECX[2] = uVar4;
  uVar4 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  extraout_ECX[1] = iVar1;
  extraout_ECX[5] = uVar4;
  FUN_004b06ed((Tact2010CString *)(extraout_ECX + 3),pcVar2);
  FUN_004b06ed((Tact2010CString *)(extraout_ECX + 4),*(char **)(unaff_EBP + 0x10));
  uVar4 = *(undefined4 *)(unaff_EBP + -0xc);
  extraout_ECX[6] = *(undefined4 *)(unaff_EBP + 0x18);
  *unaff_FS_OFFSET = uVar4;
  return extraout_ECX;
}

