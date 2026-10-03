
bool FUN_004b1f41(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  char local_108 [256];
  Tact2010CString *local_8;
  
  iVar1 = FUN_004b1fc5(param_1,local_108,0x100);
  if (0x100U - iVar1 < 3) {
    iVar3 = 0x100;
    do {
      iVar4 = iVar3 + 0x100;
      iVar1 = iVar4;
      uVar2 = FUN_004b0956(iVar3 + 0xff);
      iVar1 = FUN_004b1fc5(param_1,uVar2,iVar1);
      iVar3 = iVar4;
    } while (iVar4 - iVar1 < 3);
    FUN_004b09a5(0xffffffff);
  }
  else {
    FUN_004b06ed(local_8,local_108);
  }
  return 0 < iVar1;
}

