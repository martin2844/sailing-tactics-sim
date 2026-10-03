
undefined4 FUN_004b0105(int *param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  
  if ((*param_1 != 0) || (iVar2 = FUN_004b008c(param_1), iVar2 == 0)) {
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
      FUN_004ad107(iVar2);
    }
    piVar3 = (int *)FUN_0049a2e0();
    iVar2 = 0;
    if (piVar3 != (int *)0x0) {
      iVar2 = piVar3[7];
    }
    iVar2 = FUN_004ae55f(iVar2,param_1);
    if (iVar2 == 0) {
      if (piVar3 != (int *)0x0) {
        FUN_004ac7ac(*param_1);
        piVar4 = (int *)FUN_004ade0b();
        if (piVar4 != piVar3) {
          uVar5 = (**(code **)(*piVar3 + 0x98))(param_1);
          return uVar5;
        }
      }
      return 0;
    }
  }
  return 1;
}

