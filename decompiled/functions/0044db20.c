
void __cdecl FUN_0044db20(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  COLORREF CVar2;
  
  if (DAT_004911a4 != 0) {
    iVar1 = *(int *)param_1;
    if (DAT_004ac92c == 0) {
      CVar2 = 0x7f7f00;
    }
    else {
      CVar2 = 0;
    }
    (**(code **)(iVar1 + 0x38))((void *)param_1,CVar2);
    if (DAT_004a763c < 700) {
      param_4 = param_3 + 1;
    }
    FUN_0047033f((void *)param_1,2);
    (**(code **)(iVar1 + 0x34))((void *)param_1,0xffffff);
    (**(code **)(iVar1 + 100))
              ((void *)param_1,param_4,(DAT_004aa824 - DAT_004a72d0 / 0x32) - param_2,DAT_004a7048,
               *(int *)(DAT_004a7048 + -8));
    FUN_0047033f((void *)param_1,1);
  }
  return;
}

