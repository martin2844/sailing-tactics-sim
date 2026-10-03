
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00418b80(CDC *param_1,int param_2,uint param_3,undefined4 param_4,int param_5,int param_6,
            int param_7,uint param_8)

{
  int iVar1;
  int iVar2;
  double dVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  code *pcVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  HDC pHVar13;
  HGDIOBJ pvVar14;
  int local_18;
  int local_14;
  int local_8 [2];
  
  pcVar9 = SelectObject_exref;
  if (param_6 <= DAT_004ac13c) {
    return;
  }
  if (DAT_00491188 == 8) {
    return;
  }
  if ((DAT_00491140 < (int)param_3) && (DAT_004ac928 == 1)) {
    return;
  }
  uVar12 = 0x27;
  if (param_2 != 1) {
    uVar12 = param_3;
  }
  if (param_2 == 2) {
    uVar12 = 0x2d;
  }
  if (param_2 == 3) {
    uVar12 = 0x33;
  }
  dVar3 = (double)CONCAT44(param_5,param_4);
  if (DAT_004ac904 == 1) {
    iVar10 = (int)(longlong)(dVar3 + dVar3);
    local_14 = iVar10 / 3;
    local_18 = (iVar10 * 9) / 10;
  }
  else {
    iVar10 = (int)(longlong)(dVar3 * _DAT_00484ff8);
    local_14 = 0;
    local_18 = 0;
  }
  iVar5 = (&DAT_004aa2a4)[uVar12] - iVar10 / 2;
  iVar6 = (&DAT_004aa2a8)[uVar12] - iVar10 / 2;
  uVar4 = (int)param_3 >> 0x1f;
  if (param_2 == 2) {
    if (((DAT_004ac92c == 1) || (((param_3 ^ uVar4) - uVar4 & 1 ^ uVar4) == uVar4)) ||
       (DAT_004ac98c == 1)) {
      if (DAT_004a7354 < param_6) {
        if (DAT_004a3a04 != (HGDIOBJ)0x0) {
          SelectObject(*(HDC *)(param_1 + 4),DAT_004a3a04);
          iVar11 = 4;
          goto LAB_00418f02;
        }
      }
      else if (DAT_004a403c != (HGDIOBJ)0x0) {
        SelectObject(*(HDC *)(param_1 + 4),DAT_004a403c);
      }
      iVar11 = 4;
    }
    else {
      if (DAT_004a7354 < param_6) {
        if (DAT_004abf04 != (HGDIOBJ)0x0) {
          SelectObject(*(HDC *)(param_1 + 4),DAT_004abf04);
          iVar11 = 2;
          goto LAB_00418f02;
        }
      }
      else if (DAT_004a89bc != (HGDIOBJ)0x0) {
        SelectObject(*(HDC *)(param_1 + 4),DAT_004a89bc);
      }
      iVar11 = 2;
    }
  }
  else {
    if (((DAT_004ac92c == 1) || (((param_3 ^ uVar4) - uVar4 & 1 ^ uVar4) == uVar4)) ||
       (DAT_004ac98c == 1)) {
      if (DAT_004a7354 < param_6) {
        if (DAT_004a8a44 != (HGDIOBJ)0x0) {
          pHVar13 = *(HDC *)(param_1 + 4);
          pvVar14 = DAT_004a8a44;
LAB_00418e19:
          SelectObject(pHVar13,pvVar14);
        }
      }
      else if (DAT_004abdbc != (HGDIOBJ)0x0) {
        pHVar13 = *(HDC *)(param_1 + 4);
        pvVar14 = DAT_004abdbc;
        goto LAB_00418e19;
      }
      iVar11 = 3;
    }
    else {
      if (DAT_004a7354 < param_6) {
        if (DAT_004ab9e4 != (HGDIOBJ)0x0) {
          SelectObject(*(HDC *)(param_1 + 4),DAT_004ab9e4);
          iVar11 = 1;
          goto LAB_00418e20;
        }
      }
      else if (DAT_004abbfc != (HGDIOBJ)0x0) {
        SelectObject(*(HDC *)(param_1 + 4),DAT_004abbfc);
      }
      iVar11 = 1;
    }
LAB_00418e20:
    if (DAT_004ac92c == 0) {
      if ((((int)param_3 % 3 == 0) && (DAT_004ac98c == 0)) && (DAT_004ac904 == 0)) {
        if (DAT_004a7354 < param_6) {
          if (DAT_004a6794 != (HGDIOBJ)0x0) {
            pHVar13 = *(HDC *)(param_1 + 4);
            pvVar14 = DAT_004a6794;
LAB_00418e92:
            SelectObject(pHVar13,pvVar14);
          }
        }
        else if (DAT_004ab15c != (HGDIOBJ)0x0) {
          pHVar13 = *(HDC *)(param_1 + 4);
          pvVar14 = DAT_004ab15c;
          goto LAB_00418e92;
        }
        iVar11 = 5;
      }
      if (((DAT_004ac92c == 0) && (DAT_004ac904 == 1)) && (param_3 == 1)) {
        if (DAT_004a7354 < param_6) {
          if (DAT_004a6794 != (HGDIOBJ)0x0) {
            pHVar13 = *(HDC *)(param_1 + 4);
            pvVar14 = DAT_004a6794;
LAB_00418efb:
            SelectObject(pHVar13,pvVar14);
          }
        }
        else if (DAT_004ab15c != (HGDIOBJ)0x0) {
          pHVar13 = *(HDC *)(param_1 + 4);
          pvVar14 = DAT_004ab15c;
          goto LAB_00418efb;
        }
        iVar11 = 5;
      }
    }
  }
LAB_00418f02:
  FUN_004706bd(param_1,local_8,(&DAT_004aa1a0)[uVar12],(&DAT_004aa2a0)[uVar12] - local_14);
  CDC::LineTo(param_1,(&DAT_004aa1a4)[uVar12],(&DAT_004aa2a4)[uVar12] - iVar10);
  CDC::LineTo(param_1,(&DAT_004aa1a8)[uVar12],(&DAT_004aa2a8)[uVar12] - iVar10);
  CDC::LineTo(param_1,(&DAT_004aa1ac)[uVar12],(&DAT_004aa2ac)[uVar12] - local_14);
  FUN_004706bd(param_1,local_8,(&DAT_004aa1a0)[uVar12],(&DAT_004aa2a0)[uVar12] - local_14);
  if ((DAT_004a7354 < param_6) || (pcVar9 = SelectObject_exref, param_3 == 1)) {
    if ((iVar11 == 2) && (DAT_004a89bc != (HGDIOBJ)0x0)) {
      (*pcVar9)(*(HDC *)(param_1 + 4),DAT_004a89bc);
    }
    if ((iVar11 == 1) && (DAT_004abbfc != (HGDIOBJ)0x0)) {
      (*pcVar9)(*(HDC *)(param_1 + 4),DAT_004abbfc);
    }
    if ((iVar11 == 4) && (DAT_004a403c != (HGDIOBJ)0x0)) {
      (*pcVar9)(*(HDC *)(param_1 + 4),DAT_004a403c);
    }
    if ((iVar11 == 3) && (DAT_004abdbc != (HGDIOBJ)0x0)) {
      (*pcVar9)(*(HDC *)(param_1 + 4),DAT_004abdbc);
    }
    if ((iVar11 == 5) && (DAT_004ab15c != (HGDIOBJ)0x0)) {
      (*pcVar9)(*(HDC *)(param_1 + 4),DAT_004ab15c);
    }
    if (((param_2 < 2) || (DAT_00491188 != 7)) || (param_7 != 1)) {
      iVar11 = 0;
    }
    else {
      iVar11 = (iVar10 * 3) / 2;
    }
    FUN_004706bd(param_1,local_8,(&DAT_004aa1a0)[uVar12],(&DAT_004aa2a0)[uVar12] - local_14);
    CDC::LineTo(param_1,(&DAT_004aa1b0)[uVar12],iVar11 + (&DAT_004aa2b0)[uVar12]);
    FUN_004706bd(param_1,local_8,(&DAT_004aa1ac)[uVar12],(&DAT_004aa2ac)[uVar12] - local_14);
    CDC::LineTo(param_1,(&DAT_004aa1b4)[uVar12],iVar11 + (&DAT_004aa2b4)[uVar12]);
    if ((DAT_004ac904 == 0) && ((param_2 == 1 || (DAT_00491188 < 7)))) {
      iVar11 = *(int *)(&DAT_004aa730 + param_3 * 4);
      if (DAT_004a4dec != (HGDIOBJ)0x0) {
        SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
      }
      uVar4 = iVar11 * -0x5a - param_8;
      uVar8 = (int)uVar4 >> 0x1f;
      iVar11 = (uVar4 ^ uVar8) - uVar8;
      if (((iVar11 < 0x32) || ((int)param_8 < -0x96)) || (0x96 < (int)param_8)) {
        iVar7 = (&DAT_004aa1a4)[uVar12];
        iVar1 = (&DAT_004aa1b0)[uVar12];
        iVar2 = (&DAT_004aa2b0)[uVar12];
        FUN_004706bd(param_1,local_8,iVar7,iVar5);
        CDC::LineTo(param_1,(iVar7 + iVar1 * 2) / 3,(iVar5 + iVar2 * 2) / 3);
      }
      if ((iVar11 < 0x5a) ||
         ((int)((param_8 ^ (int)param_8 >> 0x1f) - ((int)param_8 >> 0x1f)) <
          (int)((-(uint)(param_2 != 1) & 0xffffffdd) + 0x37))) {
        iVar5 = ((&DAT_004aa1a8)[uVar12] + (&DAT_004aa1b4)[uVar12] * 2) / 3;
        iVar11 = (iVar6 + (&DAT_004aa2b4)[uVar12] * 2) / 3;
        FUN_004706bd(param_1,local_8,(&DAT_004aa1a8)[uVar12],iVar6);
        CDC::LineTo(param_1,iVar5,iVar11);
        if ((param_2 == 1) && ((DAT_0049114c < 1 && (DAT_004ac904 == 0)))) {
          FUN_004706bd(param_1,local_8,DAT_004aa708,DAT_004abe68);
          CDC::LineTo(param_1,iVar5,iVar11);
        }
      }
    }
    if (DAT_004ac904 == 1) {
      iVar11 = DAT_004a70f4 * 4;
      iVar5 = DAT_004a70fc * 6;
      iVar7 = DAT_004a72c0 * 4;
      iVar6 = DAT_004a72cc * 6;
      FUN_004706bd(param_1,local_8,(&DAT_004aa1a4)[uVar12],(&DAT_004aa2a4)[uVar12] - iVar10);
      CDC::LineTo(param_1,(iVar11 + iVar5) / 10,(iVar7 + iVar6) / 10);
      iVar7 = DAT_004a70f4 * 6;
      iVar5 = DAT_004a70fc * 4;
      iVar11 = DAT_004a72cc * 4;
      iVar6 = DAT_004a72c0 * 6;
      FUN_004706bd(param_1,local_8,(&DAT_004aa1a8)[uVar12],(&DAT_004aa2a8)[uVar12] - iVar10);
      CDC::LineTo(param_1,(iVar7 + iVar5) / 10,(iVar11 + iVar6) / 10);
    }
  }
  (**(code **)(*(int *)param_1 + 0x2c))(param_1,7);
  iVar10 = 1 - (int)(longlong)((double)CONCAT44(param_5,param_4) * _DAT_00485060);
  if (iVar10 < 3) {
    iVar10 = 3;
  }
  if ((DAT_00491188 == 1) && (iVar10 = iVar10 + 1, DAT_004ac904 == 0)) {
    local_18 = local_18 + -1;
  }
  if (param_6 < DAT_004a7354) {
    iVar10 = iVar10 + -1;
    local_18 = local_18 + -1;
  }
  iVar5 = (int)((&DAT_004aa1a8)[uVar12] + (&DAT_004aa1a4)[uVar12]) / 2;
  iVar6 = (int)((&DAT_004aa2a8)[uVar12] + (&DAT_004aa2a4)[uVar12]) / 2;
  if ((DAT_004ac92c == 0) && (DAT_004ac98c == 0)) {
    if (DAT_004ab17c == (HGDIOBJ)0x0) goto LAB_0041947f;
    pHVar13 = *(HDC *)(param_1 + 4);
    pvVar14 = DAT_004ab17c;
  }
  else {
    if (DAT_004a3efc == (HGDIOBJ)0x0) goto LAB_0041947f;
    pHVar13 = *(HDC *)(param_1 + 4);
    pvVar14 = DAT_004a3efc;
  }
  SelectObject(pHVar13,pvVar14);
LAB_0041947f:
  Ellipse(*(HDC *)(param_1 + 4),iVar5 - iVar10,(iVar6 + iVar10 * -3) - local_18,iVar10 + iVar5,
          (iVar6 - local_18) - iVar10);
  return;
}

