
undefined4 FUN_00467df7(HWND param_1,int param_2,uint param_3,uint param_4,uint param_5)

{
  uint uVar1;
  undefined4 uVar2;
  uint dwNewLong;
  
  uVar1 = GetWindowLongA(param_1,param_2);
  dwNewLong = ~param_3 & uVar1 | param_4;
  if (uVar1 == dwNewLong) {
    uVar2 = 0;
  }
  else {
    SetWindowLongA(param_1,param_2,dwNewLong);
    if (param_5 != 0) {
      SetWindowPos(param_1,(HWND)0x0,0,0,0,0,param_5 | 0x17);
    }
    uVar2 = 1;
  }
  return uVar2;
}

