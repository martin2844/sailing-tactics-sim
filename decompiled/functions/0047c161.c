
int FUN_0047c161(void)

{
  DWORD DVar1;
  
  if (DAT_004ae6a8 == 0) {
    DAT_004ae6a8 = 1;
    DVar1 = GetVersion();
    if (((byte)DVar1 < 4) && ((DVar1 & 0x80000000) != 0)) {
      DAT_004ae848 = 1;
    }
    else {
      DAT_004ae848 = 0;
    }
    if (DAT_004ae848 == 0) {
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_004ae850);
    }
  }
  return DAT_004ae6a8;
}

