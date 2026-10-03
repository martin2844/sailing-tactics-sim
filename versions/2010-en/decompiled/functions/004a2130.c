
bool FUN_004a2130(int *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  
  if (DAT_004f047c == 0) {
    return false;
  }
  iVar6 = param_1[5];
  if ((iVar6 == DAT_004f0510) && (iVar6 == DAT_004f0520)) goto LAB_004a2304;
  if (DAT_005387c0 == 0) {
    FUN_004a23a0(1,1,iVar6,4,1,0,0,2,0,0,0);
    iVar6 = param_1[5];
    uVar8 = 0;
    uVar3 = 0;
    uVar10 = 0;
    uVar4 = 2;
    uVar1 = 0;
    uVar9 = 5;
    uVar7 = 10;
LAB_004a22f8:
    uVar5 = 1;
    uVar11 = 0;
  }
  else {
    if (DAT_00538860 != 0) {
      uVar3 = 0;
      uVar8 = 0;
      uVar10 = DAT_00538864._2_2_;
    }
    else {
      uVar3 = DAT_00538864 & 0xffff;
      uVar8 = DAT_00538864._2_2_;
      uVar10 = 0;
    }
    FUN_004a23a0(1,DAT_00538860 == 0,iVar6,DAT_00538862,uVar8,uVar3,uVar10,DAT_00538868 & 0xffff,
                 DAT_00538868 >> 0x10,DAT_0053886c & 0xffff,DAT_0053886c >> 0x10);
    uVar8 = DAT_00538818._2_2_;
    uVar10 = DAT_00538814._2_2_;
    uVar7 = DAT_0053880e;
    if (DAT_0053880c == 0) {
      uVar3 = DAT_00538818 & 0xffff;
      uVar4 = DAT_00538814 & 0xffff;
      uVar1 = DAT_00538810 & 0xffff;
      iVar6 = param_1[5];
      uVar9 = DAT_00538810._2_2_;
      goto LAB_004a22f8;
    }
    uVar3 = DAT_00538818 & 0xffff;
    uVar4 = DAT_00538814 & 0xffff;
    iVar6 = param_1[5];
    uVar1 = 0;
    uVar9 = 0;
    uVar5 = 0;
    uVar11 = DAT_00538810._2_2_;
  }
  FUN_004a23a0(0,uVar5,iVar6,uVar7,uVar9,uVar1,uVar11,uVar4,uVar10,uVar3,uVar8);
LAB_004a2304:
  iVar6 = param_1[7];
  if (DAT_004f0514 < DAT_004f0524) {
    if ((iVar6 < DAT_004f0514) || (DAT_004f0524 < iVar6)) {
      return false;
    }
    if ((DAT_004f0514 < iVar6) && (iVar6 < DAT_004f0524)) {
      return true;
    }
  }
  else {
    if ((iVar6 < DAT_004f0524) || (DAT_004f0514 < iVar6)) {
      return true;
    }
    if ((DAT_004f0524 < iVar6) && (iVar6 < DAT_004f0514)) {
      return false;
    }
  }
  iVar2 = (*param_1 + (param_1[1] + param_1[2] * 0x3c) * 0x3c) * 1000;
  if (iVar6 != DAT_004f0514) {
    return iVar2 < DAT_004f0528;
  }
  return DAT_004f0518 <= iVar2;
}

