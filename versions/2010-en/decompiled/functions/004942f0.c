
void __thiscall FUN_004942f0(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)*param_2;
  (*(code *)*puVar1)(DAT_005364c8 == 0);
  uVar2 = 1;
  if ((DAT_004fe77c != 1) || (DAT_005364c8 != 0)) {
    uVar2 = 0;
  }
  (*(code *)puVar1[1])(uVar2);
  return;
}

