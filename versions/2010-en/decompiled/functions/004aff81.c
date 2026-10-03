
bool __thiscall FUN_004aff81(int param_1,int param_2)

{
  BOOL BVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 < 1) {
    iVar3 = *(int *)(param_1 + 0x1c);
    if ((iVar3 != 0) && (*(HWND *)(iVar3 + 0x1c) != (HWND)0x0)) {
      BVar1 = IsWindowVisible(*(HWND *)(iVar3 + 0x1c));
      if (BVar1 != 0) {
        FUN_004ac540(iVar3,*(undefined4 *)(iVar3 + 0x1c),0x363,1,0);
        FUN_004ae04c(*(undefined4 *)(iVar3 + 0x1c),0x363,1,0,1,1);
      }
    }
    FUN_004bfff8();
    iVar2 = FUN_004c04f2(FUN_0049a3b2);
    for (iVar2 = *(int *)(iVar2 + 8); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x54)) {
      if ((*(int *)(iVar2 + 0x1c) != 0) && (iVar2 != iVar3)) {
        if (*(int *)(iVar2 + 0x88) == 0) {
          FUN_004af52c(0);
        }
        BVar1 = IsWindowVisible(*(HWND *)(iVar2 + 0x1c));
        if ((BVar1 != 0) || (-1 < *(int *)(iVar2 + 0x88))) {
          FUN_004ac540(iVar2,*(undefined4 *)(iVar2 + 0x1c),0x363,1,0);
          FUN_004ae04c(*(undefined4 *)(iVar2 + 0x1c),0x363,1,0,1,1);
        }
        if (0 < *(int *)(iVar2 + 0x88)) {
          FUN_004af52c(*(int *)(iVar2 + 0x88));
        }
        *(undefined4 *)(iVar2 + 0x88) = 0xffffffff;
      }
    }
  }
  else {
    FUN_004bfff8();
    iVar3 = FUN_004c04f2(FUN_0049a3b2);
    if (*(int *)(iVar3 + 0x10) == 0) {
      FUN_004b1b1a();
      FUN_004b1b23(1);
    }
  }
  return param_2 < 0;
}

