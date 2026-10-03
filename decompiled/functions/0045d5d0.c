
BOOL __cdecl
FUN_0045d5d0(DWORD param_1,LPCSTR param_2,int param_3,LPWORD param_4,UINT param_5,LCID param_6)

{
  BOOL BVar1;
  int iVar2;
  LPCWSTR lpWideCharStr;
  WORD local_2;
  
  lpWideCharStr = (LPCWSTR)0x0;
  if (DAT_004aec60 == 0) {
    BVar1 = GetStringTypeA(0,1,"",1,&local_2);
    if (BVar1 == 0) {
      BVar1 = GetStringTypeW(1,L"",1,&local_2);
      if (BVar1 == 0) {
        return 0;
      }
      DAT_004aec60 = 1;
    }
    else {
      DAT_004aec60 = 2;
    }
  }
  if (DAT_004aec60 == 2) {
    if (param_6 == 0) {
      param_6 = DAT_004aec48;
    }
    BVar1 = GetStringTypeA(param_6,param_1,param_2,param_3,param_4);
    return BVar1;
  }
  param_6 = DAT_004aec60;
  if (DAT_004aec60 == 1) {
    param_6 = 0;
    if (param_5 == 0) {
      param_5 = DAT_004aec58;
    }
    iVar2 = MultiByteToWideChar(param_5,9,param_2,param_3,(LPWSTR)0x0,0);
    if (iVar2 != 0) {
      lpWideCharStr = (LPCWSTR)FUN_00458640(2,iVar2);
      if (lpWideCharStr != (LPCWSTR)0x0) {
        iVar2 = MultiByteToWideChar(param_5,1,param_2,param_3,lpWideCharStr,iVar2);
        if (iVar2 != 0) {
          BVar1 = GetStringTypeW(param_1,lpWideCharStr,iVar2,param_4);
          FUN_00457710((undefined *)lpWideCharStr);
          return BVar1;
        }
      }
    }
    FUN_00457710((undefined *)lpWideCharStr);
  }
  return param_6;
}

