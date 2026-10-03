
void __thiscall FUN_00478eaf(void *this,int param_1)

{
  tagRECT local_24;
  tagRECT local_14;
  
  FUN_00468021(this);
  GetWindowRect(*(HWND *)((int)this + 0x1c),&local_14);
  GetClientRect(*(HWND *)((int)this + 0x1c),&local_24);
  *(LONG *)(param_1 + 0x18) = (local_14.right - local_14.left) - local_24.right;
  *(LONG *)(param_1 + 0x1c) = (local_14.bottom - local_14.top) - local_24.bottom;
  return;
}

