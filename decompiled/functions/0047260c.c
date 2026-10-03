
undefined4 FUN_0047260c(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBP;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  FUN_0046bd7a((undefined4 *)(unaff_EBP + -0x10));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046d861(*(UINT *)(unaff_EBP + 8));
  iVar3 = *(int *)(unaff_EBP + 0x10);
  if (iVar3 == -1) {
    iVar3 = *(int *)(unaff_EBP + 8);
  }
  iVar1 = FUN_0047b918();
  uVar2 = (**(code **)(**(int **)(iVar1 + 4) + 0x94))
                    (*(undefined4 *)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + 0xc),iVar3);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0046bec5((int *)(unaff_EBP + -0x10));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar2;
}

