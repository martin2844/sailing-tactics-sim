
void __thiscall FUN_00496320(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (((DAT_005363b0 == 0) && (DAT_004da190 == 7)) && (DAT_00536470 == 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  puVar1 = (undefined4 *)*param_2;
  (*(code *)*puVar1)(uVar2);
  if ((DAT_004da19c == 8) && (DAT_004f8b78 == 1)) {
    (*(code *)puVar1[1])(1);
    return;
  }
  (*(code *)puVar1[1])(0);
  return;
}

