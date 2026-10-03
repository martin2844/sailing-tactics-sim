
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00423830(CDC *param_1,int param_2,int param_3,int param_4,int param_5)

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
  
  FUN_004166e0((int)param_1,param_4);
  local_50 = (_DAT_00484cf0 - _DAT_00485100 / (double)*(int *)(&DAT_004a8660 + param_5 * 4)) *
             _DAT_004a8670 * _DAT_00484db0;
  if (4 < *(int *)(&DAT_004a8660 + param_5 * 4)) {
    local_50 = 7.75;
  }
  local_14[0] = -0x19;
  local_14[4] = 0xffffffe7;
  local_14[1] = 0xffffff65;
  local_14[2] = 0x19;
  local_14[3] = 0x9b;
  iVar2 = FUN_00413cb0(*(int *)(&DAT_004ac018 + param_4 * 4) - *(int *)(&DAT_004ac018 + param_5 * 4)
                      );
  if ((&DAT_004ab160)[param_5] == 0) {
    iVar2 = FUN_00413cb0((iVar2 - *(int *)(&DAT_004a6830 + param_5 * 4)) +
                         *(int *)(&DAT_004ac018 + param_5 * 4));
  }
  if ((&DAT_004ab160)[param_5] == 2) {
    iVar2 = FUN_00413cb0((iVar2 - *(int *)(&DAT_004aa5b0 + param_5 * 4)) +
                         *(int *)(&DAT_004ac018 + param_5 * 4));
  }
  iVar2 = FUN_00413cb0(iVar2);
  piVar4 = local_2c;
  iVar5 = 0;
  do {
    iVar3 = FUN_00413cb0(*(int *)((int)local_14 + iVar5) + iVar2);
    iVar1 = (&DAT_004a3450)[iVar3];
    *(int *)((int)local_44 + iVar5) =
         param_2 - (int)(longlong)((double)(int)(&DAT_004a54a0)[iVar3] * local_50 * _DAT_00484e28);
    iVar5 = iVar5 + 4;
    *piVar4 = param_3 - (int)(longlong)((double)iVar1 * local_50 * _DAT_00484cc8);
    piVar4 = piVar4 + 1;
  } while (iVar5 < 0x11);
  FUN_004706bd(param_1,(int *)&local_50,local_44[0],local_2c[0]);
  CDC::LineTo(param_1,local_44[1],local_2c[1]);
  FUN_004706bd(param_1,(int *)&local_50,local_44[2],local_2c[2]);
  CDC::LineTo(param_1,local_44[3],local_2c[3]);
  FUN_004706bd(param_1,(int *)&local_50,(local_44[0] + local_44[1]) / 2,
               (local_2c[0] + local_2c[1]) / 2);
  CDC::LineTo(param_1,(local_44[2] + local_44[3]) / 2,(local_2c[2] + local_2c[3]) / 2);
  local_2c[0] = local_2c[1] * 7 + local_2c[0];
  local_44[0] = local_44[1] * 7 + local_44[0];
  FUN_004706bd(param_1,(int *)&local_50,(int)(local_44[0] + (local_44[0] >> 0x1f & 7U)) >> 3,
               (int)(local_2c[0] + (local_2c[0] >> 0x1f & 7U)) >> 3);
  local_2c[2] = local_2c[3] * 7 + local_2c[2];
  local_44[2] = local_44[3] * 7 + local_44[2];
  CDC::LineTo(param_1,(int)(local_44[2] + (local_44[2] >> 0x1f & 7U)) >> 3,
              (int)(local_2c[2] + (local_2c[2] >> 0x1f & 7U)) >> 3);
  return;
}

