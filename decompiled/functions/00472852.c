
uint __thiscall FUN_00472852(void *this,LPCSTR param_1,LPCSTR param_2,BYTE *param_3)

{
  HKEY hKey;
  int iVar1;
  uint uVar2;
  
  if (*(int *)((int)this + 0x7c) == 0) {
    uVar2 = WritePrivateProfileStringA
                      (param_1,param_2,(LPCSTR)param_3,*(LPCSTR *)((int)this + 0x90));
    return uVar2;
  }
  if (param_2 == (LPCSTR)0x0) {
    hKey = FUN_0047b112((int)this);
    if (hKey == (HKEY)0x0) {
      return 0;
    }
    iVar1 = RegDeleteKeyA(hKey,param_1);
  }
  else if (param_3 == (BYTE *)0x0) {
    hKey = GetSectionKey(this,param_1);
    if (hKey == (HKEY)0x0) {
      return 0;
    }
    iVar1 = RegDeleteValueA(hKey,param_2);
  }
  else {
    hKey = GetSectionKey(this,param_1);
    if (hKey == (HKEY)0x0) {
      return 0;
    }
    iVar1 = lstrlenA((LPCSTR)param_3);
    iVar1 = RegSetValueExA(hKey,param_2,0,1,param_3,iVar1 + 1);
  }
  RegCloseKey(hKey);
  return (uint)(iVar1 == 0);
}

