
undefined4 __thiscall FUN_0046ac54(void *this,HWND param_1)

{
  int iVar1;
  bool bVar2;
  undefined3 extraout_var;
  int *piVar3;
  undefined *dwNewLong;
  LONG LVar4;
  undefined4 uVar5;
  
  bVar2 = FUN_00468110(this,(uint)param_1);
  uVar5 = 0;
  if (CONCAT31(extraout_var,bVar2) != 0) {
    iVar1 = *(int *)this;
    (**(code **)(iVar1 + 0x58))();
    piVar3 = (int *)(**(code **)(iVar1 + 0x88))();
    dwNewLong = FUN_004681a7();
    LVar4 = SetWindowLongA(param_1,-4,(LONG)dwNewLong);
    if (*piVar3 == 0) {
      *piVar3 = LVar4;
    }
    uVar5 = 1;
  }
  return uVar5;
}

