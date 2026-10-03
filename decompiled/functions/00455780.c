
void __thiscall FUN_00455780(void *this,int *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if ((DAT_004911c0 < 0) || (DAT_004ac93c != 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  puVar1 = (undefined4 *)*param_1;
  (*(code *)*puVar1)(uVar2);
  (*(code *)puVar1[1])(DAT_004ac9ec == 1);
  return;
}

