
void __thiscall FUN_004baad5(CWnd *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == 2) {
    CWnd::ActivateTopParent(param_1);
    if (((byte)param_1[0x130] & 0x40) == 0) {
      iVar1 = 0;
      iVar2 = 1;
      do {
        if (*(int *)(param_1 + 0x150) <= iVar2) break;
        iVar1 = FUN_004ba70d(iVar2);
        iVar2 = iVar2 + 1;
      } while (iVar1 == 0);
      (**(code **)**(undefined4 **)(iVar1 + 0x74))(param_3,param_4);
      return;
    }
  }
  else if ((9 < param_2) && (param_2 < 0x12)) {
    CWnd::ActivateTopParent(param_1);
    iVar1 = 0;
    iVar2 = 1;
    do {
      if (*(int *)(param_1 + 0x150) <= iVar2) break;
      iVar1 = FUN_004ba70d(iVar2);
      iVar2 = iVar2 + 1;
    } while (iVar1 == 0);
    (**(code **)(**(int **)(iVar1 + 0x74) + 4))(param_2,param_3,param_4);
    return;
  }
  FUN_004bd99b(param_2,param_3,param_4);
  return;
}

