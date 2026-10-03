
LRESULT __cdecl FUN_00462a90(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4,int param_5)

{
  WNDPROC lpPrevWndFunc;
  LRESULT LVar1;
  
  lpPrevWndFunc = FUN_00462860(param_1,param_5);
  LVar1 = CallWindowProcA(lpPrevWndFunc,param_1,param_2,param_3,param_4);
  RemovePropA(param_1,(LPCSTR)(uint)DAT_004aff4e);
  RemovePropA(param_1,(LPCSTR)(uint)DAT_004aff54);
  return LVar1;
}

