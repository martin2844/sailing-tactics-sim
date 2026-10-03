
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_00476514(void)

{
  DWORD DVar1;
  
  DVar1 = GetVersion();
  if ((DVar1 & 0x80000000) == 0) {
LAB_00476537:
    DVar1 = GetVersion();
    if ((DVar1 & 0x80000000) == 0) {
      DVar1 = GetVersion();
      if ((short)DVar1 == 3) goto LAB_0047654d;
    }
    _DAT_004ae370 = 0;
  }
  else {
    DVar1 = GetVersion();
    if ((short)DVar1 != 4) goto LAB_00476537;
LAB_0047654d:
    _DAT_004ae370 = RegisterWindowMessageA("MSWHEEL_ROLLMSG");
  }
  return;
}

