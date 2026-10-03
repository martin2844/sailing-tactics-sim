
void __thiscall FUN_00453a90(void *this,int *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if ((DAT_00491140 == 2) || (DAT_0049118c == 2)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  puVar1 = (undefined4 *)*param_1;
  (*(code *)*puVar1)(uVar2);
  (*(code *)puVar1[1])(DAT_004a9444 == 100);
  return;
}

