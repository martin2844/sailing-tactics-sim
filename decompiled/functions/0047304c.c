
void __fastcall FUN_0047304c(int *param_1)

{
  int iVar1;
  CWnd *pCVar2;
  
  if (param_1[7] != 0) {
    iVar1 = FUN_004786ef(param_1);
    if (iVar1 != 0) {
      pCVar2 = FUN_004786de((int)param_1);
      (**(code **)(*(int *)pCVar2 + 0x60))();
      return;
    }
  }
  FUN_00468970((int)param_1);
  return;
}

