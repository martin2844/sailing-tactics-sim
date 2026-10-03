
void FUN_00472995(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = 0x7fff;
  if ((param_2 == 0) || (param_3 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x7fff;
  }
  if ((param_2 == 0) || (param_3 != 0)) {
    uVar1 = 0;
  }
  *param_1 = uVar2;
  param_1[1] = uVar1;
  return;
}

