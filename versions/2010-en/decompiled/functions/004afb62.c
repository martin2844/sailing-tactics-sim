
undefined4 __thiscall FUN_004afb62(undefined4 *param_1,int *param_2,int param_3)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 local_10 [2];
  undefined4 local_8;
  
  if ((param_1[1] == 0) || (*(short *)(param_1 + 1) == -1)) {
    local_8 = 1;
  }
  else {
    iVar1 = *param_2;
    param_1[6] = 0;
    pcVar2 = *(code **)(iVar1 + 0x14);
    local_8 = (*pcVar2)(param_1[1],0xffffffff,param_1,0);
    if ((param_3 != 0) && (param_1[6] == 0)) {
      local_10[0] = 0;
      uVar3 = (*pcVar2)(param_1[1],0,param_1,local_10);
      (**(code **)*param_1)(uVar3);
    }
  }
  return local_8;
}

