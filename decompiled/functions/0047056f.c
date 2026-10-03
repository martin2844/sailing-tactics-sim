
void __thiscall
FUN_0047056f(void *this,int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  tagSIZE local_c;
  
  local_c.cx = (LONG)this;
  local_c.cy = (LONG)this;
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    ScaleWindowExtEx(*(HDC *)((int)this + 4),param_2,param_3,param_4,param_5,&local_c);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    ScaleWindowExtEx(*(HDC *)((int)this + 8),param_2,param_3,param_4,param_5,&local_c);
  }
  *param_1 = local_c.cx;
  param_1[1] = local_c.cy;
  return;
}

