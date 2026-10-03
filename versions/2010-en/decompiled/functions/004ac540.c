
undefined4 FUN_004ac540(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int unaff_EBP;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar8;
  
  FUN_0049bcd8();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffc0;
  iVar2 = FUN_004c04f2(FUN_0049a32a);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(unaff_EBP + -0x14) = iVar2;
  puVar6 = (undefined4 *)(iVar2 + 0x34);
  puVar7 = (undefined4 *)(unaff_EBP + -0x40);
  for (iVar5 = 7; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  iVar5 = *(int *)(unaff_EBP + 0x10);
  piVar1 = *(int **)(unaff_EBP + 8);
  *(undefined4 *)(iVar2 + 0x34) = *(undefined4 *)(unaff_EBP + 0xc);
  *(undefined4 *)(iVar2 + 0x3c) = *(undefined4 *)(unaff_EBP + 0x14);
  uVar4 = *(undefined4 *)(unaff_EBP + 0x18);
  *(int *)(iVar2 + 0x38) = iVar5;
  *(undefined4 *)(iVar2 + 0x40) = uVar4;
  if ((iVar5 == 2) && ((int *)piVar1[0xd] != (int *)0x0)) {
    (**(code **)(*(int *)piVar1[0xd] + 100))(0);
  }
  if (iVar5 == 0x110) {
    FUN_004ac630(piVar1,unaff_EBP + -0x24,unaff_EBP + 0xc);
  }
  uVar4 = *(undefined4 *)(unaff_EBP + 0x18);
  uVar8 = *(undefined4 *)(unaff_EBP + 0x14);
  uVar3 = (**(code **)(*piVar1 + 0xa0))(iVar5,uVar8,uVar4);
  *(undefined4 *)(unaff_EBP + 8) = uVar3;
  if (iVar5 == 0x110) {
    FUN_004ac653(piVar1,unaff_EBP + -0x24,*(undefined4 *)(unaff_EBP + 0xc));
    uVar4 = FUN_004ac611(uVar8,uVar4);
    return uVar4;
  }
  uVar4 = *(undefined4 *)(unaff_EBP + 8);
  puVar6 = (undefined4 *)(unaff_EBP + -0x40);
  puVar7 = (undefined4 *)(iVar2 + 0x34);
  for (iVar5 = 7; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar4;
}

