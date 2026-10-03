
bool FUN_0046d443(int param_1)

{
  AFX_MODULE_THREAD_STATE *pAVar1;
  int iVar2;
  CWinThread *pCVar3;
  int iVar4;
  SIZE_T SVar5;
  undefined4 uVar6;
  
  pAVar1 = AfxGetModuleThreadState();
  if ((*(int *)(pAVar1 + 0x10) != 0) &&
     (iVar2 = *(int *)(pAVar1 + 0x10) + -1, *(int *)(pAVar1 + 0x10) = iVar2, iVar2 == 0)) {
    pCVar3 = AfxGetThread();
    iVar2 = FUN_0047b918();
    iVar2 = *(int *)(iVar2 + 4);
    if (param_1 != 0) {
      if (((param_1 != -1) && (pCVar3 != (CWinThread *)0x0)) &&
         (*(code **)(pCVar3 + 0x54) != (code *)0x0)) {
        (**(code **)(pCVar3 + 0x54))(0,0);
      }
      FUN_00470993();
      FUN_00470030();
      FUN_0046d765();
      FUN_00468048();
      FUN_004562b3();
    }
    iVar4 = FUN_0047be12(&DAT_004ae4b8,FUN_00455c3a);
    if (((iVar2 != 0) &&
        ((*(undefined **)(iVar4 + 0xc) == (undefined *)0x0 ||
         (SVar5 = FUN_00458320(*(undefined **)(iVar4 + 0xc)), SVar5 < *(uint *)(iVar2 + 0xb8))))) &&
       (*(int *)(iVar2 + 0xb8) != 0)) {
      SVar5 = 0;
      if (*(undefined **)(iVar4 + 0xc) != (undefined *)0x0) {
        SVar5 = FUN_00458320(*(undefined **)(iVar4 + 0xc));
        FUN_00457710(*(undefined **)(iVar4 + 0xc));
      }
      iVar2 = FUN_00457640(*(uint *)(iVar2 + 0xb8));
      *(int *)(iVar4 + 0xc) = iVar2;
      if ((iVar2 == 0) && (SVar5 != 0)) {
        uVar6 = FUN_00457640(SVar5);
        *(undefined4 *)(iVar4 + 0xc) = uVar6;
      }
    }
  }
  return *(int *)(pAVar1 + 0x10) != 0;
}

