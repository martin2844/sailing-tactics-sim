
void __fastcall FUN_004b938c(int param_1)

{
  int iVar1;
  HWND pHVar2;
  tagPOINT local_14;
  tagPOINT local_c;
  
  iVar1 = FUN_004bcdcf();
  if (iVar1 == 0) {
    local_c.x = *(int *)(param_1 + 0xa8);
    local_c.y = *(int *)(param_1 + 0xac);
    if ((local_c.x < 0) || (local_c.y < 0)) {
      local_c.x = *(int *)(param_1 + 0x94);
      local_c.y = *(int *)(param_1 + 0x98);
      pHVar2 = GetParent(*(HWND *)(*(int *)(param_1 + 0x68) + 0x1c));
      iVar1 = FUN_004ac7ac(pHVar2);
      ClientToScreen(*(HWND *)(iVar1 + 0x1c),&local_c);
    }
    FUN_004be598(*(undefined4 *)(param_1 + 0x68),local_c.x,local_c.y,*(undefined4 *)(param_1 + 0xa4)
                );
  }
  else if ((*(byte *)(*(int *)(param_1 + 0x68) + 0x69) & 0xf0) != 0) {
    local_14.x = *(LONG *)(param_1 + 0x94);
    local_14.y = *(LONG *)(param_1 + 0x98);
    local_c.x = *(LONG *)(param_1 + 0x9c);
    local_c.y = *(LONG *)(param_1 + 0xa0);
    iVar1 = 0;
    if (*(int *)(param_1 + 0x90) != 0) {
      iVar1 = FUN_004bc506(*(int *)(param_1 + 0x90));
      ClientToScreen(*(HWND *)(iVar1 + 0x1c),&local_14);
      ClientToScreen(*(HWND *)(iVar1 + 0x1c),&local_c);
    }
    FUN_004be509(*(undefined4 *)(param_1 + 0x68),iVar1,&local_14);
    (**(code **)(**(int **)(param_1 + 0x6c) + 0xd0))(1);
  }
  return;
}

