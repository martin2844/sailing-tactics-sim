
char * __cdecl FUN_004570e0(uint param_1,char *param_2,uint param_3)

{
  if ((param_3 == 10) && ((int)param_1 < 0)) {
    FUN_00457120(param_1,param_2,10,1);
    return param_2;
  }
  FUN_00457120(param_1,param_2,param_3,0);
  return param_2;
}

