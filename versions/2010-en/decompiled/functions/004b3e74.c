
undefined4 FUN_004b3e74(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffff8c;
  *(int **)(unaff_EBP + -0x18) = extraout_ECX;
  FUN_004b16a9();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004b045a((Tact2010CString *)(unaff_EBP + -0x20));
  *(undefined4 *)(unaff_EBP + -0x24) = 0xffffffff;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(undefined ***)(unaff_EBP + -0x30) = &PTR_FUN_004ce6f4;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  FUN_004b06ed((Tact2010CString *)(unaff_EBP + -0x20),(char *)0x0);
  iVar1 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  iVar2 = (**(code **)(iVar1 + 0x8c))(*(undefined4 *)(unaff_EBP + 8),0x1012,unaff_EBP + -0x30);
  *(int *)(unaff_EBP + -0x14) = iVar2;
  if (iVar2 == 0) {
    (**(code **)(iVar1 + 0x88))(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x30,1,0xf100);
    *(undefined ***)(unaff_EBP + -0x30) = &PTR_FUN_004ce6f4;
    *(undefined4 *)(unaff_EBP + -4) = 3;
    uVar3 = func_0x004b3ff2();
    return uVar3;
  }
  FUN_004b5195(iVar2,2,0x1000,0);
  *(undefined4 *)(unaff_EBP + -0x70) = 0;
  *(int **)(unaff_EBP + -0x74) = extraout_ECX;
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_004bfff8();
  FUN_004af903();
  *(undefined1 *)(unaff_EBP + -4) = 6;
  (**(code **)(iVar1 + 8))(unaff_EBP + -0x74);
  FUN_004b52f9();
  (**(code **)(iVar1 + 0x90))(*(undefined4 *)(unaff_EBP + -0x14),0);
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_004bfff8();
  FUN_004af918();
  *(undefined4 *)(unaff_EBP + -4) = 4;
  (**(code **)(iVar1 + 100))(0);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_004b5271();
  *(undefined ***)(unaff_EBP + -0x30) = &PTR_FUN_004ce6f4;
  *(undefined4 *)(unaff_EBP + -4) = 0xb;
  FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x20));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return 1;
}

