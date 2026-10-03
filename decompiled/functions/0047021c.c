
void __thiscall FUN_0047021c(void *this,int param_1)

{
  HGDIOBJ h;
  
  h = GetStockObject(param_1);
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    SelectObject(*(HDC *)((int)this + 4),h);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    SelectObject(*(HDC *)((int)this + 8),h);
  }
  FUN_00470a17();
  return;
}

