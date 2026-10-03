
undefined4 FUN_0049fb80(void)

{
  int iVar1;
  
  DAT_0053992c = HeapCreate(0,0x1000,0);
  if (DAT_0053992c == (HANDLE)0x0) {
    return 0;
  }
  iVar1 = FUN_004a0040();
  if (iVar1 == 0) {
    HeapDestroy(DAT_0053992c);
    return 0;
  }
  return 1;
}

