
void __cdecl FUN_00423980(int *param_1,double param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  int local_34;
  int *local_30;
  int local_24;
  int local_20 [2];
  int aiStack_18 [4];
  int local_8;
  int local_4;
  
  if (param_3 < 2) {
    local_34 = 1;
    uVar7 = DAT_004fdfd0 / 2 >> 0x1f;
    param_3 = (DAT_004fdfd0 / 2 ^ uVar7) - uVar7;
  }
  else {
    param_3 = 0;
    local_34 = 1;
  }
  do {
    if (local_34 == 1) {
      iVar1 = DAT_005228f8 + DAT_005228fc;
      local_24 = DAT_005229f8 + DAT_005229fc;
      iVar2 = DAT_00522904 + DAT_005228fc * 3;
      iVar2 = iVar2 + (iVar2 >> 0x1f & 3U);
      iVar3 = DAT_00522a04 + DAT_005229fc * 3;
      iVar3 = iVar3 + (iVar3 >> 0x1f & 3U);
      iVar4 = DAT_00522900 + DAT_005228f8 * 3;
      iVar4 = iVar4 + (iVar4 >> 0x1f & 3U);
      iVar5 = DAT_00522a00;
      iVar6 = DAT_005229f8;
    }
    else {
      iVar1 = DAT_00522920 + DAT_0052291c;
      local_24 = DAT_00522a20 + DAT_00522a1c;
      iVar2 = DAT_00522914 + DAT_0052291c * 3;
      iVar2 = iVar2 + (iVar2 >> 0x1f & 3U);
      iVar3 = DAT_00522a14 + DAT_00522a1c * 3;
      iVar3 = iVar3 + (iVar3 >> 0x1f & 3U);
      iVar4 = DAT_00522918 + DAT_00522920 * 3;
      iVar4 = iVar4 + (iVar4 >> 0x1f & 3U);
      iVar5 = DAT_00522a18;
      iVar6 = DAT_00522a20;
    }
    local_24 = local_24 / 2;
    iVar5 = iVar5 + iVar6 * 3;
    iVar8 = (int)(iVar5 + (iVar5 >> 0x1f & 3U)) >> 2;
    iVar5 = ((iVar4 >> 2) + (iVar2 >> 2)) / 2;
    iVar6 = (iVar8 + (iVar3 >> 2)) / 2;
    if (DAT_004fdfd0 < 1) {
      local_30 = aiStack_18 + local_34;
      piVar9 = aiStack_18 + local_34 + 3;
      *local_30 = ((iVar2 >> 2) * param_3 + iVar5) / (param_3 + 1);
      iVar2 = ((iVar3 >> 2) * param_3 + iVar6) / (param_3 + 1);
    }
    else {
      local_30 = aiStack_18 + local_34;
      piVar9 = aiStack_18 + local_34 + 3;
      *local_30 = ((iVar4 >> 2) * param_3 + iVar5) / (param_3 + 1);
      iVar2 = (iVar8 * param_3 + iVar6) / (param_3 + 1);
    }
    *piVar9 = iVar2;
    if (DAT_004f7084 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004f7084);
    }
    FUN_004b4d9d(param_1,local_20,iVar1 / 2,local_24);
    CDC::LineTo(param_1,*local_30,*piVar9);
    local_34 = local_34 + 1;
  } while (local_34 < 3);
  FUN_004b4d9d(param_1,local_20,aiStack_18[1],local_8);
  CDC::LineTo(param_1,aiStack_18[2],local_4);
  DAT_00522fc0 = (aiStack_18[1] + aiStack_18[2]) / 2;
  DAT_00535560 = (local_8 + local_4) / 2;
  (**(code **)(*param_1 + 0x2c))(param_1,7);
  return;
}

