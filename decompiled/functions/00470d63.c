
undefined4 FUN_00470d63(UINT param_1,int *param_2)

{
  int iVar1;
  byte *pbVar2;
  undefined4 uVar3;
  byte local_104 [256];
  
  iVar1 = FUN_0046d8e5(param_1,(LPSTR)local_104,0x100);
  uVar3 = 0;
  if (iVar1 != 0) {
    pbVar2 = FUN_00457780(local_104,10);
    if (pbVar2 != (byte *)0x0) {
      iVar1 = FUN_00458260(pbVar2 + 1);
      *param_2 = iVar1;
      iVar1 = MulDiv(iVar1,DAT_004ae654,0x48);
      *param_2 = iVar1;
      *pbVar2 = 0;
    }
    lstrcpynA((LPSTR)(param_2 + 7),(LPCSTR)local_104,0x20);
    uVar3 = 1;
  }
  return uVar3;
}

