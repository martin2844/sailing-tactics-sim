
LPVOID FUN_0049cb30(LPVOID param_1,uint param_2)

{
  int iVar1;
  LPVOID pvVar2;
  uint dwBytes;
  undefined4 local_4;
  
  if (0xffffffe0 < param_2) {
    return (LPVOID)0x0;
  }
  if (param_2 == 0) {
    dwBytes = 0x10;
  }
  else {
    dwBytes = param_2 + 0xf & 0xfffffff0;
  }
  FUN_0049fe10(9);
  iVar1 = FUN_004a02e0(param_1,&local_4,&param_2);
  if (iVar1 != 0) {
    pvVar2 = (LPVOID)0x0;
    if (dwBytes <= DAT_004f0244) {
      iVar1 = FUN_004a0760(local_4,param_2,iVar1,dwBytes >> 4);
      if (iVar1 != 0) {
        pvVar2 = param_1;
      }
    }
    FUN_0049fe90(9);
    return pvVar2;
  }
  FUN_0049fe90(9);
  pvVar2 = HeapReAlloc(DAT_0053992c,0x10,param_1,dwBytes);
  return pvVar2;
}

