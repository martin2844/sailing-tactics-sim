
undefined4 FUN_0046f794(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffff8c;
  *(int **)(unaff_EBP + -0x18) = extraout_ECX;
  FUN_0046cfc9((undefined4 *)(unaff_EBP + -0x30));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046bd7a((undefined4 *)(unaff_EBP + -0x20));
  *(undefined4 *)(unaff_EBP + -0x24) = 0xffffffff;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(undefined ***)(unaff_EBP + -0x30) = &PTR_FUN_00486a54;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  FUN_0046c00d((void *)(unaff_EBP + -0x20),(LPCSTR)0x0);
  iVar1 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  iVar2 = (**(code **)(iVar1 + 0x8c))(*(undefined4 *)(unaff_EBP + 8),0x1012,unaff_EBP + -0x30);
  *(int *)(unaff_EBP + -0x14) = iVar2;
  if (iVar2 == 0) {
    (**(code **)(iVar1 + 0x88))(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x30,1,0xf100);
    *(undefined ***)(unaff_EBP + -0x30) = &PTR_FUN_00486a54;
    *(undefined4 *)(unaff_EBP + -4) = 3;
    uVar3 = func_0x0046f912();
    return uVar3;
  }
  FUN_00470ab5();
  *(undefined4 *)(unaff_EBP + -0x70) = 0;
  *(int **)(unaff_EBP + -0x74) = extraout_ECX;
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_0047b918();
  FUN_0046b223();
  *(undefined1 *)(unaff_EBP + -4) = 6;
  (**(code **)(iVar1 + 8))(unaff_EBP + -0x74);
  FUN_00470c19(unaff_EBP + -0x74);
  (**(code **)(iVar1 + 0x90))(*(undefined4 *)(unaff_EBP + -0x14),0);
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_0047b918();
  FUN_0046b238();
  *(undefined4 *)(unaff_EBP + -4) = 4;
  (**(code **)(iVar1 + 100))(0);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_00470b91();
  *(undefined ***)(unaff_EBP + -0x30) = &PTR_FUN_00486a54;
  *(undefined4 *)(unaff_EBP + -4) = 0xb;
  FUN_0046bec5((int *)(unaff_EBP + -0x20));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return 1;
}

