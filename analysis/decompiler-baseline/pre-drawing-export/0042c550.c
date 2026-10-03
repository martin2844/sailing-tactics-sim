
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0042c550(CDC *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iStack_1c;
  int iStack_18;
  double adStack_14 [2];
  
  (**(code **)(*(int *)param_1 + 0x2c))(7);
  if (DAT_004aaa4c <= DAT_004aaa50) {
    FUN_004706bd(param_1,(int *)adStack_14,DAT_004a7c4c,DAT_004aaa4c);
    iStack_1c = 1;
    iStack_18 = 9;
    iVar1 = param_4 - param_4 / 0x14;
    do {
      adStack_14[0] = (double)iStack_1c;
      FUN_0042bfc0(0,((double)DAT_004a70f8 * adStack_14[0] +
                     (double)DAT_004aa594 * (double)iStack_18) * _DAT_00484d48,
                   ((double)DAT_004a72c8 * adStack_14[0] + (double)DAT_004aa59c * (double)iStack_18)
                   * _DAT_00484d48,param_5,0);
      if (((DAT_004aaa48 < iVar1) && (param_2 < DAT_004a7c48)) && (DAT_004a7c48 < param_3)) {
        CDC::LineTo(param_1,DAT_004a7c48,DAT_004aaa48);
      }
      iStack_1c = iStack_1c + 1;
      iStack_18 = iStack_18 + -1;
    } while (-1 < iStack_18);
    if (((DAT_004aaa50 < iVar1) && (param_2 < DAT_004a7c50)) && (DAT_004a7c50 < param_3)) {
      CDC::LineTo(param_1,DAT_004a7c50,DAT_004aaa50);
    }
  }
  if (DAT_004aaa50 < DAT_004aaa4c) {
    FUN_004706bd(param_1,(int *)adStack_14,DAT_004a7c50,DAT_004aaa50);
    iStack_1c = 1;
    iStack_18 = 9;
    iVar1 = param_4 - param_4 / 0x14;
    do {
      adStack_14[0] = (double)iStack_1c;
      FUN_0042bfc0(0,((double)DAT_004aa594 * adStack_14[0] +
                     (double)DAT_004a70f8 * (double)iStack_18) * _DAT_00484d48,
                   ((double)DAT_004aa59c * adStack_14[0] + (double)DAT_004a72c8 * (double)iStack_18)
                   * _DAT_00484d48,param_5,0);
      if (((DAT_004aaa48 < iVar1) && (param_2 < DAT_004a7c48)) && (DAT_004a7c48 < param_3)) {
        CDC::LineTo(param_1,DAT_004a7c48,DAT_004aaa48);
      }
      iStack_1c = iStack_1c + 1;
      iStack_18 = iStack_18 + -1;
    } while (-1 < iStack_18);
    if (((DAT_004aaa4c < iVar1) && (param_2 < DAT_004a7c4c)) && (DAT_004a7c4c < param_3)) {
      CDC::LineTo(param_1,DAT_004a7c4c,DAT_004aaa4c);
    }
  }
  return;
}

