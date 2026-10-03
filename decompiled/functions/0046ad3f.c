
void __thiscall FUN_0046ad3f(void *this,uint param_1,uint param_2,uint param_3)

{
  if (*(int **)((int)this + 0x38) == (int *)0x0) {
    FUN_00467ddd(*(HWND *)((int)this + 0x1c),param_1,param_2,param_3);
  }
  else {
    (**(code **)(**(int **)((int)this + 0x38) + 0x80))(param_1,param_2,param_3);
  }
  return;
}

