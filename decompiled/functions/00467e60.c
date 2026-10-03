
undefined4 FUN_00467e60(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int unaff_EBP;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffc0;
  iVar2 = FUN_0047be12(&DAT_004ae4b8,FUN_00455c3a);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(unaff_EBP + -0x14) = iVar2;
  puVar5 = (undefined4 *)(iVar2 + 0x34);
  puVar6 = (undefined4 *)(unaff_EBP + -0x40);
  for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  iVar4 = *(int *)(unaff_EBP + 0x10);
  piVar1 = *(int **)(unaff_EBP + 8);
  *(undefined4 *)(iVar2 + 0x34) = *(undefined4 *)(unaff_EBP + 0xc);
  *(undefined4 *)(iVar2 + 0x3c) = *(undefined4 *)(unaff_EBP + 0x14);
  uVar3 = *(undefined4 *)(unaff_EBP + 0x18);
  *(int *)(iVar2 + 0x38) = iVar4;
  *(undefined4 *)(iVar2 + 0x40) = uVar3;
  if ((iVar4 == 2) && ((int *)piVar1[0xd] != (int *)0x0)) {
    (**(code **)(*(int *)piVar1[0xd] + 100))(0);
  }
  if (iVar4 == 0x110) {
    FUN_00467f50((int)piVar1,(LPRECT)(unaff_EBP + -0x24),(undefined4 *)(unaff_EBP + 0xc));
  }
  uVar3 = (**(code **)(*piVar1 + 0xa0))
                    (iVar4,*(undefined4 *)(unaff_EBP + 0x14),*(undefined4 *)(unaff_EBP + 0x18));
  *(undefined4 *)(unaff_EBP + 8) = uVar3;
  if (iVar4 == 0x110) {
    FUN_00467f73(piVar1,(int *)(unaff_EBP + -0x24),*(uint *)(unaff_EBP + 0xc));
    uVar3 = FUN_00467f31();
    return uVar3;
  }
  uVar3 = *(undefined4 *)(unaff_EBP + 8);
  puVar5 = (undefined4 *)(unaff_EBP + -0x40);
  puVar6 = (undefined4 *)(iVar2 + 0x34);
  for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar3;
}

