
undefined4 * __thiscall FUN_0046705e(void *this,uint param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  
  uVar1 = param_1;
  puVar2 = FUN_00466ff9(this,param_1,&param_1);
  if (puVar2 == (undefined4 *)0x0) {
    if (*(int *)((int)this + 4) == 0) {
      FUN_00466ef2(this,*(int *)((int)this + 8),1);
    }
    puVar2 = (undefined4 *)FUN_00466f96((int)this);
    puVar2[1] = uVar1;
    *puVar2 = *(undefined4 *)(*(int *)((int)this + 4) + param_1 * 4);
    *(undefined4 **)(*(int *)((int)this + 4) + param_1 * 4) = puVar2;
  }
  return puVar2 + 2;
}

