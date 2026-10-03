
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0042b0b0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  float10 fVar6;
  float10 fVar7;
  int local_14;
  
  iVar2 = FUN_0041e000(2000);
  iVar3 = FUN_0041e000(0x8c);
  iVar3 = FUN_0041bc20(iVar3 + -0x46 + DAT_005362d4);
  if (DAT_004da140 == 1) {
    local_14 = (int)(longlong)DAT_004f6b00;
    iVar4 = (int)(longlong)DAT_004f6c18;
  }
  else {
    local_14 = ((int)(longlong)DAT_004f6b08 + (int)(longlong)DAT_004f6b00) / 2;
    iVar4 = ((int)(longlong)DAT_004f6c20 + (int)(longlong)DAT_004f6c18) / 2;
  }
  fVar6 = (float10)fsin((float10)iVar3 * (float10)_DAT_004cc568);
  iVar1 = param_1 * 4;
  fVar7 = (float10)fcos((float10)iVar3 * (float10)_DAT_004cc568);
  *(double *)(&DAT_00535460 + param_1 * 8) =
       (double)((float10)local_14 + fVar6 * (float10)(iVar2 + 500));
  *(double *)(&DAT_004f4b08 + param_1 * 8) =
       (double)((float10)iVar4 - fVar7 * (float10)(iVar2 + 500));
  iVar2 = FUN_0041e000(2);
  bVar5 = DAT_004da154 == 1;
  *(int *)(&DAT_004f71d8 + iVar1) = iVar2 + 2 + DAT_0051158c * 2;
  if (bVar5) {
    *(undefined4 *)(&DAT_004f71d8 + iVar1) = 2;
  }
  iVar2 = FUN_0041e000(300);
  *(int *)(&DAT_00523630 + iVar1) =
       (int)(longlong)((double)(iVar2 + 0x96) * _DAT_004da160) + DAT_004f8cd0;
  iVar2 = FUN_0041e000(400);
  *(int *)(&DAT_004f7ea0 + iVar1) = iVar2 + 200;
  if (DAT_004fb5d4 == 1) {
    iVar2 = FUN_0041e000(400);
    *(int *)(&DAT_004f7ea0 + iVar1) = iVar2 + 300;
  }
  if (0 < DAT_004da1f8) {
    iVar2 = FUN_0041e000(400);
    *(int *)(&DAT_004f7ea0 + iVar1) = iVar2 + 300;
  }
  iVar2 = FUN_0041e000(DAT_00522ad0 / 2);
  *(int *)(&DAT_004f42a0 + iVar1) = iVar2 + DAT_00522ad0 / 2;
  iVar2 = FUN_0041e000(4);
  if (DAT_0053645c == 0) {
    *(int *)(&DAT_005357d8 + iVar1) =
         iVar2 + -2 + *(int *)(&DAT_004f71d8 + iVar1) * 3 + DAT_005362d4;
    return;
  }
  *(int *)(&DAT_005357d8 + iVar1) = iVar2 + -2 + *(int *)(&DAT_004f71d8 + iVar1) * -3 + DAT_005362d4
  ;
  return;
}

