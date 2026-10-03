
void FUN_0046df6d(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int extraout_ECX;
  int unaff_EBP;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  iVar1 = FUN_0046b505(*(int *)(*(int *)(extraout_ECX + 0x10) + -8) + 5);
  *(int *)(unaff_EBP + -0x10) = iVar1;
  iVar2 = FUN_0047b918();
  iVar4 = 0;
  iVar1 = *(int *)(extraout_ECX + 4);
  *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(iVar2 + 4);
  if (0 < iVar1) {
    do {
      iVar1 = iVar4 + 1;
      wsprintfA(*(LPSTR *)(unaff_EBP + -0x10),*(LPCSTR *)(extraout_ECX + 0x10),iVar1);
      piVar3 = (int *)FUN_0047b258();
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_0046bfbe((void *)(*(int *)(extraout_ECX + 8) + iVar4 * 4),piVar3);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0046bec5((int *)(unaff_EBP + -0x18));
      iVar4 = iVar1;
    } while (iVar1 < *(int *)(extraout_ECX + 4));
  }
  FUN_0046b541(*(undefined **)(unaff_EBP + -0x10));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

