
int __thiscall FUN_004701c7(void *this,int param_1)

{
  int iVar1;
  BOOL BVar2;
  
  iVar1 = 1;
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    iVar1 = RestoreDC(*(HDC *)((int)this + 4),param_1);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    if ((iVar1 != 0) && (BVar2 = RestoreDC(*(HDC *)((int)this + 8),param_1), BVar2 != 0)) {
      return 1;
    }
    iVar1 = 0;
  }
  return iVar1;
}

