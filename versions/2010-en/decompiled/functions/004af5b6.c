
/* Library Function - Single Match
    protected: void __thiscall CWnd::AttachControlSite(class CHandleMap *)
   
   Library: Visual Studio 1998 Release */

void __thiscall CWnd::AttachControlSite(CWnd *this,CHandleMap *param_1)

{
  HWND pHVar1;
  int iVar2;
  
  if ((this != (CWnd *)0x0) && (*(int *)(this + 0x38) == 0)) {
    pHVar1 = GetParent(*(HWND *)(this + 0x1c));
    iVar2 = FUN_004ab70b(pHVar1);
    if (iVar2 != 0) {
      FUN_004af5e6(iVar2);
    }
  }
  return;
}

