
void FUN_004ace41(undefined4 param_1,undefined4 param_2,uint param_3,int *param_4,int param_5,
                 undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  
  if (param_5 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_5 + 0x1c);
  }
  FUN_004acd4b(0,param_1,param_2,param_3 | 0x40000000,*param_4,param_4[1],param_4[2] - *param_4,
               param_4[3] - param_4[1],uVar1,param_6,param_7);
  return;
}

