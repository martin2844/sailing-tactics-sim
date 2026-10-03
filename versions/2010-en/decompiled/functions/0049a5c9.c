
void __thiscall
FUN_0049a5c9(int param_1,int param_2,GRAYSTRINGPROC param_3,LPARAM param_4,int param_5,int param_6,
            int param_7,int param_8,int param_9)

{
  HBRUSH hBrush;
  
  hBrush = (HBRUSH)0x0;
  if (param_2 != 0) {
    hBrush = *(HBRUSH *)(param_2 + 4);
  }
  GrayStringA(*(HDC *)(param_1 + 4),hBrush,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  return;
}

