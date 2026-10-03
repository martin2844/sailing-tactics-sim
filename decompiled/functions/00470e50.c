
HWND FUN_00470e50(HWND param_1,LONG param_2,LONG param_3)

{
  POINT pt;
  int iVar1;
  uint uVar2;
  BOOL BVar3;
  UINT uCmd;
  tagRECT local_14;
  
  ClientToScreen(param_1,(LPPOINT)&param_2);
  uCmd = 5;
  do {
    param_1 = GetWindow(param_1,uCmd);
    if (param_1 == (HWND)0x0) {
      return (HWND)0x0;
    }
    iVar1 = GetDlgCtrlID(param_1);
    if (((short)iVar1 != -1) && (uVar2 = GetWindowLongA(param_1,-0x10), (uVar2 & 0x10000000) != 0))
    {
      GetWindowRect(param_1,&local_14);
      pt.y = param_3;
      pt.x = param_2;
      BVar3 = PtInRect(&local_14,pt);
      if (BVar3 != 0) {
        return param_1;
      }
    }
    uCmd = 2;
  } while( true );
}

