
void __thiscall FUN_004aa84f(undefined4 *param_1,char *param_2,int *param_3)

{
  int *piVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  bool bVar9;
  int local_10;
  int local_c;
  
  piVar1 = param_3;
  local_10 = 0;
  cVar2 = *param_2;
  piVar7 = param_3;
  pcVar3 = param_2;
  do {
    if (cVar2 == '\0') {
      FUN_004b0956(local_10);
      FUN_0049d3f0(*param_1,param_2,piVar1);
      FUN_004b09a5(0xffffffff);
      return;
    }
    if (*pcVar3 == '%') {
      pcVar3 = (char *)FUN_0049c720(pcVar3);
      cVar2 = *pcVar3;
      if (cVar2 == '%') goto LAB_004aaa76;
      iVar8 = 0;
      param_3 = (int *)0x0;
      piVar6 = piVar7;
      while (cVar2 != '\0') {
        if (cVar2 == '#') {
          local_10 = local_10 + 2;
        }
        else if (cVar2 == '*') {
          param_3 = (int *)*piVar6;
          piVar6 = piVar6 + 1;
        }
        else if ((((cVar2 != '-') && (cVar2 != '+')) && (cVar2 != '0')) && (cVar2 != ' ')) break;
        pcVar3 = (char *)FUN_0049c720(pcVar3);
        cVar2 = *pcVar3;
      }
      if (param_3 == (int *)0x0) {
        param_3 = (int *)FUN_0049cb20(pcVar3);
        while ((*pcVar3 != '\0' && (iVar4 = FUN_0049d480((int)*pcVar3), iVar4 != 0))) {
          pcVar3 = (char *)FUN_0049c720(pcVar3);
        }
      }
      local_c = 0;
      if (*pcVar3 == '.') {
        pcVar3 = (char *)FUN_0049c720(pcVar3);
        if (*pcVar3 == '*') {
          local_c = *piVar6;
          piVar6 = piVar6 + 1;
          pcVar3 = (char *)FUN_0049c720(pcVar3);
        }
        else {
          local_c = FUN_0049cb20(pcVar3);
          while ((*pcVar3 != '\0' && (iVar4 = FUN_0049d480((int)*pcVar3), iVar4 != 0))) {
            pcVar3 = (char *)FUN_0049c720(pcVar3);
          }
        }
      }
      cVar2 = *pcVar3;
      uVar5 = 0;
      if (((cVar2 == 'F') || (cVar2 == 'L')) || (cVar2 == 'N')) {
LAB_004aa95b:
        pcVar3 = (char *)FUN_0049c720(pcVar3);
      }
      else {
        if (cVar2 == 'h') {
          uVar5 = 0x10000;
          goto LAB_004aa95b;
        }
        if (cVar2 == 'l') {
          uVar5 = 0x20000;
          goto LAB_004aa95b;
        }
      }
      uVar5 = uVar5 | (int)*pcVar3;
      piVar7 = piVar6;
      if ((int)uVar5 < 0x54) {
        if (uVar5 == 0x53) goto LAB_004aa9ba;
        bVar9 = uVar5 == 0x43;
LAB_004aa995:
        if (bVar9) {
LAB_004aa9ee:
          iVar8 = 2;
          piVar7 = piVar6 + 1;
        }
      }
      else {
        if (0x73 < (int)uVar5) {
          if ((int)uVar5 < 0x10054) {
            if (uVar5 == 0x10053) goto LAB_004aa9cd;
            bVar9 = uVar5 == 0x10043;
            goto LAB_004aa995;
          }
          if (uVar5 != 0x10063) {
            if (uVar5 == 0x10073) goto LAB_004aa9cd;
            if (uVar5 != 0x20043) {
              if (uVar5 != 0x20053) {
                if (uVar5 == 0x20063) goto LAB_004aa9ee;
                if (uVar5 != 0x20073) goto LAB_004aa9f4;
              }
LAB_004aa9ba:
              if (*piVar6 == 0) goto LAB_004aa9d7;
              iVar8 = FUN_0049c650(*piVar6);
              goto LAB_004aa9e2;
            }
          }
          goto LAB_004aa9ee;
        }
        if (uVar5 == 0x73) {
LAB_004aa9cd:
          if ((LPCSTR)*piVar6 == (LPCSTR)0x0) {
LAB_004aa9d7:
            iVar8 = 6;
          }
          else {
            iVar8 = lstrlenA((LPCSTR)*piVar6);
LAB_004aa9e2:
            piVar7 = piVar6 + 1;
            if (0 < iVar8) goto LAB_004aa9f4;
            iVar8 = 1;
          }
          piVar7 = piVar6 + 1;
        }
        else if (uVar5 == 99) goto LAB_004aa9ee;
      }
LAB_004aa9f4:
      if (iVar8 == 0) {
        cVar2 = *pcVar3;
        if (cVar2 < 'Y') {
          if (cVar2 == 'X') {
LAB_004aaa51:
            piVar7 = piVar7 + 1;
            iVar8 = 0x20;
          }
          else {
            if (cVar2 != 'G') goto LAB_004aaa6c;
LAB_004aaa32:
            piVar7 = piVar7 + 2;
            iVar8 = 0x80;
          }
          local_c = local_c + (int)param_3;
          bVar9 = SBORROW4(local_c,iVar8);
          iVar4 = local_c - iVar8;
          goto LAB_004aaa63;
        }
        if (cVar2 < 'j') {
          if ((cVar2 == 'i') || (cVar2 == 'd')) goto LAB_004aaa51;
          if (('d' < cVar2) && (cVar2 < 'h')) goto LAB_004aaa32;
        }
        else if (cVar2 == 'n') {
          piVar7 = piVar7 + 1;
        }
        else if (((cVar2 == 'o') || (cVar2 == 'p')) || ((cVar2 == 'u' || (cVar2 == 'x'))))
        goto LAB_004aaa51;
      }
      else {
        if (iVar8 <= (int)param_3) {
          iVar8 = (int)param_3;
        }
        if (local_c == 0) goto LAB_004aaa6c;
        bVar9 = SBORROW4(iVar8,local_c);
        iVar4 = iVar8 - local_c;
LAB_004aaa63:
        if (bVar9 == iVar4 < 0) {
          iVar8 = local_c;
        }
      }
LAB_004aaa6c:
      local_10 = local_10 + iVar8;
    }
    else {
LAB_004aaa76:
      iVar8 = FUN_0049d460(pcVar3);
      local_10 = local_10 + iVar8;
    }
    pcVar3 = (char *)FUN_0049c720(pcVar3);
    cVar2 = *pcVar3;
  } while( true );
}

