
undefined4 FUN_004b354b(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe8;
  FUN_004b0613((Tact2010CString *)(unaff_EBP + -0x14),*(char **)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(int *)(*(int *)(unaff_EBP + -0x14) + -8) == 0) {
    piVar1 = (int *)extraout_ECX[9];
    FUN_004b069e((Tact2010CString *)(unaff_EBP + -0x14),(Tact2010CString *)(extraout_ECX + 8));
    if ((*(int *)(unaff_EBP + 0xc) != 0) && (*(int *)(*(int *)(unaff_EBP + -0x14) + -8) == 0)) {
      FUN_004b069e((Tact2010CString *)(unaff_EBP + -0x14),(Tact2010CString *)(extraout_ECX + 7));
      iVar2 = FUN_004b0a0e(" #%;/\\");
      if (iVar2 != -1) {
        FUN_004b09a5(iVar2);
      }
      FUN_004b045a((Tact2010CString *)(unaff_EBP + -0x18));
      iVar2 = *piVar1;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      iVar2 = (**(code **)(iVar2 + 0x6c))(unaff_EBP + -0x18,4);
      if ((iVar2 != 0) && (*(int *)(*(int *)(unaff_EBP + -0x18) + -8) != 0)) {
        FUN_004b093e(unaff_EBP + -0x18);
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x18));
    }
    FUN_004bfff8();
    iVar2 = FUN_004b6b31(unaff_EBP + -0x14,
                         (-(uint)(*(int *)(unaff_EBP + 0xc) != 0) & 0xfffffffd) + 0xf004,0x804,0,
                         piVar1);
    if (iVar2 != 0) goto LAB_004b362a;
  }
  else {
LAB_004b362a:
    FUN_004bfff8();
    FUN_004af903();
    iVar2 = *extraout_ECX;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    iVar3 = (**(code **)(iVar2 + 0x80))(*(undefined4 *)(unaff_EBP + -0x14));
    if (iVar3 != 0) {
      if (*(int *)(unaff_EBP + 0xc) != 0) {
        (**(code **)(iVar2 + 0x5c))(*(undefined4 *)(unaff_EBP + -0x14),1);
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_004bfff8();
      FUN_004af918();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x14));
      uVar4 = 1;
      goto LAB_004b36c4;
    }
    if (*(int *)(unaff_EBP + 8) == 0) {
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_004b0f61(*(undefined4 *)(unaff_EBP + -0x14));
      uVar4 = func_0x004b366f();
      return uVar4;
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_004bfff8();
    FUN_004af918();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x14));
  uVar4 = 0;
LAB_004b36c4:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar4;
}

