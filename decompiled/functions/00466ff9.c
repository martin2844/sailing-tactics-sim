
undefined4 * __thiscall FUN_00466ff9(void *this,uint param_1,uint *param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = (param_1 >> 4) % *(uint *)((int)this + 8);
  *param_2 = uVar2;
  if (*(int *)((int)this + 4) != 0) {
    for (puVar1 = *(undefined4 **)(*(int *)((int)this + 4) + uVar2 * 4); puVar1 != (undefined4 *)0x0
        ; puVar1 = (undefined4 *)*puVar1) {
      if (puVar1[1] == param_1) {
        return puVar1;
      }
    }
  }
  return (undefined4 *)0x0;
}

