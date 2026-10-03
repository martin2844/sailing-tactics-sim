
void __thiscall FUN_00479eb8(void *this,void *param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  CWnd *this_00;
  void *pvVar2;
  uint uVar3;
  
  if ((((*(int *)((int)param_1 + 0x6c) == 0) ||
       (pvVar2 = *(void **)((int)param_1 + 0x70), pvVar2 == (void *)0x0)) ||
      (*(int *)((int)pvVar2 + 0x78) == 0)) ||
     ((iVar1 = FUN_004753e8(pvVar2), iVar1 != 1 ||
      ((*(uint *)((int)pvVar2 + 100) & param_4 & 0xf000) == 0)))) {
    uVar3 = param_4;
    if (((*(byte *)((int)param_1 + 100) & 4) != 0) && (uVar3 = param_4 | 4, (param_4 & 0x5000) != 0)
       ) {
      uVar3 = param_4 & 0xffff2fff | 0x2004;
    }
    param_4 = uVar3;
    this_00 = (CWnd *)FUN_00479d9b(this,param_4);
    FUN_0046adfd(this_00,0,param_2,param_3,0,0,0x15);
    if (*(int *)(this_00 + 0x20) == 0) {
      *(undefined4 *)(this_00 + 0x20) = *(undefined4 *)((int)param_1 + 0x1c);
    }
    pvVar2 = (void *)FUN_0046acae(this_00,0xe81f);
    FUN_00475450(pvVar2,param_1,(RECT *)0x0);
    (**(code **)(*(int *)this_00 + 0xd0))(1);
    uVar3 = GetWindowLongA(*(HWND *)((int)param_1 + 0x1c),-0x10);
    if ((uVar3 & 0x10000000) == 0) {
      return;
    }
    FUN_0046ae4c(this_00,8);
  }
  else {
    GetParent(*(HWND *)((int)pvVar2 + 0x1c));
    this_00 = FUN_004680cc();
    FUN_0046adfd(this_00,0,param_2,param_3,0,0,0x15);
    (**(code **)(*(int *)this_00 + 0xd0))(1);
  }
  UpdateWindow(*(HWND *)(this_00 + 0x1c));
  return;
}

