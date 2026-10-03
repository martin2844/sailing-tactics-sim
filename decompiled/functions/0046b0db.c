
uint __cdecl
FUN_0046b0db(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined *param_4,
            undefined4 *param_5,uint param_6,undefined4 *param_7)

{
  uint uVar1;
  
  uVar1 = 1;
  if (param_7 != (undefined4 *)0x0) {
    *param_7 = param_1;
    param_7[1] = param_4;
    return 1;
  }
  if (param_6 < 0xd) {
    if (param_6 == 0xc) {
      (*(code *)param_4)();
      return 1;
    }
    param_5 = param_2;
    if (param_6 != 2) {
      return 0;
    }
LAB_0046b1d0:
    uVar1 = (*(code *)param_4)(param_5);
    return uVar1;
  }
  if (param_6 < 0x24) {
    if (param_6 == 0x23) {
      uVar1 = (*(code *)param_4)();
      return uVar1;
    }
    param_5 = param_2;
    if (param_6 != 0xd) {
      return 0;
    }
LAB_0046b1c5:
    (*(code *)param_4)(param_5);
    return 1;
  }
  switch(param_6) {
  case 0x26:
    (*(code *)param_4)(param_5[1],*param_5);
    break;
  case 0x27:
    uVar1 = (*(code *)param_4)(param_5[1],*param_5);
    break;
  case 0x28:
    (*(code *)param_4)(param_2,param_5[1],*param_5);
    break;
  case 0x29:
    uVar1 = (*(code *)param_4)(param_2,param_5[1],*param_5);
    break;
  default:
    return 0;
  case 0x2c:
    (*(code *)param_4)(param_5);
    goto LAB_0046b1b4;
  case 0x2d:
    (*(code *)param_4)(param_5,param_2);
LAB_0046b1b4:
    uVar1 = (uint)(param_5[7] == 0);
    param_5[7] = 0;
    break;
  case 0x2e:
    goto LAB_0046b1c5;
  case 0x2f:
    goto LAB_0046b1d0;
  }
  return uVar1;
}

