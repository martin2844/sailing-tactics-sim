
int * __cdecl FUN_00459070(int *param_1)

{
  bool bVar1;
  DWORD *pDVar2;
  DWORD DVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  bVar1 = false;
  iVar10 = *param_1;
  pDVar2 = FUN_00459ed0();
  if (iVar10 < 0) {
    return (int *)0x0;
  }
  if (pDVar2[0x10] == 0) {
    DVar3 = FUN_00457640(0x24);
    pDVar2[0x10] = DVar3;
    piVar5 = (int *)&DAT_004aea88;
    if (DVar3 == 0) goto LAB_004590af;
  }
  piVar5 = (int *)pDVar2[0x10];
LAB_004590af:
  iVar8 = iVar10 % 0x7861f80;
  iVar10 = (iVar10 / 0x7861f80) * 4;
  iVar4 = iVar10 + 0x46;
  iVar9 = iVar8;
  if (0x1e1337f < iVar8) {
    iVar9 = iVar8 + -0x1e13380;
    iVar4 = iVar10 + 0x47;
    if (0x1e1337f < iVar9) {
      iVar9 = iVar8 + -0x3c26700;
      iVar4 = iVar10 + 0x48;
      if (iVar9 < 0x1e28500) {
        bVar1 = true;
      }
      else {
        iVar4 = iVar10 + 0x49;
        iVar9 = iVar8 + -0x5a4ec00;
      }
    }
  }
  piVar5[5] = iVar4;
  piVar5[7] = iVar9 / 0x15180;
  puVar7 = (undefined4 *)&DAT_004a2370;
  if (!bVar1) {
    puVar7 = &DAT_004a23a8;
  }
  piVar6 = puVar7 + 1;
  iVar4 = 1;
  iVar10 = *piVar6;
  while (iVar10 < piVar5[7]) {
    piVar6 = piVar6 + 1;
    iVar4 = iVar4 + 1;
    iVar10 = *piVar6;
  }
  piVar5[4] = iVar4 + -1;
  piVar5[3] = piVar5[7] - puVar7[iVar4 + -1];
  iVar10 = *param_1;
  piVar5[8] = 0;
  piVar5[6] = (iVar10 / 0x15180 + 4) % 7;
  piVar5[2] = (iVar9 % 0x15180) / 0xe10;
  iVar10 = (iVar9 % 0x15180) % 0xe10;
  piVar5[1] = iVar10 / 0x3c;
  *piVar5 = iVar10 % 0x3c;
  return piVar5;
}

