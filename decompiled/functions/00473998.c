
void __thiscall FUN_00473998(void *this,undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)((int)this + 8);
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar2;
    (**(code **)(*(int *)puVar2[2] + 0x84))(param_1);
    puVar2 = puVar1;
  }
  return;
}

