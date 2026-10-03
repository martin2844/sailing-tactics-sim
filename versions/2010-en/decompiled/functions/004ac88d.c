
undefined4 FUN_004ac88d(void)

{
  HWND hWnd;
  HANDLE pvVar1;
  undefined4 uVar2;
  LRESULT LVar3;
  int iVar4;
  undefined4 uVar5;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  bool bVar6;
  
  FUN_0049bcd8();
  hWnd = *(HWND *)(unaff_EBP + 8);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffc4;
  pvVar1 = GetPropA(hWnd,"AfxOldWndProc");
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(HANDLE *)(unaff_EBP + -0x18) = pvVar1;
  iVar4 = *(int *)(unaff_EBP + 0xc);
  bVar6 = true;
  if (iVar4 == 6) {
    uVar2 = FUN_004ac7ac(*(undefined4 *)(unaff_EBP + 0x14));
    uVar5 = FUN_004ac7ac(hWnd);
    FUN_004ac9da(uVar5,*(undefined4 *)(unaff_EBP + 0x10),uVar2);
  }
  else if (iVar4 == 0x20) {
    uVar2 = FUN_004ac7ac(hWnd);
    iVar4 = FUN_004aca3b(uVar2,(int)*(short *)(unaff_EBP + 0x14),*(uint *)(unaff_EBP + 0x14) >> 0x10
                        );
    bVar6 = iVar4 == 0;
  }
  else if (iVar4 == 0x82) {
    SetWindowLongA(hWnd,-4,*(LONG *)(unaff_EBP + -0x18));
    RemovePropA(hWnd,"AfxOldWndProc");
  }
  else if (iVar4 == 0x110) {
    uVar2 = FUN_004ac7ac(hWnd);
    FUN_004ac630(uVar2,unaff_EBP + -0x30,unaff_EBP + -0x1c);
    bVar6 = false;
    LVar3 = CallWindowProcA(*(WNDPROC *)(unaff_EBP + -0x18),hWnd,0x110,*(WPARAM *)(unaff_EBP + 0x10)
                            ,*(LPARAM *)(unaff_EBP + 0x14));
    *(LRESULT *)(unaff_EBP + -0x14) = LVar3;
    FUN_004ac653(uVar2,unaff_EBP + -0x30,*(undefined4 *)(unaff_EBP + -0x1c));
  }
  if (bVar6) {
    LVar3 = CallWindowProcA(*(WNDPROC *)(unaff_EBP + -0x18),hWnd,*(UINT *)(unaff_EBP + 0xc),
                            *(WPARAM *)(unaff_EBP + 0x10),*(LPARAM *)(unaff_EBP + 0x14));
    *(LRESULT *)(unaff_EBP + -0x14) = LVar3;
  }
  uVar2 = *(undefined4 *)(unaff_EBP + -0x14);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar2;
}

