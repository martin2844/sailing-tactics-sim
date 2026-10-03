
undefined4 __thiscall FUN_0047674a(void *this,LPMSG param_1)

{
  int iVar1;
  HACCEL hAccTable;
  undefined4 uVar2;
  
  if ((param_1->message == 0x201) || (param_1->message == 0xa1)) {
    FUN_00470f36(param_1->hwnd);
  }
  iVar1 = FUN_00468a08(this,param_1);
  if (iVar1 == 0) {
    if (*(int **)((int)this + 0x68) != (int *)0x0) {
      iVar1 = (**(code **)(**(int **)((int)this + 0x68) + 0x5c))(param_1);
      if (iVar1 != 0) goto LAB_004767b5;
    }
    if ((0xff < param_1->message) && (param_1->message < 0x109)) {
      hAccTable = (HACCEL)(**(code **)(*(int *)this + 0xf0))();
      if (hAccTable != (HACCEL)0x0) {
        iVar1 = TranslateAcceleratorA(*(HWND *)((int)this + 0x1c),hAccTable,param_1);
        if (iVar1 != 0) goto LAB_004767b5;
      }
    }
    uVar2 = 0;
  }
  else {
LAB_004767b5:
    uVar2 = 1;
  }
  return uVar2;
}

