
LRESULT __thiscall FUN_004bc32d(void *this,WPARAM param_2,LPARAM param_3)

{
  LRESULT LVar1;
  
  if ((*(byte *)((int)this + 0x24) & 0x40) == 0) {
    LVar1 = SendMessageA(*(HWND *)((int)this + 0x1c),0x362,param_2,param_3);
  }
  else {
    LVar1 = 0;
  }
  return LVar1;
}

