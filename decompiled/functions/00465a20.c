
void __cdecl FUN_00465a20(HWND param_1,HDC param_2)

{
  uint uVar1;
  HGDIOBJ pvVar2;
  HWND hWnd;
  HGDIOBJ h;
  HGDIOBJ h_00;
  UINT Msg;
  HDC wParam;
  HWND lParam;
  tagRECT local_10;
  
  uVar1 = GetWindowLongA(param_1,-0x10);
  if ((uVar1 & 0x10000000) != 0) {
    GetClientRect(param_1,&local_10);
    switch(uVar1 & 0x1f) {
    case 0:
    case 1:
    case 2:
    case 0xc:
      pvVar2 = (HGDIOBJ)SendMessageA(param_1,0x31,0,0);
      if (pvVar2 == (HGDIOBJ)0x0) {
        pvVar2 = (HGDIOBJ)0x0;
      }
      else {
        pvVar2 = SelectObject(param_2,pvVar2);
      }
      SetBkMode(param_2,2);
      Msg = 0x138;
      wParam = param_2;
      lParam = param_1;
      hWnd = GetParent(param_1);
      h = (HGDIOBJ)SendMessageA(hWnd,Msg,(WPARAM)wParam,(LPARAM)lParam);
      h_00 = (HGDIOBJ)0x0;
      if (h != (HGDIOBJ)0x0) {
        h_00 = SelectObject(param_2,h);
      }
      FUN_00465940(param_1,param_2,&local_10,uVar1);
      if (pvVar2 != (HGDIOBJ)0x0) {
        SelectObject(param_2,pvVar2);
      }
      if (h_00 != (HGDIOBJ)0x0) {
        SelectObject(param_2,h_00);
        return;
      }
      break;
    case 4:
    case 7:
      FUN_00462b70(param_2,&local_10.left,2,0,0xf);
      return;
    case 5:
    case 8:
    case 0x10:
    case 0x11:
    case 0x12:
      local_10.left = local_10.left + 1;
      local_10.top = local_10.top + 1;
      FUN_00462b70(param_2,&local_10.left,0,0,0xf);
      OffsetRect(&local_10,-1,-1);
      FUN_00462b70(param_2,&local_10.left,2,2,0xf);
      return;
    case 6:
    case 9:
      FUN_00462b70(param_2,&local_10.left,0,2,0xf);
    }
  }
  return;
}

