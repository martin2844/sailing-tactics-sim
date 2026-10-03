
int * __fastcall FUN_004add82(int param_1)

{
  int iVar1;
  HWND pHVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x1c);
  }
  if (iVar1 != 0) {
    pHVar2 = *(HWND *)(param_1 + 0x1c);
    while( true ) {
      pHVar2 = GetParent(pHVar2);
      piVar3 = (int *)FUN_004ac7ac(pHVar2);
      if (piVar3 == (int *)0x0) break;
      iVar1 = (**(code **)(*piVar3 + 0xb8))();
      if (iVar1 != 0) {
        return piVar3;
      }
      pHVar2 = (HWND)piVar3[7];
    }
  }
  return (int *)0x0;
}

