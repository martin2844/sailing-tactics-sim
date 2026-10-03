
void __thiscall FUN_004beb71(int *param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  HWND hWnd;
  BOOL BVar2;
  int iVar3;
  int iVar4;
  int local_10 [3];
  
  FUN_004b7e00(param_2,param_3);
  uVar1 = FUN_004af3eb();
  if ((uVar1 & 0x100) != 0) {
    hWnd = GetParent((HWND)param_1[7]);
    BVar2 = IsZoomed(hWnd);
    if (BVar2 == 0) {
      (**(code **)(*param_1 + 0xa8))(0x407,0,local_10);
      iVar3 = GetSystemMetrics(5);
      iVar4 = GetSystemMetrics(2);
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + ((iVar3 * -2 - local_10[0]) - iVar4);
    }
  }
  return;
}

