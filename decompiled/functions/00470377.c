
COLORREF __thiscall FUN_00470377(void *this,COLORREF param_1)

{
  undefined4 local_8;
  
  local_8 = this;
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    local_8 = (void *)SetTextColor(*(HDC *)((int)this + 4),param_1);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    local_8 = (void *)SetTextColor(*(HDC *)((int)this + 8),param_1);
  }
  return (COLORREF)local_8;
}

