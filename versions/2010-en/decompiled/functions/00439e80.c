
float10 __cdecl FUN_00439e80(int param_1,double param_2,double param_3)

{
  return SQRT(((float10)*(double *)(&DAT_004f6c10 + param_1 * 8) - (float10)param_3) *
              ((float10)*(double *)(&DAT_004f6c10 + param_1 * 8) - (float10)param_3) +
              ((float10)*(double *)(&DAT_004f6af8 + param_1 * 8) - (float10)param_2) *
              (float10)(double)((float10)*(double *)(&DAT_004f6af8 + param_1 * 8) - (float10)param_2
                               ));
}

