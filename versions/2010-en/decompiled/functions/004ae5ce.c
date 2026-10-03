
undefined4 FUN_004ae5ce(void)

{
  HWND hWnd;
  int iVar1;
  HWND pHVar2;
  undefined4 uVar3;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  iVar1 = FUN_004ac73c(0);
  if (iVar1 != 0) {
    hWnd = *(HWND *)(unaff_EBP + 8);
    iVar1 = FUN_004ab70b(hWnd);
    if (iVar1 != 0) {
      uVar3 = FUN_004ae5a1(*(undefined4 *)(unaff_EBP + 0xc));
      goto LAB_004ae662;
    }
    pHVar2 = GetParent(hWnd);
    iVar1 = FUN_004ab70b(pHVar2);
    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x34) != 0)) {
      iVar1 = FUN_004ab70b(hWnd);
      if (iVar1 != 0) {
        FUN_004ac489(hWnd);
        *(undefined4 *)(unaff_EBP + -4) = 0;
        *(int *)(unaff_EBP + -0x10) = iVar1;
        uVar3 = FUN_004ae5a1(*(undefined4 *)(unaff_EBP + 0xc));
        *(undefined4 *)(unaff_EBP + -0x2c) = 0;
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        CWnd::~CWnd((CWnd *)(unaff_EBP + -0x48));
        goto LAB_004ae662;
      }
    }
  }
  uVar3 = 0;
LAB_004ae662:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar3;
}

