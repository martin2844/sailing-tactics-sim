
undefined4 FUN_00468cf6(void)

{
  WNDCLASSA *lpWndClass;
  ATOM AVar1;
  BOOL BVar2;
  undefined4 uVar3;
  int iVar4;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  lpWndClass = *(WNDCLASSA **)(unaff_EBP + 8);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffc4;
  BVar2 = GetClassInfoA(lpWndClass->hInstance,lpWndClass->lpszClassName,
                        (LPWNDCLASSA)(unaff_EBP + -0x38));
  if (BVar2 == 0) {
    AVar1 = RegisterClassA(lpWndClass);
    if (AVar1 == 0) {
      uVar3 = 0;
      goto LAB_00468d78;
    }
    iVar4 = FUN_0047b918();
    if (*(char *)(iVar4 + 0x14) != '\0') {
      FUN_0047c1af(1);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      iVar4 = FUN_0047b918();
      lstrcatA((LPSTR)(iVar4 + 0x34),lpWndClass->lpszClassName);
      *(undefined1 *)(unaff_EBP + 9) = 0;
      *(undefined1 *)(unaff_EBP + 8) = 10;
      lstrcatA((LPSTR)(iVar4 + 0x34),(LPCSTR)(unaff_EBP + 8));
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0047c21f(1);
    }
  }
  uVar3 = 1;
LAB_00468d78:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar3;
}

