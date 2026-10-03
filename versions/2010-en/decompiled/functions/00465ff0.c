
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00465ff0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  float10 fVar5;
  
  iVar4 = 1;
  if (DAT_004da140 != 1) {
    iVar4 = param_1;
  }
  if (DAT_004da140 == 2) {
    uVar3 = param_1 >> 0x1f;
    iVar4 = (((param_1 ^ uVar3) - uVar3 & 1 ^ uVar3) != uVar3) + 1;
  }
  iVar2 = FUN_0041e000(0x370);
  fVar5 = (float10)fsin((float10)*(int *)(&DAT_004fbb90 + iVar4 * 4) * (float10)_DAT_004cc568);
  (&DAT_004f7220)[param_1] =
       (double)((((float10)*(double *)(&DAT_004f6af8 + iVar4 * 8) - fVar5 * (float10)_DAT_004ccb40)
                - (float10)_DAT_004cccb8) + (float10)iVar2);
  iVar2 = FUN_0041e000(0x370);
  uVar1 = *(undefined4 *)((int)&DAT_004f7220 + param_1 * 8 + 4);
  fVar5 = (float10)fcos((float10)*(int *)(&DAT_004fbb90 + iVar4 * 4) * (float10)_DAT_004cc568);
  fVar5 = (((float10)*(double *)(&DAT_004f6c10 + iVar4 * 8) - fVar5 * (float10)_DAT_004cc490) -
          (float10)_DAT_004cccb8) + (float10)iVar2;
  (&DAT_004ff038)[param_1] = (double)fVar5;
  fVar5 = FUN_00466230((double)CONCAT44(uVar1,*(undefined4 *)(&DAT_004f7220 + param_1)),
                       (double)fVar5,param_1);
  if (fVar5 < (float10)_DAT_004cc5a0) {
    iVar2 = FUN_0041e000(0x370);
    fVar5 = (float10)fsin((float10)*(int *)(&DAT_004fbb90 + iVar4 * 4) * (float10)_DAT_004cc568);
    (&DAT_004f7220)[param_1] =
         (double)((((float10)*(double *)(&DAT_004f6af8 + iVar4 * 8) - fVar5 * (float10)_DAT_004cc928
                   ) - (float10)_DAT_004cccb8) + (float10)iVar2);
    iVar2 = FUN_0041e000(0x370);
    fVar5 = (float10)fcos((float10)*(int *)(&DAT_004fbb90 + iVar4 * 4) * (float10)_DAT_004cc568);
    (&DAT_004ff038)[param_1] =
         (double)((((float10)*(double *)(&DAT_004f6c10 + iVar4 * 8) - fVar5 * (float10)_DAT_004cc488
                   ) - (float10)_DAT_004cccb8) + (float10)iVar2);
  }
  fVar5 = FUN_00466230((double)CONCAT44(*(undefined4 *)((int)&DAT_004f7220 + param_1 * 8 + 4),
                                        *(undefined4 *)(&DAT_004f7220 + param_1)),
                       (double)CONCAT44(*(undefined4 *)((int)&DAT_004ff038 + param_1 * 8 + 4),
                                        *(undefined4 *)(&DAT_004ff038 + param_1)),param_1);
  if (fVar5 < (float10)_DAT_004cc5a0) {
    iVar2 = FUN_0041e000(0x370);
    fVar5 = (float10)fsin((float10)*(int *)(&DAT_004fbb90 + iVar4 * 4) * (float10)_DAT_004cc568);
    (&DAT_004f7220)[param_1] =
         (double)((((float10)*(double *)(&DAT_004f6af8 + iVar4 * 8) - fVar5 * (float10)_DAT_004cc928
                   ) - (float10)_DAT_004cccb8) + (float10)iVar2);
    iVar2 = FUN_0041e000(0x370);
    fVar5 = (float10)fcos((float10)*(int *)(&DAT_004fbb90 + iVar4 * 4) * (float10)_DAT_004cc568);
    (&DAT_004ff038)[param_1] =
         (double)((((float10)*(double *)(&DAT_004f6c10 + iVar4 * 8) - fVar5 * (float10)_DAT_004cc488
                   ) - (float10)_DAT_004cccb8) + (float10)iVar2);
  }
  return;
}

