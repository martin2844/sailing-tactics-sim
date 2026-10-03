
void __thiscall
FUN_004bd1cb(int param_1,int param_2,int param_3,int param_4,int param_5,COLORREF param_6)

{
  RECT local_14;
  
  SetBkColor(*(HDC *)(param_1 + 4),param_6);
  local_14.left = param_2;
  local_14.right = param_4 + param_2;
  local_14.bottom = param_5 + param_3;
  local_14.top = param_3;
  ExtTextOutA(*(HDC *)(param_1 + 4),0,0,2,&local_14,(LPCSTR)0x0,0,(INT *)0x0);
  return;
}

