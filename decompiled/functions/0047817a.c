
void __thiscall FUN_0047817a(void *this,int param_1,int *param_2)

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
  
  iVar4 = (**(code **)(*(int *)this + 200))();
  if ((param_1 != 0) && (*(int **)(iVar4 + 0x68) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar4 + 0x68) + 100))(0);
  }
  uStack_c = 0;
  puVar3 = *(undefined4 **)((int)this + 0x70);
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
        FUN_004778ba(piVar2,param_2[2] & uVar6,1);
      }
    }
  }
  param_2[2] = uStack_c;
  if (param_1 == 0) {
    *(undefined4 *)((int)this + 0x9c) = 0;
    pHVar8 = GetDlgItem(*(HWND *)((int)this + 0x1c),0xea21);
    if (pHVar8 != (HWND)0x0) {
      hWnd = GetDlgItem(*(HWND *)((int)this + 0x1c),0xe900);
      if (hWnd != (HWND)0x0) {
        SetWindowLongA(hWnd,-0xc,0xea21);
      }
      SetWindowLongA(pHVar8,-0xc,0xe900);
    }
    if (param_2[1] != 0) {
      InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,1);
      SetMenu(*(HWND *)((int)this + 0x1c),(HMENU)param_2[1]);
    }
    if (*(int **)(iVar4 + 0x68) != (int *)0x0) {
      (**(code **)(**(int **)(iVar4 + 0x68) + 100))(1);
    }
    (**(code **)(*(int *)this + 0xd0))(1);
    if (*param_2 != 0xe900) {
      unaff_retaddr = GetDlgItem(*(HWND *)((int)this + 0x1c),*param_2);
    }
    ShowWindow(unaff_retaddr,5);
    *(int *)((int)this + 0x48) = param_2[5];
    FUN_00476b3c(this,1);
  }
  else {
    *(int *)((int)this + 0x9c) = param_2[4];
    FUN_00476b3c(this,0);
    pHVar8 = GetDlgItem(*(HWND *)((int)this + 0x1c),*param_2);
    ShowWindow(pHVar8,0);
    pHVar9 = GetMenu(*(HWND *)((int)this + 0x1c));
    param_2[1] = (int)pHVar9;
    if (pHVar9 != (HMENU)0x0) {
      InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,1);
      SetMenu(*(HWND *)((int)this + 0x1c),(HMENU)0x0);
      *(uint *)((int)this + 0xb8) = *(uint *)((int)this + 0xb8) & 0xfffffffe;
    }
    param_2[5] = *(int *)((int)this + 0x48);
    *(undefined4 *)((int)this + 0x48) = 0;
    FUN_00476700(this,(LPCSTR)0x7915);
    if (*param_2 != 0xe900) {
      pHVar8 = GetDlgItem(*(HWND *)((int)this + 0x1c),0xe900);
    }
    if (pHVar8 != (HWND)0x0) {
      SetWindowLongA(pHVar8,-0xc,0xea21);
    }
  }
  return;
}

