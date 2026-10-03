
void __thiscall FUN_004706bd(void *this,int *param_1,int param_2,int param_3)

{
  tagPOINT local_c;
  
  local_c.x = (LONG)this;
  local_c.y = (LONG)this;
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    MoveToEx(*(HDC *)((int)this + 4),param_2,param_3,&local_c);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    MoveToEx(*(HDC *)((int)this + 8),param_2,param_3,&local_c);
  }
  *param_1 = local_c.x;
  param_1[1] = local_c.y;
  return;
}

