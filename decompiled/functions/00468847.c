
void __fastcall FUN_00468847(int *param_1)

{
  bool bVar1;
  CWinThread *pCVar2;
  int iVar3;
  undefined3 extraout_var;
  int iVar4;
  LONG LVar5;
  LONG LVar6;
  int *piVar7;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  
  pCVar2 = AfxGetThread();
  if (pCVar2 == (CWinThread *)0x0) goto LAB_00468892;
  if (*(int **)(pCVar2 + 0x1c) == param_1) {
    iVar3 = FUN_0047b918();
    if (*(char *)(iVar3 + 0x14) == '\0') {
      iVar3 = FUN_0047b918();
      if (pCVar2 == *(CWinThread **)(iVar3 + 4)) {
        bVar1 = FUN_00478719();
        if (CONCAT31(extraout_var,bVar1) == 0) goto LAB_00468887;
      }
      AfxPostQuitMessage(0);
    }
LAB_00468887:
    *(undefined4 *)(pCVar2 + 0x1c) = 0;
  }
  if (*(int **)(pCVar2 + 0x20) == param_1) {
    *(undefined4 *)(pCVar2 + 0x20) = 0;
  }
LAB_00468892:
  if ((int *)param_1[0xc] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0xc] + 0x58))();
    param_1[0xc] = 0;
  }
  if ((int *)param_1[0xd] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0xd] + 4))(1);
  }
  param_1[0xd] = 0;
  if ((*(byte *)(param_1 + 9) & 1) != 0) {
    iVar3 = FUN_0047b5c5();
    iVar3 = *(int *)(iVar3 + 0xcc);
    if (iVar3 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(iVar3 + 0x1c);
    }
    if (iVar4 != 0) {
      _memset(&local_30,0,0x2c);
      local_28 = param_1[7];
      local_30 = 0x2c;
      local_2c = 1;
      local_24 = local_28;
      SendMessageA(*(HWND *)(iVar3 + 0x1c),0x405,0,(LPARAM)&local_30);
    }
  }
  LVar5 = GetWindowLongA((HWND)param_1[7],-4);
  FUN_00468021(param_1);
  LVar6 = GetWindowLongA((HWND)param_1[7],-4);
  if (LVar6 == LVar5) {
    piVar7 = (int *)(**(code **)(*param_1 + 0x88))();
    if (*piVar7 != 0) {
      SetWindowLongA((HWND)param_1[7],-4,*piVar7);
    }
  }
  FUN_00468149((int)param_1);
  (**(code **)(*param_1 + 0xac))();
  return;
}

