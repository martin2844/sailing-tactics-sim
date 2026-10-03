
void FUN_004be0d6(int param_1,RECT *param_2,int param_3,int param_4,int param_5)

{
  HBRUSH pHVar1;
  tagRECT local_14;
  
  CopyRect(&local_14,param_2);
  local_14.right = local_14.left + param_3;
  pHVar1 = (HBRUSH)0x0;
  if (param_5 != 0) {
    pHVar1 = *(HBRUSH *)(param_5 + 4);
  }
  FillRect(*(HDC *)(param_1 + 4),&local_14,pHVar1);
  local_14.right = param_2->right;
  local_14.left = local_14.right - param_3;
  pHVar1 = (HBRUSH)0x0;
  if (param_5 != 0) {
    pHVar1 = *(HBRUSH *)(param_5 + 4);
  }
  FillRect(*(HDC *)(param_1 + 4),&local_14,pHVar1);
  CopyRect(&local_14,param_2);
  local_14.bottom = local_14.top + param_4;
  local_14.left = local_14.left + param_3;
  local_14.right = local_14.right - param_3;
  pHVar1 = (HBRUSH)0x0;
  if (param_5 != 0) {
    pHVar1 = *(HBRUSH *)(param_5 + 4);
  }
  FillRect(*(HDC *)(param_1 + 4),&local_14,pHVar1);
  local_14.bottom = param_2->bottom;
  local_14.top = local_14.bottom - param_4;
  pHVar1 = (HBRUSH)0x0;
  if (param_5 != 0) {
    pHVar1 = *(HBRUSH *)(param_5 + 4);
  }
  FillRect(*(HDC *)(param_1 + 4),&local_14,pHVar1);
  return;
}

