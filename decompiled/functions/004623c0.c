
undefined4 __cdecl FUN_004623c0(byte *param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  byte *pbVar4;
  int iVar5;
  LPWSTR pWVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  byte *pbVar10;
  byte *pbVar11;
  bool bVar12;
  
  if (param_1 == (byte *)0x0) {
    return 0xffffffff;
  }
  pbVar4 = FUN_00457780(param_1,0x3d);
  if (pbVar4 == (byte *)0x0) {
    return 0xffffffff;
  }
  if (param_1 == pbVar4) {
    return 0xffffffff;
  }
  bVar12 = pbVar4[1] == 0;
  if (DAT_004ae944 == DAT_004ae948) {
    DAT_004ae944 = FUN_00462650(DAT_004ae944);
  }
  if (DAT_004ae944 == (int *)0x0) {
    if ((param_2 == 0) || (DAT_004ae94c == (undefined4 *)0x0)) {
      if (bVar12) {
        return 0;
      }
      DAT_004ae944 = (int *)FUN_00457640(4);
      if (DAT_004ae944 == (int *)0x0) {
        return 0xffffffff;
      }
      *DAT_004ae944 = 0;
      if (DAT_004ae94c == (undefined4 *)0x0) {
        DAT_004ae94c = (undefined4 *)FUN_00457640(4);
        if (DAT_004ae94c == (undefined4 *)0x0) {
          return 0xffffffff;
        }
        *DAT_004ae94c = 0;
      }
    }
    else {
      iVar5 = FUN_00461780();
      if (iVar5 != 0) {
        return 0xffffffff;
      }
    }
  }
  piVar7 = DAT_004ae944;
  pWVar6 = (LPWSTR)(pbVar4 + -(int)param_1);
  iVar5 = FUN_004625d0(param_1,pWVar6);
  if ((iVar5 < 0) || (*piVar7 == 0)) {
    if (bVar12) {
      return 0;
    }
    if (iVar5 < 0) {
      iVar5 = -iVar5;
    }
    piVar7 = FUN_0045a070(piVar7,iVar5 * 4 + 8);
    if (piVar7 == (int *)0x0) {
      return 0xffffffff;
    }
    piVar7[iVar5] = (int)param_1;
    piVar7[iVar5 + 1] = 0;
    DAT_004ae944 = piVar7;
  }
  else if (bVar12) {
    FUN_00457710((undefined *)piVar7[iVar5]);
    iVar2 = piVar7[iVar5];
    piVar3 = piVar7 + iVar5;
    while (iVar2 != 0) {
      *piVar3 = piVar3[1];
      iVar5 = iVar5 + 1;
      iVar2 = piVar3[1];
      piVar3 = piVar3 + 1;
    }
    piVar7 = FUN_0045a070(piVar7,iVar5 * 4);
    if (piVar7 != (int *)0x0) {
      DAT_004ae944 = piVar7;
    }
  }
  else {
    piVar7[iVar5] = (int)param_1;
  }
  if (param_2 != 0) {
    uVar8 = 0xffffffff;
    pbVar4 = param_1;
    do {
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      bVar1 = *pbVar4;
      pbVar4 = pbVar4 + 1;
    } while (bVar1 != 0);
    pbVar4 = (byte *)FUN_00457640(~uVar8 + 1);
    if (pbVar4 != (byte *)0x0) {
      uVar8 = 0xffffffff;
      do {
        pbVar10 = param_1;
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        pbVar10 = param_1 + 1;
        bVar1 = *param_1;
        param_1 = pbVar10;
      } while (bVar1 != 0);
      uVar8 = ~uVar8;
      pbVar10 = pbVar10 + -uVar8;
      pbVar11 = pbVar4;
      for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(undefined4 *)pbVar11 = *(undefined4 *)pbVar10;
        pbVar10 = pbVar10 + 4;
        pbVar11 = pbVar11 + 4;
      }
      for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *pbVar11 = *pbVar10;
        pbVar10 = pbVar10 + 1;
        pbVar11 = pbVar11 + 1;
      }
      pbVar4[(int)pWVar6] = 0;
      SetEnvironmentVariableA
                ((LPCSTR)pbVar4,(LPCSTR)(~-(uint)bVar12 & (uint)(pbVar4 + 1 + (int)pWVar6)));
      FUN_00457710(pbVar4);
      return 0;
    }
  }
  return 0;
}

