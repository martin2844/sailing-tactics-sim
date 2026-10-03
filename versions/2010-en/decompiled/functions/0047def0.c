
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */

int __cdecl
FUN_0047def0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8)

{
  if (param_7 < param_1) {
    return -1;
  }
  if (param_4 < param_7) {
    return -2;
  }
  if (param_8 < (int)(longlong)
                     (((double)(param_5 - param_3) / (double)(param_4 - param_1)) *
                     (double)(param_7 - param_1)) + param_3) {
    return -3;
  }
  return ((param_8 <=
          (int)(longlong)
               (((double)(param_6 - param_2) / (double)(param_4 - param_1)) *
               (double)(param_7 - param_1)) + param_2) - 1 & 0xfffffffb) + 1;
}

