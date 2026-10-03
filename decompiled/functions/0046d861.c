
bool FUN_0046d861(UINT param_1)

{
  int iVar1;
  LPSTR pCVar2;
  int iVar3;
  int iVar4;
  CHAR local_108 [256];
  void *local_8;
  
  iVar1 = FUN_0046d8e5(param_1,local_108,0x100);
  if (0x100U - iVar1 < 3) {
    iVar3 = 0x100;
    do {
      iVar4 = iVar3 + 0x100;
      iVar1 = iVar4;
      pCVar2 = (LPSTR)FUN_0046c276(local_8,iVar3 + 0xff);
      iVar1 = FUN_0046d8e5(param_1,pCVar2,iVar1);
      iVar3 = iVar4;
    } while (iVar4 - iVar1 < 3);
    FUN_0046c2c5(local_8,-1);
  }
  else {
    FUN_0046c00d(local_8,local_108);
  }
  return 0 < iVar1;
}

