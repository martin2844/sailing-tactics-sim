
undefined4 FUN_0049f430(uint param_1,uint param_2,byte param_3)

{
  if ((*(byte *)((int)&DAT_005384c0 + (param_1 & 0xff) + 1) & param_3) == 0) {
    if (param_2 == 0) {
      param_2 = 0;
    }
    else {
      param_2 = *(ushort *)(&DAT_004f025a + (param_1 & 0xff) * 2) & param_2;
    }
    if (param_2 == 0) {
      return 0;
    }
  }
  return 1;
}

