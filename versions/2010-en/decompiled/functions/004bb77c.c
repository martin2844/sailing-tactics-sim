
void __thiscall FUN_004bb77c(int *param_1,HMENU param_2)

{
  int *piVar1;
  
  if (param_2 == (HMENU)0x0) {
    piVar1 = (int *)(**(code **)(*param_1 + 0xc4))();
    if (piVar1 != (int *)0x0) {
      param_2 = (HMENU)(**(code **)(*piVar1 + 0xac))();
    }
    if (param_2 == (HMENU)0x0) {
      param_2 = (HMENU)param_1[0x11];
    }
  }
  SetMenu((HWND)param_1[7],param_2);
  return;
}

