
void __thiscall FUN_0046ae8e(void *this,BOOL param_1)

{
  if (*(int **)((int)this + 0x38) == (int *)0x0) {
    EnableWindow(*(HWND *)((int)this + 0x1c),param_1);
  }
  else {
    (**(code **)(**(int **)((int)this + 0x38) + 0xb0))(param_1);
  }
  return;
}

