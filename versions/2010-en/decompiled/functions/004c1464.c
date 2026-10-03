
int FUN_004c1464(char *param_1,LPSTR param_2,int param_3)

{
  char cVar1;
  char *lpString2;
  int iVar2;
  
  lpString2 = param_1;
  for (; *param_1 != '\0'; param_1 = (char *)FUN_0049c720(param_1)) {
    cVar1 = *param_1;
    if (((cVar1 == '\\') || (cVar1 == '/')) || (cVar1 == ':')) {
      lpString2 = (char *)FUN_0049c720(param_1);
    }
  }
  if (param_2 == (LPSTR)0x0) {
    iVar2 = lstrlenA(lpString2);
    iVar2 = iVar2 + 1;
  }
  else {
    lstrcpynA(param_2,lpString2,param_3);
    iVar2 = 0;
  }
  return iVar2;
}

