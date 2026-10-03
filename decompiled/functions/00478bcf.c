
void FUN_00478bcf(void)

{
  HFONT h;
  int iVar1;
  BOOL BVar2;
  int unaff_EBP;
  HGDIOBJ h_00;
  undefined4 *unaff_FS_OFFSET;
  bool bVar3;
  char *lpString2;
  
  FUN_00457418();
  h_00 = (HGDIOBJ)0x0;
  if (DAT_004ae69c != 0) goto LAB_00478d1d;
  FUN_0047c1af(10);
  if (DAT_004ae8cc == (HBITMAP)0x0) {
    iVar1 = FUN_0047b918();
    DAT_004ae8cc = LoadBitmapA(*(HINSTANCE *)(iVar1 + 0xc),(LPCSTR)0x7912);
    iVar1 = GetObjectA(DAT_004ae8cc,0x18,(LPVOID)(unaff_EBP + -0x24));
    if (iVar1 != 0) {
      DAT_004ae8d8 = *(undefined4 *)(unaff_EBP + -0x20);
      DAT_004ae8dc = *(int *)(unaff_EBP + -0x1c);
    }
  }
  if (DAT_004ae8c8 == (HFONT)0x0) {
    _memset((void *)(unaff_EBP + -0x60),0,0x3c);
    *(undefined1 *)(unaff_EBP + -0x49) = 1;
    *(undefined4 *)(unaff_EBP + -0x50) = 400;
    *(int *)(unaff_EBP + -0x60) = 1 - DAT_004ae8dc;
    iVar1 = GetSystemMetrics(0x2a);
    if (iVar1 == 0) {
      lpString2 = "Small Fonts";
    }
    else {
      lpString2 = "Terminal";
    }
    lstrcpyA((LPSTR)(unaff_EBP + -0x44),lpString2);
    iVar1 = FUN_00470d63(0xf233,(int *)(unaff_EBP + -0x60));
    if (iVar1 == 0) {
      *(undefined1 *)(unaff_EBP + -0x45) = 0x20;
    }
    DAT_004ae8c8 = CreateFontIndirectA((LOGFONTA *)(unaff_EBP + -0x60));
    if (DAT_004ae8c8 != (HFONT)0x0) goto LAB_00478cb0;
  }
  else {
LAB_00478cb0:
    FUN_00470772();
    h = DAT_004ae8c8;
    bVar3 = DAT_004ae8c8 != (HFONT)0x0;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (bVar3) {
      h_00 = SelectObject(*(HDC *)(unaff_EBP + -0x1c),h);
    }
    BVar2 = GetTextMetricsA(*(HDC *)(unaff_EBP + -0x18),(LPTEXTMETRICA)(unaff_EBP + -0x5c));
    if (h_00 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(unaff_EBP + -0x1c),h_00);
    }
    if ((BVar2 == 0) || (DAT_004ae8dc < *(int *)(unaff_EBP + -0x5c) - *(int *)(unaff_EBP + -0x50)))
    {
      FUN_00470f1d(&DAT_004ae8c8);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_004707e4();
  }
  FUN_0047c21f(10);
LAB_00478d1d:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

