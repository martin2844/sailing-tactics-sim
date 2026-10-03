
void __cdecl FUN_004628b0(HWND param_1,LONG param_2)

{
  HANDLE pvVar1;
  BOOL BVar2;
  CHAR local_10 [16];
  
  pvVar1 = GetPropA(param_1,(LPCSTR)(uint)DAT_004aff48);
  if (pvVar1 == (HANDLE)0x0) {
    pvVar1 = GetPropA(param_1,(LPCSTR)(uint)DAT_004aff4e);
    if (pvVar1 == (HANDLE)0x0) {
      pvVar1 = GetPropA(param_1,(LPCSTR)(uint)DAT_004aff52);
      if (pvVar1 == (HANDLE)0x0) {
        pvVar1 = GetPropA(param_1,(LPCSTR)(uint)DAT_004aff4c);
        if (pvVar1 == (HANDLE)0x0) {
          pvVar1 = GetPropA(param_1,(LPCSTR)(uint)DAT_004aff50);
          if (pvVar1 == (HANDLE)0x0) {
            pvVar1 = GetPropA(param_1,(LPCSTR)(uint)DAT_004aff4a);
            if (pvVar1 == (HANDLE)0x0) {
              pvVar1 = FUN_00462840(param_1);
              if (pvVar1 == (HANDLE)0x0) {
                if (DAT_004b0a45 != '\0') {
                  BVar2 = IsWindowUnicode(param_1);
                  if (BVar2 == 0) {
                    GetClassNameA(param_1,local_10,0x10);
                    lstrcmpiA(local_10,&DAT_004a32e4);
                  }
                }
                pvVar1 = (HANDLE)SetWindowLongA(param_1,-4,param_2);
                SetPropA(param_1,(LPCSTR)(uint)DAT_004aff4e,pvVar1);
              }
            }
          }
        }
      }
    }
  }
  return;
}

