
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00444890(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  float10 fVar1;
  float10 fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  float10 fVar8;
  float10 fVar9;
  int aiStack_8 [2];
  
  iVar3 = param_7;
  if (((DAT_004da19c == 8) && (param_6 == 0)) && (param_3 < (DAT_004da148 * 3) / 2)) {
    return;
  }
  if (DAT_004f8cd0 < 0) {
    return;
  }
  if (0 < DAT_005363f4) {
    return;
  }
  if ((DAT_0053527c == 1) && (DAT_00536408 == 0)) {
    if (param_7 == 5) {
      return;
    }
    if (param_7 == 4) {
      return;
    }
  }
  if (((DAT_0053527c == 1) && (DAT_00536408 == 1)) && (0 < DAT_005364e0)) {
    if (param_7 == 5) {
      return;
    }
    if (param_7 == 4) {
      return;
    }
  }
  iVar4 = *(int *)(&DAT_004fae60 + param_5 * 4);
  if (param_6 == 1) {
    if ((&DAT_00525a78)[param_5] == 0) {
      param_7 = FUN_0041bc20((&DAT_00522b90)[param_5] - *(int *)(&DAT_004fbb90 + param_5 * 4));
    }
    if ((&DAT_00525a78)[param_5] == 1) {
      param_7 = FUN_0041bc20((&DAT_00522b90)[param_5] - *(int *)(&DAT_00535740 + param_5 * 4));
    }
    if ((&DAT_00525a78)[param_5] == 2) {
      param_7 = 0;
    }
  }
  if (((DAT_005363e4 == 0) && (param_4 != 3)) && (DAT_004fdfe4 != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_004fdfe4);
  }
  if (((DAT_005363e4 == 0) && (param_4 == 3)) && (DAT_005362e4 != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_005362e4);
  }
  if (DAT_005363e4 == 1) {
    (**(code **)(*param_1 + 0x2c))(param_1,6);
  }
  piVar7 = DAT_004f7200;
  if ((param_4 != 1) && (param_4 < 4)) {
    piVar7 = param_1;
  }
  if (((param_4 == 2) || (param_4 == 0x18)) || (param_4 == 0x19)) {
    piVar7 = (int *)(0xb4 - iVar4);
  }
  if (0xb0 < (int)(((uint)piVar7 ^ (int)piVar7 >> 0x1f) - ((int)piVar7 >> 0x1f))) {
    piVar7 = (int *)0x0;
  }
  if (param_4 == 3) {
    piVar7 = (int *)0x5a;
  }
  if (param_6 != 1) {
    FUN_0043e730(0,(double)(int)(longlong)*(double *)(&DAT_004f8398 + iVar3 * 8),
                 (double)(int)(longlong)*(double *)(&DAT_004fb068 + iVar3 * 8),param_5,99);
    iVar5 = DAT_00523660;
    iVar4 = DAT_004fed58;
    iVar6 = FUN_0041bc20((int)piVar7 + (&DAT_00522b90)[param_5] + 0xb4);
    FUN_0042f220((int)(longlong)*(double *)(&DAT_004f8398 + iVar3 * 8),
                 (int)(longlong)*(double *)(&DAT_004fb068 + iVar3 * 8),
                 *(int *)(&DAT_00522ef8 + param_5 * 4),iVar6);
    FUN_0043e730(0,(double)DAT_004fe080,(double)DAT_00523180,param_5,99);
    FUN_004b4d9d(param_1,aiStack_8,iVar4,iVar5);
    if ((param_4 != 4) && (param_4 < 0x14)) {
      CDC::LineTo(param_1,DAT_004fed58,DAT_00523660);
    }
    iVar6 = FUN_0041bc20(((&DAT_00522b90)[param_5] - (int)piVar7) + 0xb4);
    FUN_0042f220((int)(longlong)*(double *)(&DAT_004f8398 + iVar3 * 8),
                 (int)(longlong)*(double *)(&DAT_004fb068 + iVar3 * 8),
                 *(int *)(&DAT_00522ef8 + param_5 * 4),iVar6);
    FUN_0043e730(0,(double)DAT_004fe080,(double)DAT_00523180,param_5,99);
    FUN_004b4d9d(param_1,aiStack_8,iVar4,iVar5);
    if ((param_4 != 5) && (param_4 < 0x14)) {
      CDC::LineTo(param_1,DAT_004fed58,DAT_00523660);
    }
    if (param_4 == 0x18) {
      iVar6 = FUN_0041bc20((int)piVar7 + (&DAT_00522b90)[param_5] + 0xb4);
      if (DAT_005363f8 == 1) {
        if (DAT_004da214 != -1) goto LAB_00444f7e;
        iVar6 = FUN_0041bc20(((&DAT_00522b90)[param_5] - (int)piVar7) + 0xb4);
      }
      if ((DAT_004da214 != -1) || (DAT_004f853c == DAT_004da1e4)) goto LAB_00444f7e;
      iVar6 = ((&DAT_00522b90)[param_5] - (int)piVar7) + 0xb4;
    }
    else {
      if (param_4 != 0x19) {
        return;
      }
      iVar6 = FUN_0041bc20(((&DAT_00522b90)[param_5] - (int)piVar7) + 0xb4);
      if (DAT_005363f8 == 1) {
        if (DAT_004da214 != -1) goto LAB_00444f7e;
        iVar6 = FUN_0041bc20((int)piVar7 + (&DAT_00522b90)[param_5] + 0xb4);
      }
      if ((DAT_004da214 != -1) || (DAT_004f853c == DAT_004da1e4)) goto LAB_00444f7e;
      iVar6 = (int)piVar7 + (&DAT_00522b90)[param_5] + 0xb4;
    }
    iVar6 = FUN_0041bc20(iVar6);
LAB_00444f7e:
    FUN_0043ec20((double)CONCAT44(*(undefined4 *)(&DAT_004f839c + iVar3 * 8),
                                  *(undefined4 *)(&DAT_004f8398 + iVar3 * 8)),
                 (double)CONCAT44(*(undefined4 *)(&DAT_004fb06c + iVar3 * 8),
                                  *(undefined4 *)(&DAT_004fb068 + iVar3 * 8)),0,param_5);
    FUN_0042f220((int)(longlong)*(double *)(&DAT_004f8398 + iVar3 * 8),
                 (int)(longlong)*(double *)(&DAT_004fb068 + iVar3 * 8),
                 (int)(longlong)(_DAT_004fbb88 * _DAT_004cc7b8),iVar6);
    FUN_0043e730(0,(double)DAT_004fe080,(double)DAT_00523180,param_5,99);
    FUN_004b4d9d(param_1,aiStack_8,iVar4,iVar5);
    CDC::LineTo(param_1,DAT_004fed58,DAT_00523660);
    return;
  }
  iVar3 = (param_7 - (int)piVar7) + 0xb4;
  iVar4 = FUN_0041bc20(iVar3);
  fVar8 = (float10)fsin((float10)iVar4 * (float10)_DAT_004cc568);
  fVar1 = (float10)_DAT_004ccbb8;
  fVar9 = (float10)fcos((float10)iVar4 * (float10)_DAT_004cc568);
  fVar2 = (float10)_DAT_004ccbc0;
  FUN_004b4d9d(param_1,aiStack_8,param_2,param_3);
  if ((param_4 != 5) && (param_4 < 0x14)) {
    CDC::LineTo(param_1,param_2 - (int)(longlong)(fVar8 * fVar1),
                param_3 - (int)(longlong)(fVar9 * fVar2));
  }
  iVar4 = param_7 + 0xb4 + (int)piVar7;
  iVar5 = FUN_0041bc20(iVar4);
  fVar8 = (float10)fsin((float10)iVar5 * (float10)_DAT_004cc568);
  fVar1 = (float10)_DAT_004ccbb8;
  fVar9 = (float10)fcos((float10)iVar5 * (float10)_DAT_004cc568);
  fVar2 = (float10)_DAT_004ccbc0;
  FUN_004b4d9d(param_1,aiStack_8,param_2,param_3);
  if ((param_4 != 4) && (param_4 < 0x14)) {
    CDC::LineTo(param_1,param_2 - (int)(longlong)(fVar8 * fVar1),
                param_3 - (int)(longlong)(fVar9 * fVar2));
  }
  param_6 = FUN_0041bc20(iVar4);
  if (DAT_005363f8 == 1) {
    if (DAT_004da214 == -1) {
      param_6 = FUN_0041bc20(iVar3);
      goto LAB_00444ba5;
    }
  }
  else {
LAB_00444ba5:
    if ((DAT_004da214 == -1) && (DAT_004f853c != DAT_004da1e4)) {
      param_6 = FUN_0041bc20(iVar3);
    }
  }
  fVar8 = (float10)fsin((float10)param_6 * (float10)_DAT_004cc568);
  fVar1 = (float10)_DAT_004ccbb8;
  fVar9 = (float10)fcos((float10)param_6 * (float10)_DAT_004cc568);
  fVar2 = (float10)_DAT_004ccbc0;
  FUN_004b4d9d(param_1,aiStack_8,param_2,param_3);
  if (param_4 == 0x18) {
    CDC::LineTo(param_1,param_2 - (int)(longlong)(fVar8 * fVar1),
                param_3 - (int)(longlong)(fVar9 * fVar2));
  }
  param_6 = FUN_0041bc20(iVar3);
  if (DAT_005363f8 == 1) {
    if (DAT_004da214 != -1) goto LAB_00444c82;
    param_6 = FUN_0041bc20(iVar4);
  }
  if ((DAT_004da214 == -1) && (DAT_004f853c != DAT_004da1e4)) {
    param_6 = FUN_0041bc20(iVar4);
  }
LAB_00444c82:
  fVar8 = (float10)fsin((float10)param_6 * (float10)_DAT_004cc568);
  fVar1 = (float10)_DAT_004ccbb8;
  fVar9 = (float10)fcos((float10)param_6 * (float10)_DAT_004cc568);
  fVar2 = (float10)_DAT_004ccbc0;
  FUN_004b4d9d(param_1,aiStack_8,param_2,param_3);
  if (param_4 != 0x19) {
    return;
  }
  CDC::LineTo(param_1,param_2 - (int)(longlong)(fVar8 * fVar1),
              param_3 - (int)(longlong)(fVar9 * fVar2));
  return;
}

