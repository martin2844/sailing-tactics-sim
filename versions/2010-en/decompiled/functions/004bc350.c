
undefined4 FUN_004bc350(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  iVar4 = *extraout_ECX;
  extraout_ECX[9] = extraout_ECX[9] & 0xffffffbf;
  *(int *)(unaff_EBP + -0x1c) = extraout_ECX[0x25];
  iVar3 = (**(code **)(iVar4 + 0xdc))();
  *(int *)(unaff_EBP + -0x18) = iVar3;
  if (iVar3 == 0) {
    iVar3 = *(int *)(unaff_EBP + 8);
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    FUN_004b045a((Tact2010CString *)(unaff_EBP + -0x14));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (*(int *)(unaff_EBP + 0xc) == 0) {
      iVar3 = *(int *)(unaff_EBP + 8);
      if (iVar3 != 0) {
        if ((iVar3 == 0xef06) && (extraout_ECX[0x27] != 0)) {
          iVar3 = 0xf005;
        }
        (**(code **)(iVar4 + 0xcc))(iVar3,unaff_EBP + -0x14);
        *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(unaff_EBP + -0x14);
      }
    }
    else {
      iVar3 = *(int *)(unaff_EBP + 8);
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + 0xc);
    }
    FUN_004af487(*(undefined4 *)(unaff_EBP + -0x10));
    iVar4 = FUN_004add82();
    if (iVar4 != 0) {
      *(int *)(iVar4 + 0x94) = iVar3;
      *(int *)(iVar4 + 0x90) = iVar3;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x14));
  }
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  uVar2 = *(undefined4 *)(unaff_EBP + -0x1c);
  extraout_ECX[0x25] = iVar3;
  extraout_ECX[0x24] = iVar3;
  *unaff_FS_OFFSET = uVar1;
  return uVar2;
}

