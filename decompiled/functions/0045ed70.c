
int __cdecl FUN_0045ed70(uint param_1,char *param_2,uint param_3)

{
  int iVar1;
  DWORD *pDVar2;
  
  if ((param_1 < DAT_004aff00) &&
     ((*(byte *)((&DAT_004afe00)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_004616a0(param_1);
    iVar1 = FUN_0045edf0(param_1,param_2,param_3);
    FUN_00461710(param_1);
    return iVar1;
  }
  pDVar2 = FUN_00458cd0();
  *pDVar2 = 9;
  pDVar2 = FUN_00458ce0();
  *pDVar2 = 0;
  return -1;
}

