
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00418b80(CDC *param_1,int param_2,uint param_3,undefined4 param_4,int param_5,int param_6,
            int param_7,uint param_8)

{
  int iVar1;
  double dVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  code *pcVar8;
  int iVar9;
  uint uVar10;
  HDC pHVar11;
  HGDIOBJ pvVar12;
  int local_1c;
  int local_14;
  int local_8 [2];
  
  pcVar8 = SelectObject_exref;
  if (param_6 <= DAT_004ac13c) {
    return;
  }
  if (DAT_00491188 == 8) {
    return;
  }
  if ((DAT_00491140 < (int)param_3) && (DAT_004ac928 == 1)) {
    return;
  }
  uVar10 = 0x27;
  if (param_2 != 1) {
    uVar10 = param_3;
  }
  if (param_2 == 2) {
    uVar10 = 0x2d;
  }
  if (param_2 == 3) {
    uVar10 = 0x33;
  }
  dVar2 = (double)CONCAT44(param_5,param_4);
  if (DAT_004ac904 == 1) {
    local_1c = (int)(longlong)(dVar2 + dVar2);
    local_14 = local_1c / 3;
  }
  else {
    local_1c = (int)(longlong)(dVar2 * _DAT_00484ff8);
    local_14 = 0;
  }
  iVar4 = (&DAT_004aa2a4)[uVar10] - local_1c / 2;
  iVar5 = (&DAT_004aa2a8)[uVar10] - local_1c / 2;
  uVar3 = (int)param_3 >> 0x1f;
  if (param_2 == 2) {
    if (((DAT_004ac92c == 1) || (((param_3 ^ uVar3) - uVar3 & 1 ^ uVar3) == uVar3)) ||
       (DAT_004ac98c == 1)) {
      if (DAT_004a7354 < param_6) {
        if (DAT_004a3a04 != (HGDIOBJ)0x0) {
          SelectObject(*(HDC *)(param_1 + 4),DAT_004a3a04);
          iVar9 = 4;
          goto LAB_00418f02;
        }
      }
      else if (DAT_004a403c != (HGDIOBJ)0x0) {
        SelectObject(*(HDC *)(param_1 + 4),DAT_004a403c);
      }
      iVar9 = 4;
    }
    else {
      if (DAT_004a7354 < param_6) {
        if (DAT_004abf04 != (HGDIOBJ)0x0) {
          SelectObject(*(HDC *)(param_1 + 4),DAT_004abf04);
          iVar9 = 2;
          goto LAB_00418f02;
        }
      }
      else if (DAT_004a89bc != (HGDIOBJ)0x0) {
        SelectObject(*(HDC *)(param_1 + 4),DAT_004a89bc);
      }
      iVar9 = 2;
    }
  }
  else {
    if (((DAT_004ac92c == 1) || (((param_3 ^ uVar3) - uVar3 & 1 ^ uVar3) == uVar3)) ||
       (DAT_004ac98c == 1)) {
      if (DAT_004a7354 < param_6) {
        if (DAT_004a8a44 != (HGDIOBJ)0x0) {
          pHVar11 = *(HDC *)(param_1 + 4);
          pvVar12 = DAT_004a8a44;
LAB_00418e19:
          SelectObject(pHVar11,pvVar12);
        }
      }
      else if (DAT_004abdbc != (HGDIOBJ)0x0) {
        pHVar11 = *(HDC *)(param_1 + 4);
        pvVar12 = DAT_004abdbc;
        goto LAB_00418e19;
      }
      iVar9 = 3;
    }
    else {
      if (DAT_004a7354 < param_6) {
        if (DAT_004ab9e4 != (HGDIOBJ)0x0) {
          SelectObject(*(HDC *)(param_1 + 4),DAT_004ab9e4);
          iVar9 = 1;
          goto LAB_00418e20;
        }
      }
      else if (DAT_004abbfc != (HGDIOBJ)0x0) {
        SelectObject(*(HDC *)(param_1 + 4),DAT_004abbfc);
      }
      iVar9 = 1;
    }
LAB_00418e20:
    if (DAT_004ac92c == 0) {
      if ((((int)param_3 % 3 == 0) && (DAT_004ac98c == 0)) && (DAT_004ac904 == 0)) {
        if (DAT_004a7354 < param_6) {
          if (DAT_004a6794 != (HGDIOBJ)0x0) {
            pHVar11 = *(HDC *)(param_1 + 4);
            pvVar12 = DAT_004a6794;
LAB_00418e92:
            SelectObject(pHVar11,pvVar12);
          }
        }
        else if (DAT_004ab15c != (HGDIOBJ)0x0) {
          pHVar11 = *(HDC *)(param_1 + 4);
          pvVar12 = DAT_004ab15c;
          goto LAB_00418e92;
        }
        iVar9 = 5;
      }
      if (((DAT_004ac92c == 0) && (DAT_004ac904 == 1)) && (param_3 == 1)) {
        if (DAT_004a7354 < param_6) {
          if (DAT_004a6794 != (HGDIOBJ)0x0) {
            pHVar11 = *(HDC *)(param_1 + 4);
            pvVar12 = DAT_004a6794;
LAB_00418efb:
            SelectObject(pHVar11,pvVar12);
          }
        }
        else if (DAT_004ab15c != (HGDIOBJ)0x0) {
          pHVar11 = *(HDC *)(param_1 + 4);
          pvVar12 = DAT_004ab15c;
          goto LAB_00418efb;
        }
        iVar9 = 5;
      }
    }
  }
LAB_00418f02:
  FUN_004706bd(param_1,local_8,(&DAT_004aa1a0)[uVar10],(&DAT_004aa2a0)[uVar10] - local_14);
  CDC::LineTo(param_1,(&DAT_004aa1a4)[uVar10],(&DAT_004aa2a4)[uVar10] - local_1c);
  CDC::LineTo(param_1,(&DAT_004aa1a8)[uVar10],(&DAT_004aa2a8)[uVar10] - local_1c);
  CDC::LineTo(param_1,(&DAT_004aa1ac)[uVar10],(&DAT_004aa2ac)[uVar10] - local_14);
  FUN_004706bd(param_1,local_8,(&DAT_004aa1a0)[uVar10],(&DAT_004aa2a0)[uVar10] - local_14);
  if ((DAT_004a7354 < param_6) || (pcVar8 = SelectObject_exref, param_3 == 1)) {
    if ((iVar9 == 2) && (DAT_004a89bc != (HGDIOBJ)0x0)) {
      (*pcVar8)(*(undefined4 *)(param_1 + 4),DAT_004a89bc);
    }
    if ((iVar9 == 1) && (DAT_004abbfc != (HGDIOBJ)0x0)) {
      (*pcVar8)(*(undefined4 *)(param_1 + 4),DAT_004abbfc);
    }
    if ((iVar9 == 4) && (DAT_004a403c != (HGDIOBJ)0x0)) {
      (*pcVar8)(*(undefined4 *)(param_1 + 4),DAT_004a403c);
    }
    if ((iVar9 == 3) && (DAT_004abdbc != (HGDIOBJ)0x0)) {
      (*pcVar8)(*(undefined4 *)(param_1 + 4),DAT_004abdbc);
    }
    if ((iVar9 == 5) && (DAT_004ab15c != (HGDIOBJ)0x0)) {
      (*pcVar8)(*(undefined4 *)(param_1 + 4),DAT_004ab15c);
    }
    if (((param_2 < 2) || (DAT_00491188 != 7)) || (param_7 != 1)) {
      iVar9 = 0;
    }
    else {
      iVar9 = (local_1c * 3) / 2;
    }
    FUN_004706bd(param_1,local_8,(&DAT_004aa1a0)[uVar10],(&DAT_004aa2a0)[uVar10] - local_14);
    CDC::LineTo(param_1,(&DAT_004aa1b0)[uVar10],iVar9 + (&DAT_004aa2b0)[uVar10]);
    FUN_004706bd(param_1,local_8,(&DAT_004aa1ac)[uVar10],(&DAT_004aa2ac)[uVar10] - local_14);
    CDC::LineTo(param_1,(&DAT_004aa1b4)[uVar10],iVar9 + (&DAT_004aa2b4)[uVar10]);
    if ((DAT_004ac904 == 0) && ((param_2 == 1 || (DAT_00491188 < 7)))) {
      iVar9 = *(int *)(&DAT_004aa730 + param_3 * 4);
      if (DAT_004a4dec != (HGDIOBJ)0x0) {
        SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
      }
      uVar3 = iVar9 * -0x5a - param_8;
      uVar7 = (int)uVar3 >> 0x1f;
      param_3 = (uVar3 ^ uVar7) - uVar7;
      if ((((int)param_3 < 0x32) || ((int)param_8 < -0x96)) || (0x96 < (int)param_8)) {
        iVar9 = (&DAT_004aa1a4)[uVar10];
        iVar6 = (&DAT_004aa1b0)[uVar10];
        iVar1 = (&DAT_004aa2b0)[uVar10];
        FUN_004706bd(param_1,local_8,iVar9,iVar4);
        CDC::LineTo(param_1,(iVar9 + iVar6 * 2) / 3,(iVar4 + iVar1 * 2) / 3);
      }
      if (((int)param_3 < 0x5a) ||
         ((int)((param_8 ^ (int)param_8 >> 0x1f) - ((int)param_8 >> 0x1f)) <
          (int)((-(uint)(param_2 != 1) & 0xffffffdd) + 0x37))) {
        iVar4 = ((&DAT_004aa1a8)[uVar10] + (&DAT_004aa1b4)[uVar10] * 2) / 3;
        iVar9 = (iVar5 + (&DAT_004aa2b4)[uVar10] * 2) / 3;
        FUN_004706bd(param_1,local_8,(&DAT_004aa1a8)[uVar10],iVar5);
        CDC::LineTo(param_1,iVar4,iVar9);
        if ((param_2 == 1) && ((DAT_0049114c < 1 && (DAT_004ac904 == 0)))) {
          FUN_004706bd(param_1,local_8,DAT_004aa708,DAT_004abe68);
          CDC::LineTo(param_1,iVar4,iVar9);
        }
      }
    }
    if (DAT_004ac904 == 1) {
      iVar9 = DAT_004a70f4 * 4;
      iVar4 = DAT_004a70fc * 6;
      iVar6 = DAT_004a72c0 * 4;
      iVar5 = DAT_004a72cc * 6;
      FUN_004706bd(param_1,local_8,(&DAT_004aa1a4)[uVar10],(&DAT_004aa2a4)[uVar10] - local_1c);
      CDC::LineTo(param_1,(iVar9 + iVar4) / 10,(iVar6 + iVar5) / 10);
      iVar6 = DAT_004a70f4 * 6;
      iVar4 = DAT_004a70fc * 4;
      iVar9 = DAT_004a72cc * 4;
      iVar5 = DAT_004a72c0 * 6;
      FUN_004706bd(param_1,local_8,(&DAT_004aa1a8)[uVar10],(&DAT_004aa2a8)[uVar10] - local_1c);
      CDC::LineTo(param_1,(iVar6 + iVar4) / 10,(iVar9 + iVar5) / 10);
    }
  }
  (**(code **)(*(int *)param_1 + 0x2c))(7);
  iVar4 = 1 - (int)(longlong)((double)CONCAT44(param_4,param_3) * _DAT_00485060);
  if (iVar4 < 3) {
    iVar4 = 3;
  }
  if ((DAT_00491188 == 1) && (iVar4 = iVar4 + 1, DAT_004ac904 == 0)) {
    local_1c = local_1c + -1;
  }
  if (param_5 < DAT_004a7354) {
    iVar4 = iVar4 + -1;
    local_1c = local_1c + -1;
  }
  iVar5 = (int)((&DAT_004aa1a8)[uVar10] + (&DAT_004aa1a4)[uVar10]) / 2;
  iVar9 = (int)((&DAT_004aa2a8)[uVar10] + (&DAT_004aa2a4)[uVar10]) / 2;
  if ((DAT_004ac92c == 0) && (DAT_004ac98c == 0)) {
    if (DAT_004ab17c == (HGDIOBJ)0x0) goto LAB_0041947f;
    pHVar11 = *(HDC *)(param_1 + 4);
    pvVar12 = DAT_004ab17c;
  }
  else {
    if (DAT_004a3efc == (HGDIOBJ)0x0) goto LAB_0041947f;
    pHVar11 = *(HDC *)(param_1 + 4);
    pvVar12 = DAT_004a3efc;
  }
  SelectObject(pHVar11,pvVar12);
LAB_0041947f:
  Ellipse(*(HDC *)(param_1 + 4),iVar5 - iVar4,(iVar9 + iVar4 * -3) - local_1c,iVar4 + iVar5,
          (iVar9 - local_1c) - iVar4);
  return;
}

