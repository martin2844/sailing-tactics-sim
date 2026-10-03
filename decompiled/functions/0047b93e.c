
/* Library Function - Single Match
    class AFX_MODULE_THREAD_STATE * __stdcall AfxGetModuleThreadState(void)
   
   Library: Visual Studio 2003 Release */

AFX_MODULE_THREAD_STATE * AfxGetModuleThreadState(void)

{
  int iVar1;
  AFX_MODULE_THREAD_STATE *pAVar2;
  
  iVar1 = FUN_0047b918();
  pAVar2 = (AFX_MODULE_THREAD_STATE *)FUN_0047be12((void *)(iVar1 + 0x1070),FUN_00455cc2);
  return pAVar2;
}

