
undefined4 FUN_004aefc9(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = *(uint *)(param_1 + 4);
  if (((uVar1 < 0x100) || (0x108 < uVar1)) && ((uVar1 < 0x200 || (0x209 < uVar1)))) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004af3b8(param_1);
  }
  return uVar2;
}

