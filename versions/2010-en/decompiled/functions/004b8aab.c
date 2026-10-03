
void FUN_004b8aab(int *param_1,byte *param_2,int param_3,int param_4)

{
  byte bVar1;
  byte bVar2;
  LPCSTR pCVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  
  iVar5 = 0;
  bVar1 = *param_2;
  pbVar6 = param_2;
  while (bVar1 != 0) {
    if (*pbVar6 == 0x25) {
      bVar1 = pbVar6[1];
      if (((char)bVar1 < '0') || ('9' < (char)bVar1)) {
        if (((char)bVar1 < 'A') || ('Z' < (char)bVar1)) goto LAB_004b8b04;
        if ((char)bVar1 < ':') goto LAB_004b8ae2;
        iVar4 = (char)bVar1 + -0x38;
      }
      else {
LAB_004b8ae2:
        iVar4 = (char)bVar1 + -0x31;
      }
      pbVar6 = pbVar6 + 2;
      if (param_4 <= iVar4) goto LAB_004b8b13;
      pCVar3 = *(LPCSTR *)(param_3 + iVar4 * 4);
      if (pCVar3 != (LPCSTR)0x0) {
        iVar4 = lstrlenA(pCVar3);
        iVar5 = iVar5 + iVar4;
      }
    }
    else {
LAB_004b8b04:
      if ((*(byte *)((int)&DAT_005384c0 + *pbVar6 + 1) & 4) != 0) {
        iVar5 = iVar5 + 1;
        pbVar6 = pbVar6 + 1;
      }
      pbVar6 = pbVar6 + 1;
LAB_004b8b13:
      iVar5 = iVar5 + 1;
    }
    bVar1 = *pbVar6;
  }
  pbVar6 = (byte *)FUN_004b0956(iVar5);
  do {
    while( true ) {
      if (*param_2 == 0) {
        FUN_004b09a5((int)pbVar6 - *param_1);
        return;
      }
      bVar1 = *param_2;
      if (bVar1 == 0x25) break;
LAB_004b8b81:
      if ((*(byte *)((int)&DAT_005384c0 + bVar1 + 1) & 4) != 0) {
        *pbVar6 = bVar1;
        pbVar6 = pbVar6 + 1;
        param_2 = param_2 + 1;
      }
      *pbVar6 = *param_2;
      pbVar6 = pbVar6 + 1;
      param_2 = param_2 + 1;
    }
    bVar2 = param_2[1];
    if (((char)bVar2 < '0') || ('9' < (char)bVar2)) {
      if (((char)bVar2 < 'A') || ('Z' < (char)bVar2)) goto LAB_004b8b81;
      if ((char)bVar2 < ':') goto LAB_004b8b51;
      iVar5 = (char)bVar2 + -0x38;
    }
    else {
LAB_004b8b51:
      iVar5 = (char)bVar2 + -0x31;
    }
    param_2 = param_2 + 2;
    if (iVar5 < param_4) {
      pCVar3 = *(LPCSTR *)(param_3 + iVar5 * 4);
      if (pCVar3 != (LPCSTR)0x0) {
        lstrcpyA((LPSTR)pbVar6,pCVar3);
        iVar5 = lstrlenA((LPCSTR)pbVar6);
        pbVar6 = pbVar6 + iVar5;
      }
    }
    else {
      *pbVar6 = 0x3f;
      pbVar6 = pbVar6 + 1;
    }
  } while( true );
}

