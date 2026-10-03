
/* Library Function - Single Match
    public: void __thiscall CWnd::ActivateTopParent(void)
   
   Library: Visual Studio 2003 Release */

void __thiscall CWnd::ActivateTopParent(CWnd *this)

{
  int iVar1;
  CWnd *pCVar2;
  BOOL BVar3;
  
  iVar1 = FUN_0046972b((int)this);
  GetForegroundWindow();
  pCVar2 = FUN_004680cc();
  if (pCVar2 != (CWnd *)0x0) {
    if (*(HWND *)(pCVar2 + 0x1c) == *(HWND *)(this + 0x1c)) {
      return;
    }
    BVar3 = IsChild(*(HWND *)(pCVar2 + 0x1c),*(HWND *)(this + 0x1c));
    if (BVar3 != 0) {
      return;
    }
  }
  SetForegroundWindow(*(HWND *)(iVar1 + 0x1c));
  return;
}

