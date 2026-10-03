
LPSTR FUN_004ad47f(UINT param_1,HCURSOR param_2,HBRUSH param_3,HICON param_4)

{
  HINSTANCE hInstance;
  int iVar1;
  BOOL BVar2;
  LPSTR lpClassName;
  tagWNDCLASSA local_2c;
  
  iVar1 = FUN_004bfca5();
  lpClassName = (LPSTR)(iVar1 + 0x58);
  iVar1 = FUN_004bfff8();
  hInstance = *(HINSTANCE *)(iVar1 + 8);
  if (((param_2 == (HCURSOR)0x0) && (param_3 == (HBRUSH)0x0)) && (param_4 == (HICON)0x0)) {
    wsprintfA(lpClassName,"Afx:%x:%x",hInstance,param_1);
  }
  else {
    wsprintfA(lpClassName,"Afx:%x:%x:%x:%x:%x",hInstance,param_1,param_2,param_3,param_4);
  }
  BVar2 = GetClassInfoA(hInstance,lpClassName,&local_2c);
  if (BVar2 == 0) {
    local_2c.style = param_1;
    local_2c.lpfnWndProc = DefWindowProcA_exref;
    local_2c.cbWndExtra = 0;
    local_2c.cbClsExtra = 0;
    local_2c.lpszMenuName = (LPCSTR)0x0;
    local_2c.hIcon = param_4;
    local_2c.hCursor = param_2;
    local_2c.hbrBackground = param_3;
    local_2c.hInstance = hInstance;
    local_2c.lpszClassName = lpClassName;
    iVar1 = FUN_004ad3d6(&local_2c);
    if (iVar1 == 0) {
      FUN_004b517a();
    }
  }
  return lpClassName;
}

