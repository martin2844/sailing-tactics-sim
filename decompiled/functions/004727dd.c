
uint __thiscall FUN_004727dd(void *this,LPCSTR param_1,LPCSTR param_2,undefined4 param_3)

{
  HKEY hKey;
  LSTATUS LVar1;
  uint uVar2;
  CHAR local_14 [16];
  
  if (*(int *)((int)this + 0x7c) == 0) {
    wsprintfA(local_14,"%d",param_3);
    uVar2 = WritePrivateProfileStringA(param_1,param_2,local_14,*(LPCSTR *)((int)this + 0x90));
  }
  else {
    hKey = GetSectionKey(this,param_1);
    uVar2 = 0;
    if (hKey != (HKEY)0x0) {
      LVar1 = RegSetValueExA(hKey,param_2,0,4,(BYTE *)&param_3,4);
      RegCloseKey(hKey);
      uVar2 = (uint)(LVar1 == 0);
    }
  }
  return uVar2;
}

