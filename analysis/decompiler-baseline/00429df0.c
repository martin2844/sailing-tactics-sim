
void __cdecl FUN_00429df0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  float10 fVar5;
  float10 extraout_ST0;
  float10 extraout_ST1;
  longlong lVar6;
  
  iVar1 = *(int *)(&DAT_004a7bc8 + param_2 * 4);
  iVar3 = ((&DAT_004a3450)[iVar1] * *(int *)(&DAT_004a6338 + param_2 * 4)) / 10 + param_1;
  iVar2 = ((&DAT_004a54a0)[iVar1] * *(int *)(&DAT_004a6338 + param_2 * 4)) / 10;
  lVar6 = __ftol();
  *(int *)(&DAT_004ab9e8 + param_2 * 4) = (int)lVar6;
  if (iVar3 == 0) {
    *(undefined4 *)(&DAT_004a47f8 + param_2 * 4) = 0x5a;
    return;
  }
  if (iVar2 == 0) {
    if (iVar1 < 5) {
      *(undefined4 *)(&DAT_004a47f8 + param_2 * 4) = 0;
      return;
    }
    if (-1 < iVar1) goto LAB_00429f23;
  }
  fVar4 = (float10)iVar2;
  fVar5 = (float10)iVar3;
  if (0 < iVar3) {
    fpatan(fVar4 / fVar5,(float10)1);
    lVar6 = __ftol();
    *(int *)(&DAT_004a47f8 + param_2 * 4) = (int)lVar6;
    fVar5 = extraout_ST0;
    fVar4 = extraout_ST1;
  }
  if (iVar3 < 0) {
    fpatan(-(fVar5 / fVar4),(float10)1);
    lVar6 = __ftol();
    *(int *)(&DAT_004a47f8 + param_2 * 4) = 0x5a - (int)lVar6;
  }
  if (iVar1 < 0xb4) {
    return;
  }
LAB_00429f23:
  *(undefined4 *)(&DAT_004a47f8 + param_2 * 4) = 0xb3;
  return;
}

