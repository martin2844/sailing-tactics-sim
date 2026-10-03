
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00416d10(CDC *param_1,uint param_2,double param_3,int param_4,uint param_5,undefined *param_6,
            undefined *param_7,int param_8,int param_9,int param_10,int param_11)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  int iVar7;
  uint uVar8;
  
  iVar3 = param_10;
  iVar7 = param_9;
  puVar6 = param_6;
  param_3 = param_3 * _DAT_00484fc0;
  if (DAT_00491188 == 8) {
    param_3 = param_3 * _DAT_00484fc8;
  }
  if (DAT_004ac900 == 1) {
    param_3 = param_3 * _DAT_00484fd0;
  }
  if (DAT_004ac914 == 1) {
    param_3 = param_3 * _DAT_00484dc0;
  }
  param_5 = (int)(longlong)((double)(int)param_5 * (double)CONCAT44(param_8,param_7)) / 3;
  if (DAT_004ac904 == 1) {
    param_5 = param_5 + (int)(longlong)(param_3 * _DAT_00484dd8);
  }
  if (((param_2 == 1) || (DAT_004ac98c == 1)) || (0 < DAT_004ac994)) {
    FUN_00417570(param_1,DAT_004aa1f4,DAT_004aa2f4 - (int)(longlong)(param_3 * _DAT_00484fe0),
                 param_2,param_9,(int)param_6,param_10);
  }
  if (param_2 == 2) {
    if ((DAT_00491140 == 2) && (DAT_004ac98c == 0)) {
      FUN_00417570(param_1,DAT_004aa1f4,DAT_004aa2f4 - (int)(longlong)(param_3 * _DAT_00484fe0),2,
                   iVar7,(int)puVar6,iVar3);
    }
    if (((DAT_00491140 == 1) && (DAT_004ac98c == 0)) && (DAT_0049118c == 2)) {
      FUN_00417570(param_1,DAT_004aa1f4,DAT_004aa2f4 - (int)(longlong)(param_3 * _DAT_00484fe0),2,
                   iVar7,(int)puVar6,iVar3);
    }
  }
  if (DAT_004a7354 < (int)puVar6) {
    if (DAT_004a4dec != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
    }
  }
  else {
    (**(code **)(*(int *)param_1 + 0x2c))(param_1,7);
  }
  FUN_004706bd(param_1,(int *)&param_7,(&DAT_004aa1a0)[param_4],(&DAT_004aa2a0)[param_4]);
  iVar7 = (int)(longlong)(param_3 * _DAT_00484e00);
  CDC::LineTo(param_1,DAT_004aa1e4,DAT_004aa2e4 - iVar7);
  param_10 = (int)(longlong)(param_3 * _DAT_00484d90);
  CDC::LineTo(param_1,DAT_004aa1e8,DAT_004aa2e8 - param_10);
  iVar3 = (int)(longlong)(param_3 * _DAT_00484da8);
  CDC::LineTo(param_1,DAT_004aa1ec,DAT_004aa2ec - iVar3);
  CDC::LineTo(param_1,DAT_004aa1f0,DAT_004aa2f0 - (int)(longlong)(param_3 * _DAT_00484ec8));
  if (DAT_004ac914 == 1) {
    (**(code **)(*(int *)param_1 + 0x2c))(param_1,6);
  }
  iVar4 = (int)(longlong)(param_3 * _DAT_00484fe0);
  CDC::LineTo(param_1,DAT_004aa1f4,DAT_004aa2f4 - iVar4);
  if (DAT_004a4dec != (HGDIOBJ)0x0) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
  }
  if (DAT_004ac13c <= (int)param_6) {
    if (DAT_004ac914 == 1) {
      if ((*(int *)(&DAT_004aa730 + param_2 * 4) == 1) && (param_11 == 1)) {
        FUN_004706bd(param_1,(int *)&param_3,DAT_004aa1ec,DAT_004aa2ec - iVar3);
        CDC::LineTo(param_1,DAT_004aa1f4,DAT_004aa2f4 - iVar4);
      }
      if ((*(int *)(&DAT_004aa730 + param_2 * 4) == -1) && (param_11 == 0)) {
        FUN_004706bd(param_1,(int *)&param_3,DAT_004aa1ec,DAT_004aa2ec - iVar3);
        CDC::LineTo(param_1,DAT_004aa1f4,DAT_004aa2f4 - iVar4);
      }
    }
    DAT_004a72cc = DAT_004aa2e4 - iVar7;
    DAT_004a70fc = DAT_004aa1e4;
    if (DAT_004ac904 == 1) {
      DAT_004a72cc = DAT_004aa2e8 - param_10;
      DAT_004a70fc = DAT_004aa1e8;
    }
    DAT_004a70f4 = DAT_004aa204;
    DAT_004a72c0 = (DAT_004aa304 - param_5) - iVar7;
    FUN_004706bd(param_1,(int *)&param_3,DAT_004a70fc,DAT_004a72cc);
    CDC::LineTo(param_1,DAT_004a70f4,DAT_004a72c0);
    if (((DAT_004a7354 < (int)param_6) && ((int)param_2 < 2)) && (DAT_004ac904 != 1)) {
      param_7 = *(undefined **)(*(int *)param_1 + 0x2c);
      (*(code *)param_7)(param_1,7);
      DAT_004ac1d8 = ((0x3b < *(int *)(&DAT_004a7bc8 + param_2 * 4)) - 1 & 0xfffffffe) + 4;
      if ((DAT_004ac900 == 1) && (0x5a < *(int *)(&DAT_004a7bc8 + param_2 * 4))) {
        DAT_004ac1d8 = 3;
      }
      if (DAT_004ac900 == 0) {
        if (DAT_00491188 < 6) {
          param_10 = DAT_004a70f4;
          param_5 = DAT_004a72c0;
        }
        else {
          param_10 = (DAT_004a70fc + DAT_004a70f4 * 2) / 3;
          param_5 = (int)(DAT_004a72cc + DAT_004a72c0 * 2) / 3;
        }
      }
      else {
        iVar7 = DAT_004a70fc + DAT_004a70f4 * 3;
        param_10 = (int)(iVar7 + (iVar7 >> 0x1f & 3U)) >> 2;
        iVar7 = DAT_004a72cc + DAT_004a72c0 * 3;
        param_5 = (int)(iVar7 + (iVar7 >> 0x1f & 3U)) >> 2;
      }
      puVar6 = (undefined *)param_2;
      uVar8 = param_2;
      if (DAT_004ac900 == 0) {
        if (DAT_00491188 < 6) {
          iVar7 = 6;
          param_11 = 0x10;
        }
        else {
          iVar7 = 7;
          param_11 = 0xf;
        }
        param_6 = (undefined *)(uint)(DAT_00491188 >= 6);
        iVar3 = (&DAT_004aa2a0)[iVar7];
        param_3 = (double)CONCAT44(param_3._4_4_,iVar3);
        param_9 = ((&DAT_004aa1a0)[iVar7] + (&DAT_004aa1a0)[(int)param_6] * 6) / 7;
        piVar1 = &DAT_004aa2a0 + (int)param_6;
        iVar4 = (iVar3 + *piVar1 * 6) / 7;
        piVar2 = &DAT_004aa1a0 + param_11;
        param_6 = (undefined *)(((&DAT_004aa1a0)[(int)param_6] * 6 + *piVar2) / 7);
        param_11 = (&DAT_004aa2a0)[param_11];
        iVar5 = (param_11 + *piVar1 * 6) / 7;
        if (*(int *)(&DAT_004aa730 + param_2 * 4) == 1) {
          iVar7 = ((int)param_6 - (&DAT_004aa1a0)[iVar7]) * DAT_004ac1d8;
          iVar3 = (iVar5 - iVar3) * DAT_004ac1d8;
          puVar6 = (undefined *)(((int)(iVar7 + (iVar7 >> 0x1f & 7U)) >> 3) + param_9);
          uVar8 = ((int)(iVar3 + (iVar3 >> 0x1f & 7U)) >> 3) + iVar4;
        }
        else {
          iVar7 = (param_9 - *piVar2) * DAT_004ac1d8;
          iVar3 = (iVar4 - param_11) * DAT_004ac1d8;
          puVar6 = param_6 + ((int)(iVar7 + (iVar7 >> 0x1f & 7U)) >> 3);
          uVar8 = ((int)(iVar3 + (iVar3 >> 0x1f & 7U)) >> 3) + iVar5;
        }
      }
      if (DAT_004ac900 == 1) {
        iVar7 = (DAT_004a4880 + DAT_004a4950) / 2;
        iVar3 = (DAT_004a4884 + DAT_004a4df0) / 2;
        if (*(int *)(&DAT_004aa730 + param_2 * 4) == 1) {
          iVar4 = (DAT_004a4950 - iVar7) * DAT_004ac1d8;
          iVar5 = (DAT_004a4884 - iVar3) * DAT_004ac1d8;
          puVar6 = (undefined *)(((int)(iVar4 + (iVar4 >> 0x1f & 3U)) >> 2) + iVar7);
          uVar8 = ((int)(iVar5 + (iVar5 >> 0x1f & 3U)) >> 2) + iVar3;
        }
        if (*(int *)(&DAT_004aa730 + param_2 * 4) == -1) {
          iVar4 = (DAT_004a4880 - iVar7) * DAT_004ac1d8;
          iVar5 = (DAT_004a4df0 - iVar3) * DAT_004ac1d8;
          puVar6 = (undefined *)(((int)(iVar4 + (iVar4 >> 0x1f & 3U)) >> 2) + iVar7);
          uVar8 = ((int)(iVar5 + (iVar5 >> 0x1f & 3U)) >> 2) + iVar3;
        }
      }
      (*(code *)param_7)(param_1,4);
      FUN_004706bd(param_1,(int *)&param_3,param_10,param_5);
      CDC::LineTo(param_1,(int)puVar6,uVar8);
      if (DAT_00491188 < 7) {
        FUN_004706bd(param_1,(int *)&param_3,(DAT_004a70f4 + DAT_004a70fc) / 2,
                     (int)(DAT_004a72cc + DAT_004a72c0) / 2);
        CDC::LineTo(param_1,(DAT_004aa1a4 + DAT_004aa1a8) / 2,(DAT_004aa2a8 + DAT_004aa2a4) / 2);
      }
      if (DAT_004ac900 == 0) {
        FUN_004706bd(param_1,(int *)&param_3,(DAT_004a70f4 + DAT_004a70fc * 2) / 3,
                     (int)(DAT_004a72c0 + DAT_004a72cc * 2) / 3);
        CDC::LineTo(param_1,(&DAT_004aa1a0)[param_4],(&DAT_004aa2a0)[param_4]);
      }
    }
  }
  return;
}

