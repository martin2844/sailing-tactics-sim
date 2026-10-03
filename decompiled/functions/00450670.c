
void __thiscall FUN_00450670(void *this,int *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if ((DAT_004ac8f8 == 0) && (DAT_00491194 != 8)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  puVar1 = (undefined4 *)*param_1;
  (*(code *)*puVar1)(uVar2);
  if ((DAT_00491180 == 4) && (DAT_00491194 != 8)) {
    (*(code *)puVar1[1])(1);
    return;
  }
  (*(code *)puVar1[1])(0);
  return;
}

