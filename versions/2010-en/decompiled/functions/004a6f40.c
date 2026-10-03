
HANDLE FUN_004a6f40(HWND param_1,int param_2)

{
  HANDLE hData;
  
  hData = (HANDLE)FUN_004a6f20(param_1);
  if (hData == (HANDLE)0x0) {
    hData = DAT_0053a570;
    if (param_2 != 6) {
      hData = (HANDLE)(&DAT_0053a4e4)[param_2 * 6];
    }
    SetPropA(param_1,(LPCSTR)(uint)DAT_00539a8e,hData);
  }
  return hData;
}

