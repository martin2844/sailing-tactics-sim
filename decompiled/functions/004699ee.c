
void __thiscall FUN_004699ee(void *this,int param_1,int param_2,BOOL param_3)

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
  SetScrollPos(hWnd,param_1,param_2,param_3);
  return;
}

