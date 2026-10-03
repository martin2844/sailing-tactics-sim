
void __fastcall FUN_004b1da9(int param_1)

{
  DWORD DVar1;
  HBRUSH pHVar2;
  
  DVar1 = GetSysColor(0xf);
  *(DWORD *)(param_1 + 0x28) = DVar1;
  DVar1 = GetSysColor(0x10);
  *(DWORD *)(param_1 + 0x2c) = DVar1;
  DVar1 = GetSysColor(0x14);
  *(DWORD *)(param_1 + 0x30) = DVar1;
  DVar1 = GetSysColor(0x12);
  *(DWORD *)(param_1 + 0x34) = DVar1;
  DVar1 = GetSysColor(6);
  *(DWORD *)(param_1 + 0x38) = DVar1;
  pHVar2 = GetSysColorBrush(0xf);
  *(HBRUSH *)(param_1 + 0x24) = pHVar2;
  pHVar2 = GetSysColorBrush(6);
  *(HBRUSH *)(param_1 + 0x20) = pHVar2;
  return;
}

