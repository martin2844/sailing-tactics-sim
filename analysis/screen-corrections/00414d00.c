
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00414d00(CDC *param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int in_stack_0000001c;
  int in_stack_00000020;
  int in_stack_00000024;
  double local_8;
  
  local_8 = (double)CONCAT44(param_3,param_2) * _DAT_00484fc0;
  if (DAT_00491188 == 8) {
    local_8 = local_8 * _DAT_00484fc8;
  }
  if (DAT_004ac900 == 1) {
    local_8 = local_8 * _DAT_00484fd0;
  }
  if (DAT_004ac914 == 1) {
    local_8 = local_8 * _DAT_00484dc0;
  }
  iVar4 = (int)(longlong)((double)CONCAT44(param_6,param_5) * _DAT_00484fd8) / 3;
  if (((param_4 <= DAT_00491140) && (1 < DAT_00491188)) && (DAT_004ac930 == 0)) {
    DAT_004a76c4 = DAT_004aa1f4;
    DAT_004a7760 = DAT_004aa2f4 - (int)(longlong)(local_8 * _DAT_00484fe0);
    if (DAT_004ac900 == 0) {
      iVar5 = DAT_004aa1c0 + DAT_004aa1c4 * 3;
      DAT_004aa598 = (int)(iVar5 + (iVar5 >> 0x1f & 3U)) >> 2;
      iVar5 = DAT_004aa2c0 + DAT_004aa2c4 * 3;
      DAT_004aba64 = (int)(iVar5 + (iVar5 >> 0x1f & 3U)) >> 2;
      iVar5 = DAT_004aa1d8 + DAT_004aa1d4 * 3;
      DAT_004a67a0 = (int)(iVar5 + (iVar5 >> 0x1f & 3U)) >> 2;
      iVar5 = DAT_004aa2d8 + DAT_004aa2d4 * 3;
      DAT_004aa6fc = (int)(iVar5 + (iVar5 >> 0x1f & 3U)) >> 2;
    }
    if (DAT_004ac900 == 1) {
      DAT_004aa598 = (DAT_004aa1bc + DAT_004aa1c4 * 5) / 6;
      DAT_004aba64 = (DAT_004aa2bc + DAT_004aa2c4 * 5) / 6;
      DAT_004a67a0 = (DAT_004aa1e0 + DAT_004aa1d8 * 5) / 6;
      DAT_004aa6fc = (DAT_004aa2e0 + DAT_004aa2d8 * 5) / 6;
    }
    if (DAT_00491150 == 100) {
      DAT_004a7640 = DAT_004aa1f4;
      DAT_004a7750 = DAT_004a7760;
    }
    else {
      DAT_004a7640 = DAT_004aa1f0;
      DAT_004a7750 = DAT_004aa2f0 - (int)(longlong)(local_8 * _DAT_00484ec8);
    }
    iVar5 = DAT_004aa598;
    if (DAT_004aa734 == 1) {
      iVar5 = DAT_004a67a0;
    }
    FUN_004156f0(param_1,iVar5);
  }
  _DAT_004a4ca8 = DAT_004aa1e4;
  _DAT_004a4cec = (int)(longlong)(local_8 * _DAT_00484e00);
  _DAT_004a4cac = DAT_004aa2e4 - _DAT_004a4cec;
  _DAT_004a4cb0 = DAT_004aa1e8;
  iVar5 = (int)(longlong)(local_8 * _DAT_00484d90);
  _DAT_004a4cb4 = DAT_004aa2e8 - iVar5;
  _DAT_004a4cb8 = DAT_004aa1ec;
  iVar2 = (int)(longlong)(local_8 * _DAT_00484da8);
  _DAT_004a4cbc = DAT_004aa2ec - iVar2;
  _DAT_004a4cc0 = DAT_004aa1f0;
  iVar3 = (int)(longlong)(local_8 * _DAT_00484ec8);
  _DAT_004a4cc4 = DAT_004aa2f0 - iVar3;
  _DAT_004a4cc8 = DAT_004aa1f4;
  _DAT_004a4ccc = DAT_004aa2f4 - (int)(longlong)(local_8 * _DAT_00484fe0);
  _DAT_004a4cd0 = DAT_004aa1f8;
  _DAT_004a4cd4 = (DAT_004aa2f8 - iVar4) - iVar3;
  _DAT_004a4cd8 = DAT_004aa1fc;
  _DAT_004a4ce0 = DAT_004aa200;
  _DAT_004a4ce4 = (DAT_004aa300 - iVar4) - iVar5;
  _DAT_004a4cdc = (DAT_004aa2fc - iVar4) - iVar2;
  pcVar1 = *(code **)(*(int *)param_1 + 0x2c);
  _DAT_004a4cec = (DAT_004aa304 - iVar4) - _DAT_004a4cec;
  _DAT_004a4ce8 = DAT_004aa204;
  (*pcVar1)(param_1,7);
  if (DAT_004ac98c == 0) {
    (*pcVar1)(param_1,0);
  }
  else if (DAT_004a70e4 != (HGDIOBJ)0x0) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a70e4);
  }
  if (DAT_004ac92c == 1) {
    DAT_004ac9bc = 0;
  }
  if ((DAT_004ac98c != 0) || (DAT_004ac9bc != 1)) goto LAB_004151ca;
  if ((param_4 == 1) && (DAT_004a4f7c != (HGDIOBJ)0x0)) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a4f7c);
  }
  if ((param_4 == 2) && (DAT_004aa98c != (HGDIOBJ)0x0)) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004aa98c);
  }
  if (param_4 < 0xb) {
LAB_004151a3:
    if (param_4 < 0x15) goto LAB_004151ca;
  }
  else if (param_4 < 0x15) {
    if (DAT_004a3efc != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a3efc);
    }
    goto LAB_004151a3;
  }
  if (DAT_004a5afc != (HGDIOBJ)0x0) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a5afc);
  }
LAB_004151ca:
  iVar7 = DAT_00491140;
  if ((DAT_004911d0 == 2) && (DAT_004911d4 + 4 < DAT_004a5b80)) {
    DAT_004911d0 = 1;
  }
  iVar6 = DAT_004911d0;
  if ((*(int *)(&DAT_004a4e78 + param_4 * 4) == 0) && (param_4 <= DAT_00491140)) {
    *(undefined4 *)(&DAT_004a6090 + param_4 * 4) = 0;
  }
  if ((0 < *(int *)(&DAT_004a4e78 + param_4 * 4)) && (param_4 <= iVar7)) {
    if ((iVar6 == 1) && (*(int *)(&DAT_004a6090 + param_4 * 4) == 0)) {
      if (1 < DAT_0049116c) {
        DAT_00491178 = DAT_0049116c;
        DAT_00491174 = DAT_00491170;
      }
      DAT_00491170 = 0xb67;
      DAT_0049116c = 1;
    }
    if (DAT_004a3a14 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a3a14);
    }
    if (DAT_004a676c != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a676c);
    }
    *(undefined4 *)(&DAT_004a6090 + param_4 * 4) = *(undefined4 *)(&DAT_004a4e78 + param_4 * 4);
  }
  if ((DAT_004a5b80 < *(int *)(&DAT_004abf18 + param_4 * 4) + DAT_004a7644) &&
     (*(int *)(&DAT_004a89c0 + param_4 * 4) < 0xb)) {
    (*pcVar1)(param_1,4);
  }
  if ((param_4 == 1) && (DAT_004a40c4 == 1)) {
    (*pcVar1)(param_1,5);
  }
  if (((param_4 == 2) && (DAT_004a40c8 == 1)) && (DAT_00491140 == 2)) {
    (*pcVar1)(param_1,5);
  }
  Polygon(*(HDC *)(param_1 + 4),(POINT *)&DAT_004a4ca8,9);
  (*pcVar1)(param_1,7);
  if (((param_4 <= DAT_00491140) && (1 < DAT_00491188)) && (DAT_004ac930 == 0)) {
    iVar7 = *(int *)(&DAT_004a77e8 + param_4 * 4);
    if ((*(int *)(&DAT_004aa730 + param_4 * 4) == 1) && (-(iVar7 + 10) < in_stack_00000020)) {
      FUN_004156f0(param_1,DAT_004aa598);
    }
    if (*(int *)(&DAT_004aa730 + param_4 * 4) == -1) {
      if (in_stack_00000020 < iVar7 + 10) {
        FUN_004156f0(param_1,DAT_004a67a0);
      }
      if ((*(int *)(&DAT_004aa730 + param_4 * 4) == -1) && (in_stack_00000020 == 0xb4)) {
        FUN_004156f0(param_1,DAT_004a67a0);
      }
    }
  }
  if ((DAT_004a7358 <= in_stack_0000001c) && ((param_4 <= DAT_00491140 || (DAT_004ac928 != 1)))) {
    (*pcVar1)(param_1,7);
    iVar7 = 10;
    iVar6 = FUN_00415a20(10);
    if (10 < *(int *)(&DAT_004a8aa8 + param_4 * 4)) {
      iVar7 = iVar6 + 1;
    }
    iVar8 = 10;
    if (0x23 < *(int *)(&DAT_004a8aa8 + param_4 * 4)) {
      iVar7 = iVar6 + -6;
      iVar8 = iVar6;
    }
    FUN_00415590(param_1,iVar7,iVar8,in_stack_00000024,
                 (int)(longlong)((double)(0x1e - DAT_00491188) * (double)CONCAT44(param_6,param_5)),
                 DAT_004aa1e8,DAT_004aa2e8 - iVar5,DAT_004aa200,(DAT_004aa300 - iVar4) - iVar5,6,2);
    FUN_00415590(param_1,iVar7,iVar8,in_stack_00000024,
                 (int)(longlong)((double)(0x19 - DAT_00491188) * (double)CONCAT44(param_6,param_5)),
                 DAT_004aa1ec,DAT_004aa2ec - iVar2,DAT_004aa1fc,(DAT_004aa2fc - iVar4) - iVar2,6,2);
    if (DAT_004ac914 == 0) {
      FUN_00415590(param_1,iVar7,iVar8,in_stack_00000024,
                   (int)(longlong)
                        ((double)(0x14 - DAT_00491188) * (double)CONCAT44(param_6,param_5)),
                   DAT_004aa1f0,DAT_004aa2f0 - iVar3,DAT_004aa1f8,(DAT_004aa2f8 - iVar4) - iVar3,6,2
                  );
    }
  }
  return;
}

