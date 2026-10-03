
HANDLE __cdecl FUN_00462860(HWND param_1,int param_2)

{
  HANDLE hData;
  
  hData = FUN_00462840(param_1);
  if (hData == (HANDLE)0x0) {
    hData = DAT_004b0a30;
    if (param_2 != 6) {
      hData = (HANDLE)(&DAT_004b09a4)[param_2 * 6];
    }
    SetPropA(param_1,(LPCSTR)(uint)DAT_004aff4e,hData);
  }
  return hData;
}

