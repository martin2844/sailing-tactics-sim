
void __thiscall FUN_004b05ce(int *param_1,undefined4 *param_2,int param_3,int param_4,int param_5)

{
  undefined4 *puVar1;
  
  if (param_5 + param_3 == 0) {
    puVar1 = (undefined4 *)FUN_004b0454();
    *param_2 = *puVar1;
  }
  else {
    FUN_004b04a1(param_5 + param_3);
    FUN_0049c110(*param_2,*param_1 + param_4,param_3);
  }
  return;
}

