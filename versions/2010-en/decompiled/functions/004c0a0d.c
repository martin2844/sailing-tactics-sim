
void __thiscall FUN_004c0a0d(int *param_1,uint param_2)

{
  uint uVar1;
  
  FUN_0049ac27(param_2 & 0x10);
  uVar1 = param_1[0x19];
  if (uVar1 != param_2) {
    param_1[0x19] = param_2;
    (**(code **)(*param_1 + 0xdc))(uVar1,param_2);
  }
  return;
}

