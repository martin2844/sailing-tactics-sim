
bool FUN_004b1b23(int param_1)

{
  AFX_MODULE_THREAD_STATE *pAVar1;
  int iVar2;
  CWinThread *pCVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  
  pAVar1 = AfxGetModuleThreadState();
  if ((*(int *)(pAVar1 + 0x10) != 0) &&
     (iVar2 = *(int *)(pAVar1 + 0x10) + -1, *(int *)(pAVar1 + 0x10) = iVar2, iVar2 == 0)) {
    pCVar3 = AfxGetThread();
    iVar2 = FUN_004bfff8();
    iVar2 = *(int *)(iVar2 + 4);
    if (param_1 != 0) {
      if (((param_1 != -1) && (pCVar3 != (CWinThread *)0x0)) &&
         (*(code **)(pCVar3 + 0x54) != (code *)0x0)) {
        (**(code **)(pCVar3 + 0x54))(0,0);
      }
      FUN_004b5073();
      FUN_004b4710();
      FUN_004b1e45();
      FUN_004ac728();
      FUN_0049a9a3();
    }
    iVar4 = FUN_004c04f2(FUN_0049a32a);
    if (((iVar2 != 0) &&
        ((*(int *)(iVar4 + 0xc) == 0 ||
         (uVar5 = FUN_0049cbe0(*(int *)(iVar4 + 0xc)), uVar5 < *(uint *)(iVar2 + 0xb8))))) &&
       (*(int *)(iVar2 + 0xb8) != 0)) {
      iVar7 = 0;
      if (*(int *)(iVar4 + 0xc) != 0) {
        iVar7 = FUN_0049cbe0(*(int *)(iVar4 + 0xc));
        FUN_0049bfd0(*(undefined4 *)(iVar4 + 0xc));
      }
      iVar2 = FUN_0049bf00(*(undefined4 *)(iVar2 + 0xb8));
      *(int *)(iVar4 + 0xc) = iVar2;
      if ((iVar2 == 0) && (iVar7 != 0)) {
        uVar6 = FUN_0049bf00(iVar7);
        *(undefined4 *)(iVar4 + 0xc) = uVar6;
      }
    }
  }
  return *(int *)(pAVar1 + 0x10) != 0;
}

