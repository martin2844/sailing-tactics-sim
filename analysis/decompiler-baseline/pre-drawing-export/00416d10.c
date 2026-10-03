
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00416d10(CDC *param_1,uint param_2,double param_3,int param_4,uint param_5,undefined *param_6,
            undefined *param_7,int param_8,int param_9,int param_10,int param_11)

{
  int *piVar1;
  int *piVar2;
  CDC *this;
  uint uVar3;
  undefined *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  CDC *pCVar8;
  int iVar9;
  CDC *pCVar10;
  
  iVar7 = param_10;
  iVar9 = param_9;
  puVar4 = param_6;
  this = param_1;
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
      FUN_00417570(this,DAT_004aa1f4,DAT_004aa2f4 - (int)(longlong)(param_3 * _DAT_00484fe0),2,iVar9
                   ,(int)puVar4,iVar7);
    }
    if (((param_2 == 2) && (DAT_00491140 == 1)) && ((DAT_004ac98c == 0 && (DAT_0049118c == 2)))) {
      FUN_00417570(this,DAT_004aa1f4,DAT_004aa2f4 - (int)(longlong)(param_3 * _DAT_00484fe0),2,iVar9
                   ,(int)puVar4,iVar7);
    }
  }
  if (DAT_004a7354 < (int)puVar4) {
    if (DAT_004a4dec != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a4dec);
    }
  }
  else {
    (**(code **)(*(int *)this + 0x2c))(7);
  }
  FUN_004706bd(this,(int *)&param_7,(&DAT_004aa1a0)[param_4],(&DAT_004aa2a0)[param_4]);
  iVar9 = (int)(longlong)(param_3 * _DAT_00484e00);
  CDC::LineTo(this,DAT_004aa1e4,DAT_004aa2e4 - iVar9);
  param_10 = (int)(longlong)(param_3 * _DAT_00484d90);
  CDC::LineTo(this,DAT_004aa1e8,DAT_004aa2e8 - param_10);
  iVar7 = (int)(longlong)(param_3 * _DAT_00484da8);
  CDC::LineTo(this,DAT_004aa1ec,DAT_004aa2ec - iVar7);
  CDC::LineTo(this,DAT_004aa1f0,DAT_004aa2f0 - (int)(longlong)(param_3 * _DAT_00484ec8));
  if (DAT_004ac914 == 1) {
    (**(code **)(*(int *)this + 0x2c))(6);
  }
  iVar5 = (int)(longlong)(param_3 * _DAT_00484fe0);
  CDC::LineTo(this,DAT_004aa1f4,DAT_004aa2f4 - iVar5);
  if (DAT_004a4dec != (HGDIOBJ)0x0) {
    SelectObject(*(HDC *)(this + 4),DAT_004a4dec);
  }
  if (DAT_004ac13c <= (int)param_6) {
    if (DAT_004ac914 == 1) {
      if ((*(int *)(&DAT_004aa730 + param_2 * 4) == 1) && (param_11 == 1)) {
        FUN_004706bd(this,(int *)&param_3,DAT_004aa1ec,DAT_004aa2ec - iVar7);
        CDC::LineTo(this,DAT_004aa1f4,DAT_004aa2f4 - iVar5);
      }
      if ((*(int *)(&DAT_004aa730 + param_2 * 4) == -1) && (param_11 == 0)) {
        FUN_004706bd(this,(int *)&param_3,DAT_004aa1ec,DAT_004aa2ec - iVar7);
        CDC::LineTo(this,DAT_004aa1f4,DAT_004aa2f4 - iVar5);
      }
    }
    DAT_004a72cc = DAT_004aa2e4 - iVar9;
    DAT_004a70fc = DAT_004aa1e4;
    if (DAT_004ac904 == 1) {
      DAT_004a72cc = DAT_004aa2e8 - param_10;
      DAT_004a70fc = DAT_004aa1e8;
    }
    DAT_004a70f4 = DAT_004aa204;
    DAT_004a72c0 = (DAT_004aa304 - param_5) - iVar9;
    FUN_004706bd(this,(int *)&param_3,DAT_004a70fc,DAT_004a72cc);
    CDC::LineTo(this,DAT_004a70f4,DAT_004a72c0);
    uVar3 = param_2;
    if (((DAT_004a7354 < (int)param_6) && ((int)param_2 < 2)) && (DAT_004ac904 != 1)) {
      param_7 = *(undefined **)(*(int *)this + 0x2c);
      (*(code *)param_7)(7);
      DAT_004ac1d8 = ((0x3b < *(int *)(&DAT_004a7bc8 + uVar3 * 4)) - 1 & 0xfffffffe) + 4;
      if ((DAT_004ac900 == 1) && (0x5a < *(int *)(&DAT_004a7bc8 + uVar3 * 4))) {
        DAT_004ac1d8 = 3;
      }
      if (DAT_004ac900 == 0) {
        if (DAT_00491188 < 6) {
          param_9 = DAT_004a70f4;
          param_4 = DAT_004a72c0;
        }
        else {
          param_9 = (DAT_004a70fc + DAT_004a70f4 * 2) / 3;
          param_4 = (DAT_004a72cc + DAT_004a72c0 * 2) / 3;
        }
      }
      else {
        iVar9 = DAT_004a70fc + DAT_004a70f4 * 3;
        param_9 = (int)(iVar9 + (iVar9 >> 0x1f & 3U)) >> 2;
        iVar9 = DAT_004a72cc + DAT_004a72c0 * 3;
        param_4 = (int)(iVar9 + (iVar9 >> 0x1f & 3U)) >> 2;
      }
      pCVar8 = param_1;
      pCVar10 = param_1;
      if (DAT_004ac900 == 0) {
        if (DAT_00491188 < 6) {
          iVar9 = 6;
          param_10 = 0x10;
        }
        else {
          iVar9 = 7;
          param_10 = 0xf;
        }
        param_5 = (uint)(DAT_00491188 >= 6);
        param_2 = (&DAT_004aa2a0)[iVar9];
        param_8 = ((&DAT_004aa1a0)[iVar9] + (&DAT_004aa1a0)[param_5] * 6) / 7;
        piVar1 = &DAT_004aa2a0 + param_5;
        iVar7 = (int)(param_2 + *piVar1 * 6) / 7;
        piVar2 = &DAT_004aa1a0 + param_10;
        param_5 = ((&DAT_004aa1a0)[param_5] * 6 + *piVar2) / 7;
        param_10 = (&DAT_004aa2a0)[param_10];
        iVar5 = (param_10 + *piVar1 * 6) / 7;
        if (*(int *)(&DAT_004aa730 + (int)param_1 * 4) == 1) {
          iVar9 = (param_5 - (&DAT_004aa1a0)[iVar9]) * DAT_004ac1d8;
          iVar5 = (iVar5 - param_2) * DAT_004ac1d8;
          pCVar8 = (CDC *)(((int)(iVar9 + (iVar9 >> 0x1f & 7U)) >> 3) + param_8);
          pCVar10 = (CDC *)(((int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3) + iVar7);
        }
        else {
          iVar9 = (param_8 - *piVar2) * DAT_004ac1d8;
          iVar7 = (iVar7 - param_10) * DAT_004ac1d8;
          pCVar8 = (CDC *)(((int)(iVar9 + (iVar9 >> 0x1f & 7U)) >> 3) + param_5);
          pCVar10 = (CDC *)(((int)(iVar7 + (iVar7 >> 0x1f & 7U)) >> 3) + iVar5);
        }
      }
      if (DAT_004ac900 == 1) {
        param_1 = *(CDC **)(&DAT_004aa730 + (int)param_1 * 4);
        iVar9 = (DAT_004a4880 + DAT_004a4950) / 2;
        iVar7 = (DAT_004a4884 + DAT_004a4df0) / 2;
        if (param_1 == (CDC *)0x1) {
          iVar5 = (DAT_004a4950 - iVar9) * DAT_004ac1d8;
          iVar6 = (DAT_004a4884 - iVar7) * DAT_004ac1d8;
          pCVar8 = (CDC *)(((int)(iVar5 + (iVar5 >> 0x1f & 3U)) >> 2) + iVar9);
          pCVar10 = (CDC *)(((int)(iVar6 + (iVar6 >> 0x1f & 3U)) >> 2) + iVar7);
        }
        if (param_1 == (CDC *)0xffffffff) {
          iVar5 = (DAT_004a4880 - iVar9) * DAT_004ac1d8;
          iVar6 = (DAT_004a4df0 - iVar7) * DAT_004ac1d8;
          pCVar8 = (CDC *)(((int)(iVar5 + (iVar5 >> 0x1f & 3U)) >> 2) + iVar9);
          pCVar10 = (CDC *)(((int)(iVar6 + (iVar6 >> 0x1f & 3U)) >> 2) + iVar7);
        }
      }
      (*(code *)param_6)(4);
      FUN_004706bd(this,(int *)&param_1,param_8,param_3._4_4_);
      CDC::LineTo(this,(int)pCVar8,(int)pCVar10);
      if (DAT_00491188 < 7) {
        FUN_004706bd(this,(int *)&param_1,(DAT_004a70f4 + DAT_004a70fc) / 2,
                     (DAT_004a72cc + DAT_004a72c0) / 2);
        CDC::LineTo(this,(DAT_004aa1a4 + DAT_004aa1a8) / 2,(DAT_004aa2a8 + DAT_004aa2a4) / 2);
      }
      if (DAT_004ac900 == 0) {
        FUN_004706bd(this,(int *)&param_1,(DAT_004a70f4 + DAT_004a70fc * 2) / 3,
                     (DAT_004a72c0 + DAT_004a72cc * 2) / 3);
        CDC::LineTo(this,(&DAT_004aa1a0)[param_3._0_4_],(&DAT_004aa2a0)[param_3._0_4_]);
      }
    }
  }
  return;
}

