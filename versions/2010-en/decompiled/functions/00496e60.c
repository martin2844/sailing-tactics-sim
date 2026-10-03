
void __thiscall FUN_00496e60(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if ((((DAT_004da194 < 0x10) || (DAT_005363b0 != 0)) || (DAT_004da19c == 8)) ||
     (((2 < DAT_004da188 && (DAT_004da188 != 5)) && (DAT_004da188 != 7)))) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  puVar1 = (undefined4 *)*param_2;
  (*(code *)*puVar1)(uVar2);
  if (((0xf < DAT_004da194) && (DAT_004da1e8 == 1)) &&
     ((DAT_004da19c != 8 && (((DAT_004da188 < 3 || (DAT_004da188 == 5)) || (DAT_004da188 == 7))))))
  {
    (*(code *)puVar1[1])(1);
    return;
  }
  (*(code *)puVar1[1])(0);
  return;
}

