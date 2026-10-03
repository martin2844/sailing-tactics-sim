
void __thiscall FUN_004b4d9d(int *original_dc,int *param_2,int param_3,int param_4)

{
  tagPOINT local_c;
  
  local_c.x = (LONG)original_dc;
  local_c.y = (LONG)original_dc;
  if ((HDC)original_dc[1] != (HDC)original_dc[2]) {
    MoveToEx((HDC)original_dc[1],param_3,param_4,&local_c);
  }
  if ((HDC)original_dc[2] != (HDC)0x0) {
    MoveToEx((HDC)original_dc[2],param_3,param_4,&local_c);
  }
  *param_2 = local_c.x;
  param_2[1] = local_c.y;
  return;
}

