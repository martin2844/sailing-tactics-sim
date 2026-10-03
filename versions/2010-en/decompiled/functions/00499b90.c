
void __thiscall FUN_00499b90(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if ((DAT_005363b0 == 0) && (DAT_00536514 == 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  puVar1 = (undefined4 *)*param_2;
  (*(code *)*puVar1)(uVar2);
  if ((((DAT_004da26c == 1) && (DAT_00536510 == 1)) && (DAT_00536514 == 0)) && (DAT_004da158 == 1))
  {
    (*(code *)puVar1[1])(1);
    return;
  }
  (*(code *)puVar1[1])(0);
  return;
}

