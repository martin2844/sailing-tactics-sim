
int __cdecl FUN_0046b505(uint param_1)

{
  int iVar1;
  AFX_MODULE_THREAD_STATE *pAVar2;
  code *pcVar3;
  
  pcVar3 = DAT_00485d2c;
  while( true ) {
    iVar1 = FUN_00457640(param_1);
    if (iVar1 != 0) {
      return iVar1;
    }
    if (pcVar3 == DAT_00485d2c) {
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

