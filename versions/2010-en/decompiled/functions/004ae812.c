
void __fastcall FUN_004ae812(int param_1)

{
  int iVar1;
  CWinThread *pCVar2;
  uint uVar3;
  
  iVar1 = FUN_004bfff8();
  iVar1 = *(int *)(iVar1 + 4);
  FUN_004c0587(FUN_0049a2f9);
  if (*(int *)(iVar1 + 0x1c) == param_1) {
    FUN_004b1da9();
  }
  iVar1 = FUN_004bfff8();
  if (*(char *)(iVar1 + 0x14) == '\0') {
    pCVar2 = AfxGetThread();
    if (pCVar2 != (CWinThread *)0x0) {
      pCVar2 = AfxGetThread();
      if (*(int *)(pCVar2 + 0x1c) == param_1) {
        iVar1 = FUN_004c0587(FUN_0049a382);
        if (*(code **)(iVar1 + 0x1c) != (code *)0x0) {
          (**(code **)(iVar1 + 0x1c))();
        }
      }
    }
  }
  uVar3 = FUN_004af3eb();
  if ((uVar3 & 0x40000000) == 0) {
    FUN_004ae04c(*(undefined4 *)(param_1 + 0x1c),0x15,0,0,1,1);
  }
  FUN_004ac701(param_1);
  return;
}

