
int FUN_004abf46(void)

{
  int iVar1;
  HRSRC hResInfo;
  HGLOBAL hResData;
  LPVOID pvVar2;
  HWND hWnd;
  BOOL BVar3;
  undefined4 uVar4;
  uint uVar5;
  HWND pHVar6;
  int *extraout_ECX;
  HMODULE hModule;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffdc;
  *(int **)(unaff_EBP + -0x18) = extraout_ECX;
  hResData = (HGLOBAL)extraout_ECX[0x11];
  *(int *)(unaff_EBP + -0x14) = extraout_ECX[0x12];
  iVar1 = FUN_004bfff8();
  hModule = *(HMODULE *)(iVar1 + 0xc);
  if (extraout_ECX[0x10] != 0) {
    iVar1 = FUN_004bfff8();
    hModule = *(HMODULE *)(iVar1 + 0xc);
    hResInfo = FindResourceA(hModule,(LPCSTR)extraout_ECX[0x10],&DAT_00000005);
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
    hWnd = (HWND)FUN_004abed1();
    *(HWND *)(unaff_EBP + -0x20) = hWnd;
    FUN_004acd09();
    FUN_004ac7ac(hWnd);
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    if (hWnd != (HWND)0x0) {
      BVar3 = IsWindowEnabled(hWnd);
      if (BVar3 != 0) {
        EnableWindow(hWnd,0);
        *(undefined4 *)(unaff_EBP + -0x1c) = 1;
      }
    }
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_004accbd(extraout_ECX);
    uVar4 = FUN_004ac7ac(hWnd);
    iVar1 = FUN_004abc68(*(undefined4 *)(unaff_EBP + -0x14),uVar4,hModule);
    if (iVar1 != 0) {
      if ((*(byte *)(extraout_ECX + 9) & 0x10) != 0) {
        uVar4 = 4;
        uVar5 = FUN_004af3eb();
        if ((uVar5 & 0x100) != 0) {
          uVar4 = 5;
        }
        FUN_004aeff9(uVar4);
      }
      if (extraout_ECX[7] != 0) {
        FUN_004af4dd(0,0,0,0,0,0x97);
        iVar1 = FUN_004ac063();
        return iVar1;
      }
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    if (*(int *)(unaff_EBP + -0x1c) != 0) {
      EnableWindow(hWnd,1);
    }
    if (hWnd != (HWND)0x0) {
      pHVar6 = GetActiveWindow();
      if (pHVar6 == (HWND)extraout_ECX[7]) {
        SetActiveWindow(hWnd);
      }
    }
    (**(code **)(*extraout_ECX + 0x60))();
    FUN_004abf08();
    iVar1 = extraout_ECX[0xb];
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return iVar1;
}

