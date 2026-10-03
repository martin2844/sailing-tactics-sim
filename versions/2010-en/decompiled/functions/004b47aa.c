
bool __thiscall FUN_004b47aa(int *param_1,int param_2)

{
  undefined4 *puVar1;
  
  if (param_2 != 0) {
    FUN_004b4724(1);
    param_1[1] = param_2;
    puVar1 = (undefined4 *)FUN_004ab73e(param_2);
    *puVar1 = param_1;
    (**(code **)(*param_1 + 0x14))(param_1[1]);
  }
  return param_2 != 0;
}

