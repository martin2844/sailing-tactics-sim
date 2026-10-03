
int __cdecl FUN_00427e30(int param_1,int param_2,int param_3)

{
  DAT_00534fdc = ((&DAT_00512d70)[DAT_004da1d4] * 7) / 10 + param_3 + DAT_004f8cd0;
  DAT_005364a8 = (((&DAT_00512d70)[DAT_004da1d0] * param_2) / 100 - param_2 / 2) + param_1;
  DAT_004da1d0 = DAT_004da1d0 + 1;
  DAT_004da1d4 = DAT_004da1d4 + 1;
  if (300 < DAT_004da1d0) {
    DAT_004da1d0 = 1;
  }
  if (300 < DAT_004da1d4) {
    DAT_004da1d4 = 1;
  }
  return DAT_005364a8;
}

