
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004babf4(void)

{
  DWORD DVar1;
  
  DVar1 = GetVersion();
  if ((DVar1 & 0x80000000) == 0) {
LAB_004bac17:
    DVar1 = GetVersion();
    if ((DVar1 & 0x80000000) == 0) {
      DVar1 = GetVersion();
      if ((short)DVar1 == 3) goto LAB_004bac2d;
    }
    _DAT_00537ec8 = 0;
  }
  else {
    DVar1 = GetVersion();
    if ((short)DVar1 != 4) goto LAB_004bac17;
LAB_004bac2d:
    _DAT_00537ec8 = RegisterWindowMessageA("MSWHEEL_ROLLMSG");
  }
  return;
}

