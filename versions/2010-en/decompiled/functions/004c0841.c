
int FUN_004c0841(void)

{
  DWORD DVar1;
  
  if (DAT_00538200 == 0) {
    DAT_00538200 = 1;
    DVar1 = GetVersion();
    if (((byte)DVar1 < 4) && ((DVar1 & 0x80000000) != 0)) {
      DAT_005383a0 = 1;
    }
    else {
      DAT_005383a0 = 0;
    }
    if (DAT_005383a0 == 0) {
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_005383a8);
    }
  }
  return DAT_00538200;
}

