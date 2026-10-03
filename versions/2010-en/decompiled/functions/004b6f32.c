
uint __thiscall FUN_004b6f32(int param_1,LPCSTR param_2,LPCSTR param_3,BYTE *param_4)

{
  HKEY hKey;
  int iVar1;
  uint uVar2;
  
  if (*(int *)(param_1 + 0x7c) == 0) {
    uVar2 = WritePrivateProfileStringA(param_2,param_3,(LPCSTR)param_4,*(LPCSTR *)(param_1 + 0x90));
    return uVar2;
  }
  if (param_3 == (LPCSTR)0x0) {
    hKey = (HKEY)FUN_004bf7f2();
    if (hKey == (HKEY)0x0) {
      return 0;
    }
    iVar1 = RegDeleteKeyA(hKey,param_2);
  }
  else if (param_4 == (BYTE *)0x0) {
    hKey = (HKEY)GetSectionKey(param_2);
    if (hKey == (HKEY)0x0) {
      return 0;
    }
    iVar1 = RegDeleteValueA(hKey,param_3);
  }
  else {
    hKey = (HKEY)GetSectionKey(param_2);
    if (hKey == (HKEY)0x0) {
      return 0;
    }
    iVar1 = lstrlenA((LPCSTR)param_4);
    iVar1 = RegSetValueExA(hKey,param_3,0,1,param_4,iVar1 + 1);
  }
  RegCloseKey(hKey);
  return (uint)(iVar1 == 0);
}

