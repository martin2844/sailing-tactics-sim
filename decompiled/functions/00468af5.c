
void __thiscall FUN_00468af5(void *this,void *param_1)

{
  int iVar1;
  LPSTR lpString;
  int nMaxCount;
  
  if (*(int **)((int)this + 0x38) == (int *)0x0) {
    iVar1 = GetWindowTextLengthA(*(HWND *)((int)this + 0x1c));
    nMaxCount = iVar1 + 1;
    lpString = (LPSTR)FUN_0046c2ed(param_1,iVar1);
    GetWindowTextA(*(HWND *)((int)this + 0x1c),lpString,nMaxCount);
    FUN_0046c2c5(param_1,-1);
  }
  else {
    (**(code **)(**(int **)((int)this + 0x38) + 0x90))(param_1);
  }
  return;
}

