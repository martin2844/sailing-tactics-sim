
void __cdecl FUN_00419d50(CDC *param_1,int param_2,int param_3,int param_4)

{
  int local_8 [2];
  
  if (param_4 == 0) {
    SetPixel(*(HDC *)(param_1 + 4),param_2,param_3,0xffffff);
    return;
  }
  FUN_004706bd(param_1,local_8,param_2,param_3);
  CDC::LineTo(param_1,param_2 + -1,param_3);
  return;
}

