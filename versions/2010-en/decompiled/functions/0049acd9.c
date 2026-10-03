
void FUN_0049acd9(void)

{
  byte bVar1;
  SHORT SVar2;
  int iVar3;
  HWND pHVar4;
  undefined4 uVar5;
  CWnd *pCVar6;
  int iVar7;
  LRESULT LVar8;
  int iVar9;
  undefined4 *puVar10;
  int extraout_ECX;
  CWnd *this;
  int unaff_EBP;
  uint uVar11;
  undefined4 *puVar12;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  puVar10 = *(undefined4 **)(unaff_EBP + 8);
  iVar3 = puVar10[1];
  bVar1 = *(byte *)(extraout_ECX + 0x24);
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  if (((bVar1 & 1) == 0) ||
     ((((iVar3 != 0x200 && (iVar3 != 0xa0)) && (iVar3 != 0x202)) &&
      ((iVar3 != 0x205 && (iVar3 != 0x208)))))) goto LAB_0049afc2;
  SVar2 = GetKeyState(1);
  if (SVar2 < 0) goto LAB_0049afc2;
  SVar2 = GetKeyState(2);
  if (SVar2 < 0) goto LAB_0049afc2;
  SVar2 = GetKeyState(4);
  if (SVar2 < 0) goto LAB_0049afc2;
  pHVar4 = (HWND)*puVar10;
  while( true ) {
    iVar3 = FUN_004ac7ac(pHVar4);
    if (iVar3 == 0) break;
    if (iVar3 == extraout_ECX) goto LAB_0049ad7b;
    if ((*(byte *)(iVar3 + 0x24) & 1) != 0) break;
    pHVar4 = GetParent(*(HWND *)(iVar3 + 0x1c));
  }
  if (iVar3 != extraout_ECX) goto LAB_0049afc2;
LAB_0049ad7b:
  iVar3 = FUN_004c04f2(FUN_0049a32a);
  *(int *)(unaff_EBP + -0x18) = iVar3;
  this = *(CWnd **)(iVar3 + 0xcc);
  uVar5 = FUN_004ade37();
  *(undefined4 *)(unaff_EBP + -0x14) = uVar5;
  if (this == (CWnd *)0x0) {
LAB_0049adc9:
    iVar7 = FUN_004afbe5(0x58);
    *(int *)(unaff_EBP + -0x1c) = iVar7;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar7 == 0) {
      this = (CWnd *)0x0;
    }
    else {
      this = (CWnd *)FUN_0049aa28();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    iVar7 = FUN_0049aa7d(*(undefined4 *)(unaff_EBP + -0x14),1);
    if (iVar7 == 0) {
      if (this != (CWnd *)0x0) {
        (**(code **)(*(int *)this + 4))(1);
      }
      goto LAB_0049afc2;
    }
    SendMessageA(*(HWND *)(this + 0x1c),0x401,0,0);
    *(CWnd **)(iVar3 + 0xcc) = this;
  }
  else {
    pCVar6 = CWnd::GetOwner(this);
    if (pCVar6 != *(CWnd **)(unaff_EBP + -0x14)) {
      iVar7 = *(int *)this;
      (**(code **)(iVar7 + 0x60))();
      (**(code **)(iVar7 + 4))(1);
      this = (CWnd *)0x0;
      *(undefined4 *)(iVar3 + 0xcc) = 0;
    }
    if (this == (CWnd *)0x0) goto LAB_0049adc9;
  }
  _memset((void *)(unaff_EBP + -0x50),0,0x2c);
  *(undefined4 *)(unaff_EBP + -0x50) = 0x2c;
  *(undefined4 *)(unaff_EBP + -0x4c) = 1;
  uVar5 = *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x1c);
  *(undefined4 *)(unaff_EBP + -0x48) = uVar5;
  *(undefined4 *)(unaff_EBP + -0x44) = uVar5;
  LVar8 = SendMessageA(*(HWND *)(this + 0x1c),0x408,0,unaff_EBP + -0x50);
  if (LVar8 == 0) {
    SendMessageA(*(HWND *)(this + 0x1c),0x404,0,unaff_EBP + -0x50);
  }
  uVar5 = *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x14);
  *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x18);
  *(undefined4 *)(unaff_EBP + -0x24) = uVar5;
  ScreenToClient(*(HWND *)(*(int *)(unaff_EBP + -0x10) + 0x1c),(LPPOINT)(unaff_EBP + -0x24));
  _memset((void *)(unaff_EBP + -0x7c),0,0x2c);
  *(undefined4 *)(unaff_EBP + -0x7c) = 0x2c;
  iVar9 = (**(code **)(**(int **)(unaff_EBP + -0x10) + 0x6c))
                    (*(undefined4 *)(unaff_EBP + -0x24),*(undefined4 *)(unaff_EBP + -0x20),
                     unaff_EBP + -0x7c);
  *(int *)(unaff_EBP + -0x1c) = iVar9;
  uVar11 = -(uint)(iVar9 != -1) & *(uint *)(unaff_EBP + -0x10);
  iVar7 = *(int *)(iVar3 + 0xd4);
  *(uint *)(unaff_EBP + -0x14) = uVar11;
  if ((iVar7 == iVar9) && (*(uint *)(iVar3 + 0xd0) == uVar11)) {
    if (iVar9 != -1) {
      FUN_0049afd3(this,*(undefined4 *)(unaff_EBP + 8));
    }
  }
  else {
    if (iVar9 != -1) {
      uVar11 = *(uint *)(unaff_EBP + -0x78);
      puVar10 = (undefined4 *)(unaff_EBP + -0x7c);
      puVar12 = (undefined4 *)(unaff_EBP + -0x50);
      for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar12 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar12 = puVar12 + 1;
      }
      *(uint *)(unaff_EBP + -0x4c) = uVar11 & 0x3fffffff;
      SendMessageA(*(HWND *)(this + 0x1c),0x404,0,unaff_EBP + -0x50);
      if ((*(byte *)(unaff_EBP + -0x75) & 0x40) == 0) {
        iVar3 = FUN_004ade7e();
        if (iVar3 != 0) goto LAB_0049af3b;
      }
      else {
LAB_0049af3b:
        SendMessageA(*(HWND *)(this + 0x1c),0x401,1,0);
        SetWindowPos(*(HWND *)(this + 0x1c),(HWND)0x0,0,0,0,0,0x213);
      }
      iVar3 = *(int *)(unaff_EBP + -0x18);
      uVar11 = *(uint *)(unaff_EBP + -0x14);
    }
    FUN_0049afd3(this,*(undefined4 *)(unaff_EBP + 8));
    iVar7 = *(int *)(iVar3 + 0xd8);
    puVar10 = (undefined4 *)(iVar3 + 0xd8);
    *(undefined4 **)(unaff_EBP + 8) = puVar10;
    if (iVar7 == 0x2c) {
      SendMessageA(*(HWND *)(this + 0x1c),0x405,0,(LPARAM)puVar10);
      puVar10 = *(undefined4 **)(unaff_EBP + 8);
    }
    uVar5 = *(undefined4 *)(unaff_EBP + -0x1c);
    *(uint *)(iVar3 + 0xd0) = uVar11;
    *(undefined4 *)(iVar3 + 0xd4) = uVar5;
    puVar12 = (undefined4 *)(unaff_EBP + -0x7c);
    for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar10 = *puVar12;
      puVar12 = puVar12 + 1;
      puVar10 = puVar10 + 1;
    }
  }
  if ((*(int *)(unaff_EBP + -0x58) != -1) && (*(int *)(unaff_EBP + -0x5c) == 0)) {
    FUN_0049bfd0(*(undefined4 *)(unaff_EBP + -0x58));
  }
LAB_0049afc2:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

