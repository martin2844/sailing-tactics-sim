
int __thiscall FUN_004b49e7(int *original_dc,int param_2)

{
  int *local_8;
  
  local_8 = original_dc;
  if ((HDC)original_dc[1] != (HDC)original_dc[2]) {
    local_8 = (int *)SetBkColor((HDC)original_dc[1],param_2);
  }
  if ((HDC)original_dc[2] != (HDC)0x0) {
    local_8 = (int *)SetBkColor((HDC)original_dc[2],param_2);
  }
  return (int)local_8;
}

