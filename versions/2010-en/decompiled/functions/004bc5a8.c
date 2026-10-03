
undefined4 FUN_004bc5a8(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  HWND hWnd;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  iVar2 = FUN_004af996();
  if (iVar2 == 0) {
    FUN_004b045a((Tact2010CString *)(unaff_EBP + -0x10));
    puVar1 = *(undefined4 **)(unaff_EBP + 0xc);
    iVar2 = puVar1[2];
    hWnd = (HWND)puVar1[1];
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (((iVar2 == -0x208) && ((*(byte *)(puVar1 + 0x19) & 1) != 0)) ||
       ((iVar2 == -0x212 && ((*(byte *)(puVar1 + 0x2d) & 1) != 0)))) {
      uVar4 = GetDlgCtrlID(hWnd);
      hWnd = (HWND)(uVar4 & 0xffff);
    }
    if (hWnd != (HWND)0x0) {
      FUN_004b1fc5(hWnd,unaff_EBP + -0x110,0x100);
      FUN_004b1fec(unaff_EBP + -0x10,unaff_EBP + -0x110,1,10);
    }
    if (puVar1[2] == -0x208) {
      lstrcpynA((LPSTR)(puVar1 + 4),*(LPCSTR *)(unaff_EBP + -0x10),0x50);
    }
    else {
      FUN_004b0a2d();
    }
    **(undefined4 **)(unaff_EBP + 0x10) = 0;
    SetWindowPos((HWND)*puVar1,(HWND)0x0,0,0,0,0,0x213);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x10));
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar3;
}

