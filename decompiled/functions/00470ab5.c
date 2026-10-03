
undefined4 * FUN_00470ab5(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *extraout_ECX;
  int iVar4;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  iVar3 = **(int **)(unaff_EBP + 8);
  (**(code **)(iVar3 + 0x20))(extraout_ECX + 4);
  uVar1 = *(undefined4 *)(unaff_EBP + 0xc);
  uVar2 = *(undefined4 *)(unaff_EBP + 8);
  extraout_ECX[3] = 0xffffffff;
  extraout_ECX[5] = uVar1;
  extraout_ECX[8] = uVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0xe] = 0;
  extraout_ECX[0xd] = 0;
  *extraout_ECX = 0;
  extraout_ECX[1] = 1;
  if ((~(byte)uVar1 & 1) == 0) {
    extraout_ECX[0xf] = 0x40;
  }
  else {
    extraout_ECX[0xf] = 0x10;
  }
  uVar1 = *(undefined4 *)(unaff_EBP + 0x14);
  extraout_ECX[6] = 1;
  extraout_ECX[0xb] = uVar1;
  iVar4 = *(int *)(unaff_EBP + 0x10);
  extraout_ECX[0x10] = 0x89;
  extraout_ECX[2] = 0;
  if (iVar4 < 0x80) {
    extraout_ECX[7] = 0x80;
    extraout_ECX[0xb] = 0;
  }
  else {
    extraout_ECX[7] = iVar4;
  }
  iVar4 = extraout_ECX[0xb];
  *(undefined4 *)(unaff_EBP + 0x10) = extraout_ECX[7];
  if (iVar4 == 0) {
    iVar3 = (**(code **)(iVar3 + 0x58))(3,0,0,0);
    extraout_ECX[2] = iVar3;
    if (iVar3 == 0) {
      iVar3 = FUN_0046b505(extraout_ECX[7]);
      extraout_ECX[0xb] = iVar3;
      extraout_ECX[6] = 0;
    }
    else {
      *(undefined4 *)(unaff_EBP + 0x10) = 0;
    }
  }
  iVar4 = *(int *)(unaff_EBP + 0x10) + extraout_ECX[0xb];
  extraout_ECX[10] = iVar4;
  iVar3 = extraout_ECX[0xb];
  if ((*(byte *)(extraout_ECX + 5) & 1) != 0) {
    iVar3 = iVar4;
  }
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  extraout_ECX[9] = iVar3;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}

