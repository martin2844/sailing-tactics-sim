
bool __cdecl FUN_0045da50(int *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  if (DAT_004a22bc == 0) {
    return false;
  }
  uVar7 = param_1[5];
  if ((uVar7 == DAT_004a2350) && (uVar7 == DAT_004a2360)) goto LAB_0045dc24;
  if (DAT_004aec68 == 0) {
    FUN_0045dcc0(1,1,uVar7,4,1,0,0,2,0,0,0);
    uVar7 = param_1[5];
    uVar11 = 0;
    uVar3 = 0;
    uVar10 = 0;
    uVar4 = 2;
    uVar1 = 0;
    uVar9 = 5;
    uVar8 = 10;
LAB_0045dc18:
    uVar5 = 0;
    iVar6 = 1;
  }
  else {
    if (DAT_004aed08 != 0) {
      uVar10 = (uint)DAT_004aed0c._2_2_;
      uVar3 = 0;
      uVar1 = 0;
    }
    else {
      uVar3 = DAT_004aed0c & 0xffff;
      uVar10 = 0;
      uVar1 = (uint)DAT_004aed0c._2_2_;
    }
    FUN_0045dcc0(1,(uint)(DAT_004aed08 == 0),uVar7,(uint)DAT_004aed0a,uVar1,uVar3,uVar10,
                 DAT_004aed10 & 0xffff,DAT_004aed10 >> 0x10,DAT_004aed14 & 0xffff,
                 DAT_004aed14 >> 0x10);
    if (DAT_004aecb4 == 0) {
      uVar11 = (uint)DAT_004aecc0._2_2_;
      uVar3 = DAT_004aecc0 & 0xffff;
      uVar10 = (uint)DAT_004aecbc._2_2_;
      uVar4 = DAT_004aecbc & 0xffff;
      uVar1 = DAT_004aecb8 & 0xffff;
      uVar9 = (uint)DAT_004aecb8._2_2_;
      uVar8 = (uint)DAT_004aecb6;
      uVar7 = param_1[5];
      goto LAB_0045dc18;
    }
    uVar11 = (uint)DAT_004aecc0._2_2_;
    uVar3 = DAT_004aecc0 & 0xffff;
    uVar10 = (uint)DAT_004aecbc._2_2_;
    uVar5 = (uint)DAT_004aecb8._2_2_;
    uVar4 = DAT_004aecbc & 0xffff;
    uVar7 = param_1[5];
    uVar8 = (uint)DAT_004aecb6;
    uVar1 = 0;
    uVar9 = 0;
    iVar6 = 0;
  }
  FUN_0045dcc0(0,iVar6,uVar7,uVar8,uVar9,uVar1,uVar5,uVar4,uVar10,uVar3,uVar11);
LAB_0045dc24:
  iVar6 = param_1[7];
  if (DAT_004a2354 < DAT_004a2364) {
    if ((iVar6 < DAT_004a2354) || (DAT_004a2364 < iVar6)) {
      return false;
    }
    if ((DAT_004a2354 < iVar6) && (iVar6 < DAT_004a2364)) {
      return true;
    }
  }
  else {
    if ((iVar6 < DAT_004a2364) || (DAT_004a2354 < iVar6)) {
      return true;
    }
    if ((DAT_004a2364 < iVar6) && (iVar6 < DAT_004a2354)) {
      return false;
    }
  }
  iVar2 = (*param_1 + (param_1[1] + param_1[2] * 0x3c) * 0x3c) * 1000;
  if (iVar6 != DAT_004a2354) {
    return iVar2 < DAT_004a2368;
  }
  return DAT_004a2358 <= iVar2;
}

