
void FUN_004ad56f(void)

{
  int iVar1;
  int iVar2;
  HWND hWnd;
  BOOL BVar3;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  iVar1 = FUN_004bfff8();
  *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(iVar1 + 4);
  FUN_004bfff8();
  FUN_004af903();
  iVar1 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar2 = (**(code **)(iVar1 + 0xb8))();
  if (iVar2 != 0) {
    (**(code **)(iVar1 + 0xf8))();
  }
  SendMessageA((HWND)extraout_ECX[7],0x1f,0,0);
  FUN_004ae04c(extraout_ECX[7],0x1f,0,0,1,1);
  iVar1 = FUN_004ade0b();
  SendMessageA(*(HWND *)(iVar1 + 0x1c),0x1f,0,0);
  FUN_004ae04c(*(undefined4 *)(iVar1 + 0x1c),0x1f,0,0,1,1);
  hWnd = GetCapture();
  if (hWnd != (HWND)0x0) {
    SendMessageA(hWnd,0x1f,0,0);
  }
  BVar3 = WinHelpA(*(HWND *)(iVar1 + 0x1c),*(LPCSTR *)(*(int *)(unaff_EBP + -0x10) + 0x8c),
                   *(UINT *)(unaff_EBP + 0xc),*(ULONG_PTR *)(unaff_EBP + 8));
  if (BVar3 == 0) {
    FUN_004b6cec(0xf107,0,0xffffffff);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004bfff8();
  FUN_004af918();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

