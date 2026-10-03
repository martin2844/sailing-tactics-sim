
/* Library Function - Single Match
    class AFX_MODULE_THREAD_STATE * __stdcall AfxGetModuleThreadState(void)
   
   Library: Visual Studio 2003 Release */

AFX_MODULE_THREAD_STATE * AfxGetModuleThreadState(void)

{
  AFX_MODULE_THREAD_STATE *pAVar1;
  
  FUN_004bfff8();
  pAVar1 = (AFX_MODULE_THREAD_STATE *)FUN_004c04f2(FUN_0049a3b2);
  return pAVar1;
}

