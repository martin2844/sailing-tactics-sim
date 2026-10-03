
undefined4 __thiscall FUN_00478de7(void *this)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  CWnd *pCVar4;
  CWnd *pCVar5;
  LRESULT LVar6;
  
  iVar2 = FUN_00468021(this);
  if (iVar2 == 0) {
    return 0;
  }
  uVar3 = FUN_0046ad0b((int)this);
  if ((uVar3 & 0x100) == 0) {
    return 1;
  }
  pCVar4 = (CWnd *)FUN_0046972b((int)this);
  GetForegroundWindow();
  pCVar5 = FUN_004680cc();
  if (pCVar4 != pCVar5) {
    GetLastActivePopup(*(HWND *)(pCVar4 + 0x1c));
    pCVar4 = FUN_004680cc();
    if ((pCVar4 != pCVar5) ||
       (LVar6 = SendMessageA(*(HWND *)(pCVar5 + 0x1c),0x36d,0x40,0), LVar6 == 0)) {
      bVar1 = 0;
      goto LAB_00478e55;
    }
  }
  bVar1 = 1;
LAB_00478e55:
  SendMessageA(*(HWND *)((int)this + 0x1c),0x36d,(-(uint)bVar1 & 0xfffffffc) + 8,0);
  return 1;
}

