
void __thiscall FUN_004bd58f(int param_1,int param_2)

{
  tagRECT local_24;
  tagRECT local_14;
  
  FUN_004ac701();
  GetWindowRect(*(HWND *)(param_1 + 0x1c),&local_14);
  GetClientRect(*(HWND *)(param_1 + 0x1c),&local_24);
  *(LONG *)(param_2 + 0x18) = (local_14.right - local_14.left) - local_24.right;
  *(LONG *)(param_2 + 0x1c) = (local_14.bottom - local_14.top) - local_24.bottom;
  return;
}

