
LRESULT FUN_004a7170(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4,undefined4 param_5)

{
  WNDPROC lpPrevWndFunc;
  LRESULT LVar1;
  
  lpPrevWndFunc = (WNDPROC)FUN_004a6f40(param_1,param_5);
  LVar1 = CallWindowProcA(lpPrevWndFunc,param_1,param_2,param_3,param_4);
  RemovePropA(param_1,(LPCSTR)(uint)DAT_00539a8e);
  RemovePropA(param_1,(LPCSTR)(uint)DAT_00539a94);
  return LVar1;
}

