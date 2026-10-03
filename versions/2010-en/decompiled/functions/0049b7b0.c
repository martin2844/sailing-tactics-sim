
uint FUN_0049b7b0(void)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = FUN_0049e5b0();
  uVar1 = *(int *)(iVar2 + 0x14) * 0x343fd + 0x269ec3;
  *(uint *)(iVar2 + 0x14) = uVar1;
  return uVar1 >> 0x10 & 0x7fff;
}

