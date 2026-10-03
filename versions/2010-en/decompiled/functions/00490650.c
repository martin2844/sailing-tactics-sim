
void __thiscall FUN_00490650(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if ((DAT_005363b0 == 0) && (DAT_00536470 == 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  puVar1 = (undefined4 *)*param_2;
  (*(code *)*puVar1)(uVar2);
  (*(code *)puVar1[1])(DAT_004da194 == 0x1e);
  return;
}

