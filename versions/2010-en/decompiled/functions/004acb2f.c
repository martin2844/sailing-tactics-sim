
LRESULT FUN_004acb2f(int param_1,HWND param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  LRESULT LVar3;
  int iVar4;
  LONG *pLVar5;
  int iVar6;
  int dwNewLong;
  LONG LVar7;
  HANDLE hData;
  HANDLE pvVar8;
  code *dwNewLong_00;
  
  iVar2 = FUN_004c04f2(FUN_0049a32a);
  if (param_1 != 3) {
    LVar3 = CallNextHookEx(*(HHOOK *)(iVar2 + 0x2c),param_1,(WPARAM)param_2,(LPARAM)param_3);
    return LVar3;
  }
  piVar1 = *(int **)(iVar2 + 0x14);
  if ((piVar1 == (int *)0x0) &&
     (((*(byte *)(*param_3 + 0x23) & 0x40) != 0 ||
      (iVar4 = FUN_004bfff8(), *(char *)(iVar4 + 0x14) != '\0')))) goto LAB_004acc8b;
  if (piVar1 == (int *)0x0) {
    hData = (HANDLE)GetWindowLongA(param_2,-4);
    if (hData != (HANDLE)0x0) {
      SetPropA(param_2,"AfxOldWndProc",hData);
      pvVar8 = GetPropA(param_2,"AfxOldWndProc");
      if (pvVar8 == hData) {
        dwNewLong_00 = FUN_004acab3;
        if (*(int *)(iVar2 + 0x28) == 0) {
          dwNewLong_00 = FUN_004ac88d;
        }
        SetWindowLongA(param_2,-4,(LONG)dwNewLong_00);
      }
    }
    goto LAB_004acc8b;
  }
  FUN_004ac7f0(param_2);
  iVar4 = *piVar1;
  (**(code **)(iVar4 + 0x58))();
  pLVar5 = (LONG *)(**(code **)(iVar4 + 0x88))();
  if ((((DAT_005381ec == 0) &&
       (iVar6 = FUN_004bfff8(), iVar4 = DAT_00538188, *(char *)(iVar6 + 0x14) == '\0')) &&
      (DAT_00538188 != 0)) &&
     ((*(int *)(DAT_00538188 + 0x20) != 0 &&
      (iVar6 = FUN_004ac540(piVar1,param_2,0x36f,0,0), iVar6 != 0)))) {
    dwNewLong = FUN_004ac887();
    LVar7 = GetWindowLongA(param_2,-4);
    (**(code **)(iVar4 + 0x20))(param_2,iVar6);
    if (LVar7 != dwNewLong) {
      LVar7 = SetWindowLongA(param_2,-4,dwNewLong);
LAB_004acc36:
      *pLVar5 = LVar7;
    }
  }
  else {
    iVar4 = FUN_004ac887();
    LVar7 = SetWindowLongA(param_2,-4,iVar4);
    if (LVar7 != iVar4) goto LAB_004acc36;
  }
  *(undefined4 *)(iVar2 + 0x14) = 0;
LAB_004acc8b:
  LVar3 = CallNextHookEx(*(HHOOK *)(iVar2 + 0x2c),3,(WPARAM)param_2,(LPARAM)param_3);
  iVar4 = FUN_004bfff8();
  if (*(char *)(iVar4 + 0x14) != '\0') {
    UnhookWindowsHookEx(*(HHOOK *)(iVar2 + 0x2c));
    *(undefined4 *)(iVar2 + 0x2c) = 0;
  }
  return LVar3;
}

