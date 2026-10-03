
undefined4 __thiscall FUN_00476edf(void *this,undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_00468021(this);
  if (iVar1 != -1) {
    iVar1 = *(int *)this;
    iVar2 = (**(code **)(iVar1 + 0xe4))(param_1,param_2);
    if (iVar2 != 0) {
      PostMessageA(*(HWND *)((int)this + 0x1c),0x362,0xe001,0);
      (**(code **)(iVar1 + 0xd0))(1);
      return 0;
    }
  }
  return 0xffffffff;
}

