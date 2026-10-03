
undefined4 __thiscall FUN_004bae2a(int *param_1,LPMSG param_2)

{
  int iVar1;
  HACCEL hAccTable;
  undefined4 uVar2;
  
  if ((param_2->message == 0x201) || (param_2->message == 0xa1)) {
    FUN_004b5616(param_2->hwnd);
  }
  iVar1 = FUN_004ad0e8(param_2);
  if (iVar1 == 0) {
    if ((int *)param_1[0x1a] != (int *)0x0) {
      iVar1 = (**(code **)(*(int *)param_1[0x1a] + 0x5c))(param_2);
      if (iVar1 != 0) goto LAB_004bae95;
    }
    if ((0xff < param_2->message) && (param_2->message < 0x109)) {
      hAccTable = (HACCEL)(**(code **)(*param_1 + 0xf0))();
      if (hAccTable != (HACCEL)0x0) {
        iVar1 = TranslateAcceleratorA((HWND)param_1[7],hAccTable,param_2);
        if (iVar1 != 0) goto LAB_004bae95;
      }
    }
    uVar2 = 0;
  }
  else {
LAB_004bae95:
    uVar2 = 1;
  }
  return uVar2;
}

