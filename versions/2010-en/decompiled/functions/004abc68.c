
undefined4 FUN_004abc68(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  LPVOID pvVar4;
  HWND pHVar5;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  bool bVar6;
  
  FUN_0049bcd8();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffc0;
  *(int **)(unaff_EBP + -0x24) = extraout_ECX;
  if (*(int *)(unaff_EBP + 0x10) == 0) {
    iVar2 = FUN_004bfff8();
    *(undefined4 *)(unaff_EBP + 0x10) = *(undefined4 *)(iVar2 + 8);
  }
  iVar2 = FUN_004bfff8();
  piVar1 = *(int **)(iVar2 + 0x1038);
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(int **)(unaff_EBP + -0x28) = piVar1;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar2 = FUN_004bfff8();
  if ((*(byte *)(iVar2 + 0x18) & 0x10) == 0) {
    FUN_004af183(0x10);
  }
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*extraout_ECX + 0xbc))(unaff_EBP + -0x34);
    if (iVar2 == 0) goto LAB_004abce8;
    uVar3 = (**(code **)(*piVar1 + 0x10))(unaff_EBP + -0x34,*(undefined4 *)(unaff_EBP + 8));
    *(undefined4 *)(unaff_EBP + 8) = uVar3;
  }
  if (*(int *)(unaff_EBP + 8) == 0) {
LAB_004abce8:
    *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
    return 0;
  }
  FUN_004b045a((Tact2010CString *)(unaff_EBP + -0x1c));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  iVar2 = FUN_004b1903(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x1c,unaff_EBP + -0x18);
  bVar6 = iVar2 == 0;
  if (!bVar6) {
    iVar2 = GetSystemMetrics(0x2a);
    if (iVar2 != 0) {
      iVar2 = FUN_0049bd00(*(undefined4 *)(unaff_EBP + -0x1c),"MS Sans Serif");
      if (iVar2 != 0) {
        iVar2 = FUN_0049bd00(*(undefined4 *)(unaff_EBP + -0x1c),&DAT_004cd3bc);
        if (iVar2 != 0) {
          bVar6 = false;
          goto LAB_004abd6b;
        }
      }
      bVar6 = true;
      if (*(short *)(unaff_EBP + -0x18) == 8) {
        *(undefined4 *)(unaff_EBP + -0x18) = 0;
      }
    }
LAB_004abd6b:
    if (!bVar6) goto LAB_004abda0;
  }
  FUN_004b1753(*(undefined4 *)(unaff_EBP + 8));
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_004b1a89(*(undefined4 *)(unaff_EBP + -0x18));
  uVar3 = FUN_004b17f0();
  *(undefined4 *)(unaff_EBP + -0x14) = uVar3;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_004b17e2();
LAB_004abda0:
  if (*(int *)(unaff_EBP + -0x14) != 0) {
    pvVar4 = GlobalLock(*(HGLOBAL *)(unaff_EBP + -0x14));
    *(LPVOID *)(unaff_EBP + 8) = pvVar4;
  }
  extraout_ECX[0xb] = -1;
  extraout_ECX[9] = extraout_ECX[9] | 0x10;
  FUN_004accbd(extraout_ECX);
  if (*(int *)(unaff_EBP + 0xc) == 0) {
    pHVar5 = (HWND)0x0;
  }
  else {
    pHVar5 = *(HWND *)(*(int *)(unaff_EBP + 0xc) + 0x1c);
  }
  pHVar5 = CreateDialogIndirectParamA
                     (*(HINSTANCE *)(unaff_EBP + 0x10),*(LPCDLGTEMPLATEA *)(unaff_EBP + 8),pHVar5,
                      FUN_004abab0,0);
  *(HWND *)(unaff_EBP + -0x20) = pHVar5;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x1c));
  uVar3 = func_0x004abe0a();
  return uVar3;
}

