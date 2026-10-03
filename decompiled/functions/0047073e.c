
UINT __thiscall FUN_0047073e(void *this,UINT param_1)

{
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    SetTextAlign(*(HDC *)((int)this + 4),param_1);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    param_1 = SetTextAlign(*(HDC *)((int)this + 8),param_1);
  }
  return param_1;
}

