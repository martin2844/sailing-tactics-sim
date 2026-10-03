
void __thiscall FUN_00466e78(void *this,int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (*(int *)((int)this + 8) - param_1) - param_2;
  if (iVar1 != 0) {
    FUN_00457850((undefined4 *)(*(int *)((int)this + 4) + param_1 * 4),
                 (undefined4 *)(*(int *)((int)this + 4) + (param_2 + param_1) * 4),iVar1 * 4);
  }
  *(int *)((int)this + 8) = *(int *)((int)this + 8) - param_2;
  return;
}

