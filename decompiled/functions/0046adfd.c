
void __thiscall
FUN_0046adfd(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,UINT param_6)

{
  HWND hWndInsertAfter;
  
  if (*(int **)((int)this + 0x38) == (int *)0x0) {
    hWndInsertAfter = (HWND)0x0;
    if (param_1 != 0) {
      hWndInsertAfter = *(HWND *)(param_1 + 0x1c);
    }
    SetWindowPos(*(HWND *)((int)this + 0x1c),hWndInsertAfter,param_2,param_3,param_4,param_5,param_6
                );
  }
  else {
    (**(code **)(**(int **)((int)this + 0x38) + 0xa4))
              (param_1,param_2,param_3,param_4,param_5,param_6);
  }
  return;
}

