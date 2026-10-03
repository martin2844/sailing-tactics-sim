
void __fastcall FUN_00474cac(int param_1)

{
  int iVar1;
  CWnd *pCVar2;
  void *pvVar3;
  undefined1 local_14 [12];
  LONG local_8;
  
  iVar1 = FUN_004786ef(*(int **)(param_1 + 0x68));
  if (iVar1 == 0) {
    local_14._8_4_ = *(int *)(param_1 + 0xa8);
    local_8 = *(int *)(param_1 + 0xac);
    if (((int)local_14._8_4_ < 0) || (local_8 < 0)) {
      local_14._8_4_ = *(int *)(param_1 + 0x94);
      local_8 = *(int *)(param_1 + 0x98);
      GetParent(*(HWND *)(*(int *)(param_1 + 0x68) + 0x1c));
      pCVar2 = FUN_004680cc();
      ClientToScreen(*(HWND *)(pCVar2 + 0x1c),(LPPOINT)(local_14 + 8));
    }
    FUN_00479eb8(*(void **)(param_1 + 0x6c),*(void **)(param_1 + 0x68),local_14._8_4_,local_8,
                 *(uint *)(param_1 + 0xa4));
  }
  else if ((*(byte *)(*(int *)(param_1 + 0x68) + 0x69) & 0xf0) != 0) {
    local_14._0_4_ = *(LONG *)(param_1 + 0x94);
    local_14._4_4_ = *(LONG *)(param_1 + 0x98);
    local_14._8_4_ = *(LONG *)(param_1 + 0x9c);
    local_8 = *(LONG *)(param_1 + 0xa0);
    pvVar3 = (void *)0x0;
    if (*(uint *)(param_1 + 0x90) != 0) {
      pvVar3 = (void *)FUN_00477e26(*(void **)(param_1 + 0x6c),*(uint *)(param_1 + 0x90));
      ClientToScreen(*(HWND *)((int)pvVar3 + 0x1c),(LPPOINT)local_14);
      ClientToScreen(*(HWND *)((int)pvVar3 + 0x1c),(LPPOINT)(local_14 + 8));
    }
    FUN_00479e29(*(void **)(param_1 + 0x6c),*(void **)(param_1 + 0x68),pvVar3,(RECT *)local_14);
    (**(code **)(**(int **)(param_1 + 0x6c) + 0xd0))(1);
  }
  return;
}

