
void __fastcall FUN_004acf27(int *param_1)

{
  CWinThread *pCVar1;
  int iVar2;
  int iVar3;
  LONG LVar4;
  LONG LVar5;
  int *piVar6;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  
  pCVar1 = AfxGetThread();
  if (pCVar1 == (CWinThread *)0x0) goto LAB_004acf72;
  if (*(int **)(pCVar1 + 0x1c) == param_1) {
    iVar2 = FUN_004bfff8();
    if (*(char *)(iVar2 + 0x14) == '\0') {
      iVar2 = FUN_004bfff8();
      if (pCVar1 == *(CWinThread **)(iVar2 + 4)) {
        iVar2 = FUN_004bcdf9();
        if (iVar2 == 0) goto LAB_004acf67;
      }
      AfxPostQuitMessage(0);
    }
LAB_004acf67:
    *(undefined4 *)(pCVar1 + 0x1c) = 0;
  }
  if (*(int **)(pCVar1 + 0x20) == param_1) {
    *(undefined4 *)(pCVar1 + 0x20) = 0;
  }
LAB_004acf72:
  if ((int *)param_1[0xc] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0xc] + 0x58))();
    param_1[0xc] = 0;
  }
  if ((int *)param_1[0xd] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0xd] + 4))(1);
  }
  param_1[0xd] = 0;
  if ((*(byte *)(param_1 + 9) & 1) != 0) {
    iVar2 = FUN_004bfca5();
    iVar2 = *(int *)(iVar2 + 0xcc);
    if (iVar2 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar2 + 0x1c);
    }
    if (iVar3 != 0) {
      _memset(&local_30,0,0x2c);
      local_28 = param_1[7];
      local_30 = 0x2c;
      local_2c = 1;
      local_24 = local_28;
      SendMessageA(*(HWND *)(iVar2 + 0x1c),0x405,0,(LPARAM)&local_30);
    }
  }
  LVar4 = GetWindowLongA((HWND)param_1[7],-4);
  FUN_004ac701(param_1);
  LVar5 = GetWindowLongA((HWND)param_1[7],-4);
  if (LVar5 == LVar4) {
    piVar6 = (int *)(**(code **)(*param_1 + 0x88))();
    if (*piVar6 != 0) {
      SetWindowLongA((HWND)param_1[7],-4,*piVar6);
    }
  }
  FUN_004ac829();
  (**(code **)(*param_1 + 0xac))();
  return;
}

