
void __thiscall FUN_00466dbc(void *this,int param_1,undefined4 param_2)

{
  if (*(int *)((int)this + 8) <= param_1) {
    FUN_00466c99(this,param_1 + 1,-1);
  }
  *(undefined4 *)(*(int *)((int)this + 4) + param_1 * 4) = param_2;
  return;
}

