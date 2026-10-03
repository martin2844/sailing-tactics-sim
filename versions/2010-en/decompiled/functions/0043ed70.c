
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0043ed70(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iStack_18;
  int iStack_14;
  double dStack_10;
  
  (**(code **)(*param_1 + 0x2c))(param_1,7);
  if (DAT_00523664 <= DAT_00523668) {
    FUN_004b4d9d(param_1,(int *)&dStack_10,DAT_004fed5c,DAT_00523664);
    iStack_18 = 1;
    iStack_14 = 9;
    iVar1 = param_4 - param_4 / 0x14;
    do {
      dStack_10 = (double)iStack_14;
      FUN_0043e730(0,((double)DAT_004fe094 * (double)iStack_18 + (double)DAT_00536410 * dStack_10) *
                     _DAT_004cc570,
                   ((double)DAT_004fe2a0 * (double)iStack_18 + (double)DAT_00536414 * dStack_10) *
                   _DAT_004cc570,param_5,0);
      if (((DAT_00523660 < iVar1) && (param_2 < DAT_004fed58)) && (DAT_004fed58 < param_3)) {
        CDC::LineTo(param_1,DAT_004fed58,DAT_00523660);
      }
      iStack_18 = iStack_18 + 1;
      iStack_14 = iStack_14 + -1;
    } while (-1 < iStack_14);
    if (((DAT_00523668 < iVar1) && (param_2 < DAT_004fed60)) && (DAT_004fed60 < param_3)) {
      CDC::LineTo(param_1,DAT_004fed60,DAT_00523668);
    }
  }
  if (DAT_00523668 < DAT_00523664) {
    FUN_004b4d9d(param_1,(int *)&dStack_10,DAT_004fed60,DAT_00523668);
    iStack_18 = 1;
    iStack_14 = 9;
    param_4 = param_4 - param_4 / 0x14;
    do {
      dStack_10 = (double)iStack_14;
      FUN_0043e730(0,((double)DAT_004fe094 * dStack_10 + (double)DAT_00536410 * (double)iStack_18) *
                     _DAT_004cc570,
                   ((double)DAT_004fe2a0 * dStack_10 + (double)DAT_00536414 * (double)iStack_18) *
                   _DAT_004cc570,param_5,0);
      if (((DAT_00523660 < param_4) && (param_2 < DAT_004fed58)) && (DAT_004fed58 < param_3)) {
        CDC::LineTo(param_1,DAT_004fed58,DAT_00523660);
      }
      iStack_18 = iStack_18 + 1;
      iStack_14 = iStack_14 + -1;
    } while (-1 < iStack_14);
    if (((DAT_00523664 < param_4) && (param_2 < DAT_004fed5c)) && (DAT_004fed5c < param_3)) {
      CDC::LineTo(param_1,DAT_004fed5c,DAT_00523664);
    }
  }
  return;
}

