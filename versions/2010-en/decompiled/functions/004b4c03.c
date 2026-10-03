
void __thiscall FUN_004b4c03(int param_1,int *param_2,int param_3,int param_4)

{
  tagSIZE local_c;
  
  local_c.cx = param_1;
  local_c.cy = param_1;
  if (*(HDC *)(param_1 + 4) != *(HDC *)(param_1 + 8)) {
    SetWindowExtEx(*(HDC *)(param_1 + 4),param_3,param_4,&local_c);
  }
  if (*(HDC *)(param_1 + 8) != (HDC)0x0) {
    SetWindowExtEx(*(HDC *)(param_1 + 8),param_3,param_4,&local_c);
  }
  *param_2 = local_c.cx;
  param_2[1] = local_c.cy;
  return;
}

