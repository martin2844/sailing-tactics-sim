
void __thiscall FUN_004bc1fa(int *param_1,uint param_2,uint param_3)

{
  int iVar1;
  HWND pHVar2;
  
  iVar1 = FUN_004adeef();
  if (param_3 == 0xffff) {
    param_1[9] = param_1[9] & 0xffffffbf;
    if (*(int *)(iVar1 + 0x50) == 0) {
      param_1[0x24] = 0xe001;
    }
    else {
      param_1[0x24] = 0xe002;
    }
    SendMessageA((HWND)param_1[7],0x362,param_1[0x24],0);
    iVar1 = (**(code **)(*param_1 + 0xdc))();
    if (iVar1 != 0) {
      UpdateWindow(*(HWND *)(iVar1 + 0x1c));
    }
    goto LAB_004bc2b2;
  }
  if ((param_2 == 0) || ((param_3 & 0x810) != 0)) {
    param_1[0x24] = 0;
  }
  else {
    if ((param_2 < 0xf000) || (0xf1ef < param_2)) {
      if (0xfeff < param_2) {
        param_1[0x24] = 0xef1f;
        goto LAB_004bc2ae;
      }
    }
    else {
      param_2 = (param_2 - 0xf000 >> 4) + 0xef00;
    }
    param_1[0x24] = param_2;
  }
LAB_004bc2ae:
  *(uint *)(iVar1 + 0x24) = *(uint *)(iVar1 + 0x24) | 0x40;
LAB_004bc2b2:
  if (param_1[0x24] != param_1[0x25]) {
    pHVar2 = GetParent((HWND)param_1[7]);
    iVar1 = FUN_004ac7ac(pHVar2);
    if (iVar1 != 0) {
      PostMessageA((HWND)param_1[7],0x36a,0,0);
    }
  }
  return;
}

