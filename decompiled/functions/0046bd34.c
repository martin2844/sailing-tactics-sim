
undefined4 __fastcall FUN_0046bd34(int *param_1)

{
  LPMSG lpMsg;
  BOOL BVar1;
  int iVar2;
  undefined4 uVar3;
  
  lpMsg = (LPMSG)(param_1 + 0xc);
  BVar1 = GetMessageA(lpMsg,(HWND)0x0,0,0);
  uVar3 = 0;
  if (BVar1 != 0) {
    if (param_1[0xd] != 0x36a) {
      iVar2 = (**(code **)(*param_1 + 0x60))(lpMsg);
      if (iVar2 == 0) {
        TranslateMessage(lpMsg);
        DispatchMessageA(lpMsg);
      }
    }
    uVar3 = 1;
  }
  return uVar3;
}

