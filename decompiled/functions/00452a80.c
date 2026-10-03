
void __thiscall FUN_00452a80(void *this,int *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if ((DAT_004ac8f8 < 2) || (DAT_004a8914 < 1)) {
    uVar2 = 0;
  }
  puVar1 = (undefined4 *)*param_1;
  (*(code *)*puVar1)(uVar2);
  (*(code *)puVar1[1])(DAT_004ac1ec == 5);
  return;
}

