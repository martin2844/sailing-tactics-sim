
void __cdecl
FUN_0044d990(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  if (param_6 == 1) {
    if (DAT_004a70e4 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a70e4);
    }
  }
  else {
    (**(code **)(*(int *)param_1 + 0x2c))((void *)param_1,5);
  }
  (**(code **)(*(int *)param_1 + 0x2c))((void *)param_1,7);
  if (DAT_004a763c < 0x2ee) {
    RoundRect(*(HDC *)(param_1 + 4),param_2,param_3,param_4,param_5,5,5);
    return;
  }
  if (param_7 == 1) {
    RoundRect(*(HDC *)(param_1 + 4),param_2 + 2,param_3 + 1,param_4 + 3,param_5,0xc,0xc);
  }
  if (param_7 == 0) {
    RoundRect(*(HDC *)(param_1 + 4),param_2 + -2,param_3 + 1,param_4 + -3,param_5,0xc,0xc);
  }
  if (param_7 == -1) {
    RoundRect(*(HDC *)(param_1 + 4),param_2,param_3,param_4,param_5,0xc,0xc);
  }
  return;
}

