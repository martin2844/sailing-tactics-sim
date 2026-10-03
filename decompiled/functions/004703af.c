
int __thiscall FUN_004703af(void *this,int param_1)

{
  undefined4 local_8;
  
  local_8 = this;
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    local_8 = (void *)SetMapMode(*(HDC *)((int)this + 4),param_1);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    local_8 = (void *)SetMapMode(*(HDC *)((int)this + 8),param_1);
  }
  return (int)local_8;
}

