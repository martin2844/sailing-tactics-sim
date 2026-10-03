
void FUN_00424320(int *param_1,int param_2,int param_3,int param_4)

{
  int local_8 [2];
  
  if (param_4 != 0) {
    FUN_004b4d9d(param_1,local_8,param_2,param_3);
    CDC::LineTo(param_1,param_2 + -1,param_3);
    return;
  }
  if (DAT_00536450 == 0) {
    SetPixel((HDC)param_1[1],param_2,param_3,0xffffff);
    return;
  }
  SetPixel((HDC)param_1[1],param_2,param_3,0x7f7f7f);
  return;
}

