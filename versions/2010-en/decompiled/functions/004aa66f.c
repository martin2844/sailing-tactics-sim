
undefined4 FUN_004aa66f(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004bfff8();
  *(char *)(iVar1 + 0x14) = (char)param_1;
  if (param_1 == 0) {
    FUN_0049cfb0(0xfffffffd);
  }
  return 1;
}

