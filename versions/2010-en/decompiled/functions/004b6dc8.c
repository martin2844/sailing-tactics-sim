
void __thiscall FUN_004b6dc8(void *this,undefined4 *param_2)

{
  if (*(int **)((int)this + 0xa8) == (int *)0x0) {
    (**(code **)*param_2)(0);
  }
  else {
    (**(code **)(**(int **)((int)this + 0xa8) + 8))(param_2);
  }
  return;
}

