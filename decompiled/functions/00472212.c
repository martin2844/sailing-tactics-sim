
uint __thiscall FUN_00472212(void *this,uint param_1,int *param_2,int param_3,int *param_4)

{
  uint uVar1;
  
  if (param_1 == 0x2b) {
    (**(code **)(*(int *)this + 0xe8))(param_3);
    uVar1 = 1;
  }
  else {
    uVar1 = FUN_00469f92(this,param_1,param_2,param_3,param_4);
  }
  return uVar1;
}

