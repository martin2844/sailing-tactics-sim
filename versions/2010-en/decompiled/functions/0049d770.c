
int * FUN_0049d770(int *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  
  bVar1 = false;
  iVar8 = *param_1;
  iVar2 = FUN_0049e5b0();
  if (iVar8 < 0) {
    return (int *)0x0;
  }
  if (*(int *)(iVar2 + 0x40) == 0) {
    iVar3 = FUN_0049bf00(0x24);
    *(int *)(iVar2 + 0x40) = iVar3;
    piVar4 = (int *)&DAT_005385e0;
    if (iVar3 == 0) goto LAB_0049d7af;
  }
  piVar4 = *(int **)(iVar2 + 0x40);
LAB_0049d7af:
  iVar7 = iVar8 % 0x7861f80;
  iVar8 = (iVar8 / 0x7861f80) * 4;
  iVar2 = iVar8 + 0x46;
  iVar3 = iVar7;
  if (0x1e1337f < iVar7) {
    iVar3 = iVar7 + -0x1e13380;
    iVar2 = iVar8 + 0x47;
    if (0x1e1337f < iVar3) {
      iVar3 = iVar7 + -0x3c26700;
      iVar2 = iVar8 + 0x48;
      if (iVar3 < 0x1e28500) {
        bVar1 = true;
      }
      else {
        iVar2 = iVar8 + 0x49;
        iVar3 = iVar7 + -0x5a4ec00;
      }
    }
  }
  piVar4[5] = iVar2;
  piVar4[7] = iVar3 / 0x15180;
  puVar6 = (undefined4 *)&DAT_004f0530;
  if (!bVar1) {
    puVar6 = &DAT_004f0568;
  }
  piVar5 = puVar6 + 1;
  iVar2 = 1;
  iVar8 = *piVar5;
  while (iVar8 < piVar4[7]) {
    piVar5 = piVar5 + 1;
    iVar2 = iVar2 + 1;
    iVar8 = *piVar5;
  }
  piVar4[4] = iVar2 + -1;
  piVar4[3] = piVar4[7] - puVar6[iVar2 + -1];
  iVar8 = *param_1;
  piVar4[8] = 0;
  piVar4[6] = (iVar8 / 0x15180 + 4) % 7;
  piVar4[2] = (iVar3 % 0x15180) / 0xe10;
  iVar8 = (iVar3 % 0x15180) % 0xe10;
  piVar4[1] = iVar8 / 0x3c;
  *piVar4 = iVar8 % 0x3c;
  return piVar4;
}

