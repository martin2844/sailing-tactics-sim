
undefined4 FUN_004b4461(int param_1,int param_2)

{
  HWND pHVar1;
  undefined4 uVar2;
  int iVar3;
  BOOL BVar4;
  
  pHVar1 = GetParent(*(HWND *)(param_1 + 0x1c));
  uVar2 = FUN_004ac7ac(pHVar1);
  iVar3 = FUN_004b1618(&PTR_s_CSplitterWnd_004ce870);
  if (iVar3 != 0) {
    if (param_2 != 0) {
      return uVar2;
    }
    do {
      pHVar1 = GetParent(*(HWND *)(param_1 + 0x1c));
      param_1 = FUN_004ac7ac(pHVar1);
      if (param_1 == 0) {
        return uVar2;
      }
      BVar4 = IsIconic(*(HWND *)(param_1 + 0x1c));
    } while (BVar4 == 0);
  }
  return 0;
}

