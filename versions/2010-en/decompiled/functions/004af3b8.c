
void __thiscall FUN_004af3b8(int param_1,LPMSG param_2)

{
  int iVar1;
  
  if ((*(byte *)(param_1 + 0x25) & 1) == 0) {
    IsDialogMessageA(*(HWND *)(param_1 + 0x1c),param_2);
  }
  else {
    iVar1 = FUN_004bfff8();
    (**(code **)(**(int **)(iVar1 + 0x1038) + 0x24))(param_1,param_2);
  }
  return;
}

