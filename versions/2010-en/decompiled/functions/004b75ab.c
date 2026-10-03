
void __thiscall FUN_004b75ab(int param_1,int param_2)

{
  int yBottom;
  int xRight;
  int yBottom_00;
  tagRECT local_18;
  int local_8;
  
  FUN_004ac701();
  if ((*(byte *)(param_2 + 0x18) & 1) == 0) {
    GetWindowRect(*(HWND *)(param_1 + 0x1c),&local_18);
    xRight = local_18.right - local_18.left;
    local_8 = *(int *)(param_2 + 0x10);
    yBottom_00 = local_18.bottom - local_18.top;
    yBottom = *(int *)(param_2 + 0x14);
    if ((local_8 != xRight) && ((*(byte *)(param_1 + 0x65) & 4) != 0)) {
      SetRect(&local_18,local_8 - DAT_005381a0,0,local_8,yBottom);
      InvalidateRect(*(HWND *)(param_1 + 0x1c),&local_18,1);
      SetRect(&local_18,xRight - DAT_005381a0,0,xRight,yBottom);
      InvalidateRect(*(HWND *)(param_1 + 0x1c),&local_18,1);
    }
    if ((yBottom != yBottom_00) && ((*(byte *)(param_1 + 0x65) & 8) != 0)) {
      SetRect(&local_18,0,yBottom - DAT_005381a4,local_8,yBottom);
      InvalidateRect(*(HWND *)(param_1 + 0x1c),&local_18,1);
      SetRect(&local_18,0,yBottom_00 - DAT_005381a4,local_8,yBottom_00);
      InvalidateRect(*(HWND *)(param_1 + 0x1c),&local_18,1);
    }
  }
  return;
}

