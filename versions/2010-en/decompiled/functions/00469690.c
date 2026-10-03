
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00469690(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  
  if (((((-1 < param_2) && (param_2 <= DAT_004fe624)) && (-1 < param_3)) &&
      (param_3 <= DAT_004fe2a8)) &&
     ((param_6 != 1 || ((param_2 <= DAT_004fe624 / 3 && (DAT_004fe2a8 / 2 <= param_3)))))) {
    iVar2 = DAT_004da20c;
    if (param_6 != 0) {
      iVar2 = *(int *)(&DAT_0050f6d0 + param_8 * 4);
    }
    (**(code **)(*param_1 + 0x2c))(param_1,6);
    param_6 = 1;
    uVar3 = -(uint)(param_7 != 1) & 5;
    iVar4 = uVar3 + 4;
    if (uVar3 != 0xfffffffc) {
      param_7 = 0x5a;
      param_8 = 0x28;
      piVar6 = param_1;
      do {
        if (0 < param_4) {
          if ((iVar2 < 0x15) || (piVar6 = (int *)0x12c, iVar2 < 0x15)) {
            piVar6 = (int *)0xfa;
          }
          if (iVar2 < 9) {
            piVar6 = (int *)0x96;
          }
          if (iVar2 < 5) {
            piVar6 = (int *)0x4b;
          }
        }
        if (param_4 == 0) {
          if (0x3b < iVar2) {
            piVar6 = (int *)0x100;
          }
          if ((0x27 < iVar2) && (iVar2 < 0x3c)) {
            piVar6 = (int *)0x80;
          }
          if (iVar2 < 0x15) {
LAB_004697c0:
            piVar6 = (int *)0x20;
          }
          else {
            if (iVar2 < 0x28) {
              piVar6 = (int *)0x40;
            }
            if (iVar2 < 0x15) goto LAB_004697c0;
          }
          if (iVar2 < 9) {
            piVar6 = (int *)0x10;
          }
          if (iVar2 < 5) {
            piVar6 = (int *)0x8;
          }
          uVar3 = param_6 >> 0x1f;
          if (((param_6 ^ uVar3) - uVar3 & 1 ^ uVar3) == uVar3) {
            piVar6 = (int *)((int)piVar6 + 10);
          }
          if (((param_6 ^ uVar3) - uVar3 & 3 ^ uVar3) == uVar3) {
            piVar6 = piVar6 + 5;
          }
          iVar1 = *(int *)(&DAT_00534fe0 + param_5 * 4);
          if (iVar1 < 0x2711) {
            piVar6 = (int *)(((int)piVar6 + 0xf) * 3);
          }
          if (iVar1 < 0x2bd) {
            piVar6 = (int *)((int)piVar6 * 2);
          }
          if (iVar1 < 0x97) {
            piVar6 = (int *)((int)piVar6 * 2);
          }
        }
        if (300 < (int)piVar6) {
          piVar6 = (int *)0x12c;
        }
        iVar1 = param_7;
        if (iVar4 == 9) {
          iVar1 = param_8;
        }
        iVar1 = FUN_0041bc20(iVar1);
        iVar1 = FUN_0041bc20(iVar1);
        iVar5 = 10;
        if (*(double *)(&DAT_004fb5e0 + param_5 * 8) <= _DAT_004cc5f0) {
          iVar5 = 5;
        }
        if (DAT_005363e4 == 0) {
          uVar7 = 1;
        }
        else {
          uVar7 = 0xffffffff;
        }
        FUN_00424320(param_1,((&DAT_004f85c8)[iVar1] * iVar5) / (int)piVar6 + param_2,
                     ((&DAT_004f1740)[iVar1] * iVar5) / (int)piVar6 + param_3,uVar7);
        param_6 = param_6 + 1;
        param_8 = param_8 + 0x28;
        param_7 = param_7 + 0x5a;
      } while (param_6 <= iVar4);
    }
  }
  return;
}

