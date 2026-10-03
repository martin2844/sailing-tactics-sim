
undefined4 * __thiscall FUN_004ab2b6(int param_1,int param_2,undefined4 *param_3)

{
  if (param_3 != (undefined4 *)0x0) goto LAB_004ab2c3;
  param_3 = *(undefined4 **)(param_1 + 4);
  while( true ) {
    if (param_3 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    if (param_3[2] == param_2) break;
LAB_004ab2c3:
    param_3 = (undefined4 *)*param_3;
  }
  return param_3;
}

