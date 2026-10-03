
void __thiscall FUN_00494110(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if ((((DAT_004da190 < 7) || (8 < DAT_004da190)) || (DAT_004da140 != 1)) || (DAT_005364c8 != 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  puVar1 = (undefined4 *)*param_2;
  (*(code *)*puVar1)(uVar2);
  if (((DAT_004f7ee4 == 2) && (6 < DAT_004da190)) && ((DAT_004da190 < 9 && (DAT_005364c8 == 0)))) {
    (*(code *)puVar1[1])(1);
    return;
  }
  (*(code *)puVar1[1])(0);
  return;
}

