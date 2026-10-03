
LRESULT FUN_004b5715(HKEY param_1)

{
  HWND hWnd;
  BOOL BVar1;
  LSTATUS LVar2;
  BYTE local_120 [128];
  _OSVERSIONINFOA local_a0;
  DWORD local_c [2];
  
  if ((param_1 != (HKEY)0x0) || (DAT_00538404 == 0)) {
    DAT_00538404 = 1;
    if (DAT_00538410 == 0) {
      DAT_0053840c = RegisterWindowMessageA("MSH_SCROLL_LINES_MSG");
      DAT_00538410 = (DAT_0053840c != 0) + 1;
    }
    if (((DAT_00538410 == 2) && (hWnd = FindWindowA("MouseZ","Magellan MSWHEEL"), hWnd != (HWND)0x0)
        ) && (DAT_0053840c != 0)) {
      DAT_00538408 = SendMessageA(hWnd,DAT_0053840c,0,0);
    }
    else {
      _memset(&local_a0,0,0x94);
      local_a0.dwOSVersionInfoSize = 0x94;
      DAT_00538408 = 3;
      BVar1 = GetVersionExA(&local_a0);
      if ((BVar1 != 0) && ((local_a0.dwPlatformId == 1 || (local_a0.dwPlatformId == 2)))) {
        if (local_a0.dwMajorVersion < 4) {
          LVar2 = RegOpenKeyExA((HKEY)0x80000001,"Control Panel\\Desktop",0,1,&param_1);
          if (LVar2 == 0) {
            local_c[1] = 0x80;
            LVar2 = RegQueryValueExA(param_1,"WheelScrollLines",(LPDWORD)0x0,local_c,local_120,
                                     local_c + 1);
            if (LVar2 == 0) {
              DAT_00538408 = FUN_0049cee0(local_120,0,10);
            }
            RegCloseKey(param_1);
          }
        }
        else if ((local_a0.dwPlatformId == 2) && (3 < local_a0.dwMajorVersion)) {
          SystemParametersInfoA(0x68,0,&DAT_00538408,0);
        }
      }
    }
  }
  return DAT_00538408;
}

