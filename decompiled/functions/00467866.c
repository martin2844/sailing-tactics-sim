
int FUN_00467866(void)

{
  HMODULE hModule;
  int iVar1;
  HRSRC hResInfo;
  HGLOBAL hResData;
  LPVOID pvVar2;
  HWND hWnd;
  BOOL BVar3;
  uint uVar4;
  HWND pHVar5;
  int *this;
  byte bVar6;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffdc;
  *(int **)(unaff_EBP + -0x18) = this;
  hResData = (HGLOBAL)this[0x11];
  *(int *)(unaff_EBP + -0x14) = this[0x12];
  FUN_0047b918();
  if (this[0x10] != 0) {
    iVar1 = FUN_0047b918();
    hModule = *(HMODULE *)(iVar1 + 0xc);
    hResInfo = FindResourceA(hModule,(LPCSTR)this[0x10],&DAT_00000005);
    hResData = LoadResource(hModule,hResInfo);
  }
  if (hResData != (HGLOBAL)0x0) {
    pvVar2 = LockResource(hResData);
    *(LPVOID *)(unaff_EBP + -0x14) = pvVar2;
  }
  if (*(int *)(unaff_EBP + -0x14) == 0) {
    iVar1 = -1;
  }
  else {
    hWnd = (HWND)FUN_004677f1((int)this);
    *(HWND *)(unaff_EBP + -0x20) = hWnd;
    FUN_00468629();
    FUN_004680cc();
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    if (hWnd != (HWND)0x0) {
      BVar3 = IsWindowEnabled(hWnd);
      if (BVar3 != 0) {
        EnableWindow(hWnd,0);
        *(undefined4 *)(unaff_EBP + -0x1c) = 1;
      }
    }
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_004685dd((int)this);
    FUN_004680cc();
    iVar1 = FUN_00467588();
    if (iVar1 != 0) {
      if ((*(byte *)(this + 9) & 0x10) != 0) {
        bVar6 = 4;
        uVar4 = FUN_0046ad0b((int)this);
        if ((uVar4 & 0x100) != 0) {
          bVar6 = 5;
        }
        FUN_0046a919(this,bVar6);
      }
      if (this[7] != 0) {
        FUN_0046adfd(this,0,0,0,0,0,0x97);
        iVar1 = FUN_00467983();
        return iVar1;
      }
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    if (*(int *)(unaff_EBP + -0x1c) != 0) {
      EnableWindow(hWnd,1);
    }
    if (hWnd != (HWND)0x0) {
      pHVar5 = GetActiveWindow();
      if (pHVar5 == (HWND)this[7]) {
        SetActiveWindow(hWnd);
      }
    }
    (**(code **)(*this + 0x60))();
    FUN_00467828((int)this);
    iVar1 = this[0xb];
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return iVar1;
}

