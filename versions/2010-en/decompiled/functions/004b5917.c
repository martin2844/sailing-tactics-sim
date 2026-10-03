
void __thiscall FUN_004b5917(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  tagRECT local_14;
  
  iVar1 = FUN_004ae0fe(1);
  iVar2 = FUN_004ae0fe(0);
  if (*(int *)(param_1 + 100) != 0) {
    GetClientRect(*(HWND *)(param_1 + 0x1c),&local_14);
    if (*(int *)(param_1 + 0x4c) < local_14.right - local_14.left) {
      iVar2 = ((local_14.right - local_14.left) - *(int *)(param_1 + 0x4c)) / -2;
    }
    if (*(int *)(param_1 + 0x50) < local_14.bottom - local_14.top) {
      iVar1 = ((local_14.bottom - local_14.top) - *(int *)(param_1 + 0x50)) / -2;
    }
  }
  *param_2 = iVar2;
  param_2[1] = iVar1;
  return;
}

