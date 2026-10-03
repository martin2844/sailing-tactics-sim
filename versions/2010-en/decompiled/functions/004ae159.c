
void __thiscall FUN_004ae159(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int wBar;
  
  wBar = param_2;
  if (param_2 == 3) {
    FUN_004ae159(0,param_3);
    wBar = 1;
  }
  iVar1 = (**(code **)(*param_1 + 0x70))(wBar);
  if (iVar1 == 0) {
    ShowScrollBar((HWND)param_1[7],wBar,param_2);
  }
  else {
    FUN_004af56e(param_2);
  }
  return;
}

