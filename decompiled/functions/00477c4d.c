
LRESULT __thiscall FUN_00477c4d(void *this,WPARAM param_1,LPARAM param_2)

{
  LRESULT LVar1;
  
  if ((*(byte *)((int)this + 0x24) & 0x40) == 0) {
    LVar1 = SendMessageA(*(HWND *)((int)this + 0x1c),0x362,param_1,param_2);
  }
  else {
    LVar1 = 0;
  }
  return LVar1;
}

