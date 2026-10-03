
bool FUN_004c124b(HKEY param_1,BYTE *param_2,LPCSTR param_3)

{
  DWORD cbData;
  LSTATUS LVar1;
  int iVar2;
  LSTATUS LVar3;
  bool bVar4;
  
  if (param_3 == (LPCSTR)0x0) {
    cbData = lstrlenA((LPCSTR)param_2);
    LVar1 = RegSetValueA((HKEY)0x80000000,(LPCSTR)param_1,1,(LPCSTR)param_2,cbData);
    bVar4 = LVar1 == 0;
  }
  else {
    LVar1 = RegCreateKeyA((HKEY)0x80000000,(LPCSTR)param_1,&param_1);
    if (LVar1 == 0) {
      iVar2 = lstrlenA((LPCSTR)param_2);
      LVar1 = RegSetValueExA(param_1,param_3,0,1,param_2,iVar2 + 1);
      LVar3 = RegCloseKey(param_1);
      if ((LVar3 == 0) && (LVar1 == 0)) {
        return true;
      }
    }
    bVar4 = false;
  }
  return bVar4;
}

