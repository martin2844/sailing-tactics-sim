
void __thiscall FUN_00469a79(void *this,int param_1,undefined4 param_2)

{
  void *this_00;
  int wBar;
  
  wBar = param_1;
  if (param_1 == 3) {
    FUN_00469a79(this,0,param_2);
    wBar = 1;
  }
  this_00 = (void *)(**(code **)(*(int *)this + 0x70))(wBar);
  if (this_00 == (void *)0x0) {
    ShowScrollBar(*(HWND *)((int)this + 0x1c),wBar,param_1);
  }
  else {
    FUN_0046ae8e(this_00,param_1);
  }
  return;
}

