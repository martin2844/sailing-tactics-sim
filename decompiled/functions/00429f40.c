
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */

void __cdecl FUN_00429f40(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  longlong lVar10;
  int local_c;
  int *local_8;
  
  iVar5 = DAT_0049118c;
  if (param_1 == 1) {
    DAT_004aa830 = DAT_004a786c;
  }
  *(undefined4 *)(&DAT_004a7868 + param_1 * 4) = 0;
  bVar9 = iVar5 != 2;
  *(undefined4 *)(&DAT_004a40d0 + param_1 * 4) = 0;
  *(undefined4 *)(&DAT_004a6010 + param_1 * 4) = 0;
  *(undefined4 *)(&DAT_004aada0 + param_1 * 4) = 0;
  if (0 < iVar5) {
    local_8 = (int *)(&DAT_004ac018 + iVar5 * 4);
    do {
      if (param_1 != iVar5) {
        uVar7 = (int)(longlong)*(double *)(&DAT_004a49e8 + iVar5 * 8) -
                (int)(longlong)*(double *)(&DAT_004a49e8 + param_1 * 8);
        uVar4 = (int)(longlong)*(double *)(&DAT_004a4ae0 + param_1 * 8) -
                (int)(longlong)*(double *)(&DAT_004a4ae0 + iVar5 * 8);
        iVar6 = ((uVar7 ^ (int)uVar7 >> 0x1f) - ((int)uVar7 >> 0x1f)) +
                ((uVar4 ^ (int)uVar4 >> 0x1f) - ((int)uVar4 >> 0x1f));
        if ((iVar6 < 0x1e) &&
           (*(int *)(&DAT_004aa730 + param_1 * 4) == *(int *)(&DAT_004aa730 + iVar5 * 4))) {
          *(undefined4 *)(&DAT_004aada0 + param_1 * 4) = 1;
        }
        if (iVar6 < (int)((-(uint)bVar9 & 0xfffffff1) + 0x4b)) {
          iVar2 = FUN_0041bb10(uVar7,uVar4);
          uVar4 = *(int *)(&DAT_004aa5b0 + param_1 * 4) - iVar2 >> 0x1f;
          iVar8 = (*(int *)(&DAT_004aa5b0 + param_1 * 4) - iVar2 ^ uVar4) - uVar4;
          if (0xb4 < iVar8) {
            iVar8 = 0x168 - iVar8;
          }
          uVar4 = *(int *)(&DAT_004ac018 + param_1 * 4) - iVar2 >> 0x1f;
          iVar2 = FUN_00413cb0((*(int *)(&DAT_004ac018 + param_1 * 4) - iVar2 ^ uVar4) - uVar4);
          if (0xb4 < iVar2) {
            iVar2 = 0x168 - iVar2;
          }
          iVar3 = ((*(int *)(&DAT_004a6338 + param_1 * 4) < 0xb) - 1 & 0xfffffff6) + 0x1e;
          if (((iVar2 < 0x28) && (iVar6 < iVar3)) && (DAT_00491140 < param_1)) {
            *(undefined4 *)(&DAT_004a40d0 + param_1 * 4) = 1;
          }
          iVar1 = DAT_004ac904;
          if (((iVar2 < 0x19) && (iVar6 < iVar3)) &&
             ((DAT_004ac904 == 0 && (param_1 <= DAT_00491140)))) {
            *(undefined4 *)(&DAT_004a40d0 + param_1 * 4) = 1;
          }
          if (((iVar2 < 0x1e) && (iVar6 < iVar3)) && ((iVar1 == 1 && (param_1 <= DAT_00491140)))) {
            *(undefined4 *)(&DAT_004a40d0 + param_1 * 4) = 1;
          }
          iVar3 = *(int *)(&DAT_004aa730 + param_1 * 4);
          if (iVar3 != *(int *)(&DAT_004aa730 + iVar5 * 4)) {
            *(undefined4 *)(&DAT_004a40d0 + param_1 * 4) = 0;
          }
          if (DAT_0049118c == 2) {
            if (iVar3 == 1) {
              lVar10 = FUN_0044da90(param_1,iVar5);
              uVar4 = (int)(uint)lVar10 >> 0x1f;
              local_c = ((9 < (int)(((uint)lVar10 ^ uVar4) - uVar4)) - 1 & 10) + 0x41;
            }
            iVar3 = *(int *)(&DAT_004aa730 + param_1 * 4);
            if (iVar3 == -1) {
              local_c = 0x32;
            }
          }
          else {
            local_c = (-(uint)(iVar3 != 1) & 0xfffffff6) + 0x28;
          }
          if ((((iVar6 < local_c) && (100 < iVar2)) &&
              (iVar3 == *(int *)(&DAT_004aa730 + iVar5 * 4))) && ((iVar8 < 0x78 && (iVar3 == 1)))) {
            *(int *)(&DAT_004a6010 + param_1 * 4) = iVar5;
          }
          if (iVar8 < 0x19) {
            *(uint *)(&DAT_004a7868 + param_1 * 4) =
                 (-(uint)(iVar3 != *(int *)(&DAT_004aa730 + iVar5 * 4)) & 10) + 2;
          }
          if (iVar2 < 0x17) {
            if (iVar3 == *(int *)(&DAT_004aa730 + iVar5 * 4)) {
              if ((*(int *)(&DAT_004a7bc8 + param_1 * 4) < 0x3c) &&
                 (*(int *)(&DAT_004a7bc8 + iVar5 * 4) < 0x5a)) {
                *(undefined4 *)(&DAT_004a7868 + param_1 * 4) = 3;
              }
              goto LAB_0042a1e4;
            }
LAB_0042a1ed:
            iVar2 = FUN_00413cb0(*(int *)(&DAT_004ac018 + param_1 * 4) - *local_8);
            if (iVar2 < 0x1e) goto LAB_0042a22c;
            iVar2 = FUN_00413cb0((*(int *)(&DAT_004ac018 + param_1 * 4) - *local_8) + 0xb4);
            iVar8 = 8;
            if (iVar2 < 0x1e) goto LAB_0042a22c;
          }
          else {
LAB_0042a1e4:
            if (iVar3 != *(int *)(&DAT_004aa730 + iVar5 * 4)) goto LAB_0042a1ed;
LAB_0042a22c:
            iVar8 = 6;
          }
          if (DAT_004ac900 == 1) {
            iVar8 = 8;
          }
          if (900 < DAT_004a763c) {
            iVar8 = iVar8 + -1;
          }
          if (iVar6 < iVar8) {
            FUN_0042a530(iVar5,param_1,iVar6);
          }
        }
      }
      iVar5 = iVar5 + -1;
      local_8 = local_8 + -1;
    } while (0 < iVar5);
  }
  return;
}

