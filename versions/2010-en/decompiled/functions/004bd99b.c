
void __thiscall FUN_004bd99b(int param_1,int param_2)

{
  HWND pHVar1;
  
  if ((DAT_005381f4 == 0) && (param_2 == 3)) {
    *(undefined4 *)(param_1 + 0xbc) = 1;
    *(undefined4 *)(param_1 + 0xc0) = 1;
    pHVar1 = SetCapture(*(HWND *)(param_1 + 0x1c));
    FUN_004ac7ac(pHVar1);
    FUN_004bdac7();
  }
  else {
    FUN_004ac701(param_1);
  }
  return;
}

