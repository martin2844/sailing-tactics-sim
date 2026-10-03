
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00431b30(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int unaff_EBX;
  int *piVar6;
  CDC *unaff_retaddr;
  HDC pHVar7;
  HGDIOBJ pvVar8;
  int local_34;
  int local_24 [5];
  int local_10 [4];
  
  iVar1 = param_2;
  if (DAT_004ac98c == 1) {
    return;
  }
  FUN_0042bfc0(0,(double)CONCAT44(*(undefined4 *)(&DAT_004abd8c + param_2 * 8),
                                  *(undefined4 *)(&DAT_004abd88 + param_2 * 8)),
               (double)CONCAT44(*(undefined4 *)(&DAT_004a472c + param_2 * 8),
                                *(undefined4 *)(&DAT_004a4728 + param_2 * 8)),param_3,0);
  iVar2 = DAT_004aaa48;
  iVar3 = (param_6 - param_4) / 2;
  if (DAT_004a7c48 < param_4 - iVar3) {
    return;
  }
  if (iVar3 + param_6 < DAT_004a7c48) {
    return;
  }
  if ((param_7 - param_5) / 2 + param_7 < DAT_004aaa48) {
    return;
  }
  FUN_0042bfc0(0,*(double *)(&DAT_004abd88 + param_2 * 8) -
                 (double)*(int *)(&DAT_004a4ec0 + param_2 * 4),
               (double)CONCAT44(*(undefined4 *)(&DAT_004a472c + param_2 * 8),
                                *(undefined4 *)(&DAT_004a4728 + param_2 * 8)),param_3,0);
  local_24[0] = DAT_004a7c48;
  local_10[0] = DAT_004aaa48;
  FUN_0042bfc0(0,(double)CONCAT44(*(undefined4 *)(&DAT_004abd8c + param_2 * 8),
                                  *(undefined4 *)(&DAT_004abd88 + param_2 * 8)),
               *(double *)(&DAT_004a4728 + param_2 * 8) -
               (double)*(int *)(&DAT_004a4ec0 + param_2 * 4),param_3,0);
  local_24[1] = DAT_004a7c48;
  local_10[1] = DAT_004aaa48;
  FUN_0042bfc0(0,(double)*(int *)(&DAT_004a4ec0 + param_2 * 4) +
                 *(double *)(&DAT_004abd88 + param_2 * 8),
               (double)CONCAT44(*(undefined4 *)(&DAT_004a472c + param_2 * 8),
                                *(undefined4 *)(&DAT_004a4728 + param_2 * 8)),param_3,0);
  local_24[2] = DAT_004a7c48;
  local_10[2] = DAT_004aaa48;
  FUN_0042bfc0(0,(double)CONCAT44(*(undefined4 *)(&DAT_004abd8c + param_2 * 8),
                                  *(undefined4 *)(&DAT_004abd88 + param_2 * 8)),
               (double)*(int *)(&DAT_004a4ec0 + param_2 * 4) +
               *(double *)(&DAT_004a4728 + param_2 * 8),param_3,0);
  iVar3 = 2000;
  local_24[3] = DAT_004a7c48;
  local_10[3] = DAT_004aaa48;
  param_2 = 2000;
  piVar6 = local_24;
  iVar4 = 4;
  do {
    iVar5 = *piVar6;
    if (iVar5 < iVar3) {
      iVar3 = iVar5;
      param_2 = iVar5;
    }
    piVar6 = piVar6 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  if (param_6 < iVar3) {
    return;
  }
  iVar3 = -2000;
  piVar6 = local_24;
  param_5 = -2000;
  iVar4 = 4;
  do {
    iVar5 = *piVar6;
    if (iVar3 < iVar5) {
      iVar3 = iVar5;
      param_5 = iVar5;
    }
    piVar6 = piVar6 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  if (iVar3 < param_4) {
    return;
  }
  iVar3 = 2000;
  piVar6 = local_10;
  local_34 = 2000;
  iVar4 = 4;
  do {
    iVar5 = *piVar6;
    if (iVar5 < iVar3) {
      iVar3 = iVar5;
      local_34 = iVar5;
    }
    piVar6 = piVar6 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  if (param_7 < iVar3) {
    return;
  }
  iVar4 = -2000;
  piVar6 = local_10;
  iVar5 = 4;
  do {
    if (iVar4 < *piVar6) {
      iVar4 = *piVar6;
    }
    piVar6 = piVar6 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  if (param_7 < iVar4) {
    iVar4 = param_7;
  }
  if (param_2 < -DAT_004a763c) {
    param_2 = -DAT_004a763c;
  }
  if (DAT_004a763c * 2 < param_5) {
    param_5 = DAT_004a763c * 2;
  }
  (**(code **)(*param_1 + 0x2c))(8);
  if (DAT_004aaa1c < 9) {
    if (DAT_004aa82c != (HGDIOBJ)0x0) {
      pHVar7 = (HDC)param_1[1];
      pvVar8 = DAT_004aa82c;
LAB_00431e09:
      SelectObject(pHVar7,pvVar8);
    }
  }
  else if (DAT_004ac1cc != (HGDIOBJ)0x0) {
    pHVar7 = (HDC)param_1[1];
    pvVar8 = DAT_004ac1cc;
    goto LAB_00431e09;
  }
  if ((*(int *)(&DAT_004a4e88 + param_2 * 4) < 3) && (DAT_004ac92c == 0)) {
    Ellipse((HDC)param_1[1],(int)param_1,iVar3,param_4,iVar4);
  }
  iVar1 = (int)(longlong)
               ((((double)(local_34 - DAT_00491148) * _DAT_00484cf0) /
                (double)(param_6 - DAT_00491148)) * (double)*(int *)(&DAT_004a4ec0 + iVar1 * 4));
  iVar3 = iVar1 / 0x1e;
  iVar5 = DAT_00491148 + 0xf;
  if (iVar2 < param_3 - iVar3) {
    return;
  }
  if (param_5 + iVar3 < iVar2) {
    return;
  }
  if (param_6 + iVar3 < local_34) {
    return;
  }
  param_3 = iVar1 / 2;
  if (0x46 < param_3) {
    param_3 = 0x46;
  }
  if (DAT_004ac92c == 0) {
    if (DAT_004ab9cc == (HGDIOBJ)0x0) goto LAB_00431f31;
    pHVar7 = (HDC)param_1[1];
    pvVar8 = DAT_004ab9cc;
  }
  else {
    if (DAT_004a4dec == (HGDIOBJ)0x0) goto LAB_00431f31;
    pHVar7 = (HDC)param_1[1];
    pvVar8 = DAT_004a4dec;
  }
  SelectObject(pHVar7,pvVar8);
LAB_00431f31:
  param_6 = 1;
  if (0 < param_3) {
    piVar6 = &DAT_004a9458;
    do {
      if (param_6 % 5 == 0) {
        iVar1 = FUN_00415a20(param_4 - (int)param_1);
        iVar2 = FUN_00415a20(iVar4 - unaff_EBX);
      }
      else {
        iVar1 = (piVar6[-1] * (param_4 - (int)param_1)) / 100;
        iVar2 = ((iVar4 - unaff_EBX) * *piVar6) / 100;
      }
      if (iVar5 < iVar2 + unaff_EBX) {
        FUN_00419d50(unaff_retaddr,iVar1 + (int)param_1,iVar2 + unaff_EBX,1);
      }
      param_6 = param_6 + 1;
      piVar6 = piVar6 + 1;
    } while (param_6 <= param_3);
  }
  return;
}

