
void __thiscall FUN_0047bc41(void *this,int param_1,int param_2)

{
  undefined4 *lpTlsValue;
  HLOCAL pvVar1;
  
  lpTlsValue = TlsGetValue(*(DWORD *)this);
  if (lpTlsValue == (undefined4 *)0x0) {
LAB_0047bc71:
    lpTlsValue = FUN_0047ba5e(0x10);
    if (lpTlsValue == (undefined4 *)0x0) {
      lpTlsValue = (undefined4 *)0x0;
    }
    else {
      *lpTlsValue = &PTR_FUN_004873e4;
    }
    lpTlsValue[2] = 0;
    lpTlsValue[3] = 0;
    FUN_0047ba00((void *)((int)this + 0x14),(int)lpTlsValue);
  }
  else {
    if ((param_1 < (int)lpTlsValue[2]) || (param_2 == 0)) goto LAB_0047bcfb;
    if (lpTlsValue == (undefined4 *)0x0) goto LAB_0047bc71;
  }
  if ((HLOCAL)lpTlsValue[3] == (HLOCAL)0x0) {
    pvVar1 = LocalAlloc(0,*(int *)((int)this + 0xc) << 2);
  }
  else {
    pvVar1 = LocalReAlloc((HLOCAL)lpTlsValue[3],*(int *)((int)this + 0xc) << 2,2);
  }
  lpTlsValue[3] = pvVar1;
  if (pvVar1 == (HLOCAL)0x0) {
    FUN_00466060();
  }
  _memset((void *)(lpTlsValue[3] + lpTlsValue[2] * 4),0,
          (lpTlsValue[2] * 0x3fffffff + *(int *)((int)this + 0xc)) * 4);
  lpTlsValue[2] = *(undefined4 *)((int)this + 0xc);
  TlsSetValue(*(DWORD *)this,lpTlsValue);
LAB_0047bcfb:
  *(int *)(lpTlsValue[3] + param_1 * 4) = param_2;
  return;
}

