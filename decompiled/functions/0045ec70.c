
DWORD __cdecl FUN_0045ec70(uint param_1,LONG param_2,DWORD param_3)

{
  DWORD DVar1;
  DWORD *pDVar2;
  
  if ((param_1 < DAT_004aff00) &&
     ((*(byte *)((&DAT_004afe00)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_004616a0(param_1);
    DVar1 = FUN_0045ecf0(param_1,param_2,param_3);
    FUN_00461710(param_1);
    return DVar1;
  }
  pDVar2 = FUN_00458cd0();
  *pDVar2 = 9;
  pDVar2 = FUN_00458ce0();
  *pDVar2 = 0;
  return 0xffffffff;
}

