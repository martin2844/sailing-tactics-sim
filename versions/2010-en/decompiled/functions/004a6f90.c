
void FUN_004a6f90(HWND param_1,LONG param_2)

{
  HANDLE pvVar1;
  int iVar2;
  BOOL BVar3;
  CHAR local_10 [16];
  
  pvVar1 = GetPropA(param_1,(LPCSTR)(uint)DAT_00539a88);
  if (pvVar1 == (HANDLE)0x0) {
    pvVar1 = GetPropA(param_1,(LPCSTR)(uint)DAT_00539a8e);
    if (pvVar1 == (HANDLE)0x0) {
      pvVar1 = GetPropA(param_1,(LPCSTR)(uint)DAT_00539a92);
      if (pvVar1 == (HANDLE)0x0) {
        pvVar1 = GetPropA(param_1,(LPCSTR)(uint)DAT_00539a8c);
        if (pvVar1 == (HANDLE)0x0) {
          pvVar1 = GetPropA(param_1,(LPCSTR)(uint)DAT_00539a90);
          if (pvVar1 == (HANDLE)0x0) {
            pvVar1 = GetPropA(param_1,(LPCSTR)(uint)DAT_00539a8a);
            if (pvVar1 == (HANDLE)0x0) {
              iVar2 = FUN_004a6f20(param_1);
              if (iVar2 == 0) {
                if (DAT_0053a585 != '\0') {
                  BVar3 = IsWindowUnicode(param_1);
                  if (BVar3 == 0) {
                    GetClassNameA(param_1,local_10,0x10);
                    lstrcmpiA(local_10,&DAT_004f14a4);
                  }
                }
                pvVar1 = (HANDLE)SetWindowLongA(param_1,-4,param_2);
                SetPropA(param_1,(LPCSTR)(uint)DAT_00539a8e,pvVar1);
              }
            }
          }
        }
      }
    }
  }
  return;
}

