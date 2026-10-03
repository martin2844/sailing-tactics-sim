
void __thiscall FUN_004bb21c(int param_1,int param_2)

{
  HWND pHVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  UINT uCmd;
  
  uCmd = 5;
  pHVar1 = GetDesktopWindow();
  for (pHVar1 = GetWindow(pHVar1,uCmd); pHVar1 != (HWND)0x0; pHVar1 = GetWindow(pHVar1,2)) {
    iVar2 = FUN_004ac7d4(pHVar1);
    if (((iVar2 != 0) && (*(HWND *)(param_1 + 0x1c) != pHVar1)) &&
       (iVar3 = FUN_004bb060(*(HWND *)(param_1 + 0x1c),pHVar1), iVar3 != 0)) {
      uVar4 = GetWindowLongA(pHVar1,-0x10);
      if (param_2 == 0) {
        if ((uVar4 & 0x18000000) == 0x10000000) {
          ShowWindow(pHVar1,0);
          *(uint *)(iVar2 + 0x24) = *(uint *)(iVar2 + 0x24) | 2;
        }
      }
      else if (((uVar4 & 0x18000000) == 0) && ((*(byte *)(iVar2 + 0x24) & 2) != 0)) {
        ShowWindow(pHVar1,4);
        *(uint *)(iVar2 + 0x24) = *(uint *)(iVar2 + 0x24) & 0xfffffffd;
      }
    }
  }
  return;
}

