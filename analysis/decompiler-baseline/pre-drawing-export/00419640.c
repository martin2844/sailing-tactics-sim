
void __cdecl FUN_00419640(CDC *param_1,undefined4 param_2,undefined4 param_3,int param_4)

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
  
  if (param_4 < 2) {
    local_34 = 1;
    uVar7 = DAT_004a7044 / 2 >> 0x1f;
    param_4 = (DAT_004a7044 / 2 ^ uVar7) - uVar7;
  }
  else {
    param_4 = 0;
    local_34 = 1;
  }
  do {
    if (local_34 == 1) {
      iVar1 = DAT_004aa1b8 + DAT_004aa1bc;
      local_24 = DAT_004aa2b8 + DAT_004aa2bc;
      iVar2 = DAT_004aa1c4 + DAT_004aa1bc * 3;
      iVar2 = iVar2 + (iVar2 >> 0x1f & 3U);
      iVar3 = DAT_004aa2c4 + DAT_004aa2bc * 3;
      iVar3 = iVar3 + (iVar3 >> 0x1f & 3U);
      iVar4 = DAT_004aa1c0 + DAT_004aa1b8 * 3;
      iVar4 = iVar4 + (iVar4 >> 0x1f & 3U);
      iVar5 = DAT_004aa2c0;
      iVar6 = DAT_004aa2b8;
    }
    else {
      iVar1 = DAT_004aa1e0 + DAT_004aa1dc;
      local_24 = DAT_004aa2e0 + DAT_004aa2dc;
      iVar2 = DAT_004aa1d4 + DAT_004aa1dc * 3;
      iVar2 = iVar2 + (iVar2 >> 0x1f & 3U);
      iVar3 = DAT_004aa2d4 + DAT_004aa2dc * 3;
      iVar3 = iVar3 + (iVar3 >> 0x1f & 3U);
      iVar4 = DAT_004aa1d8 + DAT_004aa1e0 * 3;
      iVar4 = iVar4 + (iVar4 >> 0x1f & 3U);
      iVar5 = DAT_004aa2d8;
      iVar6 = DAT_004aa2e0;
    }
    local_24 = local_24 / 2;
    iVar5 = iVar5 + iVar6 * 3;
    iVar8 = (int)(iVar5 + (iVar5 >> 0x1f & 3U)) >> 2;
    iVar5 = ((iVar4 >> 2) + (iVar2 >> 2)) / 2;
    iVar6 = (iVar8 + (iVar3 >> 2)) / 2;
    if (DAT_004a7044 < 1) {
      local_30 = aiStack_18 + local_34;
      piVar9 = aiStack_18 + local_34 + 3;
      *local_30 = ((iVar2 >> 2) * param_4 + iVar5) / (param_4 + 1);
      iVar2 = ((iVar3 >> 2) * param_4 + iVar6) / (param_4 + 1);
    }
    else {
      local_30 = aiStack_18 + local_34;
      piVar9 = aiStack_18 + local_34 + 3;
      *local_30 = ((iVar4 >> 2) * param_4 + iVar5) / (param_4 + 1);
      iVar2 = (iVar8 * param_4 + iVar6) / (param_4 + 1);
    }
    *piVar9 = iVar2;
    if (DAT_004a4dec != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
    }
    FUN_004706bd(param_1,local_20,iVar1 / 2,local_24);
    CDC::LineTo(param_1,*local_30,*piVar9);
    local_34 = local_34 + 1;
  } while (local_34 < 3);
  FUN_004706bd(param_1,local_20,aiStack_18[1],local_8);
  CDC::LineTo(param_1,aiStack_18[2],local_4);
  DAT_004aa708 = (aiStack_18[1] + aiStack_18[2]) / 2;
  DAT_004abe68 = (local_8 + local_4) / 2;
  (**(code **)(*(int *)param_1 + 0x2c))(7);
  return;
}

