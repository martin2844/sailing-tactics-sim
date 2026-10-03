
void __thiscall FUN_00466fe0(void *this,undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = *(undefined4 *)((int)this + 0x10);
  piVar1 = (int *)((int)this + 0xc);
  *piVar1 = *piVar1 + -1;
  *(undefined4 **)((int)this + 0x10) = param_1;
  if (*piVar1 == 0) {
    RemoveAll((int)this);
  }
  return;
}

