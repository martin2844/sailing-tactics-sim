
undefined4 FUN_0046f5c9(void)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffff88;
  *(int **)(unaff_EBP + -0x1c) = extraout_ECX;
  iVar1 = *extraout_ECX;
  (**(code **)(iVar1 + 0x60))();
  FUN_0046cfc9((undefined4 *)(unaff_EBP + -0x34));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046bd7a((undefined4 *)(unaff_EBP + -0x24));
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined4 *)(unaff_EBP + -0x28) = 0xffffffff;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(undefined ***)(unaff_EBP + -0x34) = &PTR_FUN_00486a54;
  FUN_0046c00d((void *)(unaff_EBP + -0x24),(LPCSTR)0x0);
  *(undefined4 *)(unaff_EBP + -4) = 2;
  iVar3 = (**(code **)(iVar1 + 0x8c))(*(undefined4 *)(unaff_EBP + 8),0x20,unaff_EBP + -0x34);
  *(int *)(unaff_EBP + -0x14) = iVar3;
  if (iVar3 == 0) {
    (**(code **)(iVar1 + 0x88))(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x34,0,0xf101);
    *(undefined ***)(unaff_EBP + -0x34) = &PTR_FUN_00486a54;
    *(undefined4 *)(unaff_EBP + -4) = 3;
    uVar4 = func_0x0046f76b();
    return uVar4;
  }
  (**(code **)(iVar1 + 0x74))();
  pcVar2 = *(code **)(iVar1 + 100);
  *(code **)(unaff_EBP + -0x18) = pcVar2;
  (*pcVar2)(1);
  FUN_00470ab5();
  *(undefined4 *)(unaff_EBP + -0x74) = 0;
  *(int **)(unaff_EBP + -0x78) = extraout_ECX;
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_0047b918();
  FUN_0046b223();
  *(undefined1 *)(unaff_EBP + -4) = 6;
  iVar3 = (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x38))();
  if (iVar3 != 0) {
    (**(code **)(iVar1 + 8))(unaff_EBP + -0x78);
  }
  FUN_00470c19(unaff_EBP + -0x78);
  (**(code **)(iVar1 + 0x90))(*(undefined4 *)(unaff_EBP + -0x14),0);
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_0047b918();
  FUN_0046b238();
  *(undefined4 *)(unaff_EBP + -4) = 4;
  (**(code **)(unaff_EBP + -0x18))(0);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_00470b91();
  *(undefined ***)(unaff_EBP + -0x34) = &PTR_FUN_00486a54;
  *(undefined4 *)(unaff_EBP + -4) = 0xb;
  FUN_0046bec5((int *)(unaff_EBP + -0x24));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return 1;
}

