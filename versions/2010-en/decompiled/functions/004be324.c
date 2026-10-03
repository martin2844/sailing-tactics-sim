
void FUN_004be324(void)

{
  int iVar1;
  LPSTR lpString1;
  int extraout_ECX;
  int unaff_EBP;
  bool bVar2;
  
  FUN_0049bcd8();
  bVar2 = DAT_005381f4 != 0;
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffec;
  if (bVar2) {
    FUN_004ac701();
    func_0x004be39a();
    return;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(int *)(unaff_EBP + 0xc) == 0) {
    FUN_004b0530();
  }
  else {
    iVar1 = lstrlenA(*(LPCSTR *)(unaff_EBP + 0xc));
    lpString1 = (LPSTR)FUN_004b09cd(iVar1);
    lstrcpyA(lpString1,*(LPCSTR *)(unaff_EBP + 0xc));
  }
  SendMessageA(*(HWND *)(extraout_ECX + 0x1c),0x85,0,0);
  func_0x004be39a();
  return;
}

