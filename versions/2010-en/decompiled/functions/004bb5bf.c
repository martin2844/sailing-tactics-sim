
undefined4 __thiscall FUN_004bb5bf(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_004ac701();
  if (iVar1 != -1) {
    iVar1 = *param_1;
    iVar2 = (**(code **)(iVar1 + 0xe4))(param_2,param_3);
    if (iVar2 != 0) {
      PostMessageA((HWND)param_1[7],0x362,0xe001,0);
      (**(code **)(iVar1 + 0xd0))(1);
      return 0;
    }
  }
  return 0xffffffff;
}

