
/* Library Function - Single Match
    public: class CWnd * __thiscall CWnd::GetOwner(void)const 
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

CWnd * __thiscall CWnd::GetOwner(CWnd *this)

{
  CWnd *pCVar1;
  
  if (*(int *)(this + 0x20) == 0) {
    GetParent(*(HWND *)(this + 0x1c));
  }
  pCVar1 = FUN_004680cc();
  return pCVar1;
}

