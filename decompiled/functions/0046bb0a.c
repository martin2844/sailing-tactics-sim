
/* Library Function - Single Match
    long __stdcall AfxInternalProcessWndProcException(class CException *,struct tagMSG const *)
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

long AfxInternalProcessWndProcException(CException *param_1,tagMSG *param_2)

{
  long lVar1;
  
  if (param_2->message == 1) {
    lVar1 = -1;
  }
  else {
    if (param_2->message == 0xf) {
      ValidateRect(param_2->hwnd,(RECT *)0x0);
    }
    lVar1 = 0;
  }
  return lVar1;
}

