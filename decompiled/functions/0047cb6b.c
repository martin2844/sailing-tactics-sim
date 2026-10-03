
bool FUN_0047cb6b(HKEY param_1,BYTE *param_2,LPCSTR param_3)

{
  char cVar1;
  DWORD cbData;
  LSTATUS LVar2;
  int iVar3;
  LSTATUS LVar4;
  
  if (param_3 == (LPCSTR)0x0) {
    cbData = lstrlenA((LPCSTR)param_2);
    LVar2 = RegSetValueA((HKEY)0x80000000,(LPCSTR)param_1,1,(LPCSTR)param_2,cbData);
    cVar1 = '\x01' - (LVar2 != 0);
  }
  else {
    LVar2 = RegCreateKeyA((HKEY)0x80000000,(LPCSTR)param_1,&param_1);
    if (LVar2 == 0) {
      iVar3 = lstrlenA((LPCSTR)param_2);
      LVar2 = RegSetValueExA(param_1,param_3,0,1,param_2,iVar3 + 1);
      LVar4 = RegCloseKey(param_1);
      if ((LVar4 == 0) && (LVar2 == 0)) {
        return true;
      }
    }
    cVar1 = '\0';
  }
  return (bool)cVar1;
}

