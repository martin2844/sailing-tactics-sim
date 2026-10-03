
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */

void __cdecl FUN_0043be00(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  longlong lVar10;
  int local_8;
  int *local_4;
  
  iVar7 = DAT_004da194;
  if (param_1 == 1) {
    DAT_005231a8 = DAT_004fe8ac;
  }
  *(undefined4 *)(&DAT_004fe8a8 + param_1 * 4) = 0;
  *(undefined4 *)(&DAT_004f4208 + param_1 * 4) = 0;
  *(undefined4 *)(&DAT_004f7f98 + param_1 * 4) = 0;
  *(undefined4 *)(&DAT_005239c8 + param_1 * 4) = 0;
  if (0 < iVar7) {
    local_4 = (int *)(&DAT_00535740 + iVar7 * 4);
    do {
      if (param_1 != iVar7) {
        uVar8 = (int)(longlong)*(double *)(&DAT_004f6af8 + iVar7 * 8) -
                (int)(longlong)*(double *)(&DAT_004f6af8 + param_1 * 8);
        uVar5 = (int)(longlong)*(double *)(&DAT_004f6c10 + param_1 * 8) -
                (int)(longlong)*(double *)(&DAT_004f6c10 + iVar7 * 8);
        iVar6 = ((uVar8 ^ (int)uVar8 >> 0x1f) - ((int)uVar8 >> 0x1f)) +
                ((uVar5 ^ (int)uVar5 >> 0x1f) - ((int)uVar5 >> 0x1f));
        if ((iVar6 < 0x1e) &&
           (*(int *)(&DAT_00522ff0 + param_1 * 4) == *(int *)(&DAT_00522ff0 + iVar7 * 4))) {
          *(undefined4 *)(&DAT_005239c8 + param_1 * 4) = 1;
        }
        if (iVar6 < 0x50) {
          iVar3 = FUN_00427ee0(uVar8,uVar5);
          uVar5 = *(int *)(&DAT_00535890 + param_1 * 4) - iVar3 >> 0x1f;
          iVar9 = (*(int *)(&DAT_00535890 + param_1 * 4) - iVar3 ^ uVar5) - uVar5;
          if (0xb4 < iVar9) {
            iVar9 = 0x168 - iVar9;
          }
          uVar5 = *(int *)(&DAT_00535740 + param_1 * 4) - iVar3 >> 0x1f;
          iVar3 = FUN_0041bc20((*(int *)(&DAT_00535740 + param_1 * 4) - iVar3 ^ uVar5) - uVar5);
          uVar1 = DAT_004f8cd0;
          if (0xb4 < iVar3) {
            iVar3 = 0x168 - iVar3;
          }
          iVar4 = (((int)(&DAT_004fb380)[param_1] < 0xb) - 1 & 0xfffffff6) + 0x1e;
          if (((iVar3 < 0x28) && (iVar6 < iVar4)) && (DAT_004da140 < param_1)) {
            *(undefined4 *)(&DAT_004f4208 + param_1 * 4) = 1;
            *(undefined4 *)(&DAT_00522dd0 + param_1 * 4) = uVar1;
          }
          iVar2 = DAT_005363bc;
          if (((iVar3 < 0x19) && (iVar6 < iVar4)) &&
             ((DAT_005363bc == 0 && (param_1 <= DAT_004da140)))) {
            *(undefined4 *)(&DAT_004f4208 + param_1 * 4) = 1;
          }
          if (((iVar3 < 0x1e) && (iVar6 < iVar4)) && ((iVar2 == 1 && (param_1 <= DAT_004da140)))) {
            *(undefined4 *)(&DAT_004f4208 + param_1 * 4) = 1;
          }
          iVar4 = *(int *)(&DAT_00522ff0 + param_1 * 4);
          if (iVar4 != *(int *)(&DAT_00522ff0 + iVar7 * 4)) {
            *(undefined4 *)(&DAT_004f4208 + param_1 * 4) = 0;
          }
          if (DAT_004da194 == 2) {
            if (iVar4 == 1) {
              lVar10 = FUN_00464050(param_1,iVar7);
              uVar5 = (int)(uint)lVar10 >> 0x1f;
              local_8 = ((9 < (int)(((uint)lVar10 ^ uVar5) - uVar5)) - 1 & 10) + 0x41;
            }
            iVar4 = *(int *)(&DAT_00522ff0 + param_1 * 4);
            if (iVar4 == -1) {
              local_8 = 0x32;
            }
          }
          else {
            local_8 = (-(uint)(iVar4 != 1) & 0xfffffff6) + 0x28;
          }
          if ((((iVar6 < local_8) && (100 < iVar3)) &&
              (iVar4 == *(int *)(&DAT_00522ff0 + iVar7 * 4))) && ((iVar9 < 0x78 && (iVar4 == 1)))) {
            *(int *)(&DAT_004f7f98 + param_1 * 4) = iVar7;
          }
          if (iVar9 < 0x19) {
            *(uint *)(&DAT_004fe8a8 + param_1 * 4) =
                 (-(uint)(iVar4 != *(int *)(&DAT_00522ff0 + iVar7 * 4)) & 10) + 2;
          }
          if (iVar3 < 0x17) {
            if (iVar4 == *(int *)(&DAT_00522ff0 + iVar7 * 4)) {
              if ((*(int *)(&DAT_004fecc8 + param_1 * 4) < 0x3c) &&
                 (*(int *)(&DAT_004fecc8 + iVar7 * 4) < 0x50)) {
                *(undefined4 *)(&DAT_004fe8a8 + param_1 * 4) = 3;
              }
              goto LAB_0043c09f;
            }
LAB_0043c0a8:
            iVar3 = FUN_0041bc20(*(int *)(&DAT_00535740 + param_1 * 4) - *local_4);
            if (iVar3 < 0x1e) goto LAB_0043c0e6;
            iVar3 = FUN_0041bc20((*(int *)(&DAT_00535740 + param_1 * 4) - *local_4) + 0xb4);
            iVar9 = 8;
            if (iVar3 < 0x1e) goto LAB_0043c0e6;
          }
          else {
LAB_0043c09f:
            if (iVar4 != *(int *)(&DAT_00522ff0 + iVar7 * 4)) goto LAB_0043c0a8;
LAB_0043c0e6:
            iVar9 = 6;
          }
          if (DAT_005363b8 == 1) {
            iVar9 = 8;
          }
          if (900 < DAT_004fe624) {
            iVar9 = iVar9 + -1;
          }
          if (iVar6 < iVar9) {
            FUN_0043c440(iVar7,param_1,iVar6);
          }
        }
      }
      iVar7 = iVar7 + -1;
      local_4 = local_4 + -1;
    } while (0 < iVar7);
  }
  return;
}

