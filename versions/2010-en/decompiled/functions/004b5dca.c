
int __thiscall FUN_004b5dca(int *param_1,undefined4 param_2,short param_3)

{
  int iVar1;
  code *pcVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  uVar5 = FUN_004af3eb();
  iVar1 = *param_1;
  pcVar2 = *(code **)(iVar1 + 0x70);
  iVar6 = (*pcVar2)(1);
  if (((iVar6 == 0) || (iVar6 = FUN_004af553(), iVar6 == 0)) && ((uVar5 & 0x200000) == 0)) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
  }
  iVar6 = (*pcVar2)(0);
  iVar8 = 0;
  if (((iVar6 != 0) && (iVar6 = FUN_004af553(), iVar6 != 0)) ||
     (bVar4 = false, (uVar5 & 0x100000) != 0)) {
    bVar4 = true;
  }
  if ((!bVar3) && (!bVar4)) {
    return 0;
  }
  iVar6 = FUN_004b5715(0);
  if (bVar3) {
    iVar7 = MulDiv(-(int)param_3,iVar6,0x78);
    if ((iVar7 == -1) || (iVar6 == -1)) {
      iVar8 = param_1[0x16];
      if (0 < param_3) {
        iVar8 = -iVar8;
      }
    }
    else {
      iVar8 = param_1[0x18] * iVar7;
      if (param_1[0x16] <= param_1[0x18] * iVar7) {
        iVar8 = param_1[0x16];
      }
    }
    iVar6 = 0;
  }
  else {
    if (!bVar4) goto LAB_004b5ed8;
    iVar8 = MulDiv(-(int)param_3,iVar6,0x78);
    if ((iVar8 == -1) || (iVar6 == -1)) {
      iVar6 = param_1[0x15];
    }
    else {
      iVar6 = param_1[0x17] * iVar8;
      if (param_1[0x15] <= param_1[0x17] * iVar8) {
        iVar6 = param_1[0x15];
      }
    }
    iVar8 = 0;
  }
  iVar8 = (**(code **)(iVar1 + 200))(iVar6,iVar8,1);
LAB_004b5ed8:
  if (iVar8 != 0) {
    UpdateWindow((HWND)param_1[7]);
  }
  return iVar8;
}

