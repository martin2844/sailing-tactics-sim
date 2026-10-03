
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00445370(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  HDC pHVar8;
  HGDIOBJ pvVar9;
  int local_2c [6];
  int local_14 [5];
  
  iVar5 = param_2;
  if (DAT_00536450 == 1) {
    return;
  }
  FUN_0043e730(0,(double)CONCAT44(*(undefined4 *)(&DAT_00535464 + param_2 * 8),
                                  *(undefined4 *)(&DAT_00535460 + param_2 * 8)),
               (double)CONCAT44(*(undefined4 *)(&DAT_004f4b0c + param_2 * 8),
                                *(undefined4 *)(&DAT_004f4b08 + param_2 * 8)),param_3,0);
  iVar1 = DAT_00523660;
  if (DAT_004fed58 < param_4 - (param_6 - param_4)) {
    return;
  }
  if ((param_6 - param_4) + param_6 < DAT_004fed58) {
    return;
  }
  if (param_7 < DAT_00523660) {
    return;
  }
  FUN_0043e730(0,*(double *)(&DAT_00535460 + param_2 * 8) -
                 (double)*(int *)(&DAT_004f7ea0 + param_2 * 4),
               (double)CONCAT44(*(undefined4 *)(&DAT_004f4b0c + param_2 * 8),
                                *(undefined4 *)(&DAT_004f4b08 + param_2 * 8)),param_3,0);
  local_2c[0] = DAT_004fed58;
  local_14[0] = DAT_00523660;
  FUN_0043e730(0,(double)CONCAT44(*(undefined4 *)(&DAT_00535464 + param_2 * 8),
                                  *(undefined4 *)(&DAT_00535460 + param_2 * 8)),
               *(double *)(&DAT_004f4b08 + param_2 * 8) -
               (double)*(int *)(&DAT_004f7ea0 + param_2 * 4),param_3,0);
  local_2c[1] = DAT_004fed58;
  local_14[1] = DAT_00523660;
  FUN_0043e730(0,(double)*(int *)(&DAT_004f7ea0 + param_2 * 4) +
                 *(double *)(&DAT_00535460 + param_2 * 8),
               (double)CONCAT44(*(undefined4 *)(&DAT_004f4b0c + param_2 * 8),
                                *(undefined4 *)(&DAT_004f4b08 + param_2 * 8)),param_3,0);
  local_2c[2] = DAT_004fed58;
  local_14[2] = DAT_00523660;
  FUN_0043e730(0,(double)CONCAT44(*(undefined4 *)(&DAT_00535464 + param_2 * 8),
                                  *(undefined4 *)(&DAT_00535460 + param_2 * 8)),
               (double)*(int *)(&DAT_004f7ea0 + param_2 * 4) +
               *(double *)(&DAT_004f4b08 + param_2 * 8),param_3,0);
  iVar6 = 2000;
  local_14[3] = DAT_00523660;
  local_2c[3] = DAT_004fed58;
  param_2 = 2000;
  piVar7 = local_2c;
  iVar2 = 4;
  do {
    iVar3 = *piVar7;
    if (iVar3 < iVar6) {
      iVar6 = iVar3;
      param_2 = iVar3;
    }
    piVar7 = piVar7 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if (param_6 + DAT_004fe624 / 2 < iVar6) {
    return;
  }
  iVar6 = -2000;
  piVar7 = local_2c;
  param_6 = -2000;
  iVar2 = 4;
  do {
    iVar3 = *piVar7;
    if (iVar6 < iVar3) {
      iVar6 = iVar3;
      param_6 = iVar3;
    }
    piVar7 = piVar7 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if (iVar6 < param_4 - DAT_004fe624 / 2) {
    return;
  }
  iVar2 = 2000;
  piVar7 = local_14;
  param_4 = 2000;
  iVar3 = 4;
  do {
    iVar4 = *piVar7;
    if (iVar4 < iVar2) {
      iVar2 = iVar4;
      param_4 = iVar4;
    }
    piVar7 = piVar7 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if (param_7 < iVar2) {
    return;
  }
  iVar3 = -2000;
  piVar7 = local_14;
  iVar4 = 4;
  do {
    if (iVar3 < *piVar7) {
      iVar3 = *piVar7;
    }
    piVar7 = piVar7 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  if (param_7 + DAT_004fe2a8 < iVar3) {
    iVar3 = param_7 + DAT_004fe2a8;
  }
  if (param_2 < -DAT_004fe624) {
    param_2 = -DAT_004fe624;
  }
  if (DAT_004fe624 * 2 < iVar6) {
    param_6 = DAT_004fe624 * 2;
  }
  (**(code **)(*param_1 + 0x2c))(param_1,8);
  if (DAT_0052362c < 9) {
    if (DAT_005231a4 != (HGDIOBJ)0x0) {
      pHVar8 = (HDC)param_1[1];
      pvVar9 = DAT_005231a4;
override_prt_445638_6059bb06:
      SelectObject(pHVar8,pvVar9);
    }
  }
  else if (DAT_005359b4 != (HGDIOBJ)0x0) {
    pHVar8 = (HDC)param_1[1];
    pvVar9 = DAT_005359b4;
    goto override_prt_445638_6059bb06;
  }
  if ((((*(int *)(&DAT_004f71c0 + param_3 * 4) < 3) && (DAT_005363e4 == 0)) &&
      (DAT_004da1f8 != 0x6a)) && ((DAT_004da1f8 != 0x69 && (DAT_00536524 != 1)))) {
    Ellipse((HDC)param_1[1],param_2,iVar2,param_6,iVar3);
  }
  iVar6 = DAT_004da148 + 0xf;
  iVar5 = (int)(longlong)
               ((((double)(iVar1 - DAT_004da148) * _DAT_004cc980) / (double)(param_7 - DAT_004da148)
                ) * (double)*(int *)(&DAT_004f7ea0 + iVar5 * 4)) / 2;
  if (0x46 < iVar5) {
    iVar5 = 0x46;
  }
  if (DAT_004da174 < 0xb) {
    iVar5 = iVar5 * 2;
  }
  if (200 < iVar5) {
    iVar5 = 200;
  }
  if (DAT_005363e4 == 0) {
    if (((DAT_004da1f8 == 0x6a) || (DAT_004da1f8 == 0x69)) ||
       ((DAT_00536524 == 1 && (DAT_004da1f8 == 999)))) {
      if (DAT_004fb9a4 == (HGDIOBJ)0x0) goto LAB_00445779;
      pHVar8 = (HDC)param_1[1];
      pvVar9 = DAT_004fb9a4;
    }
    else {
      if (DAT_004fe80c == (HGDIOBJ)0x0) goto LAB_00445779;
      pHVar8 = (HDC)param_1[1];
      pvVar9 = DAT_004fe80c;
    }
  }
  else {
    if (DAT_004f7084 == (HGDIOBJ)0x0) goto LAB_00445779;
    pHVar8 = (HDC)param_1[1];
    pvVar9 = DAT_004f7084;
  }
  SelectObject(pHVar8,pvVar9);
LAB_00445779:
  if (param_4 < DAT_00535564) {
    param_7 = 1;
    if (0 < iVar5 / 2) {
      piVar7 = &DAT_00512d78;
      do {
        if (param_7 % 5 == 0) {
          iVar1 = FUN_0041e000(param_6 - param_2);
          iVar2 = FUN_0041e000(iVar3 - param_4);
        }
        else {
          iVar1 = (piVar7[-1] * (param_6 - param_2)) / 100;
          iVar2 = ((iVar3 - param_4) * *piVar7) / 100;
        }
        if (iVar6 < iVar2 + param_4) {
          FUN_00424320(param_1,iVar1 + param_2,iVar2 + param_4,1);
        }
        param_7 = param_7 + 1;
        piVar7 = piVar7 + 1;
      } while (param_7 <= iVar5 / 2);
    }
  }
  return;
}

