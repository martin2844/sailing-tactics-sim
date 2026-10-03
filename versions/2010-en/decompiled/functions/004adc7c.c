
undefined4 __thiscall FUN_004adc7c(int *param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined1 local_30 [4];
  uint local_2c;
  int local_8;
  
  uVar3 = param_2 & 0xffff;
  param_2 = param_2 >> 0x10;
  if (param_3 == 0) {
    if (uVar3 == 0) {
      return 0;
    }
    FUN_004adc49();
    local_2c = uVar3;
    (**(code **)(*param_1 + 0x14))(uVar3,0xffffffff,local_30,0);
    if (local_8 != 0) {
      param_2 = 0;
LAB_004adcc0:
      uVar1 = (**(code **)(*param_1 + 0x14))(uVar3,param_2,0,0);
      return uVar1;
    }
  }
  else {
    iVar2 = FUN_004c04f2(FUN_0049a32a);
    if ((*(int *)(iVar2 + 0xb8) != param_1[7]) && (iVar2 = FUN_004ae5ce(param_3,0), iVar2 == 0)) {
      if (uVar3 == 0) {
        return 0;
      }
      goto LAB_004adcc0;
    }
  }
  return 1;
}

