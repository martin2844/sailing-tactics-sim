
undefined4 FUN_004681ad(void)

{
  HWND hWnd;
  undefined4 uVar1;
  HANDLE pvVar2;
  CWnd *pCVar3;
  LRESULT LVar4;
  int iVar5;
  CWnd *pCVar6;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  bool bVar7;
  
  FUN_00457418();
  hWnd = *(HWND *)(unaff_EBP + 8);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffc4;
  pvVar2 = GetPropA(hWnd,"AfxOldWndProc");
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(HANDLE *)(unaff_EBP + -0x18) = pvVar2;
  iVar5 = *(int *)(unaff_EBP + 0xc);
  bVar7 = true;
  if (iVar5 == 6) {
    pCVar3 = FUN_004680cc();
    pCVar6 = FUN_004680cc();
    FUN_004682fa((int)pCVar6,*(WPARAM *)(unaff_EBP + 0x10),(int)pCVar3);
  }
  else if (iVar5 == 0x20) {
    pCVar3 = FUN_004680cc();
    iVar5 = FUN_0046835b((int)pCVar3,(int)*(short *)(unaff_EBP + 0x14),
                         *(uint *)(unaff_EBP + 0x14) >> 0x10);
    bVar7 = iVar5 == 0;
  }
  else if (iVar5 == 0x82) {
    SetWindowLongA(hWnd,-4,*(LONG *)(unaff_EBP + -0x18));
    RemovePropA(hWnd,"AfxOldWndProc");
  }
  else if (iVar5 == 0x110) {
    pCVar3 = FUN_004680cc();
    FUN_00467f50((int)pCVar3,(LPRECT)(unaff_EBP + -0x30),(undefined4 *)(unaff_EBP + -0x1c));
    bVar7 = false;
    LVar4 = CallWindowProcA(*(WNDPROC *)(unaff_EBP + -0x18),hWnd,0x110,*(WPARAM *)(unaff_EBP + 0x10)
                            ,*(LPARAM *)(unaff_EBP + 0x14));
    *(LRESULT *)(unaff_EBP + -0x14) = LVar4;
    FUN_00467f73((int *)pCVar3,(int *)(unaff_EBP + -0x30),*(uint *)(unaff_EBP + -0x1c));
  }
  if (bVar7) {
    LVar4 = CallWindowProcA(*(WNDPROC *)(unaff_EBP + -0x18),hWnd,*(UINT *)(unaff_EBP + 0xc),
                            *(WPARAM *)(unaff_EBP + 0x10),*(LPARAM *)(unaff_EBP + 0x14));
    *(LRESULT *)(unaff_EBP + -0x14) = LVar4;
  }
  uVar1 = *(undefined4 *)(unaff_EBP + -0x14);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar1;
}

