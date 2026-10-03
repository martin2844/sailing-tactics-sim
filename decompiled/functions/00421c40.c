
void __cdecl FUN_00421c40(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
  iVar3 = DAT_004a72c8;
  iVar2 = DAT_004a70f8;
  iVar1 = DAT_0049118c + 1;
  bVar5 = DAT_004911cc == 2;
  *(undefined4 *)(&DAT_004a5420 + param_1 * 4) = 0;
  if (bVar5) {
    *(int *)(&DAT_004a4888 + param_1 * 4) =
         (DAT_004aa594 * (iVar1 - param_1) + param_1 * iVar2) / iVar1;
    *(int *)(&DAT_004a6f48 + param_1 * 4) =
         (DAT_004aa59c * (iVar1 - param_1) + param_1 * iVar3) / iVar1;
  }
  if (DAT_004911cc == 1) {
    iVar4 = param_1 * DAT_004aa59c;
    *(int *)(&DAT_004a4888 + param_1 * 4) =
         (iVar2 * (iVar1 - param_1) + param_1 * DAT_004aa594) / iVar1;
    *(int *)(&DAT_004a6f48 + param_1 * 4) = (iVar3 * (iVar1 - param_1) + iVar4) / iVar1;
  }
  if ((DAT_00491140 < param_1) && (2 < DAT_004911cc)) {
    *(int *)(&DAT_004a4888 + param_1 * 4) =
         (DAT_004aa594 * (iVar1 - param_1) + param_1 * iVar2) / iVar1;
    *(int *)(&DAT_004a6f48 + param_1 * 4) =
         (DAT_004aa59c * (iVar1 - param_1) + param_1 * iVar3) / iVar1;
  }
  iVar1 = DAT_004aa59c;
  if ((2 < DAT_004911cc) &&
     (((param_1 <= DAT_00491140 || (DAT_0049118c == 2)) || (-0x1e < DAT_004a5b80)))) {
    *(int *)(&DAT_004a4888 + param_1 * 4) = (DAT_004aa594 + iVar2) / 2;
    *(int *)(&DAT_004a6f48 + param_1 * 4) = (iVar3 + iVar1) / 2;
  }
  return;
}

