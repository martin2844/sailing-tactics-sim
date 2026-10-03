
undefined4 FUN_00479c44(void)

{
  undefined4 uVar1;
  int iVar2;
  LPSTR lpString1;
  void *this;
  int unaff_EBP;
  bool bVar3;
  
  FUN_00457418();
  bVar3 = DAT_004ae69c != 0;
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffec;
  if (bVar3) {
    FUN_00468021(this);
    uVar1 = func_0x00479cba();
    return uVar1;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(int *)(unaff_EBP + 0xc) == 0) {
    FUN_0046be50((int *)((int)this + 200));
  }
  else {
    iVar2 = lstrlenA(*(LPCSTR *)(unaff_EBP + 0xc));
    lpString1 = (LPSTR)FUN_0046c2ed((void *)((int)this + 200),iVar2);
    lstrcpyA(lpString1,*(LPCSTR *)(unaff_EBP + 0xc));
  }
  SendMessageA(*(HWND *)((int)this + 0x1c),0x85,0,0);
  uVar1 = func_0x00479cba();
  return uVar1;
}

