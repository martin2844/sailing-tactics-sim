
void __fastcall FUN_004b9472(int param_1)

{
  BOOL BVar1;
  HWND pHVar2;
  int iVar3;
  HDC pHVar4;
  undefined4 uVar5;
  DWORD flags;
  tagMSG local_1c;
  
  while( true ) {
    BVar1 = PeekMessageA(&local_1c,(HWND)0x0,0xf,0xf,0);
    if (BVar1 == 0) {
      *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(*(int *)(param_1 + 0x68) + 0x68);
      *(uint *)(param_1 + 0x78) = *(uint *)(*(int *)(param_1 + 0x68) + 100) & 0xf000;
      SetRectEmpty((LPRECT)(param_1 + 0xc));
      *(undefined4 *)(param_1 + 0x20) = 0;
      *(undefined4 *)(param_1 + 0x1c) = 0;
      *(undefined4 *)(param_1 + 0x24) = 0;
      *(undefined4 *)(param_1 + 0x7c) = 0;
      *(undefined4 *)(param_1 + 0x80) = 0;
      pHVar2 = GetDesktopWindow();
      iVar3 = FUN_004ac7ac(pHVar2);
      BVar1 = LockWindowUpdate(*(HWND *)(iVar3 + 0x1c));
      if (BVar1 == 0) {
        flags = 3;
      }
      else {
        flags = 0x403;
      }
      pHVar4 = GetDCEx(*(HWND *)(iVar3 + 0x1c),(HRGN)0x0,flags);
      uVar5 = FUN_004b4794(pHVar4);
      *(undefined4 *)(param_1 + 0x84) = uVar5;
      return;
    }
    BVar1 = GetMessageA(&local_1c,(HWND)0x0,0xf,0xf);
    if (BVar1 == 0) break;
    DispatchMessageA(&local_1c);
  }
  return;
}

