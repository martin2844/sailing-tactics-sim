
void __thiscall FUN_0046b2e8(void *this,int param_1)

{
  HWND pHVar1;
  CWnd *pCVar2;
  HWND pHVar3;
  
  if (*(int *)((int)this + 0xc) == 0) {
    if (param_1 == 0) {
      pHVar3 = *(HWND *)(*(int *)((int)this + 0x14) + 0x1c);
      pHVar1 = GetFocus();
      if (pHVar1 == pHVar3) {
        GetParent(pHVar3);
        pCVar2 = FUN_004680cc();
        pHVar3 = (HWND)0x0;
        if (*(int *)((int)this + 0x14) != 0) {
          pHVar3 = *(HWND *)(*(int *)((int)this + 0x14) + 0x1c);
        }
        GetNextDlgTabItem(*(HWND *)(pCVar2 + 0x1c),pHVar3,0);
        pCVar2 = FUN_004680cc();
        FUN_0046aeb5((int)pCVar2);
      }
    }
    FUN_0046ae8e(*(void **)((int)this + 0x14),param_1);
  }
  else {
    if (*(int *)((int)this + 0x10) != 0) {
      return;
    }
    EnableMenuItem(*(HMENU *)(*(int *)((int)this + 0xc) + 4),*(UINT *)((int)this + 8),
                   (-(uint)(param_1 != 0) & 0xfffffffd) + 3 | 0x400);
  }
  *(undefined4 *)((int)this + 0x18) = 1;
  return;
}

