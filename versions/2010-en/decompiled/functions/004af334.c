
undefined4 __thiscall FUN_004af334(int *param_1,HWND param_2)

{
  int iVar1;
  int *piVar2;
  LONG LVar3;
  undefined4 uVar4;
  
  iVar1 = FUN_004ac7f0(param_2);
  uVar4 = 0;
  if (iVar1 != 0) {
    iVar1 = *param_1;
    (**(code **)(iVar1 + 0x58))();
    piVar2 = (int *)(**(code **)(iVar1 + 0x88))();
    LVar3 = FUN_004ac887();
    LVar3 = SetWindowLongA(param_2,-4,LVar3);
    if (*piVar2 == 0) {
      *piVar2 = LVar3;
    }
    uVar4 = 1;
  }
  return uVar4;
}

