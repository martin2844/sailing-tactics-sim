
int FUN_004ac6cc(void)

{
  int iVar1;
  LONG LVar2;
  DWORD DVar3;
  
  iVar1 = FUN_004c04f2(FUN_0049a32a);
  LVar2 = GetMessageTime();
  *(LONG *)(iVar1 + 0x44) = LVar2;
  DVar3 = GetMessagePos();
  *(int *)(iVar1 + 0x48) = (int)(short)DVar3;
  *(int *)(iVar1 + 0x4c) = (int)(short)(DVar3 >> 0x10);
  return iVar1 + 0x34;
}

