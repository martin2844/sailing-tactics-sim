
undefined4 * FUN_0046d984(void)

{
  int iVar1;
  LPCSTR pCVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0046bd7a(extraout_ECX + 3);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046bd7a(extraout_ECX + 4);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0046bd7a(extraout_ECX + 7);
  iVar1 = *(int *)(unaff_EBP + 0x14);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *extraout_ECX = &PTR_FUN_00487864;
  piVar3 = (int *)FUN_0046b505(iVar1 * 4 + 4);
  *(int **)(unaff_EBP + -0x14) = piVar3;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  if (piVar3 == (int *)0x0) {
    uVar4 = 0;
  }
  else {
    *piVar3 = iVar1;
    *(int **)(unaff_EBP + 0x14) = piVar3 + 1;
    FUN_004586f0(piVar3 + 1,4,iVar1,FUN_0046bd7a);
    uVar4 = *(undefined4 *)(unaff_EBP + 0x14);
  }
  pCVar2 = *(LPCSTR *)(unaff_EBP + 0xc);
  extraout_ECX[2] = uVar4;
  uVar4 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  extraout_ECX[1] = iVar1;
  extraout_ECX[5] = uVar4;
  FUN_0046c00d(extraout_ECX + 3,pCVar2);
  FUN_0046c00d(extraout_ECX + 4,*(LPCSTR *)(unaff_EBP + 0x10));
  uVar4 = *(undefined4 *)(unaff_EBP + -0xc);
  extraout_ECX[6] = *(undefined4 *)(unaff_EBP + 0x18);
  *unaff_FS_OFFSET = uVar4;
  return extraout_ECX;
}

