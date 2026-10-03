
void __thiscall FUN_0046ae4c(void *this,int param_1)

{
  if (*(int **)((int)this + 0x38) == (int *)0x0) {
    ShowWindow(*(HWND *)((int)this + 0x1c),param_1);
  }
  else {
    (**(code **)(**(int **)((int)this + 0x38) + 0xa8))(param_1);
  }
  return;
}

