
undefined4 __fastcall FUN_00472fc3(int *param_1)

{
  int iVar1;
  CWnd *pCVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_00468021(param_1);
  if (iVar1 == -1) {
    uVar3 = 0xffffffff;
  }
  else {
    if ((*(byte *)(param_1 + 0x19) & 0x10) != 0) {
      FUN_00456537(param_1,1);
    }
    GetParent((HWND)param_1[7]);
    pCVar2 = FUN_004680cc();
    iVar1 = (**(code **)(*(int *)pCVar2 + 0xb8))();
    if (iVar1 != 0) {
      param_1[0x1b] = (int)pCVar2;
      AddTail(pCVar2 + 0x6c,param_1);
    }
    uVar3 = 0;
  }
  return uVar3;
}

