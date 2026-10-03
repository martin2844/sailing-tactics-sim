
void __thiscall FUN_004bc85a(int *param_1,int param_2,int *param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  HWND pHVar8;
  HMENU pHVar9;
  HWND hWnd;
  HWND unaff_retaddr;
  uint uStack_c;
  
  iVar4 = (**(code **)(*param_1 + 200))();
  if ((param_2 != 0) && (*(int **)(iVar4 + 0x68) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar4 + 0x68) + 100))(0);
  }
  uStack_c = 0;
  puVar3 = (undefined4 *)param_1[0x1c];
  while (puVar3 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar3;
    piVar2 = (int *)puVar3[2];
    uVar5 = GetDlgCtrlID((HWND)piVar2[7]);
    uVar5 = uVar5 & 0xffff;
    puVar3 = puVar1;
    if ((0xe7ff < uVar5) && (uVar5 < 0xe820)) {
      uVar6 = 1 << ((byte)uVar5 & 0x1f);
      iVar7 = (**(code **)(*piVar2 + 0xd0))();
      if (iVar7 != 0) {
        uStack_c = uStack_c | uVar6;
      }
      iVar7 = (**(code **)(*piVar2 + 0xd8))();
      if ((iVar7 == 0) || (uVar5 != 0xe81f)) {
        FUN_004bbf9a(piVar2,param_3[2] & uVar6,1);
      }
    }
  }
  param_3[2] = uStack_c;
  if (param_2 == 0) {
    param_1[0x27] = 0;
    pHVar8 = GetDlgItem((HWND)param_1[7],0xea21);
    if (pHVar8 != (HWND)0x0) {
      hWnd = GetDlgItem((HWND)param_1[7],0xe900);
      if (hWnd != (HWND)0x0) {
        SetWindowLongA(hWnd,-0xc,0xea21);
      }
      SetWindowLongA(pHVar8,-0xc,0xe900);
    }
    if (param_3[1] != 0) {
      InvalidateRect((HWND)param_1[7],(RECT *)0x0,1);
      SetMenu((HWND)param_1[7],(HMENU)param_3[1]);
    }
    if (*(int **)(iVar4 + 0x68) != (int *)0x0) {
      (**(code **)(**(int **)(iVar4 + 0x68) + 100))(1);
    }
    (**(code **)(*param_1 + 0xd0))(1);
    if (*param_3 != 0xe900) {
      unaff_retaddr = GetDlgItem((HWND)param_1[7],*param_3);
    }
    ShowWindow(unaff_retaddr,5);
    param_1[0x12] = param_3[5];
    FUN_004bb21c(1);
  }
  else {
    param_1[0x27] = param_3[4];
    FUN_004bb21c(0);
    pHVar8 = GetDlgItem((HWND)param_1[7],*param_3);
    ShowWindow(pHVar8,0);
    pHVar9 = GetMenu((HWND)param_1[7]);
    param_3[1] = (int)pHVar9;
    if (pHVar9 != (HMENU)0x0) {
      InvalidateRect((HWND)param_1[7],(RECT *)0x0,1);
      SetMenu((HWND)param_1[7],(HMENU)0x0);
      param_1[0x2e] = param_1[0x2e] & 0xfffffffe;
    }
    param_3[5] = param_1[0x12];
    param_1[0x12] = 0;
    FUN_004bade0(0x7915);
    if (*param_3 != 0xe900) {
      pHVar8 = GetDlgItem((HWND)param_1[7],0xe900);
    }
    if (pHVar8 != (HWND)0x0) {
      SetWindowLongA(pHVar8,-0xc,0xea21);
    }
  }
  return;
}

