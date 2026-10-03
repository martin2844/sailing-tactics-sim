
void __thiscall FUN_00453500(void *this,int *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (((DAT_00491188 < 7) || (8 < DAT_00491188)) || (DAT_00491140 != 1)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  puVar1 = (undefined4 *)*param_1;
  (*(code *)*puVar1)(uVar2);
  if (((DAT_004a4efc == 2) && (6 < DAT_00491188)) && (DAT_00491188 < 9)) {
    (*(code *)puVar1[1])(1);
    return;
  }
  (*(code *)puVar1[1])(0);
  return;
}

