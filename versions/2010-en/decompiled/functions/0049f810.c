
LPSTR FUN_0049f810(void)

{
  char cVar1;
  WCHAR WVar2;
  WCHAR *pWVar3;
  int iVar5;
  int cbMultiByte;
  LPSTR lpMultiByteStr;
  LPCH pCVar6;
  CHAR *pCVar7;
  uint uVar8;
  LPCH pCVar9;
  LPWCH lpWideCharStr;
  LPCH pCVar10;
  CHAR *pCVar11;
  WCHAR *pWVar4;
  
  lpWideCharStr = (LPWCH)0x0;
  pCVar9 = (LPCH)0x0;
  if (DAT_00538718 == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr == (LPWCH)0x0) {
      pCVar9 = GetEnvironmentStrings();
      if (pCVar9 == (LPCH)0x0) {
        return (LPSTR)0x0;
      }
      DAT_00538718 = 2;
    }
    else {
      DAT_00538718 = 1;
    }
  }
  if (DAT_00538718 == 1) {
    if ((lpWideCharStr != (LPWCH)0x0) ||
       (lpWideCharStr = GetEnvironmentStringsW(), lpWideCharStr != (LPWCH)0x0)) {
      WVar2 = *lpWideCharStr;
      pWVar3 = lpWideCharStr;
      while (WVar2 != L'\0') {
        do {
          pWVar4 = pWVar3;
          pWVar3 = pWVar4 + 1;
        } while (*pWVar3 != L'\0');
        pWVar3 = pWVar4 + 2;
        WVar2 = *pWVar3;
      }
      iVar5 = ((int)pWVar3 - (int)lpWideCharStr >> 1) + 1;
      cbMultiByte = WideCharToMultiByte(0,0,lpWideCharStr,iVar5,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0
                                       );
      if ((cbMultiByte != 0) &&
         (lpMultiByteStr = (LPSTR)FUN_0049bf00(cbMultiByte), lpMultiByteStr != (LPSTR)0x0)) {
        iVar5 = WideCharToMultiByte(0,0,lpWideCharStr,iVar5,lpMultiByteStr,cbMultiByte,(LPCSTR)0x0,
                                    (LPBOOL)0x0);
        if (iVar5 == 0) {
          FUN_0049bfd0(lpMultiByteStr);
          lpMultiByteStr = (LPSTR)0x0;
        }
        FreeEnvironmentStringsW(lpWideCharStr);
        return lpMultiByteStr;
      }
      FreeEnvironmentStringsW(lpWideCharStr);
      return (LPSTR)0x0;
    }
  }
  else if ((DAT_00538718 == 2) &&
          ((pCVar9 != (LPCH)0x0 || (pCVar9 = GetEnvironmentStrings(), pCVar9 != (LPCH)0x0)))) {
    cVar1 = *pCVar9;
    pCVar6 = pCVar9;
    while (cVar1 != '\0') {
      do {
        pCVar10 = pCVar6;
        pCVar6 = pCVar10 + 1;
      } while (pCVar10[1] != '\0');
      pCVar6 = pCVar10 + 2;
      cVar1 = pCVar10[2];
    }
    pCVar6 = pCVar6 + (1 - (int)pCVar9);
    pCVar7 = (CHAR *)FUN_0049bf00(pCVar6);
    if (pCVar7 != (CHAR *)0x0) {
      pCVar10 = pCVar9;
      pCVar11 = pCVar7;
      for (uVar8 = (uint)pCVar6 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)pCVar11 = *(undefined4 *)pCVar10;
        pCVar10 = pCVar10 + 4;
        pCVar11 = pCVar11 + 4;
      }
      for (uVar8 = (uint)pCVar6 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *pCVar11 = *pCVar10;
        pCVar10 = pCVar10 + 1;
        pCVar11 = pCVar11 + 1;
      }
      FreeEnvironmentStringsA(pCVar9);
      return pCVar7;
    }
    FreeEnvironmentStringsA(pCVar9);
    return (LPSTR)0x0;
  }
  return (LPSTR)0x0;
}

