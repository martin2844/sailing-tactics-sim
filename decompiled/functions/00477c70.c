
undefined4 FUN_00477c70(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  CWnd *pCVar5;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  iVar1 = *extraout_ECX;
  extraout_ECX[9] = extraout_ECX[9] & 0xffffffbf;
  *(int *)(unaff_EBP + -0x1c) = extraout_ECX[0x25];
  iVar4 = (**(code **)(iVar1 + 0xdc))();
  *(int *)(unaff_EBP + -0x18) = iVar4;
  if (iVar4 == 0) {
    iVar4 = *(int *)(unaff_EBP + 8);
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    FUN_0046bd7a((undefined4 *)(unaff_EBP + -0x14));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (*(int *)(unaff_EBP + 0xc) == 0) {
      iVar4 = *(int *)(unaff_EBP + 8);
      if (iVar4 != 0) {
        if ((iVar4 == 0xef06) && (extraout_ECX[0x27] != 0)) {
          iVar4 = 0xf005;
        }
        (**(code **)(iVar1 + 0xcc))(iVar4,unaff_EBP + -0x14);
        *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(unaff_EBP + -0x14);
      }
    }
    else {
      iVar4 = *(int *)(unaff_EBP + 8);
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + 0xc);
    }
    FUN_0046ada7(*(void **)(unaff_EBP + -0x18),*(LPCSTR *)(unaff_EBP + -0x10));
    pCVar5 = FUN_004696a2(*(int *)(unaff_EBP + -0x18));
    if (pCVar5 != (CWnd *)0x0) {
      *(int *)(pCVar5 + 0x94) = iVar4;
      *(int *)(pCVar5 + 0x90) = iVar4;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0046bec5((int *)(unaff_EBP + -0x14));
  }
  uVar2 = *(undefined4 *)(unaff_EBP + -0xc);
  uVar3 = *(undefined4 *)(unaff_EBP + -0x1c);
  extraout_ECX[0x25] = iVar4;
  extraout_ECX[0x24] = iVar4;
  *unaff_FS_OFFSET = uVar2;
  return uVar3;
}

