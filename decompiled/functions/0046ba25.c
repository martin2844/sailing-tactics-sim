
undefined4 __thiscall FUN_0046ba25(void *this,int *param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  HWND pHVar4;
  CWnd *pCVar5;
  int *piVar6;
  undefined4 uVar7;
  
  if ((*param_1 != 0) || (iVar2 = FUN_0046b9ac(this,(int)param_1), iVar2 == 0)) {
    uVar1 = param_1[1];
    if (((uVar1 < 0x100) || (0x108 < uVar1)) && ((uVar1 < 0x104 || (0x107 < uVar1)))) {
      iVar2 = 0;
    }
    else {
      iVar2 = 1;
    }
    if (((((iVar2 != 0) || (uVar1 == 0x201)) || (uVar1 == 0x203)) ||
        (((uVar1 == 0x204 || (uVar1 == 0x206)) ||
         ((uVar1 == 0x207 || ((uVar1 == 0x209 || (uVar1 == 0xa1)))))))) ||
       ((uVar1 == 0xa3 ||
        ((((uVar1 == 0xa4 || (uVar1 == 0xa6)) || (uVar1 == 0xa7)) || (uVar1 == 0xa9)))))) {
      FUN_00468a27(iVar2);
    }
    piVar3 = (int *)FUN_00455bf0();
    pHVar4 = (HWND)0x0;
    if (piVar3 != (int *)0x0) {
      pHVar4 = (HWND)piVar3[7];
    }
    iVar2 = FUN_00469e7f(pHVar4,param_1);
    if (iVar2 == 0) {
      if (piVar3 != (int *)0x0) {
        pCVar5 = FUN_004680cc();
        piVar6 = (int *)FUN_0046972b((int)pCVar5);
        if (piVar6 != piVar3) {
          uVar7 = (**(code **)(*piVar3 + 0x98))(param_1);
          return uVar7;
        }
      }
      return 0;
    }
  }
  return 1;
}

