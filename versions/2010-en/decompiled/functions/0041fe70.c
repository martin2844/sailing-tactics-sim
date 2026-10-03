
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_0041fe70(int *param_1,int param_2,double param_3,int param_4,int param_5,int param_6,
            double param_7,int param_8,int param_9,int param_10)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar4 = param_9;
  iVar8 = param_8;
  iVar7 = param_6;
  param_3 = param_3 * _DAT_004cc828;
  if (DAT_004da190 == 8) {
    param_3 = param_3 * _DAT_004cc830;
  }
  if (((DAT_005363b8 == 1) || (DAT_005364bc == 1)) || (DAT_00536528 == 1)) {
    param_3 = param_3 * _DAT_004cc630;
  }
  if (DAT_0053652c == 1) {
    param_3 = param_3 * _DAT_004cc468;
  }
  if (DAT_005363cc == 1) {
    param_3 = param_3 * _DAT_004cc600;
  }
  if (DAT_00536530 == 1) {
    param_3 = param_3 * _DAT_004cc600;
  }
  param_5 = (int)(longlong)((double)param_5 * param_7) / 3;
  if (DAT_005363bc == 1) {
    param_5 = param_5 + (int)(longlong)(param_3 * _DAT_004cc618);
  }
  if (((param_2 == 1) || (DAT_00536450 == 1)) || (0 < DAT_00536458)) {
    FUN_00420920(param_1,DAT_00522934,DAT_00522a34 - (int)(longlong)(param_3 * _DAT_004cc6b0),
                 param_2,param_8,param_6,param_9);
  }
  if (param_2 == 2) {
    if ((DAT_004da140 == 2) && (DAT_00536450 == 0)) {
      FUN_00420920(param_1,DAT_00522934,DAT_00522a34 - (int)(longlong)(param_3 * _DAT_004cc6b0),2,
                   iVar8,iVar7,iVar4);
    }
    if (((DAT_004da140 == 1) && (DAT_00536450 == 0)) && (DAT_004da194 == 2)) {
      FUN_00420920(param_1,DAT_00522934,DAT_00522a34 - (int)(longlong)(param_3 * _DAT_004cc6b0),2,
                   iVar8,iVar7,iVar4);
    }
  }
  if (DAT_004fe33c < iVar7) {
    if (DAT_004f7084 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004f7084);
    }
  }
  else {
    (**(code **)(*param_1 + 0x2c))(param_1,7);
  }
  iVar8 = param_4;
  FUN_004b4d9d(param_1,(int *)&param_7,(&DAT_005228e0)[param_4],(&DAT_005229e0)[param_4]);
  param_9 = (int)(longlong)(param_3 * _DAT_004cc638);
  CDC::LineTo(param_1,DAT_00522924,DAT_00522a24 - param_9);
  param_8 = (int)(longlong)(param_3 * _DAT_004cc660);
  CDC::LineTo(param_1,DAT_00522928,DAT_00522a28 - param_8);
  iVar7 = (int)(longlong)(param_3 * _DAT_004cc4f8);
  CDC::LineTo(param_1,DAT_0052292c,DAT_00522a2c - iVar7);
  CDC::LineTo(param_1,DAT_00522930,DAT_00522a30 - (int)(longlong)(param_3 * _DAT_004cc738));
  if (DAT_005363cc == 1) {
    (**(code **)(*param_1 + 0x2c))(param_1,6);
  }
  iVar4 = (int)(longlong)(param_3 * _DAT_004cc6b0);
  CDC::LineTo(param_1,DAT_00522934,DAT_00522a34 - iVar4);
  if (DAT_004f7084 != (HGDIOBJ)0x0) {
    SelectObject((HDC)param_1[1],DAT_004f7084);
  }
  if (DAT_00535884 <= param_6) {
    if (DAT_005364c8 == 1) {
      (**(code **)(*param_1 + 0x2c))(param_1,6);
      FUN_004b4d9d(param_1,(int *)&param_7,DAT_005228f8,DAT_005229f8);
      CDC::LineTo(param_1,(DAT_005228f8 + DAT_00522924) - (&DAT_005228e0)[iVar8],
                  ((DAT_005229f8 - (int)(longlong)(param_3 * _DAT_004cc638)) + DAT_00522a24) -
                  (&DAT_005229e0)[iVar8]);
    }
    iVar8 = param_10;
    if (DAT_005363cc == 1) {
      if ((*(int *)(&DAT_00522ff0 + param_2 * 4) == 1) && (param_10 == 1)) {
        FUN_004b4d9d(param_1,(int *)&param_7,DAT_0052292c,DAT_00522a2c - iVar7);
        CDC::LineTo(param_1,DAT_00522934,DAT_00522a34 - iVar4);
      }
      if ((*(int *)(&DAT_00522ff0 + param_2 * 4) == -1) && (iVar8 == 0)) {
        FUN_004b4d9d(param_1,(int *)&param_7,DAT_0052292c,DAT_00522a2c - iVar7);
        CDC::LineTo(param_1,DAT_00522934,DAT_00522a34 - iVar4);
      }
    }
    if ((((((DAT_005364bc == 1) || (DAT_004da190 == 10)) || (DAT_004da190 == 8)) ||
         ((DAT_005364cc == 1 || (DAT_004da190 == 9)))) || (DAT_00536528 == 1)) ||
       (iVar7 = param_9, DAT_0053652c == 1)) {
      iVar7 = (int)(longlong)(param_3 * _DAT_004cc440);
    }
    DAT_004fe2a4 = DAT_00522a24 - iVar7;
    DAT_004fe098 = DAT_00522924;
    if (DAT_005363bc == 1) {
      DAT_004fe2a4 = DAT_00522a28 - param_8;
      DAT_004fe098 = DAT_00522928;
    }
    DAT_004fe090 = DAT_00522944;
    DAT_004fe298 = (DAT_00522a44 - param_5) - param_9;
    if ((((DAT_005364bc == 1) || (DAT_004da190 == 10)) ||
        ((DAT_004da190 == 8 || (((DAT_005364cc == 1 || (DAT_004da190 == 9)) || (DAT_00536528 == 1)))
         ))) || (DAT_0053652c == 1)) {
      DAT_004fe298 = (DAT_00522a44 - (int)(longlong)(param_3 * _DAT_004cc440)) - param_5;
    }
    FUN_004b4d9d(param_1,(int *)&param_3,DAT_004fe098,DAT_004fe2a4);
    CDC::LineTo(param_1,DAT_004fe090,DAT_004fe298);
    if (((DAT_004fe33c < param_6) && (iVar7 = 1, param_2 < 2)) && (DAT_005363bc != 1)) {
      pcVar1 = *(code **)(*param_1 + 0x2c);
      (*pcVar1)(param_1,7);
      DAT_005359cc = ((0x3b < *(int *)(&DAT_004fecc8 + param_2 * 4)) - 1 & 0xfffffffe) + 4;
      if (DAT_00536530 == 1) {
        DAT_005359cc = 1;
      }
      if ((DAT_005363b8 == 1) && (0x5a < *(int *)(&DAT_004fecc8 + param_2 * 4))) {
        DAT_005359cc = 3;
      }
      if (DAT_005363b8 == 0) {
        param_10 = DAT_004fe298;
        iVar8 = DAT_004fe090;
        if (((5 < DAT_004da190) && (DAT_004fb410 == 0)) && (DAT_00536528 == 0)) {
          param_10 = (DAT_004fe2a4 + DAT_004fe298 * 2) / 3;
          iVar8 = (DAT_004fe098 + DAT_004fe090 * 2) / 3;
        }
      }
      else {
        iVar8 = DAT_004fe098 + DAT_004fe090 * 3;
        iVar4 = DAT_004fe2a4 + DAT_004fe298 * 3;
        param_10 = (int)(iVar4 + (iVar4 >> 0x1f & 3U)) >> 2;
        iVar8 = (int)(iVar8 + (iVar8 >> 0x1f & 3U)) >> 2;
      }
      param_3 = (double)CONCAT44(param_3._4_4_,iVar8);
      iVar8 = param_2;
      iVar4 = param_2;
      if (DAT_005363b8 == 0) {
        if ((DAT_004da190 < 6) || (DAT_004fb410 != 0)) {
          iVar8 = 6;
          iVar7 = 0;
          param_5 = 0x10;
        }
        else {
          iVar8 = 7;
          param_5 = 0xf;
        }
        iVar6 = (&DAT_005228e0)[iVar8];
        param_6 = (iVar6 + (&DAT_005228e0)[iVar7] * 6) / 7;
        iVar2 = (&DAT_005229e0)[iVar8];
        param_9 = (iVar2 + (&DAT_005229e0)[iVar7] * 6) / 7;
        param_7._0_4_ = (&DAT_005228e0)[param_5];
        iVar5 = ((&DAT_005228e0)[iVar7] * 6 + param_7._0_4_) / 7;
        iVar3 = (&DAT_005229e0)[param_5];
        param_8 = (iVar3 + (&DAT_005229e0)[iVar7] * 6) / 7;
        if (*(int *)(&DAT_00522ff0 + param_2 * 4) == 1) {
          iVar7 = (iVar5 - iVar6) * DAT_005359cc;
          iVar8 = ((int)(iVar7 + (iVar7 >> 0x1f & 7U)) >> 3) + param_6;
          iVar4 = (param_8 - iVar2) * DAT_005359cc;
          iVar4 = iVar4 + (iVar4 >> 0x1f & 7U);
          iVar7 = param_9;
        }
        else {
          iVar7 = (param_6 - param_7._0_4_) * DAT_005359cc;
          iVar8 = ((int)(iVar7 + (iVar7 >> 0x1f & 7U)) >> 3) + iVar5;
          iVar4 = (param_9 - iVar3) * DAT_005359cc;
          iVar4 = iVar4 + (iVar4 >> 0x1f & 7U);
          iVar7 = param_8;
        }
        iVar4 = (iVar4 >> 3) + iVar7;
        param_5 = iVar5;
        if (DAT_00536528 == 1) {
          if (*(int *)(&DAT_00522ff0 + param_2 * 4) == 1) {
            iVar4 = (param_8 - iVar2) * (DAT_005359cc / 2);
            iVar5 = ((iVar5 - iVar6) * (DAT_005359cc / 2)) / 2 + param_6;
            iVar7 = param_9;
          }
          else {
            iVar4 = (param_9 - iVar3) * (DAT_005359cc / 2);
            iVar5 = ((param_6 - param_7._0_4_) * (DAT_005359cc / 2)) / 2 + iVar5;
            iVar7 = param_8;
          }
          iVar8 = (iVar5 + DAT_005228e0) / 2;
          iVar4 = (DAT_005229e0 + iVar4 / 2 + iVar7) / 2;
        }
      }
      if (DAT_005363b8 == 1) {
        iVar7 = (DAT_004f4d70 + DAT_004f69b0) / 2;
        iVar6 = (DAT_004f7088 + DAT_004f4d74) / 2;
        if (*(int *)(&DAT_00522ff0 + param_2 * 4) == 1) {
          iVar8 = (DAT_004f69b0 - iVar7) * DAT_005359cc;
          iVar4 = (DAT_004f4d74 - iVar6) * DAT_005359cc;
          iVar8 = ((int)(iVar8 + (iVar8 >> 0x1f & 3U)) >> 2) + iVar7;
          iVar4 = ((int)(iVar4 + (iVar4 >> 0x1f & 3U)) >> 2) + iVar6;
        }
        if (*(int *)(&DAT_00522ff0 + param_2 * 4) == -1) {
          iVar8 = (DAT_004f4d70 - iVar7) * DAT_005359cc;
          iVar4 = (DAT_004f7088 - iVar6) * DAT_005359cc;
          iVar8 = ((int)(iVar8 + (iVar8 >> 0x1f & 3U)) >> 2) + iVar7;
          iVar4 = ((int)(iVar4 + (iVar4 >> 0x1f & 3U)) >> 2) + iVar6;
        }
        if (DAT_005364c0 == 1) {
          iVar8 = iVar7;
          iVar4 = iVar6;
        }
      }
      if (DAT_00536458 == 0) {
        (*pcVar1)(param_1,4);
        FUN_004b4d9d(param_1,(int *)&param_3,param_3._0_4_,param_10);
        CDC::LineTo(param_1,iVar8,iVar4);
        if (DAT_004da190 < 7) {
          FUN_004b4d9d(param_1,(int *)&param_3,(DAT_004fe090 + DAT_004fe098) / 2,
                       (DAT_004fe2a4 + DAT_004fe298) / 2);
          CDC::LineTo(param_1,(DAT_005228e4 + DAT_005228e8) / 2,(DAT_005229e8 + DAT_005229e4) / 2);
        }
        if (DAT_005363b8 == 0) {
          FUN_004b4d9d(param_1,(int *)&param_3,(DAT_004fe090 + DAT_004fe098 * 2) / 3,
                       (DAT_004fe298 + DAT_004fe2a4 * 2) / 3);
          CDC::LineTo(param_1,(&DAT_005228e0)[param_4],(&DAT_005229e0)[param_4]);
        }
      }
    }
  }
  return;
}

