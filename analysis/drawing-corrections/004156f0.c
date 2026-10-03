
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004156f0(CDC *param_1,int param_2)

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
  int in_stack_0000000c;
  int in_stack_00000010;
  int in_stack_00000014;
  undefined4 in_stack_00000018;
  undefined4 in_stack_0000001c;
  HDC pHVar10;
  int iVar11;
  HGDIOBJ pvVar12;
  double dStack_8;
  
  if (DAT_004ac92c == 1) {
    iVar11 = 6;
    pcVar7 = *(code **)(*(int *)param_1 + 0x2c);
  }
  else {
    iVar11 = 7;
    pcVar7 = *(code **)(*(int *)param_1 + 0x2c);
  }
  (*pcVar7)(param_1,iVar11);
  iVar11 = DAT_004aa1e8;
  if (DAT_00491150 < 100) {
    iVar9 = DAT_004aa2e8 -
            (int)(longlong)((double)CONCAT44(in_stack_0000001c,in_stack_00000018) * _DAT_00484d90);
    iVar1 = (int)(longlong)
                 ((double)param_2 * _DAT_00484fe8 - (double)in_stack_00000010 * _DAT_00484ff0);
    iVar2 = (int)(longlong)
                 ((double)in_stack_0000000c * _DAT_00484fe8 -
                 (double)in_stack_00000014 * _DAT_00484ff0);
    FUN_004706bd(param_1,(int *)&dStack_8,DAT_004a7640,DAT_004a7750);
    CDC::LineTo(param_1,iVar1,iVar2);
    CDC::LineTo(param_1,param_2,in_stack_0000000c);
    if (DAT_004ac92c == 1) {
      if (DAT_004a4ee4 != (HGDIOBJ)0x0) {
        pHVar10 = *(HDC *)(param_1 + 4);
        pvVar12 = DAT_004a4ee4;
LAB_004157fb:
        SelectObject(pHVar10,pvVar12);
      }
    }
    else if (DAT_004a4dec != (HGDIOBJ)0x0) {
      pHVar10 = *(HDC *)(param_1 + 4);
      pvVar12 = DAT_004a4dec;
      goto LAB_004157fb;
    }
    FUN_004706bd(param_1,(int *)&dStack_8,iVar11,iVar9);
    if ((DAT_00491188 != 4) && (DAT_004ac900 == 0)) {
      CDC::LineTo(param_1,iVar1,iVar2);
    }
  }
  iVar11 = DAT_004aa1ec;
  if (DAT_00491150 != 100) goto LAB_00415a05;
  iVar1 = DAT_004aa1e4 + DAT_004aa1e8 * 2;
  dVar6 = (double)CONCAT44(in_stack_0000001c,in_stack_00000018) * _DAT_00484ff8;
  iVar2 = DAT_004aa2e4 + DAT_004aa2e8 * 2;
  iVar8 = DAT_004aa2ec -
          (int)(longlong)((double)CONCAT44(in_stack_0000001c,in_stack_00000018) * _DAT_00484da8);
  iVar9 = (int)(longlong)
               ((double)in_stack_00000010 * _DAT_00485000 - (double)param_2 * _DAT_00485008);
  dStack_8 = (double)in_stack_0000000c;
  iVar3 = (int)(longlong)((double)in_stack_00000014 * _DAT_00485000 - dStack_8 * _DAT_00485008);
  iVar4 = (int)(longlong)
               ((double)in_stack_00000010 * _DAT_00485010 - (double)param_2 * _DAT_00485018);
  iVar5 = (int)(longlong)((double)in_stack_00000014 * _DAT_00485010 - dStack_8 * _DAT_00485018);
  FUN_004706bd(param_1,(int *)&dStack_8,DAT_004a7640,DAT_004a7750);
  CDC::LineTo(param_1,iVar4,iVar5);
  CDC::LineTo(param_1,iVar9,iVar3);
  CDC::LineTo(param_1,param_2,in_stack_0000000c);
  if (DAT_004ac92c == 1) {
    if (DAT_004a4ee4 != (HGDIOBJ)0x0) {
      pHVar10 = *(HDC *)(param_1 + 4);
      pvVar12 = DAT_004a4ee4;
LAB_004159bd:
      SelectObject(pHVar10,pvVar12);
    }
  }
  else if (DAT_004a4dec != (HGDIOBJ)0x0) {
    pHVar10 = *(HDC *)(param_1 + 4);
    pvVar12 = DAT_004a4dec;
    goto LAB_004159bd;
  }
  FUN_004706bd(param_1,(int *)&dStack_8,iVar1 / 3,iVar2 / 3 - (int)(longlong)dVar6);
  CDC::LineTo(param_1,iVar9,iVar3);
  FUN_004706bd(param_1,(int *)&dStack_8,iVar11,iVar8);
  CDC::LineTo(param_1,iVar4,iVar5);
LAB_00415a05:
  (*pcVar7)(param_1,7);
  return;
}

