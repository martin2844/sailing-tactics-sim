
void __thiscall FUN_00472ecb(void *this,int param_1)

{
  int yBottom;
  int xRight;
  int yBottom_00;
  tagRECT local_18;
  int local_8;
  
  FUN_00468021(this);
  if ((*(byte *)(param_1 + 0x18) & 1) == 0) {
    GetWindowRect(*(HWND *)((int)this + 0x1c),&local_18);
    xRight = local_18.right - local_18.left;
    local_8 = *(int *)(param_1 + 0x10);
    yBottom_00 = local_18.bottom - local_18.top;
    yBottom = *(int *)(param_1 + 0x14);
    if ((local_8 != xRight) && ((*(byte *)((int)this + 0x65) & 4) != 0)) {
      SetRect(&local_18,local_8 - DAT_004ae648,0,local_8,yBottom);
      InvalidateRect(*(HWND *)((int)this + 0x1c),&local_18,1);
      SetRect(&local_18,xRight - DAT_004ae648,0,xRight,yBottom);
      InvalidateRect(*(HWND *)((int)this + 0x1c),&local_18,1);
    }
    if ((yBottom != yBottom_00) && ((*(byte *)((int)this + 0x65) & 8) != 0)) {
      SetRect(&local_18,0,yBottom - DAT_004ae64c,local_8,yBottom);
      InvalidateRect(*(HWND *)((int)this + 0x1c),&local_18,1);
      SetRect(&local_18,0,yBottom_00 - DAT_004ae64c,local_8,yBottom_00);
      InvalidateRect(*(HWND *)((int)this + 0x1c),&local_18,1);
    }
  }
  return;
}

