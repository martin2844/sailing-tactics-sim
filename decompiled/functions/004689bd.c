
void __thiscall FUN_004689bd(void *this,UINT param_1,WPARAM param_2,LPARAM param_3)

{
  int *piVar1;
  WNDPROC lpPrevWndFunc;
  
  lpPrevWndFunc = *(WNDPROC *)((int)this + 0x28);
  if (lpPrevWndFunc == (WNDPROC)0x0) {
    piVar1 = (int *)(**(code **)(*(int *)this + 0x88))();
    lpPrevWndFunc = (WNDPROC)*piVar1;
    if (lpPrevWndFunc == (WNDPROC)0x0) {
      DefWindowProcA(*(HWND *)((int)this + 0x1c),param_1,param_2,param_3);
      return;
    }
  }
  CallWindowProcA(lpPrevWndFunc,*(HWND *)((int)this + 0x1c),param_1,param_2,param_3);
  return;
}

