
void __fastcall FUN_004bb878(int *param_1)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int local_8;
  
  if (((code *)param_1[0x27] == (code *)0x0) ||
     (iVar3 = (*(code *)param_1[0x27])(param_1), iVar3 != 0)) {
    iVar3 = *param_1;
    piVar4 = (int *)(**(code **)(iVar3 + 0xc4))();
    if ((piVar4 == (int *)0x0) || (iVar5 = (**(code **)(*piVar4 + 0x94))(param_1), iVar5 != 0)) {
      iVar5 = FUN_004bfff8();
      piVar1 = *(int **)(iVar5 + 4);
      if ((int *)piVar1[7] == param_1) {
        if ((piVar4 == (int *)0x0) && (iVar5 = (**(code **)(*piVar1 + 0x90))(), iVar5 == 0)) {
          return;
        }
        FUN_004b6b52();
        FUN_004b6db2(0);
        iVar5 = FUN_004bcdf9();
        if (iVar5 == 0) {
          FUN_004bce09(0);
          return;
        }
        iVar5 = FUN_004bfff8();
        if ((*(char *)(iVar5 + 0x14) == '\0') && (piVar1[7] == 0)) {
          AfxPostQuitMessage(0);
          return;
        }
      }
      if ((piVar4 != (int *)0x0) && (piVar4[0x12] != 0)) {
        iVar5 = *piVar4;
        bVar2 = false;
        local_8 = (**(code **)(iVar5 + 0x68))();
        do {
          if (local_8 == 0) goto LAB_004bb95b;
          (**(code **)(iVar5 + 0x6c))(&local_8);
          piVar4 = (int *)FUN_004add82();
        } while (piVar4 == param_1);
        bVar2 = true;
LAB_004bb95b:
        if (!bVar2) {
          (**(code **)(iVar5 + 0x84))();
          return;
        }
        (**(code **)(iVar5 + 0x9c))(param_1);
      }
      (**(code **)(iVar3 + 0x60))();
    }
  }
  return;
}

