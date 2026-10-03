
undefined4 * __thiscall FUN_0046736e(void *this,byte *param_1)

{
  undefined4 *puVar1;
  void *local_8;
  
  local_8 = this;
  puVar1 = FUN_004672d0(this,param_1,(uint *)&local_8);
  if (puVar1 == (undefined4 *)0x0) {
    if (*(int *)((int)this + 4) == 0) {
      FUN_004671a5(this,*(int *)((int)this + 8),1);
    }
    puVar1 = FUN_00467270((int)this);
    puVar1[1] = local_8;
    FUN_0046c00d(puVar1 + 2,(LPCSTR)param_1);
    *puVar1 = *(undefined4 *)(*(int *)((int)this + 4) + (int)local_8 * 4);
    *(undefined4 **)(*(int *)((int)this + 4) + (int)local_8 * 4) = puVar1;
  }
  return puVar1 + 3;
}

