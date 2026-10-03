
undefined4 __thiscall FUN_0046702b(void *this,uint param_1)

{
  undefined4 *puVar1;
  
  if (*(int *)((int)this + 4) != 0) {
    for (puVar1 = *(undefined4 **)
                   (*(int *)((int)this + 4) + ((param_1 >> 4) % *(uint *)((int)this + 8)) * 4);
        puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
      if (puVar1[1] == param_1) {
        return puVar1[2];
      }
    }
  }
  return 0;
}

