
undefined4 FUN_0045b3c0(void)

{
  undefined **ppuVar1;
  
  DAT_004afdec = HeapCreate(0,0x1000,0);
  if (DAT_004afdec == (HANDLE)0x0) {
    return 0;
  }
  ppuVar1 = FUN_0045b960();
  if (ppuVar1 == (undefined **)0x0) {
    HeapDestroy(DAT_004afdec);
    return 0;
  }
  return 1;
}

