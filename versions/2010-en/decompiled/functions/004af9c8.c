
void __thiscall FUN_004af9c8(int param_1,int param_2)

{
  HWND pHVar1;
  HWND pHVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    if (param_2 == 0) {
      pHVar2 = *(HWND *)(*(int *)(param_1 + 0x14) + 0x1c);
      pHVar1 = GetFocus();
      if (pHVar1 == pHVar2) {
        pHVar2 = GetParent(pHVar2);
        iVar3 = FUN_004ac7ac(pHVar2);
        pHVar2 = (HWND)0x0;
        if (*(int *)(param_1 + 0x14) != 0) {
          pHVar2 = *(HWND *)(*(int *)(param_1 + 0x14) + 0x1c);
        }
        pHVar2 = GetNextDlgTabItem(*(HWND *)(iVar3 + 0x1c),pHVar2,0);
        FUN_004ac7ac(pHVar2);
        FUN_004af595();
      }
    }
    FUN_004af56e(param_2);
  }
  else {
    if (*(int *)(param_1 + 0x10) != 0) {
      return;
    }
    EnableMenuItem(*(HMENU *)(*(int *)(param_1 + 0xc) + 4),*(UINT *)(param_1 + 8),
                   (-(uint)(param_2 != 0) & 0xfffffffd) + 3 | 0x400);
  }
  *(undefined4 *)(param_1 + 0x18) = 1;
  return;
}

