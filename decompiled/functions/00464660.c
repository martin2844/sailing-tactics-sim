
void __cdecl
FUN_00464660(HWND param_1,HDC param_2,RECT *param_3,char *param_4,int param_5,short param_6,
            int param_7)

{
  BOOL BVar1;
  HGDIOBJ pvVar2;
  int iVar3;
  HWND pHVar4;
  int iVar5;
  int local_18;
  int local_14;
  tagRECT local_10;
  
  local_10.left = param_3->left;
  local_10.top = param_3->top;
  local_10.right = param_3->right;
  local_10.bottom = param_3->bottom;
  FUN_00462b70(param_2,&param_3->left,7,7,0xf);
  InflateRect(&local_10,-1,-1);
  if ((param_6 == 1) && (BVar1 = IsWindowEnabled(param_1), BVar1 != 0)) {
    FUN_00462b70(param_2,&local_10.left,7,7,0xf);
    InflateRect(&local_10,-1,-1);
  }
  PatBlt(param_2,param_3->left,param_3->top,1,1,0xf00021);
  PatBlt(param_2,param_3->right + -1,param_3->top,1,1,0xf00021);
  PatBlt(param_2,param_3->left,param_3->bottom + -1,1,1,0xf00021);
  PatBlt(param_2,param_3->right + -1,param_3->bottom + -1,1,1,0xf00021);
  iVar5 = (param_7 == 0) + 1;
  pvVar2 = DAT_004aff84;
  if (param_7 != 0) {
    pvVar2 = DAT_004aff8c;
  }
  pvVar2 = SelectObject(param_2,pvVar2);
  PatBlt(param_2,local_10.left,local_10.top,iVar5,local_10.bottom - local_10.top,0xf00021);
  PatBlt(param_2,local_10.left,local_10.top,local_10.right - local_10.left,iVar5,0xf00021);
  if (param_7 == 0) {
    iVar5 = 0;
    SelectObject(param_2,DAT_004aff8c);
    local_10.bottom = local_10.bottom + -1;
    local_10.right = local_10.right + -1;
    do {
      PatBlt(param_2,local_10.left,local_10.bottom,(local_10.right - local_10.left) + 1,1,0xf00021);
      PatBlt(param_2,local_10.right,local_10.top,1,local_10.bottom - local_10.top,0xf00021);
      if (iVar5 < 1) {
        InflateRect(&local_10,-1,-1);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 2);
  }
  local_10.left = local_10.left + 1;
  local_10.top = local_10.top + 1;
  SelectObject(param_2,DAT_004aff88);
  PatBlt(param_2,local_10.left,local_10.top,local_10.right - local_10.left,
         local_10.bottom - local_10.top,0xf00021);
  BVar1 = IsWindowEnabled(param_1);
  if (BVar1 == 0) {
    SetTextColor(param_2,DAT_004aff7c);
  }
  FUN_00462d60(param_2,param_4,&local_18,&local_14);
  local_10.top = local_10.top + ((local_10.bottom - local_10.top) - local_14) / 2;
  local_10.left = local_10.left + ((local_10.right - local_10.left) - local_18) / 2;
  iVar5 = local_10.top + local_14;
  if (local_10.bottom <= local_10.top + local_14) {
    iVar5 = local_10.bottom;
  }
  iVar3 = local_10.left + local_18;
  if (local_10.right <= local_10.left + local_18) {
    iVar3 = local_10.right;
  }
  local_10.right = iVar3;
  if (param_7 != 0) {
    local_10.bottom = iVar5;
    OffsetRect(&local_10,1,1);
    iVar3 = param_3->right + -3;
    if (local_10.right <= iVar3) {
      iVar3 = local_10.right;
    }
    iVar5 = param_3->bottom + -3;
    local_10.right = iVar3;
    if (local_10.bottom <= iVar5) {
      iVar5 = local_10.bottom;
    }
  }
  local_10.bottom = iVar5;
  DrawTextA(param_2,param_4,param_5,&local_10,0x20);
  pHVar4 = GetFocus();
  if (pHVar4 == param_1) {
    InflateRect(&local_10,1,1);
    IntersectRect(&local_10,&local_10,param_3);
    DrawFocusRect(param_2,&local_10);
  }
  if (pvVar2 != (HGDIOBJ)0x0) {
    SelectObject(param_2,pvVar2);
  }
  return;
}

