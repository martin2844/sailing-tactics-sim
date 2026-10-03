
LRESULT FUN_0046844f(int param_1,HWND param_2,int *param_3)

{
  int *this;
  int iVar1;
  LRESULT LVar2;
  int iVar3;
  LONG *pLVar4;
  int iVar5;
  undefined *puVar6;
  undefined *puVar7;
  HANDLE hData;
  HANDLE pvVar8;
  code *dwNewLong;
  
  iVar1 = FUN_0047be12(&DAT_004ae4b8,FUN_00455c3a);
  if (param_1 != 3) {
    LVar2 = CallNextHookEx(*(HHOOK *)(iVar1 + 0x2c),param_1,(WPARAM)param_2,(LPARAM)param_3);
    return LVar2;
  }
  this = *(int **)(iVar1 + 0x14);
  if ((this == (int *)0x0) &&
     (((*(byte *)(*param_3 + 0x23) & 0x40) != 0 ||
      (iVar3 = FUN_0047b918(), *(char *)(iVar3 + 0x14) != '\0')))) goto LAB_004685ab;
  if (this == (int *)0x0) {
    hData = (HANDLE)GetWindowLongA(param_2,-4);
    if (hData != (HANDLE)0x0) {
      SetPropA(param_2,"AfxOldWndProc",hData);
      pvVar8 = GetPropA(param_2,"AfxOldWndProc");
      if (pvVar8 == hData) {
        dwNewLong = FUN_004683d3;
        if (*(int *)(iVar1 + 0x28) == 0) {
          dwNewLong = FUN_004681ad;
        }
        SetWindowLongA(param_2,-4,(LONG)dwNewLong);
      }
    }
    goto LAB_004685ab;
  }
  FUN_00468110(this,(uint)param_2);
  iVar3 = *this;
  (**(code **)(iVar3 + 0x58))();
  pLVar4 = (LONG *)(**(code **)(iVar3 + 0x88))();
  if ((((DAT_004ae694 == 0) &&
       (iVar5 = FUN_0047b918(), iVar3 = DAT_004ae630, *(char *)(iVar5 + 0x14) == '\0')) &&
      (DAT_004ae630 != 0)) &&
     ((*(int *)(DAT_004ae630 + 0x20) != 0 && (iVar5 = FUN_00467e60(), iVar5 != 0)))) {
    puVar6 = FUN_004681a7();
    puVar7 = (undefined *)GetWindowLongA(param_2,-4);
    (**(code **)(iVar3 + 0x20))(param_2,iVar5);
    if (puVar7 != puVar6) {
      puVar7 = (undefined *)SetWindowLongA(param_2,-4,(LONG)puVar6);
LAB_00468556:
      *pLVar4 = (LONG)puVar7;
    }
  }
  else {
    puVar6 = FUN_004681a7();
    puVar7 = (undefined *)SetWindowLongA(param_2,-4,(LONG)puVar6);
    if (puVar7 != puVar6) goto LAB_00468556;
  }
  *(undefined4 *)(iVar1 + 0x14) = 0;
LAB_004685ab:
  LVar2 = CallNextHookEx(*(HHOOK *)(iVar1 + 0x2c),3,(WPARAM)param_2,(LPARAM)param_3);
  iVar3 = FUN_0047b918();
  if (*(char *)(iVar3 + 0x14) != '\0') {
    UnhookWindowsHookEx(*(HHOOK *)(iVar1 + 0x2c));
    *(undefined4 *)(iVar1 + 0x2c) = 0;
  }
  return LVar2;
}

