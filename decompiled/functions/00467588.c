
undefined4 FUN_00467588(void)

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
  
  FUN_00457418();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffc0;
  *(int **)(unaff_EBP + -0x24) = extraout_ECX;
  if (*(int *)(unaff_EBP + 0x10) == 0) {
    iVar2 = FUN_0047b918();
    *(undefined4 *)(unaff_EBP + 0x10) = *(undefined4 *)(iVar2 + 8);
  }
  iVar2 = FUN_0047b918();
  piVar1 = *(int **)(iVar2 + 0x1038);
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(int **)(unaff_EBP + -0x28) = piVar1;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar2 = FUN_0047b918();
  if ((*(byte *)(iVar2 + 0x18) & 0x10) == 0) {
    FUN_0046aaa3(0x10);
  }
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*extraout_ECX + 0xbc))(unaff_EBP + -0x34);
    if (iVar2 == 0) goto LAB_00467608;
    uVar3 = (**(code **)(*piVar1 + 0x10))(unaff_EBP + -0x34,*(undefined4 *)(unaff_EBP + 8));
    *(undefined4 *)(unaff_EBP + 8) = uVar3;
  }
  if (*(int *)(unaff_EBP + 8) == 0) {
LAB_00467608:
    *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
    return 0;
  }
  FUN_0046bd7a((undefined4 *)(unaff_EBP + -0x1c));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  iVar2 = FUN_0046d223(*(uint **)(unaff_EBP + 8),(void *)(unaff_EBP + -0x1c),
                       (undefined2 *)(unaff_EBP + -0x18));
  bVar6 = iVar2 == 0;
  if (!bVar6) {
    iVar2 = GetSystemMetrics(0x2a);
    if (iVar2 != 0) {
      iVar2 = FUN_00457440(*(byte **)(unaff_EBP + -0x1c),(byte *)"MS Sans Serif");
      if (iVar2 != 0) {
        iVar2 = FUN_00457440(*(byte **)(unaff_EBP + -0x1c),&DAT_0048571c);
        if (iVar2 != 0) {
          bVar6 = false;
          goto LAB_0046768b;
        }
      }
      bVar6 = true;
      if (*(short *)(unaff_EBP + -0x18) == 8) {
        *(undefined4 *)(unaff_EBP + -0x18) = 0;
      }
    }
LAB_0046768b:
    if (!bVar6) goto LAB_004676c0;
  }
  FUN_0046d073((void *)(unaff_EBP + -0x40),*(uint **)(unaff_EBP + 8));
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_0046d3a9((short)*(undefined4 *)(unaff_EBP + -0x18));
  uVar3 = FUN_0046d110((undefined4 *)(unaff_EBP + -0x40));
  *(undefined4 *)(unaff_EBP + -0x14) = uVar3;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0046d102((undefined4 *)(unaff_EBP + -0x40));
LAB_004676c0:
  if (*(int *)(unaff_EBP + -0x14) != 0) {
    pvVar4 = GlobalLock(*(HGLOBAL *)(unaff_EBP + -0x14));
    *(LPVOID *)(unaff_EBP + 8) = pvVar4;
  }
  extraout_ECX[0xb] = -1;
  extraout_ECX[9] = extraout_ECX[9] | 0x10;
  FUN_004685dd((int)extraout_ECX);
  if (*(int *)(unaff_EBP + 0xc) == 0) {
    pHVar5 = (HWND)0x0;
  }
  else {
    pHVar5 = *(HWND *)(*(int *)(unaff_EBP + 0xc) + 0x1c);
  }
  pHVar5 = CreateDialogIndirectParamA
                     (*(HINSTANCE *)(unaff_EBP + 0x10),*(LPCDLGTEMPLATEA *)(unaff_EBP + 8),pHVar5,
                      FUN_004673d0,0);
  *(HWND *)(unaff_EBP + -0x20) = pHVar5;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0046bec5((int *)(unaff_EBP + -0x1c));
  uVar3 = func_0x0046772a();
  return uVar3;
}

