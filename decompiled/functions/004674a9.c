
undefined4 __thiscall
FUN_004674a9(void *this,undefined4 *param_1,uint param_2,undefined4 *param_3,undefined4 *param_4)

{
  uint uVar1;
  CWnd *pCVar2;
  int iVar3;
  CWinThread *pCVar4;
  undefined4 uVar5;
  
  uVar1 = FUN_0046afc3(this,param_1,param_2,param_3,param_4);
  if (uVar1 == 0) {
    if ((((param_2 == 0) || (param_2 == 0xffffffff)) && (((uint)param_1 & 0x8000) != 0)) &&
       (param_1 < (undefined4 *)0xf000)) {
      GetParent(*(HWND *)((int)this + 0x1c));
      pCVar2 = FUN_004680cc();
      if (pCVar2 != (CWnd *)0x0) {
        iVar3 = (**(code **)(*(int *)pCVar2 + 0x14))(param_1,param_2,param_3,param_4);
        if (iVar3 != 0) goto LAB_00467520;
      }
      pCVar4 = AfxGetThread();
      if (pCVar4 != (CWinThread *)0x0) {
        iVar3 = (**(code **)(*(int *)pCVar4 + 0x14))(param_1,param_2,param_3,param_4);
        if (iVar3 != 0) goto LAB_00467520;
      }
    }
    uVar5 = 0;
  }
  else {
LAB_00467520:
    uVar5 = 1;
  }
  return uVar5;
}

