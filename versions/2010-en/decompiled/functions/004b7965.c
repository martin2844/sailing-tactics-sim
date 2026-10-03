
undefined4 __thiscall FUN_004b7965(CWnd *param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  CWnd *pCVar3;
  int iVar4;
  uint uVar5;
  
  uVar1 = FUN_004af3eb();
  uVar2 = *(uint *)(param_1 + 0x60);
  uVar5 = 0;
  if (((uVar2 & 1) == 0) || ((uVar1 & 0x10000000) == 0)) {
    if (((uVar2 & 2) != 0) && ((uVar1 & 0x10000000) == 0)) {
      uVar5 = 0x40;
    }
  }
  else {
    uVar5 = 0x80;
  }
  *(uint *)(param_1 + 0x60) = uVar2 & 0xfffffffc;
  if (uVar5 != 0) {
    FUN_004af4dd(0,0,0,0,0,uVar5 | 0x17);
  }
  uVar2 = FUN_004af3eb();
  if ((uVar2 & 0x10000000) != 0) {
    if ((*(int *)(param_1 + 0x70) != 0) && (uVar2 = FUN_004af3eb(), (uVar2 & 0x10000000) == 0)) {
      return 0;
    }
    pCVar3 = CWnd::GetOwner(param_1);
    if ((pCVar3 == (CWnd *)0x0) || (iVar4 = (**(code **)(*(int *)pCVar3 + 0xb8))(), iVar4 == 0)) {
      pCVar3 = (CWnd *)FUN_004add82();
    }
    if (pCVar3 != (CWnd *)0x0) {
      (**(code **)(*(int *)param_1 + 200))(pCVar3,param_2);
    }
    return 0;
  }
  return 0;
}

