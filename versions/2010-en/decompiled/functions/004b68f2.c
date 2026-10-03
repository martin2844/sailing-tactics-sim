
undefined4 __thiscall
FUN_004b68f2(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  
  if (param_2 == 0x2b) {
    (**(code **)(*param_1 + 0xe8))(param_4);
    uVar1 = 1;
  }
  else {
    uVar1 = FUN_004ae672(param_2,param_3,param_4,param_5);
  }
  return uVar1;
}

