
void __thiscall FUN_004bbc36(int param_1,uint param_2)

{
  int iVar1;
  LRESULT LVar2;
  
  iVar1 = FUN_004adeef();
  param_2 = param_2 & 0xfff0;
  if (*(int *)(iVar1 + 0x50) == 0) {
LAB_004bbc62:
    FUN_004ac701(param_1);
  }
  else {
    if (param_2 < 0xf011) {
      if ((param_2 != 0xf010) && (param_2 != 0xf000)) goto LAB_004bbc62;
    }
    else if (param_2 != 0xf020) {
      if (((((param_2 != 0xf030) && (param_2 != 0xf040)) && (param_2 != 0xf050)) &&
          ((param_2 != 0xf060 && (param_2 != 0xf120)))) && (param_2 != 0xf130)) goto LAB_004bbc62;
    }
    LVar2 = SendMessageA(*(HWND *)(param_1 + 0x1c),0x365,0,(param_2 - 0xf000 >> 4) + 0x1ef00);
    if (LVar2 == 0) {
      SendMessageA(*(HWND *)(param_1 + 0x1c),0x111,0xe147,0);
    }
  }
  return;
}

