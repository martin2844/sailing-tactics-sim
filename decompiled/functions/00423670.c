
void __cdecl FUN_00423670(CDC *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int local_8 [2];
  
  FUN_004166e0((int)param_1,param_4);
  if (((DAT_004ac98c != 1) || (param_4 == param_5)) || (*(int *)(&DAT_004a8660 + param_5 * 4) < 9))
  {
    iVar1 = FUN_00413cb0((*(int *)(&DAT_004ac018 + param_4 * 4) -
                         *(int *)(&DAT_004ac018 + param_5 * 4)) + 0xb4);
    if ((&DAT_004ab160)[param_5] == 0) {
      iVar1 = FUN_00413cb0((iVar1 - *(int *)(&DAT_004a6830 + param_5 * 4)) +
                           *(int *)(&DAT_004ac018 + param_5 * 4));
    }
    if ((&DAT_004ab160)[param_5] == 2) {
      iVar1 = FUN_00413cb0((iVar1 - *(int *)(&DAT_004aa5b0 + param_5 * 4)) +
                           *(int *)(&DAT_004ac018 + param_5 * 4));
    }
    if (2 < param_6) {
      iVar1 = *(int *)(&DAT_004ac018 + param_4 * 4) + 0xb4;
    }
    iVar2 = FUN_00413cb0(iVar1);
    iVar1 = (&DAT_004a54a0)[iVar2];
    iVar2 = (&DAT_004a3450)[iVar2];
    FUN_004706bd(param_1,local_8,param_2,param_3);
    CDC::LineTo(param_1,iVar1 / 10 + param_2,param_3 - iVar2 / 10);
    if (param_4 == 1) {
      FUN_004706bd(param_1,local_8,param_2 + -4,param_3);
      CDC::LineTo(param_1,param_2 + 4,param_3);
      FUN_004706bd(param_1,local_8,param_2,param_3 + -4);
      CDC::LineTo(param_1,param_2,param_3 + 4);
    }
    if ((param_4 == 2) && (DAT_00491140 == 2)) {
      iVar1 = param_3 + -3;
      iVar2 = param_2 + -3;
      FUN_004706bd(param_1,local_8,iVar2,iVar1);
      CDC::LineTo(param_1,param_2 + 3,iVar1);
      CDC::LineTo(param_1,param_2 + 3,param_3 + 3);
      CDC::LineTo(param_1,iVar2,param_3 + 3);
      CDC::LineTo(param_1,iVar2,iVar1);
    }
  }
  return;
}

