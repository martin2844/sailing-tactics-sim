
void __thiscall FUN_00494ae0(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if ((((DAT_005363b0 < 2) || (DAT_005233a8 != 0)) || (DAT_00536438 != 0)) || (DAT_005363f0 != 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  puVar1 = (undefined4 *)*param_2;
  (*(code *)*puVar1)(uVar2);
  (*(code *)puVar1[1])(DAT_00536444 == 2);
  return;
}

