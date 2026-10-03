
void __thiscall FUN_004b9129(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  tagRECT local_2c;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  *(undefined4 *)(param_1 + 0x88) = 0;
  FUN_004b9472();
  GetWindowRect(*(HWND *)(*(int *)(param_1 + 0x68) + 0x1c),&local_2c);
  *(undefined4 *)(param_1 + 4) = param_3;
  *(undefined4 *)(param_1 + 8) = param_4;
  *(undefined4 *)(param_1 + 0x8c) = param_2;
  (**(code **)(**(int **)(param_1 + 0x68) + 0xc4))(&local_c,0,6);
  local_10 = local_8 + local_2c.top;
  local_14 = local_c + local_2c.left;
  *(LONG *)(param_1 + 0x28) = local_2c.left;
  *(LONG *)(param_1 + 0x2c) = local_2c.top;
  *(int *)(param_1 + 0x30) = local_14;
  *(int *)(param_1 + 0x34) = local_10;
  *(LONG *)(param_1 + 0x38) = local_2c.left;
  *(LONG *)(param_1 + 0x3c) = local_2c.top;
  *(int *)(param_1 + 0x40) = local_14;
  *(int *)(param_1 + 0x44) = local_10;
  local_1c = local_2c.left;
  local_18 = local_2c.top;
  *(int *)(param_1 + 0x48) = local_2c.left;
  *(LONG *)(param_1 + 0x4c) = local_2c.top;
  *(int *)(param_1 + 0x50) = local_14;
  *(int *)(param_1 + 0x54) = local_10;
  FUN_004be261((int *)(param_1 + 0x48),0xc40000,0);
  InflateRect((LPRECT)(param_1 + 0x48),-DAT_005381a0,-DAT_005381a4);
  local_1c = 0;
  local_18 = 0;
  local_14 = (*(int *)(param_1 + 0x50) - ((LPRECT)(param_1 + 0x48))->left) -
             (*(int *)(param_1 + 0x40) - *(int *)(param_1 + 0x38));
  local_10 = (*(int *)(param_1 + 0x54) - *(int *)(param_1 + 0x4c)) -
             (*(int *)(param_1 + 0x44) - *(int *)(param_1 + 0x3c));
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(int *)(param_1 + 0x60) = local_14;
  *(int *)(param_1 + 100) = local_10;
  FUN_004b924d(param_3,param_4);
  FUN_004b9844();
  return;
}

