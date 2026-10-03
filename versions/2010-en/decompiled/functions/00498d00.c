
void __thiscall FUN_00498d00(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if ((DAT_005363b0 == 0) && (DAT_00536508 == 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  puVar1 = (undefined4 *)*param_2;
  (*(code *)*puVar1)(uVar2);
  if ((DAT_004da260 == 1) && (DAT_00536508 == 0)) {
    (*(code *)puVar1[1])(1);
    return;
  }
  (*(code *)puVar1[1])(0);
  return;
}

