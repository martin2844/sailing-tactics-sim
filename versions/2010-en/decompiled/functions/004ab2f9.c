
void __fastcall FUN_004ab2f9(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  while (param_1 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*param_1;
    FUN_004afc21(param_1);
    param_1 = puVar1;
  }
  return;
}

