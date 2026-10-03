
int __thiscall FUN_004705d7(void *this,int param_1)

{
  int iVar1;
  HRGN pHVar2;
  
  iVar1 = param_1;
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    if (param_1 == 0) {
      pHVar2 = (HRGN)0x0;
    }
    else {
      pHVar2 = *(HRGN *)(param_1 + 4);
    }
    param_1 = SelectClipRgn(*(HDC *)((int)this + 4),pHVar2);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    if (iVar1 == 0) {
      pHVar2 = (HRGN)0x0;
    }
    else {
      pHVar2 = *(HRGN *)(iVar1 + 4);
    }
    param_1 = SelectClipRgn(*(HDC *)((int)this + 8),pHVar2);
  }
  return param_1;
}

