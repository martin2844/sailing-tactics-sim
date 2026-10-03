
void __thiscall FUN_0046c2c5(void *this,int param_1)

{
  FUN_0046be6e(this);
  if (param_1 == -1) {
    param_1 = lstrlenA(*(LPCSTR *)this);
  }
  *(int *)(*(int *)this + -8) = param_1;
  *(undefined1 *)(*(int *)this + param_1) = 0;
  return;
}

