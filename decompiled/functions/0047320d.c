
void __thiscall FUN_0047320d(void *this,undefined4 param_1,LONG param_2,LONG param_3)

{
  int iVar1;
  
  if ((*(int *)((int)this + 0x70) != 0) &&
     (iVar1 = (**(code **)(*(int *)this + 0x6c))(param_2,param_3,0), iVar1 == -1)) {
    ClientToScreen(*(HWND *)((int)this + 0x1c),(LPPOINT)&param_2);
    (**(code **)**(undefined4 **)((int)this + 0x74))(param_2,param_3);
    return;
  }
  FUN_00468021(this);
  return;
}

