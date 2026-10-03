
void __thiscall FUN_004726e8(void *this,undefined4 *param_1)

{
  if (*(int **)((int)this + 0xa8) == (int *)0x0) {
    (**(code **)*param_1)(0);
  }
  else {
    (**(code **)(**(int **)((int)this + 0xa8) + 8))(param_1);
  }
  return;
}

