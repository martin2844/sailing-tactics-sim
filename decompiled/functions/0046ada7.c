
void __thiscall FUN_0046ada7(void *this,LPCSTR param_1)

{
  if (*(int **)((int)this + 0x38) == (int *)0x0) {
    SetWindowTextA(*(HWND *)((int)this + 0x1c),param_1);
  }
  else {
    (**(code **)(**(int **)((int)this + 0x38) + 0x88))(param_1);
  }
  return;
}

