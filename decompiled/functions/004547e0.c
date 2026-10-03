
void __thiscall FUN_004547e0(void *this,int *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (((DAT_004ac8f8 < 0) || (DAT_004ac944 < 1)) || (DAT_004ac960 != 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  puVar1 = (undefined4 *)*param_1;
  (*(code *)*puVar1)(uVar2);
  (*(code *)puVar1[1])(DAT_004ac980 == 400);
  return;
}

