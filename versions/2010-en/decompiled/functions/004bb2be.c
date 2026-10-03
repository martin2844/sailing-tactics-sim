
void __thiscall FUN_004bb2be(int *param_1,int param_2)

{
  HWND pHVar1;
  int iVar2;
  HWND pHVar3;
  
  if ((param_2 == 0) || ((*(byte *)(param_1 + 9) & 4) == 0)) {
    pHVar1 = GetParent((HWND)param_1[7]);
    iVar2 = FUN_004ac7ac(pHVar1);
    if (iVar2 == 0) {
      if ((param_2 == 0) && (param_1[0x28] == 0)) {
        *(byte *)(param_1 + 9) = *(byte *)(param_1 + 9) | 0x80;
        (**(code **)(*param_1 + 0x90))();
      }
      else if ((param_2 != 0) && ((param_1[9] & 0x80U) != 0)) {
        param_1[9] = param_1[9] & 0xffffff7f;
        (**(code **)(*param_1 + 0x94))();
        pHVar1 = (HWND)param_1[7];
        pHVar3 = GetActiveWindow();
        if (pHVar3 == pHVar1) {
          SendMessageA(pHVar1,6,1,0);
        }
      }
      if ((param_2 != 0) && ((*(byte *)(param_1 + 9) & 0x20) != 0)) {
        SendMessageA((HWND)param_1[7],0x86,1,0);
      }
      FUN_004bb37c((-(uint)(param_2 != 0) & 0xfffffff0) + 0x20);
    }
  }
  else {
    FUN_004af56e(0);
    SetFocus((HWND)0x0);
  }
  return;
}

