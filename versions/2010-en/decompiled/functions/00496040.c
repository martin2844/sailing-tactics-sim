
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00496040(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (((DAT_005363b0 < 0) || (DAT_005363e4 != 0)) || (_DAT_004da230 != _DAT_004cc658)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  puVar1 = (undefined4 *)*param_2;
  (*(code *)*puVar1)(uVar2);
  (*(code *)puVar1[1])(DAT_00536480 == 1);
  return;
}

