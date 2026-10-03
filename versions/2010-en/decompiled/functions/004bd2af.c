
void FUN_004bd2af(void)

{
  HFONT h;
  int iVar1;
  BOOL BVar2;
  int unaff_EBP;
  HGDIOBJ h_00;
  undefined4 *unaff_FS_OFFSET;
  bool bVar3;
  char *lpString2;
  
  FUN_0049bcd8();
  h_00 = (HGDIOBJ)0x0;
  if (DAT_005381f4 != 0) goto LAB_004bd3fd;
  FUN_004c088f(10);
  if (DAT_00538424 == (HBITMAP)0x0) {
    iVar1 = FUN_004bfff8();
    DAT_00538424 = LoadBitmapA(*(HINSTANCE *)(iVar1 + 0xc),(LPCSTR)0x7912);
    iVar1 = GetObjectA(DAT_00538424,0x18,(LPVOID)(unaff_EBP + -0x24));
    if (iVar1 != 0) {
      DAT_00538430 = *(undefined4 *)(unaff_EBP + -0x20);
      DAT_00538434 = *(int *)(unaff_EBP + -0x1c);
    }
  }
  if (DAT_00538420 == (HFONT)0x0) {
    _memset((void *)(unaff_EBP + -0x60),0,0x3c);
    *(undefined1 *)(unaff_EBP + -0x49) = 1;
    *(undefined4 *)(unaff_EBP + -0x50) = 400;
    *(int *)(unaff_EBP + -0x60) = 1 - DAT_00538434;
    iVar1 = GetSystemMetrics(0x2a);
    if (iVar1 == 0) {
      lpString2 = "Small Fonts";
    }
    else {
      lpString2 = "Terminal";
    }
    lstrcpyA((LPSTR)(unaff_EBP + -0x44),lpString2);
    iVar1 = FUN_004b5443(0xf233,unaff_EBP + -0x60);
    if (iVar1 == 0) {
      *(undefined1 *)(unaff_EBP + -0x45) = 0x20;
    }
    DAT_00538420 = CreateFontIndirectA((LOGFONTA *)(unaff_EBP + -0x60));
    if (DAT_00538420 != (HFONT)0x0) goto LAB_004bd390;
  }
  else {
LAB_004bd390:
    FUN_004b4e52(0);
    h = DAT_00538420;
    bVar3 = DAT_00538420 != (HFONT)0x0;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (bVar3) {
      h_00 = SelectObject(*(HDC *)(unaff_EBP + -0x1c),h);
    }
    BVar2 = GetTextMetricsA(*(HDC *)(unaff_EBP + -0x18),(LPTEXTMETRICA)(unaff_EBP + -0x5c));
    if (h_00 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(unaff_EBP + -0x1c),h_00);
    }
    if ((BVar2 == 0) || (DAT_00538434 < *(int *)(unaff_EBP + -0x5c) - *(int *)(unaff_EBP + -0x50)))
    {
      FUN_004b55fd(&DAT_00538420);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_004b4ec4();
  }
  FUN_004c08ff(10);
LAB_004bd3fd:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

