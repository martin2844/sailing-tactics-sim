
undefined4 FUN_004afbd1(undefined4 param_1)

{
  undefined4 uVar1;
  AFX_MODULE_THREAD_STATE *pAVar2;
  
  pAVar2 = AfxGetModuleThreadState();
  uVar1 = *(undefined4 *)(pAVar2 + 0x28);
  *(undefined4 *)(pAVar2 + 0x28) = param_1;
  return uVar1;
}

