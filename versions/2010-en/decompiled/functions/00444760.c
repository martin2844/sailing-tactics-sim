
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */

void __cdecl FUN_00444760(void)

{
  double dVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  int *local_10;
  int local_c;
  int local_8;
  int local_4;
  
  if (0 < DAT_004da194) {
    iVar7 = 0;
    local_c = 0x1f5;
    puVar6 = &DAT_00500bf8;
    local_10 = &DAT_004fe2b4;
    local_8 = 0;
    iVar5 = 0;
    local_4 = DAT_004da194;
    do {
      dVar1 = *(double *)((int)&DAT_004f6c18 + iVar7);
      *(int *)((int)&DAT_00513d78 + local_8) =
           (int)(longlong)*(double *)((int)&DAT_004f6b00 + iVar7);
      iVar2 = *(int *)((int)&DAT_004feccc + iVar5);
      *(int *)((int)&DAT_00526290 + local_8) = (int)(longlong)dVar1;
      *puVar6 = (uint)(iVar2 < 0x5a);
      iVar2 = *(int *)((int)&DAT_004fe8ac + iVar5);
      if (0 < iVar2) {
        if (*puVar6 == 1) {
          *puVar6 = 3;
        }
        if ((0 < iVar2) && (*puVar6 == 0)) {
          *puVar6 = 2;
        }
      }
      if (0 < *local_10) {
        *puVar6 = *puVar6 + 10;
      }
      if (1 < DAT_00534ea8) {
        iVar2 = (local_c + DAT_00534ea8) * 4;
        iVar4 = DAT_00534ea8 + -1;
        puVar3 = &DAT_00500420 + local_c + DAT_00534ea8;
        do {
          *(undefined4 *)((int)&DAT_005135a0 + iVar2) = *(undefined4 *)((int)&DAT_0051359c + iVar2);
          *(undefined4 *)((int)&DAT_00525ab8 + iVar2) = *(undefined4 *)((int)&DAT_00525ab4 + iVar2);
          *puVar3 = puVar3[-1];
          iVar2 = iVar2 + -4;
          iVar4 = iVar4 + -1;
          puVar3 = puVar3 + -1;
        } while (iVar4 != 0);
      }
      local_10 = local_10 + 1;
      iVar7 = iVar7 + 8;
      iVar5 = iVar5 + 4;
      local_8 = local_8 + 0x7d4;
      puVar6 = puVar6 + 0x1f5;
      local_c = local_c + 0x1f5;
      local_4 = local_4 + -1;
    } while (local_4 != 0);
  }
  return;
}

