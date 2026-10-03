
void __fastcall FUN_004b9349(int param_1)

{
  int local_8;
  int iStack_4;
  
  local_8 = param_1;
  iStack_4 = param_1;
  FUN_004b9533();
  (**(code **)(**(int **)(param_1 + 0x68) + 0xc4))
            (&local_8,*(int *)(param_1 + 0x40) - *(int *)(param_1 + 0x38),0x42);
  FUN_004be598(*(undefined4 *)(param_1 + 0x68),*(undefined4 *)(param_1 + 0x48),
               *(undefined4 *)(param_1 + 0x4c),
               (ushort)*(undefined4 *)(param_1 + 0x70) & 0x40 | 0x2004);
  return;
}

