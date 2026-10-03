
void __thiscall FUN_004b6b84(int param_1,int param_2)

{
  HCURSOR pHVar1;
  
  FUN_004c088f(2);
  *(int *)(param_1 + 0xa0) = *(int *)(param_1 + 0xa0) + param_2;
  if (*(int *)(param_1 + 0xa0) < 1) {
    *(undefined4 *)(param_1 + 0xa0) = 0;
    SetCursor(*(HCURSOR *)(param_1 + 0xa4));
  }
  else {
    pHVar1 = SetCursor(DAT_005381cc);
    if ((0 < param_2) && (*(int *)(param_1 + 0xa0) == 1)) {
      *(HCURSOR *)(param_1 + 0xa4) = pHVar1;
    }
  }
  FUN_004c08ff(2);
  return;
}

