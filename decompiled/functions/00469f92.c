
uint __thiscall FUN_00469f92(void *this,uint param_1,int *param_2,int param_3,int *param_4)

{
  LRESULT LVar1;
  uint uVar2;
  
  if (*(int *)((int)this + 0x38) == 0) {
    uVar2 = FUN_00469fed(this,param_1,param_2,param_3,param_4);
  }
  else {
    LVar1 = SendMessageA(*(HWND *)((int)this + 0x1c),param_1 + 0x2000,(WPARAM)param_2,param_3);
    if (((param_1 < 0x132) || (0x138 < param_1)) || (uVar2 = 0, LVar1 != 0)) {
      if (param_4 != (int *)0x0) {
        *param_4 = LVar1;
      }
      uVar2 = 1;
    }
  }
  return uVar2;
}

