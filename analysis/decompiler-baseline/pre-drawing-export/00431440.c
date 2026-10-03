
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00431440(CDC *param_1,int param_2,uint param_3,int param_4,int param_5,int param_6)

{
  float10 fVar1;
  float10 fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  float10 fVar8;
  float10 fVar9;
  int in_stack_0000001c;
  int local_8 [2];
  
  iVar5 = param_5;
  if ((((DAT_00491194 != 8) || (param_6 != 0)) || ((DAT_00491148 * 3) / 2 <= (int)param_3)) &&
     (((-1 < DAT_004a5b80 && (DAT_004ac93c < 1)) &&
      ((local_8[0] = *(int *)(&DAT_004a5f10 + param_5 * 4),
       *(int *)(&DAT_004a7bc8 + param_5 * 4) < 0x5b || (0x13 < local_8[0])))))) {
    if (param_6 == 1) {
      if ((&DAT_004ab160)[param_5] == 0) {
        param_5 = FUN_00413cb0(*(int *)(&DAT_004aa5b0 + param_5 * 4) -
                               *(int *)(&DAT_004a6830 + param_5 * 4));
      }
      if ((&DAT_004ab160)[iVar5] == 1) {
        param_5 = FUN_00413cb0(*(int *)(&DAT_004aa5b0 + iVar5 * 4) -
                               *(int *)(&DAT_004ac018 + iVar5 * 4));
      }
      if ((&DAT_004ab160)[iVar5] == 2) {
        param_5 = 0;
      }
    }
    if (((DAT_004ac92c == 0) && (param_4 != 3)) && (DAT_004a705c != (HGDIOBJ)0x0)) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a705c);
    }
    if (((DAT_004ac92c == 0) && (param_4 == 3)) && (DAT_004ac84c != (HGDIOBJ)0x0)) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004ac84c);
    }
    if (DAT_004ac92c == 1) {
      (**(code **)(*(int *)param_1 + 0x2c))(6);
    }
    if ((param_4 == 1) || (uVar7 = param_3, 3 < param_4)) {
      uVar7 = DAT_004a4eb0;
    }
    if (param_4 == 2) {
      uVar7 = 0xb4 - local_8[0];
    }
    if (0xb0 < (int)((uVar7 ^ (int)uVar7 >> 0x1f) - ((int)uVar7 >> 0x1f))) {
      uVar7 = 0;
    }
    if (param_4 == 3) {
      uVar7 = 0x5a;
    }
    if (param_6 == 1) {
      iVar5 = FUN_00413cb0((param_5 - uVar7) + 0xb4);
      fVar8 = (float10)fsin((float10)iVar5 * (float10)_DAT_00484d40);
      fVar1 = (float10)_DAT_004852d0;
      fVar9 = (float10)fcos((float10)iVar5 * (float10)_DAT_00484d40);
      fVar2 = (float10)_DAT_004852d8;
      FUN_004706bd(param_1,local_8,param_2,param_3);
      if (param_4 != 5) {
        CDC::LineTo(param_1,param_2 - (int)(longlong)(fVar8 * fVar1),
                    param_3 - (int)(longlong)(fVar9 * fVar2));
      }
      iVar5 = FUN_00413cb0(param_5 + 0xb4 + uVar7);
      fVar8 = (float10)fsin((float10)iVar5 * (float10)_DAT_00484d40);
      fVar1 = (float10)_DAT_004852d0;
      fVar9 = (float10)fcos((float10)iVar5 * (float10)_DAT_00484d40);
      fVar2 = (float10)_DAT_004852d8;
      FUN_004706bd(param_1,local_8,param_2,param_3);
      if (param_4 != 4) {
        CDC::LineTo(param_1,param_2 - (int)(longlong)(fVar8 * fVar1),
                    param_3 - (int)(longlong)(fVar9 * fVar2));
        return;
      }
    }
    else {
      FUN_0042bfc0(0,(double)(int)(longlong)*(double *)(&DAT_004a52f0 + in_stack_0000001c * 8),
                   (double)(int)(longlong)*(double *)(&DAT_004a60b0 + in_stack_0000001c * 8),iVar5,
                   99);
      iVar4 = DAT_004aaa48;
      iVar3 = DAT_004a7c48;
      iVar6 = FUN_00413cb0(uVar7 + 0xb4 + *(int *)(&DAT_004aa5b0 + iVar5 * 4));
      FUN_00420b20((int)(longlong)*(double *)(&DAT_004a52f0 + in_stack_0000001c * 8),
                   (int)(longlong)*(double *)(&DAT_004a60b0 + in_stack_0000001c * 8),
                   (*(int *)(&DAT_004aa6e0 + iVar5 * 4) / 10) * 10,iVar6);
      FUN_0042bfc0(0,(double)DAT_004a70e8,(double)DAT_004aa81c,iVar5,99);
      FUN_004706bd(param_1,local_8,iVar3,iVar4);
      if (param_4 != 4) {
        CDC::LineTo(param_1,DAT_004a7c48,DAT_004aaa48);
      }
      iVar6 = FUN_00413cb0((*(int *)(&DAT_004aa5b0 + iVar5 * 4) - uVar7) + 0xb4);
      FUN_00420b20((int)(longlong)*(double *)(&DAT_004a52f0 + in_stack_0000001c * 8),
                   (int)(longlong)*(double *)(&DAT_004a60b0 + in_stack_0000001c * 8),
                   (*(int *)(&DAT_004aa6e0 + iVar5 * 4) / 10) * 10,iVar6);
      FUN_0042bfc0(0,(double)DAT_004a70e8,(double)DAT_004aa81c,iVar5,99);
      FUN_004706bd(param_1,local_8,iVar3,iVar4);
      if (param_4 != 5) {
        CDC::LineTo(param_1,DAT_004a7c48,DAT_004aaa48);
      }
    }
  }
  return;
}

