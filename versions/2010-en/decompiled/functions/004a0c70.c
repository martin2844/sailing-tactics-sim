
int FUN_004a0c70(int param_1)

{
  bool bVar1;
  
  if (DAT_005387a0 == 0) {
    if ((0x60 < param_1) && (param_1 < 0x7b)) {
      return param_1 + -0x20;
    }
  }
  else {
    InterlockedIncrement((LONG *)&DAT_00539928);
    bVar1 = DAT_00539924 != 0;
    if (bVar1) {
      InterlockedDecrement((LONG *)&DAT_00539928);
      FUN_0049fe10(0x13);
    }
    param_1 = FUN_004a0d00(param_1);
    if (bVar1) {
      FUN_0049fe90(0x13);
      return param_1;
    }
    InterlockedDecrement((LONG *)&DAT_00539928);
  }
  return param_1;
}

