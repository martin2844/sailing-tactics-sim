
void __thiscall FUN_0046b574(void *this,undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_00455bf0();
  *(undefined4 *)((int)this + 0x84) = 0;
  PostMessageA((HWND)piVar1[7],0x36a,0,0);
  (**(code **)(*piVar1 + 0x74))(param_1,param_2);
  return;
}

