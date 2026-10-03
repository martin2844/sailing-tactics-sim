
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00433c60(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  double local_50;
  int local_44 [6];
  int local_2c [6];
  int local_14 [5];
  
  FUN_0041f130(param_1,param_4);
  local_50 = (_DAT_004cc980 - _DAT_004cc978 / (double)*(int *)(&DAT_0050f6d0 + param_5 * 4)) *
             _DAT_0050f6e0 * _DAT_004cc5f0;
  if (4 < *(int *)(&DAT_0050f6d0 + param_5 * 4)) {
    local_50 = 7.75;
  }
  local_2c[1] = 0xffffff65;
  local_2c[0] = -0x19;
  local_2c[4] = 0xffffffe7;
  local_2c[2] = 0x19;
  local_2c[3] = 0x9b;
  if (DAT_0053652c == 1) {
    local_2c[1] = 0xffffff56;
    local_2c[0] = -10;
    local_2c[2] = 10;
    local_2c[3] = 0xaa;
    local_2c[4] = 0xfffffff6;
  }
  iVar2 = FUN_0041bc20(*(int *)(&DAT_00535740 + param_4 * 4) - *(int *)(&DAT_00535740 + param_5 * 4)
                      );
  if ((&DAT_00525a78)[param_5] == 0) {
    iVar2 = FUN_0041bc20((iVar2 - *(int *)(&DAT_004fbb90 + param_5 * 4)) +
                         *(int *)(&DAT_00535740 + param_5 * 4));
  }
  if ((&DAT_00525a78)[param_5] == 2) {
    iVar2 = FUN_0041bc20((iVar2 - (&DAT_00522b90)[param_5]) + *(int *)(&DAT_00535740 + param_5 * 4))
    ;
  }
  iVar2 = FUN_0041bc20(iVar2);
  piVar4 = local_14;
  iVar5 = 0;
  do {
    iVar3 = FUN_0041bc20(*(int *)((int)local_2c + iVar5) + iVar2);
    iVar1 = (&DAT_004f1740)[iVar3];
    *(int *)((int)local_44 + iVar5) =
         param_2 - (int)(longlong)((double)(int)(&DAT_004f85c8)[iVar3] * local_50 * _DAT_004cc678);
    iVar5 = iVar5 + 4;
    *piVar4 = param_3 - (int)(longlong)((double)iVar1 * local_50 * _DAT_004cc3f0);
    piVar4 = piVar4 + 1;
  } while (iVar5 < 0x11);
  FUN_004b4d9d(param_1,(int *)&local_50,local_44[0],local_14[0]);
  CDC::LineTo(param_1,local_44[1],local_14[1]);
  FUN_004b4d9d(param_1,(int *)&local_50,local_44[2],local_14[2]);
  CDC::LineTo(param_1,local_44[3],local_14[3]);
  FUN_004b4d9d(param_1,(int *)&local_50,(local_44[0] + local_44[1]) / 2,
               (local_14[0] + local_14[1]) / 2);
  CDC::LineTo(param_1,(local_44[2] + local_44[3]) / 2,(local_14[2] + local_14[3]) / 2);
  iVar2 = local_14[1] * 7 + local_14[0];
  iVar5 = local_44[1] * 7 + local_44[0];
  FUN_004b4d9d(param_1,(int *)&local_50,(int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3,
               (int)(iVar2 + (iVar2 >> 0x1f & 7U)) >> 3);
  iVar2 = local_14[3] * 7 + local_14[2];
  iVar5 = local_44[3] * 7 + local_44[2];
  CDC::LineTo(param_1,(int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3,
              (int)(iVar2 + (iVar2 >> 0x1f & 7U)) >> 3);
  if (DAT_0053652c == 1) {
    FUN_0041ed90(param_1,param_4);
    _DAT_004f6e28 = local_44[0];
    _DAT_004f6e2c = local_14[0];
    _DAT_004f6e30 = local_44[2];
    _DAT_004f6e34 = local_14[2];
    _DAT_004f6e38 = local_44[1];
    _DAT_004f6e3c = local_14[1];
    _DAT_004f6e40 = local_44[3];
    _DAT_004f6e44 = local_14[3];
    Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
  }
  return;
}

