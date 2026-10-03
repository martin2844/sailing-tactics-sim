
void FUN_004a7a10(HWND param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  HANDLE pvVar2;
  int local_4;
  
  iVar1 = FUN_004a6f20(param_1);
  if (iVar1 == 0) {
    FUN_004a8b20(param_1,param_2,0,param_3);
    return;
  }
  pvVar2 = GetPropA(param_1,(LPCSTR)(uint)DAT_00539a94);
  if (pvVar2 == (HANDLE)0x0) {
    local_4 = 0x29a;
    SendMessageA(param_1,0x1944,0,(LPARAM)&local_4);
    if (local_4 == 0x29a) {
      SendMessageA(param_1,0x1943,0,(LPARAM)&local_4);
      if (local_4 == 0x29a) {
        RemovePropA(param_1,(LPCSTR)(uint)DAT_00539a8e);
        FUN_004a8b20(param_1,param_2 & 0xffff,0,param_3);
      }
    }
  }
  return;
}

