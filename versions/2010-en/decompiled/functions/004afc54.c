
void __thiscall FUN_004afc54(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_0049a2e0();
  *(undefined4 *)(param_1 + 0x84) = 0;
  PostMessageA((HWND)piVar1[7],0x36a,0,0);
  (**(code **)(*piVar1 + 0x74))(param_2,param_3);
  return;
}

