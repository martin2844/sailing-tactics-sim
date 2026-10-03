
void __thiscall FUN_004679cb(void *this,INT_PTR param_1)

{
  if ((*(byte *)((int)this + 0x24) & 0x18) != 0) {
    (**(code **)(*(int *)this + 0x7c))(param_1);
  }
  EndDialog(*(HWND *)((int)this + 0x1c),param_1);
  return;
}

