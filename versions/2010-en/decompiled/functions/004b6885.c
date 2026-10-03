
void FUN_004b6885(undefined4 param_1,int *param_2)

{
  tagRECT local_14;
  
  SetRectEmpty(&local_14);
  FUN_004b7e00(&local_14,1);
  *param_2 = *param_2 + local_14.left;
  param_2[1] = param_2[1] + local_14.top + -2;
  param_2[2] = param_2[2] + local_14.right;
  param_2[3] = param_2[3] + local_14.bottom;
  return;
}

