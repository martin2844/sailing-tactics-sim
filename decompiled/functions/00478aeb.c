
void __thiscall
FUN_00478aeb(void *this,int param_1,int param_2,int param_3,int param_4,COLORREF param_5)

{
  RECT local_14;
  
  SetBkColor(*(HDC *)((int)this + 4),param_5);
  local_14.left = param_1;
  local_14.right = param_3 + param_1;
  local_14.bottom = param_4 + param_2;
  local_14.top = param_2;
  ExtTextOutA(*(HDC *)((int)this + 4),0,0,2,&local_14,(LPCSTR)0x0,0,(INT *)0x0);
  return;
}

