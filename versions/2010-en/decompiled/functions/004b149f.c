
undefined4 FUN_004b149f(char *param_1,LPCSTR param_2)

{
  int iVar1;
  int iVar2;
  LCID Locale;
  undefined4 uVar3;
  WORD local_61c [260];
  WORD local_414 [260];
  WORD local_20c [260];
  
  iVar1 = lstrcmpiA(param_1,param_2);
  if (iVar1 == 0) {
    iVar1 = GetSystemMetrics(0x2a);
    if (iVar1 != 0) {
      iVar1 = lstrlenA(param_1);
      iVar2 = lstrlenA(param_2);
      if (iVar1 != iVar2) goto LAB_004b155e;
      Locale = GetThreadLocale();
      GetStringTypeExA(Locale,1,param_1,-1,local_20c);
      GetStringTypeExA(Locale,4,param_1,-1,local_414);
      GetStringTypeExA(Locale,1,param_2,-1,local_61c);
      if (*param_1 != '\0') {
        iVar1 = 0;
        do {
          if (((*(byte *)((int)local_414 + iVar1) & 0x80) != 0) &&
             (*(short *)((int)local_20c + iVar1) != *(short *)((int)local_61c + iVar1)))
          goto LAB_004b155e;
          iVar1 = iVar1 + 2;
          param_1 = (char *)FUN_0049c720(param_1);
        } while (*param_1 != '\0');
      }
    }
    uVar3 = 1;
  }
  else {
LAB_004b155e:
    uVar3 = 0;
  }
  return uVar3;
}

