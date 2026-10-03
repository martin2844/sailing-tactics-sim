
undefined4 FUN_004a3860(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  bool bVar2;
  
  InterlockedIncrement((LONG *)&DAT_00539928);
  bVar2 = DAT_00539924 != 0;
  if (bVar2) {
    InterlockedDecrement((LONG *)&DAT_00539928);
    FUN_0049fe10(0x13);
  }
  uVar1 = FUN_004a38e0(param_1,param_2,param_3);
  if (!bVar2) {
    InterlockedDecrement((LONG *)&DAT_00539928);
    return uVar1;
  }
  FUN_0049fe90(0x13);
  return uVar1;
}

