
undefined4 FUN_004a8290(int param_1)

{
  DWORD DVar1;
  HBRUSH pHVar2;
  uint uVar3;
  int iVar4;
  ushort uVar5;
  char *pcVar6;
  DWORD *pDVar7;
  DWORD *pDVar8;
  bool bVar9;
  int local_30;
  int local_2c [3];
  DWORD local_20 [4];
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  undefined4 local_4;
  
  if (DAT_00539a80 == 0) {
    return 0;
  }
  uVar3 = 0;
  do {
    uVar5 = (short)uVar3 + 1;
    DVar1 = GetSysColor((uint)(ushort)(&DAT_004d1528)[uVar3]);
    local_20[uVar3] = DVar1;
    uVar3 = (uint)uVar5;
  } while (uVar5 < 8);
  if (DAT_00539aa0 == 0x300) {
    local_20[0] = 0xffffff;
  }
  if (((local_8 == 0) || (local_20[1] == local_8)) && (local_8 = 0xc0c0c0, local_20[1] != 0x808080))
  {
    local_8 = 0x808080;
  }
  if (param_1 == 0) {
    iVar4 = 0x20;
    bVar9 = true;
    pcVar6 = &DAT_00539aa4;
    pDVar7 = local_20;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar9 = *pcVar6 == (char)*pDVar7;
      pcVar6 = pcVar6 + 1;
      pDVar7 = (DWORD *)((int)pDVar7 + 1);
    } while (bVar9);
    if (bVar9) {
      return 1;
    }
  }
  local_30 = FUN_004aa4c0(DAT_00539a98,0x67c7,local_c,local_20[1],local_20[2],local_20[0],local_10,
                          local_4);
  uVar3 = 0;
  do {
    uVar5 = (short)uVar3 + 1;
    pHVar2 = CreateSolidBrush(local_20[uVar3]);
    local_2c[uVar3] = (int)pHVar2;
    uVar3 = (uint)uVar5;
  } while (uVar5 < 3);
  uVar5 = 0;
  do {
    if (local_2c[uVar5] == 0) goto LAB_004a83e8;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 3);
  if (local_30 != 0) {
    FUN_004a71f0();
    DAT_00539ac4 = local_2c[0];
    DAT_00539ac8 = local_2c[1];
    DAT_00539acc = local_2c[2];
    pDVar7 = local_20;
    pDVar8 = (DWORD *)&DAT_00539aa4;
    for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
      *pDVar8 = *pDVar7;
      pDVar7 = pDVar7 + 1;
      pDVar8 = pDVar8 + 1;
    }
    DAT_00539ad0 = local_30;
    return 1;
  }
LAB_004a83e8:
  uVar5 = 0;
  do {
    uVar3 = (uint)uVar5;
    uVar5 = uVar5 + 1;
    FUN_004a71d0(local_2c + uVar3);
  } while (uVar5 < 3);
  FUN_004a71d0(&local_30);
  return 0;
}

