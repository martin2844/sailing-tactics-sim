
uint __thiscall FUN_004b74f7(CWnd *param_1,uint param_2,WPARAM param_3,LPARAM param_4)

{
  uint Msg;
  int iVar1;
  CWnd *pCVar2;
  
  Msg = param_2;
  if ((param_2 < 0x2b) ||
     ((((0x2f < param_2 && (param_2 != 0x39)) && (param_2 != 0x4e)) && (param_2 != 0x111)))) {
    param_2 = FUN_004ad695(param_2,param_3,param_4);
  }
  else {
    iVar1 = (**(code **)(*(int *)param_1 + 0xa4))(param_2,param_3,param_4,&param_2);
    if (iVar1 == 0) {
      pCVar2 = CWnd::GetOwner(param_1);
      param_2 = SendMessageA(*(HWND *)(pCVar2 + 0x1c),Msg,param_3,param_4);
    }
  }
  return param_2;
}

