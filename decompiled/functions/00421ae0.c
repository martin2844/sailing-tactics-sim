
void __cdecl FUN_00421ae0(int param_1,int param_2)

{
  int iVar1;
  
  if ((DAT_004a4958 == 5) && (param_2 < 1)) {
    DAT_004a71a8 = 0x10e;
    DAT_004aa284 = 0x5a;
    return;
  }
  if ((DAT_004a4958 == 5) && (0 < param_2)) {
    DAT_004aa284 = 0x10e;
    DAT_004a71a8 = 0x5a;
    return;
  }
  iVar1 = FUN_0041bb10(DAT_004ac284 - param_1,param_2 - DAT_004a3a08);
  if (DAT_004a5a4c == 0) {
    iVar1 = iVar1 + 0xb4;
  }
  DAT_004aa284 = FUN_00413cb0(iVar1 + 0x5a);
  DAT_004a71a8 = FUN_00413cb0(iVar1 + -0x5a);
  return;
}

