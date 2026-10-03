
undefined4 __thiscall FUN_004bcbe8(int param_1,int param_2,RECT *param_3)

{
  BOOL BVar1;
  
  if (param_2 == 1) {
    FUN_004ae2a6(0,0xffff,0xe900,1,param_3,0,1);
  }
  else if ((param_2 != 2) && (param_2 == 3)) {
    if (param_3 == (RECT *)0x0) {
      if ((((*(int *)(param_1 + 0x58) == 0) && (*(int *)(param_1 + 0x60) == 0)) &&
          (*(int *)(param_1 + 0x5c) == 0)) && (*(int *)(param_1 + 100) == 0)) {
        return 0;
      }
      SetRectEmpty((LPRECT)(param_1 + 0x58));
    }
    else {
      BVar1 = EqualRect((RECT *)(param_1 + 0x58),param_3);
      if (BVar1 != 0) {
        return 0;
      }
      CopyRect((RECT *)(param_1 + 0x58),param_3);
    }
  }
  return 1;
}

