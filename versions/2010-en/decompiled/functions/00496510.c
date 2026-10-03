
void __thiscall FUN_00496510(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if ((DAT_004da1cc < 0) || (DAT_005363f4 != 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  puVar1 = (undefined4 *)*param_2;
  (*(code *)*puVar1)(uVar2);
  (*(code *)puVar1[1])(DAT_005364ac == 1);
  return;
}

