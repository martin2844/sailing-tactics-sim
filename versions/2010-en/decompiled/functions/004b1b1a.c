
void FUN_004b1b1a(void)

{
  AFX_MODULE_THREAD_STATE *pAVar1;
  
  pAVar1 = AfxGetModuleThreadState();
  *(int *)(pAVar1 + 0x10) = *(int *)(pAVar1 + 0x10) + 1;
  return;
}

