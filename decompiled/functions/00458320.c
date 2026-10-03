
SIZE_T __cdecl FUN_00458320(undefined *param_1)

{
  byte bVar1;
  byte *pbVar2;
  SIZE_T SVar3;
  uint local_8;
  undefined4 local_4;
  
  FUN_0045b730(9);
  pbVar2 = (byte *)FUN_0045bc00(param_1,&local_4,&local_8);
  if (pbVar2 != (byte *)0x0) {
    bVar1 = *pbVar2;
    FUN_0045b7b0(9);
    return (uint)bVar1 << 4;
  }
  FUN_0045b7b0(9);
  SVar3 = HeapSize(DAT_004afdec,0,param_1);
  return SVar3;
}

