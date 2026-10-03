
void FUN_004bdac7(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  HDC pHVar5;
  tagRECT local_1c;
  int local_c;
  int local_8;
  
  local_8 = GetSystemMetrics(6);
  iVar1 = GetSystemMetrics(5);
  iVar2 = GetSystemMetrics(0x21);
  iVar3 = GetSystemMetrics(0x20);
  local_1c.top = local_8;
  local_1c.right = DAT_00538430 - iVar1;
  local_1c.bottom = DAT_00538434;
  local_1c.left = iVar1;
  uVar4 = FUN_004af3eb();
  if ((uVar4 & 0x40600) != 0) {
    OffsetRect(&local_1c,iVar3 - iVar1,iVar2 - local_8);
  }
  pHVar5 = GetWindowDC(*(HWND *)(local_c + 0x1c));
  iVar1 = FUN_004b4794(pHVar5);
  InvertRect(*(HDC *)(iVar1 + 4),&local_1c);
  ReleaseDC(*(HWND *)(local_c + 0x1c),*(HDC *)(iVar1 + 4));
  return;
}

