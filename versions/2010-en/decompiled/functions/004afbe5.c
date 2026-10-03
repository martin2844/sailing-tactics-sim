
int FUN_004afbe5(undefined4 param_1)

{
  int iVar1;
  AFX_MODULE_THREAD_STATE *pAVar2;
  code *pcVar3;
  
  pcVar3 = DAT_004cd9cc;
  while( true ) {
    iVar1 = FUN_0049bf00(param_1);
    if (iVar1 != 0) {
      return iVar1;
    }
    if (pcVar3 == DAT_004cd9cc) {
      pAVar2 = AfxGetModuleThreadState();
      pcVar3 = *(code **)(pAVar2 + 0x28);
    }
    if (pcVar3 == (code *)0x0) break;
    iVar1 = (*pcVar3)(param_1);
    if (iVar1 == 0) {
      return 0;
    }
  }
  return 0;
}

