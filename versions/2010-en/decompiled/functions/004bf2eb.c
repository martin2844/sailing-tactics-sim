
void __fastcall FUN_004bf2eb(int param_1)

{
  int iVar1;
  
  if (*(int **)(param_1 + 0xa8) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0xa8) + 0x10))();
  }
  if (*(int *)(param_1 + 0xb4) != 0) {
    iVar1 = FUN_004bfff8();
    FUN_004b6ebd("Settings","PreviewPages",*(undefined4 *)(*(int *)(iVar1 + 4) + 0xb4));
  }
  return;
}

