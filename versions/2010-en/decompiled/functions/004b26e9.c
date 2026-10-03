
void FUN_004b26e9(LPCSTR param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  LPCSTR lpString2;
  char *lpString;
  
  iVar1 = lstrlenA(param_1);
  iVar2 = FUN_004c1464(param_1,0,0);
  iVar2 = iVar2 + -1;
  lpString2 = param_1 + (iVar1 - iVar2);
  if (param_2 < iVar1) {
    if (param_2 < iVar2) {
      if (param_3 == 0) {
        lpString2 = &DAT_00537ed8;
      }
    }
    else {
      lpString = param_1 + 2;
      if ((*param_1 == '\\') && (param_1[1] == '\\')) {
        for (; *lpString != '\\'; lpString = (char *)FUN_0049c720(lpString)) {
        }
      }
      if (3 < iVar1 - iVar2) {
        do {
          lpString = (char *)FUN_0049c720(lpString);
        } while (*lpString != '\\');
      }
      iVar1 = (int)lpString - (int)param_1;
      if (iVar1 + 5 + iVar2 <= param_2) {
        while (iVar2 = lstrlenA(lpString), param_2 < iVar2 + 4 + iVar1) {
          do {
            lpString = (char *)FUN_0049c720(lpString);
          } while (*lpString != '\\');
        }
        param_1[iVar1] = '\0';
        lstrcatA(param_1,"\\...");
        lstrcatA(param_1,lpString);
        return;
      }
    }
    lstrcpyA(param_1,lpString2);
  }
  return;
}

