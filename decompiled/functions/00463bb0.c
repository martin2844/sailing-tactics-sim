
undefined4 __cdecl FUN_00463bb0(int param_1)

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
  HBITMAP local_30;
  int local_2c [3];
  DWORD local_20;
  uint local_1c;
  uint local_18;
  uint local_10;
  uint local_c;
  uint local_8;
  uint local_4;
  
  if (DAT_004aff40 == 0) {
    return 0;
  }
  uVar3 = 0;
  do {
    uVar5 = (short)uVar3 + 1;
    DVar1 = GetSysColor((uint)(ushort)(&DAT_00489880)[uVar3]);
    (&local_20)[uVar3] = DVar1;
    uVar3 = (uint)uVar5;
  } while (uVar5 < 8);
  if (DAT_004aff60 == 0x300) {
    local_20 = 0xffffff;
  }
  if (((local_8 == 0) || (local_1c == local_8)) && (local_8 = 0xc0c0c0, local_1c != 0x808080)) {
    local_8 = 0x808080;
  }
  if (param_1 == 0) {
    iVar4 = 0x20;
    bVar9 = true;
    pcVar6 = &DAT_004aff64;
    pDVar7 = &local_20;
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
  local_30 = FUN_00465de0(DAT_004aff58,(LPCSTR)0x67c7,local_c,local_1c,local_18,local_20,local_10,
                          local_4);
  uVar3 = 0;
  do {
    uVar5 = (short)uVar3 + 1;
    pHVar2 = CreateSolidBrush((&local_20)[uVar3]);
    local_2c[uVar3] = (int)pHVar2;
    uVar3 = (uint)uVar5;
  } while (uVar5 < 3);
  uVar5 = 0;
  do {
    if (local_2c[uVar5] == 0) goto LAB_00463d08;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 3);
  if (local_30 != (HBITMAP)0x0) {
    FUN_00462b10();
    DAT_004aff84 = local_2c[0];
    DAT_004aff88 = local_2c[1];
    DAT_004aff8c = local_2c[2];
    pDVar7 = &local_20;
    pDVar8 = (DWORD *)&DAT_004aff64;
    for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
      *pDVar8 = *pDVar7;
      pDVar7 = pDVar7 + 1;
      pDVar8 = pDVar8 + 1;
    }
    DAT_004aff90 = local_30;
    return 1;
  }
LAB_00463d08:
  uVar5 = 0;
  do {
    uVar3 = (uint)uVar5;
    uVar5 = uVar5 + 1;
    FUN_00462af0(local_2c + uVar3);
  } while (uVar5 < 3);
  FUN_00462af0(&local_30);
  return 0;
}

