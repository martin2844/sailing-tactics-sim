
void __thiscall FUN_0046adce(void *this,LPSTR param_1,int param_2)

{
  if (*(int **)((int)this + 0x38) == (int *)0x0) {
    GetWindowTextA(*(HWND *)((int)this + 0x1c),param_1,param_2);
  }
  else {
    (**(code **)(**(int **)((int)this + 0x38) + 0x8c))(param_1,param_2);
  }
  return;
}

