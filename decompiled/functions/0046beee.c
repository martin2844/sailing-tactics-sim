
void __thiscall FUN_0046beee(void *this,undefined4 *param_1,uint param_2,int param_3,int param_4)

{
  undefined **ppuVar1;
  
  if (param_4 + param_2 == 0) {
    ppuVar1 = FUN_0046bd74();
    *param_1 = *ppuVar1;
  }
  else {
    FUN_0046bdc1(param_1,param_4 + param_2);
    FUN_00457850((undefined4 *)*param_1,(undefined4 *)(*(int *)this + param_3),param_2);
  }
  return;
}

