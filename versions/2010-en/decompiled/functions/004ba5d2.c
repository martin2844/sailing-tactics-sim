
void __thiscall FUN_004ba5d2(int param_1,undefined4 param_2,int *param_3)

{
  tagRECT local_14;
  
  SetRectEmpty(&local_14);
  FUN_004b7e00(&local_14,*(uint *)(param_1 + 100) & 0xa000);
  *param_3 = *param_3 + local_14.left;
  param_3[1] = param_3[1] + local_14.top;
  param_3[2] = param_3[2] + local_14.right;
  param_3[3] = param_3[3] + local_14.bottom;
  return;
}

