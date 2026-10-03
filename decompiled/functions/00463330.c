
void __cdecl FUN_00463330(HWND param_1,ushort param_2,undefined4 param_3)

{
  HANDLE pvVar1;
  int local_4;
  
  pvVar1 = FUN_00462840(param_1);
  if (pvVar1 == (HANDLE)0x0) {
    FUN_00464440(param_1,param_2,0,param_3);
    return;
  }
  pvVar1 = GetPropA(param_1,(LPCSTR)(uint)DAT_004aff54);
  if (pvVar1 == (HANDLE)0x0) {
    local_4 = 0x29a;
    SendMessageA(param_1,0x1944,0,(LPARAM)&local_4);
    if (local_4 == 0x29a) {
      SendMessageA(param_1,0x1943,0,(LPARAM)&local_4);
      if (local_4 == 0x29a) {
        RemovePropA(param_1,(LPCSTR)(uint)DAT_004aff4e);
        FUN_00464440(param_1,param_2,0,param_3);
      }
    }
  }
  return;
}

