
undefined4 FUN_0046ee6b(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe8;
  FUN_0046bf33((void *)(unaff_EBP + -0x14),*(LPCSTR *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(int *)(*(int *)(unaff_EBP + -0x14) + -8) == 0) {
    piVar1 = (int *)extraout_ECX[9];
    FUN_0046bfbe((void *)(unaff_EBP + -0x14),extraout_ECX + 8);
    if ((*(int *)(unaff_EBP + 0xc) != 0) && (*(int *)(*(int *)(unaff_EBP + -0x14) + -8) == 0)) {
      FUN_0046bfbe((void *)(unaff_EBP + -0x14),extraout_ECX + 7);
      iVar2 = FUN_0046c32e((void *)(unaff_EBP + -0x14),(byte *)" #%;/\\");
      if (iVar2 != -1) {
        FUN_0046c2c5((void *)(unaff_EBP + -0x14),iVar2);
      }
      FUN_0046bd7a((undefined4 *)(unaff_EBP + -0x18));
      iVar2 = *piVar1;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      iVar2 = (**(code **)(iVar2 + 0x6c))(unaff_EBP + -0x18,4);
      if ((iVar2 != 0) && (*(int *)(*(int *)(unaff_EBP + -0x18) + -8) != 0)) {
        FUN_0046c25e((void *)(unaff_EBP + -0x14),(undefined4 *)(unaff_EBP + -0x18));
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_0046bec5((int *)(unaff_EBP + -0x18));
    }
    iVar2 = FUN_0047b918();
    iVar2 = FUN_00472451(*(void **)(iVar2 + 4),unaff_EBP + -0x14,
                         (-(uint)(*(int *)(unaff_EBP + 0xc) != 0) & 0xfffffffd) + 0xf004,0x804,0,
                         piVar1);
    if (iVar2 != 0) goto LAB_0046ef4a;
  }
  else {
LAB_0046ef4a:
    FUN_0047b918();
    FUN_0046b223();
    iVar2 = *extraout_ECX;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    iVar3 = (**(code **)(iVar2 + 0x80))(*(undefined4 *)(unaff_EBP + -0x14));
    if (iVar3 != 0) {
      if (*(int *)(unaff_EBP + 0xc) != 0) {
        (**(code **)(iVar2 + 0x5c))(*(undefined4 *)(unaff_EBP + -0x14),1);
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_0047b918();
      FUN_0046b238();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0046bec5((int *)(unaff_EBP + -0x14));
      uVar4 = 1;
      goto LAB_0046efe4;
    }
    if (*(int *)(unaff_EBP + 8) == 0) {
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_0046c881(*(LPCSTR *)(unaff_EBP + -0x14));
      uVar4 = func_0x0046ef8f();
      return uVar4;
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_0047b918();
    FUN_0046b238();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0046bec5((int *)(unaff_EBP + -0x14));
  uVar4 = 0;
LAB_0046efe4:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar4;
}

