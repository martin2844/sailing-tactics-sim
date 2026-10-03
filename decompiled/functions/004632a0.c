
undefined4 FUN_004632a0(HWND param_1,int param_2)

{
  HANDLE pvVar1;
  LONG LVar2;
  HWND pHVar3;
  int iVar4;
  
  if (DAT_004aff40 == 0) {
    return 0;
  }
  if ((-1 < param_2) && (param_2 < 7)) {
    pvVar1 = FUN_00462840(param_1);
    if (pvVar1 != (HANDLE)0x0) {
      return 0;
    }
    LVar2 = GetWindowLongA(param_1,-0x10);
    pHVar3 = GetParent(param_1);
    iVar4 = (*(code *)(&PTR_FUN_004897d8)[param_2 * 8])(param_1,LVar2,0xffff,0,pHVar3);
    if (iVar4 == 1) {
      FUN_004628b0(param_1,(&DAT_004b09a0)[param_2 * 6]);
    }
    return 1;
  }
  return 0;
}

