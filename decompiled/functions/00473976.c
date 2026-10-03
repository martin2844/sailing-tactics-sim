
undefined4 __fastcall FUN_00473976(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(param_1 + 8);
  do {
    if (puVar3 == (undefined4 *)0x0) {
      return 1;
    }
    puVar1 = (undefined4 *)*puVar3;
    iVar2 = (**(code **)(*(int *)puVar3[2] + 0x80))();
    puVar3 = puVar1;
  } while (iVar2 != 0);
  return 0;
}

