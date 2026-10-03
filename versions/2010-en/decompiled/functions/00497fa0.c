
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00497fa0(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*param_2;
  (*(code *)*puVar1)(1);
  if (_DAT_004da230 == _DAT_004cc650) {
    (*(code *)puVar1[1])(1);
    return;
  }
  (*(code *)puVar1[1])(0);
  return;
}

