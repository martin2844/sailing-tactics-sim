
undefined4 * __thiscall FUN_00466bd6(void *this,int param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) goto LAB_00466be3;
  param_2 = *(undefined4 **)((int)this + 4);
  while( true ) {
    if (param_2 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    if (param_2[2] == param_1) break;
LAB_00466be3:
    param_2 = (undefined4 *)*param_2;
  }
  return param_2;
}

