
void __thiscall FUN_004b8078(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 8);
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar2;
    (**(code **)(*(int *)puVar2[2] + 0x84))(param_2);
    puVar2 = puVar1;
  }
  return;
}

