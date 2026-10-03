
undefined4 FUN_0047c397(HKEY param_1)

{
  byte *lpString;
  int iVar1;
  byte *pbVar2;
  LSTATUS LVar3;
  CHAR local_10c [264];
  
  lpString = (byte *)FUN_00457bc0((char *)param_1);
  iVar1 = lstrlenA((LPCSTR)lpString);
  pbVar2 = lpString + iVar1;
  while (pbVar2 != (byte *)0x0) {
    *pbVar2 = 0;
    LVar3 = RegOpenKeyA((HKEY)0x80000000,(LPCSTR)lpString,&param_1);
    if (LVar3 != 0) break;
    LVar3 = RegEnumKeyA(param_1,0,local_10c,0x105);
    RegCloseKey(param_1);
    if (LVar3 == 0) break;
    RegDeleteKeyA((HKEY)0x80000000,(LPCSTR)lpString);
    pbVar2 = FUN_00458bc0(lpString,0x5c);
  }
  FUN_00457710(lpString);
  return 1;
}

