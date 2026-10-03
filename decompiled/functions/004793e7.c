
void FUN_004793e7(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  tagRECT local_1c;
  int local_c;
  int local_8;
  
  local_8 = GetSystemMetrics(6);
  iVar1 = GetSystemMetrics(5);
  iVar2 = GetSystemMetrics(0x21);
  iVar3 = GetSystemMetrics(0x20);
  local_1c.top = local_8;
  local_1c.right = DAT_004ae8d8 - iVar1;
  local_1c.bottom = DAT_004ae8dc;
  local_1c.left = iVar1;
  uVar4 = FUN_0046ad0b(local_c);
  if ((uVar4 & 0x40600) != 0) {
    OffsetRect(&local_1c,iVar3 - iVar1,iVar2 - local_8);
  }
  GetWindowDC(*(HWND *)(local_c + 0x1c));
  iVar1 = FUN_004700b4();
  InvertRect(*(HDC *)(iVar1 + 4),&local_1c);
  ReleaseDC(*(HWND *)(local_c + 0x1c),*(HDC *)(iVar1 + 4));
  return;
}

