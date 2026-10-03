
/* Library Function - Single Match
    struct HWND__ * __stdcall AfxGetParentOwner(struct HWND__ *)
   
   Library: Visual Studio 2003 Release */

HWND__ * AfxGetParentOwner(HWND__ *param_1)

{
  CWnd *pCVar1;
  uint uVar2;
  HWND__ *pHVar3;
  
  pCVar1 = (CWnd *)FUN_004680f4((uint)param_1);
  if (pCVar1 == (CWnd *)0x0) {
    uVar2 = GetWindowLongA(param_1,-0x10);
    if ((uVar2 & 0x40000000) == 0) {
      pHVar3 = GetWindow(param_1,4);
    }
    else {
      pHVar3 = GetParent(param_1);
    }
  }
  else {
    pCVar1 = CWnd::GetOwner(pCVar1);
    pHVar3 = (HWND__ *)0x0;
    if (pCVar1 != (CWnd *)0x0) {
      pHVar3 = *(HWND__ **)(pCVar1 + 0x1c);
    }
  }
  return pHVar3;
}

