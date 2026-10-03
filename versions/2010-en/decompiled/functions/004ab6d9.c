
undefined4 * __thiscall FUN_004ab6d9(int param_1,uint param_2,uint *param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = (param_2 >> 4) % *(uint *)(param_1 + 8);
  *param_3 = uVar2;
  if (*(int *)(param_1 + 4) != 0) {
    for (puVar1 = *(undefined4 **)(*(int *)(param_1 + 4) + uVar2 * 4); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      if (puVar1[1] == param_2) {
        return puVar1;
      }
    }
  }
  return (undefined4 *)0x0;
}

