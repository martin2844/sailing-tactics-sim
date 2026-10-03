
void FUN_004565e9(void)

{
  CWnd CVar1;
  bool bVar2;
  SHORT SVar3;
  CWnd *pCVar4;
  int iVar5;
  undefined4 uVar6;
  CWnd *pCVar7;
  int iVar8;
  LRESULT LVar9;
  int iVar10;
  undefined3 extraout_var;
  undefined4 *puVar11;
  CWnd *extraout_ECX;
  int unaff_EBP;
  uint uVar12;
  undefined4 *puVar13;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  iVar5 = *(int *)(*(int *)(unaff_EBP + 8) + 4);
  CVar1 = extraout_ECX[0x24];
  *(CWnd **)(unaff_EBP + -0x10) = extraout_ECX;
  if ((((((byte)CVar1 & 1) == 0) ||
       ((((iVar5 != 0x200 && (iVar5 != 0xa0)) && (iVar5 != 0x202)) &&
        ((iVar5 != 0x205 && (iVar5 != 0x208)))))) || (SVar3 = GetKeyState(1), SVar3 < 0)) ||
     ((SVar3 = GetKeyState(2), SVar3 < 0 || (SVar3 = GetKeyState(4), SVar3 < 0))))
  goto LAB_004568d2;
  while (pCVar4 = FUN_004680cc(), pCVar4 != (CWnd *)0x0) {
    if (pCVar4 == extraout_ECX) goto LAB_0045668b;
    if (((byte)pCVar4[0x24] & 1) != 0) break;
    GetParent(*(HWND *)(pCVar4 + 0x1c));
  }
  if (pCVar4 != extraout_ECX) goto LAB_004568d2;
LAB_0045668b:
  iVar5 = FUN_0047be12(&DAT_004ae4b8,FUN_00455c3a);
  *(int *)(unaff_EBP + -0x18) = iVar5;
  pCVar4 = *(CWnd **)(iVar5 + 0xcc);
  uVar6 = FUN_00469757((int)extraout_ECX);
  *(undefined4 *)(unaff_EBP + -0x14) = uVar6;
  if (pCVar4 == (CWnd *)0x0) {
LAB_004566d9:
    iVar8 = FUN_0046b505(0x58);
    *(int *)(unaff_EBP + -0x1c) = iVar8;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar8 == 0) {
      pCVar4 = (CWnd *)0x0;
    }
    else {
      pCVar4 = (CWnd *)FUN_00456338();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    iVar8 = FUN_0045638d(pCVar4,*(int *)(unaff_EBP + -0x14),1);
    if (iVar8 == 0) {
      if (pCVar4 != (CWnd *)0x0) {
        (**(code **)(*(int *)pCVar4 + 4))(1);
      }
      goto LAB_004568d2;
    }
    SendMessageA(*(HWND *)(pCVar4 + 0x1c),0x401,0,0);
    *(CWnd **)(iVar5 + 0xcc) = pCVar4;
  }
  else {
    pCVar7 = CWnd::GetOwner(pCVar4);
    if (pCVar7 != *(CWnd **)(unaff_EBP + -0x14)) {
      iVar8 = *(int *)pCVar4;
      (**(code **)(iVar8 + 0x60))();
      (**(code **)(iVar8 + 4))(1);
      pCVar4 = (CWnd *)0x0;
      *(undefined4 *)(iVar5 + 0xcc) = 0;
    }
    if (pCVar4 == (CWnd *)0x0) goto LAB_004566d9;
  }
  _memset((void *)(unaff_EBP + -0x50),0,0x2c);
  *(undefined4 *)(unaff_EBP + -0x50) = 0x2c;
  *(undefined4 *)(unaff_EBP + -0x4c) = 1;
  uVar6 = *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x1c);
  *(undefined4 *)(unaff_EBP + -0x48) = uVar6;
  *(undefined4 *)(unaff_EBP + -0x44) = uVar6;
  LVar9 = SendMessageA(*(HWND *)(pCVar4 + 0x1c),0x408,0,unaff_EBP + -0x50);
  if (LVar9 == 0) {
    SendMessageA(*(HWND *)(pCVar4 + 0x1c),0x404,0,unaff_EBP + -0x50);
  }
  uVar6 = *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x14);
  *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x18);
  *(undefined4 *)(unaff_EBP + -0x24) = uVar6;
  ScreenToClient(*(HWND *)(*(int *)(unaff_EBP + -0x10) + 0x1c),(LPPOINT)(unaff_EBP + -0x24));
  _memset((void *)(unaff_EBP + -0x7c),0,0x2c);
  *(undefined4 *)(unaff_EBP + -0x7c) = 0x2c;
  iVar10 = (**(code **)(**(int **)(unaff_EBP + -0x10) + 0x6c))
                     (*(undefined4 *)(unaff_EBP + -0x24),*(undefined4 *)(unaff_EBP + -0x20),
                      unaff_EBP + -0x7c);
  *(int *)(unaff_EBP + -0x1c) = iVar10;
  uVar12 = -(uint)(iVar10 != -1) & *(uint *)(unaff_EBP + -0x10);
  iVar8 = *(int *)(iVar5 + 0xd4);
  *(uint *)(unaff_EBP + -0x14) = uVar12;
  if ((iVar8 == iVar10) && (*(uint *)(iVar5 + 0xd0) == uVar12)) {
    if (iVar10 != -1) {
      FUN_004568e3((int)pCVar4,*(undefined4 **)(unaff_EBP + 8));
    }
  }
  else {
    if (iVar10 != -1) {
      uVar12 = *(uint *)(unaff_EBP + -0x78);
      puVar11 = (undefined4 *)(unaff_EBP + -0x7c);
      puVar13 = (undefined4 *)(unaff_EBP + -0x50);
      for (iVar5 = 0xb; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar13 = *puVar11;
        puVar11 = puVar11 + 1;
        puVar13 = puVar13 + 1;
      }
      *(uint *)(unaff_EBP + -0x4c) = uVar12 & 0x3fffffff;
      SendMessageA(*(HWND *)(pCVar4 + 0x1c),0x404,0,unaff_EBP + -0x50);
      if (((*(byte *)(unaff_EBP + -0x75) & 0x40) != 0) ||
         (bVar2 = FUN_0046979e(*(int *)(unaff_EBP + -0x10)), CONCAT31(extraout_var,bVar2) != 0)) {
        SendMessageA(*(HWND *)(pCVar4 + 0x1c),0x401,1,0);
        SetWindowPos(*(HWND *)(pCVar4 + 0x1c),(HWND)0x0,0,0,0,0,0x213);
      }
      iVar5 = *(int *)(unaff_EBP + -0x18);
      uVar12 = *(uint *)(unaff_EBP + -0x14);
    }
    FUN_004568e3((int)pCVar4,*(undefined4 **)(unaff_EBP + 8));
    iVar8 = *(int *)(iVar5 + 0xd8);
    puVar11 = (undefined4 *)(iVar5 + 0xd8);
    *(undefined4 **)(unaff_EBP + 8) = puVar11;
    if (iVar8 == 0x2c) {
      SendMessageA(*(HWND *)(pCVar4 + 0x1c),0x405,0,(LPARAM)puVar11);
      puVar11 = *(undefined4 **)(unaff_EBP + 8);
    }
    uVar6 = *(undefined4 *)(unaff_EBP + -0x1c);
    *(uint *)(iVar5 + 0xd0) = uVar12;
    *(undefined4 *)(iVar5 + 0xd4) = uVar6;
    puVar13 = (undefined4 *)(unaff_EBP + -0x7c);
    for (iVar5 = 0xb; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar11 = *puVar13;
      puVar13 = puVar13 + 1;
      puVar11 = puVar11 + 1;
    }
  }
  if ((*(int *)(unaff_EBP + -0x58) != -1) && (*(int *)(unaff_EBP + -0x5c) == 0)) {
    FUN_00457710(*(undefined **)(unaff_EBP + -0x58));
  }
LAB_004568d2:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

