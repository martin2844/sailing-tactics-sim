
uint __cdecl FUN_0045f200(LPSTR param_1,LPCWSTR param_2,uint param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  DWORD DVar5;
  DWORD *pDVar6;
  LPCWSTR pWVar7;
  int iVar8;
  BOOL local_4;
  
  uVar4 = param_3;
  pWVar7 = param_2;
  uVar2 = 0;
  local_4 = 0;
  if ((param_1 != (LPSTR)0x0) && (param_3 == 0)) {
    return uVar2;
  }
  if (param_1 == (LPSTR)0x0) {
    if (DAT_004aec48 == 0) {
      uVar4 = FUN_00457d90(param_2);
      return uVar4;
    }
    iVar3 = WideCharToMultiByte(DAT_004aec58,0x220,param_2,-1,(LPSTR)0x0,0,(LPCSTR)0x0,&local_4);
    if ((iVar3 != 0) && (local_4 == 0)) {
      return iVar3 - 1;
    }
  }
  else if (DAT_004aec48 == 0) {
    if (param_3 == 0) {
      return 0;
    }
    while ((ushort)*pWVar7 < 0x100) {
      param_1[uVar2] = (CHAR)*pWVar7;
      if (*pWVar7 == L'\0') {
        return uVar2;
      }
      uVar2 = uVar2 + 1;
      pWVar7 = pWVar7 + 1;
      if (param_3 <= uVar2) {
        return uVar2;
      }
    }
  }
  else if (DAT_004a229c == 1) {
    iVar3 = 0;
    if (param_3 != 0) {
      iVar3 = FUN_0045f3f0(param_2,param_3);
    }
    uVar4 = WideCharToMultiByte(DAT_004aec58,0x220,pWVar7,iVar3,param_1,iVar3,(LPCSTR)0x0,&local_4);
    if ((uVar4 != 0) && (local_4 == 0)) {
      if (param_1[uVar4 - 1] != '\0') {
        return uVar4;
      }
      return uVar4 - 1;
    }
  }
  else {
    iVar3 = WideCharToMultiByte(DAT_004aec58,0x220,param_2,-1,param_1,param_3,(LPCSTR)0x0,&local_4);
    if (iVar3 == 0) {
      if ((local_4 == 0) && (DVar5 = GetLastError(), DVar5 == 0x7a)) {
        uVar2 = 0;
        if (uVar4 != 0) {
          do {
            iVar3 = WideCharToMultiByte(DAT_004aec58,0,pWVar7,1,(LPSTR)&param_2,DAT_004a229c,
                                        (LPCSTR)0x0,&local_4);
            if ((iVar3 == 0) || (local_4 != 0)) goto LAB_0045f3d6;
            if (uVar4 < iVar3 + uVar2) {
              return uVar2;
            }
            iVar8 = 0;
            if (0 < iVar3) {
              do {
                cVar1 = *(char *)((int)&param_2 + iVar8);
                param_1[uVar2] = cVar1;
                if (cVar1 == '\0') {
                  return uVar2;
                }
                iVar8 = iVar8 + 1;
                uVar2 = uVar2 + 1;
              } while (iVar8 < iVar3);
            }
            pWVar7 = pWVar7 + 1;
          } while (uVar2 < uVar4);
        }
        return uVar2;
      }
    }
    else if (local_4 == 0) {
      return iVar3 - 1;
    }
  }
LAB_0045f3d6:
  pDVar6 = FUN_00458cd0();
  *pDVar6 = 0x2a;
  return 0xffffffff;
}

