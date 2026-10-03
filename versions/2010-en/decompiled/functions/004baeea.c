
void __fastcall FUN_004baeea(int param_1)

{
  BOOL BVar1;
  HWND pHVar2;
  int iVar3;
  tagMSG local_1c;
  
  if (*(int *)(param_1 + 0x50) != 0) {
    BVar1 = PeekMessageA(&local_1c,*(HWND *)(param_1 + 0x1c),0x367,0x367,3);
    if (BVar1 == 0) {
      PostMessageA(*(HWND *)(param_1 + 0x1c),0x367,0,0);
    }
    pHVar2 = GetCapture();
    if (pHVar2 == *(HWND *)(param_1 + 0x1c)) {
      ReleaseCapture();
    }
    iVar3 = FUN_004adeef();
    *(undefined4 *)(param_1 + 0x50) = 0;
    *(undefined4 *)(iVar3 + 0x50) = 0;
    PostMessageA(*(HWND *)(param_1 + 0x1c),0x36a,0,0);
  }
  return;
}

