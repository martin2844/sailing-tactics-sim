
undefined4 FUN_004c0a77(HKEY param_1)

{
  LPCSTR lpString;
  int iVar1;
  LPCSTR pCVar2;
  LSTATUS LVar3;
  CHAR local_10c [264];
  
  lpString = (LPCSTR)FUN_0049c480(param_1);
  iVar1 = lstrlenA(lpString);
  pCVar2 = lpString + iVar1;
  while (pCVar2 != (LPCSTR)0x0) {
    *pCVar2 = '\0';
    LVar3 = RegOpenKeyA((HKEY)0x80000000,lpString,&param_1);
    if (LVar3 != 0) break;
    LVar3 = RegEnumKeyA(param_1,0,local_10c,0x105);
    RegCloseKey(param_1);
    if (LVar3 == 0) break;
    RegDeleteKeyA((HKEY)0x80000000,lpString);
    pCVar2 = (LPCSTR)FUN_0049d2c0(lpString,0x5c);
  }
  FUN_0049bfd0(lpString);
  return 1;
}

