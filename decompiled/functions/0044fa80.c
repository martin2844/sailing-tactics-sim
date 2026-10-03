
void __thiscall FUN_0044fa80(void *this,int *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if ((DAT_004ac8f8 == 0) && (DAT_004ac9ac == 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  puVar1 = (undefined4 *)*param_1;
  (*(code *)*puVar1)(uVar2);
  (*(code *)puVar1[1])(DAT_00491144 == 5);
  return;
}

