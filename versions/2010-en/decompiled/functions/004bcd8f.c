
/* Library Function - Single Match
    protected: void __thiscall CFrameWnd::BringToTop(int)
   
   Libraries: Visual Studio 1998 Release, Visual Studio 2003 Release */

void __thiscall CFrameWnd::BringToTop(CFrameWnd *this,int param_1)

{
  HWND hWnd;
  
  if ((((param_1 != 0) && (param_1 != 6)) && (param_1 != 7)) && ((param_1 != 8 && (param_1 != 4))))
  {
    hWnd = GetLastActivePopup(*(HWND *)(this + 0x1c));
    BringWindowToTop(hWnd);
  }
  return;
}

