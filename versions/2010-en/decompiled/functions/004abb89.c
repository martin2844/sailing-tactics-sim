
undefined4 __thiscall
FUN_004abb89(int param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  HWND pHVar2;
  int *piVar3;
  CWinThread *pCVar4;
  undefined4 uVar5;
  
  iVar1 = FUN_004af6a3(param_2,param_3,param_4,param_5);
  if (iVar1 == 0) {
    if ((((param_3 == 0) || (param_3 == -1)) && ((param_2 & 0x8000) != 0)) && (param_2 < 0xf000)) {
      pHVar2 = GetParent(*(HWND *)(param_1 + 0x1c));
      piVar3 = (int *)FUN_004ac7ac(pHVar2);
      if (piVar3 != (int *)0x0) {
        iVar1 = (**(code **)(*piVar3 + 0x14))(param_2,param_3,param_4,param_5);
        if (iVar1 != 0) goto LAB_004abc00;
      }
      pCVar4 = AfxGetThread();
      if (pCVar4 != (CWinThread *)0x0) {
        iVar1 = (**(code **)(*(int *)pCVar4 + 0x14))(param_2,param_3,param_4,param_5);
        if (iVar1 != 0) goto LAB_004abc00;
      }
    }
    uVar5 = 0;
  }
  else {
LAB_004abc00:
    uVar5 = 1;
  }
  return uVar5;
}

