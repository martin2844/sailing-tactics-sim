
void FUN_004b678d(void)

{
  int iVar1;
  undefined4 *puVar2;
  HGDIOBJ pvVar3;
  int iVar4;
  int *extraout_ECX;
  int iVar5;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  FUN_004b4e52(0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  pvVar3 = (HGDIOBJ)SendMessageA((HWND)extraout_ECX[7],0x31,0,0);
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if (pvVar3 != (HGDIOBJ)0x0) {
    pvVar3 = SelectObject(*(HDC *)(unaff_EBP + -0x3c),pvVar3);
    *(HGDIOBJ *)(unaff_EBP + -0x10) = pvVar3;
  }
  GetTextMetricsA(*(HDC *)(unaff_EBP + -0x38),(LPTEXTMETRICA)(unaff_EBP + -0x78));
  if (*(int *)(unaff_EBP + -0x10) != 0) {
    SelectObject(*(HDC *)(unaff_EBP + -0x3c),*(HGDIOBJ *)(unaff_EBP + -0x10));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004b4ec4();
  SetRectEmpty((LPRECT)(unaff_EBP + -0x2c));
  FUN_004beb71(unaff_EBP + -0x2c,*(undefined4 *)(unaff_EBP + 0x10));
  (**(code **)(*extraout_ECX + 0xa8))(0x407,0,unaff_EBP + -0x1c);
  iVar5 = *(int *)(unaff_EBP + -0x20);
  iVar1 = *(int *)(unaff_EBP + -0x28);
  iVar4 = GetSystemMetrics(6);
  iVar5 = (((iVar4 + *(int *)(unaff_EBP + -0x18)) * 2 - (iVar5 - iVar1)) -
          *(int *)(unaff_EBP + -0x6c)) + -1 + *(int *)(unaff_EBP + -0x78);
  if (iVar5 < extraout_ECX[0x1e]) {
    iVar5 = extraout_ECX[0x1e];
  }
  puVar2 = *(undefined4 **)(unaff_EBP + 8);
  *puVar2 = 0x7fff;
  puVar2[1] = iVar5;
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

