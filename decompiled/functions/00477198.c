
void __fastcall FUN_00477198(CWnd *param_1)

{
  int *this;
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined3 extraout_var;
  int iVar5;
  CWnd *pCVar6;
  int local_8;
  
  if ((*(code **)(param_1 + 0x9c) == (code *)0x0) ||
     (iVar2 = (**(code **)(param_1 + 0x9c))(param_1), iVar2 != 0)) {
    iVar2 = *(int *)param_1;
    piVar3 = (int *)(**(code **)(iVar2 + 0xc4))();
    if ((piVar3 == (int *)0x0) || (iVar4 = (**(code **)(*piVar3 + 0x94))(param_1), iVar4 != 0)) {
      iVar4 = FUN_0047b918();
      this = *(int **)(iVar4 + 4);
      if ((CWnd *)this[7] == param_1) {
        if ((piVar3 == (int *)0x0) && (iVar4 = (**(code **)(*this + 0x90))(), iVar4 == 0)) {
          return;
        }
        FUN_00472472((int)this);
        FUN_004726d2(this,0);
        bVar1 = FUN_00478719();
        if (CONCAT31(extraout_var,bVar1) == 0) {
          FUN_00478729(0);
          return;
        }
        iVar4 = FUN_0047b918();
        if ((*(char *)(iVar4 + 0x14) == '\0') && (this[7] == 0)) {
          AfxPostQuitMessage(0);
          return;
        }
      }
      if ((piVar3 != (int *)0x0) && (piVar3[0x12] != 0)) {
        iVar4 = *piVar3;
        bVar1 = false;
        local_8 = (**(code **)(iVar4 + 0x68))();
        do {
          if (local_8 == 0) goto LAB_0047727b;
          iVar5 = (**(code **)(iVar4 + 0x6c))(&local_8);
          pCVar6 = FUN_004696a2(iVar5);
        } while (pCVar6 == param_1);
        bVar1 = true;
LAB_0047727b:
        if (!bVar1) {
          (**(code **)(iVar4 + 0x84))();
          return;
        }
        (**(code **)(iVar4 + 0x9c))(param_1);
      }
      (**(code **)(iVar2 + 0x60))();
    }
  }
  return;
}

