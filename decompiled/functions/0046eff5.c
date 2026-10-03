
undefined4 FUN_0046eff5(void)

{
  byte *pbVar1;
  int iVar2;
  LPSTR pCVar3;
  undefined4 uVar4;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  iVar2 = *extraout_ECX;
  *(int *)(unaff_EBP + -0x18) = iVar2;
  iVar2 = (**(code **)(iVar2 + 0x60))();
  if (iVar2 != 0) {
    FUN_0046bd7a((undefined4 *)(unaff_EBP + -0x10));
    iVar2 = *(int *)(extraout_ECX[8] + -8);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar2 == 0) {
      FUN_0046bfbe((void *)(unaff_EBP + -0x10),extraout_ECX + 7);
      if (*(int *)(*(int *)(unaff_EBP + -0x10) + -8) == 0) {
        FUN_0046d861(0xf003);
      }
    }
    else {
      FUN_0046bfbe((void *)(unaff_EBP + -0x10),extraout_ECX + 8);
      if (DAT_004ae6a0 != 0) {
        pbVar1 = (byte *)extraout_ECX[8];
        iVar2 = 0x104;
        pCVar3 = (LPSTR)FUN_0046c276((void *)(unaff_EBP + -0x10),0x104);
        FUN_0046ce82(pbVar1,pCVar3,iVar2);
        FUN_0046c2c5((void *)(unaff_EBP + -0x10),-1);
      }
    }
    FUN_0046bd7a((undefined4 *)(unaff_EBP + -0x14));
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_004744ca((int *)(unaff_EBP + -0x14),0xf103);
    iVar2 = FUN_004725eb(*(undefined4 *)(unaff_EBP + -0x14),3,0xf103);
    if (iVar2 == 2) {
LAB_0046f0e2:
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_0046bec5((int *)(unaff_EBP + -0x14));
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0046bec5((int *)(unaff_EBP + -0x10));
      uVar4 = 0;
      goto LAB_0046f0fb;
    }
    if (iVar2 == 6) {
      iVar2 = (**(code **)(*(int *)(unaff_EBP + -0x18) + 0xa4))();
      if (iVar2 == 0) goto LAB_0046f0e2;
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_0046bec5((int *)(unaff_EBP + -0x14));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0046bec5((int *)(unaff_EBP + -0x10));
  }
  uVar4 = 1;
LAB_0046f0fb:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar4;
}

