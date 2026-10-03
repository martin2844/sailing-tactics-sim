
int __thiscall FUN_004716ea(int *param_1,undefined4 param_2,short param_3)

{
  int iVar1;
  code *pcVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  LRESULT nNumerator;
  int iVar7;
  int unaff_EDI;
  
  uVar5 = FUN_0046ad0b((int)param_1);
  iVar1 = *param_1;
  pcVar2 = *(code **)(iVar1 + 0x70);
  iVar6 = (*pcVar2)(1);
  if (((iVar6 == 0) || (iVar6 = FUN_0046ae73(iVar6), iVar6 == 0)) && ((uVar5 & 0x200000) == 0)) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
  }
  iVar6 = (*pcVar2)(0);
  iVar7 = 0;
  if (((iVar6 != 0) && (iVar6 = FUN_0046ae73(iVar6), iVar6 != 0)) ||
     (bVar4 = false, (uVar5 & 0x100000) != 0)) {
    bVar4 = true;
  }
  if ((!bVar3) && (!bVar4)) {
    return unaff_EDI;
  }
  nNumerator = FUN_00471035((HKEY)0x0);
  if (bVar3) {
    iVar7 = MulDiv(-(int)param_3,nNumerator,0x78);
    if ((iVar7 == -1) || (nNumerator == -1)) {
      iVar6 = param_1[0x16];
      if (0 < param_3) {
        iVar6 = -iVar6;
      }
    }
    else {
      iVar6 = param_1[0x18] * iVar7;
      if (param_1[0x16] <= param_1[0x18] * iVar7) {
        iVar6 = param_1[0x16];
      }
    }
    iVar7 = 0;
  }
  else {
    if (!bVar4) goto LAB_004717f8;
    iVar6 = MulDiv(-(int)param_3,nNumerator,0x78);
    if ((iVar6 == -1) || (nNumerator == -1)) {
      iVar7 = param_1[0x15];
    }
    else {
      iVar7 = param_1[0x17] * iVar6;
      if (param_1[0x15] <= param_1[0x17] * iVar6) {
        iVar7 = param_1[0x15];
      }
    }
    iVar6 = 0;
  }
  iVar7 = (**(code **)(iVar1 + 200))(iVar7,iVar6,1);
LAB_004717f8:
  if (iVar7 != 0) {
    UpdateWindow((HWND)param_1[7]);
  }
  return unaff_EDI;
}

