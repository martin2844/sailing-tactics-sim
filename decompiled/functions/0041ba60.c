
int __cdecl FUN_0041ba60(int param_1,int param_2,int param_3)

{
  DAT_004abae4 = ((&DAT_004a9450)[DAT_004911c8] * 7) / 10 + param_3 + DAT_004a5b80;
  DAT_004ac9e8 = (((&DAT_004a9450)[DAT_004911c4] * param_2) / 100 - param_2 / 2) + param_1;
  DAT_004911c4 = DAT_004911c4 + 1;
  DAT_004911c8 = DAT_004911c8 + 1;
  if (300 < DAT_004911c4) {
    DAT_004911c4 = 1;
  }
  if (300 < DAT_004911c8) {
    DAT_004911c8 = 1;
  }
  return DAT_004ac9e8;
}

