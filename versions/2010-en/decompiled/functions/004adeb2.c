
/* Library Function - Single Match
    public: void __thiscall CWnd::ActivateTopParent(void)
   
   Library: Visual Studio 2003 Release */

void __thiscall CWnd::ActivateTopParent(CWnd *this)

{
  int iVar1;
  HWND pHVar2;
  int iVar3;
  BOOL BVar4;
  
  iVar1 = FUN_004ade0b();
  pHVar2 = GetForegroundWindow();
  iVar3 = FUN_004ac7ac(pHVar2);
  if (iVar3 != 0) {
    if (*(HWND *)(iVar3 + 0x1c) == *(HWND *)(this + 0x1c)) {
      return;
    }
    BVar4 = IsChild(*(HWND *)(iVar3 + 0x1c),*(HWND *)(this + 0x1c));
    if (BVar4 != 0) {
      return;
    }
  }
  SetForegroundWindow(*(HWND *)(iVar1 + 0x1c));
  return;
}

