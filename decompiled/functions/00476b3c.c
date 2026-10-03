
void __thiscall FUN_00476b3c(void *this,int param_1)

{
  HWND hWnd;
  HWND__ *hWnd_00;
  int iVar1;
  int iVar2;
  uint uVar3;
  UINT uCmd;
  
  uCmd = 5;
  hWnd = GetDesktopWindow();
  for (hWnd_00 = GetWindow(hWnd,uCmd); hWnd_00 != (HWND__ *)0x0; hWnd_00 = GetWindow(hWnd_00,2)) {
    iVar1 = FUN_004680f4((uint)hWnd_00);
    if (((iVar1 != 0) && (*(HWND__ **)((int)this + 0x1c) != hWnd_00)) &&
       (iVar2 = FUN_00476980(*(HWND__ **)((int)this + 0x1c),hWnd_00), iVar2 != 0)) {
      uVar3 = GetWindowLongA(hWnd_00,-0x10);
      if (param_1 == 0) {
        if ((uVar3 & 0x18000000) == 0x10000000) {
          ShowWindow(hWnd_00,0);
          *(uint *)(iVar1 + 0x24) = *(uint *)(iVar1 + 0x24) | 2;
        }
      }
      else if (((uVar3 & 0x18000000) == 0) && ((*(byte *)(iVar1 + 0x24) & 2) != 0)) {
        ShowWindow(hWnd_00,4);
        *(uint *)(iVar1 + 0x24) = *(uint *)(iVar1 + 0x24) & 0xfffffffd;
      }
    }
  }
  return;
}

