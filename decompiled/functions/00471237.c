
void __thiscall FUN_00471237(void *this,int *param_1)

{
  int iVar1;
  int iVar2;
  tagRECT local_14;
  
  iVar1 = FUN_00469a1e(this,1);
  iVar2 = FUN_00469a1e(this,0);
  if (*(int *)((int)this + 100) != 0) {
    GetClientRect(*(HWND *)((int)this + 0x1c),&local_14);
    if (*(int *)((int)this + 0x4c) < local_14.right - local_14.left) {
      iVar2 = ((local_14.right - local_14.left) - *(int *)((int)this + 0x4c)) / -2;
    }
    if (*(int *)((int)this + 0x50) < local_14.bottom - local_14.top) {
      iVar1 = ((local_14.bottom - local_14.top) - *(int *)((int)this + 0x50)) / -2;
    }
  }
  *param_1 = iVar2;
  param_1[1] = iVar1;
  return;
}

