
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_0041dcd0(int *param_1,int param_2,int param_3,int param_4,int param_5,double param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  double dVar6;
  code *pcVar7;
  int iVar8;
  int iVar9;
  HDC pHVar10;
  int iVar11;
  HGDIOBJ pvVar12;
  double dStack_8;
  
  if (DAT_005363e4 == 1) {
    iVar11 = 6;
    pcVar7 = *(code **)(*param_1 + 0x2c);
  }
  else {
    iVar11 = 7;
    pcVar7 = *(code **)(*param_1 + 0x2c);
  }
  (*pcVar7)(param_1,iVar11);
  iVar11 = DAT_00522928;
  if (DAT_004da150 < 100) {
    iVar9 = DAT_00522a28 - (int)(longlong)(param_6 * _DAT_004cc660);
    iVar1 = (int)(longlong)((double)param_2 * _DAT_004cc850 - (double)param_4 * _DAT_004cc858);
    iVar2 = (int)(longlong)((double)param_3 * _DAT_004cc850 - (double)param_5 * _DAT_004cc858);
    FUN_004b4d9d(param_1,(int *)&dStack_8,DAT_004fe628,DAT_004fe760);
    CDC::LineTo(param_1,iVar1,iVar2);
    CDC::LineTo(param_1,param_2,param_3);
    if (DAT_005363e4 == 1) {
      if (DAT_004f7ec4 != (HGDIOBJ)0x0) {
        pHVar10 = (HDC)param_1[1];
        pvVar12 = DAT_004f7ec4;
override_prt_41dddb_6059bb06:
        SelectObject(pHVar10,pvVar12);
      }
    }
    else if (DAT_004f7084 != (HGDIOBJ)0x0) {
      pHVar10 = (HDC)param_1[1];
      pvVar12 = DAT_004f7084;
      goto override_prt_41dddb_6059bb06;
    }
    FUN_004b4d9d(param_1,(int *)&dStack_8,iVar11,iVar9);
    if (((DAT_004da190 != 4) && (DAT_005363b8 == 0)) && (DAT_00536530 == 0)) {
      CDC::LineTo(param_1,iVar1,iVar2);
    }
  }
  iVar11 = DAT_0052292c;
  if (DAT_004da150 != 100) goto LAB_0041dfee;
  iVar1 = DAT_00522924 + DAT_00522928 * 2;
  dVar6 = param_6 * _DAT_004cc860;
  iVar2 = DAT_00522a24 + DAT_00522a28 * 2;
  iVar8 = DAT_00522a2c - (int)(longlong)(param_6 * _DAT_004cc4f8);
  iVar9 = (int)(longlong)((double)param_4 * _DAT_004cc868 - (double)param_2 * _DAT_004cc870);
  dStack_8 = (double)param_3;
  iVar3 = (int)(longlong)((double)param_5 * _DAT_004cc868 - dStack_8 * _DAT_004cc870);
  iVar4 = (int)(longlong)((double)param_4 * _DAT_004cc878 - (double)param_2 * _DAT_004cc880);
  iVar5 = (int)(longlong)((double)param_5 * _DAT_004cc878 - dStack_8 * _DAT_004cc880);
  FUN_004b4d9d(param_1,(int *)&dStack_8,DAT_004fe628,DAT_004fe760);
  CDC::LineTo(param_1,iVar4,iVar5);
  CDC::LineTo(param_1,iVar9,iVar3);
  CDC::LineTo(param_1,param_2,param_3);
  if (DAT_005363e4 == 1) {
    if (DAT_004f7ec4 != (HGDIOBJ)0x0) {
      pHVar10 = (HDC)param_1[1];
      pvVar12 = DAT_004f7ec4;
override_prt_41dfa6_6059bb06:
      SelectObject(pHVar10,pvVar12);
    }
  }
  else if (DAT_004f7084 != (HGDIOBJ)0x0) {
    pHVar10 = (HDC)param_1[1];
    pvVar12 = DAT_004f7084;
    goto override_prt_41dfa6_6059bb06;
  }
  FUN_004b4d9d(param_1,(int *)&dStack_8,iVar1 / 3,iVar2 / 3 - (int)(longlong)dVar6);
  CDC::LineTo(param_1,iVar9,iVar3);
  FUN_004b4d9d(param_1,(int *)&dStack_8,iVar11,iVar8);
  CDC::LineTo(param_1,iVar4,iVar5);
LAB_0041dfee:
  (*pcVar7)(param_1,7);
  return;
}

