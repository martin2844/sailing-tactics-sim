
CWnd * __fastcall FUN_0046980f(CWnd *param_1)

{
  CWnd *pCVar1;
  int iVar2;
  CWnd *pCVar3;
  
  if (param_1 == (CWnd *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x1c);
  }
  if (iVar2 != 0) {
    iVar2 = (**(code **)(*(int *)param_1 + 0xb8))();
    pCVar3 = param_1;
    if (iVar2 == 0) {
      param_1 = FUN_004696a2((int)param_1);
      pCVar3 = param_1;
    }
    while (pCVar1 = pCVar3, pCVar1 != (CWnd *)0x0) {
      pCVar3 = FUN_004696a2((int)pCVar1);
      param_1 = pCVar1;
    }
    return param_1;
  }
  return (CWnd *)0x0;
}

