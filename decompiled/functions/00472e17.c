
uint __thiscall FUN_00472e17(void *this,uint param_1,WPARAM param_2,LPARAM param_3)

{
  uint Msg;
  int iVar1;
  CWnd *pCVar2;
  
  Msg = param_1;
  if ((param_1 < 0x2b) ||
     ((((0x2f < param_1 && (param_1 != 0x39)) && (param_1 != 0x4e)) && (param_1 != 0x111)))) {
    param_1 = FUN_00468fb5(this,param_1,param_2,param_3);
  }
  else {
    iVar1 = (**(code **)(*(int *)this + 0xa4))(param_1,param_2,param_3,&param_1);
    if (iVar1 == 0) {
      pCVar2 = CWnd::GetOwner(this);
      param_1 = SendMessageA(*(HWND *)(pCVar2 + 0x1c),Msg,param_2,param_3);
    }
  }
  return param_1;
}

