
undefined4 FUN_004ac858(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0x360) {
    uVar1 = 1;
  }
  else {
    uVar1 = FUN_004ac7d4(param_1);
    uVar1 = FUN_004ac540(uVar1,param_1,param_2,param_3,param_4);
  }
  return uVar1;
}

