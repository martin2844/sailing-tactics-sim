
void __cdecl FUN_00431960(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
  iVar3 = DAT_004fe2a0;
  iVar2 = DAT_004fe094;
  iVar1 = DAT_004da194 + 1;
  bVar5 = DAT_004da1d8 == 2;
  *(undefined4 *)(&DAT_004f8538 + param_1 * 4) = 0;
  if (bVar5) {
    *(int *)(&DAT_004f4d78 + param_1 * 4) =
         (DAT_00536410 * (iVar1 - param_1) + param_1 * iVar2) / iVar1;
    *(int *)(&DAT_004fc350 + param_1 * 4) =
         (DAT_00536414 * (iVar1 - param_1) + param_1 * iVar3) / iVar1;
  }
  if (DAT_004da1d8 == 1) {
    iVar4 = param_1 * DAT_00536414;
    *(int *)(&DAT_004f4d78 + param_1 * 4) =
         (iVar2 * (iVar1 - param_1) + param_1 * DAT_00536410) / iVar1;
    *(int *)(&DAT_004fc350 + param_1 * 4) = (iVar3 * (iVar1 - param_1) + iVar4) / iVar1;
  }
  if ((DAT_004da140 < param_1) && (2 < DAT_004da1d8)) {
    *(int *)(&DAT_004f4d78 + param_1 * 4) =
         (DAT_00536410 * (iVar1 - param_1) + param_1 * iVar2) / iVar1;
    *(int *)(&DAT_004fc350 + param_1 * 4) =
         (DAT_00536414 * (iVar1 - param_1) + param_1 * iVar3) / iVar1;
  }
  iVar1 = DAT_00536414;
  if ((2 < DAT_004da1d8) &&
     (((param_1 <= DAT_004da140 || (DAT_004da194 == 2)) || (-0x1e < DAT_004f8cd0)))) {
    *(int *)(&DAT_004f4d78 + param_1 * 4) = (DAT_00536410 + iVar2) / 2;
    *(int *)(&DAT_004fc350 + param_1 * 4) = (iVar3 + iVar1) / 2;
  }
  return;
}

