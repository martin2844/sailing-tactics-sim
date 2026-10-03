
undefined4 FUN_004ac611(void)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_EBX;
  int unaff_EBP;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *unaff_FS_OFFSET;
  
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  puVar3 = (undefined4 *)(unaff_EBP + -0x40);
  puVar4 = (undefined4 *)(unaff_EBX + 0x34);
  for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar1;
}

