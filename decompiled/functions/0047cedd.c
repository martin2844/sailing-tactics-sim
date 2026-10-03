
/* Library Function - Single Match
    void __stdcall AfxPostQuitMessage(int)
   
   Library: Visual Studio 1998 Release */

void AfxPostQuitMessage(int param_1)

{
  CWinThread *pCVar1;
  
  pCVar1 = AfxGetThread();
  if ((pCVar1 != (CWinThread *)0x0) && (*(code **)(pCVar1 + 0x54) != (code *)0x0)) {
    (**(code **)(pCVar1 + 0x54))(1,1);
  }
  PostQuitMessage(param_1);
  return;
}

