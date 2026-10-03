
undefined4 FUN_004a7980(HWND param_1,int param_2)

{
  int iVar1;
  LONG LVar2;
  HWND pHVar3;
  
  if (DAT_00539a80 == 0) {
    return 0;
  }
  if ((-1 < param_2) && (param_2 < 7)) {
    iVar1 = FUN_004a6f20(param_1);
    if (iVar1 != 0) {
      return 0;
    }
    LVar2 = GetWindowLongA(param_1,-0x10);
    pHVar3 = GetParent(param_1);
    iVar1 = (*(code *)(&PTR_FUN_004d1480)[param_2 * 8])(param_1,LVar2,0xffff,0,pHVar3);
    if (iVar1 == 1) {
      FUN_004a6f90(param_1,(&DAT_0053a4e0)[param_2 * 6]);
    }
    return 1;
  }
  return 0;
}

