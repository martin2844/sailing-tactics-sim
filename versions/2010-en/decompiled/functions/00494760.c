
void __thiscall FUN_00494760(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if ((DAT_004da140 == 2) || (DAT_004da194 == 2)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  puVar1 = (undefined4 *)*param_2;
  (*(code *)*puVar1)(uVar2);
  (*(code *)puVar1[1])(DAT_00512d64 == 100);
  return;
}

