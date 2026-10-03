
undefined4 FUN_00477ec8(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  HWND hWnd;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  iVar2 = FUN_0046b2b6();
  if (iVar2 == 0) {
    FUN_0046bd7a((undefined4 *)(unaff_EBP + -0x10));
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
      FUN_0046d8e5((UINT)hWnd,(LPSTR)(unaff_EBP + -0x110),0x100);
      FUN_0046d90c((int *)(unaff_EBP + -0x10),(byte *)(unaff_EBP + -0x110),1,'\n');
    }
    if (puVar1[2] == -0x208) {
      lstrcpynA((LPSTR)(puVar1 + 4),*(LPCSTR *)(unaff_EBP + -0x10),0x50);
    }
    else {
      FUN_0046c34d((LPWSTR)(puVar1 + 4),*(LPCSTR *)(unaff_EBP + -0x10),0x50);
    }
    **(undefined4 **)(unaff_EBP + 0x10) = 0;
    SetWindowPos((HWND)*puVar1,(HWND)0x0,0,0,0,0,0x213);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0046bec5((int *)(unaff_EBP + -0x10));
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar3;
}

