
void __thiscall FUN_0046acae(void *this,int param_1)

{
  if (*(int **)((int)this + 0x34) == (int *)0x0) {
    GetDlgItem(*(HWND *)((int)this + 0x1c),param_1);
    FUN_004680cc();
  }
  else {
    (**(code **)(**(int **)((int)this + 0x34) + 0x78))(param_1);
  }
  return;
}

