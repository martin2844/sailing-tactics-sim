
void __thiscall FUN_004537c0(void *this,int *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if ((DAT_00491188 < 2) || (DAT_00491188 == 9)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  puVar1 = (undefined4 *)*param_1;
  (*(code *)*puVar1)(uVar2);
  (*(code *)puVar1[1])(DAT_004a4388 == 1);
  return;
}

