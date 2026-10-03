
void __thiscall FUN_004ae126(int *param_1,int param_2,int param_3,int param_4,BOOL param_5)

{
  int iVar1;
  HWND hWnd;
  
  iVar1 = (**(code **)(*param_1 + 0x70))(param_2);
  if (iVar1 == 0) {
    hWnd = (HWND)param_1[7];
  }
  else {
    param_2 = 2;
    hWnd = *(HWND *)(iVar1 + 0x1c);
  }
  SetScrollRange(hWnd,param_2,param_3,param_4,param_5);
  return;
}

