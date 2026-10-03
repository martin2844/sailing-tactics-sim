
undefined4 __fastcall FUN_00476875(CWnd *param_1)

{
  CWnd *pCVar1;
  undefined4 uVar2;
  
  pCVar1 = FUN_0046980f(param_1);
  if (*(int *)(pCVar1 + 0x50) == 0) {
    uVar2 = FUN_00468021(param_1);
  }
  else {
    SetCursor(DAT_004ae67c);
    uVar2 = 1;
  }
  return uVar2;
}

