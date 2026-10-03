
void __thiscall FUN_004702b4(void *this,int param_1)

{
  HGDIOBJ pvVar1;
  
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    if (param_1 == 0) {
      pvVar1 = (HGDIOBJ)0x0;
    }
    else {
      pvVar1 = *(HGDIOBJ *)(param_1 + 4);
    }
    SelectObject(*(HDC *)((int)this + 4),pvVar1);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    if (param_1 == 0) {
      pvVar1 = (HGDIOBJ)0x0;
    }
    else {
      pvVar1 = *(HGDIOBJ *)(param_1 + 4);
    }
    SelectObject(*(HDC *)((int)this + 8),pvVar1);
  }
  FUN_00470a17();
  return;
}

