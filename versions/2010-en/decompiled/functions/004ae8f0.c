
void __thiscall FUN_004ae8f0(int param_1,undefined4 param_2)

{
  CWinThread *pCVar1;
  uint uVar2;
  int iVar3;
  
  pCVar1 = AfxGetThread();
  if (pCVar1 != (CWinThread *)0x0) {
    pCVar1 = AfxGetThread();
    if (*(int *)(pCVar1 + 0x1c) == param_1) {
      FUN_004bfff8();
      FUN_004afd68(param_2);
    }
  }
  uVar2 = FUN_004af3eb();
  if ((uVar2 & 0x40000000) == 0) {
    iVar3 = FUN_004ac6cc();
    FUN_004ae04c(*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(iVar3 + 4),
                 *(undefined4 *)(iVar3 + 8),*(undefined4 *)(iVar3 + 0xc),1,1);
  }
  return;
}

