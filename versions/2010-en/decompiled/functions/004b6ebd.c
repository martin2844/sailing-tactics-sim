
uint __thiscall FUN_004b6ebd(int param_1,LPCSTR param_2,LPCSTR param_3,undefined4 param_4)

{
  HKEY hKey;
  LSTATUS LVar1;
  uint uVar2;
  CHAR local_14 [16];
  
  if (*(int *)(param_1 + 0x7c) == 0) {
    wsprintfA(local_14,"%d",param_4);
    uVar2 = WritePrivateProfileStringA(param_2,param_3,local_14,*(LPCSTR *)(param_1 + 0x90));
  }
  else {
    hKey = (HKEY)GetSectionKey(param_2);
    uVar2 = 0;
    if (hKey != (HKEY)0x0) {
      LVar1 = RegSetValueExA(hKey,param_3,0,4,(BYTE *)&param_4,4);
      RegCloseKey(hKey);
      uVar2 = (uint)(LVar1 == 0);
    }
  }
  return uVar2;
}

