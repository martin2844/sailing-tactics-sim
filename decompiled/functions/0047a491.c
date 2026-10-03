
void __thiscall FUN_0047a491(void *this,int *param_1,int param_2)

{
  uint uVar1;
  HWND hWnd;
  BOOL BVar2;
  int iVar3;
  int iVar4;
  int local_10 [3];
  
  FUN_00473720(this,param_1,param_2);
  uVar1 = FUN_0046ad0b((int)this);
  if ((uVar1 & 0x100) != 0) {
    hWnd = GetParent(*(HWND *)((int)this + 0x1c));
    BVar2 = IsZoomed(hWnd);
    if (BVar2 == 0) {
      (**(code **)(*(int *)this + 0xa8))(0x407,0,local_10);
      iVar3 = GetSystemMetrics(5);
      iVar4 = GetSystemMetrics(2);
      param_1[2] = param_1[2] + ((iVar3 * -2 - local_10[0]) - iVar4);
    }
  }
  return;
}

