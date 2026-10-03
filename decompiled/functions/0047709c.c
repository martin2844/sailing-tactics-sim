
void __thiscall FUN_0047709c(void *this,HMENU param_1)

{
  int *piVar1;
  
  if (param_1 == (HMENU)0x0) {
    piVar1 = (int *)(**(code **)(*(int *)this + 0xc4))();
    if (piVar1 != (int *)0x0) {
      param_1 = (HMENU)(**(code **)(*piVar1 + 0xac))();
    }
    if (param_1 == (HMENU)0x0) {
      param_1 = *(HMENU *)((int)this + 0x44);
    }
  }
  SetMenu(*(HWND *)((int)this + 0x1c),param_1);
  return;
}

