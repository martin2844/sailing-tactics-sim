
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */

int __cdecl
FUN_0047dfa0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8)

{
  if (param_2 < param_8) {
    return -1;
  }
  if (param_8 < param_4) {
    return -2;
  }
  if (param_7 < (int)(longlong)
                     (((float10)(param_3 - param_1) / (float10)(param_4 - param_2)) *
                     (float10)(param_8 - param_2)) + param_1) {
    return -3;
  }
  return ((param_7 <=
          (int)(longlong)
               (((float10)(param_5 - param_6) / (float10)(param_4 - param_2)) *
               (float10)(param_8 - param_2)) + param_6) - 1 & 0xfffffffb) + 1;
}

