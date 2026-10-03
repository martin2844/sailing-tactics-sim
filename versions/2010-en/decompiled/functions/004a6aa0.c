
undefined4 FUN_004a6aa0(char *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  LPCSTR lpName;
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  bool bVar11;
  
  if (param_1 == (char *)0x0) {
    return 0xffffffff;
  }
  pcVar4 = (char *)FUN_0049c040(param_1,0x3d);
  if (pcVar4 == (char *)0x0) {
    return 0xffffffff;
  }
  if (param_1 == pcVar4) {
    return 0xffffffff;
  }
  bVar11 = pcVar4[1] == '\0';
  if (DAT_0053849c == DAT_005384a0) {
    DAT_0053849c = (int *)FUN_004a6d30(DAT_0053849c);
  }
  if (DAT_0053849c == (int *)0x0) {
    if ((param_2 == 0) || (DAT_005384a4 == (undefined4 *)0x0)) {
      if (bVar11) {
        return 0;
      }
      DAT_0053849c = (int *)FUN_0049bf00(4);
      if (DAT_0053849c == (int *)0x0) {
        return 0xffffffff;
      }
      *DAT_0053849c = 0;
      if (DAT_005384a4 == (undefined4 *)0x0) {
        DAT_005384a4 = (undefined4 *)FUN_0049bf00(4);
        if (DAT_005384a4 == (undefined4 *)0x0) {
          return 0xffffffff;
        }
        *DAT_005384a4 = 0;
      }
    }
    else {
      iVar5 = FUN_004a5e60();
      if (iVar5 != 0) {
        return 0xffffffff;
      }
    }
  }
  piVar7 = DAT_0053849c;
  iVar6 = (int)pcVar4 - (int)param_1;
  iVar5 = FUN_004a6cb0(param_1,iVar6);
  if ((iVar5 < 0) || (*piVar7 == 0)) {
    if (bVar11) {
      return 0;
    }
    if (iVar5 < 0) {
      iVar5 = -iVar5;
    }
    piVar7 = (int *)FUN_0049e750(piVar7,iVar5 * 4 + 8);
    if (piVar7 == (int *)0x0) {
      return 0xffffffff;
    }
    piVar7[iVar5] = (int)param_1;
    piVar7[iVar5 + 1] = 0;
    DAT_0053849c = piVar7;
  }
  else if (bVar11) {
    FUN_0049bfd0(piVar7[iVar5]);
    iVar2 = piVar7[iVar5];
    piVar3 = piVar7 + iVar5;
    while (iVar2 != 0) {
      *piVar3 = piVar3[1];
      iVar5 = iVar5 + 1;
      iVar2 = piVar3[1];
      piVar3 = piVar3 + 1;
    }
    piVar7 = (int *)FUN_0049e750(piVar7,iVar5 * 4);
    if (piVar7 != (int *)0x0) {
      DAT_0053849c = piVar7;
    }
  }
  else {
    piVar7[iVar5] = (int)param_1;
  }
  if (param_2 != 0) {
    uVar8 = 0xffffffff;
    pcVar4 = param_1;
    do {
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    lpName = (LPCSTR)FUN_0049bf00(~uVar8 + 1);
    if (lpName != (LPCSTR)0x0) {
      uVar8 = 0xffffffff;
      do {
        pcVar4 = param_1;
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        pcVar4 = param_1 + 1;
        cVar1 = *param_1;
        param_1 = pcVar4;
      } while (cVar1 != '\0');
      uVar8 = ~uVar8;
      pcVar4 = pcVar4 + -uVar8;
      pcVar10 = lpName;
      for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar4;
        pcVar4 = pcVar4 + 4;
        pcVar10 = pcVar10 + 4;
      }
      for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *pcVar10 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        pcVar10 = pcVar10 + 1;
      }
      lpName[iVar6] = '\0';
      SetEnvironmentVariableA(lpName,(LPCSTR)(~-(uint)bVar11 & (uint)(lpName + iVar6 + 1)));
      FUN_0049bfd0(lpName);
      return 0;
    }
  }
  return 0;
}

