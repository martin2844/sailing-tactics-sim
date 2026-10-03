
void __cdecl
FUN_0044d990(int *param_1,int param_2,int param_3,int param_4,undefined4 param_5,int param_6)

{
  if (param_6 == 1) {
    if (DAT_004a70e4 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004a70e4);
    }
  }
  else {
    (**(code **)(*param_1 + 0x2c))(5);
  }
  (**(code **)(*param_1 + 0x2c))(7);
  if (DAT_004a763c < 0x2ee) {
    RoundRect((HDC)param_1[1],(int)param_1,param_2,param_3,param_4,5,5);
    return;
  }
  if (param_6 == 1) {
    RoundRect((HDC)param_1[1],(int)param_1 + 2,param_2 + 1,param_3 + 3,param_4,0xc,0xc);
  }
  if (param_6 == 0) {
    RoundRect((HDC)param_1[1],(int)param_1 + -2,param_2 + 1,param_3 + -3,param_4,0xc,0xc);
  }
  if (param_6 == -1) {
    RoundRect((HDC)param_1[1],(int)param_1,param_2,param_3,param_4,0xc,0xc);
  }
  return;
}

