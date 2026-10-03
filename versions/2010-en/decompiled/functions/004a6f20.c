
HANDLE FUN_004a6f20(HWND param_1)

{
  HANDLE pvVar1;
  
  if (param_1 == (HWND)0x0) {
    return (HANDLE)0x0;
  }
  pvVar1 = GetPropA(param_1,(LPCSTR)(uint)DAT_00539a8e);
  return pvVar1;
}

