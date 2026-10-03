
void __thiscall FUN_004c0321(DWORD *param_1,int param_2,int param_3)

{
  undefined4 *lpTlsValue;
  HLOCAL pvVar1;
  
  lpTlsValue = TlsGetValue(*param_1);
  if (lpTlsValue == (undefined4 *)0x0) {
LAB_004c0351:
    lpTlsValue = (undefined4 *)FUN_004c013e(0x10);
    if (lpTlsValue == (undefined4 *)0x0) {
      lpTlsValue = (undefined4 *)0x0;
    }
    else {
      *lpTlsValue = &PTR_FUN_004cf084;
    }
    lpTlsValue[2] = 0;
    lpTlsValue[3] = 0;
    FUN_004c00e0(lpTlsValue);
  }
  else {
    if ((param_2 < (int)lpTlsValue[2]) || (param_3 == 0)) goto LAB_004c03db;
    if (lpTlsValue == (undefined4 *)0x0) goto LAB_004c0351;
  }
  if ((HLOCAL)lpTlsValue[3] == (HLOCAL)0x0) {
    pvVar1 = LocalAlloc(0,param_1[3] << 2);
  }
  else {
    pvVar1 = LocalReAlloc((HLOCAL)lpTlsValue[3],param_1[3] << 2,2);
  }
  lpTlsValue[3] = pvVar1;
  if (pvVar1 == (HLOCAL)0x0) {
    FUN_004aa740();
  }
  _memset((void *)(lpTlsValue[3] + lpTlsValue[2] * 4),0,
          (lpTlsValue[2] * 0x3fffffff + param_1[3]) * 4);
  lpTlsValue[2] = param_1[3];
  TlsSetValue(*param_1,lpTlsValue);
LAB_004c03db:
  *(int *)(lpTlsValue[3] + param_2 * 4) = param_3;
  return;
}

