
int __fastcall FUN_004769a0(int param_1)

{
  int iVar1;
  HWND pHVar2;
  BOOL BVar3;
  int iVar4;
  LRESULT LVar5;
  UINT UVar6;
  undefined4 local_8;
  
  *(int *)(param_1 + 0xa0) = *(int *)(param_1 + 0xa0) + 1;
  iVar4 = param_1 + 0xa0;
  if (*(uint *)(param_1 + 0xa0) < 2) {
    iVar1 = FUN_0046972b(param_1);
    local_8 = 0;
    UVar6 = 5;
    pHVar2 = GetDesktopWindow();
    while( true ) {
      pHVar2 = GetWindow(pHVar2,UVar6);
      if (pHVar2 == (HWND)0x0) break;
      BVar3 = IsWindowEnabled(pHVar2);
      if (BVar3 != 0) {
        iVar4 = FUN_004680f4((uint)pHVar2);
        if (iVar4 != 0) {
          iVar4 = FUN_00476980(*(HWND__ **)(iVar1 + 0x1c),pHVar2);
          if (iVar4 != 0) {
            LVar5 = SendMessageA(pHVar2,0x36c,0,0);
            if (LVar5 == 0) {
              local_8 = local_8 + 1;
            }
          }
        }
      }
      UVar6 = 2;
    }
    iVar4 = 0;
    if (local_8 != 0) {
      iVar4 = FUN_0046b505(local_8 * 4 + 4);
      local_8 = 0;
      UVar6 = 5;
      *(int *)(param_1 + 0xa4) = iVar4;
      pHVar2 = GetDesktopWindow();
      for (pHVar2 = GetWindow(pHVar2,UVar6); pHVar2 != (HWND)0x0; pHVar2 = GetWindow(pHVar2,2)) {
        BVar3 = IsWindowEnabled(pHVar2);
        if (BVar3 != 0) {
          iVar4 = FUN_004680f4((uint)pHVar2);
          if (iVar4 != 0) {
            iVar4 = FUN_00476980(*(HWND__ **)(iVar1 + 0x1c),pHVar2);
            if (iVar4 != 0) {
              LVar5 = SendMessageA(pHVar2,0x36c,0,0);
              if (LVar5 == 0) {
                EnableWindow(pHVar2,0);
                *(HWND *)(*(int *)(param_1 + 0xa4) + local_8 * 4) = pHVar2;
                local_8 = local_8 + 1;
              }
            }
          }
        }
      }
      iVar4 = *(int *)(param_1 + 0xa4);
      *(undefined4 *)(iVar4 + local_8 * 4) = 0;
    }
  }
  return iVar4;
}

