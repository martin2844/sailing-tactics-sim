
SIZE_T FUN_0049cbe0(LPCVOID param_1)

{
  byte bVar1;
  byte *pbVar2;
  SIZE_T SVar3;
  undefined1 local_8 [4];
  undefined1 local_4 [4];
  
  FUN_0049fe10(9);
  pbVar2 = (byte *)FUN_004a02e0(param_1,local_4,local_8);
  if (pbVar2 != (byte *)0x0) {
    bVar1 = *pbVar2;
    FUN_0049fe90(9);
    return (uint)bVar1 << 4;
  }
  FUN_0049fe90(9);
  SVar3 = HeapSize(DAT_0053992c,0,param_1);
  return SVar3;
}

