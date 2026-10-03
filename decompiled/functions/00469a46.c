
void __thiscall FUN_00469a46(void *this,int param_1,int param_2,int param_3,BOOL param_4)

{
  int iVar1;
  HWND hWnd;
  
  iVar1 = (**(code **)(*(int *)this + 0x70))(param_1);
  if (iVar1 == 0) {
    hWnd = *(HWND *)((int)this + 0x1c);
  }
  else {
    param_1 = 2;
    hWnd = *(HWND *)(iVar1 + 0x1c);
  }
  SetScrollRange(hWnd,param_1,param_2,param_3,param_4);
  return;
}

