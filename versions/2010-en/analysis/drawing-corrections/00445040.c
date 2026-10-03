
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */

void FUN_00445040(int *param_1,int param_2,uint param_3,double param_4,int param_5,int param_6,
                 int param_7,int param_8,int param_9,int param_10,int param_11)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  
  if (DAT_00536450 != 1) {
    if (((param_11 == 1) && (*(int *)(&DAT_0050f6d0 + param_3 * 4) < 8)) &&
       (((DAT_00522cac == 1 && (param_3 == 1)) || ((DAT_00522d18 == 1 && (param_3 == 2)))))) {
      if (DAT_004f7084 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004f7084);
      }
      iVar6 = 100;
      do {
        iVar1 = FUN_0041e000(param_9 - param_7);
        iVar2 = FUN_0041e000(param_10 - param_8);
        FUN_00424320(param_1,iVar1 + param_7,iVar2 + param_8,1);
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      return;
    }
    iVar6 = DAT_004fe624 / 0xe;
    if (param_11 == 1) {
      iVar1 = *(int *)(&DAT_0050f6d0 + param_3 * 4);
      if (iVar1 < 5) {
        iVar6 = (DAT_004fe624 * 2) / 3;
      }
      if (iVar1 == 8) {
        iVar6 = DAT_004fe624 / 3;
      }
      if (iVar1 == 0x10) {
        iVar6 = (int)(DAT_004fe624 + (DAT_004fe624 >> 0x1f & 7U)) >> 3;
      }
    }
    if ((((param_7 - iVar6 <= param_5) && (param_5 <= iVar6 + param_9)) &&
        (param_6 <= iVar6 + param_10)) && (param_8 - iVar6 <= param_6)) {
      iVar6 = (int)(longlong)((double)*(int *)(&DAT_004f7ea0 + param_2 * 4) * param_4);
      if (iVar6 < 5) {
        iVar6 = 5;
      }
      if (DAT_004fe624 * 2 < iVar6) {
        iVar6 = DAT_004fe624 * 2;
      }
      if (((*(int *)(&DAT_0050f6d0 + param_3 * 4) < 9) && (param_11 == 1)) && (DAT_005363e4 == 0)) {
        (**(code **)(*param_1 + 0x2c))(param_1,8);
        if (DAT_004f8d6c != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_004f8d6c);
        }
        Ellipse((HDC)param_1[1],param_5 - iVar6,param_6 - iVar6,iVar6 + param_5,iVar6 + param_6);
      }
      if (DAT_00535214 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_00535214);
      }
      if ((param_11 != 1) || (iVar1 = 0x12, 8 < *(int *)(&DAT_0050f6d0 + param_3 * 4))) {
        iVar1 = 6;
      }
      iVar2 = iVar6 * 2;
      for (; iVar1 != 0; iVar1 = iVar1 + -1) {
        iVar3 = FUN_0041e000(iVar2);
        iVar4 = FUN_0041e000(iVar2);
        FUN_00424320(param_1,iVar3 + (param_5 - iVar6),iVar4 + (param_6 - iVar6),1);
      }
      if (param_11 == 1) {
        uVar5 = 0x28;
        iVar1 = *(int *)(&DAT_0050f6d0 + param_3 * 4);
        if (iVar1 < 9) {
          uVar5 = 0x12a;
        }
        if (iVar1 == 0x10) {
          uVar5 = 0x96;
        }
        if (iVar1 == 0x20) {
          uVar5 = 0x4b;
        }
      }
      else {
        uVar5 = 0x14;
      }
      if (10 < DAT_004da174) {
        uVar5 = uVar5 / 2;
      }
      if (uVar5 != 0) {
        piVar7 = &DAT_00512d74;
        param_3 = uVar5;
        do {
          FUN_00424320(param_1,(iVar2 * *piVar7) / 100 + (param_5 - iVar6),
                       (iVar2 * piVar7[1]) / 100 + (param_6 - iVar6),1);
          piVar7 = piVar7 + 1;
          param_3 = param_3 - 1;
        } while (param_3 != 0);
      }
    }
  }
  return;
}

