
uint FUN_004a26a0(uint param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = FUN_004a2700();
  uVar1 = param_2 & param_1 | ~param_2 & uVar1;
  FUN_004a27a0(uVar1);
  return uVar1;
}

